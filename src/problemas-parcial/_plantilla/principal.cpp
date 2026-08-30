#include <iostream>
#include "../../../lib/funciones/files.hpp"
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "principal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

// ─── Helpers ─────────────────────────────────────────────────────────────────

int cmpRRegistroId(RRegistro re, int id)
{
    return re.r.id - id;
}

// ─── Cargar maestro ──────────────────────────────────────────────────────────

Coll<RRegistro> registrosSubir()
{
    Coll<RRegistro> c = coll<RRegistro>();
    // TODO: leer archivo maestro y subir a coleccion
    return c;
}

// ─── Procesar movimientos ─────────────────────────────────────────────────────

void punto1Procesar(Registro mov, Coll<RRegistro>& c)
{
    // TODO: lógica punto 1
}

void punto2Procesar(Registro mov, Coll<RRegistro>& c)
{
    // TODO: lógica punto 2
}

// ─── Mostrar resultados ───────────────────────────────────────────────────────

void punto1Mostrar(Coll<RRegistro> c)
{
    // TODO: recorrer y mostrar
}

void punto2Mostrar(Coll<RRegistro> c)
{
    // TODO: recorrer y mostrar
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main()
{
    Coll<RRegistro> c = registrosSubir();

    FILE* f = fopen("MOVIMIENTOS.dat", "r+b");
    Registro mov = read<Registro>(f);
    while (!feof(f))
    {
        punto1Procesar(mov, c);
        punto2Procesar(mov, c);

        mov = read<Registro>(f);
    }
    fclose(f);

    punto1Mostrar(c);
    punto2Mostrar(c);
    
    std::cin.get();
    return 0;
}
