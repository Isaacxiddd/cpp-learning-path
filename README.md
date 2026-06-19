# C++ Learning Path

Ejercicios de programación en C++ del curso **Algoritmos y Programación A Fondo** (Pablo A. Sznajdleder).

Cada archivo en `src/` es un programa independiente que resuelve un problema puntual.

---

## Tecnologías

- C++ (estándar C++11/17)
- Compilador g++ (MinGW)
- API educativa de la materia (`lib/`): strings, tokens, archivos, colecciones, fechas

---

## Estructura del proyecto

```
├── lib/                            Biblioteca educativa del curso
│   ├── funciones/                  Funciones utilitarias
│   │   ├── strings.hpp             API de cadenas de caracteres
│   │   ├── tokens.hpp              API de tokens
│   │   ├── files.hpp               API de archivos
│   │   ├── arrays.hpp              API de arreglos
│   │   ├── lists.hpp               API de listas
│   │   ├── millis.hpp              API de instantes en milisegundos
│   │   └── Coll.hpp                TAD Coll (template)
│   └── tads/
│       ├── intro/
│       │   └── Fraccion.hpp        TAD Fracción (completo - referencia)
│       ├── parte1/
│       │   ├── Coll.hpp            TAD Coll
│       │   ├── Fecha.hpp           TAD Fecha (pendiente implementar)
│       │   ├── Timer.hpp           TAD Timer (pendiente implementar)
│       │   └── MultidimColl.hpp    TAD Coll multidimensional
│       └── parte2/
│           ├── Array.hpp           TAD Array
│           ├── List.hpp            TAD List
│           ├── Map.hpp             TAD Map
│           ├── Queue.hpp           TAD Queue
│           └── Stack.hpp           TAD Stack
├── src/
│   ├── leccion-01-basicos/         Lección 1: Operaciones, condicionales, loops
│   ├── leccion-02-funciones/       Lección 2: Funciones (factorial, primo, etc.)
│   ├── leccion-03-tads/            Lección 3: implementar Fecha.hpp y Timer.hpp
│   └── capitulo-04-problemas/      Capítulo 4: Corte de control, apareo, etc.
├── docs/                           Apéndices del libro (solo lectura)
├── AlgoritmosAFondo_EMPTY_v2.7.29/ Proyecto vacío original del curso (referencia)
├── principal.hpp                   Header que incluye toda la biblioteca
└── README.md
```

> **Lecciones 4, 5 y 6/7 no tienen carpeta en `src/`** porque su entregable es la biblioteca misma:
> - Lección 4 → `lib/funciones/strings.hpp` ✅
> - Lección 5 → `lib/funciones/tokens.hpp` ✅
> - Lección 6/7 → `lib/funciones/Coll.hpp` ✅

---

## Roadmap de ejercicios

### Lección 1 — Operaciones aritméticas, condicionales y loops

| # | Ejercicio | Dificultad | Requerido | Estado |
|---|---|---|---|---|
| 1.2.1 | Operaciones aritméticas (suma, resta, producto, cociente) | Básica | Indispensable | |
| 1.2.2 | Cociente entre dos números (validando b≠0) | Básica | Indispensable | |
| 1.2.3 | División entera y módulo | Básica | Indispensable | |
| 1.2.4 | Mayor valor entre dos números | Básica | Indispensable | |
| 1.2.5 | Mayor y menor valor entre dos números | Básica | Indispensable | |
| 1.2.6 | Mayor, medio y menor entre tres números | Básica | Indispensable | |
| 1.2.7 | Tipo de triángulo según sus lados | Básica | Indispensable | |
| 1.2.8 | Separar atributos de una fecha (aaaammdd) | Básica | Indispensable | |
| 1.2.9 | Unificar atributos de una fecha | Básica | Indispensable | |
| 1.2.10 | Fecha más próxima | Moderada | Indispensable | |
| 1.2.11 | Cuántos días tiene un mes | Básica | Indispensable | ✅ `dias_del_mes.cpp` |
| 1.2.12 | Producto mediante sumas sucesivas | Básica | Indispensable | |
| 1.2.13 | Factorial de un número | Básica | Indispensable | ✅ `factorial.cpp` |
| 1.2.14 | Números primos | Básica | Indispensable | ✅ `numeros_primos.cpp` |
| 1.2.15 | Primeros n números primos | Básica | Indispensable | |
| 1.2.16 | Número de Fibonacci | Básica | Indispensable | |
| 1.2.17 | Múltiplos (a, b, n) | Básica | Indispensable | |
| 1.2.18 | Factorial de los primeros n naturales | Básica | Indispensable | |
| 1.2.19 | Suma de fracciones | Básica | Indispensable | ✅ `suma_fracciones.cpp` |
| 1.2.20 | Simplificar una fracción | Básica | Indispensable | ✅ `simplificar_fraccion.cpp` |
| 1.2.21 | Docenas (conteo por rangos) | Básica | Indispensable | 🚧 `conteo_valores.cpp` |
| 1.2.22 | Cantidades, promedios y porcentajes | Básica | Indispensable | |
| 1.2.23 | Mayores y menores que | Básica | Indispensable | |
| 1.2.24 | Máximos | Básica | Indispensable | |
| 1.2.25 | Mínimos | Básica | Indispensable | |
| 1.2.26 | Mayor de los negativos, menor de los positivos | Moderada | Indispensable | |
| 1.2.27 | Mínimo valor dentro de un intervalo | Moderada | Indispensable | |
| 1.2.28 | Persona más joven, persona más vieja | Moderada | Indispensable | |
| 1.2.29 | Conjuntos y subconjuntos | Moderada | Indispensable | |
| 1.2.30 | Conjunto dividido por valores 0 | Moderada | Indispensable | |
| 1.2.31 | Seguidilla | Moderada | Indispensable | |
| 1.2.32 | Palabras dentro de una oración | Moderada | Indispensable | |

### Lección 2 — Funciones

| # | Ejercicio | Dificultad | Requerido | Estado |
|---|---|---|---|---|
| 1.3.1 | Función factorial | Básica | Indispensable | ✅ `factorial.cpp` |
| 1.3.2 | Factorial de los primeros n números (usando función) | Básica | Indispensable | |
| 1.3.3 | Función esPrimo | Básica | Indispensable | ✅ `numeros_primos.cpp` |
| 1.3.4 | Primeros n números primos (usando esPrimo) | Moderada | Indispensable | |
| 1.3.5 | Función Fibonacci | Moderada | Indispensable | |
| 1.3.6 | Primeros términos de Fibonacci | Moderada | Indispensable | |

### Lección 3 — TADs (Fracción, Fecha, Timer)

| # | Ejercicio | Dificultad | Requerido | Estado |
|---|---|---|---|---|
| 1.4.1 | TAD Fracción | Moderada | Indispensable | ✅ `lib/tads/intro/Fraccion.hpp` |
| 1.4.2 | Fechas, horas y milisegundos | Moderada | Indispensable | 🚧 `lib/tads/parte1/Fecha.hpp` |
| 1.4.3 | TAD Timer | Moderada | Indispensable | 🚧 `lib/tads/parte1/Timer.hpp` |
| 1.4.4 | Medición de tiempos | Moderada | Indispensable | |

### Lección 4 — API de Strings → `lib/funciones/strings.hpp` ✅

> El entregable de esta lección es la implementación de `strings.hpp`, no ejercicios separados.  
> Ejercicios de aplicación que usan strings van en `leccion-01-basicos/` y `leccion-02-funciones/`.

| # | Función a implementar | Estado |
|---|---|---|
| — | `strings.hpp` completo | ✅ `lib/funciones/strings.hpp` |

### Lección 5 — API de Tokens → `lib/funciones/tokens.hpp` ✅

> El entregable de esta lección es la implementación de `tokens.hpp`.

| # | Función a implementar | Estado |
|---|---|---|
| — | `tokens.hpp` completo | ✅ `lib/funciones/tokens.hpp` |

### Lección 6/7 — TAD Coll → `lib/funciones/Coll.hpp` ✅

> El entregable de esta lección es la implementación de `Coll.hpp`.

| # | Función a implementar | Estado |
|---|---|---|
| — | `Coll.hpp` completo | ✅ `lib/funciones/Coll.hpp` |

### Capítulo 4 — Resolución de problemas

| # | Versión | Técnica | Estado |
|---|---|---|---|
| 4.5.1 | Corte de control | Corte de control simple | |
| 4.5.2 | Corte de control con salida bufferizada | Corte de control + buffer | |
| 4.5.3 | Descubrimiento | Colecciones + descubrimiento | |
| 4.5.4 | Archivo de consulta en memoria | Subir archivo a colección | |
| ... | (versiones 5 a 15) | Apareo, indexación, etc. | |

---

## Referencias

- `docs/apendice-01-ejercicios.md` — Enunciados detallados de todos los ejercicios
- `docs/apendice-02-api.md` — Especificaciones y API de cada TAD y biblioteca
- `docs/capitulo-04-resolucion.md` — Técnicas de resolución de problemas

---

## Cómo compilar y ejecutar

Los archivos en `src/` son independientes. Sin biblioteca:

```bash
g++ src/leccion-01-basicos/dias_del_mes.cpp -o dias_del_mes
./dias_del_mes
```

Con biblioteca (usando `principal.hpp`):

```bash
g++ src/leccion-02-funciones/numeros_primos.cpp -I. -o numeros_primos
./numeros_primos
```

---

## Leyenda

| Símbolo | Significado |
|---|---|
| ✅ | Implementado |
| 🚧 | En progreso (esqueleto vacío) |
| (vacío) | Pendiente |
