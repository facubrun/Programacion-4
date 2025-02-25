#ifndef MANEJADORIDIOMA
#define MANEJADORIDIOMA

#include <string>
#include <set>
#include <map>
#include "Idioma.h"

class ManejadorIdioma {
    private:
        static ManejadorIdioma* instancia;
        ManejadorIdioma();
        std::map<std::string, Idioma*> idiomas;
    public:
        static ManejadorIdioma* getInstance();
        std::set<std::string> obtenerNombres();
        Idioma* obtenerIdioma(std::string nomIdioma);
        std::set<std::string> buscarIdiomas(Usuario * u);
        std::set<std::string> obtenerSuscripciones(Usuario * u);
        void agregarIdioma(Idioma * nomIdioma);
        ~ManejadorIdioma();
};

#endif