#ifndef DTAVANCEESTUDIANTE
#define DTAVANCEESTUDIANTE

#include <string>
#include "enumDificultad.h"

class DTAvanceEstudiante {
  private:
    std::string nombreCurso;
    std::string descripcionCurso;
    enumDificultad dificultadCurso; 
    float avanceEstudiante;
  public:
    DTAvanceEstudiante();
    DTAvanceEstudiante(std::string nombreCurso, std::string descripcionCurso, enumDificultad dificultadCurso, float avanceEstudiante);
    std::string getNombreCurso() const;
    std::string getDescripcionCurso() const;
    enumDificultad getDificultadCurso() const;
    float getAvanceEstudiante() const;
};

#endif