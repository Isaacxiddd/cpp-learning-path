// Genera SOCIOS.dat y VENTAS.dat con datos coherentes con el enunciado.
// Ejecutar desde esta carpeta: g++ gen-datos.cpp -o gen-datos.exe && gen-datos.exe
#include <cstdio>
#include <cstring>

#include "principal.hpp"
#include "../../../../lib/funciones/files.hpp"

int main()
{
    Socio socios[] = {
        {1, "", -1, fecha(2015, 1, 1),  0, 0, 0},
        {2, "",  1, fecha(2016, 3, 15), 0, 0, 0},
        {3, "",  1, fecha(2016, 6, 20), 0, 0, 0},
        {4, "",  2, fecha(2017, 2, 10), 0, 0, 0},
        {5, "",  2, fecha(2018, 11, 5), 0, 0, 0},
        {6, "",  4, fecha(2019, 7, 22), 0, 0, 0},
    };
    const char* nombres[] = {"Don Jefe", "Maria", "Luis", "Ana", "Pablo", "Sofi"};

    FILE* fs = fopen("SOCIOS.dat", "w+b");
    for(int i = 0; i < 6; i++)
    {
        strcpy(socios[i].nombre, nombres[i]);
        write<Socio>(fs, socios[i]);
    }
    fclose(fs);

    Venta ventas[] = {
        {5, 100, "notebook",  fecha(2026, 9, 1), 1000},
        {6, 100, "telefono",  fecha(2026, 9, 2), 2000},
        {3, 100, "tablet",    fecha(2026, 9, 3), 1500},
    };

    FILE* fv = fopen("VENTAS.dat", "w+b");
    for(int i = 0; i < 3; i++)
    {
        write<Venta>(fv, ventas[i]);
    }
    fclose(fv);

    return 0;
}
