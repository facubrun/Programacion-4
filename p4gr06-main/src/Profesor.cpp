#include "../include/Profesor.h"		
        
Profesor::Profesor(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion, std::set<DTNotificacion> colDT, std::string instituto):Usuario(nickname, contrasenia, nombre, descripcion, colDT){
    this->instituto = instituto;
}
void Profesor::notificar(DTNotificacion dn){}
std::string Profesor::getInstituto(){
    return this->instituto;
}
std::set<std::string> Profesor::obtenerIdiomasProfe(){
    std::set<std::string> a;
    for (std::map<std::string, Idioma*>::iterator it = especializaciones.begin(); it != especializaciones.end(); ++it){
        a.insert(it->first);
    }
    return a;
}
void Profesor::agregarCurso(Curso* c){}
void Profesor::agregarEspecializacion(Idioma* i){
    especializaciones.insert(make_pair(i->getNombre(),i));
}
void Profesor::desvincularProfesor(){

}

std::set<Curso*> Profesor::obtenerCursos(){
    return this->cursosDictados;
}
Profesor::~Profesor(){}