#include "../include/DTAvanceCurso.h"
#include <string>
DTAvanceCurso::DTAvanceCurso(){}
DTAvanceCurso::DTAvanceCurso(std::string nomCurso, std::string descripcion, enumDificultad dificultad, float avance) {
	this->nombreCurso = nomCurso;
	this->descripcionCurso = descripcion;
	this->dificultadCurso = dificultad;
	this->avanceCurso = avance;
}

std::string DTAvanceCurso::getNombreCurso() {
	return nombreCurso;
}

std::string DTAvanceCurso::getDescripcionCurso() {
	return descripcionCurso;
}

enumDificultad DTAvanceCurso::getDificultadCurso() {
	return dificultadCurso;
}

float DTAvanceCurso::getAvanceCurso() {
	return avanceCurso;
}