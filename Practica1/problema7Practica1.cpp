#include <iostream>

using namespace std;

bool esPar(int numero) {
    return (numero % 2 == 0);
}


int main() {
    int suma = 0;
    int numero;
    int terminoAnterior = 1;
    int terminoActual = 1;
    int futura = 0;

    cout << "Ingrese un número: ";
    cin >> numero;

    while (terminoActual <= numero) {
        if (esPar(terminoActual)) {
            suma += terminoActual;
        }

        futura = terminoAnterior + terminoActual;
        terminoAnterior = terminoActual;
        terminoActual = futura;
    }

    cout << "La suma de los terminos pares menores o iguales a " << numero << " que se producen el serie Fibonacci es: " << suma << endl;

    return 0;
}
