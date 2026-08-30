TITLE: Inscripción en la facultad
TAGS: Problema [[Nivel avanzado]]

Para agilizar su sistema de inscripción, una facultad requiere desarrollar un programa que procese los siguientes archivos: `INSCRIPCIONES.dat`, con las inscripciones de los estudiantes a los diferentes cursos, y `CURSOS.dat`, con la oferta de cursos disponibles donde se dictarán las diferentes materias.

`INSCRIPCIONES.dat` se encuentra  ordenado  ascendentemente según la fecha de la inscripción.

```cpp
struct Inscripcion
{
   int idAlu;
   int idCur;
   int fecha; // aaaammdd
};
```

```cpp
struct Curso
{
   int idCur; 
   char turno; // M, T o N
   int cap;
   char materia[20]; 
};
```

!!! Se pide:

# Por cada alumno, emitir el listado de materias en que su inscripción resultó rechazada por falta de capacidad en el curso.
# Por cada materia, generar un listado de cursos donde, luego de procesar las inscripciones, quedaron cupos disponibles.
# Grabar el archivo `REASIGNACION.dat`, cuya estructura se describe más abajo, reasignando (siempre que sea posible) las inscripciones rechazadas a aquellos cursos que quedaron con cupos disponibles. Este archivo debe quedar ordenado por `idAlu`. <div>

```java
struct Reasignacion
{
   int idAlu;
   int idCurReasig;
};
```
</div>

# Generar el archivo `REASIGNACION2.dat`, con registros `Reasignacion2`, con los pares {`idAlu`, `materia`} que no pudieron ser reasignados en el punto anterior.<div>

```java
struct Reasignacion2
{
   int idAlu;
   char materia[20];
};
```
</div>


Para agilizar su sistema de inscripción, una facultad requiere desarrollar un programa que procese los siguientes archivos: `INSCRIPCIONES.dat`, con las inscripciones de los estudiantes a los diferentes cursos, y `CURSOS.dat`, con la oferta de cursos disponibles donde se dictarán las diferentes materias.

`INSCRIPCIONES.dat` se encuentra  ordenado  ascendentemente según la fecha de la inscripción.

```cpp
struct Inscripcion
{
   int idAlu;
   int idCur;
   int fecha; // aaaammdd
};
```

```cpp
struct Curso
{
   int idCur; 
   char turno; // M, T o N
   int cap;
   char materia[20]; 
};
```

!!! Se pide:

# Por cada alumno, emitir el listado de materias en que su inscripción resultó rechazada por falta de capacidad en el curso.
# Por cada materia, generar un listado de cursos donde, luego de procesar las inscripciones, quedaron cupos disponibles.
# Grabar el archivo `REASIGNACION.dat`, cuya estructura se describe más abajo, reasignando (siempre que sea posible) las inscripciones rechazadas a aquellos cursos que quedaron con cupos disponibles. Este archivo debe quedar ordenado por `idAlu`. <div>

```java
struct Reasignacion
{
   int idAlu;
   int idCurReasig;
};
```
</div>

# Generar el archivo `REASIGNACION2.dat`, con registros `Reasignacion2`, con los pares {`idAlu`, `materia`} que no pudieron ser reasignados en el punto anterior.<div>

```java
struct Reasignacion2
{
   int idAlu;
   char materia[20];
};
```
</div>
