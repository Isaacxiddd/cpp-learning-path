TITLE: Corrección de exámenes
TAGS: Problema [[Nivel intermedio]]

Un profesor desea automatizar la corrección de los exámenes que rinden sus estudiantes. Para esto requiere un programa que le permita cotejar las respuestas correctas (o esperadas) con las respuestas entregadas.

Un examen consiste en 20 afirmaciones, cada una de las cuales el estudiante deberá determinar si son verdaderas o falsas. A su vez, las afirmaciones se dividen en dos grupos: teoría y práctica. Las respuestas correctas suman 0,5 puntos. Las incorrectas restan 0,5 puntos. Las afirmaciones no respondidas no se toman en cuenta.

La calificación total del estudiante se calcula como: 0,5*//n//-0,5*//m//, siendo //n// y //m//, respectivamente, la cantidad de afirmaciones correcta e incorrectamente respondidas.

La nota mínima para aprobar el examen es 6 (seis). Sin embargo, el profesor impone la siguiente restricción: cada parte del examen (teórica y práctica) debe tener un mínimo de 3 puntos. De lo contrario el examen estará reprobado. A su vez, para que el examen lleve una calificación numérica, el estudiante deberá haber obtenido 
un mínimo de 2,5 puntos por categoría. De otro modo la calificación será R (reprobado).

En síntesis, los exámenes se calificarán con números entre 5 y 10, siendo 5 reprobado, y entre 6 y 10 aprobado. O llevarán la letra R en caso de no cumplir con la condición de haber obtenido un mínimo de 2,5 puntos por cada grupo de afirmaciones.

Existen 5 temas diferentes. Cada tema representa un conjunto de 20 afirmaciones; 10 prácticas y 10 teóricas. 

La información a procesar se encuentra detallada en los archivos que veremos a continuación. El archivo `RESPUESTAS.dat`, que contiene las respuestas entregadas por 
los estudiantes, se encuentra ordenado por `idAlu`, `tipoAfir`, `idAfir`. Las afirmaciones no respondidas no figuran en el archivo. De este modo, las respuestas entregadas por un estudiante para un examen podrían ser 20 o menos.

Archivos `ALUMNOS.dat`  y `CURSOS.dat`.

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
   char turno; // 'M','T'... 
};
```

Archivos `TEMAS.dat` y `RESPUESTAS.dat`: 

```cpp
struct Tema
{
   int idTema; 
   int idAfir;
   char tipoAfir;// 'T','P'
   char afir[250]; 
   char rta; // 'V', 'F'
};
```

```cpp
struct Respuesta
{
   int idAlu; 
   char tipoAfir; // 'T' o 'P' 
   int idAfir; // 1 a 10
   char rta; // 'V' o 'F'  
   int idTema; // 1 a 5
};
```

!!!Se pide: 
# Desarro el TAD `TTema` con la siguiente API: <div>

```cpp
// Funcion de inicializacion
TTema ttema(); 

// Evalua un examen y retorna la calificacion
int ttemaEvaluar(TTema t,List<Respuesta> lst);
```

</div>

# Emitir un listado detallando, por cada curso, todos los estudiantes que rindieron examen, cada uno con su correspondiente calificación. Indicando también las estadísticas que se muestran en el siguiente ejemplo. <div>

|>|Curso: K9999 |
|>|Rindieron: 999 |
|>|Aprobaron: 99 (99%) |
|>|Reprobaron: 99 (99%) |
|Alumno |Calificación |
|xxxxxxxxxxxxxxxxxxxx | 9|
|xxxxxxxxxxxxxxxxxxxx | 9|
|xxxxxxxxxxxxxxxxxxxx | 9|
|: | :|
|>| Promedio: 9|

</div>




Un profesor desea automatizar la corrección de los exámenes que rinden sus estudiantes. Para esto requiere un programa que le permita cotejar las respuestas correctas (o esperadas) con las respuestas entregadas.

Un examen consiste en 20 afirmaciones, cada una de las cuales el estudiante deberá determinar si son verdaderas o falsas. A su vez, las afirmaciones se dividen en dos grupos: teoría y práctica. Las respuestas correctas suman 0,5 puntos. Las incorrectas restan 0,5 puntos. Las afirmaciones no respondidas no se toman en cuenta.

La calificación total del estudiante se calcula como: 0,5*//n//-0,5*//m//, siendo //n// y //m//, respectivamente, la cantidad de afirmaciones correcta e incorrectamente respondidas.

La nota mínima para aprobar el examen es 6 (seis). Sin embargo, el profesor impone la siguiente restricción: cada parte del examen (teórica y práctica) debe tener un mínimo de 3 puntos. De lo contrario el examen estará reprobado. A su vez, para que el examen lleve una calificación numérica, el estudiante deberá haber obtenido 
un mínimo de 2,5 puntos por categoría. De otro modo la calificación será R (reprobado).

En síntesis, los exámenes se calificarán con números entre 5 y 10, siendo 5 reprobado, y entre 6 y 10 aprobado. O llevarán la letra R en caso de no cumplir con la condición de haber obtenido un mínimo de 2,5 puntos por cada grupo de afirmaciones.

Existen 5 temas diferentes. Cada tema representa un conjunto de 20 afirmaciones; 10 prácticas y 10 teóricas. 

La información a procesar se encuentra detallada en los archivos que veremos a continuación. El archivo `RESPUESTAS.dat`, que contiene las respuestas entregadas por 
los estudiantes, se encuentra ordenado por `idAlu`, `tipoAfir`, `idAfir`. Las afirmaciones no respondidas no figuran en el archivo. De este modo, las respuestas entregadas por un estudiante para un examen podrían ser 20 o menos.

Archivos `ALUMNOS.dat`  y `CURSOS.dat`.

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
   char turno; // 'M','T'... 
};
```

Archivos `TEMAS.dat` y `RESPUESTAS.dat`: 

```cpp
struct Tema
{
   int idTema; 
   int idAfir;
   char tipoAfir;// 'T','P'
   char afir[250]; 
   char rta; // 'V', 'F'
};
```

```cpp
struct Respuesta
{
   int idAlu; 
   char tipoAfir; // 'T' o 'P' 
   int idAfir; // 1 a 10
   char rta; // 'V' o 'F'  
   int idTema; // 1 a 5
};
```

!!!Se pide: 
# Desarro el TAD `TTema` con la siguiente API: <div>

```cpp
// Funcion de inicializacion
TTema ttema(); 

// Evalua un examen y retorna la calificacion
int ttemaEvaluar(TTema t,List<Respuesta> lst);
```

</div>

# Emitir un listado detallando, por cada curso, todos los estudiantes que rindieron examen, cada uno con su correspondiente calificación. Indicando también las estadísticas que se muestran en el siguiente ejemplo. <div>

|>|Curso: K9999 |
|>|Rindieron: 999 |
|>|Aprobaron: 99 (99%) |
|>|Reprobaron: 99 (99%) |
|Alumno |Calificación |
|xxxxxxxxxxxxxxxxxxxx | 9|
|xxxxxxxxxxxxxxxxxxxx | 9|
|xxxxxxxxxxxxxxxxxxxx | 9|
|: | :|
|>| Promedio: 9|

</div>


