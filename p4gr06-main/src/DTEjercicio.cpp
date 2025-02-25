#include "../include/DTEjercicio.h"


DTEjercicio::DTEjercicio(int id_ej, std::string tipo_ej, std::string desc) {
	this->idEjercicio = id_ej;
	this->tipoEjercicio = tipo_ej;
	this->descripcion = desc;
}

int DTEjercicio::getidEjercicio() const{
    return this->idEjercicio;
}

std::string DTEjercicio::getTipoEjercicio() const{
    return this->tipoEjercicio;
}

std::string DTEjercicio::getdescripcion() const{
    return this->descripcion;
}
