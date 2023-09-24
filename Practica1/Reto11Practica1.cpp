#include <iostream>

using namespace std;

int main() {
    
    int numN;
    
    cout << "Ingrese un numero: ";
    cin >> numN;
    
    
    int multiplicacion = numN;
    
    for (int i = 1; i <= 10; i++) { // Corrección: Debes declarar e inicializar 'i' en el bucle
        multiplicacion = multiplicacion * i;
        cout << i <<"*"<< numN<<"=" << multiplicacion<<endl;
        multiplicacion=numN;
    }
    return 0;
}
