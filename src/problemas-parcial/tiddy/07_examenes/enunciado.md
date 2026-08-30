TITLE: Corrección de exámenes
TAGS: Problema [[Nivel intermedio]] · Corte de control

Un profesor desea automatizar la corrección de los exámenes que rinden sus estudiantes. Para esto requiere un programa que le permita cotejar las respuestas correctas (o esperadas) con las respuestas entregadas.

Un examen consiste en 20 afirmaciones, cada una de las cuales el estudiante deberá determinar si son verdaderas o falsas. A su vez, las afirmaciones se dividen en dos grupos: teoría (`T`) y práctica (`P`). Las respuestas correctas suman 0,5 puntos. Las incorrectas restan 0,5 puntos. Las afirmaciones no respondidas no se toman en cuenta.

La calificación total del estudiante se calcula como: `0,5*n - 0,5*m`, siendo `n` y `m`, respectivamente, la cantidad de afirmaciones correcta e incorrectamente respondidas.

Cada parte del examen (teórica y práctica) debe tener un mínimo de 3 puntos, de lo contrario el examen estará reprobado. A su vez, para que el examen lleve una calificación numérica, el estudiante deberá haber obtenido un mínimo de 2,5 puntos por categoría. De otro modo la calificación será `R` (reprobado). La nota mínima para aprobar el examen es 6 (seis).

En síntesis: los exámenes se califican con números entre 5 y 10 (siendo 5 reprobado y entre 6 y 10 aprobado), o llevarán la letra `R` en caso de no cumplir con la condición de haber obtenido un mínimo de 2,5 puntos por cada grupo de afirmaciones.

El archivo `RESPUESTAS.dat`, con las respuestas entregadas por los estudiantes, se encuentra ordenado por `idAlu`, `tipoAfir`, `idAfir`. Las afirmaciones no respondidas no figuran en el archivo.

Archivos `ALUMNOS.dat` y `CURSOS.dat`:

```cpp
struct Alumno
{
   int idAlu;
   int legajo;
   char nombre[50];
   int idCur;
};
```

```cpp
struct Curso
{
   int idCur;
   char descr[10]; // K1027
   char turno;     // 'M','T'
};
```

Archivos `TEMAS.dat` y `RESPUESTAS.dat`:

```cpp
struct Tema
{
   int idTema;
   int idAfir;
   char tipoAfir; // 'T','P'
   char afir[250];
   char rta;      // 'V','F'
};
```

```cpp
struct Respuesta
{
   int idAlu;
   char tipoAfir; // 'T' o 'P'
   int idAfir;    // 1 a 10
   char rta;      // 'V' o 'F'
   int idTema;    // 1 a 5
};
```

!!! Se pide:

# Emitir un listado detallando, por cada estudiante que rindió examen, el curso al que pertenece (descripción y turno) y su calificación. El listado debe estar ordenado por `idAlu`.

=== RESULTADO ESPERADO (datos provistos) ===

TEMAS.dat (respuestas correctas, 2 temas × 2 tipos × 10 afirmaciones):
- Tema 1: teóricas impares `V` / pares `F` · prácticas impares `F` / pares `V`
- Tema 2: teóricas 1..5 `V` / 6..10 `F` · prácticas 1..5 `F` / 6..10 `V`

ALUMNOS.dat:
   1 PEREZ JUAN       (curso 1)     2 GOMEZ MARIA (curso 1)
   3 LOPEZ ANA        (curso 2)     4 FERNANDEZ LUIS (curso 2)
   5 SOSA CARLA       (curso 2)

RESPUESTAS.dat: todos los alumnos responden las 20 afirmaciones.

Salida esperada (corte de control por idAlu):

```
 1 PEREZ JUAN       K1027 M  7  Aprobado
 2 GOMEZ MARIA      K1027 M  0  R
 3 LOPEZ ANA        K2048 T  10 Aprobado
 4 FERNANDEZ LUIS   K2048 T  6  Aprobado
 5 SOSA CARLA       K2048 T  8  Aprobado
```

Detalle de la corrección (para verificar):

| idAlu | T ac | T err | notaT | P ac | P err | notaP | nota | cal |
|-------|------|-------|-------|------|-------|-------|------|-----|
| 1     | 8    | 2     | 3     | 9    | 1     | 4     | 7    | Aprobado |
| 2     | 4    | 6     | -1    | 6    | 4     | 1     | 0    | R |
| 3     | 10   | 0     | 5     | 10   | 0     | 5     | 10   | Aprobado |
| 4     | 8    | 2     | 3     | 8    | 2     | 3     | 6    | Aprobado |
| 5     | 9    | 1     | 4     | 9    | 1     | 4     | 8    | Aprobado |
