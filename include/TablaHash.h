//
// Created by ferna on 10/15/2026.
//

#ifndef MINIDB_TABLAHASH_H
#define MINIDB_TABLAHASH_H
#include "Registro.h"

enum EstadoCasilla { //enum sirve para crear un tipo de dato enumerado llamado EstadoCasilla, cuyos  valores son VACIO, ELIMINADO y OCUPADO
    VACIO,
    ELIMINADO,
    OCUPADO
};

struct Casilla { //creacion de una casilla. Cada casilla guarda un dato(un registro de la base de datos) y un estado
    Registro dato;
    EstadoCasilla estado;
};

class TablaHash { //clase
private: //datos internos para proteger
    Casilla* casillas; //puntero
    int capacidad;
public: //funciones que se pueden usar desde fuera
TablaHash();~TablaHash();
    bool insertar(const Registro& r); //recibe un registro llamado r 

};


#endif //MINIDB_TABLAHASH_H
