#include "../include/DTEstudiante.h"

DTEstudiante::DTEstudiante() {
	
}
DTEstudiante::DTEstudiante(std::string nombre, std::string descripcion, std::string pais, DTFecha fecha) : DTUsuario(nombre, descripcion) {
	this->pais = pais;
	this->fecha = DTFecha(fecha.getDia(), fecha.getMes(), fecha.getAnio());
}
std::string DTEstudiante::getPais() {
	return pais;
}
DTFecha DTEstudiante::getFecha() {
	return fecha;
}
void DTEstudiante::setPais(std::string paisR) {
	pais = paisR;
}
void DTEstudiante::setFecha(DTFecha fechaNac) {
	fecha = DTFecha(fechaNac.getDia(), fechaNac.getMes(), fechaNac.getAnio());
}

void DTEstudiante::imprimirDatosRestantes(std::ostream& os) {
    os << "Pais: " << pais << std::endl;
    os << "Fecha: " << fecha << std::endl;
}