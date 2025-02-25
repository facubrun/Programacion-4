#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion, std::set<DTNotificacion> colDT){
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
}
std::string Usuario::getNickname(){
    return this->nickname;
}
std::string Usuario::getContrasenia(){
    return this->contrasenia;
}
std::string Usuario::getNombre(){
    return this->nombre;
}
std::string Usuario::getDescripcion() {
    return this->descripcion;
}
std::vector<DTNotificacion> Usuario::getColDT(){
    return this->colDT;
}

DTNotificacion Usuario::getDTNotificacion() {
    std::vector<DTNotificacion> setDTN = getColDT();
    DTNotificacion dn = (*setDTN.begin());
    return dn;
}

void Usuario::setColDT(){}
void Usuario::notificar(DTNotificacion dn){}
void Usuario::eliminarNotificacion(DTNotificacion dn){
    auto it = colDT.begin();
    DTNotificacion actual = (*it);
    while(actual.getnomCurso() != dn.getnomCurso()) {
        ++it;
        actual = (*it);
    }
    colDT.erase(it);
}
Usuario::~Usuario(){}