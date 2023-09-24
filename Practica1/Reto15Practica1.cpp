#include <iostream>

using namespace std;

int main(){

    int numero,sumatoria=0;
    cout<<"Ingrese un numero: ";
    cin>>numero;

    if(numero==0){
        cout<<"La sumatoria es: 0";
    }
    else{

        while(numero!=0){
            sumatoria=sumatoria+numero;
            cout<<"Ingrese un nuevo numero: ";
            cin>>numero;

        }
        cout<<"la sumatoria de los numeros ingresados es: "<<sumatoria;
    }


    return 0;
}