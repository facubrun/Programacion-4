#ifndef INSCRIPCION
#define INSCRIPCION

#include <string>
#include <set>
#include "Curso.h"
#include "DTFecha.h"

class Inscripcion { 
	private:
		DTFecha fechaIns = DTFecha(0,0,0);
		bool aprobado;
		Curso* curso;
	public:
		Inscripcion(DTFecha fechaIns, bool aprobado);
		DTFecha getFechaIns();
		bool getAprobado();
		bool esDeEsteCurso(std::string nomCurso);
		bool compararCursos(Curso* c);
		~Inscripcion();
};

#endif