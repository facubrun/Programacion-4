#ifndef COMPLETAR
#define COMPLETAR

#include <string>
#include "Ejercicio.h"
 
class Completar: public Ejercicio {
	private:
		std::string fraseACompletar;
	public:
	    Completar(std::string solucion, std::string fraseACompletar);
		std::string getFrase();
        ~Completar();
};

#endif