#include <iostream>
#include "../../../lib/funciones/millis.hpp"
#include "../../../lib/funciones/files.hpp"
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "../../../lib/tads/parte1/Fecha.hpp"
#include "../../../lib/tads/parte1/Timer.hpp"
#include "../../../lib/tads/parte1/Coll.hpp"
#include "../../../lib/tads/parte2/Array.hpp"
#include "../../../lib/tads/parte2/List.hpp"
#include "../../../lib/tads/parte2/Map.hpp"
#include "../../../lib/tads/parte2/Queue.hpp"
#include "../../../lib/tads/parte2/Stack.hpp"

#include "principal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;
//La duración de los cuentos es muy corta. De este modo, si un mismo usuario reproduce más de una vez un mismo cuento, será porque lo quiso escuchar varias veces.

//Se pide:
//Un listado ordenado por cuento, indicando cuántas reproducciones completas tuvo. Cuántas
// estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%, y
//cuántas reproducciones duraron menos del 25% del total del cuento.
//Los 10 relatores cuyas lecturas tuvieron la mayor cantidad 
//de reproducciones entre el 75% y 100%, ordenado de mayor a menor por dicha cantidad.
//Datos de entrada: 
//Cuentos. tenemos idCuento , idRelator ,Idautor , titulo, duracion
//Relatores , tenemos idRelator, y nombre
//reproduccion idUsuario , idCuento ,fecha,minutos


//logica , hay que primero que leer y extraer los archivos de cuentos, relatores, y reproducciones.
//cada relator tiene una id y las reproducciones tambien tienen una id para el usuario
//hay que hacer un descubrimiento para los usuarios , cada usuario puede escuchar mas de una vez al cuento

//leer las reproducciones --> meterlas en una coll --> hacer otra coleccion de cuentos --> comparar ids --> 
//wrappear los minutos en autores y en cuentos 


//



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
