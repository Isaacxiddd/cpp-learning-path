/*
  EJERCICIO 8: Find-or-create en 1 nivel
  Buscar en una Coll, si no existe lo creo y agrego
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

struct Persona { int id; string nombre; };
Persona persona(int id, string nombre) { Persona p; p.id = id; p.nombre = nombre; return p; }
string personaToString(Persona x) { char sep=1; return to_string(x.id)+sep+x.nombre; }
Persona personaFromString(string s) { char sep=1; Persona x; x.id=stoi(getTokenAt(s,sep,0)); x.nombre=getTokenAt(s,sep,1); return x; }
int cmpPersonaId(Persona p, int id) { return p.id - id; }

// Completar funcion agregarPersona(Coll<Persona>& col, int id, string nombre)
// 1. collFind<Persona, int>(col, id, cmpPersonaId, personaFromString)
// 2. Si da -1: crear persona con constructor, collAdd
//    Si da >=0: ya existe, no hacer nada
// void agregarPersona(???) { ??? }

int main() {
    Coll<Persona> col = coll<Persona>('&');

    // Llamar agregarPersona 3 veces (id=1 "Juan", id=2 "Maria", id=1 "Juan" de nuevo)
    // ???

    // Mostrar collSize (deberia ser 2, no 3)
    // ???

    return 0;
}
