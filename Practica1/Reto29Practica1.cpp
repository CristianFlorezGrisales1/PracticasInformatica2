
#include <iostream>
using namespace std;



int main() {
    cout << "Piensa en un número entre 0 y 100 (sin decirlo) y yo trataré de adivinarlo." << endl;

    int limiteInferior = 0;
    int limiteSuperior = 100;
    char respuesta;

    while (limiteInferior <= limiteSuperior) {
        int intento = (limiteInferior + limiteSuperior) / 2;
        cout << "¿Es " << intento << "? Ingresa '<' si es menor, '>' si es mayor o '=' si adiviné: ";
        cin >> respuesta;

        if (respuesta == '=') {
            cout << "¡Adiviné tu número! Es " << intento << endl;
            break;
        } else if (respuesta == '<') {
            limiteSuperior = intento - 1;
        } else if (respuesta == '>') {
            limiteInferior = intento + 1;
        } else {
            cout << "Respuesta no válida. Usa '<', '>', o '='." << endl;
        }
    }

    return 0;
}