
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

double porcentaje(int cantTrabajadores,int cantAccidentes)
{
    return 0;
}


Coll<REmpresa> empresasSubir()
{
    return {};
}

void punto1Procesar(Accidente a,Coll<REmpresa>& cEmp)
{
    // busco la empresa 
    // incremento el contador
}

void punto2Procesar(Accidente a,Coll<RTrabajador>&  cTra)
{
    // descubro al trabajador
    // acumulo los dias de licencia
}

void punto1Mostrar(Coll<REmpresa> cEmp)
{
}

void punto2Mostrar(Coll<RTrabajador> cTra)
{
}

int main()
{
    Coll<REmpresa> cEmp = empresasSubir();
    Coll<RTrabajador> cTra = coll<RTrabajador>();

    FILE* f = fopen("ACCIDENTES.dat","r+b");
    
    Accidente a = read<Accidente>(f);
    while( !feof(f) )
    {
        punto1Procesar(a,cEmp);
        punto2Procesar(a,cTra);

        a = read<Accidente>(f);
    }

    punto1Mostrar(cEmp);
    punto2Mostrar(cTra);


    fclose(f);
    return 0;
}
