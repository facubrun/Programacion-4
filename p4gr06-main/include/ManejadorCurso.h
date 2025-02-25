#ifndef MANEJADORCURSO
#define MANEJADORCURSO

#include <string>
#include <set>
#include "Curso.h"

class ManejadorCurso { 
	private:
		static ManejadorCurso* instancia;
		ManejadorCurso();
		std::map<std::string,Curso*> cursos;
	public:
		static ManejadorCurso* getInstance();
		std::set<std::string> obtenerNicknames();
		void agregarCurso(Curso* c);
        std::set<std::string> obtenerCursos();
        Curso* seleccionarCurso();
        void verificarPrevia();
        void eliminarCurso();
        Curso * buscarCurso(std::string nomCurso);
        std::set<std::string> obtenerEstudiantes();
		~ManejadorCurso();
};

#endif