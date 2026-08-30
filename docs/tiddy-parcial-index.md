# Índice de ejercicios formato parcial — caypaf3 (tiddlyhost)

Fuente: https://caypaf3.tiddlyhost.com/ (37 tiddlers → 28 ejercicios reales).
Enunciados persistidos en `src/problemas-parcial/tiddy/enunciados/` (NN_nombre.md).

> **Regla**: este índice es un MAPA, no un apéndice. No duplica teoría. Todo concepto se
> referencia desde `docs/AGENTS.md` (API, reglas, patrones) y `docs/CONTEXT_MAP.md` (mapa general).

## Cómo leer los archivos

| Aspecto | Dónde |
|---|---|
| API completa (strings, tokens, Coll, files) | `docs/AGENTS.md` §API |
| Reglas del curso (no APT, 1 pasada, no STL) | `docs/AGENTS.md` §Reglas |
| Patrones (corte, apareo, descubrimiento, indexar) | `docs/AGENTS.md` §Patrones |
| Guía file I/O | `docs/file-io-guia.md` |
| Cómo compilar | `docs/AGENTS.md` §Cómo compilar |

## Convención de datos

- **Los archivos `.dat` los genera la IA** (este asistente), NO el usuario. El usuario solo
  resuelve el programa. Al trabajar un ejercicio hay que crear primero sus `.dat` coherentes
  con el enunciado (mismo struct, cantidades acotadas) en la carpeta del ejercicio.
- CWD de ejecución = carpeta del ejercicio (fopen relativo al exe).

## Leyenda de niveles

- `básico` (8): 1 archivo consulta en memoria + acumuladores. Es el objetivo del viernes.
- `intermedio` (7): suman ordenar Coll / apareo / actualizar .dat.
- `avanzado` (10): suman indexación, top-N, estructuras anidadas.
- `sueltos` (3): práctica de strings sobre PALABRAS.dat, NO formato parcial.

## Taxonomía (28 ejercicios)

| # | Ejercicio | Nivel | Técnicas clave | Puntos | Solución |
|---|---|---|---|---|---|
| 01 | Aseguradora de riesgos del trabajo | básico | subir_consulta, wrap_struct, corte | 2 | — |
| 02 | Asistencia mecánica | avanzado | subir_consulta, descubrimiento, wrap | 2 | — |
| 03 | Buques y containers | intermedio | subir_consulta, ordenar, **apareo** | 2 | ✅ en tiddler | ❌ **FUERA** (apareo) |
| 04 | Canal de televisión | avanzado | subir_consulta, wrap, corte | 2 | — |
| 05 | Compañía de aviación | básico | subir_consulta, wrap, descubrimiento | 3 | ✅ en tiddler |
| 06 | Constelaciones | avanzado | sin archivos (consola) | 2 | — |
| 07 | Corrección de exámenes | intermedio | subir_consulta, corte, wrap | 2 | — |
| 08 | Emisión de tickets | básico | subir_consulta, descubrimiento, **top-10** | 2 | — |
| 09 | Empresa de gas | intermedio | **indexación, búsqueda binaria, actualizar .dat** | 4 | — | ❌ **FUERA** (indexación) |
| 10 | Empresa piramidal | intermedio | subir_consulta, descubrimiento, **actualizar .dat** | 2 | — |
| 11 | Gastos por consorcio | intermedio | subir_consulta, wrap, corte, ordenar | 2 | — |
| 12 | Hospedaje en casas de familia | intermedio | subir_consulta, wrap, ordenar | 1 | — |
| 13 | Imputación horas/proyecto | intermedio | subir_consulta, descubrimiento, ordenar | 1 | — |
| 14 | Infracciones de tránsito | básico | subir_consulta, wrap, descubrimiento | 2 | — |
| 15 | Inscripción en la facultad | avanzado | subir_consulta, descubrimiento, ordenar | 4 | — |
| 16 | Letras | suelto | string_manip, descubrimiento | 1 | — |
| 17 | Línea de cajas | avanzado | wrap, acumulador | 3 | — |
| 18 | Medición de audiencia | avanzado | subir_consulta, wrap, ordenar | 1 | — |
| 19 | Obras de teatro | avanzado | subir_consulta, wrap | 1 | — |
| 20 | Optimización de colas | avanzado | wrap, acumulador | 1 | — |
| 21 | Palabras con números | suelto | string_manip, descubrimiento, ordenar | 1 | — |
| 22 | Predios de fútbol | avanzado | subir_consulta, descubrimiento, wrap | 3 | — |
| 23 | Prestadores médicos | básico | **apareo (PRESTA19 vs PRESTA20)** | 3 | — | ❌ **FUERA** (apareo) |
| 24 | Reserva de turnos | avanzado | subir_consulta, descubrimiento, wrap | 2 | ✅ en tiddler |
| 25 | Sílabas | suelto | string_manip, descubrimiento | 1 | — |
| 26 | Streaming de audiocuentos | básico | subir_consulta, wrap, **top-10** | 2 | — |
| 27 | Streaming de audiolibros | básico | subir_consulta, wrap, **top-10** | 2 | — |
| 28 | Torneo de fútbol | básico | subir_consulta, descubrimiento, **actualizar .dat** | 3 | — |

## Scaffold de práctica (cómo está cada `principal.cpp`)

Los **includes van siempre puestos y correctos** en TODOS los cpp (el prof no hace escribirlos).
El bloque estándar (idéntico en los 18 ejercicios):

```cpp
#include <iostream>
#include "../../../../lib/funciones/files.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"
#include "../../../../lib/funciones/Coll.hpp"
#include "principal.hpp"
```

| Nivel | Ejercicios | El cpp trae hecho | Lo resuelve el estudiante |
|---|---|---|---|
| 🟢 **N1** | 05_aviacion | includes + wrap structs + firmas + `subir` resuelto + `main()` con loop | inicializar wraps, búsquedas, procesar, mostrar |
| 🟡 **N2** | 26_audiocuentos | includes + wrap structs + firmas | TODO el flujo (subir, loop, procesar, mostrar) |
| 🔴 **N3** | los otros 16 | includes + `main()` vacío | TODO: wraps, subir, procesar, mostrar |

Los `principal.hpp` son **jar-only** (solo structs base + serialización). Los wrap structs
(`R*`) los define el cpp, como en el parcial.

## Orden de práctica (miércoles → viernes)

1. **Miércoles**: 05 (N1), 26 (N2), 14 (N3) → aprender el patrón completo, luego soltarlo.
2. **Jueves mañana**: 28 (actualizar .dat), 27 (corte + top-10).
3. **Jueves tarde**: 13 (corte anidado), 08 (ticket + top-N).
4. **Jueves noche**: simulacro cronometrado (1 básico + 1 intermedio).
5. **Extra (a pelo, listos)**: 11 (corte + ordenar), 15 (generar archivo), 07 (corte), 22 (wrap pesado), 01, 02, 17, 18, 19, 20, 29.

> **Alcance del parcial (confirmado por el prof):** Sí = procesamiento directo, subir consultas a Coll,
> corte de control, descubrimiento, ordenar Coll, top-N, actualizar .dat. **NO** = apareo (03, 23) e
> indexación/búsqueda binaria sobre archivo (09). La búsqueda binaria sobre Coll en memoria SÍ va.
> Contrato: dan enunciado + `principal.hpp` del jar; el `principal.cpp` completo va a pelo.

## Enunciados con solución oficial incluida

- `03 Buques y containers`, `05 Compañía de aviación`, `24 Reserva de turnos`.
  El bloque "Ver solución" está en el tiddler; usarlos como referencia de comparación
  (faded examples), NO como primer contacto.

## Notas clave por ejercicio (trampas)

- **09**: ❌ FUERA (indexación/búsqueda binaria sobre archivo grande).
- **10 / 28**: reescriben el .dat (acceso directo con seek).
- **08 / 26 / 27**: top-10 = ordenar Coll desc + cortar en 10.
- **23**: ❌ FUERA (apareo).
- **24**: agenda anidada `Map<int,Map<int,Map<int,Array<bool>>>>` — solo conceptual, requiere parte2.
