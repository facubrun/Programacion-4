#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include <string>
#include <map>
#include <set>
#include <vector>
#include "DTFecha.h"
#include "Curso.h"
#include "Ejercicio.h"
#include "DTNotificacion.h"
#include "IUsuario.h"
#include "ManejadorUsuario.h"
#include "ManejadorIdioma.h"
#include "Idioma.h"
#include "DTUsuario.h"
#include "DTEstudiante.h"
#include "DTProfesor.h"

class ControladorUsuario : public IUsuario{
  private:
    static ControladorUsuario* instancia;
		ControladorUsuario();
		std::string memNick;
		std::string memPass;
		std::string memNom;
		std::string memDesc;
		std::string memPais;
		DTFecha memFechaNac;
		std::string memIns;
		Usuario * memUser;
		std::set<Idioma*> IdiomasRecordados;
  public:
		static ControladorUsuario* getInstance();
		void ingresarDatosUsuario(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion);
		void setNickname(std::string nickname);
		void ingresarPaisResidencia(std::string pais);
		void ingresarFechaNacimiento(DTFecha fechaNac);
		bool confirmarAltaEstudiante();
		void AltaEstudiante();
		bool NicknameDisponible(std::string nickname);
		void ingresarInstituto(std::string nomInstituto);
		std::set<std::string> obtenerIdiomasDisponibles();
		void agregarEspecializacion(std::string nomIdioma);
		bool confirmarAltaProfesor();
		void AltaProfesor();
		std::set<std::string> obtenerCursosNoAprobados(std::string nickname);
		Curso* seleccionarCurso(std::string nomCurso);
		Ejercicio* seleccionarEjercicio(int idEjercicio);
		void ingresarSolucion(std::string respuesta);
		std::set<std::string> listarIdiomas(std::string nickname);
		std::vector<DTNotificacion> notificacionesRecibidas(std::string nickname);
		std::set<std::string> listaSuscripciones(std::string nickname);
		void eliminarSuscripcion(std::string nomidioma);
		void altaSuscripcion(std::string nomIdioma);
		std::set<std::string> obtenerNicks();
		//DTUsuario obtenerInfoUsuario(std::string nickname);
		DTEstudiante obtenerInfoEstudiante(std::string nickname);
		DTProfesor obtenerInfoProfesor(std::string nickname);
		bool esEstudiante(std::string nickname);
		~ControladorUsuario();
};

#endif