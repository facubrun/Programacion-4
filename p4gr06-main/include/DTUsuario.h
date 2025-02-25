#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>
#include <iostream>
#include <set>

class DTProfesor;
class DTEstudiante;

class DTUsuario {
  private:
    std::string nombre;
    std::string descripcion;
     
  public:
    DTUsuario();
    DTUsuario(std::string nombre, std::string descripcion);
    std::string getNombre();
    std::string getDescripcion();
    void setNombre(std::string nom);
    void setDescripcion(std::string desc);
    virtual void imprimirDatosRestantes(std::ostream& os);
    //virtual ~DTUsuario()
};

std::ostream& operator<<(std::ostream& os, DTUsuario& usuario);

#include "DTProfesor.h"
#include "DTEstudiante.h"

#endif