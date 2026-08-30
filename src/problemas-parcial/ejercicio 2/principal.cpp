#include <iostream>
#include "../../../lib/funciones/millis.hpp"
#include "../../../lib/funciones/files.hpp"
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "../../../lib/tads/parte1/Fecha.hpp"
#include "../../../lib/tads/parte1/Timer.hpp"
#include "../../../lib/funciones/Coll.hpp"
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


/*
    Leer el archivo FRASES.txt y generar un listado donde se clasifiquen las frases según el anio y
    el autor. El listado debe tener el siguiente formato:

    2003
       Maradona, D.
            La vida es maravillosa con una pelota en el pie.
            La Claudia ya me tiene podrido.
            :
       Galvan, M.
            No somos nada a lo somos todo.
            El mundo es un slot y la vida es una plaqueta.
            :
    2007
       Maradona, D.
            :
       Galindez, R.

      Recorrer el archivo de arriba a abajo usando readLine y mostrar por consola cada línea leída.
      Tokenizar cada línea leída, extraer frase, autor y año y mostrarlo por separado en pantalla.
      Descubro en la colección de años, el año.
      Descubro en la colección de autores del año, el autor.
      Agrego la frase a la colección de frases del autor.
      Retorno la estructura de datos.
      usar readline no un while , el readline es como un collhasnext
     :
*/

int main()
{
    Coll<Anio> cAnios = coll<Anio>();
    FILE* f = fopen("FRASES.txt", "rb");

    string ln;
    bool hayMas = readLine(f, ln);
    while (hayMas)
    {
        string fra = getTokenAt(ln, '|', 0);
        string autor = getTokenAt(ln, '|', 1);
        string anio = getTokenAt(ln, '|', 2);

        cout << "{" << ln << "}" << endl;
        collAdd(cAnios, anio, anioToString());

        hayMas = readLine(f, ln);
    }

    fclose(f);
    return 0;
}

