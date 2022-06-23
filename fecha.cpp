

#include "fecha.h"

fecha::fecha(){
}

fecha::~fecha(){
}

fecha::fecha(int _dia, int _mes, int _anio){
    this->dia=_dia;
    this->mes=_mes;
    this->anio=_anio;
}

string fecha::getFecha(){
    return to_string(this->dia)+"/"+to_string(this->mes)+"/"+to_string(this->anio);
}

bool fecha::validarFecha(){
    if (this->dia>31 || this->dia<1 || this->mes>12 || this->mes<1 || this->anio<1900)
        return false;
    else
        return true;           
}


