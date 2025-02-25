#ifndef USUARIO
#define USUARIO

#include <string>
#include <set>
#include <vector>
#include "DTNotificacion.h"


class Usuario {
	private:
	    std::string nickname;
	    std::string contrasenia;
	    std::string nombre;
	    std::string descripcion;
	    std::vector<DTNotificacion> colDT;
	public:
		Usuario(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion, std::set<DTNotificacion> colDT);
		std::string getNickname();
		std::string getContrasenia();
		std::string getNombre();
		std::string getDescripcion();
		std::vector<DTNotificacion> getColDT();
		DTNotificacion getDTNotificacion();
		void setColDT();
		virtual void notificar(DTNotificacion dn);
		void eliminarNotificacion(DTNotificacion dn);
		virtual ~Usuario();

};


#endif