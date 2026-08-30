/*
  EJERCICIO 3: Struct simple con serializacion
  Definir un struct Persona, hacer ToString y FromString
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"

using namespace std;

// Definir struct Persona con: int id, string nombre
// struct Persona { ??? }
struct Persona {
   string nombre;
   int id;
};

string personaToString(Persona p){
  string sep = "|";
 string a = intToString(p.id);
 return p.nombre + sep + a;
}

// Funcion personaFromString(string s) que usa getTokenAt
// Persona ???
Persona personaFromString(string s){

 return  Persona{getTokenAt(s,'|',0),stringToInt(getTokenAt(s,'|',1))};
}


// Funcion comparadora cmpPersonaId(Persona p, int id)
// int ???
int cmpPersonaId(Persona p, int id){
if(p.id == id){return 0;}else if(p.id>id){return 1;}
    return -1;
}
int main() {
Coll<Persona> col = coll<Persona>('&');
Persona p1 = {"isaac",1};
Persona p2 = {"isaac",2};
Persona p3 = {"isaac",3};

collAdd<Persona>(col, p1, personaToString);
collAdd<Persona>(col, p2, personaToString);
collAdd<Persona>(col, p3, personaToString);

cout << "collSize = " << collSize<Persona>(col) << endl;
int pos = collFind<Persona, int>(col, 2,cmpPersonaId,personaFromString);
cout << "pos = " << pos << endl;
if (pos >= 0)
{
    Persona encontrada = collGetAt<Persona>(col, pos, personaFromString);
    cout << encontrada.nombre << endl;
}

    // Crear Coll<Persona> con separador '&'
    // ???

    // Agregar 3 personas
    // ???

    // Buscar persona con id=2
    // collFind<Persona, int>(...)
    // Si la encuentra, mostrar su nombre con collGetAt
    // ???

    cin.get();
    return 0;
}
