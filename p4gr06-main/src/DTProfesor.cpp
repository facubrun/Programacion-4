#include "../include/DTProfesor.h"

DTProfesor::DTProfesor() {

}

DTProfesor::DTProfesor(std::string nombre, std::string descripcion, std::string instituto, std::set<std::string> espec) : DTUsuario(nombre, descripcion) {
	this->nomInstituto = instituto;
	this->nomEspec = espec;
}

std::string DTProfesor::getNomInstituto() {
	return nomInstituto;
}

std::set<std::string> DTProfesor::getNomEspec() {
	return nomEspec;
}

void DTProfesor::setNomInstituto(std::string instituto) {
	nomInstituto = instituto; 
}

void DTProfesor::imprimirDatosRestantes(std::ostream& os) {
    os << "Instituto: " << nomInstituto << std::endl;
    os << "Especializaciones: ";
    for (std::set<std::string>::iterator it = nomEspec.begin(); it!=nomEspec.end(); ++it) {
        os << (*it) << " ";
    }
    os << std::endl;
}