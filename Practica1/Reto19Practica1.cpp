#include <iostream>

using namespace std;

int main(){

    int numeroN;
    bool valorfv;

    cout<<"Ingrese un numero: ";
    cin>>numeroN;

    for(int i=2;i<numeroN;i++){

        if (numeroN%i==0){
            valorfv=false;

             break;
        }

        else{
             valorfv=true;

        }


    }

    if(valorfv){
        cout<<"El "<<numeroN<<" es un numero primo";
    }


    else{
        cout<<"El "<<numeroN<<" NO es un numero primo";
    }

    return 0;
}
