#include <iostream>
using namespace std;

int main() {
    int numerador, denominador;

    cout << "Ingrese un numerador: ";
    cin >> numerador;

    cout << "Ingrese un denominador: ";
    cin >> denominador;

    // Validación
    if (denominador == 0) {
        cout << "Error: no se puede dividir por cero" << endl;
        return 1;
    }

    // Guardar valores originales
    int num_orig = numerador;
    int den_orig = denominador;

    // Algoritmo de Euclides (MCD)
    int aux;
    while (denominador != 0) {
        aux = denominador;
        denominador = numerador % denominador;
        numerador = aux;
    }

    int mcd = numerador;

    // Simplificación
    int num_simpl = num_orig / mcd;
    int den_simpl = den_orig / mcd;

    cout << "Fraccion simplificada: "
         << num_simpl << "/" << den_simpl << endl;

    return 0;
}
