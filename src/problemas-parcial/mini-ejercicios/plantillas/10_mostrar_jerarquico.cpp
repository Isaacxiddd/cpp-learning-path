/*
  EJERCICIO 10: Mostrar estructura jerarquica
  Triple while anidado para mostrar datos agrupados
  COMBINA el ejercicio 9 + la funcion mostrar
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

struct Alumno { int legajo; Coll<string> materias; };
Alumno alumno(int legajo, Coll<string> materias) { Alumno a; a.legajo=legajo; a.materias=materias; return a; }
string alumnoToString(Alumno x) { char sep=1; return to_string(x.legajo)+sep+collToString<string>(x.materias); }
Alumno alumnoFromString(string s) { char sep=1; Alumno x; x.legajo=stoi(getTokenAt(s,sep,0)); x.materias=collFromString<string>(getTokenAt(s,sep,1)); return x; }
int cmpAlumnoLegajo(Alumno a, int leg) { return a.legajo-leg; }

struct Curso { int idCurso; Coll<Alumno> alumnos; };
Curso curso(int idCurso, Coll<Alumno> alumnos) { Curso c; c.idCurso=idCurso; c.alumnos=alumnos; return c; }
string cursoToString(Curso x) { char sep=2; return to_string(x.idCurso)+sep+collToString<Alumno>(x.alumnos); }
Curso cursoFromString(string s) { char sep=2; Curso x; x.idCurso=stoi(getTokenAt(s,sep,0)); x.alumnos=collFromString<Alumno>(getTokenAt(s,sep,1)); return x; }
int cmpCursoId(Curso c, int id) { return c.idCurso-id; }

// Copiar procesar del ejercicio 9
void procesar(Coll<Curso>& cursos, int idCurso, int legajo, string materia) {
    // ??? (completar con find-or-create en 2 niveles)
}

// ============================================================
// COMPLETAR: void mostrar(Coll<Curso> cursos)
// Triple while anidado:
//   while cursos: mostrar idCurso
//     while alumnos: mostrar legajo
//       while materias: mostrar materia
// Usar collReset - collHasNext - collNext en cada nivel
// void mostrar(???) { ??? }
// ============================================================

int main() {
    Coll<Curso> cursos = coll<Curso>('&');

    procesar(cursos, 101, 111, "Matematica");
    procesar(cursos, 101, 111, "Fisica");
    procesar(cursos, 101, 222, "Matematica");
    procesar(cursos, 102, 333, "Historia");
    procesar(cursos, 102, 333, "Geografia");

    // Llamar a mostrar
    // ???

    return 0;
}
