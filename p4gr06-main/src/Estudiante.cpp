#include "../include/Estudiante.h"

Estudiante::Estudiante(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion, std::set<DTNotificacion> colDT, std::string pais, DTFecha fechaNac):Usuario(nickname, contrasenia, nombre, descripcion, colDT){
    this->pais = pais;
    this->fechaNac = DTFecha(fechaNac.getDia(),fechaNac.getMes(),fechaNac.getAnio());
}
void Estudiante::notificar(DTNotificacion dn){}
std::string Estudiante::getPais(){
    return this->pais;
}
DTFecha Estudiante::getFechaNac(){
    return this->fechaNac;
}
void Estudiante::desvincularCursosInscripto(std::string){}
std::set<std::string> Estudiante::obtenerCursosNoAp(){
    std::set<std::string> a;
    return a;
}
void Estudiante::marcarAprobado(Ejercicio* ej){}
std::set<Curso*> Estudiante::obtenerCursos(){
    std::set<Curso*> a;
    return a;
}
bool Estudiante::noEstaAprobado(Ejercicio* ej){
    return 1;
}
float Estudiante::obtenerAvanceEst(){
    return 0;
}
std::map<int,Ejercicio*> Estudiante:: getEjerciciosAprobados(){
    std::map<int,Ejercicio*> m;
    return m;
}
void Estudiante::agregarCursoAprobado(Curso* c){}
Estudiante::~Estudiante(){}