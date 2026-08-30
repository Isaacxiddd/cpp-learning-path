# PLAN PARCIAL — corte de control + procesamiento directo

> El profe da el hpp **ya resuelto**. Vos solo escribís el `principal.cpp`.
> Alcance memorizado (5/8/26): SOLO **corte de control** y **procesamiento directo**. El resto NO existe.

## Cómo estudiar (retrieval practice — escribir de memoria, NO releer)

1. Repasá la plantilla **una** vez (TEORIA_PARCIAL.pdf).
2. Cerrá todo. Escribila de memoria en un papel.
3. Compará contra la plantilla y marcá lo que se te olvidó.
4. Esperá 10–15 min y repetí. A la noche, repetí de nuevo.
5. Los ejercicios: intentarlos SOLO (sin mirar nada) y comparar después.

## Bloque 1 — Corte de control (el pesado, ~60%)

- **Paso 1 · plantilla de memoria (15 min)** — Escribí de memoria el doble while con las 3 secciones (PDF §2). Después las variantes buffer (PDF §3) y 2 niveles (PDF §4).
- **Paso 2 · 4.5.1 promedio por asignatura (30 min)** — Enunciado en `docs/reglas...md` §4.5.1 (CALIFICACIONES.dat). Hacelo entero sin mirar; compará contra §2/§3.
- **Paso 3 · 07_examenes (45 min)** — `src/problemas-parcial/tiddy/07_examenes/principal.cpp` es TODO: corte de control por idAlu. Leé el enunciado y resolvelo desde cero.
- **Paso 4 · 2 niveles (15 min)** — `tiddy/13_imputacion`: corte por empleado y luego por proyecto. Armá el esqueleto de 3 whiles de memoria.

## Bloque 2 — Procesamiento directo (~25%)

- Reescribí de memoria la tabla de clasificación (`docs/AGENTS.md` L231–235).
- Un ejercicio binario: `read<T>` y procesar al vuelo.
- Un ejercicio de texto: `readLine` + `getTokenAt` + `stringToInt`.
- Uno de `tiddy/enunciados` que sea procesamiento directo, a mano.

## Bloque 3 — Cierre (~15%)

- Repetí la plantilla de corte de control de memoria una última vez.
- Recitá el checklist (PDF §7) sin mirar.

## Simulacros (mañana temprano, como si fuera el parcial)

- 2 ejercicios nuevos (1 corte de control + 1 procesamiento directo), cronometrados, sin mirar nada.
- Formato espejo del parcial: hpp dado + `principal.cpp` en blanco.

## La hoja mental (no se puede llevar hoja — memorizá esto)

1. ¿Archivo ordenado por clave + informar por subconjunto? → **corte de control** (doble while).
2. ¿Cada registro suelto? → **procesamiento directo** (while simple).
3. `collAdd` → ToString; `collGetAt/Next/Find` → FromString.
4. Primera lectura antes del while; leer al final del interno; `!feof` en ambos.
