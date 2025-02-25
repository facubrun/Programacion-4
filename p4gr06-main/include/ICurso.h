#ifndef ICURSO
#define ICURSO

#include <string>
#include <set>
#include <vector>
#include "DTFecha.h"
#include "Curso.h"
#include "Ejercicio.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "DTAvanceEstudiante.h"
#include "DTAvanceCurso.h"
#include "DTNotificacion.h"
#include "DTEjercicio.h"
#include "DTNotificacion.h"
#include "enumDificultad.h"

class ICurso {
  public:
		static ICurso* getInstance();
		virtual std::set<std::string> obtenerNicksProfes() = 0;
		virtual void seleccionarProfesor(std::string nickname) = 0;
		virtual void ingresarDatosCurso(std::string nomCurso, std::string descripcionCurso, enumDificultad dificultad)= 0;
		virtual std::set<std::string> obtenerIdiomasProfe() = 0;
		virtual Idioma* seleccionarIdioma(std::string nomIdioma) = 0;
		virtual std::set<std::string> obtenerCursosHabilitados() = 0;
		virtual void agregarPrevia(std::string nomPrevia) = 0;
		virtual void agregarLeccion(std::string nomTema, std::string objetivo) = 0;
		virtual void agregarEjercicioCompletar(std::string FraseACompletar, std::string solucion) = 0;
		virtual void agregarEjercicioTraducir(std::string FraseATraducir, std::string solucion) = 0;
		virtual void confirmarAltaCurso() = 0;
		virtual std::set<std::string> obtenerCursos() = 0;
		virtual void eliminarCurso(std::string nomCurso) = 0;
		virtual std::set<std::string> obtenerEstudiantes() = 0;
		virtual void seleccionarEstudiante(std::string nickname) = 0;
		virtual std::vector<DTAvanceEstudiante> obtenerAvanceEstudiante() = 0;
		virtual std::vector<DTAvanceCurso> obtenerAvanceProfesor() = 0;
		virtual DTAvanceCurso obtenerAvanceCurso() = 0;
		virtual std::set<DTEjercicio> obtenerEjercicios() = 0;
		virtual std::set<std::string>  consultarIdiomas() = 0;
		virtual bool altaIdioma(std::string nomIdioma) = 0;
		virtual void seleccionarCurso(std::string nomCurso) = 0;
};

#endif