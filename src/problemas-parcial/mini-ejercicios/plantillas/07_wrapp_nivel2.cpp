/*
  EJERCICIO 7: Wrap nivel 2
  Struct con Coll<OtroStruct> adentro (anidamiento doble)
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

// --- NIVEL 1: Alumno (igual que ejercicio 6) ---
struct Alumno { int legajo; Coll<string> materias; };
Alumno alumno(int legajo, Coll<string> materias) {
    Alumno a; a.legajo = legajo; a.materias = materias; return a;
}
string alumnoToString(Alumno x) {
    char sep = 1;
    return to_string(x.legajo) + sep + collToString<string>(x.materias);
}
Alumno alumnoFromString(string s) {
    char sep = 1; Alumno x;
    x.legajo = stoi(getTokenAt(s, sep, 0));
    x.materias = collFromString<string>(getTokenAt(s, sep, 1));
    return x;
}

// --- NIVEL 2: Curso - COMPLETAR ---
// struct Curso { int idCurso; Coll<Alumno> alumnos; };
// Curso curso(int idCurso, Coll<Alumno> alumnos) { ??? }
// string cursoToString(Curso x) { usar sep=2, collToString<Alumno>(...) }
// Curso cursoFromString(string s) { usar sep=2, collFromString<Alumno>(...) }

int main() {
    // Crear 2 alumnos con sus materias
    // ???

    // Crear Coll<Alumno> con separador '%'
    // Agregar los 2 alumnos
    // ???

    // Crear Curso con id=101
    // ???

    // Serializar todo el curso y mostrar el string
    // ???

    // Deserializar y mostrar cuantos alumnos tiene
    // ???

    return 0;
}
