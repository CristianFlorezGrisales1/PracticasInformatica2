#include<iostream>

using namespace std;

int main(){

    int num1,parteEntera=1,numeroDigitos=0;
    cout<<"ingrese un numero: ";
    cin>>num1;
    cout<<"\n";

    while(parteEntera!=0){
        parteEntera=(num1/10);
        num1=parteEntera;//este cambio de num1=partEntera se realiza para que la division entre 10 se haga de forma ciclica algo como 10/10=1 despues 1/10=0.1
        numeroDigitos=numeroDigitos+1;
    }
    cout<<numeroDigitos;




    return 0;
}