/*
  EJERCICIO 1: Hola Coll<string>
  Concepto: crear una Coll, agregar elementos, iterarlos
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"

using namespace std;

int main() {
    // Crear una coleccion de strings con separador '#'
    Coll<string> frases = coll<string>('#');

    // Agregar elementos (devuelve la posicion)
    collAdd<string>(frases, "Hola", stringToString);
    collAdd<string>(frases, "Mundo", stringToString);
    collAdd<string>(frases, "Chau", stringToString);

    // Iterar: reset -> hasNext -> next
    collReset<string>(frases);
    while (collHasNext<string>(frases)) {
        string s = collNext<string>(frases, stringToString);
        cout << s << endl;
    }

    // Mostrar cantidad
    cout << "Total: " << collSize<string>(frases) << endl;

    return 0;
}
