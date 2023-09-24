
#include <iostream>


using namespace std;

int main (){
    char caracter;
    cout<<"Ingrese un caracter:";
    cin>>caracter;
    if(((caracter>='A')&&(caracter<='Z'))||((caracter>='a')&&(caracter<='z'))){
        if((caracter>='A')&&(caracter<='Z')){
            caracter=caracter+32;
            cout<<"letra convertida: "<<caracter;
        }
        else{
            caracter=caracter-32;
            cout<<"letra convertida: "<<caracter;
            }
    }
    else{
        cout<<"El caracter "<<caracter<<" NO es una letra"<<endl;
    }

    return 0;
    }
