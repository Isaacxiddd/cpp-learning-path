TITLE: Padrón / Inscripciones - Inconsistencias
TAGS: Problema [[Nivel intermedio]] · Búsqueda binaria sobre archivo

Se dispone del archivo `PADRON.dat`, que contiene el padrón de los estudiantes matriculados en todas las escuelas de la municipalidad. Este archivo se encuentra ordenado por `idEst`, y su estructura de registro es la siguiente:

```cpp
struct Padron
{
   int idEst;              // identificador de estudiante
   int dni;                // documento de identidad
   char nombre[20];
   char telefono[20];
   char direccion[20];
   int codigoPostal;
   int fechaNacimiento;    // aaaammdd
   int idEscuela;          // escuela donde estudia
   int fechaMatriculacion; // cuando se matriculo
   int idSeguroSocial;     // cobertura medica
};
```

Se cuenta también con el archivo `INSCRIPCIONES.dat`, sin orden, con las inscripciones de los estudiantes en los diferentes establecimientos educativos.

```cpp
struct Inscripcion
{
   int idEst;
   int idEscuela;
   int fecha;   // fecha de la inscripcion (aaaammdd)
};
```

Se pide generar el archivo `INCONSISTENCIAS.dat` con las inscripciones inconsistentes. Detallando el tipo de problema (1, 2 o 3), el nombre del estudiante involucrado, y el identificador de la escuela (`idEscuela`).

Tipos de problema:

1. El estudiante no figura en el padrón (tipo de problema: 1).
2. El estudiante figura matriculado en una escuela diferente a la que se inscribió (tipo de problema: 2).
3. La fecha de inscripción es anterior a la de matriculación (tipo de problema: 3).

El archivo de consulta (PADRON.dat) es demasiado extenso como para subirlo a una colección. Como está ordenado por `idEst` —que justamente es el campo por el cual nos interesa buscar— lo accederemos mediante el algoritmo de la búsqueda binaria.

Para grabar el archivo de inconsistencias utilizaremos la siguiente estructura:

```cpp
struct Inconsistencia
{
   int idTipoProblema; // 1, 2 o 3
   char nombreEstudiante[20];
   int idEscuela;
};
```

!!! Se pide:

# Generar `INCONSISTENCIAS.dat` recorriendo las inscripciones y consultando el padrón con búsqueda binaria (`buscarEstudiante`). Cuando el estudiante no existe, el nombre grabado será `desconocido!!`.
# Listar el contenido de `INCONSISTENCIAS.dat`.

=== RESULTADO ESPERADO (datos provistos) ===

PADRON.dat (consulta, ordenado por idEst, 10 estudiantes):
 100 GARCIA JUAN    esc 1  mat 20220101
 150 PEREZ ANA      esc 2  mat 20220201
 200 LOPEZ LUIS     esc 3  mat 20220301
 250 MARTINEZ CARLA esc 4  mat 20220401
 300 GOMEZ PEDRO    esc 5  mat 20220501
 350 DIAZ SOFIA     esc 6  mat 20220601
 400 FERNANDEZ JOSE esc 7  mat 20220701
 450 ALVAREZ MARIA  esc 8  mat 20220801
 500 ROMERO DIEGO   esc 9  mat 20220901
 550 TORRES LAURA   esc 10 mat 20221001

INSCRIPCIONES.dat (novedades, 12 registros sin orden):
 100/1/20220101 ok · 120/2/20220301 inexistente · 250/5/20220501 esc-dif
 300/3/20200101 esc-dif · 150/2/20220202 ok · 999/1/20220601 inexistente
 200/3/20200101 fecha-ant · 350/6/20200101 fecha-ant · 450/5/20220909 esc-dif
 100/7/20220707 esc-dif · 400/7/20220701 ok · 550/10/20221201 ok

INCONSISTENCIAS.dat (8 registros, en orden de las inscripciones):
 1 | desconocido!!  | 2
 2 | MARTINEZ CARLA | 5
 2 | GOMEZ PEDRO    | 3
 1 | desconocido!!  | 1
 3 | LOPEZ LUIS     | 3
 3 | DIAZ SOFIA     | 6
 2 | ALVAREZ MARIA  | 5
 2 | GARCIA JUAN    | 7
