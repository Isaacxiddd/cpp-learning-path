#include <cstdio>
#include <iostream>
#include "principal.hpp"

#include "../../../../lib/funciones/files.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/tads/parte1/Fecha.hpp"
#include "../../../../lib/tads/parte2/Array.hpp"
#include "../../../../lib/tads/parte2/Map.hpp"

using std::cout;
using std::endl;
using std::string;

// Se pide:
// 1. Imprimir un listado, ordenado por idSocio, detallando su nombre, fecha de ingreso, 
// liquidaciÃ³n anterior, liquidaciÃ³n actual (la que surge de procesar las ventas), 
// porcentaje de incremento o decremento de la liquidaciÃ³n actual respecto a la anterior, 
// y el total de acumulado desde su ingreso a la empresa.
// 2. Actualice los campos liquidacionAnterior, liquidacionAcumulada y totalVentasAcumuladas 
// del archivo SOCIOS.dat.




RSocio rSocio(Socio socio, double sumLiqAct){
    RSocio rs;
    rs.s = socio;
    rs.sumLiqAct = sumLiqAct;
    return rs;
}

Map<int, RSocio> sociosSubir()
{
    FILE* f = fopen("SOCIOS.dat", "r+b");
    Socio s = read<Socio>(f);
    Map<int, RSocio> mapRs = map<int, RSocio>();

    while ( !feof(f) ){
        int idSoc = s.idSocio;
        RSocio rs = rSocio(s, 0);

        mapPut<int, RSocio>(mapRs, idSoc, rs);
        s = read<Socio>(f);
    }

    fclose(f);
    return mapRs;
}
//  
// 
//

// ESTE ES EL TRABAJO !!!
// socio
// socio
//   ^ le da el 30%   
// socio <--- venta
// socio
// key value
// key2 value2
void ventaProcesar(Venta v, Map<int, RSocio>& mSoc)
{
    RSocio* rs = mapGet<int, RSocio>(mSoc, v.idSocio);
    if( rs == NULL )
    {
        return;
    }

    rs->s.totalVentasAcumuladas += v.importe;
    double monto = v.importe * 0.30;
    int id = v.idSocio;
    int pasos = 0;

    while( id != -1 && pasos < mapSize<int, RSocio>(mSoc) )
    {
        rs = mapGet<int, RSocio>(mSoc, id);
        if( rs == NULL )
        {
            break;
        }

        rs->sumLiqAct += monto;

        id = rs->s.idSocioRef;
        monto *= 0.30;
        pasos++;
    }
}

double tasaCambioEntreLiquidaciones(RSocio rs){
    double ac = rs.sumLiqAct;
    double an = rs.s.liquidacionAnterior;
    return  (ac * 100) / an - 100;
}


void sumLiqActAlTotal(RSocio& rs){
    rs.s.liquidacionesAcumuladas += rs.sumLiqAct;
}


// La key que guarda el map es el mismo id que esta contenido dentro de algun
// rsocio-socio
void punto1Mostrar(Map<int,RSocio> mSoc)
{
mapSortByKeys<int, RSocio>(mSoc, cmpKK<int>);
mapReset<int, RSocio>(mSoc);
while(mapHasNext<int, RSocio>(mSoc))
{
 int socioActual = mapNextKey<int, RSocio>(mSoc);
 RSocio* datos = mapGet<int, RSocio>(mSoc, socioActual);
 cout << "nombre "<< datos->s.nombre <<endl;
 cout << "id "<< datos->s.nombre <<endl;
  cout << "fecha de ingreso "<< datos->s.fechaIngreso <<endl;
 cout << "liquidacion actual "<< datos->sumLiqAct <<endl;
 cout << "liquidacion anterior "<< datos->s.totalVentasAcumuladas <<endl;
 cout << "liquidacion total "<< datos->sumLiqAct <<endl;


}


}

int main()
{
    // subo los socios a memoria
    Map<int, RSocio> mSoc = sociosSubir();
    // recorro ventas
    FILE* f = fopen("VENTAS.dat", "r+b");
    Venta v = read<Venta>(f);

    while( !feof(f) )
    {
        // proceso la venta
        ventaProcesar(v, mSoc);
        // leo la siguiente venta
        v = read<Venta>(f);
    }

    // muestro los resultados
    punto1Mostrar(mSoc);
    fclose(f);
    return 0;
}