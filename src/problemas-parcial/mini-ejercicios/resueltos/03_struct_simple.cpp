/*
  EJERCICIO 3: Struct simple con serializacion
  Concepto: crear un struct, funciones ToString/FromString para Coll
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

// Serializar: convertir struct a string para guardar en la Coll
string personaToString(Persona x) {
    char sep = 1;                       // separador entre campos
    return to_string(x.id) + sep + x.nombre;
    // Resultado: "23<char1>Juan"
}

// Deserializar: reconstruir struct desde string
Persona personaFromString(string s) {
    char sep = 1;
    Persona x;
    x.id = stoi(getTokenAt(s, sep, 0));     // token 0 = id
    x.nombre = getTokenAt(s, sep, 1);       // token 1 = nombre
    return x;
}

// Comparador: buscar Persona por id (int)
int cmpPersonaId(Persona p, int id) {
    return p.id - id;
}

int main() {
    Coll<Persona> col = coll<Persona>('&');

    Persona p1 = {1, "Juan"};
    Persona p2 = {2, "Maria"};
    Persona p3 = {3, "Pedro"};

    collAdd<Persona>(col, p1, personaToString);
    collAdd<Persona>(col, p2, personaToString);
    collAdd<Persona>(col, p3, personaToString);

    // Buscar persona con id = 2
    int pos = collFind<Persona, int>(col, 2, cmpPersonaId, personaFromString);
    if (pos >= 0) {
        Persona encontrada = collGetAt<Persona>(col, pos, personaFromString);
        cout << "Encontre a: " << encontrada.nombre << " (id=" << encontrada.id << ")" << endl;
    }

    return 0;
}
