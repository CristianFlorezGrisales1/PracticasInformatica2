#include <iostream>

using namespace std;

// Función para calcular el máximo común divisor (MCD) de dos números
int calcularMCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para calcular el mínimo común múltiplo (MCM) de dos números
int calcularMCM(int a, int b) {
    return (a * b) / calcularMCD(a, b);
}

int main() {
    int numero;
    
    cout << "Ingrese un número: ";
    cin >> numero;

    if (numero <= 0) {
        cout << "El número debe ser positivo." << endl;
    } else {
        int mcm = 1;

        // Calcular el MCM de todos los números enteros entre 1 y el número ingresado
        for (int i = 2; i <= numero; i++) {
            mcm = calcularMCM(mcm, i);
        }

        cout << "El mínimo común múltiplo es: " << mcm << "." << endl;
    }

    return 0;
}
