//
// Created by ferna on 10/15/2026.
//
#include <iostream>
#include "TablaHash.h"

TablaHash::TablaHash() {
    capacidad = 10; //tabla con 10 casillas
    casillas = new Casilla[capacidad]; //reservar memoria para 10 casillas
    contador=0; //contar registros ocupados
    eliminadas=0; //contar casillas eliminadas

    for (int i=0; i<capacidad; i++) { //inicializar casillas en estado vacio
        casillas[i].estado = VACIO;
    }
}
    TablaHash::~TablaHash() { //destructor
        delete[] casillas;
    }

//INSERTAR
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
                eliminadas--; //se resta 1 eliminada si se reutilizo una casilla eliminada
            }
            //cuando encuentra una casilla vacia
            casillas[posicion].dato=r; //se guarda el registro
            casillas[posicion].estado=OCUPADO; //se cambia su estado a ocupado
            contador++;
            verificarCarga();
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
            contador ++;
            eliminadas--;
            verificarCarga();
            return true; //devuelve true si la inserción fue exitosa
        }
        return false; //si no encontró ninguna casilla disponible devuelve false
    }

//BUSCAR
bool TablaHash::buscar(int id, Registro& resultado) const {
    int posicion = id % capacidad;

    for (int i = 0; i < capacidad; i++) {
        if (casillas[posicion].estado==VACIO) {
            return false;
        }
        if (casillas[posicion].estado==OCUPADO &&
            casillas[posicion].dato.id==id) {
            resultado=casillas[posicion].dato;
            return true;
            }

        posicion = (posicion + 1) % capacidad;
    }
        return false;
}

//ELIMINAR
bool TablaHash::eliminar(int id) {
    int posicion = id % capacidad;

    for (int i=0; i < capacidad; i++) {
        if (casillas[posicion].estado==VACIO) {
            return false;
        }

            if (casillas[posicion].estado==OCUPADO &&
                casillas[posicion].dato.id==id) {
                casillas[posicion].estado=ELIMINADO; //cambia su estado de ocupado a eliminado
                contador--; //cuando se elimina una casilla hay un registro menos
                eliminadas++; //se le suma una casilla eliminada
                return true;
                }

            posicion = (posicion + 1) % capacidad;
        }
    return false;
    }

//ACTUALIZAR
bool TablaHash::actualizar(int id, int nuevoValor) {
    int posicion = id % capacidad;
    for (int i=0; i < capacidad; i++) {
        if (casillas[posicion].estado==VACIO) {//comprobar si la casilla esta vacia
            return false;
        }
        if (casillas[posicion].estado==OCUPADO &&
            casillas[posicion].dato.id==id) { //comprobar si se encontro el id
            casillas[posicion].dato.valor=nuevoValor; //actualizar el valor
            return true; //se encontro el registro y se logro modificar
        }
            posicion = (posicion + 1) % capacidad; //avanzar cuando hay una colision
            }
    return false;
    }



//rehash
void TablaHash::rehash() {
    int capacidadAnterior=capacidad; //guarda capacidad anterior
    Casilla* casillasAnteriores=casillas; //guarda los arreglos anteriores
    int nuevaCapacidad=siguientePrimo(capacidad*2); //calcula la nueva capacidad al doble y ajustandola a un numero primo
    casillas = new Casilla[nuevaCapacidad]; //reserva memoria para las casillas nuevas
    capacidad=nuevaCapacidad; //actualiza capacidad


    for (int i=0; i<capacidad; i++) { //recorre las nuevas casillas y las marca como vacias
        casillas[i].estado = VACIO;}
    contador=0; //reiniciar contador a 0
    eliminadas=0;
    for (int i=0; i<capacidadAnterior; i++ ) {
        if (casillasAnteriores[i].estado==OCUPADO) { //solo se copian los registros de las casillas ocupadas
            insertar(casillasAnteriores[i].dato);//tomar registro de la casilla anterior e insertarlo en la tabla nueva
        }
    }
        delete[] casillasAnteriores; //liberar el arreglo anterior
    }


    bool TablaHash::esPrimo(int numero) {
        if (numero <= 1) return false;
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;

    }

int TablaHash::siguientePrimo(int numero) {
    if (numero <= 2) return 2;
    int candidato=numero;
    while (!esPrimo(candidato)) {
        candidato ++;
    }
    return candidato;
}

void TablaHash::verificarCarga() {
    double factorCarga=(double)contador/capacidad; //calcular el factor de carga con decimales
    if (factorCarga>=0.7) { //comprobar si es mayor o igual a 0.7
        rehash(); //llamar a rehash cuando se alcanza el limite de 70% de la capacidad
    }
}

//verificar: cuenta los registros y comprueba que se pueden encontrar
bool TablaHash::verificarTablahash() {
    int ocupadas=0; //contar casillas ocupadas
    for (int i=0; i < capacidad; i++) {
        if (casillas[i].estado==OCUPADO) { //ver si la casilla esta ocupada
            ocupadas++; //cada que se encuentra una casilla ocupada, el contador aumenta 1
            Registro encontrado; //variable para guardar el registro ocupado que se encuentre
            if (!buscar (casillas[i].dato.id, encontrado)) { //si se encuentra el registro que deberia de estar guardado en la casilla..
                return false; //si un registro no puede localizarse
            }
        }
    }
    if (ocupadas!=contador) {
        return false; //devuelve false si ocupadas y el contador no coincide
    }
    return true; //devuelve true si si coinciden
}
























