#include <iostream>
#include <cassert>
#include "lib/funciones/files.hpp"
#include "lib/funciones/strings.hpp"
#include "lib/funciones/tokens.hpp"
#include "lib/funciones/Coll.hpp"
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

// Función comparadora de años (usa el campo anio del struct Anio)
int cmpAnioAnio(Anio a, int b)
{
    return a.anio - b;
}

// Función comparadora de autores por nom (el struct Autor usa `nom`, no `nombre`)
int cmpAutorAutor(Autor a, string b)
{
    // El struct Autor tiene `nom`, comparamos con el string b
    if (a.nom < b) return -1;
    if (a.nom > b) return 1;
    return 0;
}

// Función para crear un nodo Anio vacío y cargarle el año
Anio crearAnio(int anio)
{
    Anio x;
    x.anio = anio;
    // struct Anio tiene `a` como field de tipo Coll<Autor>, no `autores`
    x.a = coll<Autor>();  
    return x;
}

// Función principal de procesamiento: descubre o crea el año y el autor, y agrega la frase
void fraseProcesar(string frase, string aut, int a, Coll<Anio>& cAni)
{
    // 1. Descubro si ya existe el año en la colección
    int posAnio = collFind<Anio,int>(cAni, a, cmpAnioAnio, anioFromString);
    
    if (posAnio < 0)
    {
        // No existe → lo creo vacío y lo agrego
        Anio x = crearAnio(a);
        posAnio = collAdd<Anio>(cAni, x, anioToString);
    }

    // Ahora ya sé que el año existe, lo obtengo
    Anio elm = collGetAt<Anio>(cAni, posAnio, anioFromString);

    // 2. Dentro del año, descubro si ya existe el autor
    // Usamos cmpAutorAutor que compara `a.nom` de Autor con el string `aut`
    int posAut = collFind<Autor>(elm.a, aut, cmpAutorAutor, autorFromString);
    
    if (posAut < 0)
    {
        // Autor nuevo: lo creamos con su colección de frases vacía y lo agregamos
        Autor x;
        x.nom = aut;          // El field es `nom`, no `nombre`
        x.frases = coll<string>(); // colección vacía de strings
        posAut = collAdd<Autor>(elm.a, x, autorToString);
    }

    // Obtenemos el autor ya existente (o recién creado)
    Autor elmAut = collGetAt<Autor>(elm.a, posAut, autorFromString);

    // 3. Agregamos la frase a la colección de frases del autor
    // collAdd<string> necesita el string y la función ToString
    collAdd<string>(elmAut.frases, frase, stringToString);

    // 4. Actualizamos el autor en la colección (aunque collAdd ya lo hizo, es good practice)
    collSetAt<Autor>(elm.a, elmAut, posAut, autorToString);

    // 5. Actualizamos el año en la colección general
    collSetAt<Anio>(cAni, elm, posAnio, anioToString);
}

// Función para mostrar los años disponibles y pedir al usuario que elija uno
int mostrarAniosDisp(Coll<Anio> a)
{
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

// Función para mostrar todas las frases del año y autor seleccionados
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

            // struct Autor usa `nom`, no `nombre`
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
    if (!f) {
        cout << "Error: no se puede abrir FRASES.txt" << endl;
        return 1;
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
    
    // Mostrar resultados
    frasesMostrar(cAni);

    // Pausa al final
    cin.ignore();
    cin.get();

    return 0;
}