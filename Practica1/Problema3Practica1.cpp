
#include <iostream>

using namespace std;

int main(){

    int dia,mes;

    cout<<"ingrese mes:",
    cin>>mes;
    cout<<"Ingrese dia:";
    cin>>dia;

    if((mes==2)&&(dia==29)){
        cout<<"La fecha 29/2 es valida,si es un año bisiesto";
            return 0;
    }

    
    
    
    if (((mes<=12)&&(dia<=31))&&((mes!=2)&&(dia<=28))){

            cout<<"La fecha "<<dia<<"/"<<mes<<" es valida";
        }
    else{
         cout<<"La fecha "<<dia<<"/"<<mes<<" es invalida";
    }



    return 0;
}
