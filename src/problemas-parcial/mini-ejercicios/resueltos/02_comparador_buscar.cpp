/*
  EJERCICIO 2: Comparador y collFind
  Concepto: buscar un elemento en una Coll usando una funcion comparadora
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"

using namespace std;

// Comparador: dice si un string es igual a otro
// Devuelve 0 si son iguales
int cmpStringString(string a, string b) {
    return a < b ? -1 : a > b ? 1 : 0;
    // O mas simple: return a.compare(b);
    // O usando la libreria: return cmpString(a, b);
}

int main() {
    Coll<string> col = coll<string>('#');

    collAdd<string>(col, "perro", stringToString);
    collAdd<string>(col, "gato", stringToString);
    collAdd<string>(col, "pajaro", stringToString);

    // collFind<QueTieneLaColl, QueEstoyBuscando>(coll, valor, comparador, fromString)
    // Busca "gato" en la coleccion
    int pos = collFind<string, string>(col, "gato", cmpStringString, stringToString);

    if (pos >= 0) {
        cout << "Encontrado en posicion: " << pos << endl;
    } else {
        cout << "NO encontrado" << endl;
    }

    // Buscar uno que no existe
    pos = collFind<string, string>(col, "vaca", cmpStringString, stringToString);
    cout << "Buscando 'vaca': " << pos << " (deberia ser -1)" << endl;

    return 0;
}
