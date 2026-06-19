/* 
  CONSIGNA - EJERCICIO DE CLASE 2:
  1. Crear una función llamada 'calcularEstadisticas' que:
     - Reciba dos números enteros por VALOR [5].
     - Reciba una variable entera por REFERENCIA (usando &) para guardar la suma [3].
     - RETORNE un valor double con el promedio de ambos números [2, 6].
  2. En el 'main': pedir dos números al usuario, llamar a la función y mostrar 
     por consola la suma y el promedio obtenidos.
*/
#include <iostream>
#include <string>
using namespace std;
double Calcular (int a , int b)
{
    
 int suma = a + b; 
 return (a + b)/2.0;
}
int main()
{
 int a = 0;
 int b = 0;
 int r = 0;
 cout << "escribe un numero ";
 cin >> a;
 cout << "escribe un numero ";
 cin >> b;
 r = Calcular(a, b );
 cout << r << endl;
 return 0;
}
