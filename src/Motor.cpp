// =============================================================================
//  Motor.cpp — ESTE ES TU PROYECTO. Todo lo de aquí es un esqueleto.
// =============================================================================
#include "Motor.h"

#include <cstring>
#include <cstdio>
Motor::Motor() {}
Motor::~Motor() {}

bool Motor::insertar(const Registro& r) {return tabla.insertar(r);}

bool Motor::eliminar(int id) { return tabla.eliminar(id);}

bool Motor::actualizar(int id, int nuevoValor) { return tabla.actualizar(id, nuevoValor); }

bool Motor::obtener(int id, Registro& salida) {return tabla.buscar(id, salida);}

void Motor::rango(int a, int b, int limite, ResultadoRango& salida) {
    (void)a; (void)b; (void)limite;
    salida.n = 0;
    salida.firma = 0;
    salida.nFilas = 0;
}

int  Motor::contar(int a, int b) { (void)a; (void)b; return 0; }
bool Motor::kesimo(int k, Registro& salida) { (void)k; (void)salida; return false; }
int  Motor::top(int k, int categoria, Registro* salida) { (void)k; (void)categoria; (void)salida; return 0; }

void Motor::iniciarTransaccion() {}
bool Motor::confirmar() { return false; }
bool Motor::revertir() { return false; }

int  Motor::altura() const { return -1; }
void Motor::configurarCache(int capacidad) { (void)capacidad; }

EstadisticasCache Motor::estadisticasCache() const {
    EstadisticasCache e;
    std::memset(&e, 0, sizeof(e));
    return e;
}

bool Motor::verificar(char* mensaje, int capacidad) {
    if (capacidad > 0) mensaje[0] = '\0';
    if (!tabla.verificarTablahash()) {
        if (capacidad > 0) {
            std::snprintf(mensaje, capacidad, "Error en tabla hash");
        }
        return false;
    }
    return true;
}

void Motor::imprimirStats(std::ostream& os) { os << "(sin estadisticas)\n"; }
