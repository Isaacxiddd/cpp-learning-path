/*
  EJERCICIO 4: Constructor de struct
  Hacer una funcion constructora para Persona
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

struct Persona {
    int id;
    string nombre;
};

// Completar constructor: Persona persona(int id, string nombre)
// Persona ??? { Persona p; p.id = ???; p.nombre = ???; return p; }

Persona persona(int n , string a){
Persona p;
p.id = n;
p.nombre = a;
return p;
}
// ToString
string personaToString(Persona x) {
    char sep = 1;
    return to_string(x.id) + sep + x.nombre;
}

// FromString
Persona personaFromString(string s) {
    char sep = 1;
    Persona x;
    x.id = stoi(getTokenAt(s, sep, 0));
    x.nombre = getTokenAt(s, sep, 1);
    return x;
}

int main() {
    // Crear 2 personas. Una SIN constructor (a mano), otra CON constructor
    // Persona p1; p1.id = ... ; p1.nombre = ... ;
    // Persona p2 = persona(2, "Maria");

    Persona p1;
    p1.id = 23;
    p1.nombre = "juan";

   Persona p2 = persona(23,"carlos");


   cout << p2.nombre<< endl;
   cout << p1.nombre<< endl;



    // Mostrar los nombres
    // ???
    cin.get();
    return 0;
}
