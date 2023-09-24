#include <iostream>

using namespace std;

int elevar(int digito,int numero) {
    int numeroElevado = 1;
    
    for (int i = 0; i < digito; i++) {
       numeroElevado = numeroElevado * numero;

    }
    
    return numeroElevado;
}




int main() {
    int numero, digito, suma = 0;
    bool valor = true;
    
    cout << "Ingrese un número:";
    cin >> numero;
    
    while (valor) {
        digito = numero % 10;
        numero = numero / 10;
        suma = suma + elevar(digito, digito);
        if (numero == 0) {
            valor = false;
        }
    }
    
    cout << "La suma de los dígitos elevados a sí mismos es: " << suma << endl;
    
    return 0;
}
