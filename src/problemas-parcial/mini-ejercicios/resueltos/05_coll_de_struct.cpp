/*
  EJERCICIO 5: Coll de struct completo
  Concepto: Coll<Persona> con add, find, getAt, setAt
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

// Constructor
Persona persona(int id, string nombre) {
    Persona p;
    p.id = id;
    p.nombre = nombre;
    return p;
}

string personaToString(Persona x) {
    char sep = 1;
    return to_string(x.id) + sep + x.nombre;
}

Persona personaFromString(string s) {
    char sep = 1;
    Persona x;
    x.id = stoi(getTokenAt(s, sep, 0));
    x.nombre = getTokenAt(s, sep, 1);
    return x;
}

int cmpPersonaId(Persona p, int id) {
    return p.id - id;
}

int main() {
    Coll<Persona> col = coll<Persona>('&');

    // ADD: agrega y devuelve posicion
    int pos1 = collAdd<Persona>(col, persona(1, "Juan"), personaToString);
    int pos2 = collAdd<Persona>(col, persona(2, "Maria"), personaToString);

    // GETAT: obtiene una COPIA del elemento
    Persona p = collGetAt<Persona>(col, 0, personaFromString);
    cout << "Pos 0: " << p.nombre << endl;

    // MODIFICAR: get -> cambiar -> set
    p.nombre = "Juan Carlos";
    collSetAt<Persona>(col, p, 0, personaToString);  // <-- GUARDA LA COPIA MODIFICADA

    // Verificar el cambio
    p = collGetAt<Persona>(col, 0, personaFromString);
    cout << "Despues del set: " << p.nombre << endl;

    // BUSCAR
    int pos = collFind<Persona, int>(col, 2, cmpPersonaId, personaFromString);
    if (pos >= 0) {
        p = collGetAt<Persona>(col, pos, personaFromString);
        cout << "Encontre id=2: " << p.nombre << endl;
    }

    return 0;
}
