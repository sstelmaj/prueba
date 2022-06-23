

#include "VideoJuego.h"

VideoJuego::VideoJuego() {
}

VideoJuego::VideoJuego(const VideoJuego& orig) {
}

VideoJuego::VideoJuego(string nombre, TipoJuego genero) {
    this->nombre = nombre;
    this->genero = genero;
}

VideoJuego::~VideoJuego() {
}

void VideoJuego::setNombre(string _nombre){
    this->nombre = _nombre;
}

string VideoJuego::getNombre(){
    return nombre;
}

TipoJuego VideoJuego::getGenero() {
    return this->genero;
}

float VideoJuego::darTotalHorasDeJuego() {
    float total = 0;
    for (int i = 0; i < partidas.size(); i++) {
        if (PartidaIndividual * pPI = dynamic_cast<PartidaIndividual*> (partidas[i])) {
            total += pPI->darTotalHorasParticipantes();
        } else {
            if (PartidaMultijugador * pPM = dynamic_cast<PartidaMultijugador*> (partidas[i])) {
                total += pPM->darTotalHorasParticipantes();
            }
        }
    }
    return total;
}

void VideoJuego::agregarPartida(Partida *nuevaPartida){
    this->partidas.push_back(nuevaPartida);
}

vector<Partida*> VideoJuego::getPartidas(){
    return this->partidas;
}