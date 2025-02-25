#ifndef EJERCICIO
#define EJERCICIO

#include <string>

class Ejercicio {
	private:
		std::string solucion;
        int idEjercicio;
	public:
	    Ejercicio(std::string solucion);
		std::string getSolucion();
        virtual std::string getFrase() = 0;
        virtual ~Ejercicio();
};


#endif