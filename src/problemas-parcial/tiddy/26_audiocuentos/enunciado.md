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

# Un listado ordenado por cuento, indicando cuántas reproducciones completas tuvo. Cuántas estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%, y cuántas reproducciones duraron menos del 25% del total del cuento.
# Los 10 relatores cuyas lecturas tuvieron la mayor cantidad de reproducciones entre el 75% y 100%, ordenado de mayor a menor por dicha cantidad.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `REPRODUCCIONES.dat` → 11 reproducciones = 176 B (16 B c/u)
- `CUENTOS.dat`        → 3 cuentos = 204 B (68 B c/u)
- `RELATORES.dat`      → 2 relatores = 112 B (56 B c/u)

Layout C++ (MinGW, little endian):
- `Reproduccion` = 16 B (4 ints)
- `Cuento`       = 68 B: idCuento@0, idRelator@4, idAutor@8, titulo@12, duracion@62, pad 66-67
- `Relator`      = 56 B: idRelator@0, nombre@4, pad 54-55

Cuentos:
- 1 EL PRINCIPE FELIZ (dur 100)
- 2 LA CIGARRA Y LA HORMIGA (dur 50)
- 3 RAPUNZEL (dur 80)

1) Reproducciones por cuento:
   - Cuento 1: completa 2 (u1=100, u6=100), 75-100% 1 (u2=80), 50-75% 1 (u3=60), 25-50% 1 (u4=30), <25% 1 (u5=10)
   - Cuento 2: completa 1 (u1=50), 75-100% 1 (u2=40), 50-75% 1 (u3=30), 25-50% 0, <25% 0
   - Cuento 3: completa 1 (u1=80), 75-100% 0, 50-75% 0, 25-50% 0, <25% 1 (u2=10)

2) Relatores (reproducciones 75-100%, incluye completas):
   - Relator 1 (cuentos 1 y 2): completa 2+1=3, 75-100 1+1=2 → total 5
   - Relator 2 (cuento 3): completa 1 → total 1
   Orden: relator 1 (5), relator 2 (1).
