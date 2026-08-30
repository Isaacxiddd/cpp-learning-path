/*
  EJERCICIO 10: Mostrar estructura jerarquica
  Concepto: triple while anidado para mostrar datos agrupados
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

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

void procesar(Coll<Curso>& cursos, int idCurso, int legajo, string materia) {
    int posCurso = collFind<Curso, int>(cursos, idCurso, cmpCursoId, cursoFromString);
    if (posCurso < 0) {
        Curso c = curso(idCurso, coll<Alumno>('%'));
        posCurso = collAdd<Curso>(cursos, c, cursoToString);
    }

    Curso c = collGetAt<Curso>(cursos, posCurso, cursoFromString);

    int posAlum = collFind<Alumno, int>(c.alumnos, legajo, cmpAlumnoLegajo, alumnoFromString);
    if (posAlum < 0) {
        Alumno a = alumno(legajo, coll<string>('#'));
        posAlum = collAdd<Alumno>(c.alumnos, a, alumnoToString);
    }

    Alumno a = collGetAt<Alumno>(c.alumnos, posAlum, alumnoFromString);
    collAdd<string>(a.materias, materia, stringToString);

    collSetAt<Alumno>(c.alumnos, a, posAlum, alumnoToString);
    collSetAt<Curso>(cursos, c, posCurso, cursoToString);
}

// ============================================================
// MOSTRAR JERARQUICO: triple while anidado
// ============================================================
void mostrar(Coll<Curso> cursos) {
    collReset<Curso>(cursos);
    while (collHasNext<Curso>(cursos)) {
        Curso c = collNext<Curso>(cursos, cursoFromString);
        cout << "Curso " << c.idCurso << endl;

        collReset<Alumno>(c.alumnos);
        while (collHasNext<Alumno>(c.alumnos)) {
            Alumno a = collNext<Alumno>(c.alumnos, alumnoFromString);
            cout << "    Legajo " << a.legajo << endl;

            collReset<string>(a.materias);
            while (collHasNext<string>(a.materias)) {
                string m = collNext<string>(a.materias, stringToString);
                cout << "        " << m << endl;
            }
        }
    }
}

int main() {
    Coll<Curso> cursos = coll<Curso>('&');

    procesar(cursos, 101, 111, "Matematica");
    procesar(cursos, 101, 111, "Fisica");
    procesar(cursos, 101, 222, "Matematica");
    procesar(cursos, 102, 333, "Historia");
    procesar(cursos, 102, 333, "Geografia");

    mostrar(cursos);

    return 0;
}
