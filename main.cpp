#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
#include "funciones.h"
int main(){
    bool seguir=true;
    while(seguir==true){
    int opciones;
    system("cls");
    cout<<"-----------------------------"<<endl;
    cout<<"1| Iniciar partida"<<endl;
    cout<<"0| Salir del programa"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"Opcion:";cin>>opciones;
     system("cls");
    switch(opciones){
        case 0:
        cout<<"Salio del programa"<<endl;
        seguir=false;
        break;
        case 1:
        pantalla1();
        cout<<"caso 1"<<endl;
        break;
        case 2:
        cout<<"caso 2"<<endl;
        break;
        default : cout<<"opcion incorrecta"<<endl;
    }
    system("pause");
    }
    return 0;
}
