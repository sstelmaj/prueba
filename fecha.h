

#ifndef FECHA_H
#define FECHA_H
#include <string>
using namespace std;

class fecha{
public:
    fecha();
    fecha(int,int,int);
    virtual ~fecha();
    
    string getFecha();
    bool validarFecha();
private:
    int dia;
    int mes;
    int anio;
};

#endif /* FECHA_H */

