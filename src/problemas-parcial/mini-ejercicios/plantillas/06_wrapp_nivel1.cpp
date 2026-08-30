/*
  EJERCICIO 6: Wrap nivel 1
  Struct con una Coll<string> adentro
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

// Definir struct Alumno con: int legajo, Coll<string> materias
// struct Alumno { ??? }
Materias materias(string nombre) {m.nombre = nombre; return m; }
struct Alumno {
int legajo;
string name;

 
}

// Constructor: Alumno alumno(int legajo, Coll<string> materias)
// ???

// ToString: legajo + sep + collToString<string>(materias)
// El sep debe ser DIFERENTE al de la Coll interna
// ???

// FromString: getTokenAt -> legajo, getTokenAt -> collFromString<string>
// ???

int main() {
    // Crear Coll<string> de materias con separador '#'
    // Agregar "Matematica" y "Fisica"
    // ???

    // Crear Alumno con constructor
    // Alumno a = alumno(1234, materias);

    // Serializar a string y mostrarlo
    // ???

    // Deserializar de vuelta y mostrar el legajo
    // ???

    return 0;
}
