

#include <cstdlib>
#include <vector>
#include <valarray>
#include <ctype.h>
#include <cstring>
#include "sistema.h"
#include "Jugador.h"
#include "Partida.h"
#include "VideoJuego.h"
#include "fecha.h"

using namespace std;


sistema::sistema(){
}
sistema::~sistema(){
}
//-----------------------------------------------------------------------------------------------------------

TipoJuego sistema::elegirGenero() {
    int opcion;
    char dato[20];
    bool verificar = false;
    do {
        cout << "1- RPG" << endl;
        cout << "2- MMO" << endl;
        cout << "3- MOBA" << endl;
        cout << "4- SHOOTER" << endl;
        cout << "5- TERROR" << endl;
        cout << "6- FANTASIA" << endl;
        cout << "7- CASUAL" << endl;
        cout << "8- ACCION" << endl;
        cout << "9- ESTRATEGIA" << endl;
        cout << "10- SIMULACION" << endl;
        cout << "11- DEPORTIVO" << endl;
        cout << "12- MUSICAL" << endl;
        cout << "13- DE MESA" << endl;

        cin>>dato;
        opcion=atoi(dato);
        if (opcion > 0 && opcion < 14) {
            verificar = true;
        } else {
            cout << "Opcion invalida, elija de nuevo " << endl;
            cout<<"[ENTER] para continuar...";
            getchar();
            getchar();
            system("clear");
        }

    } while (verificar == false);

    return (TipoJuego) opcion;
}
//-----------------------------------------------------------------------------------------------------------

void sistema::Menu() {
    cout << "[1] Agregar Jugador" << endl;
    cout << "[2] Agregar Videojuego" << endl;
    cout << "[3] Iniciar Partida " << endl;
    cout << "[4] Obtener Partidas " << endl;
    cout << "[5] Obtener Jugadores " << endl;
    cout << "[6] Obtener Videojuegos " << endl;
    cout << "[0] Salir " << endl;
}
//-----------------------------------------------------------------------------------------------------------

void sistema::agregarJugador(string nickname, int edad, string password) {
    Jugador* jugador = new Jugador(nickname, edad, password);
    jugadores.push_back(jugador);
    cout << "Jugador agregado con exito" << endl;
    cout<<"[ENTER] para continuar...";
    getchar();
    getchar();
}
//-----------------------------------------------------------------------------------------------------------

void sistema::agregarVideojuego(string nombre, TipoJuego genero) {
    VideoJuego* Videojuego = new VideoJuego(nombre, genero);
    Videojuegos.push_back(Videojuego);
    cout << "Videojuego agregado con exito" << endl;
    cout<<"[ENTER] para continuar...";
    getchar();
    getchar();
}
//-----------------------------------------------------------------------------------------------------------
//valido el nombre que ingresa el usuario como jugador

bool sistema::validarJugadores(string _id) {
    for (Jugador*player : jugadores) {
        if (player->getNickname() == _id) {
            return false;
        }
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------
//valido el juego que ingresa el usuario

bool sistema::validarJuego(string _juego) {
    for (VideoJuego*play : Videojuegos) {
        if (play->getNombre() == _juego) {
            return false;
        }
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------

void sistema::iniciarPartida(string nickname, string nom_videojuego, Partida* datos) {
    fecha* fechapartida = NULL;
    string _nickname;
    char misdatos[20];
    char i;
    char r;
    int dia, mes, anio;
    float duracion;
    bool estado;
    if (validarJugadores(nickname) == true) {
        cout << "El jugador ingresado no existe"<<endl;
        cout<<"[ENTER] para continuar...";
        getchar();
        getchar();
        return;
    }
    if (validarJuego(nom_videojuego) == true) {
        cout << "El videojuego ingresado no existe"<<endl;
        cout<<"[ENTER] para continuar...";
        getchar();
        getchar();
        return;
    }

    cout << "[1] Partida Individual " << endl;
    cout << "[2] Partida Multijugador " << endl;
    cout << "- ";
    cin>>i;

    if (i == '1') { //Partida PartidaIndividual

        cout << "\n[1] Continuar Partida  " << endl;
        cout << "[2] Partida Nueva " << endl;
        cout << "- ";
        cin>>i;
        if (i == '1') {
            estado = true;
        }
        datos = new PartidaIndividual();
        PartidaIndividual* individual = dynamic_cast<PartidaIndividual*> (datos);
        individual->setContinuaPartidaAnterior(estado);

    }//Partida Multijugador
    else {
        cout << "\n[1] Es en vivo  " << endl;
        cout << "[2] No es en vivo " << endl;
        cout << "- ";
        cin>>i;
        if (i == '1') {
            estado = true;
        } else {
            estado = false;
        }
        datos = new PartidaMultijugador();
        PartidaMultijugador* multi = dynamic_cast<PartidaMultijugador*> (datos);
        multi->setTransmitidaEnVivo(estado);

        do {
            cout << "ingrese nombre de jugador a unirse: ";
            cin>>_nickname;

            while (_nickname == nickname) {
                cout << "El jugador es el host de la partida, ingrese otro: ";
                cin>>_nickname;
            }

            if (multi->existeJugadorUnido(_nickname) == true)
                cout << "El jugador ya se encuentra unido" << endl;

            else if (validarJugadores(_nickname) == true)
                cout << "El jugador no existe en el sistema" << endl;

            else {
                for (Jugador*p : jugadores) {
                    if (p->getNickname() == _nickname) {
                        multi->Agregar_jugadores(p);
                    }
                }
            }

            cout << "[1] para seguir uniendo jugadores: \n[2] Terminar:" << endl;
            cout << "- ";
            cin>>r;
        } while (r == '1');
    }

    do{
    cout << "\nDigite duracion de partida en Hs:";
    cin>>duracion;
    if (duracion < 1) {
        cout << "Duracion no valida, ingrese nuevamente:" << endl;
    }
    }while(duracion<1);
    datos->setDuracion(duracion);

    do {
        cout << "\ningrese el dia:";
        cin>>misdatos;
        dia=atoi(misdatos);
        cout << "\ningrese el mes:";
        cin>>misdatos;
        mes=atoi(misdatos);
        cout << "\ningrese el anio:";
        cin>>misdatos;
        anio=atoi(misdatos);
        fechapartida = new fecha(dia, mes, anio);

        if (fechapartida->validarFecha() == false) {
            cout << endl << "\tFECHA INVALIDA..." << endl;
            fechapartida->~fecha();
            delete(fechapartida);
            fecha* fechapartida = NULL;
        } else
            datos->setfecha(fechapartida);
    } while (fechapartida->validarFecha() == false);

    for (Jugador*r : jugadores) {
        if (r->getNickname() == nickname) {
            datos->setHost(r);
        }
    }
    //Agrego la partida al vector de partidas del juego ingresado:

    for (VideoJuego *v : Videojuegos) {
        if (nom_videojuego == v->getNombre()) {
            v->agregarPartida(datos);
        }
    }
    cout<<"Partida iniciada con exito."<<endl;
    cout<<"[ENTER] para continuar...";
    getchar();
    getchar();
}
//-----------------------------------------------------------------------------------------------------------

int sistema::contarPartidasVideojuego(string nom_videojuego) {
    int total = 0;
    for (VideoJuego *v : Videojuegos) {
        if (nom_videojuego == v->getNombre()) {
            for (Partida *p : v->getPartidas()) {
                total++;
            }
            return total;
        }
    }
    return total;
}
//-----------------------------------------------------------------------------------------------------------

Partida **sistema::obtenerPartidas(string videojuego, int& cantPartidas) {
    if (validarJuego(videojuego) == true)
        return NULL;

    for (VideoJuego *v : Videojuegos) {
        if (v->getNombre() == videojuego) {
            vector<Partida*> Part = v->getPartidas();
            cantPartidas = Part.size();
            Partida **miArreglo = new Partida*[cantPartidas];
            int i = 0;
            for (Partida *a : Part) {
                miArreglo[i] = a;
                i++;
            }
            return miArreglo;
        }
    }
    return NULL;
}
//-----------------------------------------------------------------------------------------------------------

void sistema::mostrarPartidas(Partida **miArreglo, int &cantPartidas) {
    if (!miArreglo) {
        cout << "El juego no existe" << endl;
        cout<<"[ENTER] para continuar...";
        getchar();
        getchar();
        return;
    }
    if (cantPartidas == 0) {
        cout << "Este videojuego no tiene partidas" << endl;
        cout<<"[ENTER] para continuar...";
        getchar();
        getchar();
        return;
    }
    Partida *puntero = NULL;
    for (int i = 0; i < cantPartidas; i++) {
        puntero = miArreglo[i];
        if (PartidaIndividual * pPi = dynamic_cast<PartidaIndividual*> (puntero)) {
            pPi->tostring();
            cout << "\n";
        } else {
            PartidaMultijugador* pPm = dynamic_cast<PartidaMultijugador*> (puntero);
            pPm->tostring();
            cout << "\n";
        }
    }
    cout<<"[ENTER] para continuar...";
    getchar();
    getchar();
}
//-----------------------------------------------------------------------------------------------------------

int sistema::contarJugadores() {
    return jugadores.size();
}

int sistema::contarJugadoresMenores(){
    int total=0;
    for (Jugador* j : this->jugadores){
        if (j->getEdad()<19)
            total++;
    }
    return total;
}
//-----------------------------------------------------------------------------------------------------------

Jugador* sistema::obtenerJugadores(int& cantJugadores) {
    cantJugadores = contarJugadores();
    Jugador* miArreglo = NULL;
    miArreglo = new Jugador[cantJugadores];
    
    int i = 0;
    for (Jugador *a : jugadores) {
        miArreglo[i] = *a;
        i++;
    }
    return miArreglo;
}
//-----------------------------------------------------------------------------------------------------------

void sistema::mostrarArregloJugadores(Jugador* miArreglo, int &cantJugadores) {
    int i;
    for (i = 0; i < cantJugadores; i++) {
        cout << "Jugador n�" << i + 1 << ":" << endl;
        cout << "usuario:" << miArreglo[i].getNickname() << " | " << miArreglo[i].getPassword() << endl;
        cout << "edad:" << miArreglo[i].getEdad() << endl;
        cout << "-------------------" << endl;
    }
    cout<<"[ENTER] para continuar...";
    getchar();
    getchar();
    return;
}
//-----------------------------------------------------------------------------------------------------------

int sistema::contarVideojuegos() {
    return Videojuegos.size();
}
//-----------------------------------------------------------------------------------------------------------

VideoJuego* sistema::obtenerVideojuegos(int & cantVideojuegos) {
    cantVideojuegos = contarVideojuegos();
    VideoJuego *miArreglo = NULL;
    miArreglo = new VideoJuego[cantVideojuegos];

    int i = 0;
    for (VideoJuego*a : Videojuegos) {
        miArreglo[i] = *a;
        i++;
    }
    return miArreglo;
}
//-----------------------------------------------------------------------------------------------------------

void sistema::mostrarArregloVideojuegos(VideoJuego *miArreglo, int &cantVideojuegos) {
    int i;
    for (i = 0; i < cantVideojuegos; i++) {
        cout << "------" << miArreglo[i].getNombre() << "------" << endl << "Genero: ";

        switch (miArreglo[i].getGenero()) {
            case 1: cout << "RPG\n";
                break;
            case 2: cout << "MMO\n";
                break;
            case 3: cout << "MOBA\n";
                break;
            case 4: cout << "SHOOTER\n";
                break;
            case 5: cout << "TERROR\n";
                break;
            case 6: cout << "FANTASIA\n";
                break;
            case 7: cout << "CASUAL\n";
                break;
            case 8: cout << "ACCION\n";
                break;
            case 9: cout << "ESTRATEGIA\n";
                break;
            case 10: cout << "SIMULACION\n";
                break;
            case 11: cout << "DEPORTIVO\n";
                break;
            case 12: cout << "MUSICAL\n";
                break;
            case 13: cout << "DE MESA\n";
                break;
            default:
                cout << "*desconocido*";
                break;
        }

        cout << "Total de horas jugadas: " << miArreglo[i].darTotalHorasDeJuego() << endl << endl;
    }
    cout<<"[ENTER] para continuar...";
    getchar();
    getchar();
    return;
}
//-----------------------------------------------------------------------------------------------------------
