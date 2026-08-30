/*
  EJERCICIO 8: Patron find-or-create en 1 nivel
  Concepto: buscar en una Coll, si no existe lo creo y lo agrego
  Este es el patron MAS IMPORTANTE de todo el parcial
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

// Funcion que recibe un id y un nombre, y lo agrega a la coleccion
// Si ya existe, no lo duplica (encarna el patron find-or-create)
void agregarPersona(Coll<Persona>& col, int id, string nombre) {
    // PASO 1: BUSCAR
    int pos = collFind<Persona, int>(col, id, cmpPersonaId, personaFromString);

    if (pos < 0) {
        // PASO 2: NO existe -> CREAR y AGREGAR
        Persona p = persona(id, nombre);
        collAdd<Persona>(col, p, personaToString);
        cout << "Agregada persona id=" << id << endl;
    } else {
        // PASO 3: SI existe -> no hago nada (o aviso)
        cout << "La persona id=" << id << " ya existe" << endl;
    }
}

int main() {
    Coll<Persona> col = coll<Persona>('&');

    agregarPersona(col, 1, "Juan");   // se agrega
    agregarPersona(col, 2, "Maria");  // se agrega
    agregarPersona(col, 1, "Juan");   // ya existe, no se duplica

    cout << "Total personas: " << collSize<Persona>(col) << " (deberia ser 2)" << endl;

    return 0;
}
