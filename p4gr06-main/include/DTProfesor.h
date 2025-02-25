#ifndef DTPROFESOR
#define DTPROFESOR

#include <string>
#include <set>
#include <iostream>
#include "DTUsuario.h"

class DTProfesor : public DTUsuario{
	private:
		std::string nomInstituto;
		std::set<std::string> nomEspec; 
	public:
		DTProfesor();
		DTProfesor(std::string nombre, std::string descripcion, std::string instituto, std::set<std::string> espec);
		std::string getNomInstituto();
		std::set<std::string> getNomEspec();
		void setNomInstituto(std::string instituto);
		void imprimirDatosRestantes(std::ostream& os);
};

#endif