#ifndef IUSUARIO
#define IUSUARIO

#include <string>
#include <set>
#include <vector>
#include "DTFecha.h"
#include "Curso.h"
#include "Ejercicio.h"
#include "DTNotificacion.h"
#include "DTUsuario.h"
#include "DTProfesor.h"
#include "DTEstudiante.h"


class IUsuario {
  public:
	static IUsuario* getInstance();
	virtual void ingresarDatosUsuario(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion) = 0;
	virtual void setNickname(std::string nickname) = 0;
	virtual void ingresarPaisResidencia(std::string pais) = 0;
	virtual void ingresarFechaNacimiento(DTFecha fechaNac) = 0;
	virtual bool confirmarAltaEstudiante() = 0;
	virtual void AltaEstudiante() = 0;
	virtual bool NicknameDisponible(std::string nickname) = 0;
	virtual void ingresarInstituto(std::string nomInstituto) = 0;
	virtual std::set<std::string> obtenerIdiomasDisponibles() = 0;
	virtual void agregarEspecializacion(std::string nomIdioma) = 0;
	virtual bool confirmarAltaProfesor() = 0;
	virtual void AltaProfesor() = 0;
	virtual std::set<std::string> obtenerCursosNoAprobados(std::string nickname) = 0;
	virtual Curso* seleccionarCurso(std::string nomCurso) = 0;
	virtual Ejercicio* seleccionarEjercicio(int idEjercicio) = 0;
	virtual void ingresarSolucion(std::string respuesta) = 0;
	virtual std::set<std::string> listarIdiomas(std::string nickname) = 0;
	virtual std::vector<DTNotificacion> notificacionesRecibidas(std::string nickname) = 0;
	virtual std::set<std::string> listaSuscripciones(std::string nickname) = 0;
	virtual void eliminarSuscripcion(std::string nomidioma) = 0;
	virtual void altaSuscripcion(std::string nomIdioma) = 0;
	virtual std::set<std::string> obtenerNicks() = 0;
	//virtual DTUsuario obtenerInfoUsuario(std::string nickname) = 0;
	virtual DTEstudiante obtenerInfoEstudiante(std::string nickname) = 0;
	virtual DTProfesor obtenerInfoProfesor(std::string nickname) = 0;
	virtual bool esEstudiante(std::string nickname) = 0;
};

#endif