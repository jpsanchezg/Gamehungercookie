#include <iostream>
#include <iomanip>
#include "time.h"
#include "stdlib.h"
#include <iomanip>
#include "windows.h"
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
void tablerdiabolico (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);

void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol,int alienf,int alienc,int galletf,int galletc,int abisf,int abisc,int contu);
void vistamundo ( char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);
int sensacion (  int numeros [maxf][maxc], int nfilas, int ncol,int pojf,int pojc);
int disparar (  int numeros [maxf][maxc], int nfilas, int ncol,int balf,int balc,int contad,int contai,int alienf,int alienc);

int gameover ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol);

int main ()
{
    int contu =0;
    int numeros[maxf][maxf], nfilas =0, ncol=0, opcion=0, respu=0;
    int jugf=0, jugc=0,alienf=0,alienc=0,galletc=0,galletf=0,abisf=0,abisc=0;
    srand(time(NULL));
    char player [maxf][maxc];
    personaje lucas;
    cout<<"\t \t \t \t    MMMMMMMMMMMMWKxl:,','''',,,'. ;KMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMNOl;'....'lxxxxxxx:.,kNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMWKd;',col,'.,lxxxxxxxc.'xNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMWKo''cdxxxxdlldxxxxxxdxd'.dNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMNx,'cdxxxxxxxxxxxxxxxxxxd,.;l0MMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMK:..cdxxxxxxxxxxo:;;:ldxxxdl. oXKNMMMMMMMWMMWWMM"<<endl;
    cout<<"\t \t \t \t    MK; ...;dxxxxxxxxo,.''.'lxxxxxc',,.cKOokXO::ol;lKM"<<endl;
    cout<<"\t \t \t \t    X:.::;;ldxxxxxxxxd;....'lxxxxxxdol;','.','';;,'.:X"<<endl;
    cout<<"\t \t \t \t    o.;xxxxxxxxxxxxxxxdc:::ldxxxxxxxxxxdooddlodxxoc'.o"<<endl;
    cout<<"\t \t \t \t    '.oxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxxxxdl:;.,"<<endl;
    cout<<"\t \t \t \t    .;xxxdl:::ldxxxxxxxxxxxxxxxxxo:;;cdxxxdxxxxd:....."<<endl;
    cout<<"\t \t \t \t    :xxxl'.'..cxxxxxxxxxxxxxxxxxo'..,oxxxxxxxxdc,',. "<<endl;
    cout<<"\t \t \t \t    .cxxxo,...'lxxxxxxxxxxxxxxxxxdolcoxxxxxxxxxxxdlc, "<<endl;
    cout<<"\t \t \t \t    :xxxxdlcloxxxxxxxxxxoc:cloxxxxxxxxdc::coxxxxdlc' "<<endl;
    cout<<"\t \t \t \t    .,dxxxxxxxxxxxxxxxxxd;.'..;dxxxxxxd;.'..,oxxdolc.."<<endl;
    cout<<"\t \t \t \t    :.coldxxxxxxxdxxxxxxd;....,oxxxxxxx:....,oxxoll;.c"<<endl;
    cout<<"\t \t \t \t    k....,oxxxxxxxo:;;ldxdc:cloxxxxxxxxdoc:ldxxoll:.'0"<<endl;
    cout<<"\t \t \t \t    Wd...,oxxxxxxxc...'oxxxxxxxdxxxxxxxxdxxdlcccc:..kW"<<endl;
    cout<<"\t \t \t \t    MWx..:dxxxxxxxdc::ldxxxxxxxxxxdoodxxdxd;...;;.'kWM"<<endl;
    cout<<"\t \t \t \t    MMWO;.,odxxxxxxxxxxxxxxxxxxxd:,'';lxxxd:'''..;0WMM"<<endl;
    cout<<"\t \t \t \t    MMMMNd'.;lodxxxxxxxxxxxxxxxxl'.,'.;oolll:'.,xNMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMXd,.':loddddoodxxxxdxxdc;,',:ccc;'.,dXMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMNkc'.';:c,''':ooooollolccc:,'.,ckNMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMMWXko:,.. ...,;;;;,,,'..',:oOXMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMMMMMMWKko;'..      ..':okXWMMMMMMMMMMMMMM"<<endl;
    cout<<endl;
    cout<<"Iniciando juego Cookie Hunter";
    Sleep (1500);
    cout<<".";
    Sleep (1000);
    cout<<".";
    Sleep (1000);
    cout<<".";
    Sleep (0700);
    cout<<".";
    Sleep (0700);
    system("cls");
    cout<<"\t \t \t \t    MMMMMMMMMMMMWKxl:,','''',,,'. ;KMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMNOl;'....'lxxxxxxx:.,kNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMWKd;',col,'.,lxxxxxxxc.'xNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMWKo''cdxxxxdlldxxxxxxdxd'.dNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMNx,'cdxxxxxxxxxxxxxxxxxxd,.;l0MMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMK:..cdxxxxxxxxxxo:;;:ldxxxdl. oXKNMMMMMMMWMMWWMM"<<endl;
    cout<<"\t \t \t \t    MK; ...;dxxxxxxxxo,.''.'lxxxxxc',,.cKOokXO::ol;lKM"<<endl;
    cout<<"\t \t \t \t    X:.::;;ldxxxxxxxxd;....'lxxxxxxdol;','.','';;,'.:X"<<endl;
    cout<<"\t \t \t \t    o.;xxxxxxxxxxxxxxxdc:::ldxxxxxxxxxxdooddlodxxoc'.o"<<endl;
    cout<<"\t \t \t \t    '.oxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxxxxdl:;.,"<<endl;
    cout<<"\t \t \t \t    .;xxxdl:::ldxxxxxxxxxxxxxxxxxo:;;cdxxxdxxxxd:....."<<endl;
    cout<<"\t \t \t \t    :xxxl'.'..cxxxxxxxxxxxxxxxxxo'..,oxxxxxxxxdc,',. "<<endl;
    cout<<"\t \t \t \t    .cxxxo,...'lxxxxxxxxxxxxxxxxxdolcoxxxxxxxxxxxdlc, "<<endl;
    cout<<"\t \t \t \t    :xxxxdlcloxxxxxxxxxxoc:cloxxxxxxxxdc::coxxxxdlc' "<<endl;
    cout<<"\t \t \t \t    .,dxxxxxxxxxxxxxxxxxd;.'..;dxxxxxxd;.'..,oxxdolc.."<<endl;
    cout<<"\t \t \t \t    :.coldxxxxxxxdxxxxxxd;....,oxxxxxxx:....,oxxoll;.c"<<endl;
    cout<<"\t \t \t \t    k....,oxxxxxxxo:;;ldxdc:cloxxxxxxxxdoc:ldxxoll:.'0"<<endl;
    cout<<"\t \t \t \t    Wd...,oxxxxxxxc...'oxxxxxxxdxxxxxxxxdxxdlcccc:..kW"<<endl;
    cout<<"\t \t \t \t    MWx..:dxxxxxxxdc::ldxxxxxxxxxxdoodxxdxd;...;;.'kWM"<<endl;
    cout<<"\t \t \t \t    MMWO;.,odxxxxxxxxxxxxxxxxxxxd:,'';lxxxd:'''..;0WMM"<<endl;
    cout<<"\t \t \t \t    MMMMNd'.;lodxxxxxxxxxxxxxxxxl'.,'.;oolll:'.,xNMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMXd,.':loddddoodxxxxdxxdc;,',:ccc;'.,dXMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMNkc'.';:c,''':ooooollolccc:,'.,ckNMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMMWXko:,.. ...,;;;;,,,'..',:oOXMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMMMMMMWKko;'..      ..':okXWMMMMMMMMMMMMMM"<<endl;
    cout<<endl;
    cout<<"Abriendo carpeta juego.dem"<<endl;
    Sleep (1500);
    cout<<"main.cpp"<<endl;
    Sleep (1000);
    cout<<"Archivo encontrado"<<endl;
    Sleep (1000);
    cout<<"soy_la_muerte_encarnada.lv"<<endl;
    Sleep (0700);
    cout<<"Todos los archivos estan en perfecto estado"<<endl;
    Sleep (0700);
    system("cls");
    cout<<"\t \t \t \t    MMMMMMMMMMMMWKxl:,','''',,,'. ;KMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMNOl;'....'lxxxxxxx:.,kNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMWKd;',col,'.,lxxxxxxxc.'xNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMWKo''cdxxxxdlldxxxxxxdxd'.dNMMMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMNx,'cdxxxxxxxxxxxxxxxxxxd,.;l0MMMMMMMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMK:..cdxxxxxxxxxxo:;;:ldxxxdl. oXKNMMMMMMMWMMWWMM"<<endl;
    cout<<"\t \t \t \t    MK; ...;dxxxxxxxxo,.''.'lxxxxxc',,.cKOokXO::ol;lKM"<<endl;
    cout<<"\t \t \t \t    X:.::;;ldxxxxxxxxd;....'lxxxxxxdol;','.','';;,'.:X"<<endl;
    cout<<"\t \t \t \t    o.;xxxxxxxxxxxxxxxdc:::ldxxxxxxxxxxdooddlodxxoc'.o"<<endl;
    cout<<"\t \t \t \t    '.oxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxdxxxxdl:;.,"<<endl;
    cout<<"\t \t \t \t    .;xxxdl:::ldxxxxxxxxxxxxxxxxxo:;;cdxxxdxxxxd:....."<<endl;
    cout<<"\t \t \t \t    :xxxl'.'..cxxxxxxxxxxxxxxxxxo'..,oxxxxxxxxdc,',. "<<endl;
    cout<<"\t \t \t \t    .cxxxo,...'lxxxxxxxxxxxxxxxxxdolcoxxxxxxxxxxxdlc, "<<endl;
    cout<<"\t \t \t \t    :xxxxdlcloxxxxxxxxxxoc:cloxxxxxxxxdc::coxxxxdlc' "<<endl;
    cout<<"\t \t \t \t    .,dxxxxxxxxxxxxxxxxxd;.'..;dxxxxxxd;.'..,oxxdolc.."<<endl;
    cout<<"\t \t \t \t    :.coldxxxxxxxdxxxxxxd;....,oxxxxxxx:....,oxxoll;.c"<<endl;
    cout<<"\t \t \t \t    k....,oxxxxxxxo:;;ldxdc:cloxxxxxxxxdoc:ldxxoll:.'0"<<endl;
    cout<<"\t \t \t \t    Wd...,oxxxxxxxc...'oxxxxxxxdxxxxxxxxdxxdlcccc:..kW"<<endl;
    cout<<"\t \t \t \t    MWx..:dxxxxxxxdc::ldxxxxxxxxxxdoodxxdxd;...;;.'kWM"<<endl;
    cout<<"\t \t \t \t    MMWO;.,odxxxxxxxxxxxxxxxxxxxd:,'';lxxxd:'''..;0WMM"<<endl;
    cout<<"\t \t \t \t    MMMMNd'.;lodxxxxxxxxxxxxxxxxl'.,'.;oolll:'.,xNMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMXd,.':loddddoodxxxxdxxdc;,',:ccc;'.,dXMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMNkc'.';:c,''':ooooollolccc:,'.,ckNMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMMWXko:,.. ...,;;;;,,,'..',:oOXMMMMMMMMMMM"<<endl;
    cout<<"\t \t \t \t    MMMMMMMMMMMMMMWKko;'..      ..':okXWMMMMMMMMMMMMMM"<<endl;
    cout<<endl;
    cout<<"Cargo exitosamente";
    Sleep (1000);
    system("cls");

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
            jugador (player,numeros,nfilas,ncol,alienf,alienc,galletf,galletc,abisf,abisc,contu);


            break;
        case 1:
            nfilas = 1 + rand ()% (maxf);
            ncol=1 + rand ()% (maxc);
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
            system("cls");

            tableroaleatorio(player, numeros,nfilas,ncol);
            jugador (player,numeros,nfilas,ncol,alienf,alienc,galletf,galletc,abisf,abisc,contu);
            break;

        case 2:
            cout<<"Las instrucciones del juego son las siguientes:"<<endl;
            cout<<" El jugador debe encontrar la galleta por un mapa que el jugador puede crear o elejir la creacion alatoria"<<endl;
            cout<<" Los abismos, el alien y la galleta tienen su olor y sonido respectivo."<<endl;
            cout<<"El abismo persibe una brisa la cual le va a indicar a el jugador que esta cerca a un abismo"<<endl;
            break;
        case 66:
            nfilas = 30;
            ncol=20;
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
            system("cls");
            tablerdiabolico (player, numeros,nfilas,ncol);
            jugador (player,numeros,nfilas,ncol,alienf,alienc,galletf,galletc,abisf,abisc,contu);
            break;
        }

    }
    while (opcion != 4);
}
void tablerocreado (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{
    int abis=0,alienf=0,alienc=0,multi=0,ret=0,filas=0,col=0;
    int jugf=0, jugc=0;
    int contu=0;
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
        contu =k;

    }
    while(k<abis);

    system("cls");
    cout<<"\t \t \t \t    Recuerda que para moverte tienes que oprimir la letra d o i, "<<endl;
    cout<<"\t \t \t \t    para  a para poder avanzar pulsa a "<<endl;
    cout<<"\t \t \t \t    aca te camos los movimientos de cada letra: "<<endl;
    cout<<"\t \t \t \t\t    d = Derecha "<<endl;
    cout<<"\t \t \t \t\t    dd = Abajo "<<endl;
    cout<<"\t \t \t \t\t    ddd = Izquierda "<<endl;
    cout<<"\t \t \t \t\t    dddd = Arriba "<<endl;
    cout<<endl;
    cout<<"\t \t \t \t\t     i = Izquierda "<<endl;
    cout<<"\t \t \t \t\t     ii = Abajo "<<endl;
    cout<<"\t \t \t \t\t     iii = Derecha "<<endl;
    cout<<"\t \t \t \t\t     iiii= Arriba "<<endl;
    Sleep (1500);
    cout<<"Cargando mapa";
    Sleep (0500);
    cout<<".";
    Sleep (0500);
    cout<<".";
    Sleep (0500);
    cout<<".";
    system("cls");
    cout<<"\t \t \t \t    Tambien puedes percibir el olor o aroma de ciertas cosas, "<<endl;
    cout<<"\t \t \t \t    esas cosas pueden ser: "<<endl;
    cout<<"\t \t \t \t\t     Alien= frio polar  "<<endl;
    cout<<"\t \t \t \t\t     Abismo= brisa "<<endl;
    cout<<"\t \t \t \t\t     Galleta= Galleta "<<endl;
    Sleep (1500);
    cout<<"Poniendo el alien, la galleta y los avismos en sus posiciones"<<endl;
    Sleep (1500);
    cout<<"Todo cargo a la perfeccion es hora de jugar"<<endl;
    Sleep (1500);
    system("cls");











    jugador (player,numeros,nfilas,ncol,alienf,alienc,galletf,galletc,abisf,abisc,contu);

}
void tablerdiabolico (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{
    int abis=0,alienf=0,alienc=0,multi=0,ret=0,filas=0,col=0;
    int jugf=0, jugc=0;
    player[jugf][jugc]='L';
    numeros[jugf][jugc]= 5;
    int galletf=0,galletc=0,contu =0;
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
    if (numeros[galletf][galletc]!= numeros[jugf][jugc] )
    {
        numeros[galletf][galletc]=3;
    }

    abis =  200;
    int k=0,abisf=0,abisc=0;

    do
    {
        k++;
        abisf =  0 + rand ()% (nfilas);
        abisc =  0 + rand ()% (ncol);

        contu = k;


        if (numeros[jugf][jugc] !=  numeros[abisf][abisc])
        {
            if (numeros[galletf][galletc] !=  numeros[abisf][abisc] )
            {
                if (numeros[abisf][abisc] == 0  )
                {
                    numeros[abisf][abisc]=2;
                }
            }
        }
    }
    while(k<abis);


    cout<<"\t \t \t \t    Recuerda que para moverte tienes que oprimir la letra d o i, "<<endl;
    cout<<"\t \t \t \t    para  a para poder avanzar pulsa a "<<endl;
    cout<<"\t \t \t \t    aca te camos los movimientos de cada letra: "<<endl;
    cout<<"\t \t \t \t\t    d = Derecha "<<endl;
    cout<<"\t \t \t \t\t    dd = Abajo "<<endl;
    cout<<"\t \t \t \t\t    ddd = Izquierda "<<endl;
    cout<<"\t \t \t \t\t    dddd = Arriba "<<endl;
    cout<<endl;
    cout<<"\t \t \t \t\t     i = Izquierda "<<endl;
    cout<<"\t \t \t \t\t     ii = Abajo "<<endl;
    cout<<"\t \t \t \t\t     iii = Derecha "<<endl;
    cout<<"\t \t \t \t\t     iiii= Arriba "<<endl;
    Sleep (1500);
    cout<<"Cargando mapa";
    Sleep (0500);
    cout<<".";
    Sleep (0500);
    cout<<".";
    Sleep (0500);
    cout<<".";
    system("cls");
    cout<<"\t \t \t \t    Tambien puedes percibir el olor o aroma de ciertas cosas, "<<endl;
    cout<<"\t \t \t \t    esas cosas pueden ser: "<<endl;
    cout<<"\t \t \t \t\t     Alien= frio polar  "<<endl;
    cout<<"\t \t \t \t\t     Abismo= brisa "<<endl;
    cout<<"\t \t \t \t\t     Galleta= Galleta "<<endl;
    Sleep (1500);
    cout<<"Poniendo el alien, la galleta y los avismos en sus posiciones"<<endl;
    Sleep (1500);
    cout<<"Todo cargo a la perfeccion es hora de jugar"<<endl;
    Sleep (1500);
    system("cls");

    cout<<"ENTRASTE AL NIVEL !SOY LA MUERTE ENCARNADA!"<<endl;

    jugador (player,numeros,nfilas,ncol,alienf,alienc,galletf,galletc,abisf,abisc,contu);

}

void tableroaleatorio (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{

    int abis=0,alienf=0,alienc=0,multi=0,ret=0,filas=0,col=0;
    int jugf=0, jugc=0,x=0,y=0;
    player[jugf][jugc]='L';
    numeros[jugf][jugc]= 5;
    int galletf=0,galletc=0;
    int contu = 0;
    int olor =0;
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

    abis =  1 + rand ()% (ret);
    int k =0,abisf=0,abisc=0;
    do
    {
        k++;
        abisf =  0 + rand ()% (nfilas);
        abisc =  0 + rand ()% (ncol);
        contu = k;
        if (numeros[jugf][jugc] !=  numeros[abisf][abisc])
        {
            if (numeros[galletf][galletc] !=  numeros[abisf][abisc] )

            {
                if (numeros[abisf][abisc] == 0  )
                {
                    numeros[abisf][abisc]=2;

                }
            }
        }

    }
    while(k<abis);
    cout<<"\t \t \t \t    Recuerda que para moverte tienes que oprimir la letra d o i, "<<endl;
    cout<<"\t \t \t \t    para  a para poder avanzar pulsa a "<<endl;
    cout<<"\t \t \t \t    aca te camos los movimientos de cada letra: "<<endl;
    cout<<"\t \t \t \t\t    d = Derecha "<<endl;
    cout<<"\t \t \t \t\t    dd = Abajo "<<endl;
    cout<<"\t \t \t \t\t    ddd = Izquierda "<<endl;
    cout<<"\t \t \t \t\t    dddd = Arriba "<<endl;
    cout<<endl;
    cout<<"\t \t \t \t\t     i = Izquierda "<<endl;
    cout<<"\t \t \t \t\t     ii = Abajo "<<endl;
    cout<<"\t \t \t \t\t     iii = Derecha "<<endl;
    cout<<"\t \t \t \t\t     iiii= Arriba "<<endl;
    Sleep (1500);
    cout<<"Cargando mapa";
    Sleep (0500);
    cout<<".";
    Sleep (0500);
    cout<<".";
    Sleep (0500);
    cout<<".";
    system("cls");
    cout<<"\t \t \t \t    Tambien puedes percibir el olor o aroma de ciertas cosas, "<<endl;
    cout<<"\t \t \t \t    esas cosas pueden ser: "<<endl;
    cout<<"\t \t \t \t\t     Alien= frio polar  "<<endl;
    cout<<"\t \t \t \t\t     Abismo= brisa "<<endl;
    cout<<"\t \t \t \t\t     Galleta= Galleta "<<endl;
    Sleep (1500);
    cout<<"Poniendo el alien, la galleta y los avismos en sus posiciones"<<endl;
    Sleep (1500);
    cout<<"Todo cargo a la perfeccion es hora de jugar"<<endl;
    Sleep (1500);
    system("cls");

    jugador (player,numeros,nfilas,ncol,alienf,alienc,galletf,galletc,abisf,abisc,contu);



}
void vistamundo (char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol)
{
    for(int i=0; i<nfilas; i++)

    {
        // cout<<"|"<<setw(8);
        for (int j=0; j<ncol; j++)
        {

            cout<<setw(4)<<player[i][j];
        }
        cout<<endl;
    }
}
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol,int alienf,int alienc,int galletf,int galletc,int abisf,int abisc,int contu)
{
    char opcion;
    int k=0,muertos=0;
    int alienm=0;
    string alienfu;
    int olor =0;
    string aroma;
    string muro;
    int contad =0,contai =0;
    int pojf=0,pojc=0,balf=0,balc=0;
    bool laser = true;
    bool pared = false;
    bool galleta = false;
    bool muerto = false;
    do
    {
        vistamundo (player,numeros,nfilas,ncol);

        cout<<"Ingrese un movimiento o accion"<<endl;
        cout<<"GIRAR A LA DERECHA = D"<<endl;
        cout<<"GIRAR IZQUIERDA = I"<<endl;
        cout<<"AVANZAR = A"<<endl;
        if (laser == true)
        {
            cout<<"DISPARAR = F"<<endl;
        }
        if (laser == false)
        {
            if (alienm == 1)
            {
                cout<<"######  ####### ####### #     # ### ### ###"<<endl;
                cout<<"#     # #     # #     # ##   ## ### ### ### "<<endl;
                cout<<"#     # #     # #     # # # # # ### ### ### "<<endl;
                cout<<"######  #     # #     # #  #  #  #   #   #  "<<endl;
                cout<<"#     # #     # #     # #     #             "<<endl;
                cout<<"#     # #     # #     # #     # ### ### ### "<<endl;
                cout<<"######  ####### ####### #     # ### ### ### "<<endl;

            }
            cout<<"SONIDO: "<<alienfu<<endl;

        }
        if (numeros[pojf][pojc]==numeros[galletf][galletc] )
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
        olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
        if (olor == 0)
        {
            aroma = "no hueles nada,tal vez tienes la nariz tapada";
        }
        if (olor == 1)
        {
            aroma = "Frio polar";
        }
        if (olor == 2)
        {
            aroma = "Brisa";
        }
        if (olor == 3)
        {
            aroma = "Frio polar + brisa";
        }
        if (olor == 4)
        {
            aroma = "MMMM... Galletttaaaaa";
        }
        if (olor == 5)
        {
            aroma = "Frio polar + la deliciosa galleta";
        }
        if (olor == 6)
        {
            aroma = "Brisa + La deliciosa galleta";
        }
        if (olor == 7)
        {
            aroma = "Frio polar + Brisa + La deliciosa galleta";
        }
        cout<<"AROMA = "<<aroma<<endl;
        if (pared == true)
        {
            cout<<muro<<endl;
            pared = false;
        }
        cin>>opcion;
        if (opcion == 'd')
        {
            contad++;
            if (contad == 1)
            {
                player [pojf][pojc]='D';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            if (contad == 2)
            {
                player [pojf][pojc]='B';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            if (contad == 3)
            {
                player [pojf][pojc]='I';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            if (contad == 4)
            {
                player [pojf][pojc]='A';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            system("cls");
        }
        if (opcion == 'i')
        {
            contai++;
            if (contai == 1)
            {
                player [pojf][pojc]='I';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            if (contai == 2)
            {
                player [pojf][pojc]='B';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            if (contai == 3)
            {
                player [pojf][pojc]='D';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            if (contai == 4)
            {
                player [pojf][pojc]='A';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
            }
            system("cls");
        }
        if (opcion == 'a')
        {
            if (contad == 1)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojc = pojc +1;
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( pojc == ncol)
                {
                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='D';
                    numeros[pojf][pojc] = 5;
                    pojc = pojc -1;
                }
                player [pojf][pojc]='D';
                numeros [pojf][pojc]=5;

                olor =  sensacion (numeros,  nfilas, ncol,pojf,pojc);
                contad=0;

            }

            if (contad == 2)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojf = pojf +1;
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if (pojf == nfilas)
                {
                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='B';
                    numeros[pojf][pojc] = 5;
                    pojf = pojf -1;
                }
                player [pojf][pojc]='B';
                numeros [pojf][pojc]=5;

                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contad=0;



            }
            if (contad == 3)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojc = pojc -1;
                if ( pojc == -1)
                {
                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='I';
                    numeros[pojf][pojc] = 5;
                    pojc = pojc +1;
                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }

                player [pojf][pojc]='I';
                numeros [pojf][pojc]=5;

                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contad=0;


            }
            if (contad == 4)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojf = pojf -1;
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( pojf == -1)
                {
                    pared = true;
                    muro = "Te chocaste con el muro";
                    player [pojf][pojc]='A';
                    numeros[pojf][pojc] = 5;
                    pojf = pojf + 1;
                }
                player [pojf][pojc]='A';
                numeros [pojf][pojc]=5;

                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contad=0;


            }
            if (contai == 1)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojc = pojc -1;
                if ( pojc == -1)
                {
                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='I';
                    numeros[pojf][pojc] = 5;
                    pojc = pojc +1;
                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                player [pojf][pojc]='I';
                numeros [pojf][pojc]=5;

                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contai=0;



            }
            if (contai == 2)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojf = pojf +1;
                if ( pojf == nfilas)
                {
                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='B';
                    numeros[pojf][pojc] = 5;
                    pojf = pojf -1;
                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }

                player [pojf][pojc]='B';
                numeros [pojf][pojc]=5;
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

                contai=0;



            }
            if (contai == 3)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojc = pojc +1;
                if ( pojc == ncol)
                {
                    player [pojf][pojc]='D';
                    numeros[pojf][pojc] = 5;
                    pojc = pojc -1;
                    muro = "Te chocaste con el muro";
                    pared = true;

                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                player [pojf][pojc]='D';
                numeros [pojf][pojc]=5;
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contai=0;


            }
            if (contai == 4)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojf = pojf -1;

                if ( pojf == -1)
                {
                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='A';
                    numeros[pojf][pojc] = 5;
                    pojf = pojf +1;
                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ( player, numeros, nfilas, ncol);
                }
                player [pojf][pojc]='A';
                numeros [pojf][pojc]=5;

                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

                contai=0;


            }
            system("cls");

        }




        if (opcion =='f')
        {
            if (laser == true)
            {

                balf = pojf;
                balc = pojc;
                alienm = disparar (numeros,nfilas,ncol,balf,balc,contad,contai,alienf,alienc);
                laser = false;
                if (alienm == 1)
                {
                    alienfu = "*Sonidos de agonia en algun punto del mapa*";
                }
                if(alienm == 0)
                {
                    alienfu ="No se escucha ningun sonido";
                }

            }

        }

        if (opcion == 'r')
        {
            system("cls");

            if (numeros [pojf][pojc]== numeros[galletf][galletc])
            {
                galleta =true;
            }
        }
        if (opcion == 'p')
        {
            system("cls");
            for(int i=0; i<nfilas; i++)
            {
                for (int j=0; j<ncol; j++)
                {
                    cout<<setw(4)<<numeros[i][j];
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
    if (pojf>0)
    {
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
    }
    if (pojf<nfilas)
    {
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
    }
    if (pojc>0)
    {
        if (numeros [pojf][pojc-1]==1)
        {
            if (numeros [pojf][pojc+1]==2)
            {
                if (numeros [pojf+1][pojc]==2)
                {
                    olor =3;
                    return olor;

                }
                if (numeros [pojf-1][pojc]==2)
                {
                    olor=3;
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
                    olor = 3;
                    return olor;
                }
                if (numeros [pojf][pojc+1]==2)
                {
                    olor = 3;
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
                    olor = 3;
                    return olor;
                }
                if (numeros [pojf][pojc+1]==2)
                {
                    olor = 3;
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
                else
                {
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
                else
                {
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
                else
                {
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
    }
    if (pojc<ncol)
    {
        if (numeros [pojf][pojc+1]==1)
        {
            if (numeros [pojf][pojc-1]==2)
            {
                if (numeros [pojf+1][pojc]==2)
                {

                    olor=3;
                    return olor;


                }
                if (numeros [pojf-1][pojc]==2)
                {
                    olor=3;
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
                {
                    olor = 3;
                    return olor;
                }
                if (numeros [pojf][pojc-1]==3)
                {
                    olor = 7;
                    return olor;
                }
                else
                {
                    olor=3;
                    return olor;

                }
            }
            if (numeros [pojf-1][pojc]==2)
            {
                if (numeros [pojf][pojc-1]==2)
                {
                    olor = 3;
                    return olor;
                }
                if (numeros [pojf][pojc-1]==3)
                {
                    olor = 7;
                    return olor;
                }
                else
                {
                    olor=3;
                    return olor;

                }

            }
            if (numeros [pojf][pojc-1]==3)
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
                else
                {
                    olor =5;
                    return olor;
                }
            }
            if (numeros [pojf+1][pojc]==3)
            {

                if (numeros [pojf][pojc-1]==2)
                {
                    olor = 7;
                    return olor;
                }
                else
                {
                    olor =5;
                    return olor;
                }
            }
            if (numeros [pojf-1][pojc]==3)
            {
                if (numeros [pojf][pojc-1]==2)
                {
                    olor = 7;
                    return olor;
                }
                else
                {
                    olor =5;
                    return olor;
                }
            }
            else
            {
                olor =1;

                return olor;
            }
        }
    }
    //abismo
    if (pojf<nfilas)
    {
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
                if (numeros [pojf][pojc+1]==2 )
                {
                    olor = 3;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==2 )
                {
                    olor = 3;
                    return olor;
                }

                else
                {
                    olor = 3;
                    return olor;
                }
            }
            if (numeros [pojf-1][pojc]==3)
            {
                if (numeros [pojf][pojc+1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if (numeros [pojf][pojc+1]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==1 )
                {
                    olor = 7;
                    return olor;
                }
                else
                {
                    olor = 6;
                    return olor;
                }
            }
            if (numeros [pojf][pojc+1]==3)
            {
                if (numeros [pojf+1][pojc]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 6;
                    return olor;
                }
            }
            if (numeros [pojf][pojc-1]==3)
            {
                if (numeros [pojf+1][pojc]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 6;
                    return olor;
                }
            }

            if (numeros [pojf][pojc-1]==2)
            {
                if (numeros [pojf+1][pojc]==1 )
                {
                    olor = 3;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==1 )
                {
                    olor = 3;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==3 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==3 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 2;
                    return olor;
                }
            }
            if (numeros [pojf][pojc+1]==2)
            {
                if (numeros [pojf+1][pojc]==1 )
                {
                    olor = 3;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==1 )
                {
                    olor = 3;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==3 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==3 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 2;
                    return olor;
                }
            }
            else
            {
                olor= 2;
                return olor;
            }
        }
    }
    // abismo arriba
    if (pojf >0)
    {
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
                if (numeros [pojf][pojc+1]==2 )
                {
                    olor = 3;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==2 )
                {
                    olor = 3;
                    return olor;
                }

                else
                {
                    olor = 3;
                    return olor;
                }
            }
            if (numeros [pojf+1][pojc]==3)
            {
                if (numeros [pojf][pojc+1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if (numeros [pojf][pojc+1]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==1 )
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
                if (numeros [pojf+1][pojc]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==2 )
                {
                    olor = 6;
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
                if (numeros [pojf+1][pojc]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==1 )
                {
                    olor = 7;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 5;
                    return olor;
                }
            }

            if (numeros [pojf][pojc-1]==2)
            {
                if (numeros [pojf+1][pojc]==1 )
                {
                    olor = 3;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==1 )
                {
                    olor = 3;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==2 )
                {
                    olor = 2;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==2 )
                {
                    olor = 2;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==3 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==3 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 2;
                    return olor;
                }
            }
            if (numeros [pojf][pojc+1]==2)
            {
                if (numeros [pojf+1][pojc]==1 )
                {
                    olor = 3;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==1 )
                {
                    olor = 3;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==2 )
                {
                    olor = 2;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==2 )
                {
                    olor = 2;
                    return olor;
                }
                if (numeros [pojf+1][pojc]==3 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc-1]==3 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 2;
                    return olor;
                }
            }
            else
            {
                olor= 2;
                return olor;
            }
        }
    }
    //derecha
    if (pojc<ncol)
    {
        if (numeros [pojf][pojc+1]==2)
        {
            olor =2;
            return olor;
        }
    }
    //izquierda
    if(pojc>0)
    {
        if (numeros [pojf][pojc-1]==2)
        {
            olor =2;
            return olor;
        }
    }
    //galleta arriba
    if (pojf >0)
    {
        if (numeros [pojf-1][pojc]==3)
        {
            if (numeros [pojf+1][pojc]==1)
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
            if (numeros [pojf+1][pojc]==1)
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
            if (numeros [pojf][pojc+1]==1)
            {
                if (numeros [pojf+1][pojc]==2 )
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
            if (numeros [pojf][pojc-1]==1)
            {
                if (numeros [pojf+1][pojc]==2 )
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

            if (numeros [pojf][pojc-1]==2)
            {
                if (numeros [pojf+1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 6;
                    return olor;
                }
            }
            if (numeros [pojf][pojc+1]==2)
            {
                if (numeros [pojf+1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 6;
                    return olor;
                }
            }
            else
            {
                olor= 4;
                return olor;
            }
        }
    }
    //abajo
    if (pojf <nfilas)
    {
        if (numeros [pojf+1][pojc]==3)
        {
            if (numeros [pojf-1][pojc]==1)
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
            if (numeros [pojf-1][pojc]==1)
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
            if (numeros [pojf][pojc+1]==1)
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
            if (numeros [pojf][pojc-1]==1)
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

            if (numeros [pojf][pojc-1]==2)
            {
                if (numeros [pojf-1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 6;
                    return olor;
                }
            }
            if (numeros [pojf][pojc+1]==2)
            {
                if (numeros [pojf-1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                if ( numeros [pojf][pojc+1]==2 )
                {
                    olor = 6;
                    return olor;
                }
                else
                {
                    olor = 6;
                    return olor;
                }
            }
            else
            {
                olor= 4;
                return olor;
            }
        }
    }
    //derecha
    if (pojc< ncol)
    {
        if (numeros [pojf][pojc+1]==3)
        {
            if (numeros [pojf][pojc-1]==2)
            {
                olor =6;
                return olor;
            }
            if (numeros [pojf][pojc-1]==1)
            {
                olor =5;
                return olor;
            }
            else
            {
                olor =4;
                return olor;
            }
        }
    }
    //izquierda

    if (pojc>0)
    {

        if (numeros [pojf][pojc-1]==3)
        {
            if (numeros [pojf][pojc+1]==2)
            {
                olor =6;
                return olor;
            }
            if (numeros [pojf][pojc+1]==1)
            {
                olor =5;
                return olor;
            }
            else
            {
                olor =4;
                return olor;
            }
        }
    }

}
int gameover ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol)

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
int disparar (  int numeros [maxf][maxc], int nfilas, int ncol,int balf,int balc,int contad,int contai,int alienf,int alienc)
{
    bool alienmuerto =false;
    int alienm =0;
    if (contad == 1)
    {
        balc = balc +alienc;

        if ( numeros [balf][balc] == numeros [alienf][alienc])
        {
            alienmuerto = true;
            numeros [balf][balc]=0;
            alienm=1;
            return alienm;
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
            alienm=1;
            return alienm;
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
            alienm=1;
            return alienm;
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
            alienm=1;
            return alienm;
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
            alienm=1;
            return alienm;
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
            alienm=1;
            return alienm;
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
            alienm=1;
            return alienm;
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
            alienm=1;
            return alienm;
        }
        contad=0;
    }
    else
    {
        alienm = 0;
        return alienm;

    }
}

