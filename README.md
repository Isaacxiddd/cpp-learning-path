# C++ Fundamentals

University programming exercises covering algorithms, data structures, and problem-solving in C++.

## Technologies

- **Language:** C++ (C++11/17)
- **Compiler:** g++ / MinGW
- **IDE:** Visual Studio Code
- **Library:** Custom educational C++ API (provided by the course) for strings, collections, file I/O, date/time handling

## Concepts Practiced

| Category | Topics |
|---|---|
| **Algorithms** | Factorial (iterative), prime numbers (recursive), fraction arithmetic, GCD/Euclidean algorithm, fraction simplification |
| **Data Structures** | Primitive types (`int`, `short`, `string`), memory representation |
| **Functions** | Pass by value, pass by reference, return values, recursion |
| **Control Flow** | Conditional branching (`if/else`), loops (`while`), input validation |
| **Structs** | Custom data types, date structures, leap year logic |
| **I/O** | Console input/output, formatted output |

## Repository Structure

```
├── lib/                        Educational C++ API (course-provided)
│   ├── funciones/              String, file, token, list, array, timestamp utilities
│   └── tads/                   Generic data structures: Coll, Array, List, Map, Queue, Stack
├── src/
│   ├── algorithms/             Algorithm implementations
│   │   ├── factorial.cpp          Factorial calculation (user input)
│   │   ├── factorial_hardcoded.cpp Factorial (hardcoded value)
│   │   ├── numeros_primos.cpp     Prime number detection (recursive)
│   │   ├── simplificar_fraccion.cpp Fraction simplification (Euclidean GCD)
│   │   └── suma_fracciones.cpp    Addition of two fractions
│   ├── data-structures/        Data type exploration
│   │   ├── tipos_int.cpp          Integer type demonstration
│   │   ├── tipos_short.cpp        Short type demonstration
│   │   └── tipos_string.cpp       String type demonstration
│   └── mini-projects/          Complete mini programs
│       ├── anio_bisiesto.cpp      Struct-based leap year validator
│       ├── calcular_promedio.cpp  Statistics function with references
│       ├── conteo_valores.cpp     Range-based value counting
│       ├── dias_del_mes.cpp       Days-in-month calculator (leap year aware)
│       ├── ejercicio4.cpp         Loop/counter exercise
│       └── plantilla.cpp          Basic program template
├── principal.hpp               Convenience header (includes all library modules)
└── .gitignore
```

## How to Compile & Run

Each `.cpp` file in `src/` is self-contained. Compile and run individually:

```bash
# Using g++
g++ src/algorithms/factorial.cpp -o factorial
./factorial

# Using g++ with the library (if needed)
g++ src/algorithms/numeros_primos.cpp -I. -o numeros_primos
./numeros_primos
```

Or compile all at once:

```bash
g++ src/algorithms/factorial.cpp src/algorithms/factorial_hardcoded.cpp -o factorial
./factorial
```

> Note: Files in `src/` do not depend on `lib/`. The library headers are only required when building programs that use the educational API (e.g., programs that include `principal.hpp`).

## About

This repository contains exercises completed as part of a university C++ course. The educational library (`lib/`) was provided by the course and is included for reference — it is not my own work. All programs in `src/` were written by me.

Feel free to explore, clone, or use as reference for learning C++ fundamentals.
