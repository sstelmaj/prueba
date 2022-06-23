

#include <iostream>
#include <cstdlib>
#include "sistema.h"
#include "VideoJuego.h"
#include "Partida.h"
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    int cant_jugadores = 0;
    int cant_Videojuego = 0;
    int cant_Partidas = 0;

    Partida *datos = NULL;
    sistema* Sistema = new sistema ();
    bool i; 
    int opcion = 15;
    int edad = 0;
    char dato[20];
    string nickname = "";
    string password = "";
    string nombre = "";

    do {
        system("clear");
		Sistema->Menu();
        cin>>opcion;
        switch (opcion) {

            case 1:
            {
                system("clear");
                do {
                    cout << "\nIngrese nickname: ";
                    cin>>nickname;
                    if (Sistema->validarJugadores(nickname) == true) {
                        i = true;
                    } else {
                        cout << "El jugador " << nickname << " ya esta registrado" << endl;
                        i = false;
                    }
                } while (i == false);
                do {
                    cout << "\nIngrese edad: ";
                    cin>>dato;
                    edad=atoi(dato);
                    if (edad < 1) {
                        cout << "Edad no valida, ingrese nuevamente:" << endl;
                    }
                } while (edad < 1);
                cout << "\nIngrese password: ";
                cin>>password;
                Sistema->agregarJugador(nickname, edad, password);
                break;
            }
            case 2:
            {
                system("clear");
                do {
                    cout << "\nIngrese nombre: ";
                    cin>>nombre;
                    if (Sistema->validarJuego(nombre) == true) {
                        i = true;
                    } else {
                        cout << "El juego ya esta en el sistema" << endl;
                        i = false;
                    }
                } while (i == false);

                cout << "Ingrese genero:" << endl;
				Sistema->agregarVideojuego(nombre, Sistema->elegirGenero());
                break;
            }
            case 3:
                system("clear");
            {
                VideoJuego*p ;
                p = Sistema->obtenerVideojuegos(cant_Videojuego);
                if (cant_Videojuego == 0) {
                    cout << "No hay videojuegos ingresados en el sistema para iniciar una partida" << endl;
                    getchar();
                    getchar();
                    break;
                }
                Jugador*c ;
                c = Sistema->obtenerJugadores(cant_jugadores);
                if (cant_jugadores == 0) {
                    cout << "No hay jugadores ingresados en el sistema para iniciar una partida" << endl;
                    getchar();
                    getchar();
                    break;
                }
                cout << "\nIngrese nickname: ";
                cin>>nickname;
                cout << "\nIngrese nombre del Videojuego: ";
                cin>>nombre;
                Sistema->iniciarPartida(nickname, nombre, datos = new Partida());
                break;
            }
            case 4:
                system("clear");
            {
                cout << "\nIngrese videojuego: ";
                cin>>nombre;
                Partida** p;
                p = Sistema->obtenerPartidas(nombre, cant_Partidas);
                Sistema-> mostrarPartidas(p, cant_Partidas);
                break;
            }
            case 5:
                system("clear");
            {
                Jugador*p;
                p = Sistema->obtenerJugadores(cant_jugadores);
                if (cant_jugadores == 0) {
                    cout << "No hay jugadores ingresados en el sistema" << endl;
                    getchar();
                    getchar();
                    break;
                }
                Sistema->mostrarArregloJugadores(p, cant_jugadores);
            }
                break;
            case 6:
                system("clear");
            {
                VideoJuego*p;
                p = Sistema->obtenerVideojuegos(cant_Videojuego);
                if (cant_Videojuego == 0) {
                    cout << "No hay videojuegos ingresados en el sistema" << endl;
                    getchar();
                    getchar();
                    break;
                }
                Sistema->mostrarArregloVideojuegos(p, cant_Videojuego);
            }
                break;
        }
    } while (opcion != 0);

    return 0;
}

