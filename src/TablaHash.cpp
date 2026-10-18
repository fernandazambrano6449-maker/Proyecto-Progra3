//
// Created by ferna on 10/15/2026.
//

#include "TablaHash.h"

TablaHash::TablaHash() {
    capacidad = 10; //tabla con 10 casillas
    casillas = new Casilla[capacidad]; //reservar memoria para 10 casillas

    for (int i=0; i<capacidad; i++) { //inicializar casillas en estado vacio
        casillas[i].estado = VACIO;
    }
}
    TablaHash::~TablaHash() { //destructor
        delete[] casillas;
    }

bool TablaHash::insertar(const Registro& r) {
    //se recibe el registro

    int posicion=r.id % capacidad; //calcular la posicion, casilla que se esta revisando actualmente
    int primeraEliminada=-1; //recuerda la primera casilla eliminada que se encontro

    for (int i=0; i<capacidad;i++) {
        //recorrer la tabla
        
        if (casillas[posicion].estado==OCUPADO &&
            casillas[posicion].dato.id==r.id) {
            return false;
            }//comprobar si el id ya existe

        if (casillas[posicion].estado==VACIO) {
            //si se encuentra una casilla vacia
            if (primeraEliminada != -1) { //si antes se encuentra una casilla eliminada, se reutiliza
                posicion=primeraEliminada;
            }
            casillas[posicion].dato=r; //se guarda el registro
            casillas[posicion].estado=OCUPADO; //se cambia su estado a ocupado
            return true;
        }

        ////////////////
        if (casillas[posicion].estado==ELIMINADO &&
            primeraEliminada==-1) {
            //recordar primera casilla eliminada
            primeraEliminada=posicion;
            }
        posicion=(posicion+1) % capacidad; //avanzar a la siguiente posicion, se empieza otra vez el for
    }

        if (primeraEliminada != -1) { //si se encuentra una casilla eliminada...
            casillas[primeraEliminada].dato=r; //se guarda el registro
            casillas[primeraEliminada].estado=OCUPADO; //se cambia su estado a ocupado
            return true; //devuelve true si la inserción fue exitosa
        }
        return false; //si no encontró ninguna casilla disponible devuelve false
    }











