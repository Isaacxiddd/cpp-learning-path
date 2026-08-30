/*
  EJERCICIO 2: Comparador y collFind
  Hacer una funcion comparadora y buscar elementos en una Coll
*/

#include <iostream>
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/funciones/strings.hpp"

using namespace std;

// Completar: funcion que compara dos strings
// Devuelve 0 si son iguales
// int cmpStringString(string a, string b) { ??? }

int cmpStringString(string a, string b)
{
    if (a >  b)
    {
    return 1;
    } else if(a < b)
    {
   return -1;
    }else {
        return 0;
    }
}


int main() {
    Coll<string> col = coll<string>('#');
    collAdd<string>(col, "perro", stringToString);
    collAdd<string>(col, "gato", stringToString);
    collAdd<string>(col, "pajaro", stringToString);

  string b = "gato";

    int posicion = collFind<string>(col,b,cmpStringString,stringToString);

    // Buscar "gato" con collFind<string, string>(...)
    // La funcion fromString para strings es stringToString
    // int pos = ???

    // Mostrar si lo encontro o no
    // ???
    string r = "";
   if(posicion > -1){
     r = "resultado correcto";
   }else{
     r = "resultado incorrecto";
   }
   cout<< r <<endl;
   cin.get();
    return 0;
}
