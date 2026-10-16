//
// Created by ferna on 10/15/2026.
//

#ifndef MINIDB_TABLAHASH_H
#define MINIDB_TABLAHASH_H
#include "Registro.h"

enum EstadoCasilla { //estados de la casilla
    VACIO,
    ELIMINADO,
    OCUPADO
};

struct Casilla { //creacion de una casilla
    Registro dato;
    EstadoCasilla estado;
};

class TablaHash { //clase
private: //datos internos para proteger
    Casilla* casillas; //puntero
    int capacidad;
public: //funciones que se pueden usar desde fuera
TablaHash();~TablaHash();
};


#endif //MINIDB_TABLAHASH_H
