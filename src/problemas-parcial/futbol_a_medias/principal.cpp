
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

int cmpREquipoId(REquipo e,int id)
{
    return e.e.idEq-id;
}

void equipoActualizarPtos(int idEq,int ptos,Coll<REquipo>& cEq)
{
    int pos = collFind<REquipo,int>(cEq,idEq,cmpREquipoId,rEquipoFromString);
    REquipo re = collGetAt<REquipo>(cEq,pos,rEquipoFromString);
    re.acum+=ptos;
    collSetAt<REquipo>(cEq,re,pos,rEquipoToString);        
}

void punto1Procesar(Resultado r,Coll<REquipo>& cEq)
{
    int ptos1 = r.codRes<0?3:r.codRes==0?1:0;
    int ptos2 = r.codRes>0?3:r.codRes==0?1:0;
    equipoActualizarPtos(r.idEq1,ptos1,cEq);
    equipoActualizarPtos(r.idEq2,ptos2,cEq);
}

int cmpREstadioEs(REstadio re,string es)
{
    return cmpString(re.est,es);
}

REstadio estadioDescubrir(string es,Coll<REstadio>& cEs)
{
    int pos = collFind<REstadio,string>(cEs,es,cmpREstadioEs,rEstadioFromString);
    if( pos<0 )
    {
        REstadio re = rEstadio(es,0,0);
        pos = collAdd<REstadio>(cEs,re,rEstadioToString);
    }

     return collGetAt<REstadio>(cEs,pos,rEstadioFromString);   
}

void estadioActualizar(REstadio re,Coll<REstadio>& cEs)
{
    int pos = collFind<REstadio,string>(cEs,re.est,cmpREstadioEs,rEstadioFromString);
    collSetAt<REstadio>(cEs,re,pos,rEstadioToString);        
}

void punto2Procesar(Resultado r,Coll<REstadio>& cEs)
{
    string es = r.estadio;
    REstadio re = estadioDescubrir(es,cEs);
    re.cpj++;
    if( r.codRes==0 )
    {
        re.cpe++;
    }

    estadioActualizar(re,cEs);
}

int cmpREquipo(REquipo a,REquipo b)
{
    int sa = a.acum+a.e.puntos;    
    int sb = b.acum+b.e.puntos;    
    return sb-sa;
}

void punto1Mostrar(Coll<REquipo> cEq)
{
    // ordenar cEq descr. por puntos+acum
    collSort<REquipo>(cEq,cmpREquipo,rEquipoFromString,rEquipoToString);    

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
