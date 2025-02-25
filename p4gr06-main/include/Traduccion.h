#ifndef TRADUCCION
#define TRADUCCION

#include <string>
#include "Ejercicio.h"

class Traduccion: public Ejercicio {
	private:
		std::string fraseATraducir;
	public:
	    Traduccion(std::string solucion, std::string fraseATraducir);
		std::string getFrase();
        ~Traduccion();
};

#endif