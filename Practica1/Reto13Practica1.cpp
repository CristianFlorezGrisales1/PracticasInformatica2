#include <iostream>

using namespace std;

int main() {
    
    int numN;
    cout<<"Ingrese un numero: ";
    cin>>numN;
    cout<<"\n";
    cout<<"los divisores de "<<numN<<" son:"<<"\n";
    
    
    for (int i=1;i<numN+1;i++){
        
        if (numN % i== 0){
            cout<<i<<endl;
        }
    }

    return 0;
}
