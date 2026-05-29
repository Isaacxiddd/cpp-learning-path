#include <iostream>
using namespace std;

int main() {
    int n = 5; // definí el número acá
    int prod = 1;

    while (n > 1) {
        prod = prod * n;
        n = n - 1;
    }

    cout << prod << endl;
    return 0;
}
