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

// Wrap struct: el socio del archivo + su liquidacion actual acumulada.
struct RSocio
{
    Socio s;
    double acum;
};

Map<int, RSocio> sociosSubir()
{
    Map<int, RSocio> mSoc = map<int, RSocio>();

    FILE* f = fopen("SOCIOS.dat", "rb");
    Socio s = read<Socio>(f);
    while( !feof(f) )
    {
        RSocio r = {s, 0};
        mapPut<int, RSocio>(mSoc, s.idSocio, r);
        s = read<Socio>(f);
    }
    fclose(f);

    return mSoc;
}

void ventaProcesar(Venta v, Map<int, RSocio>& mSoc)
{
    RSocio* r = mapGet<int, RSocio>(mSoc, v.idSocio);
    if( r == NULL )
    {
        return;
    }

    r->s.totalVentasAcumuladas += v.importe;

    double monto = v.importe * 0.30;
    int id = v.idSocio;
    while( id != -1 )
    {
        r = mapGet<int, RSocio>(mSoc, id);
        if( r == NULL )
        {
            break;
        }
        r->acum += monto;
        id = r->s.idSocioRef;
        monto *= 0.30;
    }
}

void sociosBajar(Map<int, RSocio> mSoc)
{
    FILE* f = fopen("SOCIOS.dat", "r+b");
    Socio s = read<Socio>(f);
    while( !feof(f) )
    {
        RSocio* r = mapGet<int, RSocio>(mSoc, s.idSocio);
        if( r != NULL )
        {
            s.liquidacionAnterior = r->acum;
            s.liquidacionesAcumuladas += r->acum;
            s.totalVentasAcumuladas = r->s.totalVentasAcumuladas;

            seek<Socio>(f, filePos<Socio>(f) - 1);
            write<Socio>(f, s);
        }
        s = read<Socio>(f);
    }
    fclose(f);
}

void punto1Mostrar(Map<int, RSocio> mSoc)
{
    mapSortByKeys<int, RSocio>(mSoc, cmpKK);

    cout << "  id  nombre                  ingreso     liqAnterior   liqActual   variacion   acumulado" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    mapReset<int, RSocio>(mSoc);
    while( mapHasNext<int, RSocio>(mSoc) )
    {
        RSocio* r = mapNextValue<int, RSocio>(mSoc);

        int anio = fechaGetAnio(r->s.fechaIngreso);
        int mes = fechaGetMes(r->s.fechaIngreso);
        int dia = fechaGetDia(r->s.fechaIngreso);

        double anterior = r->s.liquidacionAnterior;
        double actual = r->acum;
        double acumulado = r->s.liquidacionesAcumuladas + r->acum;

        if( anterior != 0 )
        {
            double pct = ((actual - anterior) / anterior) * 100;
            printf("%4d  %-20s   %02d/%02d/%04d   %10.2f   %10.2f   %8.2f%%   %10.2f\n",
                   r->s.idSocio, r->s.nombre, dia, mes, anio, anterior, actual, pct, acumulado);
        }
        else
        {
            printf("%4d  %-20s   %02d/%02d/%04d   %10.2f   %10.2f   %8s   %10.2f\n",
                   r->s.idSocio, r->s.nombre, dia, mes, anio, anterior, actual, "-", acumulado);
        }
    }
}

int main()
{
    Map<int, RSocio> mSoc = sociosSubir();

    FILE* f = fopen("VENTAS.dat", "r+b");
    Venta v = read<Venta>(f);
    while( !feof(f) )
    {
        ventaProcesar(v, mSoc);
        v = read<Venta>(f);
    }
    fclose(f);

    sociosBajar(mSoc);

    punto1Mostrar(mSoc);

    return 0;
}