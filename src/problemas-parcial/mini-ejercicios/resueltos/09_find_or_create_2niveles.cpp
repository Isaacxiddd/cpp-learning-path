/*
  EJERCICIO 9: Patron find-or-create en 2 niveles
  Concepto: igual que procesarAnio (el corazon del parcial)
  Primero busco/creo el padre, despues busco/creo el hijo
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

// --- NIVEL 1: Alumno (wrap de Coll<string>) ---
struct Alumno {
    int legajo;
    Coll<string> materias;
};

Alumno alumno(int legajo, Coll<string> materias) {
    Alumno a;
    a.legajo = legajo;
    a.materias = materias;
    return a;
}

string alumnoToString(Alumno x) {
    char sep = 1;
    return to_string(x.legajo) + sep + collToString<string>(x.materias);
}

Alumno alumnoFromString(string s) {
    char sep = 1;
    Alumno x;
    x.legajo = stoi(getTokenAt(s, sep, 0));
    x.materias = collFromString<string>(getTokenAt(s, sep, 1));
    return x;
}

int cmpAlumnoLegajo(Alumno a, int leg) {
    return a.legajo - leg;
}

// --- NIVEL 2: Curso (wrap de Coll<Alumno>) ---
struct Curso {
    int idCurso;
    Coll<Alumno> alumnos;
};

Curso curso(int idCurso, Coll<Alumno> alumnos) {
    Curso c;
    c.idCurso = idCurso;
    c.alumnos = alumnos;
    return c;
}

string cursoToString(Curso x) {
    char sep = 2;
    return to_string(x.idCurso) + sep + collToString<Alumno>(x.alumnos);
}

Curso cursoFromString(string s) {
    char sep = 2;
    Curso x;
    x.idCurso = stoi(getTokenAt(s, sep, 0));
    x.alumnos = collFromString<Alumno>(getTokenAt(s, sep, 1));
    return x;
}

int cmpCursoId(Curso c, int id) {
    return c.idCurso - id;
}

// ============================================================
// Funcion que procesa: idCurso, legajoAlumno, materia
// PATRON FIND-OR-CREATE EN 2 NIVELES (identico a procesarAnio)
// ============================================================
void procesar(Coll<Curso>& cursos, int idCurso, int legajo, string materia) {
    // ---- NIVEL 1: buscar/crear CURSO ----
    int posCurso = collFind<Curso, int>(cursos, idCurso, cmpCursoId, cursoFromString);
    if (posCurso < 0) {
        Curso c = curso(idCurso, coll<Alumno>('%'));
        posCurso = collAdd<Curso>(cursos, c, cursoToString);
    }

    // Obtener el curso (copia!)
    Curso c = collGetAt<Curso>(cursos, posCurso, cursoFromString);

    // ---- NIVEL 2: buscar/crear ALUMNO dentro del curso ----
    int posAlum = collFind<Alumno, int>(c.alumnos, legajo, cmpAlumnoLegajo, alumnoFromString);
    if (posAlum < 0) {
        Alumno a = alumno(legajo, coll<string>('#'));
        posAlum = collAdd<Alumno>(c.alumnos, a, alumnoToString);
    }

    // Obtener el alumno (copia!)
    Alumno a = collGetAt<Alumno>(c.alumnos, posAlum, alumnoFromString);

    // ---- NIVEL 3: agregar la MATERIA al alumno ----
    // (aca no hay find, porque las materias se repiten)
    collAdd<string>(a.materias, materia, stringToString);

    // ---- GUARDAR CAMBIOS (de adentro hacia afuera) ----
    collSetAt<Alumno>(c.alumnos, a, posAlum, alumnoToString);
    collSetAt<Curso>(cursos, c, posCurso, cursoToString);
}

int main() {
    Coll<Curso> cursos = coll<Curso>('&');

    // Procesar datos como si vinieran de un archivo
    procesar(cursos, 101, 111, "Matematica");
    procesar(cursos, 101, 111, "Fisica");       // mismo alumno, nueva materia
    procesar(cursos, 101, 222, "Matematica");   // mismo curso, nuevo alumno
    procesar(cursos, 102, 333, "Historia");     // nuevo curso

    return 0;
}
