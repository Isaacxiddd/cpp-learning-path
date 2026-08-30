TITLE: Imputación horas/proyecto
TAGS: Problema [[Nivel intermedio]]


!! Versión 1

Una consultora que gestiona diversos proyectos requiere información sobre cómo sus empleados distribuyen el tiempo de trabajo. Los datos se encuentran disponibles en los siguientes  archivos: `PROYECTOS.dat`, que describe los proyectos gestionados por la consultora. `EMPLEADOS.dat`, con los datos de los empleados, y `HORAS.dat`, con el detalle de las horas de trabajo que cada empleado dice haber trabajado en cada proyecto.

Existen 20 proyectos, cuyos  `idProyecto` se numeran de 1 a 20, y 50 empleados, cuyos `idEmpleado` se numeran de 1 a 50. 

```cpp
// Archivo: PROYECTOS.dat
struct Proyecto
{
   int idProyecto;
   char descripcion[100];
   int fechaInicio;
   int horasAsignadas;
   int horasImputadas;
};
```

```cpp
// Archivo HORAS.dat
struct Hora
{
   int idEmpleado; 
   int idProyecto; 
   int fecha; // *ordenado
   int horas; 
   char tareas[200];
};
```

```cpp
// Archivo: EMPLEADOS.dat
struct Empleado
{
   int idEmpleado;
   char nombre[50]; 
};
```

!!! Se pide:

#Emitir un listado indicando, para cada proyecto, qué empleados trabajaron, y por cada uno, qué tareas desarrolló. Ordenado por proyecto, luego por empleado, y por fecha descendente.<div>

|>|>|Proyecto: xxxxxxxxxxxxxxxxx |
|>|>|Horas asignadas: 9999 |
|>|>|Horas imputadas: 9999 |

|>|>|Empleado: xxxxxxxxxxxxxxxxx, Horas trabajadas: 999 |
|Fecha |Tarea desarrollada |Horas |
| 99/99/9999|xxxxxxxxxxxxxxxxxxxxxxxx | 9999|
| 99/99/9999|xxxxxxxxxxxxxxxxxxxxxxxx | 9999|
| 99/99/9999|xxxxxxxxxxxxxxxxxxxxxxxx | 9999|
| :|: | :|

</div>

!! Versión 2

Ídem anterior, pero no se conoce cuántos proyectos gestiona la consultora, ni cuantos empleados allí trabajan. Sí se sabe que no serán más de 100 proyectos y no trabajan más de 300 empleados. Además, sus identificadores (`idProyecto`, `idEmpleado`) no necesariamente comienzan desde 1 ni son correlativos.

!! Versión 1

Una consultora que gestiona diversos proyectos requiere información sobre cómo sus empleados distribuyen el tiempo de trabajo. Los datos se encuentran disponibles en los siguientes  archivos: `PROYECTOS.dat`, que describe los proyectos gestionados por la consultora. `EMPLEADOS.dat`, con los datos de los empleados, y `HORAS.dat`, con el detalle de las horas de trabajo que cada empleado dice haber trabajado en cada proyecto.

Existen 20 proyectos, cuyos  `idProyecto` se numeran de 1 a 20, y 50 empleados, cuyos `idEmpleado` se numeran de 1 a 50. 

```cpp
// Archivo: PROYECTOS.dat
struct Proyecto
{
   int idProyecto;
   char descripcion[100];
   int fechaInicio;
   int horasAsignadas;
   int horasImputadas;
};
```

```cpp
// Archivo HORAS.dat
struct Hora
{
   int idEmpleado; 
   int idProyecto; 
   int fecha; // *ordenado
   int horas; 
   char tareas[200];
};
```

```cpp
// Archivo: EMPLEADOS.dat
struct Empleado
{
   int idEmpleado;
   char nombre[50]; 
};
```

!!! Se pide:

#Emitir un listado indicando, para cada proyecto, qué empleados trabajaron, y por cada uno, qué tareas desarrolló. Ordenado por proyecto, luego por empleado, y por fecha descendente.<div>

|>|>|Proyecto: xxxxxxxxxxxxxxxxx |
|>|>|Horas asignadas: 9999 |
|>|>|Horas imputadas: 9999 |

|>|>|Empleado: xxxxxxxxxxxxxxxxx, Horas trabajadas: 999 |
|Fecha |Tarea desarrollada |Horas |
| 99/99/9999|xxxxxxxxxxxxxxxxxxxxxxxx | 9999|
| 99/99/9999|xxxxxxxxxxxxxxxxxxxxxxxx | 9999|
| 99/99/9999|xxxxxxxxxxxxxxxxxxxxxxxx | 9999|
| :|: | :|

</div>

!! Versión 2

Ídem anterior, pero no se conoce cuántos proyectos gestiona la consultora, ni cuantos empleados allí trabajan. Sí se sabe que no serán más de 100 proyectos y no trabajan más de 300 empleados. Además, sus identificadores (`idProyecto`, `idEmpleado`) no necesariamente comienzan desde 1 ni son correlativos.