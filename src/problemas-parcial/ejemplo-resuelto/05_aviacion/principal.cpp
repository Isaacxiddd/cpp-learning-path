// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  ARCHIVO: principal.cpp                                                ║
// ║  QUÉ ES:  El archivo de LÓGICA. Aquí vive el esqueleto del programa.  ║
// ║                                                                        ║
// ║  🧠 EL ESQUELETO DE TODO PROBLEMA DE PARCIAL (memorizá esto):          ║
// ║                                                                        ║
// ║   ┌─────────────────────────────────────────────────────────────┐      ║
// ║   │  FASE 1: SUBIR a memoria los archivos de CONSULTA           │      ║
// ║   │          (los que se usan como "tabla de búsqueda")         │      ║
// ║   ├─────────────────────────────────────────────────────────────┤      ║
// ║   │  FASE 2: PROCESAR el archivo de NOVEDADES, 1 sola pasada    │      ║
// ║   │          (con collFind → collGetAt → modificar → collSetAt) │      ║
// ║   ├─────────────────────────────────────────────────────────────┤      ║
// ║   │  FASE 3: MOSTRAR los listados pedidos                      │      ║
// ║   └─────────────────────────────────────────────────────────────┘      ║
// ║                                                                        ║
// ║  ¿CÓMO SABER QUÉ ES CONSULTA Y QUÉ ES NOVEDAD?                         ║
// ║  - CONSULTA: los archivos que tienen la DESCRIPCIÓN de las entidades   ║
// ║    (ciudades, vuelos). Estos se suben TODOS a memoria.                 ║
// ║  - NOVEDAD: el archivo de MOVIMIENTOS, el que tiene la acción          ║
// ║    (reservas, accidentes, ventas...). Este se lee UNA VEZ y se barre.  ║
// ╚═══════════════════════════════════════════════════════════════════════╝

#include "principal.hpp"

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  SECCIÓN 1: COMPARADORES PARA collFind                                 ║
// ║                                                                        ║
// ║  collFind necesita saber CÓMO comparar 2 cosas. El comparador          ║
// ║  devuelve 0 si son iguales, negativo si el 1° es menor, positivo si    ║
// ║  es mayor. La forma más fácil: RESTAR.                                 ║
// ║  (se busca por el ID, que es la llave que identifica a cada elemento)  ║
// ╚═══════════════════════════════════════════════════════════════════════╝

int cmpRCiudadId(RCiudad rc,int id)   // compara una RCiudad contra un int (id)
{
	return rc.c.idCiu-id;             // 0 si coinciden → collFind encontró la ciudad
}

int cmpRVueloId(RVuelo rv,int id)
{
	return rv.v.idVue-id;
}

int cmpRClienteId(RCliente rcl,int id)
{
	return rcl.idCli-id;
}

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  FASE 1: SUBIR LAS CONSULTAS A MEMORIA                                 ║
// ║                                                                        ║
// ║  ¿Por qué subimos TODO el archivo a una Coll?                          ║
// ║  Porque después, al procesar cada novedad, vamos a necesitar BUSCAR    ║
// ║  el vuelo/ciudad correspondiente. Si lo buscáramos releyendo el        ║
// ║  archivo cada vez, tardaríamos muchísimo. En memoria es instantáneo.   ║
// ║                                                                        ║
// ║  El patrón de lectura es SIEMPRE el mismo (memorizalo):                ║
// ║  ┌──────────────────────────────────────────────────────────────┐      ║
// ║  │  FILE* f = fopen("ARCHIVO.dat","r+b");   // 1) abrir          │      ║
// ║  │  T t = read<T>(f);                       // 2) leer el 1º      │      ║
// ║  │  while( !feof(f) )                       // 3) mientras no...  │      ║
// ║  │  {                                        //    llegue al fin    │      ║
// ║  │      ...procesar t...                    // 4) usar el dato     │      ║
// ║  │      t = read<T>(f);                     // 5) leer el SIGUIENTE│      ║
// ║  │  }                                                              │      ║
// ║  │  fclose(f);                             // 6) cerrar           │      ║
// ║  └──────────────────────────────────────────────────────────────┘      ║
// ║  (leer ANTES del while y al FINAL del while = "lectura anticipada";    ║
// ║   así feof() se evalúa correctamente)                                  ║
// ╚═══════════════════════════════════════════════════════════════════════╝

// Sube todas las CIUDADES a una Coll<RCiudad>, con el contador en 0.
// El contador NO viene del archivo: nace aquí, en la subida.
Coll<RCiudad> ciudadesSubir()
{
	Coll<RCiudad> cCiu = coll<RCiudad>();     // 1) creo la Coll vacía

	FILE* f = fopen("CIUDADES.dat","r+b");    // 2) abro el archivo binario
	Ciudad c = read<Ciudad>(f);               // 3) leo la primera ciudad
	while( !feof(f) )                         // 4) ¿llegué al final? si no, entro
	{
		RCiudad rc;          // envuelvo la ciudad leída
		rc.c = c;            //   → le copio la ciudad original
		rc.cont = 0;         //   → el contador arranca en 0
		collAdd<RCiudad>(cCiu,rc,rCiudadToString);  // 5) la agrego a la Coll
		c = read<Ciudad>(f); // 6) leo la SIGUIENTE ciudad
	}
	fclose(f);                // 7) cierro el archivo
	return cCiu;              // 8) devuelvo la Coll ya cargada
}

// Sube todos los VUELOS a una Coll<RVuelo>, con los contadores en 0.
Coll<RVuelo> vuelosSubir()
{
	Coll<RVuelo> cVue = coll<RVuelo>();

	FILE* f = fopen("VUELOS.dat","r+b");
	Vuelo v = read<Vuelo>(f);
	while( !feof(f) )
	{
		RVuelo rv;
		rv.v = v;
		rv.cpr = 0;   // plazas rechazadas arrancan en 0
		rv.cpa = 0;   // plazas aceptadas arrancan en 0
		collAdd<RVuelo>(cVue,rv,rVueloToString);
		v = read<Vuelo>(f);
	}
	fclose(f);
	return cVue;
}

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  FASE 2: PROCESAR CADA NOVEDAD                                         ║
// ║                                                                        ║
// ║  Este es el CORAZÓN del programa. Se llama UNA VEZ POR CADA reserva.  ║
// ║                                                                        ║
// ║  🎯 EL PATRÓN DE ORO (el que se repite en el 99% de los parciales):    ║
// ║  ┌──────────────────────────────────────────────────────────────┐      ║
// ║  │  int pos = collFind<T,K>(coll, llave, cmp, fromString);      │      ║
// ║  │  T t   = collGetAt<T>(coll, pos, fromString);   // leer      │      ║
// ║  │  t.algo = ...;                                  // MODIFICAR  │      ║
// ║  │  collSetAt<T>(coll, t, pos, toString);          // escribir   │      ║
// ║  └──────────────────────────────────────────────────────────────┘      ║
// ║  - collFind:  ¿en qué posición está el elemento con esa llave?         ║
// ║  - collGetAt: dame una COPIA de ese elemento (por valor, no por ref)  ║
// ║  - modificar: cambio la copia                                          ║
// ║  - collSetAt: escribo la copia modificada de vuelta en su posición     ║
// ║  ⚠️  SI NO HACÉS collSetAt, tus cambios SE PIERDEN (se modifica la   ║
// ║      copia, no el original).                                           ║
// ║                                                                        ║
// ║  🎯 EL PATRÓN DE DESCUBRIMIENTO (cuando la entidad NO existe en       ║
// ║  ningún archivo, como el cliente aquí):                                ║
// ║  ┌──────────────────────────────────────────────────────────────┐      ║
// ║  │  int pos = collFind(...);                                     │      ║
// ║  │  if( pos < 0 )                        // no existe?            │      ║
// ║  │  {                                   // → lo CREO              │      ║
// ║  │      T nuevo;                        //   arranca en 0         │      ║
// ║  │      pos = collAdd(coll, nuevo);     //   lo agrego            │      ║
// ║  │  }                                                             │      ║
// ║  │  T t = collGetAt(...);  t.algo += x;  collSetAt(...);          │      ║
// ║  └──────────────────────────────────────────────────────────────┘      ║
// ╚═══════════════════════════════════════════════════════════════════════╝

void reservaProcesar(Reserva r,Coll<RCiudad>& cCiu,Coll<RVuelo>& cVue,Coll<RCliente>& cCli)
{
	// ── 1) Busco el VUELO de la reserva ──────────────────────────────────
	// La reserva guarda idVue. Necesito el vuelo para saber su capacidad y
	// qué ciudades une (origen/destino).
	int posV = collFind<RVuelo,int>(cVue,r.idVue,cmpRVueloId,rVueloFromString);
	RVuelo rv = collGetAt<RVuelo>(cVue,posV,rVueloFromString);

	// ── 2) PUNTO 1: incremento el contador de la CIUDAD DESTINO ──────────
	// El vuelo me dice a qué ciudad va (idDes). Esa ciudad fue "elegida
	// de destino" por este grupo → le sumo 1 a su contador.
	int posDes = collFind<RCiudad,int>(cCiu,rv.v.idDes,cmpRCiudadId,rCiudadFromString);
	RCiudad rcDes = collGetAt<RCiudad>(cCiu,posDes,rCiudadFromString);
	rcDes.cont++;                                        // contar
	collSetAt<RCiudad>(cCiu,rcDes,posDes,rCiudadToString); // GUARDAR (clave)

	// ── 3) Decido UNA sola vez si la reserva es aceptada ─────────────────
	// ¿Entran las plazas pedidas en lo que queda del vuelo?
	//   plazas ya aceptadas + plazas pedidas <= capacidad total?
	// 💡 IMPORTANTE: se decide UNA VEZ y se usa para TODOS los puntos.
	//    (mi primer intento decidía la aceptación dos veces por separado
	//     y por eso los resultados daban mal → ERROR CLÁSICO)
	bool aceptada = rv.cpa + r.cant <= rv.v.cap;

	// ── 4) PUNTO 2: actualizo las plazas del vuelo ───────────────────────
	if( aceptada )
	{
		rv.cpa += r.cant;   // entraron: sumo a las aceptadas
	}
	else
	{
		rv.cpr += r.cant;   // no entraron: sumo a las rechazadas
	}
	collSetAt<RVuelo>(cVue,rv,posV,rVueloToString);   // GUARDAR de nuevo

	// ── 5) PUNTO 3: si la reserva fue RECHAZADA, el cliente no acumula ────
	// Las millas solo se ganan volando, y volando = reserva aceptada.
	if( !aceptada )
	{
		return;   // chau, me voy sin tocar a los clientes
	}

	// ── 6) Calculo las millas del cliente ─────────────────────────────────
	// millas = |millas del destino − millas del origen| × plazas reservadas
	// (el |abs| es para que nunca dé negativo si el origen vale más)
	int posOri = collFind<RCiudad,int>(cCiu,rv.v.idOri,cmpRCiudadId,rCiudadFromString);
	RCiudad rcOri = collGetAt<RCiudad>(cCiu,posOri,rCiudadFromString);
	int millas = abs(rcDes.c.millas-rcOri.c.millas)*r.cant;

	// ── 7) DESCUBRIMIENTO del cliente ─────────────────────────────────────
	// No existe archivo de clientes → el primer vuelo de cada cliente lo
	// "descubre": lo creo recién cuando aparece.
	int posCli = collFind<RCliente,int>(cCli,r.idCli,cmpRClienteId,rClienteFromString);
	if( posCli<0 )                  // ¿todavía no existe?
	{
		RCliente rcl;
		rcl.idCli = r.idCli;        // le guardo su id
		rcl.millas = 0;             // arranca sin millas
		posCli = collAdd<RCliente>(cCli,rcl,rClienteToString);  // lo creo
	}

	// ── 8) Le sumo las millas y GUARDO ────────────────────────────────────
	RCliente rcl = collGetAt<RCliente>(cCli,posCli,rClienteFromString);
	rcl.millas += millas;
	collSetAt<RCliente>(cCli,rcl,posCli,rClienteToString);
}

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  FASE 3: MOSTRAR LOS LISTADOS                                          ║
// ║                                                                        ║
// ║  Patrón de recorrido de una Coll (memorizalo):                         ║
// ║  ┌──────────────────────────────────────────────────────────────┐      ║
// ║  │  collReset<T>(c);                 // 1) rebobinar             │      ║
// ║  │  while( collHasNext<T>(c) )       // 2) mientras quede algo   │      ║
// ║  │  {                                //                           │      ║
// ║  │      T t = collNext<T>(c,fromString); // 3) trae el siguiente │      ║
// ║  │      ...mostrar...                // 4) uso                   │      ║
// ║  │  }                                                             │      ║
// ║  └──────────────────────────────────────────────────────────────┘      ║
// ╚═══════════════════════════════════════════════════════════════════════╝

// PUNTO 1: para cada ciudad, cuántos grupos la eligieron de destino.
void punto1Mostrar(Coll<RCiudad> cCiu)
{
	collReset<RCiudad>(cCiu);    // vuelvo al principio de la Coll
	cout << "PUNTO 1: grupos por ciudad" << endl;
	while( collHasNext<RCiudad>(cCiu) )
	{
		RCiudad rc = collNext<RCiudad>(cCiu,rCiudadFromString);
		cout << "  " << rc.c.descr << " (" << rc.c.idCiu << "): " << rc.cont << " grupos" << endl;
	}
}

// PUNTO 2: por cada vuelo, plazas rechazadas y si sale completo o no.
void punto2Mostrar(Coll<RVuelo> cVue)
{
	collReset<RVuelo>(cVue);
	cout << "PUNTO 2: plazas por vuelo" << endl;
	while( collHasNext<RVuelo>(cVue) )
	{
		RVuelo rv = collNext<RVuelo>(cVue,rVueloFromString);
		// Salió completo si las plazas ACEPTADAS llenaron toda la capacidad.
		string estado = (rv.cpa==rv.v.cap)?"completo":"incompleto";
		cout << "  Vuelo " << rv.v.idVue << ": rechazadas=" << rv.cpr << " -> " << estado << endl;
	}
}

// PUNTO 3: por cada cliente, total de millas acumuladas.
void punto3Mostrar(Coll<RCliente> cCli)
{
	collReset<RCliente>(cCli);
	cout << "PUNTO 3: millas por cliente" << endl;
	while( collHasNext<RCliente>(cCli) )
	{
		RCliente rcl = collNext<RCliente>(cCli,rClienteFromString);
		cout << "  Cliente " << rcl.idCli << ": " << rcl.millas << " millas" << endl;
	}
}

// ╔═══════════════════════════════════════════════════════════════════════╗
// ║  MAIN: EL ORQUESTADOR                                                 ║
// ║  Solo sabe coordinar las 3 fases. No tiene lógica de negocio adentro. ║
// ╚═══════════════════════════════════════════════════════════════════════╝

int main()
{
	// ── FASE 1: subir las consultas a memoria ─────────────────────────────
	Coll<RCiudad> cCiu = ciudadesSubir();      // todas las ciudades, cont=0
	Coll<RVuelo>  cVue = vuelosSubir();        // todos los vuelos, cpr=cpa=0
	Coll<RCliente> cCli = coll<RCliente>();    // los clientes se descubren, arranca vacía

	// ── FASE 2: barrer el archivo de NOVEDADES una sola vez ───────────────
	// Mismo patrón de lectura anticipada de siempre.
	FILE* f = fopen("RESERVAS.dat","r+b");
	Reserva r = read<Reserva>(f);
	while( !feof(f) )
	{
		reservaProcesar(r,cCiu,cVue,cCli);   // proceso cada reserva
		r = read<Reserva>(f);                // leo la siguiente
	}
	fclose(f);

	// ── FASE 3: emitir los listados ────────────────────────────────────────
	punto1Mostrar(cCiu);
	punto2Mostrar(cVue);
	punto3Mostrar(cCli);

	return 0;
}
