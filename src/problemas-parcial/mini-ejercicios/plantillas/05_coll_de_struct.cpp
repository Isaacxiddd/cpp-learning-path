/*
  EJERCICIO 5: Coll de struct completo
  Coll<Persona> con add, find, getAt, setAt
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

int main() {
    Coll<Persona> col = coll<Persona>('&');

    // ADD: agregar persona(1, "Juan") y persona(2, "Maria")
    // int pos1 = collAdd<Persona>(col, ???, personaToString);

    Persona p1 = persona(1, "juan");
    Persona p2 = persona(2, "daniel");
    collAdd<Persona>(col,p1,personaToString);
    collAdd<Persona>(col,p2,personaToString);
    

    Persona p3 = collGetAt<Persona>(col, 0, personaFromString);
    cout<< p3.nombre <<endl;

    p3.nombre = "juan carlos";
    collSetAt<Persona>(col, p3, 0, personaToString);


    int pos = collFind<Persona, int>(col, 2, cmpPersonaId, personaFromString);
    if (pos >= 0)
     {
        p3 = collGetAt<Persona>(col, pos, personaFromString);
        cout << "Encontre id=2: " << p3.nombre << endl;
     }
    // GETAT: obtener la de posicion 0 y mostrar su nombre
    // Persona p = collGetAt<Persona>(col, 0, personaFromString);

    // MODIFICAR: cambiar su nombre a "Juan Carlos"
    // collSetAt<Persona>(col, p, 0, personaToString);

    // Verificar el cambio volviendo a leer
    // ???

    // BUSCAR id=2 con collFind
    // ???

    return 0;
}
