
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
    int A, B;
    
    cout << "Ingrese el primer número (A): ";
    cin >> A;

    cout << "Ingrese el segundo número (B): ";
    cin >> B;

    int mcm = calcularMCM(A, B);

    cout << "El MCM de " << A << " y " << B << " es: " << mcm << "." << endl;

    return 0;
}