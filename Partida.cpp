

#include "Partida.h"
#include "fecha.h"
#include <iostream>
using namespace std;
//                                                                  Padre (PARTIDA)

Partida::Partida() {
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

void Partida::tostring() {
    cout << "Partida " << this->getTipo() << " iniciada por -" << this->host->getNickname() << "-." << endl;
    cout << "Fecha: " << this->fechas->getFecha() << endl;
    cout << "Duracion: " << this->getDuracion() << "hs." << endl;
}

void Partida::setfecha(fecha*p) {
    this->fechas = p;
}

string Partida::getTipo(){
    return "";
}

float Partida::getDuracion() {
    return this->duracion;
}

void Partida::setDuracion(float _duracion) {
    this->duracion = _duracion;
}

void Partida::setHost(Jugador*p) {
    this->host = p;
}

Jugador* Partida::getHost(){
    return this->host;
}

fecha* Partida::getFechaPartida(){
    return this->fechas;
}
//                                                                  Partida Individual

PartidaIndividual::PartidaIndividual() {
}

PartidaIndividual::~PartidaIndividual() {
}

void PartidaIndividual::tostring() {
    Partida::tostring();
    if (this->continuaPartidaAnterior == true) {
        cout << "Continuacion de Partida" << endl;

    } else {
        cout << "Partida Nueva" << endl;
    }
    cout<<"-----------------";
}

string PartidaIndividual::getTipo() {
    return "Individual";
}

float PartidaIndividual::darTotalHorasParticipantes() {
    return this->duracion;
}

void PartidaIndividual::setContinuaPartidaAnterior(bool si_no) {
    this->continuaPartidaAnterior = si_no;
}

bool PartidaIndividual::getContinuaPartidaAnterior() {
    return this->continuaPartidaAnterior;
}

//                                                                  Partida Multijugador                                                   

PartidaMultijugador::PartidaMultijugador() {
}

PartidaMultijugador::~PartidaMultijugador() {
}

float PartidaMultijugador::darTotalHorasParticipantes() {
    return this->duracion * (this->GetCantidad_jugadores());
}

void PartidaMultijugador::Agregar_jugadores(Jugador* p) {
    this->unidos.push_back(p);
}

void PartidaMultijugador::tostring() {
    Partida::tostring();
    if (this->GetTransmitidaEnVivo() == true) {
        cout << "Transmitida en vivo" << endl;
    } else {
        cout << "No transmitida en vivo" << endl;
    }
    cout<<"Jugadores que se unieron a la partida: "<<endl;
    for (Jugador *j : this->unidos){
                cout<<"-"<<j->getNickname()<<"-"<<endl;
            }
    cout<<"("<<this->GetCantidad_jugadores()<<" jugadores)"<<endl;
    cout<<"-----------------";
}

string PartidaMultijugador::getTipo() {
    return "Multijudador";
}

void PartidaMultijugador::setTransmitidaEnVivo(bool vivio_novivo) {
    this->transmitidaEnVivo = vivio_novivo;
}

bool PartidaMultijugador::GetTransmitidaEnVivo() {
    return this->transmitidaEnVivo;
}

int PartidaMultijugador::GetCantidad_jugadores() {
    return (this->unidos.size()+1);
}

bool PartidaMultijugador::existeJugadorUnido(string nickname){
    for (Jugador* p : this->unidos){
        if (p->getNickname() == nickname)
            return true;
    }
    return false;    
}

vector<Jugador*> PartidaMultijugador::getUnidos(){
    return this->unidos;
}