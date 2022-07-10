# include<iostream>
# include<cstdlib>
# include<time.h>
# include<string.h>

using namespace std;
#include "funciones.h"
int main(){
    bool seguir=true;
    while(seguir==true){
    int opciones;
    system("cls");
    cout<<"-----------------------------"<<endl;
    cout<<"1| Iniciar partida"<<endl;
    cout<<"0| Salir"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"Opcion:";cin>>opciones;
     system("cls");
    switch(opciones){
        case 0:
        cout<<"Salio del programa"<<endl;
        seguir=false;
        break;
        case 1:
        char palabras[2][10];
        iniciaPartida(palabras);
        break;
        default : cout<<"opcion incorrecta"<<endl;
    }
    }
    return 0;
}
