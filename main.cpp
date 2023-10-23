#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------------

string leerArchivobinario(){

    ifstream archivoB;
    string texto;

    archivoB.open("C:\\Users\\ASUS\\Desktop\\archivoB.txt",ios::in);
    if (archivoB.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    while (!archivoB.eof()) {
        getline(archivoB, texto);

    }

    archivoB.close();

    return texto;
}
//----------------------------------------------------------------------------------------------------------------------------------------

string leerArchivo() {

    ifstream archivoC;
    string texto;

    archivoC.open("C:\\Users\\ASUS\\Desktop\\archivoC.txt", ios::in);

    if (archivoC.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    while (!archivoC.eof()) {
        getline(archivoC, texto);

    }

    archivoC.close();
    return texto;
}

//---------------------------------------------------------------------------------------------------------------------------------


string convertirBinario(string textoCualquiera, int semilla) {

    string oldBinario;

    for (char caracter : textoCualquiera) {
        // Convierte cada carácter en su valor ASCII
        int valorASCII = static_cast<int>(caracter);

        // Convierte el valor ASCII en una representación binaria de 8 bits
        for (int i = 7; i >= 0; i--) {
            oldBinario += ((valorASCII & (1 << i)) ? '1' : '0');
        }
    }

    cout<<oldBinario<<endl;
    return oldBinario;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------


string encriptacionDemasBloquesMetodo1(string sinCodificar,int semilla,int limiteInferior){

    string bloqueAnterior = "", bloqueActual = "";
    int contador1s = 0, contador0s = 0;
    string encriptadoActual = "";

    bloqueAnterior = sinCodificar.substr(limiteInferior, semilla);

    for (char caracter : bloqueAnterior) {
        if (caracter == '1') {
            contador1s++;
        }
        if (caracter == '0') {
            contador0s++;
        }
    }

    limiteInferior = limiteInferior + semilla;

    if (contador0s == contador1s) {
        bloqueActual = sinCodificar.substr(limiteInferior, semilla);
        for (char i : bloqueActual) {
            if (i == '1') {
                encriptadoActual = encriptadoActual + '0';
            }
            if (i == '0') {
                encriptadoActual = encriptadoActual + '1';
            }
        }
    }

    if (contador0s > contador1s) {
        int contadorbits = 0;
        bloqueActual = sinCodificar.substr(limiteInferior, semilla);
        for (char i : bloqueActual) {
            contadorbits++;
            if (contadorbits == 2) {
                contadorbits = 0;
                if (i == '0') {
                    encriptadoActual = encriptadoActual + "1";
                }


                if (i == '1') {
                    encriptadoActual = encriptadoActual + "0";
                }

            }
            else{
                encriptadoActual=encriptadoActual+i;
            }
        }
    }


    if (contador0s<contador1s) {
        int contadorbits = 0;
        bloqueActual = sinCodificar.substr(limiteInferior, semilla);
        for (char i : bloqueActual) {
            contadorbits++;
            if (contadorbits == 3) {
                contadorbits = 0;
                if (i == '0') {
                    encriptadoActual = encriptadoActual + "1";
                }


                if (i == '1') {
                    encriptadoActual = encriptadoActual + "0";
                }

            }
            else{
                encriptadoActual=encriptadoActual+i;
            }
        }
    }




   /* cout << bloqueAnterior << endl;
    cout << bloqueActual << endl;
    cout << encriptadoActual;*/

    return encriptadoActual;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
string desencriptacionDemasBloquesMetodo1(string textoBinario,int semilla,int limiteInferior){

    string bloqueAnterior = "", bloqueActual = "";
    int contador1s = 0, contador0s = 0;
    string desencriptadoActual = "";

    bloqueAnterior = textoBinario.substr(limiteInferior, semilla);

    for (char caracter : bloqueAnterior) {
        if (caracter == '1') {
            contador1s++;
        }
        if (caracter == '0') {
            contador0s++;
        }
    }

    limiteInferior = limiteInferior + semilla;

    if (contador0s == contador1s) {
        bloqueActual = textoBinario.substr(limiteInferior, semilla);
        for (char i : bloqueActual) {
            if (i == '1') {
                desencriptadoActual = desencriptadoActual + '0';
            }
            if (i == '0') {
                desencriptadoActual = desencriptadoActual + '1';
            }
        }
    }

    if (contador1s > contador0s) {
        int contadorbits = 0;
        bloqueActual = textoBinario.substr(limiteInferior, semilla);
        for (char i : bloqueActual) {
            contadorbits++;
            if (contadorbits == 3) {
                contadorbits = 0;
                if (i == '0') {
                    desencriptadoActual = desencriptadoActual + "1";
                }


                if (i == '1') {
                    desencriptadoActual = desencriptadoActual + "0";
                }

            }
            else{
                desencriptadoActual=desencriptadoActual+i;
            }
        }
    }


    if (contador0s<contador1s) {
        int contadorbits = 0;
        bloqueActual = textoBinario.substr(limiteInferior, semilla);
        for (char i : bloqueActual) {
            contadorbits++;
            if (contadorbits == 2) {
                contadorbits = 0;
                if (i == '0') {
                    desencriptadoActual = desencriptadoActual + "1";
                }


                if (i == '1') {
                    desencriptadoActual = desencriptadoActual + "0";
                }

            }
            else{
                desencriptadoActual=desencriptadoActual+i;
            }
        }
    }




    cout << desencriptadoActual;

    return desencriptadoActual;

}
//----------------------------------------------------------------------------------------------------------------------------------------------------

string metodo1(string sinCodificar,int semilla){

    //encriptacion de primer bloque de binarios
    string binarioEncriptadoF="";

    string bloque1 = sinCodificar.substr(0, semilla);

    for(char caracter:bloque1){

        if (caracter=='1'){
            binarioEncriptadoF=binarioEncriptadoF+"0";
        }
        if(caracter=='0'){
            binarioEncriptadoF=binarioEncriptadoF+"1";
        }

    }


    int limiteInferior=0;
    int longitudBinario=sinCodificar.size();
    int numbloques=longitudBinario/semilla;
    int contadorBloques=1;


    while(contadorBloques<=numbloques){
    string  demasBloquesEncriptados=encriptacionDemasBloquesMetodo1(sinCodificar,semilla,limiteInferior);

    binarioEncriptadoF=binarioEncriptadoF+demasBloquesEncriptados;
    demasBloquesEncriptados="";
    limiteInferior=limiteInferior+semilla;
    contadorBloques++;
    }






    cout<<binarioEncriptadoF;
    return binarioEncriptadoF;

}

//------------------------------------------------------------------------------------------------------------------------------------------


string metodo2(string sinCodificar, int semilla){

    string BinarioEncriptadoF="";
    int limiteInferior=0;


    int longitudBinario=sinCodificar.size();
    int numbloques=longitudBinario/semilla;
    int contadorBloques=0;

    while(contadorBloques<numbloques){

    char ultimoCaracter = sinCodificar.back();
    string subCadena = sinCodificar.substr(limiteInferior, semilla-1);

    string bloqueCodificado=ultimoCaracter+subCadena;

    BinarioEncriptadoF=BinarioEncriptadoF+bloqueCodificado;
    contadorBloques++;

    bloqueCodificado="";
    limiteInferior=limiteInferior+semilla;
    }

    cout<<BinarioEncriptadoF;
    return BinarioEncriptadoF;
}

//---------------------------------------------------------------------------------------------------------------------------------------
string desenencriptacionMetodo1(string textoBinario, int semilla){

    //desencriptacion de primer bloque de binarios
    string binarioDesencriptadoF="";

    string bloque1 = textoBinario.substr(0, semilla);

    for(char caracter:bloque1){

    if (caracter=='1'){
            binarioDesencriptadoF=binarioDesencriptadoF+"0";
    }
    if(caracter=='0'){
            binarioDesencriptadoF=binarioDesencriptadoF+"1";
    }

    }

    int limiteInferior=0;
    int longitudBinario=textoBinario.size();
    int numbloques=longitudBinario/semilla;
    int contadorBloques=1;

    while(contadorBloques<=numbloques){
    string  demasBloquesDesencriptados=desencriptacionDemasBloquesMetodo1(textoBinario,semilla,limiteInferior);

    binarioDesencriptadoF=binarioDesencriptadoF+demasBloquesDesencriptados;
    demasBloquesDesencriptados="";
    limiteInferior=limiteInferior+semilla;
    contadorBloques++;
    }


    cout<<binarioDesencriptadoF;
    return binarioDesencriptadoF;

}



//----------------------------------------------------------------------------------------------------------------------------------------
string desenEncriptacionMetodo2(string textoBinario, int semilla){

    string BinarioDesencriptadoF="";
    int limiteInferior=1;


    int longitudBinario=textoBinario.size();
    int numbloques=longitudBinario/semilla;
    int contadorBloques=0;
    int primerCaracterBloque=0;

    while(contadorBloques<numbloques){

    char primerCaracter = textoBinario[primerCaracterBloque];
    string subCadena = textoBinario.substr(limiteInferior, semilla-1);

    string bloqueDescodificado=subCadena+primerCaracter;

    BinarioDesencriptadoF=BinarioDesencriptadoF+bloqueDescodificado;
    contadorBloques++;

    bloqueDescodificado="";
    limiteInferior=limiteInferior+semilla;
    primerCaracterBloque=primerCaracterBloque+semilla;
    }


    cout<<"Desencriptado:"<<BinarioDesencriptadoF;
    return BinarioDesencriptadoF;
}
//------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    int opcion;
    cout << "Bienvenido a la aplicacion codificadora de textos." << endl;
    cout << "Para codificar un texto elija la opcion 1 (coloque 1) o opcion 2 (coloque 2) o para descodificar un texto ingrese 3:";
    cin >> opcion;

    switch (opcion) {
    case 1: {
        string texto = leerArchivo();
        int semilla;
        cout << "Ingrese la semilla para dividir los bloques: ";
        cin >> semilla;
        string sinCodificar=convertirBinario(texto, semilla);
        string binarioEncriptado=metodo1(sinCodificar,semilla);



        break;
    }
    case 2: {
        string texto = leerArchivo();
        int semilla;
        cout << "Ingrese la semilla para dividir los bloques: ";
        cin >> semilla;
        string sinCodificar=convertirBinario(texto, semilla);
        string binarioEncriptado=metodo2(sinCodificar,semilla);

        break;
    }
    case 3:{

        int opcion;
        string textoBinario = leerArchivobinario();
        int semilla;
        cout << "Ingrese la semilla para dividir los bloques: ";
        cin >> semilla;
        cout<<"Por que metodo quiere desencriptar el archivo metodo 1 o metodo 2:";
        cin>>opcion;
        cout<<"codificado:"<<textoBinario<<endl;
        if(opcion==1){

            string binarioDesencriptado=desenEncriptacionMetodo2(textoBinario,semilla);
            break;

        }
        if(opcion==2){
            string binarioDesencriptado=desenEncriptacionMetodo2( textoBinario, semilla);

        }
        else{
            cout<<"OPCION NO VALIDA";



        }

        break;
    }


    default:
        cout << "Opcion no valida." << endl;
        break;
    }

    return 0;
}
