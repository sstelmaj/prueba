

#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

class Jugador {
public:

    Jugador();
    Jugador(string, int, string);
    Jugador(const Jugador& orig);
    virtual ~Jugador();
    
    void setNickname(string);
    void setEdad(int);
    void setPassword(string);
    
    string getNickname();
    int getEdad();
    string getPassword();
	
private:

    string nickname;
    int edad;
    string password;

};

#endif /* JUGADOR_H */

