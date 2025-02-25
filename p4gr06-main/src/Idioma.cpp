#include "../include/Idioma.h"

Idioma::Idioma(std::string nombre){
    this->nombre = nombre;
}
std::string Idioma::getNombre(){
    return this->nombre;
}
void Idioma::nuevoCurso(){}
void Idioma::verificarSuscriptor(){}
void Idioma::agregarSuscripcion(Usuario* u){
    suscriptores.insert(make_pair(u->getNombre(),u));
}
bool Idioma::verificarSuscripcion(Usuario * u){
    return suscriptores.find(u->getNombre()) != suscriptores.end();
}
void Idioma::desuscribir(Usuario* u){
    suscriptores.erase(u->getNickname());
}
Idioma::~Idioma(){}