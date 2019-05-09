#include <iostream>
#include <iomanip>
#include "time.h"
#include "stdlib.h"
#include <iomanip>

using namesapec std;

#define maxc 30
#define maxf 30
void tablerocreado (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);
void tableroaleatorio (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol);
void vistamundo ( char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);
void sensacion (  char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);
void disparar (  char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);

int main ()
{
    int numeros[maxf][maxf], nfilas =0, ncol=0, opcion=0, respu=0;
    srand(time(NULL));
    char player [maxf][maxc];
    string nombre;
    do
    {
        cout<<"Bienvenido a EN BUSCA DE LA GALLETA PERDIDA"<<endl;
        cout<<"menu de opciones"<<endl;
        cout<<"1. JUGAR"<<endl;
        cout<<"2. INSTRUCCIONES"<<endl;
        cout<<"3. OPCIONES"<<endl;
        cout<<"4. SALIR"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            cout<<"Ingrese su nombre"<<endl;
            cin>>nombre;
            cout<<"opciones de crar mapa"<<endl;
            cout<<"1. creacion propia del mapa"<<endl;
            cout<<"2. la maquina crea el mapa de juego"<<endl;
            cin>>respu;
            if (respu == 1)
            {
                cout<<"ingrese el numero de filas que desea para el mapa, recuerde que el numero maximo de filas es de "<<maxf<<endl;
                cin>>nfilas;
                cout<<"ingrese el numero de columnas que desea para el mapa, recuerde que el numero maximo de columnas es de "<<maxc<<endl;
                cin>>ncol;
                for(int i = 0; i<nfilas; i++)
                {
                    for(int j = 0; j<ncol; j++)
                    {
                        numeros[i][j]='0';
                        
                    }
                }
                   for(int i=0; i<nfilas; i++)
    {
        for (int j=0; j<ncol; j++)
        {
            cout<<setw(8)<<numeros [i][j];
        }
        cout<<endl;
    }
                tablerocreado (player, numeros,nfilas,ncol);
                jugador (player,numeros,nfilas,ncol);
            }
            if (respu == 2)
            {
                nfilas = 0 + rand ()% 30;
                ncol = 0 + rand ()% 30;
                for(int i = 0; i<nfilas; i++)
                {
                    for(int j = 0; j<ncol; j++)
                    {
                        numeros[i][j]=0;
                    }
                }
                tableroaleatorio (numeros,nfilas,ncol);
                jugador (player,numeros,nfilas,ncol);

            }
break;
            case 2:
                cout<<"Las instrucciones del juego son las siguientes:"<<endl;
                cout<<" El jugador debe encontrar la galleta por un mapa que el jugador puede crear o elejir la creacion alatoria"<<endl;
                cout<<" Los abismos, el alien y la galleta tienen su olor y sonido respectivo."<<endl;
                cout<<"El abismo persibe una brisa la cual le va a indicar a el jugador que esta cerca a un abismo"<<endl;
break;
        }

    }
    while (opcion != 4);
}
void tablerocreado (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{
    int abis=0,alienf=0,alienc=0,multi=0,ret=0;
    int jugf=0, jugc=0;
    int galletf=0,galletc=0;
    bool poss=false;
    multi = nfilas* ncol;
    ret = multi/2;
    cout<<"tienes  "<<multi<<" posiciones en el mapa para poner los abismos, el monstruo y la galleta"<<endl;
    cout<<"En que filas vas a poner la galleta?"<<endl;
    cin>>galletf;
    cout<<"en que columna vas a poner la galleta?"<<endl;
    cin>>galletc;
    while(poss== false){
       cout<<"en que fila quiere poner el alien "<<endl; 
    cin>>alienf;
        cout<<"en que columna va a ingresar el alien"<<endl;
    cin>>alienc;
    if (alienf == galletf && alienc == galletc){
        cout<<"Valor ingresado incorrecto, es el mismo que el de la galleta"<<endl;
        poss= false;}
        
    if (alienf != galletf && alienc != galletc){
        poss= true;}
    }
    
    cout<<"cuantos abismos va a poner recuerde que debe ser menos a "<<ret<<endl;
    cin>>abis;
        player[jugf][jugc]='L';
    numeros[galletf][galletc]=3;
    numeros[alienf][alienc]=1;
    for(int i=0;i<abis;i++){
        nfilas = 0 + rand ()% (nfilas);
        ncol = 0 + rand ()% (ncol);    
        numeros[nfilas][ncol]=2;
}
void tableroaleatorio (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{
   todavia no hay nbada jajajaj
    
}
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol)
{
char opcion;
    do{
    cout<<"Ingrese un movimiento o accion"<<endl;
    cout<<"ARRIBA = A"<<endl;
    cout<<"ABAJO = B"<<endl;
    cout<<"IZQUIERDA = I"<<endl;
    cout<<"DERECHA = D"<<endl;
    cout<<"DISPARAR = F"<<endl;
    cout<<"RECOGER GALLETA = R"<<endl;
        cin>>opcion;
        switch (opcion){
            case a:
            case A:
                
                
    
    
}
void (  char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol)
{




}
