#include <iostream>
using namespace std;

int main() {
    
    int sumaNumeros=0,num;
    
    cout<<"Ingrese un numero: ";
    cin>>num;
    
    for (int i = 1; i < num+1; i++) {
        ///cout << i << "\n";
        sumaNumeros=sumaNumeros+i;
    }
    cout<<"la suma entre los numeros que hay entre 0 y "<<num<<" es :"<<sumaNumeros;

    return 0;
}