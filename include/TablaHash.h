//
// Created by ferna on 10/15/2026.
//

#ifndef MINIDB_TABLAHASH_H
#define MINIDB_TABLAHASH_H
#include "Registro.h"

enum EstadoCasilla {
    VACIO,
    ELIMINADO,
    OCUPADO
};

struct Casilla {
    Registro dato;
    EstadoCasilla estado;
};

#endif //MINIDB_TABLAHASH_H
