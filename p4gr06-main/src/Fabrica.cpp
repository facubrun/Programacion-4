#include "../include/Fabrica.h"

IUsuario* Fabrica::getIUsuario(){
    return ctrlUsuario->getInstance();
}
ICurso* Fabrica::getICurso(){
    return ctrlCurso->getInstance();
}