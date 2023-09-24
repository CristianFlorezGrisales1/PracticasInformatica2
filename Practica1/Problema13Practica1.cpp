#include <iostream>
using namespace std;



bool esPrimo(int numeros){

    int residuo;

    bool bandera=true;

    for(int i=2;i< numeros;i++){
        residuo=numeros%i;

        if(residuo==0){

           bandera=false;

           return(bandera);
            }
     }
    return(bandera);
}




int main(){

    int numeroUsers,suma=0;
    bool valor;

    cout <<"ingrese un numero:";
    cin>>numeroUsers;

    // La variable 'numeros' se inicializa en 2 porque aquí se generarán los posibles primos del número ingresado por el usuario, pero el número 1 no se considera primo, por lo tanto se inicia desde 2.

    for(int numeros=2;numeros<numeroUsers;numeros++){
            valor=esPrimo(numeros);

        if(valor){
            suma=suma+numeros;
        }
      }

    cout<<suma;


    return 0;
}
