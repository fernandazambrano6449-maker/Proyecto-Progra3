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
    int capacidad; //cuantas casillaas tiene la tabla 
    int contador; //saber cuantos registros estan guardados en la tabla
    int eliminadas; //variable para contar cuantas casillas estan marcadas como eliminadas
    void rehash();
    bool esPrimo(int); //comprobar si un numero es primo
    int siguientePrimo(int); //encontrar una capacidad adecuada 
    void verificarCarga(); //revisa si se alcanzo el limite y si hay que llamara rehash


public: //funciones que se pueden usar desde fuera
TablaHash();~TablaHash();
    bool insertar(const Registro& r); //recibe un registro llamado r
    bool buscar(int id, Registro& resultado) const; //recibe el id que se busca y guarda el registro encontrado en resultado 
    bool eliminar(int id);
    bool actualizar(int id, int nuevoValor);
    bool verificarTablahash();
};


#endif //MINIDB_TABLAHASH_H
