#ifndef FABRICA
#define FABRICA

#include "ICurso.h"
#include "IUsuario.h"
#include "ControladorUsuario.h"
#include "ControladorCurso.h"

class Fabrica {
    private:
        ControladorUsuario* ctrlUsuario;
        ControladorCurso* ctrlCurso;
	public:
        IUsuario* getIUsuario();
        ICurso* getICurso();
};

#endif