TITLE: Streaming de audiocuentos
TAGS: [[Nivel básico]] Problema

Un emprendimiento universitario registra el audio que proviene de la lectura de cuentos, y lo publica en una plataforma de //streaming// de audiocuentos. Dada la naturaleza del contexto (emprendimiento universitario), todos los archivos que se describen a continuación tienen una cantidad acotada de registros.

```cpp
// Archivo: REPRODUCCIONES.dat
struct Reproduccion
{
   int idUsuario; 
   int idCuento;
   int fecha;
   int minutos;
};
```

```cpp
// Archivo: CUENTOS.dat
struct Cuento
{
   int idCuento; 
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

La duración de los cuentos es muy corta. De este modo, si un mismo usuario reproduce más de una vez un mismo cuento, será porque lo quiso escuchar varias veces. 

!!!Se pide:

# Un listado ordenado por cuento, indicando cuántas reproducciones completas tuvo. Cuántas estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%,  y cuántas reproducciones duraron menos del 25% del total del cuento.
# Los 10 relatores cuyas lecturas tuvieron la mayor cantidad de reproducciones entre el 75% y 100%, ordenado de mayor a menor por dicha cantidad.


Un emprendimiento universitario registra el audio que proviene de la lectura de cuentos, y lo publica en una plataforma de //streaming// de audiocuentos. Dada la naturaleza del contexto (emprendimiento universitario), todos los archivos que se describen a continuación tienen una cantidad acotada de registros.

```cpp
// Archivo: REPRODUCCIONES.dat
struct Reproduccion
{
   int idUsuario; 
   int idCuento;
   int fecha;
   int minutos;
};
```

```cpp
// Archivo: CUENTOS.dat
struct Cuento
{
   int idCuento; 
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

La duración de los cuentos es muy corta. De este modo, si un mismo usuario reproduce más de una vez un mismo cuento, será porque lo quiso escuchar varias veces. 

!!!Se pide:

# Un listado ordenado por cuento, indicando cuántas reproducciones completas tuvo. Cuántas estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%,  y cuántas reproducciones duraron menos del 25% del total del cuento.
# Los 10 relatores cuyas lecturas tuvieron la mayor cantidad de reproducciones entre el 75% y 100%, ordenado de mayor a menor por dicha cantidad.
