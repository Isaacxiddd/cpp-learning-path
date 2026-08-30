TITLE: Imputación de horas
TAGS: [[Nivel básico]] Problema

Una consultora informática registra las horas imputadas por sus empleados a los proyectos de la empresa. Dada la naturaleza del contexto, todos los archivos que se describen a continuación tienen una cantidad acotada de registros.

```cpp
// Archivo: PROYECTOS.dat
struct Proyecto
{
   int idProy;
   char descr[50];
   char dir[50];
};
```

```cpp
// Archivo: HORAS.dat
struct Horas
{
   int idEmpleado; // ordenado
   int idProy;     // ordenado
   int horas;
   int fecha;
};
```

```cpp
// Archivo: EMPLEADOS.dat
struct Empleado
{
   int idEmp;
   char nombre[50];
};
```

Cada registro del archivo HORAS representa la cantidad de horas que un empleado le imputó a un proyecto en un día determinado. Un mismo empleado puede imputar horas a distintos proyectos en distintos días.

!!! Se pide:

# Un listado por proyecto indicando el total de horas imputadas y la cantidad de empleados que participaron en él.
# Un listado por empleado indicando el total de horas imputadas y la cantidad de proyectos en los que trabajó.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `PROYECTOS.dat` → 3 proyectos = 312 B (104 B c/u)
- `HORAS.dat`     → 7 imputaciones = 112 B (16 B c/u), ordenado por idEmpleado + idProy
- `EMPLEADOS.dat` → 3 empleados = 168 B (56 B c/u)

Layout C++ (MinGW, little endian):
- `Proyecto` = 104 B: idProy@0, descr@4, dir@54
- `Horas`    = 16 B (4 ints)
- `Empleado` = 56 B: idEmp@0, nombre@4, pad 54-55

Imputaciones (corte por empleado, luego por proyecto):
- E1: P1 5+3=8, P2 4   → E1 total 12, proyectos 2
- E2: P1 6, P3 8       → E2 total 14, proyectos 2
- E3: P1 2, P2 7       → E3 total 9, proyectos 2

1) Listado por proyecto:
   - P1 SISTEMA DE FACTURACION: 16 horas, 3 empleados
   - P2 PORTAL WEB: 11 horas, 2 empleados
   - P3 APP MOVIL: 8 horas, 1 empleado

2) Listado por empleado:
   - E1 LOPEZ MARIA: 12 horas, 2 proyectos
   - E2 FERNANDEZ PEDRO: 14 horas, 2 proyectos
   - E3 RUIZ SOFIA: 9 horas, 2 proyectos
