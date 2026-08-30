/*
  EJERCICIO 1: Hola Coll<string>
  Crear una Coll, agregar frases, iterarlas con el while
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"

using namespace std;

int main() {
    // Crear una Coll<string> con separador '#'
   int b = 0;
   Coll<string> a = coll<string>('#');
   collAdd<string>(a, "hola mundo", stringToString);
   collAdd<string>(a, "mundo", stringToString);
   collAdd<string>(a, "chau", stringToString);
   b = collSize<string>(a);

    
    // Coll<string> frases = ???

    // Agregar "Hola", "Mundo", "Chau" con collAdd
    // ???

    // Iterar con collReset -> while collHasNext -> collNext
    // ???
        collReset<string>(a);
    while(collHasNext<string>(a))
    {
   string  q = collNext<string>(a,stringToString);
    cout << q <<endl;
    };
     

    // Mostrar la cantidad de elementos con collSize
    // ???
    cout << b << endl;
    cout << "Presione una tecla para salir..." << endl;
    cin.get();
    return 0;
}
