#include "../include/ControladorUsuario.h"
ControladorUsuario* ControladorUsuario::instancia = NULL;
ControladorUsuario::ControladorUsuario(){

}
ControladorUsuario* ControladorUsuario::getInstance(){
    if (instancia == NULL){
        instancia = new ControladorUsuario();
    }
    return instancia;
}
void ControladorUsuario::ingresarDatosUsuario(std::string nickname, std::string contrasenia, std::string nombre, std::string descripcion){
    memNick = nickname;
    memPass = contrasenia;
    memNom = nombre;
    memDesc = descripcion;
}
void ControladorUsuario::setNickname(std::string nickname) {
    memNick = nickname;
}
void ControladorUsuario::ingresarPaisResidencia(std::string pais){
    memPais = pais;
}
void ControladorUsuario::ingresarFechaNacimiento(DTFecha fechaNac){
    memFechaNac = DTFecha(fechaNac.getDia(), fechaNac.getMes(), fechaNac.getAnio());
}
bool ControladorUsuario::confirmarAltaEstudiante(){
    bool disponible = NicknameDisponible(memNick);
    if(disponible)
        AltaEstudiante();
    return disponible;
}
void ControladorUsuario::AltaEstudiante(){
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    std::set<DTNotificacion> colDT;
    Usuario * e = new Estudiante(memNick, memPass, memNom, memDesc, colDT, memPais, memFechaNac);
    mu->agregarUsuario(e);
}
bool ControladorUsuario::NicknameDisponible(std::string nickname){
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    return !(mu->existeUsuario(nickname));
}
void ControladorUsuario::ingresarInstituto(std::string nomInstituto){
    memIns = nomInstituto;
}
std::set<std::string> ControladorUsuario::obtenerIdiomasDisponibles(){
    ManejadorIdioma * mi = ManejadorIdioma::getInstance();
    std::set<std::string> a = mi->obtenerNombres();
    return a;
}
void ControladorUsuario::agregarEspecializacion(std::string nomIdioma){
    ManejadorIdioma * mi = ManejadorIdioma::getInstance();
    Idioma * i = mi->obtenerIdioma(nomIdioma);
    IdiomasRecordados.insert(i);
}
bool ControladorUsuario::confirmarAltaProfesor(){
    bool disponible = NicknameDisponible(memNick);
    if(disponible)
        AltaProfesor();
    return disponible;
}
void ControladorUsuario::AltaProfesor(){
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    std::set<DTNotificacion> colDT;
    Usuario * p = new Profesor(memNick, memPass, memNom, memDesc, colDT, memIns);
    for (std::set<Idioma*>::iterator it = IdiomasRecordados.begin(); it != IdiomasRecordados.end(); ++it){
        dynamic_cast<Profesor*>(p)->agregarEspecializacion((*it));
    }
    //Usuario * u = p;
    mu->agregarUsuario(p);
}
std::set<std::string> ControladorUsuario::obtenerCursosNoAprobados(std::string nickname){
    std::set<std::string> a;
    return a;
}
Curso* ControladorUsuario::seleccionarCurso(std::string nomCurso){
    return nullptr;
}
Ejercicio* ControladorUsuario::seleccionarEjercicio(int idEjercicio){
    return nullptr;
}
void ControladorUsuario::ingresarSolucion(std::string respuesta){}

std::set<std::string> ControladorUsuario::listarIdiomas(std::string nickname){
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    ManejadorIdioma * mi = ManejadorIdioma::getInstance();
    Usuario * u = mu->buscarUsuario(nickname);
    memUser = u;
    std::set<std::string> set_idiomas = mi->buscarIdiomas(u);
    return set_idiomas;
}

std::vector<DTNotificacion> ControladorUsuario::notificacionesRecibidas(std::string nickname){
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    Usuario * u = mu->buscarUsuario(nickname);
    std::vector<DTNotificacion> a;
    DTNotificacion dn;
    while(!(u->getColDT().empty())) {
        dn = u->getDTNotificacion();
        a.push_back(dn);
        u->eliminarNotificacion(dn);
    }
    return a;
}
std::set<std::string> ControladorUsuario::listaSuscripciones(std::string nickname){
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    ManejadorIdioma * mi = ManejadorIdioma::getInstance();
    memUser = mu->buscarUsuario(nickname);
    std::set<std::string> a = mi->obtenerSuscripciones(memUser);
    return a;
}
void ControladorUsuario::eliminarSuscripcion(std::string nomIdioma){
    ManejadorIdioma * mi = ManejadorIdioma::getInstance();
    Idioma * i = mi->obtenerIdioma(nomIdioma);
    i->desuscribir(memUser);
}
void ControladorUsuario::altaSuscripcion(std::string nomIdioma){
    ManejadorIdioma * mi = ManejadorIdioma::getInstance();
    Idioma * i = mi->obtenerIdioma(nomIdioma);
    i->agregarSuscripcion(memUser);
}
std::set<std::string> ControladorUsuario::obtenerNicks() {
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    return mu->obtenerNicknames();
}
/*DTUsuario ControladorUsuario::obtenerInfoUsuario(std::string nickname) {
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    Usuario * u = mu->buscarUsuario(nickname);
    Estudiante * est = dynamic_cast<Estudiante*>(u);
    if(est) {
        std::string nombre = u->getNombre();
        std::string descripcion = u->getDescripcion();
        std::string pais = dynamic_cast<Estudiante*>(u)->getPais();
        DTFecha fecha = dynamic_cast<Estudiante*>(u)->getFechaNac();
        DTUsuario du = DTEstudiante(nombre, descripcion, pais, fecha);
        return du;
    }
    else {
        std::string nombre = u->getNombre();
        std::string descripcion = u->getDescripcion();
        std::string instituto = dynamic_cast<Profesor*>(u)->getInstituto();
        std::set<std::string> idiomas = dynamic_cast<Profesor*>(u)->obtenerIdiomasProfe();
        DTUsuario du = DTProfesor(nombre, descripcion, instituto, idiomas);
        return du;
    }
}*/
DTEstudiante ControladorUsuario::obtenerInfoEstudiante(std::string nickname) {
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    Usuario * u = mu->buscarUsuario(nickname);
    std::string nombre = u->getNombre();
    std::string descripcion = u->getDescripcion();
    std::string pais = dynamic_cast<Estudiante*>(u)->getPais();
    DTFecha fecha = dynamic_cast<Estudiante*>(u)->getFechaNac();
    DTEstudiante de = DTEstudiante(nombre, descripcion, pais, fecha);
    return de;
}
DTProfesor ControladorUsuario::obtenerInfoProfesor(std::string nickname) {
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    Usuario * u = mu->buscarUsuario(nickname);
    std::string nombre = u->getNombre();
    std::string descripcion = u->getDescripcion();
    std::string instituto = dynamic_cast<Profesor*>(u)->getInstituto();
    std::set<std::string> idiomas = dynamic_cast<Profesor*>(u)->obtenerIdiomasProfe();
    DTProfesor dp = DTProfesor(nombre, descripcion, instituto, idiomas);
    return dp;
}
bool ControladorUsuario::esEstudiante(std::string nickname) {
    ManejadorUsuario * mu = ManejadorUsuario::getInstance();
    Usuario * u = mu->buscarUsuario(nickname); 
    Estudiante * est = dynamic_cast<Estudiante*>(u);
    if(est)
        return true;
    else 
        return false;
}

ControladorUsuario::~ControladorUsuario(){}