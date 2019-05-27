/**
El juego consta de un monstruo come galletas que esta en un mundo intentando encontrar su galleta que esta perdida
tiene 2 enemigos los cuales son los abismos y el alien ambos lo pueden matar.
lucas tiene una pistola laser con un solo disparo.
lucas puede detectar el aroma de la galleta, alien y el abismo.
si lucas tiene la galleta tiene que devolverse al punto de origen para poder estar a salvo del alien y poderse comer la galleta.
si lucas cae en un abismo o se encuentra con el alien muere y se acaba la partida.
**/
//juan pablo sanchez gaitan
// Pensamiento 2019-1

//las librerias a utilizar para este proyecto
#include <iostream>
#include <iomanip>
#include "time.h"
#include "stdlib.h"
#include <iomanip>
#include "windows.h"

using namespace std;

//se definen todas las funciones que se van a utilizar para el juego
#define maxc 30
#define maxf 30

void tablerocreado (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);
void tableroaleatorio (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);
void tablerdiabolico (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol);
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol,int alienf,int alienc,int galletf,int galletc,int abisf,int abisc,int contu);
void vistamundo ( char player [maxf][maxc], int numeros [maxf][maxc], int nfilas, int ncol);
int sensacion (  int numeros [maxf][maxc], int nfilas, int ncol,int pojf,int pojc);
int disparar (  int numeros [maxf][maxc], int nfilas, int ncol,int balf,int balc,int contad,int contai,int alienf,int alienc);
//estas funciones no llevan nada adentro debido a que son imagenes en codigo ascii
int gameover ( );
void boom ();
void alienmuerto();
void alienvivo();
void ganaste ();


int main ()
{
    //se definen todas las variables de esta funcion
    int contu =0;
    int filas =0,col=0;
    int numeros[maxf][maxf];//matriz de posiciones de abismos , alien y jugador
    int nfilas =0, ncol=0, opcion=0, respu=0;
    int jugf=0, jugc=0,alienf=0,alienc=0,galletc=0,galletf=0,abisf=0,abisc=0;
    srand(time(NULL));
    char player [maxf][maxc];//matriz de movimientos del jugador,
    // esta es la pantalla de inicio del juego el cual va a mostra en arte ascii una galleta.
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
        system("cls");

// este es el menu de inicio del juego
        cout<<"\t \t \t \t\t\t Bienvenido a EN BUSCA DE LA GALLETA PERDIDA"<<endl;
        cout<<endl;
        cout<<"\t \t \t \t\t\t\t MENU"<<endl;
        cout<<endl;
        cout<<"\t \t \t \t\t 0. JUGAR CON MAPA CREADO"<<endl;
        cout<<"\t \t \t \t\t 1. JUGAR MODO ALEATORIO"<<endl;
        cout<<"\t \t \t \t\t 2. INSTRUCCIONES"<<endl;
        cout<<"\t \t \t \t\t 3. CONTROLES"<<endl;
        cout<<"\t \t \t \t\t 4. ANUNCIOS"<<endl;
        cout<<"\t \t \t \t\t 5. SALIR"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 0:
            // si el jugador le dio a la opcion de 0 aparece este submenu el cual pide el numero de filas y el numero de columnas del mnundo donde van a jugar.
            system("cls");
            cout<<"CREADOR DE MAPA"<<endl;
            cout<<endl;
            // el usuario dijita el numero de filas que va a tener el mundo
            cout<<"Ingrese el numero de filas que desea para el mapa, recuerde que el numero maximo de filas es de "<<maxf<<endl;
            cin>>nfilas;
            cout<<endl;
            //el usuario dijita el numero de columnas que va a tener el mundo
            cout<<"Ingrese el numero de columnas que desea para el mapa, recuerde que el numero maximo de columnas es de "<<maxc<<endl;
            cin>>ncol;
            cout<<endl;
            // se inicia el mundo donde va a estar la unbicacion del alien, abismos y galleta en 0
            for(int i = 0; i<nfilas; i++)
            {
                for(int j = 0; j<ncol; j++)
                {
                    numeros[i][j]= 0;
                }
            }
            //se inicia el mundo que el jugador va a estar viendo .
            for(int i = 0; i<nfilas; i++)
            {
                for(int j = 0; j<ncol; j++)
                {
                    player[i][j]= '-';
                }
            }
//se llama la funcion de tablero creado para que el usuario siga dijitando datos para luego ser utilizados en el juego
            tablerocreado (player, numeros,nfilas,ncol);


            break;
        case 1:
            // si el jugador le dio a mundo aleatorio o opcion 1 todo se va a generar aleatoriamente
            system("cls");

            filas = 1 + rand ()% (maxf);
            col=1 + rand ()% (maxc);
            if (filas >4 && col >4)
            {
                nfilas = filas;
                ncol=col;
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
            }
            system("cls");
//se llama a la funcion de tablero aleatorio el cual
            tableroaleatorio(player, numeros,nfilas,ncol);
            break;

        case 2:
            system("cls");
            //instrucciones del juego

            cout<<"Las instrucciones del juego son las siguientes:"<<endl;
            cout<<endl;

            cout<<" El jugador debe encontrar la galleta por un mapa que el jugador puede crear o elejir la creacion alatoria"<<endl;
            cout<<endl;

            cout<<" Los abismos, el alien y la galleta tienen su olor y sonido respectivo."<<endl;
            cout<<endl;

            cout<<"El abismo persibe una brisa la cual le va a indicar a el jugador que esta cerca a un abismo"<<endl;
            cout<<endl;

            cout<<"Cuando estas cerca al alien vas a percibir una sensacion de frio polar la cual te inidica que estas cerca de el."<<endl;
            cout<<endl;

            cout<<"cuando estas cerca a la galleta vas a percibir un aroma de la galleta la cual te indica que estas cerca a esta misma"<<endl;
            cout<<endl;

            Sleep(1500);
            system("cls");
            break;
        case 3:
            system("cls");
// este es el menu de opciones el cual se descriuben los controles que tiene el jugadopr

            cout<<"CONTROLES DEL JUEGO"<<endl;
            cout<<"Los controles del juego son:"<<endl;
            cout<<endl;
            cout<<"D = Derecha(puedes girar en 4 sentidos)"<<endl;
            cout<<endl;

            cout<<"I = Izquierda(puedes girar en 4 sentidos)"<<endl;
            cout<<endl;

            cout<<"F = Disparo(solo tienes un disparo asi que cuidalo mucho)"<<endl;
            cout<<endl;

            cout<<"R = Recoger galleta ( esta solo se encuentra cuando estas en la misma pocision del la galleta)."<<endl;
            cout<<endl;

            cout<<"C = Comer galleta(esta opcion solo la puedes dar cuando estes en el punto de origen y tengas la galleta puesta"<<endl;
            cout<<endl;

            cout<<"AROMAS = Cada paso que das esta lleno de muchos aromas ten cuidado con lo que te indican los aromas te pueden ayudar:"<<endl;
            Sleep(1500);
            system("cls");
            break;
        case 4:
            system("cls");
            cout<<"ANUNCIOS"<<endl;
            //anuncios del juego

            cout<<endl;

            cout<<"- PROXIMAMENTE SE INCLUIRA UN DLC LLENO DE COSAS LAS CUALES TIENES QUE COMPRAR PARA PODER PASAR DE NIVEL"<<endl;
            cout<<endl;

            cout<<"- PATROCINADOR OFICIAL EA (ELECTRONIC ARTS)"<<endl;
            cout<<endl;

            cout<<"- PARA QUITAR LOS ANUNCIOS EN EL JUEGO PAGA $9.99 AL MES ES UN GRAN OFERTON"<<endl;
            cout<<endl;

            cout<<"- JUEGO PATROCINADO POR LA UNIVERSIDAD JAVERIANA BOGOTA "<<endl;
            cout<<endl;

            cout<<"- PROXIMO DLC INCLUIRA MUSICA Y UN NUEVO NIVEL MAS DIFICIL "<<endl;
            cout<<endl;

            Sleep(1500);
            system("cls");


            break;
        case 66:
            // este es un nivel secreto que solamente cuando ganas podras saber de su existencia
            system("cls");

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
            break;
        }

    }
    while (opcion != 5);
}
void tablerocreado (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{
    //variables que se utilizan en esta funcion
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
    numeros[alienf][alienc]=1;//ell alien se idica con un uno
    //se le pregunta al usuario la ubicacion de la galleta
    cout<<"En que filas vas a poner la galleta?"<<endl;
    cin>>galletf;
    cout<<"en que columna vas a poner la galleta?"<<endl;
    cin>>galletc;
    numeros[galletf][galletc]=3;// la galleta se indica con un tres
//el usuario indica cuantos abismos va a poner en el mapa
    cout<<"cuantos abismos va a poner recuerde que debe ser menos a "<<ret<<endl;
    cin>>abis;
    int k=0,abisf=0,abisc=0;
    do
    {
        k++;
        // aca se ponen los abismos y se repite a medida de que el contador sea menor a los abismos
        cout<<"Ingrese la fila del "<<k<<" abismo"<<endl;
        cin>>abisf;
        cout<<"ingrese la columna del "<<k<<" abismo"<<endl;
        cin>>abisc;
        //si la posicion del abismo es distinto al de la galleta se ejecuta esta opcion
        if (numeros[galletf][galletc] !=  numeros[abisf][abisc])
        {

            numeros[abisf][abisc]=2;//el abismo se indica con un dos

        }
        //si la posicion del abismo es igual al de la galleta se ejecuta esta opcion
        if (numeros[galletf][galletc] ==  numeros[abisf][abisc])
        {
//si el usuario dijita una posicion igual a la de la galleta le sale etse mensaje
            cout<<"Ingresa un valor ditinto al valor de la galleta"<<endl;
        }
        contu =k;

    }
    while(k<abis);

    system("cls");
    // aca se muestran las instrucciones del juego como pantalla de carga para que el jugador este informado de las cosas que puede hacer.
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
    system("cls");

    cout<<"\t \t \t \t\t ######  #######    #    ######  #     # "<<endl;
    cout<<"\t \t \t \t\t #     # #         # #   #     #  #   #  "<<endl;
    cout<<"\t \t \t \t\t #     # #        #   #  #     #   # #   "<<endl;
    cout<<"\t \t \t \t\t ######  #####   #     # #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #   #   #       ####### #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #    #  #       #     # #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #     # ####### #     # ######     # "<<endl;
    cout<<endl;
    Sleep (1500);
    system("cls");

    cout<<"\t \t \t \t\t ######  #          #    #     #    "<<endl;
    cout<<"\t \t \t \t\t #     # #         # #    #   #  "<<endl;
    cout<<"\t \t \t \t\t #     # #        #   #    # #        "<<endl;
    cout<<"\t \t \t \t\t ######  #       #     #    #         "<<endl;
    cout<<"\t \t \t \t\t #       #       #######    #           "<<endl;
    cout<<"\t \t \t \t\t #       #       #     #    #           "<<endl;
    cout<<"\t \t \t \t\t #       ####### #     #    #  "<<endl;
    cout<<endl;
    Sleep (1500);
    system("cls");
    cout<<"NIVEL CREADO"<<endl;
    cout<<endl;

//se llama a la funcion de jugador con la cual empieza a jugar
    jugador (player,numeros,nfilas,ncol,alienf,alienc,galletf,galletc,abisf,abisc,contu);

}
void tablerdiabolico (char player [maxf][maxc],int numeros[maxf][maxf], int nfilas, int ncol)
{
    //se declaran todas las variables que se van a utilizar en la creacion del mapa soy la muerte encarnada
    int abis=0,alienf=0,alienc=0,multi=0,ret=0,filas=0,col=0;
    int jugf=0, jugc=0;// el jugador empieza en la posicion 0,0
    player[jugf][jugc]='L';
    numeros[jugf][jugc]= 5;
    int galletf=0,galletc=0,contu =0;
    bool poss=false;
    multi = nfilas* ncol;
    ret = multi/2;
    // poricion aleatoria del alien
    alienf =  0 + rand ()% (nfilas);
    alienc =  0 + rand ()% (ncol);
    // aca comprueba que la posicion que se puso en aleatorio sea diferente a la posicion del jugador en su inisio.
    if (    numeros[alienf][alienc]!= numeros[jugf][jugc] )
    {
        numeros[alienf][alienc]=1;
    }
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

// se comprueba que la posicion aleatoria del abismo sea diferente a la del jugador y la de la galleta
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

    // aca se muestran las instrucciones del juego como pantalla de carga para que el jugador este informado de las cosas que puede hacer.

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
    system("cls");

    cout<<"\t \t \t \t\t ######  #######    #    ######  #     # "<<endl;
    cout<<"\t \t \t \t\t #     # #         # #   #     #  #   #  "<<endl;
    cout<<"\t \t \t \t\t #     # #        #   #  #     #   # #   "<<endl;
    cout<<"\t \t \t \t\t ######  #####   #     # #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #   #   #       ####### #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #    #  #       #     # #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #     # ####### #     # ######     # "<<endl;
    cout<<endl;
    Sleep (1500);
    system("cls");

    cout<<"\t \t \t \t\t ######  #          #    #     #    "<<endl;
    cout<<"\t \t \t \t\t #     # #         # #    #   #  "<<endl;
    cout<<"\t \t \t \t\t #     # #        #   #    # #        "<<endl;
    cout<<"\t \t \t \t\t ######  #       #     #    #         "<<endl;
    cout<<"\t \t \t \t\t #       #       #######    #           "<<endl;
    cout<<"\t \t \t \t\t #       #       #     #    #           "<<endl;
    cout<<"\t \t \t \t\t #       ####### #     #    #  "<<endl;
    cout<<endl;
    Sleep (1500);
    system("cls");

    cout<<"ENTRASTE AL NIVEL !SOY LA MUERTE ENCARNADA!"<<endl;
    cout<<endl;
//se llama a la funcion de jugador con la cual empieza a jugar

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
    //se comprueba que la posicion del alien sea distinta al punto de origen del jugador
    if (    numeros[alienf][alienc]!= numeros[jugf][jugc] )
    {
        numeros[alienf][alienc]=1;
    }
    //posicion aleatoria de la galleta
    galletf=0 + rand ()% (nfilas);
    galletc =0 + rand ()% (ncol);
    //comprovacion que la posicion aleatoria de la galleta sea distinta al punto de origen del jugador
    if (numeros[galletf][galletc]!= numeros[jugf][jugc] )
    {
        numeros[galletf][galletc]=3;
    }
    abis =  0 + rand ()% (ret);
    int k =0,abisf=0,abisc=0;
    do
    {
        k++;
        abisf =  0 + rand ()% (nfilas);
        abisc =  0 + rand ()% (ncol);
        contu = k;
        // se comprueba que la posicion aleatoria del abismo sea diferente a la del jugador y la de la galleta

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
    // aca se muestran las instrucciones del juego como pantalla de carga para que el jugador este informado de las cosas que puede hacer.

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
    system("cls");
//pantalla de carga para entrar a jugar
    cout<<"\t \t \t \t\t ######  #######    #    ######  #     # "<<endl;
    cout<<"\t \t \t \t\t #     # #         # #   #     #  #   #  "<<endl;
    cout<<"\t \t \t \t\t #     # #        #   #  #     #   # #   "<<endl;
    cout<<"\t \t \t \t\t ######  #####   #     # #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #   #   #       ####### #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #    #  #       #     # #     #    #    "<<endl;
    cout<<"\t \t \t \t\t #     # ####### #     # ######     # "<<endl;
    cout<<endl;
    Sleep (1500);
    system("cls");

    cout<<"\t \t \t \t\t ######  #          #    #     #    "<<endl;
    cout<<"\t \t \t \t\t #     # #         # #    #   #  "<<endl;
    cout<<"\t \t \t \t\t #     # #        #   #    # #        "<<endl;
    cout<<"\t \t \t \t\t ######  #       #     #    #         "<<endl;
    cout<<"\t \t \t \t\t #       #       #######    #           "<<endl;
    cout<<"\t \t \t \t\t #       #       #     #    #           "<<endl;
    cout<<"\t \t \t \t\t #       ####### #     #    #  "<<endl;
    cout<<endl;
    Sleep (1500);
    system("cls");
    cout<<"NIVEL ALEATORIO TODO PUEDE PASAR"<<endl;
    cout<<endl;

//se llama a la funcion de jugador con la cual empieza a jugar
    jugador (player,numeros,nfilas,ncol,alienf,alienc,galletf,galletc,abisf,abisc,contu);
}
void vistamundo (char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol)
{
    // esta funcion imprime el mundo del jugador pero sin los abismos, alien y la galleta solo muestra la posicion del jugador.
    for(int i=0; i<nfilas; i++)
    {

        for (int j=0; j<ncol; j++)
        {
            cout<<setw(3.5)<<player[i][j]<<'|';
        }
        cout<<endl;
    }
}
void jugador ( char player [maxf][maxc],int numeros[maxf][maxc], int nfilas, int ncol,int alienf,int alienc,int galletf,int galletc,int abisf,int abisc,int contu)
{
    // aca se encuentran todas las variables que se utilizaron para jugar
    int k=0,muertos=0;
    int alienm=0;
    int olor =0;
    int contad =0,contai =0;
    int pojf=0,pojc=0,balf=0,balc=0;
    char opcion;
    string alienfu;
    string bala;
    string aroma;
    string muro;
    string galletano;
    bool laser = true;
    bool galletacu = false;
    bool pared = false;
    bool galleta = false;
    bool muerto = false;
    bool balas = true;
    do
    {
        vistamundo (player,numeros,nfilas,ncol);
// menu de juego
        cout<<endl;
        cout<<"\t \t \t Ingrese un movimiento o accion"<<endl;
        cout<<"\t \t \t GIRAR A LA DERECHA = D"<<endl;
        cout<<"\t \t \t GIRAR IZQUIERDA = I"<<endl;
        cout<<"\t \t \t AVANZAR = A"<<endl;
        // si tiene el laser aparece disparar si no lo tiene desaparece esta opcion y se pone en falso.
        if (laser == true)
        {
            cout<<"\t \t \t DISPARAR = F"<<endl;
        }
        // aca se muesnta que se utilizo el laser.
        if (laser == false)
        {
            cout<<"\t \t \t SONIDO: "<<alienfu<<endl;

        }
        //si el jugador le da a la f por 2 vez
        if (balas == false)
        {
            cout<<"\t \t \t "<<bala<<endl;
        }
        // si el jugador esta en la misma posicion de la galleta aparece esta opcion la cual le da al jugador que recoja la galleta
        if (numeros[pojf][pojc]==numeros[galletf][galletc] )
        {
            cout<<"\t \t \t RECOGER GALLETA = R"<<endl;
        }
        if (galletacu == true )
        {
            cout<<"\t \t \t "<<galletano<<endl;
            galletacu= false;
        }
        // si tiene la galleta en sus manos este mensaje le va a aparecer al jugador
        if(galleta == true)
        {
            cout<<"\t \t \t "<<galletano<<endl;

            // si el jugador esta en la posicion de inicio le va a aparecer este mensaje el cual es comer galleta con este mensaje se termina e l juego.
            if (numeros[pojf][pojc]==numeros[0][0] )
            {
                cout<<"\t \t \t COMER GALLETA = C"<<endl;
            }

        }
        //aca se comprueba el valor que retorna la funcion sensacion y es evaluado para luego ser escrito en el menu de aromas.
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
        cout<<"\t \t \t AROMA = "<<aroma<<endl;
        // aca se imprime cuando el jugador esta en un muro
        if (pared == true)
        {
            cout<<"\t \t \t "<<muro<<endl;
            pared = false;
        }
        cin>>opcion;
        // giro de la derecha
        if (opcion == 'd'||opcion ==  'D')
        {
            contad++;
            // si el jugador presiono una vez la d significa que va a la derecha
            if (contad == 1)
            {
                player [pojf][pojc]='D';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            // si el jugador presiono dos veces la D significa que va para abajo
            if (contad == 2)
            {
                player [pojf][pojc]='B';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            // si el jugador le dio 3 veces a la D significa que va para la izquierda
            if (contad == 3)
            {
                player [pojf][pojc]='I';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            // si el jugador le deio 4 veces a la D significa que va para arriba
            if (contad == 4)
            {
                player [pojf][pojc]='A';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            system("cls");
        }
        // giro de la izquierda
        if (opcion == 'i'|| opcion == 'I')
        {
            contai++;
            // si el jugado le dio 1 vez a la I significa que va para la izquierda
            if (contai == 1)
            {
                player [pojf][pojc]='I';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            // si el jugador le dio 2 veces a la I significa que va para abajo
            if (contai == 2)
            {
                player [pojf][pojc]='B';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            // si el jugador le dio 3 veces a la I significa que va a la derecha
            if (contai == 3)
            {
                player [pojf][pojc]='D';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

            }
            // si el jugador le dio 4 veces a la I significa que va para arriba
            if (contai == 4)
            {
                player [pojf][pojc]='A';
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
            }
            system("cls");
        }
        // si la opcion es a significa que va a avanzar las posiciones del contador si es D o I.
        if (opcion == 'a' || opcion ==  'A')
        {
            //si el conatdor de la derecha indica un uno va para la derecha
            if (contad == 1)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojc = pojc +1;
                // se comprueba que no este en un muro o este en la misma posicion del alien o de un abismo.
                if ( numeros [pojf][pojc]== 2)
                {
                    //si esta en la misma posicion del abismo se llama a la funcion gameover la cual termina el juego
                    gameover ();
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    //si esta en la misma posicion del alien se llama a la funcion gameover la cual termina el juego

                    gameover ();
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
//si el contador de la derecha indica un dos va para abajo
            if (contad == 2)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojf = pojf +1;
                // se comprueba que no este en un muro o este en la misma posicionde un alien o un abismo.

                if ( numeros [pojf][pojc]== 2)
                {
                    //si esta en la misma posicion del abismo se llama a la funcion gameover la cual termina el juego

                    gameover ();
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    //si esta en la misma posicion del alien se llama a la funcion gameover la cual termina el juego

                    gameover ();
                }
                if (pojf == nfilas)
                {
                    // si el jugador se mueve hacia un muro este se va a quedar en la misma posicion y le va a indicar que esta sobre un muro.

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
            //si el contador de la derecha indica tres va para la izquierda
            if (contad == 3)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojc = pojc -1;
                // se comprueba que no este en un muro o este en la misma posicionde un alien o un abismo.

                if ( pojc == -1)
                {
                    // si el jugador se mueve hacia un muro este se va a quedar en la misma posicion y le va a indicar que esta sobre un muro.
                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='I';
                    numeros[pojf][pojc] = 5;
                    pojc = pojc +1;
                }
                if ( numeros [pojf][pojc]== 2)
                {
                    //si esta en la misma posicion del abismo se llama a la funcion gameover la cual termina el juego

                    gameover ();
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ();
                }

                player [pojf][pojc]='I';
                numeros [pojf][pojc]=5;

                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contad=0;


            }
            //si el contador de la derecha indica cuatro va para arriba
            if (contad == 4)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojf = pojf -1;
                // se comprueba que no este en un muro o este en la misma posicionde un alien o un abismo.

                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ();
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ();
                }
                if ( pojf == -1)
                {
                    // si el jugador se mueve hacia un muro este se va a quedar en la misma posicion y le va a indicar que esta sobre un muro.

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
            //si el contador de la izquierda indica uno va para la izquierda
            if (contai == 1)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojc = pojc -1;
                // se comprueba que no este en un muro o este en la misma posicionde un alien o un abismo.

                if ( pojc == -1)
                {
                    // si el jugador se mueve hacia un muro este se va a quedar en la misma posicion y le va a indicar que esta sobre un muro.

                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='I';
                    numeros[pojf][pojc] = 5;
                    pojc = pojc +1;
                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ();
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ();
                }
                player [pojf][pojc]='I';
                numeros [pojf][pojc]=5;

                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contai=0;



            }
            //si el contador de la izquierda indica 2 va para abajo
            if (contai == 2)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojf = pojf +1;
                // se comprueba que no este en un muro o este en la misma posicionde un alien o un abismo.

                if ( pojf == nfilas)
                {
                    // si el jugador se mueve hacia un muro este se va a quedar en la misma posicion y le va a indicar que esta sobre un muro.

                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='B';
                    numeros[pojf][pojc] = 5;
                    pojf = pojf -1;
                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ();
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ();
                }

                player [pojf][pojc]='B';
                numeros [pojf][pojc]=5;
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

                contai=0;



            }
            //si el contador de la izquierda indica un tres va para la derecha
            if (contai == 3)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojc = pojc +1;
                // se comprueba que no este en un muro o este en la misma posicionde un alien o un abismo.

                if ( pojc == ncol)
                {
                    // si el jugador se mueve hacia un muro este se va a quedar en la misma posicion y le va a indicar que esta sobre un muro.

                    player [pojf][pojc]='D';
                    numeros[pojf][pojc] = 5;
                    pojc = pojc -1;
                    muro = "Te chocaste con el muro";
                    pared = true;

                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ();
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ();
                }
                player [pojf][pojc]='D';
                numeros [pojf][pojc]=5;
                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);
                contai=0;


            }
            //el contador de la izquierda si es 4 indica que va para arriba
            if (contai == 4)
            {
                player [pojf][pojc]='-';
                numeros[pojf][pojc] = 0;
                pojf = pojf -1;
                // se comprueba que no este en un muro o este en la misma posicionde un alien o un abismo.

                if ( pojf == -1)
                {
                    // si el jugador se mueve hacia un muro este se va a quedar en la misma posicion y le va a indicar que esta sobre un muro.

                    muro = "Te chocaste con el muro";
                    pared = true;

                    player [pojf][pojc]='A';
                    numeros[pojf][pojc] = 5;
                    pojf = pojf +1;
                }
                if ( numeros [pojf][pojc]== 2)
                {
                    gameover ();
                }
                if ( numeros [pojf][pojc]== 1)
                {
                    gameover ();
                }
                player [pojf][pojc]='A';
                numeros [pojf][pojc]=5;

                olor =  sensacion (    numeros,  nfilas, ncol,pojf,pojc);

                contai=0;


            }
            system("cls");

        }



// si la opcion es f significa que dispara el rayo laser en la posicion en la que este mirando.
        if (opcion =='f' || opcion == 'F')
        {
            if (laser == true)
            {
                system("cls");
                balf = pojf;
                balc = pojc;
                // la funcion disparar retorna un numero el cula determina si mato o no al alien y se le notifica al jugador con un mensaje.
                alienm = disparar (numeros,nfilas,ncol,balf,balc,contad,contai,alienf,alienc);
                laser = false;
//si el numero que regresa de la funcion disparo es un uno o un cero se activan estas dos opciones las cuales una es caundo lo mata y la otra es cuando falla
                if (alienm == 1)
                {
                    boom();
                    alienfu = "HEADSHOOT *Sonidos de agonia en algun punto del mapa*";
                    alienmuerto();
                }
                if(alienm == 0)
                {
                    boom();
                    alienfu ="No se escucha ningun sonido";
                    alienvivo();
                }

            }
            //si el jugador le da mas a la f le aparece este mensaje
            if (laser == false)
            {
                balas = false;
                bala = "YA NO TIENES MAS BALAS";
            }

        }
// si la opcion es r significa que el jugador puede estar en la posicion de la galleta
        if (opcion == 'r' || opcion == 'R')
        {
            system("cls");
            if (numeros [pojf][pojc]== numeros[galletf][galletc])
            {
                // si esta en la posicion de la galleta retorna un booleano el cual es verdadero haciendo que cuando llegue al punto de origen se la pueda comer
                galletano = "Tienes la galleta en tus manos ";
                galleta =true;
            }
            if (numeros [pojf][pojc] != numeros[galletf][galletc])
            {
                // si le dio a la opcion r y no esta en la misma posicion de la galleta le va a indicar que no tiene la galleta
                galletano = "Todavia no has encontrado la galleta";
                galletacu =true;
            }
        }
        //opcion de organizador donde puede ver todo el mapa con la ubicacion del jugador junto a la ubicacion de loas abismos , alien y
        if (opcion == 'p' ||opcion ==  'P')
        {
            system("cls");
            for(int i=0; i<nfilas; i++)
            {
                for (int j=0; j<ncol; j++)
                {
                    cout<<setw(3.5)<<numeros[i][j];
                }
                cout<<endl;
            }
        }
        //esta es la opcion de comer galleta esta se avilita cuando esta en el origen y tiene la galleta puesta
        if (opcion == 'c' ||opcion == 'C')
        {
            if(galleta == true)
            {
                ganaste ();
            }
        }
    }
    while (muerto == false);
}
int sensacion (  int numeros [maxf][maxc], int nfilas, int ncol,int pojf,int pojc)
{
    int olor=0;
//olor del alien
    //alien arriba
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
    // alien abajo
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
    // alien izquierda
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
    //alien derecha
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
    //olor abismno
    //abismo abajo
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
    //abismo derecha
    if (pojc<ncol)
    {
        if (numeros [pojf][pojc+1]==2)
        {
            olor =2;
            return olor;
        }
    }
    //abismo izquierda
    if(pojc>0)
    {
        if (numeros [pojf][pojc-1]==2)
        {
            olor =2;
            return olor;
        }
    }

    //galleta aromas
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
    //galleta abajo
    if (pojf <nfilas)
    {
        if (numeros [pojf+1][pojc]==3)
        {
            //alien arriba
            if (numeros [pojf-1][pojc]==1)
            {
                // abismo derecha
                if (numeros [pojf][pojc+1]==2 )
                {
                    olor = 7;
                    return olor;
                }
                //abismo izquierda
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
            // alien derecha

            if (numeros [pojf][pojc+1]==1)
            {
                //abismo arriba
                if (numeros [pojf-1][pojc]==2 )
                {
                    olor = 7;
                    return olor;
                }
                //abismo izquierda
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
            // alien izquierda
            if (numeros [pojf][pojc-1]==1)
            {
                //abismo arriba
                if (numeros [pojf-1][pojc]==2 )
                {
                    olor = 7;
                    return olor;
                }
                //abismo derecha
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
//abismo izquierda
            if (numeros [pojf][pojc-1]==2)
            {
                //abismo arriba
                if (numeros [pojf-1][pojc]==2 )
                {
                    olor = 6;
                    return olor;
                }
                //abismo derecha
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
            //abismo derecha
            if (numeros [pojf][pojc+1]==2)
            {
                //abism
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
    // galleta derecha
    if (pojc< ncol)
    {
        if (numeros [pojf][pojc+1]==3)
        {
            // abismo izquierda
            if (numeros [pojf][pojc-1]==2)
            {
                olor =6;
                return olor;
            }
            //alien izquierda
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
    //galleta izquierda

    if (pojc>0)
    {

        if (numeros [pojf][pojc-1]==3)
        {
            //abismo derecha
            if (numeros [pojf][pojc+1]==2)
            {
                olor =6;
                return olor;
            }
            //alien derecha
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
int gameover ()

{
    system("cls");
    cout<<endl;
    cout<<endl;

    cout << "\t \t \t \t@@@@@@@@@@@@@@@@((((((((((@@@@@@@((((((((((@@@@@@@@@@@@@@@@"    << endl;
    cout << "\t \t \t \t@@@@@@@@@@@@@((((((@@@@@@@@@@@@@@@@@@@@@((((((@@@@@@@@@@@@@"    << endl;
    cout << "\t \t \t \t&@@@@@@@@@(((((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(((((@@@@@@@@@@"    << endl;
    cout << "\t \t \t \t@@@@@@@@((((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@((((@@@@@@@@"    << endl;
    cout << "\t \t \t \t@@@@@@((((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@((((@@@@@&"    << endl;
    cout << "\t \t \t \t@@@@@(((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(((@@@@@"    << endl;
    cout << "\t \t \t \t@@@/(((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(((/@@@"    << endl;
    cout << "\t \t \t \t&@(((@@@@@@@@/(((@@@@@((((@@@@@@@%(((@@@@@(((*@@@@@@@((((@@"    << endl;
    cout << "\t \t \t \t@#(((@@@@@@@@@@((((@((((@@@@@@@@@@@((((@((((@@@@@@@@@@(((#@"    << endl;
    cout << "\t \t \t \t@(((@@@@@@@@@@@@@(((((@@@@@@@@@@@@@@@(((((@@@@@@@@@@@@@(((%"    << endl;
    cout << "\t \t \t \t(((@@@@@@@@@@@@@(((((((@@@@@@@@@@@@@(((((((@@@@@@@@@@@@@((("    << endl;
    cout << "\t \t \t \t(((@@@@@@@@@@@((((@@@((((@@@@@@@@@((((@@@((((@@@@@@@@@@@((("    << endl;
    cout << "\t \t \t \t((@@@@@@@@@@@@@(@@@@@@@(@@@@@@@@@@@(@@@@@@@(@@@@@@@@@@@@@(("    << endl;
    cout << "\t \t \t \t((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(("    << endl;
    cout << "\t \t \t \t((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(("    << endl;
    cout << "\t \t \t \t((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(("    << endl;
    cout << "\t \t \t \t(((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@((("    << endl;
    cout << "\t \t \t \t(((@@@@@@@@@@@@@@(((((((((((((((((((((((((((@@@@@@@@@@@@((("    << endl;
    cout << "\t \t \t \t@(((@@@@@@@@@@@@@@@@@@@@@@@@@@((@@@@@@@@@(((@@@@@@@@@@@(((@"    << endl;
    cout << "\t \t \t \t@@(((@@@@@@@@@@@@@@@@@@@@@@@@@((@@@@@@@@@(((@@@@@@@@@@(((@@"    << endl;
    cout << "\t \t \t \t@@/(((@@@@@@@@@@@@@@@@@@@@@@@@((@@@@@@@@@(((@@@@@@@@@(((/@&"    << endl;
    cout << "\t \t \t \t@@@@(((@@@@@@@@@@@@@@@@@@@@@@@(((@@@@@@@(((@@@@@@@@@(((@@@@"    << endl;
    cout << "\t \t \t \t@@@@@(((*@@@@@@@@@@@@@@@@@@@@@@(((((@(((((@@@@@@@@*(((@@@@@"    << endl;
    cout << "\t \t \t \t&@@@@@*(((@@@@@@@@@@@@@@@@@@@@@@@(((((((@@@@@@@@@(((@@@@@@@"    << endl;
    cout << "\t \t \t \t@@@@@@@@((((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%((((@@@@@@@@"    << endl;
    cout << "\t \t \t \t@@@@@@@@@@@((((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@((((@@@@@@@@@@@"    << endl;
    cout << "\t \t \t \t@@@@@@@@@@@@@((((((@@@@@@@@@@@@@@@@@@@@@((((((@@@@@@@@@@@@@"    << endl;
    cout << "\t \t \t \t@@@@@@@@@@@@@@@@@(((((((((((((((((((((((((@@@@@@@@@@@@@@@@@"    << endl;
    cout<<endl;
    cout<<endl;
    cout << "\t \t \t \t\t  _____      ___       ___  ___   _____"    << endl;
    cout << "\t \t \t \t\t / ___ |    /   |     /   |/   | |  ___|"  << endl;
    cout << "\t \t \t \t\t| |        / /| |    / /|   /| | | |__"    << endl;
    cout << "\t \t \t \t\t| |  _    / ___ |   / / |__/ | | |  __|"   << endl;
    cout << "\t \t \t \t\t| |_| |  / /  | |  / /       | | | |___"   << endl;
    cout << "\t \t \t \t\t\\_____/ /_/   |_| /_/        |_| |_____|"  << endl;
    cout << "\t \t \t \t\t _____   _     _   _____   _____"          << endl;
    cout << "\t \t \t \t\t/  _  \\ | |   / / |  ___| |  _   \\ "        << endl;
    cout << "\t \t \t \t\t| | | | | |  / /  | |__   | |_|  |"         << endl;
    cout << "\t \t \t \t\t| | | | | | / /   |  __|  |  _   /"         << endl;
    cout << "\t \t \t \t\t| |_| | | |/ /    | |___  | | \\  \\  "        << endl;
    cout << "\t \t \t \t\t\\_____/ |___/     |_____| |_|  \\ _\\ "       << endl;
    cout << endl << endl;
    cout << endl << endl;
    exit(0);
}
//funcion de disparo
int disparar (  int numeros [maxf][maxc], int nfilas, int ncol,int balf,int balc,int contad,int contai,int alienf,int alienc)
{
    //variables
    bool alienmuerto =false;
    int alienm =0;
    int posc =0,posf =0,pc=0,pf=0;
    int k=0;
    posc= balc;
    posf = balf;
//depende a la opcion que de el jugador se activa una de esas opciones
//con cada opcion se desplaza por la matriz depende con el dontador de D o I
    if (contad == 1)
    {
        do
        {
            pc = posc + k;//don esto recorre la matris con las columnas
            if ( numeros [balf][pc] == 1)
            {
                alienmuerto = true;
                numeros [balf][pc]=0;
                alienm=1;
                return alienm;
            }
            k++;
        }
        while(pc<ncol);
    }
    if (contad == 2)
    {
        do
        {

            pf = posf + k;//con esto recorre la matriz con la fila y se queda en la misma columna

            if ( numeros [pf][balc]==1)
            {
                alienmuerto = true;
                numeros [pf][balc]=0;
                alienm=1;
                return alienm;
            }
            k++;
        }
        while (pf<nfilas);



    }

    if (contad == 3)
    {
        do
        {

            pc = posc - k;//RECORRIDO DE LA MATRIZ HACIA LA IZQUIERDA
            if ( numeros [balf][pc]== 1)
            {
                alienmuerto = true;
                numeros [balf][pc]=0;
                alienm=1;
                return alienm;
            }
            k++;
        }
        while (pc > 0);


    }

    if (contad == 4)
    {
        do
        {

            posf = k - 1;//recorre la matriz hacia arriba sin camboar de columna

            if ( numeros [balf][posc]== numeros [alienf][alienc])
            {
                alienmuerto = true;
                numeros [balf][balc]=0;
                alienm=1;
                return alienm;
            }
            k++;
        }
        while (pc > 0);
    }

    if (contai == 1)
    {
        do
        {
            pc = posc - k;
            if ( numeros [balf][pc]== 1)
            {
                alienmuerto = true;
                numeros [balf][pc]=0;
                alienm=1;
                return alienm;
            }
            k++;
        }
        while (pc > 0);


    }

    if (contai == 2)
    {
        do
        {

            pf = posf + k;

            if ( numeros [pf][balc]==1)
            {
                alienmuerto = true;
                numeros [pf][balc]=0;
                alienm=1;
                return alienm;
            }
            k++;
        }
        while (pf<nfilas);

    }

    if (contai == 3)
    {
        do
        {
            pc = posc + k;
            if ( numeros [balf][pc] == 1)
            {
                alienmuerto = true;
                numeros [balf][pc]=0;
                alienm=1;
                return alienm;
            }
            k++;
        }
        while(pc<ncol);
    }

    if (contai == 4)
    {
        do
        {
            posf = k - 1;

            if ( numeros [balf][posc]== numeros [alienf][alienc])
            {
                alienmuerto = true;
                numeros [balf][balc]=0;
                alienm=1;
                return alienm;
            }
            k++;
        }
        while (pc > 0);

    }
    else
    {
        alienm = 0;
        return alienm;

    }
}
void boom ( )
{
    //pantalla cuando dispara la pistola laser
    cout<<"\t \t \t \t\t######  ####### ####### #     # ### ### ###"<<endl;
    cout<<"\t \t \t \t\t#     # #     # #     # ##   ## ### ### ### "<<endl;
    cout<<"\t \t \t \t\t#     # #     # #     # # # # # ### ### ### "<<endl;
    cout<<"\t \t \t \t\t######  #     # #     # #  #  #  #   #   #  "<<endl;
    cout<<"\t \t \t \t\t#     # #     # #     # #     #             "<<endl;
    cout<<"\t \t \t \t\t#     # #     # #     # #     # ### ### ### "<<endl;
    cout<<"\t \t \t \t\t######  ####### ####### #     # ### ### ### "<<endl;
    Sleep(1500);
    system("cls");

}
void ganaste()
{
    //pantalla cuando ya estas en el origen y te comes la galleta
    string nombre;
    system("cls");
    cout<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@@@@@@@@@        #@@@/  @@@@/ ,@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@@@@@@@(           @   ,@@@@&   @@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@@@@@@@             ,     .     .@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@@@@@@@     .       /           ,@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@@@%&@@   @@@@@    #            %######@@@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@@######@ @@@@@   @##@        @###########@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@&%#########@&%@########%%###############&@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@################################################&@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@#########################@##############@#@@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@##&@########@#####@@#@@@@@@@@@@@##@@@@@@@#######@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@#####&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#########@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@%#######@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##########%@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@########@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#########@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@########@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#########@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@########@@@@@@@@@@@@@@@@@@@@@@@@@@@#########@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@#@@########@@@@@@@@@@@@@@@@@@@@@@@@@########@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@##########@%%&@@@@@%*%@@@@@@&@@#########%@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@%####%***************/****%##########%###@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@###%%##%*********%#(*******##****(%%#*%@#######@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@#########%***#(******%%#********************#######@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@########%***%##******************************@@#####@@@@"<<endl;
    cout<<"\t \t \t \t\t@%#####@#%%******************************%###***###%@####@@"<<endl;
    cout<<"\t \t \t \t\t@####@####&******************************%%###**@#####%###@"<<endl;
    cout<<"\t \t \t \t\t####@#######@/***************%#/*************%%#######@###&"<<endl;
    cout<<"\t \t \t \t\t@############@##*************************/%#######@@###@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@###%@%######@****************************#@@&@@%#####@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@########&@(******************************%@#######%##@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@##########/********%##*********####***&%#####&##@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@####@@@&@&***********%%/*********%###****@@&%######@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@%#########@(/*******************%%*****//@#####%@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@####@@@###***********************/////&@@####@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@######%@/%%%/*********************//////@#####@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@&%&@@@%///////*********###****//////#&&@@@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@@@@@@&&%/////////////%##%/////////%&&&@@@@@@@@@@@@"<<endl;
    cout<<"\t \t \t \t\t@@@@@@@@@@@@@@&&&&&%/////////////////////%&&&&&@@@@@@@@@@@@"<<endl;
    cout<<endl;

    cout<<endl;

    cout<<"\t \t \t \t\t     _____                       _ "<<endl;
    cout<<"\t \t \t \t\t    / ____|                     | |     "<<endl;
    cout<<"\t \t \t \t\t   | |  __  __ _ _ __   __ _ ___| |_ ___ "<<endl;
    cout<<"\t \t \t \t\t   | | |_ |/ _` | '_ \\ / _` / __| __/ _ \\ "<<endl;
    cout<<"\t \t \t \t\t   | |__| | (_| | | | | (_| \\__ \ ||  ___/ "<<endl;
    cout<<"\t \t \t \t\t    \\_____|\\__,_|_| |_|\\__,_|___/\\__\\___| "<<endl;
    cout<<"\t \t \t \t\t                                         "<<endl;
    cout<<endl;
    //se le da la ubicacion del nivel secreto del juego
    cout<<"\t \t  YA QUE GANASTE ESTA PARTIDA EN EL MENU DE INICIO DEL JUEGO DIJITA 66 PARA ENTRAR A UN NUEVO NIVEL"<<endl;
    cout<<"\t \t \t \t\t\t\tINGRESA TU NOMBRE"<<endl;
    cin>>nombre;
    cout<<"\t \t \t \t\t\t\t TABLA DE GANADORES"<<endl;
    cout<<"\t \t \t \t\t\t\t\t "<<nombre<<endl;
    cout<<"\t \t \t \t\t\t\t ..................."<<endl;
    cout<<endl;
    cout<<endl;
    system("pause");
    exit(0);
}
void alienmuerto()
{
    //pantalla cuando mata al alien
    cout<<"\t \t \t  ______   _______  _______  ______     _______  ___      ___   _______  __    _ "<<endl;
    cout<<"\t \t \t |      | |       ||   _   ||      |   |   _   ||   |    |   | |       ||  |  | |"<<endl;
    cout<<"\t \t \t |  _    ||    ___||  |_|  ||  _    |  |  |_|  ||   |    |   | |    ___||   |_| |"<<endl;
    cout<<"\t \t \t | | |   ||   |___ |       || | |   |  |       ||   |    |   | |   |___ |       |"<<endl;
    cout<<"\t \t \t | |_|   ||    ___||       || |_|   |  |       ||   |___ |   | |    ___||  _    |"<<endl;
    cout<<"\t \t \t |       ||   |___ |   _   ||       |  |   _   ||       ||   | |   |___ | | |   |"<<endl;
    cout<<"\t \t \t |______| |_______||__| |__||______|   |__| |__||_______||___| |_______||_|  |__|"<<endl;
    cout<<endl;
    Sleep(1500);
    system("cls");

}
void alienvivo ()
{
    //pantalla cuando el jugador nmo le da al alien
    cout<<"\t \t \t  __   __  _______    _______  _______  ___   ___      ___        _______  ___      ___   __   __  _______ "<<endl;
    cout<<"\t \t \t |  | |  ||       |  |       ||       ||   | |   |    |   |      |   _   ||   |    |   | |  | |  ||       |"<<endl;
    cout<<"\t \t \t |  |_|  ||    ___|  |  _____||_     _||   | |   |    |   |      |  |_|  ||   |    |   | |  |_|  ||    ___|"<<endl;
    cout<<"\t \t \t |       ||   |___   | |_____   |   |  |   | |   |    |   |      |       ||   |    |   | |       ||   |___ "<<endl;
    cout<<"\t \t \t |       ||    ___|  |_____  |  |   |  |   | |   |___ |   |___   |       ||   |___ |   | |       ||    ___|"<<endl;
    cout<<"\t \t \t |   _   ||   |___    _____| |  |   |  |   | |       ||       |  |   _   ||       ||   |  |     | |   |___ "<<endl;
    cout<<"\t \t \t |__| |__||_______|  |_______|  |___|  |___| |_______||_______|  |__| |__||_______||___|   |___|  |_______|    "<<endl;
    cout<<endl;
    Sleep(1500);
    system("cls");

}
