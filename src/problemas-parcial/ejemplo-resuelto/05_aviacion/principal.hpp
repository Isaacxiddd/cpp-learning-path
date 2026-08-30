#ifndef _MAINHPP
#define _MAINHPP

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  ARCHIVO: principal.hpp                                                ║
// ║  QUÉ ES:  El archivo de "declaraciones" (plantillas).                  ║
// ║  REGLA DE ORO: aquí van los STRUCTS y sus FUNCIONES de                ║
// ║  serialización (ToString/FromString). NO va lógica de negocio.        ║
// ╚═══════════════════════════════════════════════════════════════════════╝
//
//  EL PORQUÉ DE LOS INCLUDE:
//  - <iostream>:  para cout / cin / endl
//  - <sstream>:   para stringstream (solo si querés ToDebug)
//  - <string>:    para el tipo string (texto de verdad, no char[])
//  - <string.h>:  para strcpy (copiar un string DENTRO de un char[])
//  - <stdlib.h>:  para abs(), stringToInt()...
//  - strings.hpp, tokens.hpp, files.hpp, Coll.hpp: TU biblioteca del curso.
//    FIJATE: los includes apuntan hacia arriba (../../../../lib/...) porque
//    este archivo vive 4 carpetas adentro de la raíz del repo.
//
//  ⚠️  NOTA IMPORTANTE SOBRE char[] vs string:
//  Un struct que se lee/escribe de un archivo .dat NECESITA tamaño fijo.
//  Por eso los campos de texto de los structs son `char[20]`, NO `string`.
//  (un string tiene tamaño variable → la memoria del archivo no coincidiría)

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"
#include "../../../../lib/funciones/files.hpp"
#include "../../../../lib/funciones/Coll.hpp"
using namespace std;

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  SECCIÓN 1: LOS STRUCTS DEL ENUNCIADO                                  ║
// ║  Estos son los que YA EXISTEN en los archivos .dat.                    ║
// ║  El enunciado te da la estructura → la copiás tal cual.                ║
// ╚═══════════════════════════════════════════════════════════════════════╝

// ─── CIUDADES.dat: 1 registro = 1 ciudad ──────────────────────────────────
struct Ciudad
{
	int idCiu;       // identificador único de la ciudad
	char descr[20];  // nombre de la ciudad (texto fijo)
	int millas;      // millas que vale llegar a esta ciudad
};

// ─── VUELOS.dat: 1 registro = 1 vuelo ─────────────────────────────────────
struct Vuelo
{
	int idVue;  // identificador único del vuelo
	int cap;    // capacidad del vuelo (cuántas plazas tiene)
	int idOri;  // idCiu de ORIGEN  (la ciudad de donde sale)
	int idDes;  // idCiu de DESTINO (la ciudad a donde va)
};

// ─── RESERVAS.dat: 1 registro = 1 reserva (esto es la NOVEDAD) ────────────
struct Reserva
{
	int idCli;  // id del cliente que reservó
	int idVue;  // id del vuelo que reservó
	int cant;   // cuántas plazas pidió (su grupo/familia)
};

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  SECCIÓN 2: LOS STRUCTS ENVUELTOS (WRAP)                               ║
// ║  "WRAP" = envolver el struct original para AGREGARLE lo que nos falta.║
// ║  ¿Por qué? Porque los archivos son de SOLO LECTURA de datos, pero     ║
//  ║ nosotros necesitamos CONTAR/ACUMULAR cosas que no vienen en el       ║
//  ║ archivo. Entonces envuelvo el struct y le agrego un contador.        ║
//  ║  La R del nombre significa "Resultado" / "Registro" (conteo).        ║
//  ╚══════════════════════════════════════════════════════════════════════╝

// ─── Para el PUNTO 1: quiero contar, por ciudad, cuántos grupos la eligieron de destino ───
struct RCiudad
{
	Ciudad c;    // la ciudad original (intacta)
	int cont;    // contador extra que YO agrego = grupos que la eligieron
};

// ─── Para el PUNTO 2: quiero saber por vuelo cuántas plazas se aceptaron/rechazaron ───
struct RVuelo
{
	Vuelo v;   // el vuelo original
	int cpr;   // plazas RECHAZADAS (la reserva no entraba)
	int cpa;   // plazas ACEPTADAS   (la reserva entró)
};

// ─── Para el PUNTO 3: los clientes NO están en ningún archivo → los descubro ───
struct RCliente
{
	int idCli;   // id del cliente (el único dato que tengo de él)
	int millas;  // total de millas que va acumulando
};

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  SECCIÓN 3: SERIALIZACIÓN (ToString / FromString)                      ║
// ║                                                                        ║
// ║  ¿QUÉ ES LA SERIALIZACIÓN?                                             ║
// ║  La Coll<T> es INTERNAMENTE un texto largo separado por un caracter.  ║
// ║  Cada elemento queda como "valor1 SEP valor2 SEP valor3".              ║
// ║  Entonces necesito:                                                    ║
// ║   - ToString:   convertir mi struct a ese texto   (para GUARDAR)      ║
// ║   - FromString: volver de ese texto a mi struct   (para LEER)         ║
// ║                                                                        ║
// ║  💡 LA REGLA DE ORO DE LOS SEPARADORES:                                 ║
// ║  Cada struct usa UN NÚMERO de separador distinto (1,2,3,4,5,6...).    ║
// ║  ¿Por qué? Porque los wraps EMBEBEN al struct original:               ║
// ║   rCiudadToString guarda ciudadToString adentro. Si ambos usaran el   ║
// ║   mismo separador, al desarmar no sabríamos dónde termina un campo.   ║
// ║  ➜ regla: el wrap SIEMPRE usa un separador mayor que el original.    ║
// ╚═══════════════════════════════════════════════════════════════════════╝

// ─── Ciudad: sep = 1 ──────────────────────────────────────────────────────
string ciudadToString(Ciudad x)
{
	char sep = 1;    // el separador es el caracter con código 1 (invisible, no choca con '|')
	return intToString(x.idCiu)+sep+x.descr+sep+intToString(x.millas);
}

Ciudad ciudadFromString(string s)
{
	char sep = 1;
	Ciudad x;
	x.idCiu  = stringToInt(getTokenAt(s,sep,0));   // getTokenAt(texto, sep, índice) saca el pedazo i
	strcpy(x.descr,getTokenAt(s,sep,1).c_str()); // .c_str() convierte string → char* para strcpy
	x.millas = stringToInt(getTokenAt(s,sep,2));
	return x;
}

// ─── Vuelo: sep = 2 ───────────────────────────────────────────────────────
string vueloToString(Vuelo x)
{
	char sep = 2;
	return intToString(x.idVue)+sep+intToString(x.cap)+sep+intToString(x.idOri)+sep+intToString(x.idDes);
}

Vuelo vueloFromString(string s)
{
	char sep = 2;
	Vuelo x;
	x.idVue = stringToInt(getTokenAt(s,sep,0));
	x.cap   = stringToInt(getTokenAt(s,sep,1));
	x.idOri = stringToInt(getTokenAt(s,sep,2));
	x.idDes = stringToInt(getTokenAt(s,sep,3));
	return x;
}

// ─── Reserva: sep = 3 ─────────────────────────────────────────────────────
string reservaToString(Reserva x)
{
	char sep = 3;
	return intToString(x.idCli)+sep+intToString(x.idVue)+sep+intToString(x.cant);
}

Reserva reservaFromString(string s)
{
	char sep = 3;
	Reserva x;
	x.idCli = stringToInt(getTokenAt(s,sep,0));
	x.idVue = stringToInt(getTokenAt(s,sep,1));
	x.cant  = stringToInt(getTokenAt(s,sep,2));
	return x;
}

// ─── RCiudad: sep = 4 (EMBEbe a Ciudad, por eso usa 4, no 1) ──────────────
string rCiudadToString(RCiudad x)
{
	char sep = 4;
	return ciudadToString(x.c)+sep+intToString(x.cont);  // adentro va la ciudad ya serializada
}

RCiudad rCiudadFromString(string s)
{
	char sep = 4;
	RCiudad x;
	x.c = ciudadFromString(getTokenAt(s,sep,0));  // desarmo la ciudad que estaba adentro
	x.cont = stringToInt(getTokenAt(s,sep,1));
	return x;
}

// ─── RVuelo: sep = 5 (EMBEbe a Vuelo) ─────────────────────────────────────
string rVueloToString(RVuelo x)
{
	char sep = 5;
	return vueloToString(x.v)+sep+intToString(x.cpr)+sep+intToString(x.cpa);
}

RVuelo rVueloFromString(string s)
{
	char sep = 5;
	RVuelo x;
	x.v   = vueloFromString(getTokenAt(s,sep,0));
	x.cpr = stringToInt(getTokenAt(s,sep,1));
	x.cpa = stringToInt(getTokenAt(s,sep,2));
	return x;
}

// ─── RCliente: sep = 6 (no embebe a nadie, es 100% nuestro) ───────────────
string rClienteToString(RCliente x)
{
	char sep = 6;
	return intToString(x.idCli)+sep+intToString(x.millas);
}

RCliente rClienteFromString(string s)
{
	char sep = 6;
	RCliente x;
	x.idCli  = stringToInt(getTokenAt(s,sep,0));
	x.millas = stringToInt(getTokenAt(s,sep,1));
	return x;
}

#endif
