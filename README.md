# C++ Learning Path

Ejercicios de programación en C++ que hice en la universidad. Cada archivo es un programa independiente que resuelve un problema puntual.

## Tecnologías

- C++ (estándar C++11/17)
- Compilador g++ (MinGW)
- API educativa proporcionada por la materia (librería con funciones para strings, archivos, colecciones y fechas)

## Lo que practiqué

- Algoritmos: factorial, números primos, suma y simplificación de fracciones
- Estructuras de datos: tipos enteros (int, short), strings
- Conceptos: funciones con paso por valor y por referencia, recursividad, structs, validación de entrada
- Control de flujo: if/else, while, operador ternario
- Archivos de texto y entrada/salida por consola

## Estructura del proyecto

```
├── lib/                        Librería educativa (la uso pero no es mía)
│   ├── funciones/              Funciones de strings, archivos, tokens, arrays, listas, fechas
│   └── tads/                   Estructuras genéricas: Coll, Array, List, Map, Queue, Stack
├── src/
│   ├── algorithms/             Ejercicios de algoritmos
│   │   ├── factorial.cpp               Cálculo de factorial con valor ingresado por el usuario
│   │   ├── factorial_hardcoded.cpp     Factorial con valor fijo (n=5)
│   │   ├── numeros_primos.cpp          Detección de números primos con recursividad
│   │   ├── simplificar_fraccion.cpp    Simplificar fracciones usando el algoritmo de Euclides
│   │   └── suma_fracciones.cpp         Sumar dos fracciones
│   ├── data-structures/        Ejercicios de tipos de datos
│   │   ├── tipos_int.cpp               Muestra cómo funciona el tipo int
│   │   ├── tipos_short.cpp             Muestra cómo funciona el tipo short
│   │   └── tipos_string.cpp            Muestra cómo funciona el tipo string
│   └── mini-projects/          Programas completos
│       ├── anio_bisiesto.cpp           Valida si un año es bisiesto usando struct Fecha
│       ├── calcular_promedio.cpp       Calcula suma y promedio con funciones y referencias
│       ├── conteo_valores.cpp          Cuenta valores según rangos numéricos
│       ├── dias_del_mes.cpp            Muestra los días de un mes considerando año bisiesto
│       ├── ejercicio4.cpp              Ejercicio de contador con while
│       └── plantilla.cpp               Plantilla básica para empezar un programa
├── principal.hpp               Header que incluye toda la librería
└── .gitignore
```

## Cómo compilar y ejecutar

Los archivos en `src/` son independientes. Se compilan y ejecutan así:

```bash
g++ src/algorithms/factorial.cpp -o factorial
./factorial
```

Si algún programa necesita la librería:

```bash
g++ src/algorithms/numeros_primos.cpp -I. -o numeros_primos
./numeros_primos
```

## Aclaración

La carpeta `lib/` contiene una API educativa que nos dieron en la facultad. No es código mío. Los programas en `src/` sí los hice yo como parte de las prácticas de la materia.
