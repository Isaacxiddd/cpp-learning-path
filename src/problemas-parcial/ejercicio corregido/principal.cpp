
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


/*
    Leer el archivo FRASES.txt y generar un listado donde se clasifiquen las
    frases según el anio y el autor. El listado debe tener el siguiente formato:

    2003
       Maradona, D.
            La vidaaaa eeeeeeeeessss maravillosa con una pelota en el pie.
            La Claudia ya me tiene podrido.
            :
       Galvan, M.
            No somos nada o lo somos todo.
            El mundo es un slot y la vida es una plaqueta.
            :
    2007
       Maradona, D.
            :
       Galindez, R.
            :
     :
*/

// ============================================================
// cmpRAnioAnio: funcion comparadora para collFind<RAnio,int>
// Devuelve 0 si ra.anio == a, negativo si es menor, positivo si mayor
// ============================================================
int cmpRAnioAnio(RAnio ra,int a)
{
    return ra.anio-a;
}

// ============================================================
// cmpRAutorAutor: funcion comparadora para collFind<RAutor,string>
// Compara el nombre del autor con el string buscado
// ============================================================
int cmpRAutorAutor(RAutor ra,string a)
{
    return cmpString(ra.nombre,a);
}

// ============================================================
// procesarAnio: CORAZON DEL PROGRAMA
// Recibe anio, autor, frase y la coleccion principal
// 1) Busca/crea el RAnio en cAnios
// 2) Busca/crea el RAutor dentro de ese RAnio
// 3) Agrega la frase a ese RAutor
// 4) Guarda los cambios con collSetAt (¡siempre!)
// ============================================================
void procesarAnio(int anio,string autor,string frase,Coll<RAnio>& cAnios)
{
    // --- NIVEL 1: Buscar o crear el ANIO ---
    int posAnio = collFind<RAnio,int>(cAnios,anio,cmpRAnioAnio,rAnioFromString);
    if( posAnio<0 )
    {
        // No existe: creo un RAnio nuevo con una Coll<RAutor> vacia (sep '%')
        RAnio x = rAnio(anio,coll<RAutor>('%'));
        posAnio = collAdd<RAnio>(cAnios,x,rAnioToString); // lo agrego a la coleccion
    }

    // Obtengo el RAnio (ya sea recien creado o existente)
    RAnio x = collGetAt<RAnio>(cAnios,posAnio,rAnioFromString);

    // --- NIVEL 2: Buscar o crear el AUTOR dentro del anio ---
    int posAutor = collFind<RAutor,string>(x.autores,autor,cmpRAutorAutor,rAutorFromString);
    if( posAutor<0 )
    {
        // No existe: creo un RAutor nuevo con Coll<string> vacia (sep '#')
        RAutor z = rAutor(autor,coll<string>('#'));
        posAutor = collAdd<RAutor>(x.autores,z,rAutorToString);
    }

    // Obtengo el RAutor
    RAutor z = collGetAt<RAutor>(x.autores,posAutor,rAutorFromString);

    // --- NIVEL 3: Agrego la FRASE al autor ---
    collAdd<string>(z.frases,frase,stringToString);

    // Guardo los cambios hacia arriba (¡siempre collSetAt!)
    collSetAt<RAutor>(x.autores,z,posAutor,rAutorToString);
    collSetAt<RAnio>(cAnios,x,posAnio,rAnioToString);
}

// ============================================================
// mostrarListado: recorre la coleccion e imprime en formato jerarquico
//  2003
//     Maradona D.
//         frase 1
//         frase 2
// ============================================================
void mostrarListado(Coll<RAnio> cAnios)
{
    collReset<RAnio>(cAnios);
    while( collHasNext<RAnio>(cAnios) )
    {
        RAnio rAn = collNext<RAnio>(cAnios,rAnioFromString);
        cout << rAn.anio << endl; // imprime el anio

        Coll<RAutor> cAutores = rAn.autores;
        collReset<RAutor>(cAutores);
        while( collHasNext<RAutor>(cAutores) )
        {
            RAutor rAu = collNext<RAutor>(cAutores,rAutorFromString);
            cout << "    " << rAu.nombre << endl; // imprime el autor con indentacion

            Coll<string> cFrases = rAu.frases;
            collReset<string>(cFrases);
            while( collHasNext<string>(cFrases) )
            {
                string fr = collNext<string>(cFrases,stringToString);
                cout << "        " << fr << endl; // imprime la frase con doble indentacion
            }
        }
    }
}


// ============================================================
// main: punto de entrada
// 1) Abre FRASES.txt
// 2) Crea coleccion principal de RAnio
// 3) Lee linea por linea, parsea con getTokenAt (separador '|')
// 4) Procesa cada linea con procesarAnio
// 5) Muestra el listado final
// ============================================================
int main()
{
    cout << "INICIO" << endl;

    // Abro el archivo FRASES.txt en modo lectura+escritura binaria
    FILE* f = fopen("FRASES.txt", "r+b");
    if (f == NULL)
    {
        cout << "ERROR: No se pudo abrir FRASES.txt" << endl;
        cout << "Presione una tecla para continuar..." << endl;
        cin.get();
        return 1;
    }
    cout << "Archivo abierto OK" << endl;

    // Creo la coleccion principal de RAnio (separador '&')
    Coll<RAnio> cAnios = coll<RAnio>('&');
    cout << "Coleccion creada OK" << endl;

    // Leo el archivo linea por linea
    string ln;
    bool hayMas = readLine(f, ln);
    cout << "Primera linea leida: " << hayMas << endl;
    int cont = 0;
    while(hayMas)
    {
        cont++;
        if (cont % 10 == 0) cout << "Leidas " << cont << " lineas..." << endl;

        // Parseo la linea: formato "frase|autor|anio"
        string frase = getTokenAt(ln,'|',0); // token 0 = frase
        string autor = getTokenAt(ln,'|',1); // token 1 = autor
        int anio = stringToInt(getTokenAt(ln,'|',2)); // token 2 = anio

        // Proceso el triplete (anio, autor, frase)
        procesarAnio(anio,autor,frase,cAnios);

        // Siguiente linea
        hayMas = readLine(f, ln);
    }
    cout << "Procesadas " << cont << " lineas" << endl;

    cout << "Mostrando listado..." << endl;
    mostrarListado(cAnios);

    fclose(f); // cierro el archivo

    cout << "Presione una tecla para continuar..." << endl;
    cin.get(); // pausa para ver resultado

    return 0;
}
