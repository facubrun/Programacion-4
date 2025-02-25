#include "../include/DTFecha.h"

DTFecha::DTFecha(){}

DTFecha::DTFecha(int dia, int mes, int anio) {
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int DTFecha::getDia() {
	return dia;
}
int DTFecha::getMes() {
	return mes;
}
int DTFecha::getAnio() {
	return anio;
}

std::ostream& operator<<(std::ostream& os, DTFecha& fecha) {
	os << std::setfill('0') << std::setw(4) << fecha.getAnio() << '/' << std::setw(2) << 
	fecha.getMes() << '/' << std::setw(2) << fecha.getDia();
	return os;
}


