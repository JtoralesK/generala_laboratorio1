#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES
void ordenarVector(int v[], int tam );/// ordena de menor a mayor un vector
int contarNumerosRepetidos(int v[], int numero , int tam);///cuenta la cantidad de veces que se repite un //número en el vector
void poneTodoUnvEn0(int v[],int tam);///Pone todas las pociciones de un vector en 0

void niegaTodoVector(int v[],int tam){
 for(int x=0;x<tam;x++){
        v[x]=-1;
        }
}
void ordenarVector(int v[], int tam ){
   int i,j,aux,posMin;
   for(i=0;i<tam-1;i++){
        posMin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posMin])posMin=j;
        }
    aux=v[i];
    v[i]=v[posMin];
    v[posMin]=aux;
   }
}
int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}

void imprimeVector(int v[],int tam){
    ordenarVector(v,5);
    for(int i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}
  ///jugadas
int verificaEscalera(int v[],int tam){
    bool verifica=true;
    int full=0;
    int pri= v[0];
    for(int i=0;i<tam;i++){
      switch(pri){
      case 1:
        if(v[i]==(i+1) && (verifica==true) ){
            full=1;
        }else{
            verifica=false;
        full=0;
        }
        break;
        case 2:
        if(v[i]==(i+2) && (verifica==true) ){
            full=1;
        }else{
        verifica=false;
        full=0;
        }
        break;
      }
    }
   return full;
}
int verificaFull(int v[],int tam){
    int pri = v[0];
    int se= v[3];
    int dosDigitos= contarNumerosRepetidos(v,pri,tam);
   int tresDigitos= contarNumerosRepetidos(v,se,tam);
   int full1 = (dosDigitos==2) && (tresDigitos==3);
   int full2 = (tresDigitos==2) && (dosDigitos==3);
   if(full1 || full2){
    return 1;
   }else return 0;
}
int verificaPoker(int v[],int tam){
    int pri= v[0];
    int se= v[1];
   int poker1= contarNumerosRepetidos(v,pri,tam);
   int poker2= contarNumerosRepetidos(v,se,tam);
   if(poker1==4 || poker2==4){
    return 1;
   }else return 0;
}
int verificaGenerala(int v[]){
 int primero= v[0];
 int e =contarNumerosRepetidos(v,primero,5);
 if(e==5){
    return 1;
 }else return 0;

}
int eligeJugada(int tirada,int vPuntaje[]){
    if(tirada!=3)cout<<"0|para volver a tirar"<<endl;
    for(int i=0;i<6;i++){
        if(vPuntaje[i]==-1){
            cout<<i+1<<"|para "<<i+1<<endl;
        }
    }
    if(vPuntaje[6]==-1){
    cout<<"7|para E"<<endl;
    }
    if(vPuntaje[7]==-1){
    cout<<"8|para F"<<endl;
    }
    if(vPuntaje[8]==-1){
    cout<<"9|para P"<<endl;
    }
    if(vPuntaje[9]==-1){
    cout<<"10|para G"<<endl;
    }
   int n ;
    cout<<"opcion:";cin>>n;
   return n;
}
int numeroRepetido(int n,int vDados[],int tam){
    int nVeces=contarNumerosRepetidos(vDados,n,tam);
    int resultado=(n*nVeces);
    return resultado;
}
void sumaPuntaje(int vdados[],int jE,int vPuntaje[]){
    int puntaje,repetidos,tam=5;
    int i=jE-1;
    switch(i){
    case -1:
    break;
    case 0:{
    int resultado = numeroRepetido(1,vdados,tam);
    vPuntaje[0]=resultado;
    break;
    }
    case 1:{
    int resultado = numeroRepetido(2,vdados,tam);
    vPuntaje[1]=resultado;
    break;
    }
    case 2:{
    int resultado = numeroRepetido(3,vdados,tam);
    vPuntaje[2]=resultado;
    break;
    }
    case 3:{
    int resultado = numeroRepetido(4,vdados,tam);
    vPuntaje[3]=resultado;
    break;
    }
    case 4:{
    int resultado = numeroRepetido(5,vdados,tam);
    vPuntaje[4]=resultado;
    break;
    }
    case 5:{
   int resultado = numeroRepetido(6,vdados,tam);
    vPuntaje[5]=resultado;
    break;
    }
    case 6:{
    int escalera = verificaEscalera(vdados,tam);
    if(escalera==1){
      vPuntaje[6]=20;
      }else{
            vPuntaje[6]=0;
      }
    break;
    }
    case 7:{
    int full = verificaFull(vdados,tam);
        if(full==1){
            vPuntaje[7]=30;
        }else{
             vPuntaje[7]=0;
    }
    break;
    }
    case 8:{
     int poker = verificaPoker(vdados,tam);
        if(poker==1){
           vPuntaje[8]=40;

        }else{
            vPuntaje[8]=0;
    }
    break;
    }
    case 9:{int generala = verificaGenerala(vdados);
        if(generala==1){
          vPuntaje[9]=50;
        }else{
            vPuntaje[9]=0;
       }
     break;
     }
    default :cout<<"opcion incorrecta"<<endl;

    }}
int verificaJugada(int v[],int tirada,int vPuntaje[]){
   imprimeVector(v,5);
   int jugadaElegida = eligeJugada(tirada,vPuntaje);
   sumaPuntaje(v,jugadaElegida,vPuntaje);
   return jugadaElegida;
}
void cargaDados(int v[],int tam,int arranca){
     int i;
  srand(time(NULL));
  for( i=arranca; i<tam; i++ ){
        v[i]=(rand()%6)+1;
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
void ingresaDadosQueQuedan(int v[]){
  for(int i=0;i<5;i++){
    cout<<"dado "<<i+1<<":";cin>>v[i];
  }
}
bool tiraDados(int vuelta,int vtirada[],int dadosNuevos,int arranca,int vPuntaje[]){
    cout<<"Dados:"<<endl;
    cargaDados(vtirada,dadosNuevos,arranca);
    int jugada= verificaJugada(vtirada,vuelta,vPuntaje);
    if(jugada!=0){
    return false;
    }else return true;

}
int jugador1(){
    int vPuntaje[10];
    int puntaje=0;
    niegaTodoVector(vPuntaje,10);
    for(int i=1;i<12;i++){
        cout<<"ronda "<<i<<endl;
        int nPuntaje=0;
        for(int a=0;a<10;a++){
           if((vPuntaje[a])!=-1){
            nPuntaje=nPuntaje+vPuntaje[a];
           }}
        cout<<"puntaje:"<<nPuntaje<<endl;
        if(i==11){
        puntaje=nPuntaje;
        }
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
        if(vuelta==1){
             seguir=tiraDados(vuelta,tirada1,5,0,vPuntaje);
        }else{
            cout<<"ingrese 1 para guardar el dado y 0 para cambiarlo"<<endl;
             int vDadosQuedan[5];
            ingresaDadosQueQuedan(vDadosQuedan);
            system("cls");
            if(vuelta==2){
            int dadosGuardados=guardaDados(vDadosQuedan,tirada1,tirada2);
            seguir=tiraDados(vuelta,tirada2,5,dadosGuardados,vPuntaje);
            }
            if(vuelta==3){
            int dadosGuardados=guardaDados(vDadosQuedan,tirada2,tirada3);
            seguir=tiraDados(vuelta,tirada3,5,dadosGuardados,vPuntaje);
            }
        }
        if(vuelta==3){
        seguir=false;
          }
    } }

    system("cls");
    }
    return puntaje;
}
void pantalla1(){
    int x;
    cout<<"1| 1 jugador"<<endl;
    cout<<"2| 2 jugadores"<<endl;
    cout<<"ingrese:";cin>>x;
    system("cls");

    if(x==1){
        int puntaje1= jugador1();
        cout<<"jugador 1:"<<puntaje1<<" puntos"<<endl;
        system("pause");

    }
    if(x==2){
       // jugador2();
    cout<<"jugador2"<<endl;
    }
}

#endif // FUNCIONES_H_INCLUDED
