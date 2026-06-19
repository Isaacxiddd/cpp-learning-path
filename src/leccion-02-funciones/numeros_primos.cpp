#include <iostream>
using namespace std;

bool esPrimo(int n, int i){

    if(n <= 1){
        return false; //evalua si es invalido
    }

    if(i == n){
        return true; //si llega hasta el numero es que es primo
    }

    if(n % i == 0){
        return false;
    }

    return esPrimo(n, i + 1); 
}

int main(){

    int n = 0;
    cout << "escribe un numero" <<endl;
    cin >> n;

    if(esPrimo(n, 2)){
        cout << "el numero " << n << " es primo" << endl;
    }else{
        cout << "el numero " << n << " no es primo" << endl;
    }
    cin.ignore();
    cin.get();
    return 0;
}
