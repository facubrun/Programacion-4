#include "../include/ManejadorUsuario.h"
ManejadorUsuario* ManejadorUsuario::instancia = NULL;
ManejadorUsuario::ManejadorUsuario(){}
ManejadorUsuario* ManejadorUsuario::getInstance(){
    if (instancia == NULL){
        instancia = new ManejadorUsuario();
    }
    return instancia;
}
std::set<std::string> ManejadorUsuario::obtenerNicknames(){
    std::set<std::string> a;
    for (std::map<std::string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it){
        a.insert(it->first);
    }
    return a;
}
Profesor* ManejadorUsuario::seleccionarProfesor(std::string nickname){
    for (auto it=usuarios.begin(); it!=usuarios.end(); it++){
        if (Profesor* prof = dynamic_cast<Profesor*>(it->second)){
            if ((prof->getNickname()) == nickname)
                return dynamic_cast <Profesor*>(prof);
        }
            
    }
    return NULL;
}
bool ManejadorUsuario::existeUsuario(std::string nickname){
    return usuarios.find(nickname) != usuarios.end();
}
void ManejadorUsuario::agregarUsuario(Usuario *u){
    usuarios.insert(make_pair(u->getNickname(),u));
}
std::set<std::string> ManejadorUsuario::obtenerNombres(){
    std::set<std::string> a;
    return a;
}
void ManejadorUsuario::eliminarCurso(std::string nomCurso){}
std::set<std::string> ManejadorUsuario::obtenerCursosNoAp(std::string){
    std::set<std::string> a;
    return a;
}
std::set<std::string> ManejadorUsuario::obtenerEstudiantes(){
    std::set<std::string> nicks;
    for (auto it=usuarios.begin(); it!=usuarios.end(); it++){
        if(Estudiante * e = dynamic_cast<Estudiante*>(it->second)){
            nicks.insert(e->getNickname());
        };
    }
    return nicks;
}
Estudiante* ManejadorUsuario::seleccionarEstudiante(std::string nickname){
    for (auto it=usuarios.begin(); it!=usuarios.end(); it++){
        if (Estudiante* est = dynamic_cast<Estudiante*>(it->second))
            if ((est->getNickname()) == nickname)
                return dynamic_cast<Estudiante*>(est);
    };
    return NULL;
}
std::set<std::string> ManejadorUsuario::obtenerProfesores(){
    std::set<std::string> nicks;
    for (auto it=usuarios.begin(); it!=usuarios.end(); it++){
        if(Profesor * p = dynamic_cast<Profesor*>(it->second)){
            nicks.insert(p->getNickname());
        };
    };
    return nicks;
}
Usuario * ManejadorUsuario::buscarUsuario(std::string nickname){
    return usuarios.find(nickname)->second;
}
bool ManejadorUsuario::estudianteNoAprobo(Ejercicio *ej){
    return 0;
}
ManejadorUsuario::~ManejadorUsuario(){}