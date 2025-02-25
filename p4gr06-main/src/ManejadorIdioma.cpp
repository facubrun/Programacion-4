#include "../include/ManejadorIdioma.h"
ManejadorIdioma* ManejadorIdioma::instancia = NULL;
ManejadorIdioma::ManejadorIdioma(){}
ManejadorIdioma* ManejadorIdioma::getInstance(){
    if (instancia == NULL){
        instancia = new ManejadorIdioma();
    }
    return instancia;
}
std::set<std::string> ManejadorIdioma::obtenerNombres(){
    std::set<std::string> a;
    for (std::map<std::string, Idioma*>::iterator it = idiomas.begin(); it != idiomas.end(); ++it){
        a.insert(it->first);
    }
    return a;
}
Idioma* ManejadorIdioma::obtenerIdioma(std::string nomIdioma){
    Idioma * language = NULL;
    if (this->idiomas.find(nomIdioma) != this->idiomas.end())
        language = this->idiomas.at(nomIdioma);
    return language;
}
std::set<std::string> ManejadorIdioma::buscarIdiomas(Usuario * u){
    std::set<std::string> a;
    bool verificar;
    for (std::map<std::string, Idioma*>::iterator it = idiomas.begin(); it != idiomas.end(); ++it){
        verificar = it->second->verificarSuscripcion(u);
        if(!verificar)
            a.insert(it->first);
    }
    return a;
}
std::set<std::string> ManejadorIdioma::obtenerSuscripciones(Usuario * u){
    std::set<std::string> a;
    bool estaSuscrito;
    for (std::map<std::string, Idioma*>::iterator it = idiomas.begin(); it != idiomas.end(); ++it){
        estaSuscrito = it->second->verificarSuscripcion(u);
        if(estaSuscrito)
            a.insert(it->first);
    }
    return a;
}
void ManejadorIdioma::agregarIdioma(Idioma * nomIdioma){
    if (this->idiomas.find(nomIdioma->getNombre()) == this->idiomas.end()) {
        this->idiomas.insert(std::pair<std::string, Idioma*>(nomIdioma->getNombre(), nomIdioma));
    }
}
ManejadorIdioma::~ManejadorIdioma(){}