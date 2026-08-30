TITLE: Streaming de audiolibros
TAGS: [[Nivel básico]] Problema

Un emprendimiento universitario registra el audio que proviene de la lectura de libros, y lo publica en una plataforma de //streaming// de audiolibros. Dada la naturaleza del contexto (emprendimiento universitario), todos los archivos que se describen a continuación tienen una cantidad acotada de registros.

```cpp
// Archivo: REPRODUCCIONES.dat
struct Reproduccion
{
   int idUsuario; // ordenado
   int idLibro;
   int fecha;
   int minutos;
};
```

```cpp
// Archivo: LIBROS.dat
struct Libro
{
   int idLibro; 
   int idRelator;
   int idAutor; 
   char titulo[50];
   int duracion; 
};
```

```cpp
// Archivo: RELATORES.dat
struct Relator
{
   int idRelator; 
   char nombre[50]; 
};
```

Un libro puede durar varias horas. Por esto, es probable que existan varias reproducciones de un mismo usuario para un mismo libro, hasta terminarlo, o dejarlo inconcluso. Se acepta que un mismo usuario no escuchará el mismo libro más de una vez. Cada reproducción de un usuario para con un libro comenzará desde el mismo instante en que lo dejó de escuchar durante la reproducción anterior, o desde el inicio si es la primera reproducción.

!!! Se pide:

# Un  listado ordenado por  libro,  indicando cuántas reproducciones completas tuvo. Cuántas estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%, y cuántas reproducciones duraron menos del 25% del total del cuento.

# Los 10 relatores cuyas lecturas tuvieron la mayor cantidad de reproducciones entre el 75% y 100%, ordenado de mayor a menor por dicha cantidad.

Un emprendimiento universitario registra el audio que proviene de la lectura de libros, y lo publica en una plataforma de //streaming// de audiolibros. Dada la naturaleza del contexto (emprendimiento universitario), todos los archivos que se describen a continuación tienen una cantidad acotada de registros.

```cpp
// Archivo: REPRODUCCIONES.dat
struct Reproduccion
{
   int idUsuario; // ordenado
   int idLibro;
   int fecha;
   int minutos;
};
```

```cpp
// Archivo: LIBROS.dat
struct Libro
{
   int idLibro; 
   int idRelator;
   int idAutor; 
   char titulo[50];
   int duracion; 
};
```

```cpp
// Archivo: RELATORES.dat
struct Relator
{
   int idRelator; 
   char nombre[50]; 
};
```

Un libro puede durar varias horas. Por esto, es probable que existan varias reproducciones de un mismo usuario para un mismo libro, hasta terminarlo, o dejarlo inconcluso. Se acepta que un mismo usuario no escuchará el mismo libro más de una vez. Cada reproducción de un usuario para con un libro comenzará desde el mismo instante en que lo dejó de escuchar durante la reproducción anterior, o desde el inicio si es la primera reproducción.

!!! Se pide:

# Un  listado ordenado por  libro,  indicando cuántas reproducciones completas tuvo. Cuántas estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%, y cuántas reproducciones duraron menos del 25% del total del cuento.

# Los 10 relatores cuyas lecturas tuvieron la mayor cantidad de reproducciones entre el 75% y 100%, ordenado de mayor a menor por dicha cantidad.