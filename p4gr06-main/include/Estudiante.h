#ifndef ESTUDIANTE
#define ESTUDIANTE

#include <string>
#include <set>
#include <map>
#include "Usuario.h"
#include "Curso.h"
#include "Inscripcion.h"
#include "DTNotificacion.h"
#include "DTFecha.h"

class Estudiante : public Usuario{
	private:
		std::string pais;
		DTFecha fechaNac;
		std::set<Inscripcion> inscripciones;
		std::map<int,Ejercicio*> ejerciciosAprobados;
	public:
		Estudiante(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion, std::set<DTNotificacion> colDT, std::string pais, DTFecha fechaNac);
		void notificar(DTNotificacion dn);
		std::string getPais();
		DTFecha getFechaNac();
		void desvincularCursosInscripto(std::string);
		std::set<std::string> obtenerCursosNoAp();
		void marcarAprobado(Ejercicio* ej);
		std::set<Curso*> obtenerCursos();
		bool noEstaAprobado(Ejercicio* ej);
		float obtenerAvanceEst();
		void agregarCursoAprobado(Curso* c);
		std::map<int,Ejercicio*> getEjerciciosAprobados();
		~Estudiante();
};

#endif