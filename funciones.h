#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
void niegaMatriz(int v[][2],int tam){
 for(int x=0;x<tam;x++){
        v[x][0]=-1;
        }
    for(int x=0;x<tam;x++){
    v[x][1]=-1;
    }
}
void poneTodoUnvEn0(int v[],int tam){
 for(int x=0;x<tam;x++){
        v[x]=0;
        }
}
void imprimeVector(int v[],int tam){
for(int i=0;i<tam;i++){
    cout<<v[i]<<endl;
}
}
int sumaPuntaje(int vPuntaje[][2],int tam,int ju){
    int puntaje=0;
    for(int i=0;i<10;i++){
        if(vPuntaje[i][ju]!=-1)puntaje=puntaje+vPuntaje[i][ju];
    }
    return puntaje;
}
void contarRepetidos (int v1[] , int tam , int v2[] ){
int c1=0 , c2=0 , c3=0 , c4=0 , c5=0 , c6=0 , i;
for (i=0;i<tam;i++){
    switch (v1[i]){
    case 1:c1++; v2[0]=c1;break;
    case 2:c2++; v2[1]=c2;break;
    case 3:c3++; v2[2]=c3;break;
    case 4:c4++; v2[3]=c4;break;
    case 5:c5++; v2[4]=c5;break;
    case 6:c6++; v2[5]=c6;break;
    }
}
}
bool detectarEscalera(int v[], int tam){
int i,c=0;
bool esc=false;
for(i=0;i<tam;i++){
    if(v[i]==1){c++;}
    if(c==5){esc=true;}
    if(v[0]==1&&v[5]==1){esc=false;}
}
return esc;}
bool detectarFull(int v[], int tam){
int i;
bool full=false , dosDigitos=false , tresDigitos=false;
for (i=0;i<tam;i++){
    switch (v[i]){
    case 2: dosDigitos=true;break;
    case 3: tresDigitos=true;break;
    }
    if(dosDigitos==true && tresDigitos==true){
        full=true;
    }
}
return full;
}
bool detectarPoker(int v[], int tam){
int i;
bool poker=false;
for (i=0;i<tam;i++){
        if(v[i]>=4){poker=true;}
}
return poker;
}

bool detectarGenerala(int v[], int tam){
int i;
bool generala=false;
for (i=0;i<tam;i++){
        if(v[i]==5){generala=true;}
}
return generala;
}
void anotarPuntos(int dados[],int puntaje[][2],int j,int ju){
    int tam2=6;
    int rep[6];
    poneTodoUnvEn0(rep,6);
    contarRepetidos(dados,5,rep);
bool escalera , full , poker , generala;
int n=j-1;
switch(j){
case 1:puntaje[n][ju]=rep[n]*1;break;
case 2:puntaje[n][ju]=rep[n]*2;break;
case 3:puntaje[n][ju]=rep[n]*3;break;
case 4:puntaje[n][ju]=rep[n]*4;break;
case 5:puntaje[n][ju]=rep[n]*5;break;
case 6:puntaje[n][ju]=rep[n]*6;break;
case 7:escalera=detectarEscalera(rep,tam2);
if(escalera==true){
    puntaje[n][ju]=25;
}
else{puntaje[n][ju]=0;}
break;
case 8:full=detectarFull(rep,tam2);
if(full==true){
puntaje[n][ju]=30;
}
else{puntaje[n][ju]=0;}
break;

case 9:poker=detectarPoker(rep,tam2);
if (poker==true){
   puntaje[n][ju]=40;
}
else{puntaje[n][ju]=0;}
break;

case 10:generala=detectarGenerala(rep,tam2);
if(generala==true){
    puntaje[n][ju]=50;
}
else{puntaje[n][ju]=0;}
break;
}
}
int eligeJugada(int tirada,int puntaje[][2],int ju){
    if(tirada!=3)cout<<"0|para volver a tirar"<<endl;
    for(int i=0;i<6;i++){
        if(puntaje[i][ju]==-1) cout<<i+1<<"|para "<<i+1<<endl;
        }
    if(puntaje[6][ju]==-1)cout<<"7|para Escalera"<<endl;
    if(puntaje[7][ju]==-1)cout<<"8|para Full"<<endl;
    if(puntaje[8][ju]==-1)cout<<"9|para Poker"<<endl;
    if(puntaje[9][ju]==-1)cout<<"10|para Generala"<<endl;
    int n ;
    cout<<"opcion:";cin>>n;
     system("cls");
   return n;
}
void cargaDados(int v[],bool v2[],int tam){
     int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        if(v2[i]==false){
            v[i]=(rand()%6)+1;}
            }
}
void elegirDados(bool v[] , int tam){
int n,contador=0;
cout<<"ingrese el numero de dado que desee conservar, para finalizar, presione el numero cero(0): "<<endl;cin>>n;
while (n!=0 && contador<5){
    switch (n){
    case 1: v[n-1]=true; break;
    case 2: v[n-1]=true; break;
    case 3: v[n-1]=true; break;
    case 4: v[n-1]=true; break;
    case 5: v[n-1]=true; break;
    default: cout<<"el numero ingresado no es correcto"<<endl;
    }
    cout<<"--------"<<endl;
    cin>>n;
    contador++;
}
 system("cls");
}
void partida(int cantJugaodores,int vPuntaje[][2],int ronda,char jug[2][10]){
    const int tam=5;
    int jugador=1;
    for(int i=1;i<=ronda;i++){
         for(int z=1;z<=cantJugaodores;z++){
          int puntaje=0;
         if(cantJugaodores==2){
             jugador=!jugador;
         }else jugador=0;
        puntaje = sumaPuntaje(vPuntaje,10,jugador);
        cout<<"ronda "<<i<<endl;
        cout<<"Jugador:"<<jug[jugador]<<endl;
        cout<<"puntaje:"<<puntaje<<endl;
        bool seguir=true;
        int dados[tam];
        bool vFalsos[tam]={false,false,false,false,false};
        int vuelta=0,tirada;
        while(seguir==true){
              if(vuelta==0)cargaDados(dados,vFalsos,tam);
              else{
               tirada = eligeJugada(vuelta,vPuntaje,jugador);
              if(tirada==0){
                 imprimeVector(dados,tam);
                elegirDados(vFalsos,tam);
                cargaDados(dados,vFalsos,tam);
              }else seguir=false;
              }
              imprimeVector(dados,tam);
              if(vuelta==3)seguir=false;
            vuelta++;
        }
        anotarPuntos(dados,vPuntaje,tirada,jugador);
        system("cls");
        }
    }
}
void imprimePuntaje(int players,int puntaje[][2],char jugUno[2][10]){
    int r[2];
    r[0]=0,r[1]=0;
    for (int x=0;x<2;x++){
        for(int i=0;i<10;i++){
            if(puntaje[i][x]!=-1)r[x]=r[x]+puntaje[i][x];
    }}
    switch(players){
    case 1:
        cout<<jugUno[0]<<":"<<r[0]<<endl;
    break;
    case 2:
         cout<<jugUno[0]<<":"<<r[0]<<endl;
        cout<<jugUno[1]<<":"<<r[1]<<endl;
    break;
    }
}
void iniciaPartida(char nombres[2][10]){
int r;
cout<<"ingrese el numero de rondas a jugar:";cin>>r;
int n,j=0;
int vPuntaje[10][2];
niegaMatriz(vPuntaje,10);
cout<<"1| 1 Jugador"<<endl;
cout<<"2| 2 Jugadores"<<endl;
cout<<"opcion:";cin>>n;
system("cls");
  int i;
  for(i=0;i<n;i++){
    cout<<"Nombre del jugador "<<i+1<<":";cin>>nombres[i];
    }
system("cls");
partida(n,vPuntaje,r,nombres);
imprimePuntaje(n,vPuntaje,nombres);
system("pause");
}
#endif // FUNCIONES_H_INCLUDED
