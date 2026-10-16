# Bitácora — <matrícula>

<!-- Una entrada por sesión de trabajo. -->
## 2026-10-15, 17:00–23:00
Qué hice:
- Definí los estados de las casillas (VACIO,OCUPADO y ELIMINADO) mediante enum
- Creé la estructura Casilla en TablaHash.h
- Definí la clase TablaHash con un puntero para almacenar casilla y una variables para su capacidad
- Puse el constructor para reservar memoria dinámica para 10 casillas e inicializarlas con VACIO
- Puse también el destructor para liberar la memoria utilizando delete[].


Qué falló o me confundió:

Al principio me costó entender como organizar la clase TablaHas y la estructura casilla. También tuve dudas sobre los punteros y cómo reservar memoria y como liberarla

Qué consulté (URL exacta, libro y página, o nombre del profesor): 
- https://benhoyt.com/writings/hash-table-in-c/
- https://www.udemy.com/course/programacion-en-c-plus-plus-con-estructuras-de-datos/learn/lecture/48472249#overview

Commit(s):
- Configuración inicial del proyecto
- Definición de estados y estructura de casilla

## 2026-10-16, HH:MM–HH:MM

