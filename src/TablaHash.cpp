//
// Created by ferna on 10/15/2026.
//

#include "TablaHash.h"

TablaHash::TablaHash() {
    capacidad = 10; //tabla con 10 casillas
    casillas = new Casilla[capacidad]; //reservar memoria

    for (int i=0; i<capacidad; i++) { //inicializar cacillas en estado vacio
        casillas[i].estado = VACIO;
    }
}
    TablaHash::~TablaHash() { //destructor
        delete[] casillas;
    }

