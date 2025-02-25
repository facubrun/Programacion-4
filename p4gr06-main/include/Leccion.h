#ifndef LECCION
#define LECCION

#include <string>
#include <vector>
#include <set>
#include "Ejercicio.h"
#include "DTEjercicio.h"

class Leccion {
	private:
		std::string tema;
		std::string objetivo;
        std::vector<Ejercicio*> ejercicios; 
	public:
	    Leccion(std::string tema, std::string objetivo);
		std::string getTema();
		void agregarEjercicioCompletar(Ejercicio* ejcom);
        void agregarEjercicioTraduccion(Ejercicio* ejtrad);
        std::set<DTEjercicio> obtenerDatosEjercicios();
        Ejercicio* obtenerEjercicio(int idEjercicio);
        std::set<Ejercicio*>obtenerEjercicios();
        bool verificarEjs();
        ~Leccion();
};


#endif