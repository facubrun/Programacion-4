#include "../include/Leccion.h"

Leccion::Leccion(std::string tema, std::string objetivo){
    this->tema = tema;
    this->objetivo = objetivo;
}
std::string Leccion::getTema(){
    return this->tema;
}

void Leccion::agregarEjercicioCompletar(Ejercicio* ejcom){
    ejercicios.push_back(ejcom);
}
void Leccion::agregarEjercicioTraduccion(Ejercicio* ejtrad){
    ejercicios.push_back(ejtrad);
}
Ejercicio* Leccion::obtenerEjercicio(int idEjercicio){
    return ejercicios[idEjercicio];
     
}
std::set<Ejercicio*> Leccion::obtenerEjercicios(){
    std::set<Ejercicio*> a;
    return a;
}
bool Leccion::verificarEjs(){
    return 0;
}
Leccion::~Leccion(){}