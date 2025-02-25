#ifndef PROFESOR
#define PROFESOR

#include <string>
#include <set>
#include <map>
#include "Curso.h"
#include "Usuario.h"
#include "Idioma.h"
#include "DTNotificacion.h"

class Profesor : public Usuario{
	private:
		std::string instituto;
		std::set<Curso*> cursosDictados;
		std::map<std::string, Idioma*> especializaciones;
	public:
		Profesor(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion, std::set<DTNotificacion> colDT, std::string instituto);
		void notificar(DTNotificacion dn);
		std::string getInstituto();
		std::set<std::string> obtenerIdiomasProfe();
		void agregarCurso(Curso* c);
		void agregarEspecializacion(Idioma* i);
		void desvincularProfesor();
		std::set<Curso*> obtenerCursos();
		~Profesor();
};

#endif