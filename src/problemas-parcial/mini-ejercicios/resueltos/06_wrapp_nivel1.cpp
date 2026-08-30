/*
  EJERCICIO 6: Wrap nivel 1
  Concepto: struct con una Coll<string> adentro (como RAutor)
  "Wrappear" = poner una Coll dentro de un struct
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

struct Alumno {
    int legajo;
    Coll<string> materias;  // <-- Wrap: una Coll dentro del struct
};

// Constructor
Alumno alumno(int legajo, Coll<string> materias) {
    Alumno a;
    a.legajo = legajo;
    a.materias = materias;
    return a;
}

string alumnoToString(Alumno x) {
    char sep = 1;
    string sLegajo = to_string(x.legajo);
    string sMaterias = collToString<string>(x.materias);  // serializa la Coll interna
    return sLegajo + sep + sMaterias;
    // Resultado: "1234<sep>mat1#mat2#mat3"
}

Alumno alumnoFromString(string s) {
    char sep = 1;
    Alumno x;
    x.legajo = stoi(getTokenAt(s, sep, 0));
    string t1 = getTokenAt(s, sep, 1);
    x.materias = collFromString<string>(t1);  // deserializa la Coll interna
    return x;
}

int main() {
    // Crear un Alumno con su Coll de materias
    Coll<string> mats = coll<string>('#');
    collAdd<string>(mats, "Matematica", stringToString);
    collAdd<string>(mats, "Fisica", stringToString);

    Alumno a = alumno(1234, mats);

    // Serializar y deserializar para ver que funciona
    string s = alumnoToString(a);
    cout << "Serializado: " << s << endl;

    Alumno b = alumnoFromString(s);
    cout << "Legajo recuperado: " << b.legajo << endl;

    // IMPORTANTE: getTokenAt usa char(1) para separar campos
    // pero adentro la Coll<string> usa '#' para separar sus elementos
    // Son separadores DISTINTOS para cada nivel

    return 0;
}
