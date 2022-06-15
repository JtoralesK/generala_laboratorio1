#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargaDados(int v[],int tam,int arranca){
    srand(time(0));
    for(int i=arranca;i<tam;i++){
        int r;
        r= rand()%6+1;
        v[i]=r;
    }
}
int guardaDados(int v[],int vViejo[],int vNuevo[]){
    int iNuevo =0;
    for(int i=0;i<5;i++){
      if(v[i]==1){
        vNuevo[iNuevo]=vViejo[i];
        iNuevo++;
    }
  }

    return iNuevo;
}
void imprimeVector(int v[],int tam){
    for(int i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}
void ingresaDadosQueQuedan(int v[]){
  for(int i=0;i<5;i++){
    cout<<"dado "<<i+1<<":";cin>>v[i];
  }

}
void jugador1(){
    int t;
    cout<<"ingrese 1 para tirar los dados:";cin>>t;
    if(t==1){
    bool seguir=true;
    int vuelta=0;
    while(seguir==true){

    vuelta++;
        int tirada1[5];
        int tirada2[5];
        int tirada3[5];
        switch(vuelta){
        case 1:{
          cout<<"Dados:"<<endl;
            cargaDados(tirada1,5,0);
            imprimeVector(tirada1,5);
            break;
        }

        case 2:{
            int vDadosQuedan[5];
            cout<<"ingrese 1 para guardar el dado y 0 para cambiarlo"<<endl;
            ingresaDadosQueQuedan(vDadosQuedan);
            system("cls");
            int dadosGuardados=guardaDados(vDadosQuedan,tirada1,tirada2);
            cargaDados(tirada2,5,dadosGuardados);
            cout<<"Dados:"<<endl;
            imprimeVector(tirada2,5);
            break;
        }

         case 3:{
            int vDadosQuedan[5];
            cout<<"ingrese 1 para guardar el dado y 0 para cambiarlo"<<endl;
            ingresaDadosQueQuedan(vDadosQuedan);
            system("cls");
            int dadosGuardados=guardaDados(vDadosQuedan,tirada2,tirada3);
            cargaDados(tirada3,5,dadosGuardados);
            cout<<"Dados:"<<endl;
            imprimeVector(tirada3,5);
            break;
         }

        }
        if(vuelta==3){
        seguir=false;
          }









    }

    }


}
void pantalla1(){
    int x;
    cout<<"1| 1 jugador"<<endl;
    cout<<"2| 2 jugadores"<<endl;
    cout<<"ingrese:";cin>>x;
    system("cls");

    if(x==1){
        jugador1();
    }
    if(x==2){
       // jugador2();
    cout<<"jugador2"<<endl;
    }



}







#endif // FUNCIONES_H_INCLUDED
