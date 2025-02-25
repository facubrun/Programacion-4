#ifndef CONTROLADORCURSO
#define CONTROLADORCURSO

#include <string>
#include <set>
#include <vector>
#include "DTFecha.h"
#include "Curso.h"
#include "Ejercicio.h" 
#include "Profesor.h"
#include "Estudiante.h"
#include "Leccion.h"
#include "DTAvanceEstudiante.h"
#include "DTAvanceCurso.h"
#include "DTNotificacion.h"
#include "DTEjercicio.h"
#include "DTNotificacion.h"
#include "DTCurso.h"
#include "ICurso.h"
#include "enumDificultad.h"
#include "ManejadorCurso.h"
#include "ManejadorUsuario.h"
#include "ManejadorIdioma.h"
#include "Completar.h"
#include "Traduccion.h"

class ControladorCurso : public ICurso{
  private:
		  static ControladorCurso* instancia;
		  ControladorCurso();
		  Estudiante * memEstudianteRecordado;
		  Profesor * memProfesorRecordado;
		  Curso * memCursoRecordado;
		  Idioma * memIdiomaRecordado;
		  std::string memNomCurso;
		  std::string memDescCurso;
		  enumDificultad memDificultad;
		  std::set<Curso*> previasRecordadas;
		  std::vector<Leccion*> leccionesRecordadas;
		  int memIdEjc=0;
		  int memIdEjt=0;
		  int memIdLRec=0 ;
  public:
			static ControladorCurso* getInstance();
			std::set<std::string> obtenerNicksProfes();
			void seleccionarProfesor(std::string nickname);
			void ingresarDatosCurso(std::string nomCurso, std::string descripcionCurso, enumDificultad dificultad);
			std::set<std::string> obtenerIdiomasProfe();
			Idioma* seleccionarIdioma(std::string nomIdioma);
			std::set<std::string> obtenerCursosHabilitados();
			void agregarPrevia(std::string nomPrevia);
			void agregarLeccion(std::string nomTema, std::string objetivo);
			void agregarEjercicioCompletar(std::string FraseACompletar, std::string solucion);
			void agregarEjercicioTraducir(std::string FraseATraducir, std::string solucion);
			void confirmarAltaCurso();
			std::set<std::string> obtenerCursos();
			void eliminarCurso(std::string nomCurso);
			std::set<std::string> obtenerEstudiantes();
			void seleccionarEstudiante(std::string nickname);
			std::vector<DTAvanceEstudiante> obtenerAvanceEstudiante();
			std::vector<DTAvanceCurso> obtenerAvanceProfesor();
			DTAvanceCurso obtenerAvanceCurso();
			std::set<DTEjercicio> obtenerEjercicios();
			void seleccionarCurso(std::string nomCurso);
			bool altaIdioma(std::string nomIdioma);
			std::set<std::string> consultarIdiomas();
			~ControladorCurso();
};

#endif