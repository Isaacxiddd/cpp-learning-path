#include <iostream>
using namespace std;

int main(){
int numerador1 = 0;
int denominador1 = 0;
int numerador2 = 0;
int denominador2 = 0;
int pdenominador = 0;
int pnumerador = 0;

cout << "ingresa el numerador de la primera fraccion" <<endl;
cin >> numerador1;
cout << "ingresa el denominador de la primera fraccion" <<endl;
cin >> denominador1;
cout << "ingresa el numerador de la segunda fraccion" <<endl;
cin >> numerador2;
cout << "ingresa el denominador de la segunda fraccion" <<endl;
cin >> denominador2;
if (denominador1 == 0 || denominador2 == 0){
    cout<<"error fatal"<<endl;
    return 1;
}
if (denominador1 == denominador2){
     pdenominador = denominador1;
     pnumerador = numerador1 + numerador2;
} else {
       pdenominador = denominador1 * denominador2;
       pnumerador = (denominador1 * numerador2)+ (numerador1 * denominador2);
    }
cout << "tu funcion es "<< pnumerador <<"/"<< pdenominador <<endl;
    return 0;
}
