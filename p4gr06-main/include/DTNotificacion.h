#ifndef DTNOTIFICACION
#define DTNOTIFICACION

#include <string>

class DTNotificacion {
	private:
		std::string nomIdioma;
		std::string nomCurso; 
	public:
		DTNotificacion();
		DTNotificacion(std::string nomIdioma, std::string nomCurso);
		std::string getnomIdioma();
		std::string getnomCurso();
};

#endif