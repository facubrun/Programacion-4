#include "../include/Completar.h"
#include <string>

Completar::Completar(std::string solucion, std::string fraseACompletar):Ejercicio(solucion){
    this->fraseACompletar = fraseACompletar; 
}
std::string Completar::getFrase(){
    return this->fraseACompletar;
}
Completar::~Completar(){}