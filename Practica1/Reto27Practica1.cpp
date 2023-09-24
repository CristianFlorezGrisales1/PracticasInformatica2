#include <iostream>
using namespace std;

int suma(int num1, int num2) {
    int resultadoS = num1 + num2;
    return resultadoS;
}

int resta(int num1, int num2){
    int resultadoR = num1 - num2;
    return resultadoR;
}

int multiplicacion(int num1, int num2) {
    int resultadoM = num1 * num2;
    return resultadoM;
}

float division(float num1, float num2) {
    if (num2 != 0) {
        float resultadoD = num1 / num2;
        return resultadoD;
    } else {
        cout << "Error: No se puede dividir por cero." << endl;
        return 0.0;
    }
}

int main(){
    float num1, num2;
    char operando;

    cout << "CALCULADORA" << "\n" << "\n";
    cout << "Ingrese un numero:";
    cin >> num1;
    cout << "Ingrese operacion:";
    cin >> operando;
    cout << "\n";
    cout << "Ingrese un numero:";
    cin >> num2;
    cout << "La operacion ingresada es:" << num1 << operando << num2 << "\n";

    if (operando == '+'){
        int resultadoS = suma(num1, num2);
        cout << "El resultado es :" << num1 << operando << num2 << "=" << resultadoS;
    }

    if (operando == '-'){
        int resultadoR = resta(num1, num2);
        cout << "El resultado es :" << num1 << operando << num2 << "=" << resultadoR;
    }

    if (operando == '*'){
        int resultadoM = multiplicacion(num1, num2);
        cout << "El resultado es :" << num1 << operando << num2 << "=" << resultadoM;
    }

    if (operando == '/'){
        float resultadoD = division(num1, num2);
        cout << "El resultado es :" << num1 << operando << num2 << "=" << resultadoD;
    }

    return 0;
}
