

#ifndef PARTIDA_H
#define PARTIDA_H
#include "Jugador.h"
#include "fecha.h"
#include <vector>
using namespace std;

class Partida {
public:
    Partida();
    Partida(const Partida& orig);
    virtual ~Partida();
    
    virtual string getTipo();
    virtual void tostring();
    
    void setfecha(fecha*);

    void setDuracion(float);
    float getDuracion();
    
    void setHost(Jugador*);
    Jugador* getHost();
    
    fecha* getFechaPartida();
protected:
    float duracion;
    Jugador* host = NULL;
    fecha* fechas;
};
//------------------------------------------------------------------------------

class PartidaIndividual : public Partida {
public:
    PartidaIndividual();
    virtual ~PartidaIndividual();
    
    void setContinuaPartidaAnterior(bool);
    bool getContinuaPartidaAnterior();

    float darTotalHorasParticipantes();
    virtual string getTipo();
    virtual void tostring();
	
private:
    bool continuaPartidaAnterior;
};
//------------------------------------------------------------------------------

class PartidaMultijugador : public Partida {
public:
    PartidaMultijugador();
    virtual ~PartidaMultijugador();
    
    void setTransmitidaEnVivo(bool);
    void Agregar_jugadores(Jugador*);

    bool GetTransmitidaEnVivo();
    int GetCantidad_jugadores();

    float darTotalHorasParticipantes();
    virtual string getTipo();
    virtual void tostring();
    
    vector<Jugador*> getUnidos();
    
    bool existeJugadorUnido(string);

private:
    vector<Jugador*> unidos;
    bool transmitidaEnVivo;
};
#endif /* PARTIDA_H */


