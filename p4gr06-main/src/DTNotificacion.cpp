#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion() {

}

DTNotificacion::DTNotificacion(std::string nom_idioma, std::string nom_curso) {
	this->nomIdioma = nom_idioma;
	this->nomCurso = nom_curso;
}

std::string DTNotificacion::getnomIdioma() {
	return nomIdioma;
}

std::string DTNotificacion::getnomCurso() {
	return nomCurso;
}