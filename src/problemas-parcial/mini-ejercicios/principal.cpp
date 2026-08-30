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

/* struct item
    int anio;
    string autor;
    coll<string> frases;

    el archivo tiene lineas tokenizadas. separo los tokens y cargo la estructura.
    tengo que descubrir: 1. anio. 2. autor. 3. y colgar la frase. */

int cmpAnioAnio(Anio a, int b)
{
    return a.anio - b;
}

int cmpAutorAutor(Autor a, string b)
{
    return cmpString(a.nom, b);
}

void fraseProcesar(string frase, string aut, int a, Coll<Anio>& cAni)
{
    /* 1. descubro el anio; 2. dentro del anio descubro el autor; 3. agrego frase; 4. seteo la coll
    interna y luego la externa. */

    int posAnio = collFind<Anio,int>(cAni, a, cmpAnioAnio, anioFromString);
    if (posAnio < 0)
    {
        Anio x = anio(a, coll<Autor>('%'));
        posAnio = collAdd<Anio>(cAni, x, anioToString);
    }

    Anio elm = collGetAt<Anio>(cAni, posAnio, anioFromString);

    // descubro autor.
    int posAut = collFind<Autor>(elm.a, aut, cmpAutorAutor, autorFromString);
    if (posAut < 0)
    {
        Autor x = autor(aut, coll<string>('&'));
        posAut = collAdd<Autor>(elm.a, x, autorToString);
    }
    // guardo la frase.
    Autor elmAut = collGetAt<Autor>(elm.a, posAut, autorFromString);

    collAdd<string>(elmAut.frases, frase, stringToString);
    collSetAt<Autor>(elm.a, elmAut, posAut, autorToString);

    // guardo el anio
    collSetAt<Anio>(cAni, elm, posAnio, anioToString);
}

int mostrarAniosDisp(Coll<Anio> a)
{
    /* recorrer la coll de anios y mostrar los anios disponibles */

    cout << "SELECCIONE ANIO" << endl;

    int p = 0;
    while (p < collSize(a))
    {
        Anio an = collGetAt<Anio>(a, p, anioFromString);

        cout << '[' << an.anio << ']' << endl;

        p++;
    }

    cout << "Ingrese anio: " << endl;
    int ret;
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

            cout << "-" << s << '(' << aut.nom << ')' << endl;

            i++;
        }
        p++;
    }
}

int main()
{
    Coll<Anio> cAni = coll<Anio>();

    FILE* f = fopen("FRASES.txt", "rt");

    string ln;
    bool hasNext = readLine(f, ln);
    while (hasNext)
    {
        string frase = getTokenAt(ln, '|', 0);
        string autor = getTokenAt(ln, '|', 1);
        int anio = stringToInt(getTokenAt(ln, '|', 2));

        fraseProcesar(frase, autor, anio, cAni);

        hasNext = readLine(f, ln);
    }

    frasesMostrar(cAni);

    fclose(f);
    return 0;
}
