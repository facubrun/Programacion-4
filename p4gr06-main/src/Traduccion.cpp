#include "../include/Traduccion.h"
#include <string>

Traduccion::Traduccion(std::string solucion, std::string fraseATraducir):Ejercicio(solucion){
    this->fraseATraducir = fraseATraducir;
}
std::string Traduccion::getFrase(){
    return this->fraseATraducir;
}
Traduccion::~Traduccion(){}