/*
  EJERCICIO 9: Find-or-create en 2 niveles
  Identico a procesarAnio del parcial
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

// --- NIVEL 1: Alumno (legajo + Coll<string> materias) ---
struct Alumno { int legajo; Coll<string> materias; };
Alumno alumno(int legajo, Coll<string> materias) {
    Alumno a; a.legajo = legajo; a.materias = materias; return a;
}
string alumnoToString(Alumno x) {
    char sep = 1; return to_string(x.legajo) + sep + collToString<string>(x.materias);
}
Alumno alumnoFromString(string s) {
    char sep = 1; Alumno x;
    x.legajo = stoi(getTokenAt(s, sep, 0));
    x.materias = collFromString<string>(getTokenAt(s, sep, 1));
    return x;
}
int cmpAlumnoLegajo(Alumno a, int leg) { return a.legajo - leg; }

// --- NIVEL 2: Curso (idCurso + Coll<Alumno> alumnos) ---
struct Curso { int idCurso; Coll<Alumno> alumnos; };
Curso curso(int idCurso, Coll<Alumno> alumnos) {
    Curso c; c.idCurso = idCurso; c.alumnos = alumnos; return c;
}
string cursoToString(Curso x) {
    char sep = 2; return to_string(x.idCurso) + sep + collToString<Alumno>(x.alumnos);
}
Curso cursoFromString(string s) {
    char sep = 2; Curso x;
    x.idCurso = stoi(getTokenAt(s, sep, 0));
    x.alumnos = collFromString<Alumno>(getTokenAt(s, sep, 1));
    return x;
}
int cmpCursoId(Curso c, int id) { return c.idCurso - id; }

// ============================================================
// COMPLETAR: procesar(Coll<Curso>& cursos, int idCurso, int legajo, string materia)
// ============================================================
// NIVEL 1: find-or-create CURSO
//   collFind<Curso, int>(cursos, idCurso, cmpCursoId, cursoFromString)
//   si no existe: crear Curso con coll<Alumno>('%'), collAdd
//   collGetAt para obtener el curso
//
// NIVEL 2: find-or-create ALUMNO dentro del curso
//   collFind<Alumno, int>(c.alumnos, legajo, cmpAlumnoLegajo, alumnoFromString)
//   si no existe: crear Alumno con coll<string>('#'), collAdd
//   collGetAt para obtener el alumno
//
// NIVEL 3: agregar materia al alumno (sin find, se pueden repetir)
//   collAdd<string>(a.materias, materia, stringToString)
//
// GUARDAR: collSetAt del alumno, luego collSetAt del curso
// void procesar(???) { ??? }

int main() {
    Coll<Curso> cursos = coll<Curso>('&');

    // Procesar:
    // - curso 101, legajo 111, "Matematica"
    // - curso 101, legajo 111, "Fisica"     (mismo alumno, nueva materia)
    // - curso 101, legajo 222, "Matematica" (mismo curso, nuevo alumno)
    // - curso 102, legajo 333, "Historia"   (nuevo curso)
    // ???

    return 0;
}
