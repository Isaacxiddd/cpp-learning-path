# Mapa de contexto para la IA

## Proyecto: Algoritmos y Programación A FONDO (Sznajdleder)
## Raíz: `C:\vscode\Workspace\Proyecto_01\cpp-learning-path\`

---

## Para entender qué sabe el alumno

| Tema | Leer esto primero |
|------|-------------------|
| **Proyecto completo (estructura, reglas, APIs)** | `docs/AGENTS.md` (~500 líneas) — contiene TODO: estructura, API completa, reglas, patrones |
| **Roadmap + qué está implementado** | `README.md` — tabla de ejercicios con estados |
| **Plan del Capítulo 4** | `docs/capitulo-4-plan.md` — corte de control, apareo, las 15 versiones |
| **Apéndice 1 (ejercicios)** | `docs/apendice 1 de ejercicios basicos string,tad,ordenamiento.md` — enunciados L1 a L7 |
| **Apéndice 2 (especificaciones API)** | `docs/apendice 2 string ,tokens ,ejercicios tad ,tadcoll.md` — specs de strings, tokens, Coll, Fecha, Timer |
| **Reglas Cap4** | `docs/reglas para resolver problemas y ejercicios ya en ultimo piso.md` — texto del libro cap4 |
| **Guía FILE I/O** | `docs/file-io-guia.md` — read/write/seek/fileSize |
| **Roadmap promoción** | `docs/roadmap-promocion.md` |
| **Plan promoción** | `docs/PLAN_PROMOCION.md` |
| **Parcial — índice de ejercicios (caypaf3)** | `docs/tiddy-parcial-index.md` — taxonomía de los 28 ejercicios formato parcial, orden de práctica, trampas |
| **Parcial — enunciados completos** | `src/problemas-parcial/tiddy/enunciados/NN_nombre.md` — los 28 enunciados persistidos (los `.dat` los genera la IA) |

## Para leer el código fuente

| Archivo | Contenido | Estado |
|---------|-----------|--------|
| `lib/funciones/strings.hpp` | Implementación de strings | ✅ Completa |
| `lib/funciones/tokens.hpp` | Implementación de tokens | ✅ Completa |
| `lib/funciones/Coll.hpp` | TAD Coll (genérico, basado en tokens) | ✅ Completa |
| `lib/funciones/files.hpp` | API archivos (read/write/seek) | ✅ Completa |
| `lib/tads/parte1/Coll.hpp` | TAD Coll (parte1, esqueleto vacío) | 🚧 Esqueleto |
| `lib/tads/parte1/Fecha.hpp` | TAD Fecha | 🚧 Esqueleto |
| `lib/tads/parte1/Timer.hpp` | TAD Timer | 🚧 Esqueleto |
| `principal.hpp` | Include que junta toda la biblioteca | — |
| `principal.cpp` | Scratch para pruebas rápidas | — |

## Capas de abstracción (orden estricto)

```
Parte2 (Array, List, Map, Queue, Stack)  ← depende de arrays, lists
    ↑
Parte1 (Coll, Fecha, Timer, MultidimColl) ← depende de tokens, strings, millis
    ↑
Tokens + Files  ← tokens depende de strings
    ↑
Strings + Millis + Arrays + Lists  ← no dependen de nada (solo std)
```

## Reglas clave del curso

1. **No APT**: no validar errores de usuario (salvo que el enunciado lo pida)
2. **No recorrer archivo más de una vez**: subir a Coll o indexar
3. **Prohibido STL**: nada de vector, map, sort, etc. Solo `Coll<T>` y la API del curso
4. **Archivo novedades** = se procesa (1 pasada). **Archivo consulta** = se sube a memoria o se indexa

## Patrones clave

| Patrón | Cuándo | Estructura |
|--------|--------|------------|
| Corte de control | Archivo ordenado por clave, hay que agrupar | `while(archivo) { init; while(mismoGrupo) { procesar; } resultados; }` |
| Corte + buffer | Ídem pero hay que ordenar/filtrar antes de mostrar | Igual + guardar en Coll, ordenar, mostrar |
| Descubrimiento | Archivo NO ordenado, hay que procesar por grupos | `collFind` + `collAdd` si no existe |
| Apareo | 2+ archivos ordenados por misma clave | Comparar claves, avanzar el menor |
| Subir archivo a memoria | Archivo chico de consulta | Crear Coll, leer, `collAdd` por cada registro |
| Indexar | Archivo grande no ordenado por clave de búsqueda | Crear índice `{clave, pos}`, ordenar índice |

## Cómo compilar

```bash
# Sin biblioteca
g++ src/leccion-01-basicos/ejercicio.cpp -o ejercicio.exe

# Con biblioteca
g++ src/capitulo-04-problemas/ejercicio.cpp -I. -o ejercicio.exe
# (fopen busca desde donde se ejecuta el .exe)
```

## Convención de archivos .dat

- Los `.dat` se ponen en la raíz del proyecto y se ejecuta desde ahí
- O se ponen en la carpeta del ejercicio y se ejecuta desde ahí
