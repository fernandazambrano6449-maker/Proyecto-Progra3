//
// Created by ferna on 10/18/2026.
//
#include <iostream>
#include "TablaHash.h"
#include <cstring>
#include"Motor.h"

int main() {
    TablaHash tabla;
    Registro r;
    r.id=12;
    r.categoria=2;
    r.valor=500;
    std::strcpy(r.etiqueta, "Prueba");

    bool resultado = tabla.insertar(r);

    std::cout << "Resultado de insertar: " << resultado << '\n';
    bool duplicado = tabla.insertar(r);
    std::cout << "Resultado de duplicado: " << duplicado << '\n';

    Registro r2 = r;
    r2.id = 22;

    bool colision = tabla.insertar(r2);
    std::cout << "Resultado de colision: " << colision << '\n';

    //encontrar id
    Registro encontrado;
    bool existe=tabla.buscar(r.id,encontrado);
    std::cout<<"resultado de buscar:"<<existe<<'\n';

    //buscar id inexistente
    bool noExiste=tabla.buscar(99,encontrado);
    std::cout << "ID inexistente: "<< noExiste << '\n';

    //buscar id con colision
    bool idColision=tabla.buscar(22, encontrado);
    std::cout << "Buscar ID con colision: "<< idColision << '\n';

    //ELIMINAR
    bool eliminar=tabla.eliminar(12);
    std::cout << "ID eliminado: "<<eliminar<< '\n';


    //ver si se elimino correctamente el id 12
    bool siElimino=tabla.buscar(12, encontrado);
    std::cout<<"Se elimino correctamente: "<<siElimino<<'\n';

    bool inexistente=tabla.eliminar(52);
    std::cout<< "Eliminar ID inexistente: "<<inexistente<<'\n';

    //reutilizar casilla
    Registro r3=r;
    r3.id=32;
    bool reutilizar=tabla.insertar(r3);
    std::cout<<"reutilizar casilla: "<<reutilizar<<'\n';

    bool buscarID=tabla.buscar(32,encontrado);
    std::cout << "ID encontrado "<< buscarID<< '\n';

    //prueba rehash
    TablaHash tablaRehash; //se crea el objeto tablaRehash
    for (int i=0;i<7;i++) {
        Registro nuevo; //se crea un registro nuevo en cada repeticion del ciclo
        nuevo.id=(i+1)*10; //se le asigna un id diferente a cada registro
        nuevo.categoria=30;
        nuevo.valor=64;
        std::strcpy(nuevo.etiqueta, "Prueba");
        tablaRehash.insertar(nuevo); //se le pide a tabla rehash que inserte el registro nuevo
    }
    for (int i=0;i<7;i++) {
        int idBuscar=(i+1)*10;
        Registro encontradoRehash;
        tablaRehash.buscar(idBuscar, encontradoRehash);

        bool existe =tablaRehash.buscar(idBuscar,encontradoRehash);
        std::cout << "Existe el id? "<< existe<< '\n';
    }

}















