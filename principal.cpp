#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

int sumar(int a, int b){ // se declara la funcion
    return a + b;
}

int main()
{
    int n = sumar(1, 2); // le asignamos a n, el resultado de invocar a la funcion sumar y pasarle 1 y 2 

    cout << n << endl; //imprimimos

    std::cin.get(); //ignores 

    return 0; 
}