#include "../include/ManejadorCurso.h"
ManejadorCurso* ManejadorCurso::instancia = NULL;
ManejadorCurso::ManejadorCurso(){}
ManejadorCurso* ManejadorCurso::getInstance(){
    if (instancia == NULL){
        instancia = new ManejadorCurso();
    }
    return instancia;
}
/*std::set<std::string> ManejadorCurso::obtenerNicknames(){
    std::set<std::string> a;
    for (std::map<std::string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it){
        a.insert(it->first);
    }
    return a;
}*/
void ManejadorCurso::agregarCurso(Curso* c){
    cursos.insert(make_pair(c->getNombre(),c));
}

std::set<std::string> ManejadorCurso::obtenerCursos(){
    std::set<std::string> nombres;
    for (auto it = cursos.begin(); it != cursos.end(); it++)
        nombres.insert(it->first);
    return nombres;
}
Curso* ManejadorCurso::seleccionarCurso(){
    return nullptr;
}
void ManejadorCurso::verificarPrevia(){}
void ManejadorCurso::eliminarCurso(){}
Curso* ManejadorCurso::buscarCurso(std::string nomCurso) {
    return cursos.find(nomCurso)->second;
}
std::set<std::string> ManejadorCurso::obtenerEstudiantes(){
    std::set<std::string> a;
    return a;
}
ManejadorCurso::~ManejadorCurso(){}