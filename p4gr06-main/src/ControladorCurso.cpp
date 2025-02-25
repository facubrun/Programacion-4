#include "../include/ControladorCurso.h"
ControladorCurso* ControladorCurso::instancia = NULL;
ControladorCurso::ControladorCurso(){}
ControladorCurso* ControladorCurso::getInstance(){
    if (instancia == NULL){
        instancia = new ControladorCurso();
    }
    return instancia;
}
std::set<std::string> ControladorCurso::obtenerNicksProfes(){
    ManejadorUsuario * mu;
    mu = ManejadorUsuario::getInstance();
    return mu->obtenerProfesores();
}

void ControladorCurso::seleccionarProfesor(std::string nickname){
    ManejadorUsuario * mu;
    mu = ManejadorUsuario::getInstance();
    Profesor * prof = mu->seleccionarProfesor(nickname);
    if (prof !=NULL)
        this->memProfesorRecordado = prof;
}
void ControladorCurso::ingresarDatosCurso(std::string nomCurso, std::string descripcionCurso, enumDificultad dificultad){
    this->memNomCurso = nomCurso;
    this->memDescCurso = descripcionCurso;
    this->memDificultad = dificultad;
}

std::set<std::string> ControladorCurso::obtenerIdiomasProfe(){
    return memProfesorRecordado->obtenerIdiomasProfe();
}
Idioma* ControladorCurso::seleccionarIdioma(std::string nomIdioma){
    ManejadorIdioma * mi;
    mi = ManejadorIdioma::getInstance();
    Idioma * i = mi->obtenerIdioma(nomIdioma);
    if (i !=NULL)
        this->memIdiomaRecordado = i;
    return i;
}
std::set<std::string> ControladorCurso::obtenerCursosHabilitados(){
    ManejadorCurso *mc;
    mc= ManejadorCurso::getInstance();
    std::set<std::string> cursosh;
    std::set<std::string> cursos2=mc->obtenerCursos();
    for (std::set<std::string>::iterator it = cursos2.begin(); it != cursos2.end(); it++){
        Curso* c;
        c=mc->buscarCurso((*it));
        if (c->getHabilitado()){
            cursosh.insert((*it));
        }
    }
    return cursosh;
}
void ControladorCurso::agregarPrevia(std::string nomPrevia){
    ManejadorCurso * mu = ManejadorCurso::getInstance();
    Curso * pr = mu->buscarCurso(nomPrevia);
    previasRecordadas.insert((pr)); 
}
void ControladorCurso::agregarLeccion(std::string nomTema, std::string objetivo){
    memIdLRec++;
    Leccion * L = new Leccion(/*memIdLRec++,*/ nomTema, objetivo);
    leccionesRecordadas.push_back(L);
} 
void ControladorCurso::agregarEjercicioCompletar(std::string FraseACompletar, std::string solucion){
    Leccion * L = leccionesRecordadas[memIdLRec-1];
    Ejercicio * ej = new Completar(solucion, FraseACompletar);
    L->agregarEjercicioCompletar(dynamic_cast<Ejercicio*>(ej));
}
void ControladorCurso::agregarEjercicioTraducir(std::string FraseATraducir, std::string solucion){
    Leccion * L = leccionesRecordadas[memIdLRec-1];
    Ejercicio * ej = new Traduccion(solucion, FraseATraducir);
    L->agregarEjercicioTraduccion(dynamic_cast<Ejercicio*>(ej));
}
void ControladorCurso::confirmarAltaCurso(){
    ManejadorCurso * mc = ManejadorCurso::getInstance();
    Curso *c= new Curso(memNomCurso, memDescCurso, memDificultad, true);
    c->agregarIdioma(memIdiomaRecordado);
    c->agregarProfesor(memProfesorRecordado);
    memProfesorRecordado->agregarCurso(c);
    for(std::set<Curso*>::iterator it = previasRecordadas.begin(); it != previasRecordadas.end(); ++it) {
        c->AgregarPrevia((*it));
    }
    for(std::vector<Leccion*>::iterator it = leccionesRecordadas.begin(); it != leccionesRecordadas.end(); ++it) {
        c->AgregarLeccion(*it);
    }
    mc->agregarCurso(c);
    memIdiomaRecordado->nuevoCurso();
}
std::set<std::string> ControladorCurso::obtenerCursos(){
    ManejadorCurso * mc;
    mc = ManejadorCurso::getInstance();
    return mc->obtenerCursos();
}
void ControladorCurso::eliminarCurso(std::string nomCurso){

}
std::set<std::string> ControladorCurso::obtenerEstudiantes(){
    ManejadorUsuario * mu;
    mu = ManejadorUsuario::getInstance();
    return mu->obtenerEstudiantes();
}
void ControladorCurso::seleccionarEstudiante(std::string nickname){
    ManejadorUsuario * mu;
    mu = ManejadorUsuario::getInstance();
    Estudiante * est = mu->seleccionarEstudiante(nickname);
    if (est !=NULL)
        this->memEstudianteRecordado = est;
}
std::vector<DTAvanceEstudiante> ControladorCurso::obtenerAvanceEstudiante(){
    std::vector<DTAvanceEstudiante> advance;
    if(this->memEstudianteRecordado != NULL){
        std::set<Curso*> cursos= this->memEstudianteRecordado->obtenerCursos();
        for( auto iterador = cursos.begin(); iterador != cursos.end();iterador++){
            int cantAprobados = 0;
            float avance = 0;
            DTCurso info = (*iterador)->obtenerInfoCurso();
            std::string name = info.getNombre();
            std::string des = info.getDescripcion();
            enumDificultad dif = info.getDificultad();
            std::set<DTEjercicio> ejercicios = (*iterador)->obtenerEjercicios();
            int cantEj = ejercicios.size();
            std::map<int,Ejercicio*> aprobado = (this->memEstudianteRecordado)->getEjerciciosAprobados();
            for (auto it = ejercicios.begin(); it != ejercicios.end(); it++){
                int id = (*it).getidEjercicio();
                if (aprobado.find(id)!=aprobado.end())
                    cantAprobados++;
            };
            if (cantEj!=0)
                avance = (100*cantAprobados)/cantEj;
                
            advance.push_back(DTAvanceEstudiante(name,des,dif,avance));

        }
    };
    return advance;
}
std::vector<DTAvanceCurso> ControladorCurso::obtenerAvanceProfesor(){
    std::vector<DTAvanceCurso> advance;
    if(this->memProfesorRecordado != NULL){
        std::set<Curso*> cursos = (this->memProfesorRecordado)->obtenerCursos();
        for (auto iterador = cursos.begin(); iterador != cursos.end(); iterador++){
            int avanceCurso = 0;
            int cantEst = 0;
            int avanceTotal = 0;
            std::set<Estudiante*> estudiantes = (*iterador)->obtenerEst();
            std::set<DTEjercicio> ejercicios = (*iterador)->obtenerEjercicios();
            int cantEj = ejercicios.size();
            for (auto iterador2 = estudiantes.begin(); iterador2 != estudiantes.end(); iterador2++ ){
                int avance = 0;
                this->memEstudianteRecordado = (*iterador2);
                cantEst++;
                int cantAprobados = 0;
                std::map<int,Ejercicio*> aprobado = (this->memEstudianteRecordado)->getEjerciciosAprobados();
                for (auto it = ejercicios.begin(); it != ejercicios.end(); it++){
                    int id = (*it).getidEjercicio();
                    if (aprobado.find(id) != aprobado.end())
                        cantAprobados++;
                };
                if (cantEj!=0)
                    avance = (100*cantAprobados)/cantEj;
                avanceTotal = avanceTotal + avance;
            };
            if (cantEst != 0)
                avanceCurso = (avanceTotal)/cantEst;
            DTCurso info = (*iterador)->obtenerInfoCurso();
            std::string name = info.getNombre();
            std::string des = info.getDescripcion();
            enumDificultad dif = info.getDificultad();
            advance.push_back(DTAvanceCurso(name,des,dif,avanceCurso));
        };
    }
    return advance;
}
DTAvanceCurso ControladorCurso::obtenerAvanceCurso(){
    std::string name = (this->memCursoRecordado)->getNombre();
    std::string des = (this->memCursoRecordado)->getDescripcion();
    enumDificultad dif = (this->memCursoRecordado)->getDificultad();
    std::set<Estudiante*> estudiantes = (this->memCursoRecordado)->obtenerEst();//falta imple,emtat
    int cantEst = 0;
    int avanceCurso = 0;
    int avanceTotal = 0;
    std::set<DTEjercicio> ejercicios = (this->memCursoRecordado)->obtenerEjercicios();//falta implementar
    int cantEj = ejercicios.size();
    for (auto iterador = estudiantes.begin(); iterador != estudiantes.end(); iterador++){
        int avance = 0;
        cantEst++;
        int cantAprobados = 0;
        std::map<int,Ejercicio*> aprobado = (*iterador)->getEjerciciosAprobados();//falta implementar
        for (auto it = ejercicios.begin(); it != ejercicios.end(); it++){
            int id = (*it).getidEjercicio();
            if (aprobado.find(id) != aprobado.end())
                cantAprobados++;
        };
        if (cantEj!=0)
            avance = (100*cantAprobados)/cantEj;
        avanceTotal = avanceTotal + avance;
        };
        if (cantEst != 0)
            avanceCurso = (avanceTotal)/cantEst;
        DTAvanceCurso advance = DTAvanceCurso(name,des,dif,avanceCurso);
        
    return advance;
}


std::set<DTEjercicio> ControladorCurso::obtenerEjercicios(){
    std::set<DTEjercicio> a;
    return a;
}
bool ControladorCurso::altaIdioma(std::string nomIdioma){
    bool alta = false;
    ManejadorIdioma * mi;
    mi = ManejadorIdioma::getInstance();
    Idioma * language = mi->obtenerIdioma(nomIdioma);
    if (language == NULL){
        alta = true;
        language = new Idioma(nomIdioma);
        mi->agregarIdioma(language);
    };
    return alta;
}
void ControladorCurso::seleccionarCurso(std::string nomCurso){
    ManejadorCurso * mc;
    mc = ManejadorCurso::getInstance();
    Curso * course = mc->seleccionarCurso();
    if (course != NULL)
        this->memCursoRecordado = course;
}
std::set<std::string> ControladorCurso::consultarIdiomas(){
    ManejadorIdioma * mi;
    mi = ManejadorIdioma::getInstance();
    return mi->obtenerNombres();
}
ControladorCurso::~ControladorCurso(){
    
}