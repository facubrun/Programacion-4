#include "../include/DTCurso.h"
#include <string>


DTCurso::DTCurso(std::string nomCurso, std::string descripcion, enumDificultad dificultad) {
	this->nomCurso = nomCurso;
	this->descripcion = descripcion;
	this->dificultad = dificultad;
}

std::string DTCurso::getNombre() const{
	return nomCurso;
}

std::string DTCurso::getDescripcion() const{
	return descripcion;
}

enumDificultad DTCurso::getDificultad() const{
	return dificultad;
}