#ifndef DTCURSO
#define DTCURSO

#include <string>
#include "enumDificultad.h"

class DTCurso {
  private:
    std::string nomCurso;
    std::string descripcion;
    enumDificultad dificultad; 
  public:
    DTCurso(std::string nomCurso, std::string descripcion, enumDificultad dificultad);
    std::string getNombre() const;
    std::string getDescripcion() const;
    enumDificultad getDificultad() const;
};

#endif