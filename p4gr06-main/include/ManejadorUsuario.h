#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include <string>
#include <set>
#include <map>
#include "Usuario.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "DTFecha.h"

class ManejadorUsuario { 
	private:
		static ManejadorUsuario* instancia;
		ManejadorUsuario();
		std::map<std::string, Usuario*> usuarios;
	public:
		static ManejadorUsuario* getInstance();
		std::set<std::string> obtenerNicknames();
		Profesor* seleccionarProfesor(std::string nickname);
		bool existeUsuario(std::string nickname);
		void agregarUsuario(Usuario *u);
		std::set<std::string> obtenerNombres();
		void eliminarCurso(std::string nomCurso);
		std::set<std::string> obtenerCursosNoAp(std::string);
		std::set<std::string> obtenerEstudiantes();
		Estudiante* seleccionarEstudiante(std::string nickname);//if no hay nickname dar error
		std::set<std::string> obtenerProfesores();
		Usuario * buscarUsuario(std::string nickname);
		bool estudianteNoAprobo(Ejercicio *ej);
		~ManejadorUsuario();
};

#endif