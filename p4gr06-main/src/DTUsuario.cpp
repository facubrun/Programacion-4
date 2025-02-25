#include "../include/DTUsuario.h"
DTUsuario::DTUsuario() {

}
DTUsuario::DTUsuario(std::string nombre, std::string descripcion) {
	this->nombre = nombre;
	this->descripcion = descripcion;
}
std::string DTUsuario::getNombre() {
	return nombre;
}
std::string DTUsuario::getDescripcion() {
	return descripcion;
}
void DTUsuario::setNombre(std::string nom) {
	nombre = nom;
}
void DTUsuario::setDescripcion(std::string desc) {
	descripcion = desc;
}


std::ostream& operator<<(std::ostream& os, DTUsuario& usuario) {
        os << "Nombre: " << usuario.getNombre() << std::endl;
        os << "Descripcion: " << usuario.getDescripcion() << std::endl;
        usuario.imprimirDatosRestantes(os);  // Llama a la función virtual para imprimir los datos específicos del tipo hijo
        return os;
}

void DTUsuario::imprimirDatosRestantes(std::ostream& os) {}