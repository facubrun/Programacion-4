#ifndef DTEJERCICIO
#define DTEJERCICIO

#include <string>

class DTEjercicio {
	private:
		int idEjercicio;
		std::string tipoEjercicio;
		std::string descripcion;
	public:
		DTEjercicio(int idEjercicio, std::string tipoEjercicio, std::string descripcion);
		int getidEjercicio() const;
        std::string getTipoEjercicio() const;
        std::string getdescripcion() const;
};

#endif