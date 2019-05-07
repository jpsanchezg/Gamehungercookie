#include <iostream>
#include <iomanip>
#include "time.h"
#include "stdlib.h"
#include <iomanip>

using namespace std;

#define maxc 30
#define maxf 30
void tablerocreado (int numeros[maxf][maxf], int nfilas, int ncol);
void tableroaleatorio (int numeros[maxf][maxf], int nfilas, int ncol);
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
                        numeros[i][j]=0;
                    }
                }
                tablerocreado (numeros,nfilas,ncol);
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
void tablerocreado (int numeros[maxf][maxf], int nfilas, int ncol)
{
    int abis=0,alien=0,multi=0;
    multi = nfilas* ncol;
    cout<<"cuantos abismos desea poner?"<<" reduerde que tiene "<<multi<<" posiciones en el mapa"<<endl;
    cin>>abis;
       cout<<"En que posicion va a poner el alien? recuerde que la posicion ustde no la sabe lo unico que va a poner es el numero 2"<<endl;
    cin>>alien;
    for(int i=0+rand()%nfilas; i<nfilas; i++)
    {
        for (int j=0+rand()%ncol; j<ncol; j++)
        {

                numeros [0][0]=0;


                numeros [i][j]=alien;


            if  (numeros [i][j] == 0)
            {
                if( numeros [i][j+1] == 0)
                {
                    if(numeros[i][j-1] == 0)
                    {
                        if (numeros [i+1][j] == 0)
                        {
                            if(numeros [i-1][j] == 0)
                            {
                                numeros[i][j]=3;

                            }
                        }
                    }
                }
            }
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
}
void tableroaleatorio (int numeros[maxf][maxf], int nfilas, int ncol)
{
     for(int i=0; i<nfilas; i++)
    {
        for (int j=1; j<ncol; j++)
        {

                numeros [0][0]=0;


                numeros [i][0+rand()%(ncol)]=1;


            if  (numeros [i][j] == 0)
            {
                if( numeros [i][j+1] == 0)
                {
                    if(numeros[i][j-1] == 0)
                    {
                        if (numeros [i+1][j] == 0)
                        {
                            if(numeros [i-1][j] == 0)
                            {
                                numeros[i][j]=3;

                            }
                        }
                    }
                }
            }
        }
    }
    
}
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol)
{
for(int i =0;i<nfilas;i++)
{
    for(int j=0;j<ncol;j++)
    {
        cin>>player[i][j]
        
        if (player [i][j]=='d')
        {
            player [i][j+1];
        }
        if(player[i][j]=='i'){
            playr[i][j-1];
        }
        if (player[i][j]=='a'){
            player[i-1][j];
        }
        if(player[i][j]=='b'){
            player[i+1][j];
        
        }
        
        
    }
}
}
void (  char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol)
{




}
