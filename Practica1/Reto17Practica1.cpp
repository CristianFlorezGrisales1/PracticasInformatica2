
#include <iostream>

using namespace std;

int main(){

    int numero,numeroMayor=0;
    cout<<"Ingrese un numero: ";
    cin>>numero;

    if(numero==0){
        cout<<"el numero mayor es: 0";
    }
    else{

        while(numero!=0){
            if(numero>numeroMayor ){
                numeroMayor=numero;
            }
            cout<<"Ingrese un nuevo numero: ";
            cin>>numero;

        }
        cout<<"El numero mayor de los ingresados es: "<<numeroMayor;
    }


    return 0;
}
