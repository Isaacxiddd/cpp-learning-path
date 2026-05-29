
#include <iostream>
#include "biblioteca/funciones/millis_v1.1.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/parte1/Fecha_v1.2_Empty.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "principal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;


int main()
{
Fecha f = fecha(2026,10,9); // 9 de octubre de 2026
fechaSetAnio(f,1990); // cambio a 9 de octubre de 1990
cout<<f.anio<<endl;
std::cin.ignore().get();
return 0;
}
