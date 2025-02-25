#ifndef CURSO
#define CURSO

#include <string>
#include <vector>
#include "DTCurso.h"
#include "Leccion.h"
#include "DTEjercicio.h"
#include "Ejercicio.h"
#include "enumDificultad.h"

class Idioma;
class Profesor;
class Estudiante;
class Inscripcion;

class Curso {
	private:
		std::string nombre;
        std::string descripcion;
        enumDificultad dificultad;
        bool habilitado;
        std::set<Estudiante*> estudiantesInscriptos;
        Profesor* profesor;
        std::set<Curso*> previas;
        std::vector<Leccion*> lecciones;
        Idioma* idioma;
	public:
        Curso(std::string nombre, std::string descripcion, enumDificultad dificultad, bool habilitado);
        std::string getNombre();
        std::string getDescripcion();
        enumDificultad getDificultad();
        bool getHabilitado();
		void agregarIdioma(Idioma* idioma);
        void agregarProfesor(Profesor* profesor);
        void AgregarPrevia(Curso* previa);
        void AgregarLeccion(Leccion* leccion) ;
        void EliminarInscripcionEstudiantes();
        Profesor* obtenerProfesor();
        void desvincularPrevia(Curso*);
        std::set<DTEjercicio> obtenerEjercicios();
        Ejercicio* obtenerEjercicio(int idEjercicio);
        std::set<Estudiante*> obtenerEst();
        void contarLecciones();
        DTCurso obtenerInfoCurso();
        ~Curso();
};

#include "Idioma.h"
#include "Profesor.h"
#include "Estudiante.h"

#endif