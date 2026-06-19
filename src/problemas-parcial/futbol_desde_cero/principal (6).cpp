
#include <iostream>
#include "biblioteca/funciones/millis.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/parte1/Fecha.hpp"
#include "biblioteca/tads/parte1/Timer.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"

#include "principal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

Coll<REquipo> equiposSubir()
{
    // abro EQUIPOS.dat
    // creo una Coll<REquipo> vacia
    // lo recorro del primero al ultimo
    // le agrego REquipos a la coll vacia
    // cierro el archivo
    // retorno la coll 
    return {};
}

void punto1Procesar(Resultado r,Coll<REquipo>& cEq)
{
    // veo que equipo gano
    // lo busco en cEq y le sumo 3
    // si hubo empate => busco ambos equipos y les sumo 1 a c/u
}

void punto2Procesar(Resultado r,Coll<REstadio>& cEs)
{
    // descubro el estadio (lo busco en cEs y si no lo encuentro => lo agrego)
    // le sumo 1 al cpj
    // si corresponde le sumo 1 al cpe
}

void punto1Mostrar(Coll<REquipo> cEq)
{
    // ordeno cEq por puntos+acum decreciente
    // recorro y muestro
}

void punto2Mostrar(Coll<REstadio> cEs)
{
    // recorro y muestro
}

int main()
{
    Coll<REquipo> cEq = equiposSubir();
    Coll<REstadio> cEs = coll<REstadio>();

    FILE* f = fopen("RESULTADOS.dat","r+b");    

    Resultado r = read<Resultado>(f);
    while( !feof(f) )
    {
        punto1Procesar(r,cEq);
        punto2Procesar(r,cEs);
        r = read<Resultado>(f);
    }

    punto1Mostrar(cEq);
    punto2Mostrar(cEs);

    fclose(f);
    return 0;
}
