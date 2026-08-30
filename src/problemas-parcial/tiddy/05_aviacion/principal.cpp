#include <iostream>
#include "../../../../lib/funciones/files.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"
#include "../../../../lib/funciones/Coll.hpp"
#include "principal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

// ─── Enunciado ─────────────────────────────────────────────────────────────────
// Archivos:
//   CIUDADES.dat   → consulta (se sube a memoria)
//   VUELOS.dat     → consulta (se sube a memoria)
//   RESERVAS.dat   → novedades (se recorre una sola vez)
//
// Una reserva se acepta si cpaVuelo + cant <= cap. Si se acepta, el cliente
// acumula millas = |millasCiudadDestino - millasCiudadOrigen| * cant.
// Se pide:
//   1) Por cada ciudad, la cantidad de grupos que la eligieron de destino.
//   2) Por cada vuelo, plazas rechazadas y si salio completo o incompleto
//      (completo si cpa == cap).
//   3) Por cada cliente, el total de millas acumuladas.

// ─── Estructuras de trabajo ───────────────────────────────────────────────────


struct RCiudad
{
	Ciudad c;
	int cont;
};

struct RVuelo
{
	Vuelo v;
	int cpa;
	int cpr;
};

struct RCliente
{
	int idCli;
	int millas;
};

// ─── Subir consultas a memoria ────────────────────────────────────────────────

Coll<Ciudad> ciudadesSubir()
{
	Coll<Ciudad> c = coll<Ciudad>();
	FILE* f = fopen("CIUDADES.dat", "r+b");
	Ciudad r = read<Ciudad>(f);
	while (!feof(f))
	{
		collAdd<Ciudad>(c, r, ciudadToString);
		r = read<Ciudad>(f);
	}
	fclose(f);
	return c;
}

Coll<Vuelo> vuelosSubir()
{
	Coll<Vuelo> c = coll<Vuelo>();
	FILE* f = fopen("VUELOS.dat", "r+b");
	Vuelo r = read<Vuelo>(f);
	while (!feof(f))
	{
		collAdd<Vuelo>(c, r, vueloToString);
		r = read<Vuelo>(f);
	}
	fclose(f);
	return c;
}


RCliente rClienteFromString(string s)
{
	char sep = 6;
	RCliente x;
	x.idCli  = stringToInt(getTokenAt(s,sep,0));
	x.millas = stringToInt(getTokenAt(s,sep,1));
	return x;
}
// ─── Inicializar estructuras de trabajo ───────────────────────────────────────

Coll<RCiudad> rCiudadesIni(Coll<Ciudad> cCiudades)
{
	Coll<RCiudad> c = coll<RCiudad>();
	// TODO: copiar cada ciudad a un RCiudad con cont = 0
	return c;
}

string rCiudadToString(RCiudad x){
    char sep = 4;
    return ciudadToString(x.c)+sep+intToString(x.cont);

}


int cmpCiudadId(Ciudad a , Ciudad b){
return a.idCiu - b.idCiu;
}

RCiudad RCiudadFromString(string a){
 char sep = 4;
 RCiudad x;
 x.c = ciudadFromString(getTokenAt(a,sep,0));
 x.cont = stringToInt(getTokenAt(a,sep,1));
 return x;
};

Coll<RVuelo> rVuelosIni(Coll<Vuelo> cVuelos)
{
	Coll<RVuelo> c = coll<RVuelo>();
	// TODO: copiar cada vuelo a un RVuelo con cpa = 0 y cpr = 0
	return c;
}



// ─── Busquedas ────────────────────────────────────────────────────────────────

int cmpRCiudadId(RCiudad a, int idBuscado)
{
	return a.c.idCiu - idBuscado;
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


int buscarCiudad(int idCiu, Coll<RCiudad> c)
{
	int inf = 0;
	int sup = collSize<RCiudad>(c) - 1;

	while (inf <= sup)
	{
		int medio = (inf + sup) / 2;
		RCiudad s = collGetAt<RCiudad>(c, medio, RCiudadFromString);

		int cmp = cmpRCiudadId(s, idCiu);
		if (cmp == 0)
		{
			return medio;
		}
		if (cmp < 0)
		{
			inf = medio + 1;
		}
		else
		{
			sup = medio - 1;
		}
	}

	return -1;
}

int cmpRVueloId(RVuelo a, int idBuscado)
{
	return a.v.idVue - idBuscado;
}

int cmpRClienteId(RCliente a, int idBuscado)
{
	return a.idCli - idBuscado;
}
int buscarVuelo(int idVue, Coll<RVuelo> c)
{
	// TODO: busqueda binaria (c ordenada por idVue), devolver indice o -1
    int inf = 0; 
    int sup = collSize<RVuelo>(c) - 1;
    while(inf <= sup){
    int medio = (inf + sup)/2;

    RVuelo s = collGetAt<RVuelo>(c, medio, rVueloFromString);
    int cmp = cmpRVueloId(s, idVue);
    if(cmp == 0){
        return medio;
    }else if(medio > 0)
    {
        medio = medio - 1;
    }
    else{
        medio = medio + 1;

    }

    }
	return -1;
}

int buscarCliente(int idCli, Coll<RCliente> c)
{
    int inf = 0;
    int sup = collSize<RCliente>(c) - 1;
    while(inf < sup){
        int medio = (inf + sup)/2;
        RCliente s = collGetAt<RCliente>(c, medio, rClienteFromString);
        if(medio == 0){return medio;}else if(medio > 0){medio = medio - 1;}else{medio = medio + 1;}
    
    }
	// TODO: busqueda por idCli, devolver indice o -1
	return -1;
}

// ─── Procesar una reserva ─────────────────────────────────────────────────────

void procesarReserva(Reserva r, Coll<RCiudad>& cCiudades, Coll<RVuelo>& cVuelos, Coll<RCliente>& cClientes)
{
	// TODO:
	//   1) buscar el vuelo de r.idVue (buscarVuelo)
	//   2) sumar 1 al cont de la ciudad de destino del vuelo (buscarCiudad)
	//   3) si r.cant <= v.cap - v.cpa: aceptada -> cpa += r.cant y acumular
	//      millas en el cliente (buscarCliente / descubrimiento)
	//      sino: rechazada -> cpr += r.cant
   int post = buscarVuelo( r.idVue, cVuelos);
   RVuelo rv = collGetAt<RVuelo>(cVuelos, post, rVueloFromString);  // bajo el vuelo
   int postC = buscarCiudad(rv.v.idDes, cCiudades); 
   RCiudad s = collGetAt<RCiudad>(cCiudades, post,RCiudadFromString);
   s.cont = s.cont + 1;
   collSetAt<RCiudad>(cCiudades,s,post,rCiudadToString);
    
}

// ─── Mostrar ─────────────────────────────────────────────────────────────────

void mostrarCiudades(Coll<RCiudad> c)
{
	// TODO: por cada ciudad, idCiu, descr, cantidad de grupos que la eligieron de destino

    collReset<RCiudad>(c);
    while(collHasNext<RCiudad>(c)){
    
   RCiudad rc = collNext<RCiudad>( c,RCiudadFromString);

    
    }
}

void mostrarVuelos(Coll<RVuelo> c)
{
	// TODO: por cada vuelo, idVue, plazas rechazadas, completo o incompleto
}

void mostrarClientes(Coll<RCliente> c)
{
	// TODO: por cada cliente, idCli y total de millas
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main()
{
	Coll<Ciudad> cCiudades = ciudadesSubir();
	Coll<Vuelo> cVuelos = vuelosSubir();

	Coll<RCiudad> cRCiudad = rCiudadesIni(cCiudades);
	Coll<RVuelo> cRVuelo = rVuelosIni(cVuelos);
	Coll<RCliente> cClientes = coll<RCliente>();

	FILE* f = fopen("RESERVAS.dat", "r+b");
	Reserva r = read<Reserva>(f);
	while (!feof(f))
	{
		procesarReserva(r, cRCiudad, cRVuelo, cClientes);

		r = read<Reserva>(f);
	}
	fclose(f);

	mostrarCiudades(cRCiudad);
	mostrarVuelos(cRVuelo);
	mostrarClientes(cClientes);

	std::cin.get();
	return 0;
}
