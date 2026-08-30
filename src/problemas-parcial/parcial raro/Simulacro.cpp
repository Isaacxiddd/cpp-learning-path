#include "principal.hpp"

#include <cassert>
#include <iostream>

#include "../../../lib/funciones/files.hpp"
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "../../../lib/funciones/Coll.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

// Comparadora de años: resta los campos anio
int cmpAnioAnio(Anio a, int b)
{
    return a.anio - b;
}

// Comparadora de autores: compara el campo `nom` del struct Autor con el string b
// Usamos strcmp de <cstring> para comparación de C-strings
#include <cstring>
int cmpAutorAutor(Autor a, string b)
{
    // a.nom es el field del struct Autor, b es el string a comparar
    // Retornamos negativo, 0 o positivo según sea menor, igual o mayor
    int r = strcmp(a.nom.c_str(), b.c_str());
    return r;
}

// Función para crear un Anio vacío con su colección de autores
Anio crearAnioVacio(int anio)
{
    Anio x;
    x.anio = anio;
    // struct Anio tiene field `a` que es Coll<Autor>
    x.a = coll<Autor>();
    return x;
}

// Función para crear un Autor vacío
Autor crearAutorVacio(string nom)
{
    Autor x;
    x.nom = nom;
    x.frases = coll<string>();
    return x;
}

void fraseProcesar(string frase, string aut, int a, Coll<Anio>& cAni)
{
    /* 1. descubro el anio; 2. dentro del anio descubro el autor; 3. agrego frase;
       4. seteo la coll interna y luego la externa. */

    // 1. Busco si ya existe el año en la colección
    int posAnio = collFind<Anio,int>(cAni, a, cmpAnioAnio, anioFromString);
    if (posAnio < 0)
    {
        // No existe → lo creo vacío con el año y lo agrego
        Anio x = crearAnioVacio(a);
        posAnio = collAdd<Anio>(cAni, x, anioToString);
    }

    // Obtengo el año ya existente (o recién creado)
    Anio elm = collGetAt<Anio>(cAni, posAnio, anioFromString);

    // 2. Dentro del año, busco si ya existe el autor
    int posAut = collFind<Autor>(elm.a, aut, cmpAutorAutor, autorFromString);
    if (posAut < 0)
    {
        // Autor nuevo → lo creo vacío y lo agrego a la colección del año
        Autor x = crearAutorVacio(aut);
        posAut = collAdd<Autor>(elm.a, x, autorToString);
    }

    // Obtengo el autor ya existente (o recién creado)
    Autor elmAut = collGetAt<Autor>(elm.a, posAut, autorFromString);

    // 3. Agrego la frase a la colección de frases del autor
    collAdd<string>(elmAut.frases, frase, stringToString);

    // 4. Actualizo el autor en la colección del año (aunque collAdd ya lo hizo)
    collSetAt<Autor>(elm.a, elmAut, posAut, autorToString);

    // 5. Actualizo el año en la colección general
    collSetAt<Anio>(cAni, elm, posAnio, anioToString);
}

int mostrarAniosDisp(Coll<Anio> a)
{
    /* recorrer la coll de anios, y mostrar los anios disponibles*/
    int ret;

    cout << "SELECCIONE ANIO" << endl;

    int p = 0;
    while (p < collSize(a))
    {
        Anio an = collGetAt<Anio>(a, p, anioFromString);

        cout << '[' << an.anio << ']' << endl;

        p++;
    }

    cout << "Ingrese anio: " << endl;
    cin >> ret;

    return ret;
}

void frasesMostrar(Coll<Anio> cAni)
{
    int a = mostrarAniosDisp(cAni);

    int posAnio = collFind<Anio,int>(cAni, a, cmpAnioAnio, anioFromString);
    Anio an = collGetAt<Anio>(cAni, posAnio, anioFromString);

    cout << "[" << an.anio << "]" << endl;

    int p = 0;
    while (p < collSize(an.a))
    {
        Autor aut = collGetAt<Autor>(an.a, p, autorFromString);

        int i = 0;
        while (i < collSize(aut.frases))
        {
            string s = collGetAt<string>(aut.frases, i, stringToString);

            // struct Autor usa `nom`, mostramos lo que hay
            cout << "-" << s << '(' << aut.nom << ')' << endl;

            i++;
        }
        p++;
    }
}

int main()
{
    Coll<Anio> cAni = coll<Anio>();

    // Abrimos el archivo FRASES.txt en modo texto (rt)
    // El archivo debe estar en el directorio actual donde se ejecuta el programa
    FILE* f = fopen("FRASES.txt", "rt");
    if (!f)
    {
        cout << "Error: no se puede abrir FRASES.txt" << endl;
        // Intentar con ruta relativa del proyecto
        FILE* f2 = fopen("FRASES.txt", "rt");
        if (!f2)
        {
            cout << "Error crítico: FRASES.txt no encontrado" << endl;
            cin.get();
            return 1;
        }
        f = f2;
    }

    string ln;
    bool hasNext = readLine(f, ln);
    while (hasNext)
    {
        // El archivo FRASES.txt usa pipe | como delimitador:
        // campo 0 = frase, campo 1 = autor, campo 2 = año
        string frase = getTokenAt(ln, '|', 0);
        string autor = getTokenAt(ln, '|', 1);
        int anio = stringToInt(getTokenAt(ln, '|', 2));

        fraseProcesar(frase, autor, anio, cAni);

        hasNext = readLine(f, ln);
    }

    fclose(f);

    // Mostrar resultados finales
    frasesMostrar(cAni);

    // Pausa
    cin.get();
    return 0;
}