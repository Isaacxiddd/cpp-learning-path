TITLE: Torneo de fútbol
TAGS: Problema [[Nivel básico]]

Se requiere un programa que informe sobre la posición actual de cada uno de los equipos que participan de un torneo de fútbol.

Contamos con archivos: `RESULTADOS.dat`, con los resultados de los partidos que se jugaron durante la última fecha, y `EQUIPOS.dat`, que contiene la información de los equipos que participan en el torneo.

La estructura de cada uno de estos archivos la vemos a continuación:

```cpp
struct Resultado
{
   int idEq1;
   int idEq2;
   int codRes;
   char estadio[20];
};
```

```cpp
struct Equipo
{
   int idEq;
   char nombre[20];
   int puntos;
};
```

El valor del campo `codRes` (código de resultado) indica qué equipo ganó el partido. Si `codRes`<0 significa que ganó el equipo identificado con `idEq1`. Si `codRes`>0 el ganador fue el equipo identificado con `idEq2`. Finalmente, si `codRes` es 0 (cero) el partido resultó en empate.

El equipo ganador acumula 3 puntos. Si empataron le corresponde 1 punto cada uno. El perdedor no recibe puntos.

!!! Se pide:

# Informar la tabla de posiciones actualizada al día del proceso.
# Informar, para cada estadio, cuántos partidos se jugaron y cuántos de estos partidos resultaron empatados.
# Actualizar las puntuaciones en el archivo `EQUIPOS.dat`.

=== RESULTADO ESPERADO (datos provistos) ===

EQUIPOS.dat (consulta, puntos ANTES de la fecha):
  1 River            22
  2 Boca             20
  3 Racing           18
  4 Independiente    17
  5 San Lorenzo      16
  6 Huracan          15
  7 Velez            14
  8 Lanus            13
  9 Estudiantes      12
 10 Newells          11

RESULTADOS.dat (novedades, 8 partidos):
  1-2 cod=-1 (gana 1) Monumental
  3-4 cod= 1 (gana 4) Cilindro
  5-6 cod= 0 (empate) Nuevo Gasometro
  7-8 cod=-1 (gana 7) Jose Amalfitani
  9-10 cod= 0 (empate) UNO
  2-3 cod= 0 (empate) Bombonera
  4-5 cod=-1 (gana 4) Libertadores
  6-7 cod= 1 (gana 7) Duc

P1) Tabla de posiciones (puntos actualizados):
  River 25, Boca 21, Independiente 20, Racing 19, San Lorenzo 17,
  Velez 17, Huracan 16, Estudiantes 13, Lanus 13, Newells 12

P2) Estadios:
  Monumental: 1 jugado, 0 empatados
  Cilindro: 1 jugado, 0 empatados
  Nuevo Gasometro: 1 jugado, 1 empatado
  Jose Amalfitani: 1 jugado, 0 empatados
  UNO: 1 jugado, 1 empatado
  Bombonera: 1 jugado, 1 empatado
  Libertadores: 1 jugado, 0 empatados
  Duc: 1 jugado, 0 empatados

P3) EQUIPOS.dat actualizado con los puntos de la P1.
