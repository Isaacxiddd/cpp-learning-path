#include <iostream>
using namespace std;

int main()
{
    int dias = 0;
    int ano = 0;
    int mes = 0;

    cout << "escribe el ano !" << endl;
    cin >> ano;

    cout << "escribe el mes !" << endl;
    cin >> mes;

    if (mes < 1 || mes > 12) {
        cout << "mes invalido" << endl;
    }
    else if (mes == 1) {
        cout << "tu mes es enero" << endl;
        cout << "tiene 31 dias" << endl;
    }
    else if (mes == 2) {
        if (!((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) {
            cout << "tu mes es febrero" << endl;
            cout << "tiene 28 dias" << endl;
        }
        else {
            cout << "tu mes es febrero" << endl;
            cout << "tiene 29 dias" << endl;
        }
    }
    else if (mes == 3) {
        cout << "tu mes es marzo" << endl;
        cout << "tiene 31 dias" << endl;
    }
    else if (mes == 4) {
        cout << "tu mes es abril" << endl;
        cout << "tiene 30 dias" << endl;
    }
    else if (mes == 5) {
        cout << "tu mes es mayo" << endl;
        cout << "tiene 31 dias" << endl;
    }
    else if (mes == 6) {
        cout << "tu mes es junio" << endl;
        cout << "tiene 30 dias" << endl;
    }
    else if (mes == 7) {
        cout << "tu mes es julio" << endl;
        cout << "tiene 31 dias" << endl;
    }
    else if (mes == 8) {
        cout << "tu mes es agosto" << endl;
        cout << "tiene 31 dias" << endl;
    }
    else if (mes == 9) {
        cout << "tu mes es septiembre" << endl;
        cout << "tiene 30 dias" << endl;
    }
    else if (mes == 10) {
        cout << "tu mes es octubre" << endl;
        cout << "tiene 31 dias" << endl;
    }
    else if (mes == 11) {
        cout << "tu mes es noviembre" << endl;
        cout << "tiene 30 dias" << endl;
    }
    else if (mes == 12) {
        cout << "tu mes es diciembre" << endl;
        cout << "tiene 31 dias" << endl;
    }

    cin.get();
    cin.get();

    return 0;
}
