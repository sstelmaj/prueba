

#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>
#include <vector>
#include "Partida.h"
using namespace std;

typedef enum juego{
    RPG, MMO, MOBA, SHOOTER, TERROR, FANTASIA, CASUAL, ACCION, ESTRATEGIA, SIMULACION, DEPORTIVO, MUSICAL, DE_MESA
}TipoJuego;

class VideoJuego {
public:
    
    VideoJuego();
    VideoJuego(const VideoJuego& orig);
    VideoJuego(string, TipoJuego);
    virtual ~VideoJuego();
    float darTotalHorasDeJuego();
    
    void agregarPartida(Partida *);
    
    void setNombre(string);
    string getNombre();
    TipoJuego getGenero();
    
    vector<Partida*> getPartidas();
    
private:
    string nombre;
    TipoJuego genero;
    vector<Partida*> partidas;
};

#endif /* VIDEOJUEGO_H */

