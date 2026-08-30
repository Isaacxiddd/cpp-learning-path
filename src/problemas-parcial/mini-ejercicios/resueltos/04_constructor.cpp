/*
  EJERCICIO 4: Constructor de struct
  Concepto: funcion que crea y devuelve un struct con datos asignados
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

struct Persona {
    int id;
    string nombre;
};

// CONSTRUCTOR: funcion que crea una Persona con los datos dados
// Sirve para no tener que escribir los campos a mano cada vez
Persona persona(int id, string nombre) {
    Persona p;
    p.id = id;
    p.nombre = nombre;
    return p;
}

// ToString
string personaToString(Persona x) {
    char sep = 1;
    return to_string(x.id) + sep + x.nombre;
}

// FromString
Persona personaFromString(string s) {
    char sep = 1;
    Persona x;
    x.id = stoi(getTokenAt(s, sep, 0));
    x.nombre = getTokenAt(s, sep, 1);
    return x;
}

int main() {
    // SIN constructor: tenes que escribir los campos
    Persona p1;
    p1.id = 1;
    p1.nombre = "Juan";

    // CON constructor: mas limpio y rapido
    Persona p2 = persona(2, "Maria");

    cout << p1.nombre << " y " << p2.nombre << endl;
    return 0;
}
