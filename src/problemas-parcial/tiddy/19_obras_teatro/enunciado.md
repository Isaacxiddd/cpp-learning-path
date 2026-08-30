TITLE: Obras de teatro
TAGS: [[Nivel avanzado]] Problema

Un sitio de Internet vende localidades para las obras de teatro que se encuentran en cartel. Cada sala tiene varios sectores numerados desde 1, y cada sector admite una determinada capacidad de espectadores.

```cpp
struct Obra
{
   int idObra;
   char titulo[100];
   int fEstreno; // aaaammdd
   int idTeatro;
};
```

```cpp
struct Teatro
{
   int idTeatro;
   char direccion[50];
   int capacidad;
   int sectores;
};
```

```cpp
struct Funcion
{
   int idFuncion; // unico e irrepetible
   int diaSem;    // 1=>Lunes, 2=>Martes, ...
   int hora;      // hhmm
};
```

```cpp
struct Reserva
{
   int idCliente;
   int idObra;
   int idFuncion;
   int sector; // sector de la sala
   int cant;
};
```

Se dispone de `funcionesProgramadas(idObra)`, `leerReserva()` (bloqueante) y `continuarOperando()` como funciones de biblioteca. En esta práctica se simulan con archivos: `FUNCIONES.dat` (con la convención `idFuncion = idObra*100 + secuencia`), `RESERVAS.dat`, `OBRAS.dat` y `TEATROS.dat`.

La capacidad de un sector se calcula como `capacidad / sectores` del teatro. Sólo se aceptan reservas completas.

!!! Se pide:

# Emitir un listado indicando, por cada obra y por cada función, la cantidad de reservas que quedaron excluidas por falta de capacidad.

| Obra de teatro (titulo): MALEVO        |
| Id. Función | Dia | Hora  | Rechazos |
| 101         | 1   | 21:00 | 1        |
| 102         | 2   | 21:00 | 0        |
|             |     |       | Total: 1 |

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `TEATROS.dat`   → 2 teatros = 128 B (64 B c/u)
- `OBRAS.dat`     → 2 obras = 224 B (112 B c/u)
- `FUNCIONES.dat` → 4 funciones = 48 B (12 B c/u)
- `RESERVAS.dat`  → 7 reservas = 140 B (20 B c/u)

Layout C++ (MinGW, little endian):
- `Teatro`   = 64 B: idTeatro@0, direccion@4, pad 54-55, capacidad@56, sectores@60
- `Obra`     = 112 B: idObra@0, titulo@4, fEstreno@104, idTeatro@108
- `Funcion`  = 12 B (3 ints)
- `Reserva`  = 20 B (5 ints)

Teatros: T1 cap 200 / 2 sectores (sector = 100), T2 cap 300 / 3 sectores (sector = 100).

Obras: O1 MALEVO (T1), O2 EL PRINCIPE FELIZ (T2).
Funciones: O1 → F101 (Lun 21:00), F102 (Mar 21:00); O2 → F201 (Mié 20:00), F202 (Jue 22:00).

Reservas:
- R1 c1 O1 F101 sector1 40 → aceptada (40/100)
- R2 c2 O1 F101 sector1 70 → rechazada (40+70 > 100)
- R3 c3 O1 F101 sector2 30 → aceptada (30/100)
- R4 c4 O1 F102 sector1 60 → aceptada
- R5 c5 O2 F201 sector1 100 → aceptada (sector lleno)
- R6 c6 O2 F201 sector1 20 → rechazada
- R7 c7 O2 F202 sector3 50 → aceptada

Resultado:
- O1 MALEVO: F101 1 rechazo, F102 0 → Total 1
- O2 EL PRINCIPE FELIZ: F201 1 rechazo, F202 0 → Total 1
