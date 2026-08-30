#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h> 
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "../../../lib/funciones/Coll.hpp"
using namespace std;
struct RAutor{
  string nombre;
  Coll<string> frases;
};
struct RAnio{ 
    int anio;
    Coll<RAutor> autores;

};

RAutorToString(RAutor x){
    char sep = 1;
    string = s.nombre=x.nombre 
    string sFrases = collToString<string>(x.frases) 
    return x+sFrases 
};
