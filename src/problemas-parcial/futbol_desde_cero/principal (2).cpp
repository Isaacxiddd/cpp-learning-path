
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
    return {};
}

void punto1Procesar(Resultado r,Coll<REquipo>& cEq)
{
    // calculo cuantos puntos le corresponden a cada equipo
    // busco cada equipo en cEq y les sumo los puntos que corresponda.
}

void punto2Procesar(Resultado r,Coll<REstadio>& cEs)
{
    // descubro el estadio en cEs
    // sumo 1 al cpj
    // si corresponde sumo 1 a cpe
}

void punto1Mostrar(Coll<REquipo> cEq)
{
    // ordeno cEq por puntos+acum decreciente
    // recorro cEq y muestro
}

void punto2Mostrar(Coll<REstadio> cEs)
{
    // recorro cEs y muestro
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
