TITLE: Inscripciones a cursos
TAGS: [[Nivel básico]] Problema

Una facultad registra las inscripciones de alumnos a los cursos de una materia. Cada alumno se inscribe a un solo curso. Los cursos tienen un cupo máximo de alumnos. Dada la naturaleza del contexto, todos los archivos que se describen a continuación tienen una cantidad acotada de registros.

```cpp
// Archivo: CURSOS.dat
struct Curso
{
   int idCurso;
   int capacidad;
   char nombre[50];
};
```

```cpp
// Archivo: INSCRIPCIONES.dat
struct Inscripcion
{
   int idAlumno; // ordenado
   int idCurso;
};
```

!!! Se pide:

# Un listado de los cursos cuyo cupo fue superado, indicando cuántos alumnos exceden la capacidad.
# Reasignar a los alumnos que quedaron sin lugar en el curso que eligieron, generando el archivo `REASIGNACION.dat` con la nueva inscripción. La reasignación se hace al primer curso (en orden del catálogo) que tenga lugar disponible y en el que el alumno no esté inscripto. Si ningún curso tiene lugar, el alumno no se reasigna.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `CURSOS.dat`        → 4 cursos = 240 B (60 B c/u)
- `INSCRIPCIONES.dat` → 6 inscripciones = 48 B (8 B c/u), ordenado por idAlumno
- `REASIGNACION.dat`  → generado por el programa = 8 B (1 registro)

Layout C++ (MinGW, little endian):
- `Curso`       = 60 B: idCurso@0, capacidad@4, nombre@8, pad 58-59
- `Inscripcion` = 8 B (2 ints)

Cursos:
- C1 ALGORITMOS Y ESTRUCTURAS DE DATOS (cap 2)
- C2 PARADIGMAS (cap 2)
- C3 BASES DE DATOS (cap 1)
- C4 INGENIERIA DE SOFTWARE (cap 2)

Inscripciones: A1→C1, A2→C1, A3→C1, A4→C2, A5→C2, A6→C3
Cupos: C1 = 3 (superado en 1), C2 = 2 (completo), C3 = 1 (completo), C4 = 0 (libre)

1) Cursos con cupo superado:
   - C1 ALGORITMOS Y ESTRUCTURAS DE DATOS: excedente 1

2) REASIGNACION.dat:
   - A3→C4 (el único curso con lugar disponible)
