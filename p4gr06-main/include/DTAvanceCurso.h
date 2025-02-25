#ifndef DTAVANCECURSO
#define DTAVANCECURSO

#include <string>
#include "enumDificultad.h"

class DTAvanceCurso {
  private:
    std::string nombreCurso;
    std::string descripcionCurso;
    enumDificultad dificultadCurso; 
    float avanceCurso;
  public:
    DTAvanceCurso();
    DTAvanceCurso(std::string nombreCurso, std::string descripcionCurso, enumDificultad dificultadCurso, float avanceCurso);
    std::string getNombreCurso();
    std::string getDescripcionCurso();
    enumDificultad getDificultadCurso();
    float getAvanceCurso();
};

#endif