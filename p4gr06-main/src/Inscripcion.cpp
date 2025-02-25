#include "../include/Inscripcion.h"

Inscripcion::Inscripcion(DTFecha fechaIns, bool aprobado){
    this->fechaIns = fechaIns;
    this->aprobado = aprobado;
}
DTFecha Inscripcion::getFechaIns(){
    return this->fechaIns;
}
bool Inscripcion::getAprobado(){
    return this->aprobado;
}
bool Inscripcion::esDeEsteCurso(std::string nomCurso){
    return 0;
}
bool Inscripcion::compararCursos(Curso* c){
    return 0;
}
Inscripcion::~Inscripcion(){}