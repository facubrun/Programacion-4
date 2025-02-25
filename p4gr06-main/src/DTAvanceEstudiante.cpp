#include "../include/DTAvanceEstudiante.h"
#include <string>

DTAvanceEstudiante::DTAvanceEstudiante(){}
DTAvanceEstudiante::DTAvanceEstudiante(std::string nomCurso, std::string descripcion, enumDificultad dificultad, float avance) {
	this->nombreCurso = nomCurso;
	this->descripcionCurso = descripcion;
	this->dificultadCurso = dificultad;
	this->avanceEstudiante = avance;
}

std::string DTAvanceEstudiante::getNombreCurso() const{
	return nombreCurso;
}

std::string DTAvanceEstudiante::getDescripcionCurso() const{
	return descripcionCurso;
}

enumDificultad DTAvanceEstudiante::getDificultadCurso() const{
	return dificultadCurso;
}

float DTAvanceEstudiante::getAvanceEstudiante() const{
	return avanceEstudiante;
}