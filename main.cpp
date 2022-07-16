# include<iostream>
# include<cstdlib>
# include<time.h>
# include<string.h>

using namespace std;
#include "funciones.h"
int main(){
    bool seguir=true;
    char palabras[2][10];
    int opciones,maximo=0,maxNombre=0,maxTiradas=0,ultimoPuntaje, ganador;
    while(seguir==true){
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
                        maxNombre=1;}
        break;
        case 2:
            ultimoPuntaje=iniciaPartida(palabras,opciones,ganador,maxTiradas);
                if(ultimoPuntaje>maximo){maximo=ultimoPuntaje;}
        break;
        case 3:
            cout<<"el record actual es de: "<<maximo<<endl;
            cout<<"nombre del jugador:"<<palabras[ganador]<<endl;
            cout<<"tiradas:"<<maxTiradas<<endl;
        system("pause");
        default : cout<<"opcion incorrecta"<<endl;
    }
    }
    return 0;
}
