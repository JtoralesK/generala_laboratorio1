#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void niegaTodoVector(int v[],int tam){
 for(int x=0;x<tam;x++){
        v[x]=-1;
        }
}
void poneTodoUnvEn0(int v[],int tam){
 for(int x=0;x<tam;x++){
        v[x]=0;
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
    for(int i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
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
void anotarPuntos(int dados[],int puntaje[],int j){
    int tam2=6;
    int rep[6];
    poneTodoUnvEn0(rep,6);
    contarRepetidos(dados,5,rep);

bool escalera , full , poker , generala;
int n=j-1;
switch(j){
case 1:puntaje[n]=rep[n]*1;break;
case 2:puntaje[n]=rep[n]*2;break;
case 3:puntaje[n]=rep[n]*3;break;
case 4:puntaje[n]=rep[n]*4;break;
case 5:puntaje[n]=rep[n]*5;break;
case 6:puntaje[n]=rep[n]*6;break;

case 7:escalera=detectarEscalera(rep,tam2);
if(escalera==true){
    puntaje[n]=25;
}
else{puntaje[n]=0;}
break;
case 8:full=detectarFull(rep,tam2);
if(full==true){
puntaje[n]=30;
}
else{puntaje[n]=0;}
break;

case 9:poker=detectarPoker(rep,tam2);
if (poker==true){
   puntaje[n]=40;
}
else{puntaje[n]=0;}
break;

case 10:generala=detectarGenerala(rep,tam2);
if(generala==true){
    puntaje[n]=50;
}
else{puntaje[n]=0;}
break;
}
}
int eligeJugada(int tirada,int puntaje[]){
    if(tirada!=3)cout<<"0|para volver a tirar"<<endl;
    for(int i=0;i<6;i++){
        if(puntaje[i]==-1) cout<<i+1<<"|para "<<i+1<<endl;
        }
    if(puntaje[6]==-1)cout<<"7|para E"<<endl;
    if(puntaje[7]==-1)cout<<"8|para F"<<endl;
    if(puntaje[8]==-1)cout<<"9|para P"<<endl;
    if(puntaje[9]==-1)cout<<"10|para G"<<endl;
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
int x;
cout<<"ingrese 1 para quedarte con el dado y 0 para cambiarlo"<<endl;
for(int i=0;i<5;i++){
    cout<<"Dado "<<i+1<<":";cin>>x; x==1 ? v[i]=true : v[i]=false;
}
 system("cls");
}
void partida(){
    const int tam2=10;
    int vPuntaje[tam2];
        niegaTodoVector(vPuntaje,tam2);
    const int tam=5;
    for(int i=1;i<=10;i++){
        cout<<"ronda "<<i<<endl;
         int puntaje=0;
         for(int i=0;i<10;i++){
            if(vPuntaje[i]!=-1)puntaje=puntaje+vPuntaje[i];
        }
        cout<<"puntaje:"<<puntaje<<endl;
        bool seguir=true;
        int dados[tam];
        bool vFalsos[tam]={false,false,false,false,false};
        int vuelta=0,t,tirada;
        cout<<"ingrese 1 para comenzar:";cin>>t;
        while(seguir==true){
              if(vuelta==0){
              cargaDados(dados,vFalsos,tam);
              }else{
               tirada = eligeJugada(vuelta,vPuntaje);
              if(tirada==0){
                 imprimeVector(dados,5);
                elegirDados(vFalsos,5);
                cargaDados(dados,vFalsos,tam);
              }else seguir=false;
              }
              imprimeVector(dados,5);
              if(vuelta==3)seguir=false;
            vuelta++;
        }
        anotarPuntos(dados,vPuntaje,tirada);
        system("cls");
    }
}
#endif // FUNCIONES_H_INCLUDED
