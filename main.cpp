# include<iostream>
# include<cstdlib>
# include<time.h>
#include <stdlib.h>
#include <string.h>
# include<string.h>
///Integrantes: Agustin Milanes y Javier Torales
using namespace std;
#include "funciones.h"
int main(){
    bool seguir=true;
    char palabras[2][10],nombre[10];
    int opciones,maximo=0,tiradas=0;
    while(seguir==true){
    int ultimoPuntaje,maxTiradas=0,ganador;
    system("cls");
    cout<<"-----------------------------"<<endl;
    cout<<"1| Juego nuevo de a 1"<<endl;
    cout<<"2| Juego nuevo entre 2"<<endl;
    cout<<"3| Puntacion mas alta"<<endl;
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
            ultimoPuntaje=iniciaPartida(palabras,opciones,ganador,maxTiradas);
                if(ultimoPuntaje>maximo){
                        maximo=ultimoPuntaje;
                        tiradas=maxTiradas;
                         strcpy(nombre,palabras[ganador]);
                        }
        break;
        case 2:
            ultimoPuntaje=iniciaPartida(palabras,opciones,ganador,maxTiradas);
                if(ultimoPuntaje>maximo){
                        maximo=ultimoPuntaje;
                        tiradas=maxTiradas;
                         strcpy(nombre,palabras[ganador]);
                }
        break;
        case 3:
            cout<<"el record actual es de: "<<maximo<<endl;
            cout<<"nombre del jugador:"<<nombre<<endl;
            cout<<"tiradas:"<<tiradas<<endl;
        system("pause");
        default : cout<<"opcion incorrecta"<<endl;
    }
    }
    return 0;
}
