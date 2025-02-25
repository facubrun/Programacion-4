#include "../include/Ejercicio.h"
        
Ejercicio::Ejercicio(std::string solucion){
    this->solucion = solucion;
}
std::string Ejercicio::getSolucion(){
    return this->solucion;
}

Ejercicio::~Ejercicio(){}