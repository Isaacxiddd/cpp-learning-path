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

# Un listado ordenado por libro, indicando cuántas reproducciones completas tuvo. Cuántas estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%, y cuántas reproducciones duraron menos del 25% del total del cuento.

# Los 10 relatores cuyas lecturas tuvieron la mayor cantidad de reproducciones entre el 75% y 100%, ordenado de mayor a menor por dicha cantidad.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `REPRODUCCIONES.dat` → 7 reproducciones = 112 B (16 B c/u), ordenado por idUsuario
- `LIBROS.dat`         → 2 libros = 136 B (68 B c/u)
- `RELATORES.dat`      → 2 relatores = 112 B (56 B c/u)

Layout C++ (MinGW, little endian):
- `Reproduccion` = 16 B (4 ints)
- `Libro`        = 68 B: idLibro@0, idRelator@4, idAutor@8, titulo@12, duracion@62, pad 66-67
- `Relator`      = 56 B: idRelator@0, nombre@4, pad 54-55

Libros (duracion 100 ambos):
- 1 EL QUIJOTE
- 2 CIEN ANOS DE SOLEDAD

Corte de control (usuario,libro) acumulando minutos:
- u1,l1: 40+40 = 80 → 80%
- u1,l2: 30 → 30%
- u2,l1: 30 → 30%
- u2,l2: 100 → completa
- u3,l1: 10 → 10%
- u3,l2: 50 → 50%

1) Reproducciones por libro:
   - Libro 1: completa 0, 75-100% 1 (u1=80), 50-75% 0, 25-50% 1 (u2=30), <25% 1 (u3=10)
   - Libro 2: completa 1 (u2=100), 75-100% 0, 50-75% 1 (u3=50), 25-50% 1 (u1=30), <25% 0

2) Relatores (reproducciones 75-100%, incluye completas):
   - Relator 1 (libro 1): 1
   - Relator 2 (libro 2): 1
