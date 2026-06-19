#include <iostream> 
using namespace std;

int main(){ 
    int i;
     cout << "escribe un numero"<< endl;
    cin >> i;
    long long resultado = 1;
    if(i > 0){
    while (i > 1){
     resultado = resultado * i;
     i = i - 1;
    }
  cout <<"El resultado es " << resultado << endl;

}else if(i == 0){
    resultado = 1;
    cout <<"El resultado es " << resultado << endl;

}else if (i < 0){
 cout <<"numero invalido pruebe de nuevo" << endl;

}

    cin.ignore();
    cin.get();
    return 0;
}
