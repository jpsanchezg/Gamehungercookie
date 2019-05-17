#include <iostream>
#include <iomanip>
#include "time.h"
#include "stdlib.h"
#include <iomanip>
//juan pablo sanchez gaitan
using namespace std;
struct personaje{
char movs;
    char galleta;
};

#define maxc 30
#define maxf 30
void tablerocreado (struct personaje,int numeros[maxf][maxf], int nfilas, int ncol);
void tableroaleatorio (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol,int jugf,int jugc);
void vistamundo ( char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);
void sensacion (  char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);
void disparar (  char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);
void imprimirjugador (char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol);
void alien ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol);
void gameover  ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol);

int main ()
{
    int numeros[maxf][maxf], nfilas =0, ncol=0, opcion=0, respu=0;
    int jugf=0, jugc=0;
    srand(time(NULL));
    char player [maxf][maxc];

    do
    {
        cout<<"Bienvenido a EN BUSCA DE LA GALLETA PERDIDA"<<endl;
        cout<<"menu de opciones"<<endl;
        cout<<"0. JUGAR CON MAPA CREADO"<<endl;
        cout<<"1. JUGAR MODO ALEATORIO"<<endl;
        cout<<"2. INSTRUCCIONES"<<endl;
        cout<<"3. OPCIONES"<<endl;
        cout<<"4. SALIR"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 0:
            cout<<"ingrese el numero de filas que desea para el mapa, recuerde que el numero maximo de filas es de "<<maxf<<endl;
            cin>>nfilas;
            cout<<"ingrese el numero de columnas que desea para el mapa, recuerde que el numero maximo de columnas es de "<<maxc<<endl;
            cin>>ncol;
            for(int i = 0; i<nfilas; i++)
            {
                for(int j = 0; j<ncol; j++)
                {
                    numeros[i][j]= 0;
                }
            }
            for(int i = 0; i<nfilas; i++)
            {
                for(int j = 0; j<ncol; j++)
                {
                    player[i][j]= '-';
                }
            }

            tablerocreado (player, numeros,nfilas,ncol);
            jugador (player,numeros,nfilas,ncol,jugf,jugc);


            break;
        case 1:
            nfilas = 0 + rand ()% (maxf);
            ncol=0 + rand ()% (maxc);
            for(int i = 0; i<nfilas; i++)
            {
                for(int j = 0; j<ncol; j++)
                {
                    numeros[i][j]= 0;
                }
            }
            for(int i = 0; i<nfilas; i++)
            {
                for(int j = 0; j<ncol; j++)
                {
                    player[i][j]= '-';
                }
            }
            tableroaleatorio(player, numeros,nfilas,ncol);
            jugador (player,numeros,nfilas,ncol,jugf,jugc);
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
    int abis=0,alienf=0,alienc=0,multi=0,ret=0,filas=0,col=0;
    int jugf=0, jugc=0;
    player[jugf][jugc]='L';
    numeros[jugf][jugc]= 5;
    int galletf=0,galletc=0;
    bool poss=false;
    multi = nfilas* ncol;
    ret = multi/2;
    cout<<"tienes  "<<multi<<" posiciones en el mapa para poner los abismos, el monstruo y la galleta"<<endl;
    cout<<"en que fila quiere poner el alien "<<endl;
    cin>>alienf;
    cout<<"en que columna va a ingresar el alien"<<endl;
    cin>>alienc;
    numeros[alienf][alienc]=1;
    cout<<"En que filas vas a poner la galleta?"<<endl;
    cin>>galletf;
    cout<<"en que columna vas a poner la galleta?"<<endl;
    cin>>galletc;
    numeros[galletf][galletc]=3;

    cout<<"cuantos abismos va a poner recuerde que debe ser menos a "<<ret<<endl;
    cin>>abis;
    int k=0,abisf=0,abisc=0;
    do
    {
        k++;
        cout<<"Ingrese la fila del "<<k<<" abismo"<<endl;
        cin>>abisf;
        cout<<"ingrese la columna del "<<k<<" abismo"<<endl;
        cin>>abisc;

        while(poss== false)
        {

            if (alienf == abisf && alienc == abisc)
            {
                cout<<"Valor ingresado incorrecto, es el mismo que el del alienigena"<<endl;
                poss= false;
            }

            if (alienf != abisf && alienc != abisc)
            {

                poss= true;
                numeros[abisf][abisc]=2;

            }
        }
    }
    while(k<abis);

    system("cls");
    vistamundo (player,numeros,nfilas,ncol);
    jugador (player,numeros,nfilas,ncol,jugf,jugc);

}
void tableroaleatorio (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{
    int abis=0 + rand ()% (nfilas),alienf=0 + rand ()% (nfilas),alienc=0 + rand ()% (ncol);
    int multi=0,ret=0,filas=0,col=0;
    int jugf=0, jugc=0;
    int perf=0,perc=0;
    player[jugf][jugc]='L';
    int galletf=0 + rand ()% (nfilas),galletc=0 + rand ()% (ncol);
    bool poss=false;
    multi = nfilas* ncol;
    ret = multi/2;

    numeros[galletf][galletc]=3;

    while(poss== false)
    {
        if (alienf == galletf && alienc == galletc)
        {
            poss= false;
        }

        if (alienf != galletf && alienc != galletc)
        {
            poss= true;
            numeros[alienf][alienc]=1;
        }
    }
    perf= jugf +1;
    perc = jugc +1;
    for(int i=0; i<abis; i++)
    {
        filas = 0 + rand ()% (nfilas);
        col = 0 + rand ()% (ncol);
        if (filas != perf && col != perc)
        {
            if (filas != alienf && col != alienc)
            {
                numeros[filas][col]=2;
            }
        }
    }
    system("cls");
    vistamundo (player,numeros,nfilas,ncol);


}
void vistamundo (char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol)
{
    for(int i=0; i<nfilas; i++)

    {
        for (int j=0; j<ncol; j++)
        {
            cout<<setw(8)<<player[i][j];
        }
        cout<<endl;
    }
}
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol, int jugf,int jugc)
{
    char opcion;
    int pojf=0,pojc=0;
    bool muerto = false;
    cout<<"Ingrese un movimiento o accion"<<endl;
    cout<<"GIRAR A LA DERECHA = D"<<endl;
    cout<<"GIRAR IZQUIERDA = I"<<endl;
    cout<<"AVANZAR = A"<<endl;
    cout<<"DISPARAR = F"<<endl;
    cout<<"RECOGER GALLETA = R"<<endl;
    cin>>opcion;

    switch (opcion)
    {
    case 'a':
    case 'A':
        sensacion (   player, numeros,nfilas, ncol);
        if(opcion == 'd'))
        {
            switch(numeros[pojf][pojc])
            {
            case 1:

                alien(player,numeros,nfilas,ncol,jugf,jugc);

                break;
            case 2:
                gameover (player,numeros,nfilas,ncol,jugf,jugc);
                break;
            case 3:
                galleta (player,numeros,nfilas,ncol,jugf,jugc);
                break;
            default:
                player[jugf][jugc]= 'a';
                numeros[jugf][jugc]= 5;
                break;
            }
        }
        if(opcion == 'i')
    {

        switch(numeros[pojf][pojc])
            {
            case 1:

                alien(player,numeros,nfilas,ncol,jugf,jugc);

                break;
            case 2:
                gameover (player,numeros,nfilas,ncol,jugf,jugc);
                break;
            case 3:
                galleta (player,numeros,nfilas,ncol,jugf,jugc);
                break;
            default:
                player[jugf][jugc]= 'a';
                numeros[jugf][jugc]= 5;
                break;
            }
        }
        break;
    case 'D':
    case 'd':



            case 'p':

                    for(int i=0; i<nfilas; i++)
    {
        for (int j=0; j<ncol; j++)
            {
                cout<<setw(8)<<numeros[i][j];
            }
            cout<<endl;
        }
        break;
    }


}
void sensacion (  char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol)
{




}

