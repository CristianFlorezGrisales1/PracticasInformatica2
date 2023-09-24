#include<iostream>
using namespace std;

int main() {
    int num, espacios, asteriscos;

    cout << "Ingrese un numero:";
    cin >> num;

    espacios = (num - 1) / 2;
    asteriscos = num - (num - 1);

    // while de parte de arriba de la pirámide


    while (asteriscos <= num) {

        for (int i = 0; i < espacios; i++) {
            cout << " ";
        }

        for (int i = 0; i < asteriscos; i++) {
            cout << "*";
        }

        cout << endl;

        asteriscos = asteriscos + 2;
        espacios = espacios - 1;
    }


    // while segunda parte de la pirámide


    int espaciosIzq, espaciosDer;

    espaciosIzq = 1;
    espaciosDer = 1;
    asteriscos = num - 2;

    while (asteriscos >= 1) {
        for (int i = 0; i < espaciosIzq; i++) {
            cout << " ";
        }

        for (int i = 0; i < asteriscos; i++) {
            cout << "*";
        }


        for (int i = 0; i < espaciosDer; i++) {
            cout << " ";
        }

        cout << endl;


        espaciosIzq = espaciosIzq + 1;
        asteriscos = asteriscos - 2;
        espaciosDer = espaciosDer + 1;
    }

    return 0;
}
