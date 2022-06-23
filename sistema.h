

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <cstdlib>
#include "VideoJuego.h"

using namespace std;
class sistema{
public:
	sistema();
        virtual ~sistema();
	TipoJuego elegirGenero();
	void agregarJugador(string, int, string);
	void agregarVideojuego(string, TipoJuego);
	
	///Validar Opciones
	bool validarJugadores(string);
	bool validarJuego(string);
	
//-------------------------------------------------------------------------------------	
	///iniciar partida y obtener partidas
	void iniciarPartida(string, string,Partida*);
	Partida** obtenerPartidas(string, int &);
	int contarPartidasVideojuego(string);
	void mostrarPartidas(Partida **, int &);
	
//-------------------------------------------------------------------------------------	
	///Obtener jugadores
	int contarJugadores();
        int contarJugadoresMenores();
	Jugador* obtenerJugadores(int&);
	void mostrarArregloJugadores(Jugador*, int &);
	
//-------------------------------------------------------------------------------------	
	///Obtener Juegos
	int contarVideojuegos();
	VideoJuego* obtenerVideojuegos(int &);
	void mostrarArregloVideojuegos(VideoJuego*, int &);
	
//-------------------------------------------------------------------------------------		
	///menu
	void Menu();
        
private :
    vector<Jugador*> jugadores;
    vector<VideoJuego*> Videojuegos;	
};


#endif /* SISTEMA_H */

