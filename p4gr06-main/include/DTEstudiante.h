#ifndef DTESTUDIANTE
#define DTESTUDIANTE

#include <string>
#include <iostream>
#include "DTFecha.h"
#include "DTUsuario.h"

class DTEstudiante : public DTUsuario{
  private:
    std::string pais;
    DTFecha fecha;
     
  public:
    DTEstudiante();
    DTEstudiante(std::string nombre, std::string descripcion, std::string pais, DTFecha fecha);
    std::string getPais();
    DTFecha getFecha();
    void setPais(std::string paisR);
    void setFecha(DTFecha fechaNac);
    void imprimirDatosRestantes(std::ostream& os);
};

#endif