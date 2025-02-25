#include "../include/Curso.h"
#include <string>

Curso::Curso(std::string nombre, std::string descripcion, enumDificultad dificultad, bool habilitado){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->habilitado = habilitado;
}
std::string Curso::getNombre(){
    return this->nombre;
}
std::string Curso::getDescripcion(){
    return this->descripcion;
}
enumDificultad Curso::getDificultad(){
    return this->dificultad;
}
bool Curso::getHabilitado(){
    return this->habilitado;
}
void Curso::agregarIdioma(Idioma* idioma){
    this->idioma=idioma;
}
void Curso::agregarProfesor(Profesor* profesor){
    this->profesor=profesor;
}
void Curso::AgregarPrevia(Curso* previa){
 previas.insert(previa);
}
void Curso::AgregarLeccion(Leccion* leccion){
    //int id = leccion->getidLeccion();
    lecciones.push_back(leccion);
}
void Curso::EliminarInscripcionEstudiantes(){}
Profesor* Curso::obtenerProfesor(){
    return nullptr;
}
void Curso::desvincularPrevia(Curso*){}
std::set<DTEjercicio> Curso::obtenerEjercicios(){
    std::set<DTEjercicio> a;
    return a;
}
Ejercicio* Curso::obtenerEjercicio(int idEjercicio){
    return nullptr;
}
std::set<Estudiante*> Curso::obtenerEst(){
    return this->estudiantesInscriptos;
}
void Curso::contarLecciones(){}
DTCurso Curso::obtenerInfoCurso(){
    DTCurso a = DTCurso("a", "b", Avanzado);
    return a;
}