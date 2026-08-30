#include <iostream>
#include "../../lib/funciones/files.hpp"
#include "../../../lib/funciones/strings.hpp"
#include "../../lib/funciones/tokens.hpp"
#include "principal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

/*
    Dado el archivo FRASES.txt, se pide desarrollar un programa interactivo que le permita al usuario
    ver las frases que se pronunciaron en un anio seleccionado.
    Ejemplo:

    [SELECCIONE ANIO]
    1. 1996
    2. 2003
    3. 2011
    4. 2018
    >2

    [SELECCIONE AUTOR (2003)]
    1. Roldan, R.
    2. Perez, J. 
    > 1

    [FRASES (Roldan, R.)]
    La vida es lo que pasa mientras vives.
    Los dinosaurios no nenian cola, ni cabeza tampoco.
    Solo se que no quiero ir a sur.

    NOTA: No hay restricciones de ningun tipo.
*/


void descubrirLineas(int input,string autor)
{
FILE* f = fopen("FRASES.txt","rt");
string ln;
string a;

int anio;
int dato;
int i;
string autore; 
while(readLine(f,ln))
{
 dato = stringToInt(getTokenAt(ln,'-', 2));
 autore = getTokenAt(ln,'-', 1);
 
 if(autore == autor && i == input){
    cout<<getTokenAt(ln,'-', 1)<<endl;
 }
  i ++;
}
fclose(f);
cout<<a<<endl;

}
void mostrarAnios()
{
FILE* f = fopen("FRASES.txt","rt");
string ln;
string a;

int anio;
int dato;
int i = 1;
int anterior
string autore; 
while(readLine(f,ln))
{   
 if(anterior== getTokenAt(ln,'-', 2);
 {

}else{cout<<i<< " "<< getTokenAt(ln,'-', 2)<<endl;
 i ++;
 anterior = getTokenAt(ln,'-', 2);
 }

 fclose(f);
}





int main()

{

    Coll<anio> a = coll<anio>();

    mostrarAnios(a);
    string s = "";
    int anioo;
cout<< "ingresa un anio"<<endl;
cin >> anioo;
descubrirLineas(anioo, s);



    cout << "Hola Mundo !" << endl;
    cin.get();
    return 0;
}