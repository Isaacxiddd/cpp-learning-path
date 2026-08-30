/*
  EJERCICIO 7: Wrap nivel 2
  Concepto: struct con Coll<OtroStruct> adentro (como RAnio)
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

// --- NIVEL 2: Curso (wrap de Coll<Alumno>) ---
struct Curso {
    int idCurso;
    Coll<Alumno> alumnos;  // <-- Wrap de segundo nivel: Coll<OtroStruct>
};

Curso curso(int idCurso, Coll<Alumno> alumnos) {
    Curso c;
    c.idCurso = idCurso;
    c.alumnos = alumnos;
    return c;
}

string cursoToString(Curso x) {
    char sep = 2;  // separador DIFERENTE al de Alumno (sep=1)
    return to_string(x.idCurso) + sep + collToString<Alumno>(x.alumnos);
    // collToString<Alumno> llama a alumnoToString para cada Alumno
}

Curso cursoFromString(string s) {
    char sep = 2;
    Curso x;
    x.idCurso = stoi(getTokenAt(s, sep, 0));
    x.alumnos = collFromString<Alumno>(getTokenAt(s, sep, 1));
    return x;
}

int main() {
    // Crear alumnos
    Coll<string> mats1 = coll<string>('#');
    collAdd<string>(mats1, "Matematica", stringToString);
    Alumno a1 = alumno(111, mats1);

    Coll<string> mats2 = coll<string>('#');
    collAdd<string>(mats2, "Lengua", stringToString);
    collAdd<string>(mats2, "Historia", stringToString);
    Alumno a2 = alumno(222, mats2);

    // Crear curso y agregar alumnos
    Coll<Alumno> colAlumnos = coll<Alumno>('%');
    collAdd<Alumno>(colAlumnos, a1, alumnoToString);
    collAdd<Alumno>(colAlumnos, a2, alumnoToString);

    Curso c = curso(101, colAlumnos);

    // Serializar TODO
    string s = cursoToString(c);
    cout << "Serializado completo:" << endl << s << endl << endl;

    // Recuperar
    Curso c2 = cursoFromString(s);
    cout << "Curso id=" << c2.idCurso << " tiene " << collSize<Alumno>(c2.alumnos) << " alumnos" << endl;

    return 0;
}
