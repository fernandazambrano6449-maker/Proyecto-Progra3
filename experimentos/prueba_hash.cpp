//
// Created by ferna on 10/18/2026.
//
#include <iostream>
#include "TablaHash.h"
#include <cstring>
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
}