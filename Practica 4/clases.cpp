#include "clases.h"

#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;



//---------------------------------------------------------------------------------------------------------------------------------------------------
Routers::Routers(string namePadreR)
{

    tablaEnrutamiento[namePadreR] = {{namePadreR, 0}};

}

void Routers::agregarEnrutador()
{   string nombreVecino;
    int costoDeRouter;
    cout<<"Ingresa el Nombre del enrutador:";
    cin>>nombreVecino;
    cout<<"Ingresa el nuevo coste";
    cin>>costoDeRouter;
    tablaEnrutamiento.insert({nombreVecino, {{namePadreR, costoDeRouter}}});
    cout<<"\n";
    cout<<"Proceso exitoso"<<endl;
    menuRouters();

}

void Routers::eliminarEnrutador(){
    string nombreVecino;

    cout<<"Ingresa el Nombre del enrutador al cual se le va cambiar el precio de enlace:";
    cin>>nombreVecino;

    //importante !!!!!verifica si el nombre del router si esta en el mapa!!!! si no esta devolver al menu principal de router

    tablaEnrutamiento.erase(nombreVecino);
    cout<<"\n";
    cout<<"Proceso exitoso"<<endl;
    menuRouters();
}




void Routers::cambiarCosto()
{
    string  nombreVecino;
    int nuevoCosto;
    cout<<"Ingresa el Nombre del enrutador al cual se le va cambiar el precio de enlace:";
    cin>>nombreVecino;
    cout<<"Ingresa el nuevo coste";
    cin>>nuevoCosto;

    //importante !!!!!verifica si el nombre del router si esta en el mapa!!!! si no esta devolver al menu principal de router

    tablaEnrutamiento.insert({nombreVecino, {{namePadreR, nuevoCosto}}});
    cout<<"\n";
    cout<<"Proceso exitoso"<<endl;
    menuRouters();
}



void Routers::dijkstra()
{

}

void Routers::mostrarTablaEnrutamiento()
{
    cout << "Tabla de Enrutamiento para el enrutador " << namePadreR << ":" << endl;

    for (const auto& entry : tablaEnrutamiento) {
        cout << "Enrutador: " << entry.first << " | Vecino: " << entry.second[0].first << " | Costo: " << entry.second[0].second << endl;
    }

}








//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
Red::Red(){

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void menuRed()
{
    string opcion;
    cout<<"Bienvenido a menu de Red"<<endl;

    if(opcion=="1"){

    }
    else if(opcion=="2"){

    }
    else{
        menuPrincipal();

    }

}

void menuRouters()
{
    Routers routerA("A");

    string opcion;
    cout<<"Bienvenido a menu de routers"<<endl;
    cout<<"Para agregar enrutador a la red ingrese 1,para eliminar enrutador de la red ingrese 2,ingrse 3 si desea cambiar el costo de alguna conexion ,para salir al menu principal, ingrese cualquier numero:";
    cin>>opcion;

    if(opcion=="1"){

        routerA.agregarEnrutador();
    }


    else if(opcion=="2"){
        string nombre;
        cout<<"Ingrese el nombre del enrutador:";
        cin>>nombre;
        routerA.eliminarEnrutador();
    }

    else if(opcion=="3"){

        routerA.cambiarCosto();

    }

    else{
        menuPrincipal();

    }

}

void menuPrincipal(){

    Routers routerA("A");
    string opcion;
    cout<<"BIENVENIDO AL MENU PRINCIPAL"<<endl;
    cout<<"Ingrese 1 para apartado de Routers, ingrese 2 para apartado de Red o cualquier numero para salir del sistema,3 ver tabla:";
    cin>>opcion;

    if(opcion=="1"){
        menuRouters();


    }
    else if(opcion=="2"){
        menuRed();

    }
    else if(opcion=="3"){
        routerA.mostrarTablaEnrutamiento();

    }
    else{

        menuPrincipal();
    }

}
