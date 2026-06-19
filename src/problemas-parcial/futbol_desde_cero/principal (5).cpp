
#include <iostream>
#include "lib/funciones/millis.hpp"
#include "lib/funciones/files.hpp"
#include "lib/funciones/strings.hpp"
#include "lib/funciones/tokens.hpp"
#include "lib/tads/parte1/Fecha.hpp"
#include "lib/tads/parte1/Timer.hpp"
#include "lib/tads/parte1/Coll.hpp"
#include "lib/tads/parte2/Array.hpp"
#include "lib/tads/parte2/List.hpp"
#include "lib/tads/parte2/Map.hpp"
#include "lib/tads/parte2/Queue.hpp"
#include "lib/tads/parte2/Stack.hpp"

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
    // calculo cuantos puntos le tocan a cada equipo
    // busco eq1 y le sumo
    // busco eq2 y le sumo
}

void punto2Procesar(Resultado r,Coll<REstadio>& cEs)
{
    // descubro el estadio
    // sumo 1 al cpj
    // si corresponde sumo 1 al cpe
}

void punto1Mostrar(Coll<REquipo> cEq)
{
    // ordenar cEq descr. por puntos+acum
    // recorrer y mostrar
}
void punto2Mostrar(Coll<REstadio> cEs)
{
    // recorrer y mostrar cpj y cpe
}

int main()
{
    // colecciones a memoria
    Coll<REquipo> cEq = equiposSubir();
    Coll<REstadio> cEs = coll<REstadio>();

    // barro archivo de movimientos
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
