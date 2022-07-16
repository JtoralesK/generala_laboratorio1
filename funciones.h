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
void muestraDados(int v[],int tam){
cout<<"--------"<<endl;
for(int i=0;i<tam;i++){
    cout<<"dado "<<i+1<<":"<<v[i]<<endl;
}
cout<<"--------"<<endl;
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
void eligeJugada(int puntaje[][2],int ju){
    for(int i=0;i<6;i++){
        if(puntaje[i][ju]==-1) cout<<i+1<<"|para "<<i+1<<endl;
        }
    if(puntaje[6][ju]==-1)cout<<"7|para Escalera"<<endl;
    if(puntaje[7][ju]==-1)cout<<"8|para Full"<<endl;
    if(puntaje[8][ju]==-1)cout<<"9|para Poker"<<endl;
    if(puntaje[9][ju]==-1)cout<<"10|para Generala"<<endl;
}
void anotarPuntos(int dados[],int puntaje[][2],int ju){
    int tam2=6,j;
    int rep[6];
    poneTodoUnvEn0(rep,6);
    contarRepetidos(dados,5,rep);
bool escalera , full , poker , generala;
eligeJugada(puntaje,ju);
cout<<"ingrese jugada:";cin>>j;
while(puntaje[j-1][ju]!=-1){
cout<<"puntaje invalido"<<endl;
cout<<"ingrese jugada:";cin>>j;
}
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
void cargaDados(int v[],bool v2[],int tam){
     int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        if(v2[i]==false){
            v[i]=(rand()%6)+1;}
            }
}
void elegirDados( bool v1[], int tam,int v2[],int tirT[2],int jugador,int& cServida ){
int n , j , cont=0;
char sn='s';
tirT[jugador]=tirT[jugador]+1;
while (sn=='s'&&cont!=2){
        muestraDados(v2,tam);
        cout<<"desea volver a tirar?(s/n): ";cin>>sn;
        while(sn!='s'&&sn!='n'){
            cout<<"caracter invalido"<<endl;
            cout<<"desea volver a tirar?(s/n): ";cin>>sn;
        }
        cout<<"--------"<<endl;
if(sn=='s'){
    cServida++;
    tirT[jugador]=tirT[jugador]+1;
    cont++;
    cout<<"cuantos dados desea guardar?: ";
    cin>>j;
    cout<<"--------"<<endl;
    cout<<"que numero de dado desea guardar?: "<<endl<<"--------"<<endl;
for (int i=1;i<=j;i++){
        cin>>n;
    switch (n){
    case 1: v1[n-1]=true; break;
    case 2: v1[n-1]=true; break;
    case 3: v1[n-1]=true; break;
    case 4: v1[n-1]=true; break;
    case 5: v1[n-1]=true; break;
    default: cout<<"el numero ingresado no es correcto"<<endl;
    }
    cout<<"--------"<<endl;
}
 system("cls");
  cargaDados(v2,v1,tam);
}
}
 system("cls");
}
void resumenRonda(int r,int tiradasTotales[2],int players,char jugadores[2][10],int puntaje[][2],int ronda){
    if(r!=ronda){
    cout<<"Ronda "<<r<<endl;
    cout<<"Proximo turno:"<<jugadores[0]<<endl;
    cout<<"Lanzamientos:"<<tiradasTotales[0]+tiradasTotales[1]<<endl;
            int puntaje1 = sumaPuntaje(puntaje,10,0);
            int puntaje2 = sumaPuntaje(puntaje,10,1);
    switch(players){
    case 1:
        cout<<jugadores[0]<<":"<<puntaje1<<endl;
    break;
    case 2:
         cout<<jugadores[0]<<":"<<puntaje1<<endl;
         cout<<jugadores[1]<<":"<<puntaje2<<endl;
    break;
    }
    }
    else{cout<<"FIN DEL JUEGO!"<<endl;}
    system("pause");
    system("cls");
}
void muestraGanador(char jugador[][10],int v[2],int tiradas[],int gan){
    cout<<"el ganador es: "<<jugador[gan]<<"!!"<<endl;
    cout<<"puntaje final: "<<v[gan]<<endl;
    cout<<"tiradas totales del jugador: "<<tiradas[gan]<<endl;
}

int compararPuntajes(int mat[][2],char jugador[][10],int tiradas[],int cant, bool servidas[2],int& ganador,int& maxTiradas){
    system("cls");
int i,j, v[2],mayor;
poneTodoUnvEn0(v,2);
bool geServida=false;
for(i=0;i<2;i++){
    v[i]=sumaPuntaje(mat,10,i);
    if(servidas[i]==true){
    muestraGanador(jugador,v,tiradas,i);
    geServida=true;
     mayor=v[i];
     ganador=i;
     maxTiradas=tiradas[i];
    }
}
    if(geServida==false){
        if (v[0]>v[1]){
                   muestraGanador(jugador,v,tiradas,0);
                   mayor=v[0];
                   ganador=0;
                   maxTiradas=tiradas[0];
        }else{
        if(v[0]!=v[1]){
                   muestraGanador(jugador,v,tiradas,1);
                   mayor=v[1];
                   ganador=1;
                   maxTiradas=tiradas[1];
                   }
                        else{cout<<"TENEMOS UN EMPATE!"<<endl;
                             cout<<"puntaje final de ambos jugadores: "<<v[0]<<endl;
                             cout<<"tiradas totales: "<<tiradas[0]+tiradas[1]<<endl;
                             mayor=v[0];}
        }
    }

system("pause");
system("cls");
return mayor;
}

int partida(int cantJugad,int vPuntaje[][2],int ronda,char jug[2][10],int& ganador,int& maxTiradas){
    const int tam=5;
    int jugador,maximo,cServida,contServ[6],auxServida,numRonda=0,tiradasTotales[2];
    poneTodoUnvEn0(tiradasTotales,2);
    bool servidas[2];
    for(int i=1;i<=ronda;i++){
        auxServida=i;
        numRonda++;
        servidas[0]=false;
        servidas[1]=false;
        for(int z=0;z<cantJugad;z++){
        int puntaje=0;
        cServida=1;
        poneTodoUnvEn0(contServ,6);
        jugador=z;
        puntaje = sumaPuntaje(vPuntaje,10,jugador);
        cout<<"Turno De "<<jug[jugador]<<"| Ronda "<<numRonda<<"| Puntaje Total:"<<puntaje<<" puntos"<<endl;
        cout<<"Tiradas Totales:"<<tiradasTotales[jugador]<<endl;

        int dados[tam];
        bool vFalsos[tam]={false,false,false,false,false};

            cargaDados(dados,vFalsos,tam);
            elegirDados(vFalsos,tam,dados,tiradasTotales,jugador,cServida);
            muestraDados(dados,tam);
            switch(z+1){
                case 1: contarRepetidos(dados,tam,contServ);
                        if(cServida==1){servidas[0]=detectarGenerala(contServ,6);}
                        if(servidas[0]==true){
                            i=ronda+1;
                            cout<<"GENERALA SERVIDA!"<<endl;}
                        break;

                case 2: contarRepetidos(dados,tam,contServ);
                        if(cServida==1){servidas[1]=detectarGenerala(contServ,6);}
                        if(servidas[1]==true){
                            i=ronda+1;
                            cout<<"GENERALA SERVIDA!"<<endl;}
                        break;
            }
            cout<<"servida 1: "<<servidas[0]<<endl<<"servida 2: "<<servidas[1]<<endl;
        if(servidas[0]==true&&servidas[1]==true){i=auxServida;}
        anotarPuntos(dados,vPuntaje,jugador);
        system("cls");
        }
        if(i<ronda){resumenRonda(i,tiradasTotales,cantJugad,jug,vPuntaje,ronda);}
        }
        maximo=compararPuntajes(vPuntaje,jug,tiradasTotales,cantJugad,servidas,ganador,maxTiradas);
        return maximo;
}

int iniciaPartida(char nombres[2][10],int jugador,int& ganador,int& maxTiradas){
int r,maximo;
cout<<"ingrese el numero de rondas a jugar:";cin>>r;
  while(r>10||r<1){
   system("cls");
        cout<<"El numero de rondas debe estar entre 1 y 10"<<endl;
        cout<<"ingrese el numero de rondas a jugar:";cin>>r;
}
int vPuntaje[10][2];
niegaMatriz(vPuntaje,10);
system("cls");
    for(int i=0;i<jugador;i++){
    cout<<"Nombre del jugador "<<i+1<<":";cin>>nombres[i];
    }
system("cls");
maximo=partida(jugador,vPuntaje,r,nombres,ganador,maxTiradas);
return maximo;
}
#endif // FUNCIONES_H_INCLUDED
