#ifndef IDIOMA
#define IDIOMA

#include <string>
#include <map>
#include "Usuario.h"
#include "Profesor.h"

class Idioma {
	private:
		std::string nombre;
		Profesor* profesor;
		std::map<std::string, Usuario*> suscriptores;
	public:
		Idioma(std::string nombre);
		std::string getNombre();
		void nuevoCurso();
		void verificarSuscriptor();
		void agregarSuscripcion(Usuario* u);
		bool verificarSuscripcion(Usuario * u);
		void desuscribir(Usuario* u);
		~Idioma();
};

#endif