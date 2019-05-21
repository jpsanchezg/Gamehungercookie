#include <iostream>
#include <iomanip>
#include "time.h"
#include "stdlib.h"
#include <iomanip>
//juan pablo sanchez gaitan
using namespace std;
struct personaje
{
    char movs;
    char galleta;
};

#define maxc 30
#define maxf 30
void tablerocreado (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);
void tableroaleatorio (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol,int jugf,int jugc,int alienf,int alienc,int galletf,int galletc,int abisf,int abisc);
void vistamundo ( char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);
int sensacion (  int numeros [maxf][maxc], int nfilas, int ncol,int pojf,int pojc);
void disparar (  int numeros [maxf][maxc], int nfilas, int ncol,int balf,int balc,int contad,int contai,int alienf,int alienc);

int gameover ( int numeros[maxf][maxc], int nfilas, int ncol,int pojf,int pojc,int alienf,int alienc,int abisf, int abisc,bool galleta);

int main ()
{
    int numeros[maxf][maxf], nfilas =0, ncol=0, opcion=0, respu=0;
    int jugf=0, jugc=0,alienf=0,alienc=0,galletc=0,galletf=0,abisf=0,abisc=0;
    srand(time(NULL));
    char player [maxf][maxc];
    personaje lucas;

    do
    {

        cout<<"Bienvenido"<<endl;
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
            jugador (player,numeros,nfilas,ncol,jugf,jugc,alienf,alienc,galletf,galletc,abisf,abisc);


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
            jugador (player,numeros,nfilas,ncol,jugf,jugc,alienf,alienc,galletf,galletc,abisf,abisc);
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
        if (numeros[galletf][galletc] !=  numeros[abisf][abisc])
        {

            numeros[abisf][abisc]=2;

        }
    }
    while(k<abis);

    system("cls");
    vistamundo (player,numeros,nfilas,ncol);
    jugador (player,numeros,nfilas,ncol,jugf,jugc,alienf,alienc,galletf,galletc,abisf,abisc);

}
void tableroaleatorio (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{

    int abis=0,alienf=0,alienc=0,multi=0,ret=0,filas=0,col=0;
    int jugf=0, jugc=0;
    player[jugf][jugc]='L';
    numeros[jugf][jugc]= 5;
    int galletf=0,galletc=0;
    bool poss=false;
    multi = nfilas* ncol;
    ret = multi/2;
    // poricion aleatoria del alien
    alienf =  0 + rand ()% (nfilas);
    alienc =  0 + rand ()% (ncol);
    numeros[alienf][alienc]=1;
    //posicion aleatoria de la galleta
    galletf=0 + rand ()% (nfilas);
    galletc =0 + rand ()% (ncol);
    numeros[galletf][galletc]=3;

    abis =  0 + rand ()% (ret);
    int k=0,abisf=0,abisc=0;
    do
    {
        k++;
        abisf =  0 + rand ()% (nfilas);
        abisc =  0 + rand ()% (ncol);


        while(poss== false)
        {
            if (numeros[0][0] == numeros[abisf][abisc] )
            {
                if (numeros[galletf][galletc] == numeros[abisf][abisc] )
                {
                    poss= false;
                }
            }
            if (numeros[0][0] !=  numeros[abisf][abisc])
            {
                if (numeros[galletf][galletc] !=  numeros[abisf][abisc])
                {

                    poss= true;
                    numeros[abisf][abisc]=2;

                }
            }
        }
    }
    while(k<abis);


    vistamundo (player,numeros,nfilas,ncol);
    jugador (player,numeros,nfilas,ncol,jugf,jugc,alienf,alienc,galletf,galletc,abisf,abisc);



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
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol, int jugf,int jugc,int alienf,int alienc,int galletf,int galletc,int abisf,int abisc)
{
    char opcion;
    int olor =0;
    int k=0,muertos=0;
    int contad =0,contai =0;
    int pojf=0,pojc=0,balf=0,balc=0;
    bool laser = true;
    bool galleta = false;
    bool muerto = false;
    do
    {

        cout<<"Ingrese un movimiento o accion"<<endl;
        cout<<"GIRAR A LA DERECHA = D"<<endl;
        cout<<"GIRAR IZQUIERDA = I"<<endl;
        cout<<"AVANZAR = A"<<endl;
        if (laser == true)
        {
            cout<<"DISPARAR = F"<<endl;
        }
        if (galleta == false)
        {
            cout<<"RECOGER GALLETA = R"<<endl;
        }
        if(galleta == true)
        {
            if (numeros[pojf][pojc]==numeros[0][0] )
            {
                cout<<"COMER GALLETA = C"<<endl;
            }

        }
        cout<<"SALIR = S"<<endl;
        cin>>opcion;
        if (opcion == 'd')
        {
            contad++;
        }
        if (opcion == 'i')
        {
            contai++;
        }
        if (opcion == 'a')
        {
            player [pojf][pojc]='-';
            numeros[pojf][pojc] = 0;
            if (contad == 1)
            {
                pojc = pojc +1;
                player [pojf][pojc]='D';
                numeros [pojf][pojc]=5;
                vistamundo (player,numeros,nfilas,ncol);
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                cout<<olor<<endl;
                contad=0;
                gameover (numeros,nfilas,ncol,pojf,pojc,alienf,alienc,abisf,abisc,galleta);
            }
            if (contad == 2)
            {
                pojf = pojf +1;
                player [pojf][pojc]='B';
                numeros [pojf][pojc]=5;
                vistamundo (player,numeros,nfilas,ncol);
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contad=0;
                cout<<olor<<endl;
                gameover (numeros,nfilas,ncol,pojf,pojc,alienf,alienc,abisf,abisc,galleta);

            }
            if (contad == 3)
            {
                pojc = pojc -1;
                player [pojf][pojc]='a';
                numeros [pojf][pojc]=5;
                vistamundo (player,numeros,nfilas,ncol);
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contad=0;
                cout<<olor<<endl;
                gameover (numeros,nfilas,ncol,pojf,pojc,alienf,alienc,abisf,abisc,galleta);

            }
            if (contad == 4)
            {
                pojf = pojf -1;
                player [pojf][pojc]='a';
                numeros [pojf][pojc]=5;
                vistamundo (player,numeros,nfilas,ncol);
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contad=0;
                cout<<olor<<endl;
                gameover (numeros,nfilas,ncol,pojf,pojc,alienf,alienc,abisf,abisc,galleta);

            }
            if (contai == 1)
            {
                pojc = pojc -1;
                player [pojf][pojc]='I';
                numeros [pojf][pojc]=5;
                vistamundo (player,numeros,nfilas,ncol);
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contai=0;
                cout<<olor<<endl;
                gameover (numeros,nfilas,ncol,pojf,pojc,alienf,alienc,abisf,abisc,galleta);

            }
            if (contai == 2)
            {
                pojf = pojf +1;
                player [pojf][pojc]='B';
                numeros [pojf][pojc]=5;
                vistamundo (player,numeros,nfilas,ncol);
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

                contai=0;
                cout<<olor<<endl;
                gameover (numeros,nfilas,ncol,pojf,pojc,alienf,alienc,abisf,abisc,galleta);


            }
            if (contai == 3)
            {
                pojc = pojc +1;
                player [pojf][pojc]='a';
                numeros [pojf][pojc]=5;
                vistamundo (player,numeros,nfilas,ncol);
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contai=0;
                cout<<olor<<endl;
                gameover (numeros,nfilas,ncol,pojf,pojc,alienf,alienc,abisf,abisc,galleta);

            }
            if (contai == 4)
            {
                pojf = pojf -1;
                player [pojf][pojc]='a';
                numeros [pojf][pojc]=5;
                vistamundo (player,numeros,nfilas,ncol);
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

                contai=0;
                cout<<olor<<endl;
                gameover (numeros,nfilas,ncol,pojf,pojc,alienf,alienc,abisf,abisc,galleta);


            }
        }


        if (opcion =='f')
        {
            if (laser == true)
            {

                balf = pojf;
                balc = pojc;
                disparar (numeros,nfilas,ncol,balf,balc,contad,contai,alienf,alienc);
                laser = false;

            }

        }

        if (opcion == 'r')
        {
            if (numeros [pojf][pojc]== numeros[galletf][galletc])
            {
                galleta =true;
            }
        }
        if (opcion == 'p')
        {
            for(int i=0; i<nfilas; i++)
            {
                for (int j=0; j<ncol; j++)
                {
                    cout<<setw(8)<<numeros[i][j];
                }
                cout<<endl;
            }

        }
        if (opcion == 'c')
        {
            if(galleta == true)
            {
                system("cls");
                cout<<"     _____                       _ "<<endl;
                cout<<"    / ____|                     | |     "<<endl;
                cout<<"   | |  __  __ _ _ __   __ _ ___| |_ ___ "<<endl;
                cout<<"   | | |_ |/ _` | '_ \\ / _` / __| __/ _ \\ "<<endl;
                cout<<"   | |__| | (_| | | | | (_| \\__ \ ||  ___/ "<<endl;
                cout<<"    \\_____|\\__,_|_| |_|\\__,_|___/\\__\\___| "<<endl;
                cout<<"                                         "<<endl;
                cout<<endl;
                system("pause");
                exit(0);
            }
        }

    }
    while (muerto == false);


}
int sensacion (  int numeros [maxf][maxc], int nfilas, int ncol,int pojf,int pojc)
{
    int olor=0;
    //alien
    if (numeros [pojf-1][pojc]==1)
    {
        if (numeros [pojf+1][pojc]==2)
        {
            if (numeros [pojf][pojc+1]==3 )
            {
                olor = 7;
                return olor;

            }
            if (numeros [pojf][pojc-1]==3)
            {
                olor = 7;
                return olor;
            }

            else
                olor = 3;
            return olor;
        }
        if (numeros [pojf+1][pojc]==3)
        {

            if (numeros [pojf][pojc+1]==2 )
            {
                olor = 7;
                return olor;

            }
            if (numeros [pojf][pojc-1]==2)
            {
                olor = 7;
                return olor;
            }
            else
            {
                olor = 5;
                return olor;
            }
        }
        if (numeros [pojf][pojc+1]==3)
        {
            if (numeros [pojf][pojc-1]==2)
            {
                olor = 7;
                return olor;
            }
            if (numeros [pojf+1][pojc]==2)
            {
                olor = 7;
                return olor;
            }
            else
            {
                olor = 5;
                return olor;
            }
        }
        if (numeros [pojf][pojc-1]==3)
        {
            if (numeros [pojf][pojc+1]==2)
            {
                olor = 7;
                return olor;
            }
            if (numeros [pojf+1][pojc]==2)
            {
                olor = 7;
                return olor;
            }
            else
            {
                olor = 5;
                return olor;
            }
        }
        else
        {
            olor= 1;
            return olor;
        }
    }
    if (numeros [pojf+1][pojc]==1)
    {
        if (numeros [pojf-1][pojc]==2)
        {
            if (numeros [pojf][pojc+1]==3 )
            {
                olor = 7;
                return olor;
            }
            if ( numeros [pojf][pojc-1]==3 )
            {
                olor = 7;
                return olor;
            }

            else
                olor = 3;
            return olor;
        }
        if (numeros [pojf-1][pojc]==3)
        {
            if (numeros [pojf][pojc+1]==2 )
            {
                olor = 7;
                return olor;
            }
            if ( numeros [pojf][pojc-1]==2 )
            {
                olor = 7;
                return olor;
            }

            else
            {
                olor = 5;
                return olor;
            }
        }
        if (numeros [pojf][pojc+1]==3)
        {
            if (numeros [pojf-1][pojc]==2 )
            {
                olor = 7;
                return olor;
            }
            if ( numeros [pojf][pojc-1]==2 )
            {
                olor = 7;
                return olor;
            }

            else
            {
                olor = 5;
                return olor;
            }
        }
        if (numeros [pojf][pojc-1]==3)
        {
            if (numeros [pojf-1][pojc]==2 )
            {
                olor = 7;
                return olor;
            }
            if ( numeros [pojf][pojc+1]==2 )
            {
                olor = 7;
                return olor;
            }

            else
            {
                olor = 5;
                return olor;
            }
        }
        else
            olor= 1;
        return olor;
    }
    if (numeros [pojf][pojc-1]==1)
    {
        if (numeros [pojf][pojc+1]==2)
        {
            if (numeros [pojf+1][pojc]==2)
            {
                olor =5;
                return olor;

            }
            if (numeros [pojf-1][pojc]==2)
            {
                olor=5;
                return olor;

            }
            if (numeros [pojf+1][pojc]==3)
            {
                olor =7;
                return olor;

            }
            if (numeros [pojf-1][pojc]==3)
            {
                olor=7;
                return olor;

            }
            else
            {
                olor =3;
                return olor;
            }
        }
        if (numeros [pojf+1][pojc]==2)
        {
            if (numeros [pojf-1][pojc]==2)
            {
                olor = 5;
                return olor;
            }
             if (numeros [pojf][pojc+1]==2)
            {
                olor = 5;
                return olor;

            }

            if (numeros [pojf][pojc+1]==3)
            {
                olor = 7;
                return olor;

            }
            if (numeros [pojf-1][pojc]==3)
            {
                olor = 7;
                return olor;

            }
            else
            {
                olor =3;
                return olor;

            }
        }
        if (numeros [pojf-1][pojc]==2)
        {
            if (numeros [pojf+1][pojc]==2)
            {
                olor = 5;
                return olor;
            }
             if (numeros [pojf][pojc+1]==2)
            {
                olor = 5;
                return olor;

            }

            if (numeros [pojf][pojc+1]==3)
            {
                olor = 7;
                return olor;

            }
            if (numeros [pojf-1][pojc]==3)
            {
                olor = 7;
                return olor;

            }
            else
            {
                olor =3;
                return olor;

            }
        }
        if (numeros [pojf][pojc+1]==3)
        {
            if (numeros [pojf-1][pojc]==2)
            {
                olor = 7;
                return olor;

            }
            if (numeros [pojf+1][pojc]==2)
            {
                olor = 7;
                return olor;

            }
            else {
            olor =5;
            return olor;

        }
        }

        if (numeros [pojf+1][pojc]==3)
        {
           if (numeros [pojf-1][pojc]==2)
            {
                olor = 7;
                return olor;

            }
            if (numeros [pojf][pojc+1]==2)
            {
                olor = 7;
                return olor;
            }
            else {
            olor =5;
            return olor;

        }

        }
        if (numeros [pojf-1][pojc]==3)
        {
            if (numeros [pojf+1][pojc]==2)
            {
                olor = 7;
                return olor;

            }
            if (numeros [pojf][pojc+1]==2)
            {
                olor = 7;
                return olor;
            }
            else {
            olor =5;
            return olor;

        }
        }
        else
        {
            olor = 1;
            return olor;
        }
    }
    if (numeros [pojf][pojc+1]==1)
    {
        if (numeros [pojf][pojc-1]==2)
        {
            if (numeros [pojf+1][pojc]==2)
            {

                olor=5;
                return olor;


            }
            if (numeros [pojf-1][pojc]==2)
            {
                olor=5;
                return olor;

            }
            if (numeros [pojf+1][pojc]==3)
            {
                olor=7;
                return olor;

            }
            if (numeros [pojf-1][pojc]==3)
            {
                olor=7;
                return olor;

            }

            else
            {
                olor=3;
                return olor;

            }
        }
        if (numeros [pojf+1][pojc]==2)
        {
     if (numeros [pojf][pojc-1]==2)
            else {
            olor=3;
            return olor;

        }
        }
        if (numeros [pojf-1][pojc]==2)
        {
            olor=3;
            return olor;

        }
        if (numeros [pojf][pojc-1]==3)
        {
            olor =5;
            return olor;
        }
        if (numeros [pojf+1][pojc]==3)
        {
            olor =5;
            return olor;
        }
        if (numeros [pojf-1][pojc]==3)
        {
            olor =5;
            return olor;
        }
        olor =1;

        return olor;


    }
    //abismo
    if (numeros [pojf+1][pojc]==2)
    {
        if (numeros [pojf-1][pojc]==1)
        {
            if (numeros [pojf][pojc+1]==3 )
            {
                olor = 7;
                return olor;
            }
            if ( numeros [pojf][pojc-1]==3 )
            {
                olor = 7;
                return olor;
            }

            else
                olor = 3;
            return olor;
        }
        if (numeros [pojf-1][pojc]==3)
        {
            olor = 5;
            return olor;
        }
        if (numeros [pojf][pojc+1]==3)
        {
            olor = 5;
            return olor;
        }
        if (numeros [pojf][pojc-1]==3)
        {
            olor = 5;
            return olor;
        }
        else
            olor= 2;
        return olor;
    }
    if (numeros [pojf-1][pojc]==2)
    {
        if (numeros [pojf+1][pojc]==1)
        {
            if (numeros [pojf][pojc+1]==3 )
            {
                olor = 7;
                return olor;
            }
            if ( numeros [pojf][pojc-1]==3 )
            {
                olor = 7;
                return olor;
            }

            else
                olor = 3;
            return olor;
        }
        if (numeros [pojf-1][pojc]==3)
        {
            olor = 5;
            return olor;
        }
        if (numeros [pojf][pojc+1]==3)
        {
            olor = 5;
            return olor;
        }
        if (numeros [pojf][pojc-1]==3)
        {
            olor = 5;
            return olor;
        }
        else
            olor= 2;
        return olor;
    }
    //galleta
    if (numeros [pojf+1][pojc]==3)
    {
        if (numeros [pojf-1][pojc]==1)
        {
            olor = 5;
            return olor;
        }
        if  (numeros [pojf][pojc+1]==1)
        {
            olor = 5;
            return olor;
        }
        if  (numeros [pojf][pojc-1]==1)
        {
            olor = 5;
            return olor;
        }
        if  (numeros [pojf-1][pojc]==2)
        {
            olor = 6;
            return olor;
        }
        if  (numeros [pojf][pojc+1]==2)
        {
            olor = 6;
            return olor;
        }
        if  (numeros [pojf][pojc-1]==2)
        {
            olor = 6;
            return olor;
        }
        else
        {

            olor =4;
            return olor;
        }

        return olor;
    }
}
int  gameover  ( int numeros[maxf][maxc], int nfilas, int ncol,int pojf,int pojc,int alienf,int alienc,int abisf, int abisc,bool galleta)
{
    int num =0;

    if (numeros[pojf][pojc] == numeros [abisf][abisc])
    {
        system("cls");
        cout << "  _____      ___       ___  ___   _____"    << endl;
        cout << " / ___ |    /   |     /   |/   | |  ___|"  << endl;
        cout << "| |        / /| |    / /|   /| | | |__"    << endl;
        cout << "| |  _    / ___ |   / / |__/ | | |  __|"   << endl;
        cout << "| |_| |  / /  | |  / /       | | | |___"   << endl;
        cout << "\\_____/ /_/   |_| /_/        |_| |_____|"  << endl;
        cout << " _____   _     _   _____   _____"          << endl;
        cout << "/  _  \\ | |   / / |  ___| |  _   \\ "        << endl;
        cout << "| | | | | |  / /  | |__   | |_|  |"         << endl;
        cout << "| | | | | | / /   |  __|  |  _   /"         << endl;
        cout << "| |_| | | |/ /    | |___  | | \\  \\  "        << endl;
        cout << "\\_____/ |___/     |_____| |_|  \\ _\\ "       << endl;
        cout << endl << endl;
        exit(0);

    }
    if (numeros[pojf][pojc] == numeros [alienf][alienc])
    {
        system("cls");
        cout << "  _____      ___       ___  ___   _____"    << endl;
        cout << " / ___ |    /   |     /   |/   | |  ___|"  << endl;
        cout << "| |        / /| |    / /|   /| | | |__"    << endl;
        cout << "| |  _    / ___ |   / / |__/ | | |  __|"   << endl;
        cout << "| |_| |  / /  | |  / /       | | | |___"   << endl;
        cout << "\\_____/ /_/   |_| /_/        |_| |_____|"  << endl;
        cout << " _____   _     _   _____   _____"          << endl;
        cout << "/  _  \\ | |   / / |  ___| |  _   \\ "        << endl;
        cout << "| | | | | |  / /  | |__   | |_|  |"         << endl;
        cout << "| | | | | | / /   |  __|  |  _   /"         << endl;
        cout << "| |_| | | |/ /    | |___  | | \\  \\  "        << endl;
        cout << "\\_____/ |___/     |_____| |_|  \\ _\\ "       << endl;
        cout << endl << endl;
        cout << endl << endl;
        exit(0);
    }

}
void disparar (  int numeros [maxf][maxc], int nfilas, int ncol,int balf,int balc,int contad,int contai,int alienf,int alienc)
{
    bool alienmuerto =false;
    if (contad == 1)
    {
        balc = balc +alienc;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
        }


        contad=0;
    }
    if (contad == 2)
    {
        balf = balf +alienf;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
        }


        contad=0;

    }
    if (contad == 3)
    {

        balc = balc -alienc;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
        }


        contad=0;
    }
    if (contad == 4)
    {
        balf = balf -alienf;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
        }


        contad=0;
    }
    if (contai == 1)
    {

        balc = balc -alienc;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
        }


        contad=0;

    }
    if (contai == 2)
    {
        balf = balf -alienf;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
        }


        contad=0;

    }
    if (contai == 3)
    {
        balc = balc +alienc;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
        }


        contad=0;
    }
    if (contai == 4)
    {
        balf = balf +alienf;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
        }
        contad=0;
    }
}


