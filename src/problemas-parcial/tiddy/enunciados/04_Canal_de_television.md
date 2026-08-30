TITLE: Canal de televisión
TAGS: Problema [[Nivel avanzado]]

Un canal de televisión requiere validar una propuesta de programación diaria. La misma se encuentra detallada en el archivo `PLANIFICACION.dat` (ordenado por hora y minuto), que sólo es un borrador de lo que será la programación definitiva. Su estructura, así como la del archivo `PROGRAMAS.dat`, se describe a continuación.

```cpp
struct Planificacion
{
   int idPlanif; 
   int idProg;
   int horaInicio;     
   int minutoInicio;   
};
```

```cpp
struct Programa
{
   int idProg;
   char titulo[100];
   int duracion; // minutos
   int atp; // 0=>no, 1=>si 
};
```
En la programación propuesta podrían existir errores de dos tipos: 

* Superposición horaria, y 
* Programas que se emiten en un horario inadecuado, según sean ATP (Apto para Todo Público) o no.

En caso de existir superposición horaria el programa que se deberá descartar será el posterior. Por ejemplo: Si el programa  //p1// comienza a las 13 horas y dura 1 hora y media, y el programa //p2// comienza a las 14 horas, este será descartado de la planificación propuesta. 

Podría suceder que un programa se extienda hacia el día siguiente. Por ejemplo, un programa que comienza a las 23:30 horas y dura 120 minutos finalizará a la 1:30 horas del día siguiente, situación que también podría ocasionar superposición horaria.

El horario ATP está establecido por ley, y rige entre las 7 y las 22 horas. No debería suceder que un programa para adultos se emita total o parcialmente dentro de dicho horario.

Se dispone del TAD `Hora` cuyas funciones pueden utilizarse sin ser necesidad de programarlas. Además, contamos con las siguientes funciones:

La función `haySuperposicion` retorna `true` si un programa que comienza a la hora `hi1` (hora de inicio 1) y tiene una duración de `dur` minutos se extenderá más allá de la hora `hi2` (hora de inicio 2). Sí `hi2`<`hi1`  será porque `hi2` corresponde a un programa que comienza el siguiente día.

```cpp
bool haySuperposicion(Hora hi1,int dur,Hora hi2);
```

La función `invadeHorarioATP` retorna `true` si un programa, o parte del mismo, transcurre dentro del horario Apto para Todo Público (ATP).

```cpp
bool invadeHorarioATP(Hora h,int dur);
```

La función `calcularBache` retorna la hora de inicio de un bache en la programación y le asigna a `durb` la duración de dicho bache, en minutos.

```cpp
Hora calcularBache(Hora hi1,int durp,Hora hi2,int& durb);
```

La función `continuadoDiaAnterior` retorna cuántos minutos del comienzo del día están comprometido con la emisión de un programa que continúa del día anterior. Su prototipo es: 

```cpp
int continuadoDiaAnterior();
```

!!! Se pide:

# Generar el archivo `DESCARTADOS.dat`, con aquellos programas que, por cualquier motivo, fueron  removidos de la propuesta de planificación. La causa será: 1 si el programa se superponía con otro, o 2 si se emitía dentro del horario ATP sin tener la calificación habilitante.<div>

```cpp
struct Descartado
{
   int idPlanif;
   int causa;
};
```

</div>

# Generar el archivo `BACHES.dat` con los intervalos de tiempo que, luego de haber descartado los programas problemáticos, quedaron sin programación. <div>

```cpp
struct Bache
{
   int horaDesde;
   int minDesde;
   int duracion;
};
```

</div>

Un canal de televisión requiere validar una propuesta de programación diaria. La misma se encuentra detallada en el archivo `PLANIFICACION.dat` (ordenado por hora y minuto), que sólo es un borrador de lo que será la programación definitiva. Su estructura, así como la del archivo `PROGRAMAS.dat`, se describe a continuación.

```cpp
struct Planificacion
{
   int idPlanif; 
   int idProg;
   int horaInicio;     
   int minutoInicio;   
};
```

```cpp
struct Programa
{
   int idProg;
   char titulo[100];
   int duracion; // minutos
   int atp; // 0=>no, 1=>si 
};
```
En la programación propuesta podrían existir errores de dos tipos: 

* Superposición horaria, y 
* Programas que se emiten en un horario inadecuado, según sean ATP (Apto para Todo Público) o no.

En caso de existir superposición horaria el programa que se deberá descartar será el posterior. Por ejemplo: Si el programa  //p1// comienza a las 13 horas y dura 1 hora y media, y el programa //p2// comienza a las 14 horas, este será descartado de la planificación propuesta. 

Podría suceder que un programa se extienda hacia el día siguiente. Por ejemplo, un programa que comienza a las 23:30 horas y dura 120 minutos finalizará a la 1:30 horas del día siguiente, situación que también podría ocasionar superposición horaria.

El horario ATP está establecido por ley, y rige entre las 7 y las 22 horas. No debería suceder que un programa para adultos se emita total o parcialmente dentro de dicho horario.

Se dispone del TAD `Hora` cuyas funciones pueden utilizarse sin ser necesidad de programarlas. Además, contamos con las siguientes funciones:

La función `haySuperposicion` retorna `true` si un programa que comienza a la hora `hi1` (hora de inicio 1) y tiene una duración de `dur` minutos se extenderá más allá de la hora `hi2` (hora de inicio 2). Sí `hi2`<`hi1`  será porque `hi2` corresponde a un programa que comienza el siguiente día.

```cpp
bool haySuperposicion(Hora hi1,int dur,Hora hi2);
```

La función `invadeHorarioATP` retorna `true` si un programa, o parte del mismo, transcurre dentro del horario Apto para Todo Público (ATP).

```cpp
bool invadeHorarioATP(Hora h,int dur);
```

La función `calcularBache` retorna la hora de inicio de un bache en la programación y le asigna a `durb` la duración de dicho bache, en minutos.

```cpp
Hora calcularBache(Hora hi1,int durp,Hora hi2,int& durb);
```

La función `continuadoDiaAnterior` retorna cuántos minutos del comienzo del día están comprometido con la emisión de un programa que continúa del día anterior. Su prototipo es: 

```cpp
int continuadoDiaAnterior();
```

!!! Se pide:

# Generar el archivo `DESCARTADOS.dat`, con aquellos programas que, por cualquier motivo, fueron  removidos de la propuesta de planificación. La causa será: 1 si el programa se superponía con otro, o 2 si se emitía dentro del horario ATP sin tener la calificación habilitante.<div>

```cpp
struct Descartado
{
   int idPlanif;
   int causa;
};
```

</div>

# Generar el archivo `BACHES.dat` con los intervalos de tiempo que, luego de haber descartado los programas problemáticos, quedaron sin programación. <div>

```cpp
struct Bache
{
   int horaDesde;
   int minDesde;
   int duracion;
};
```

</div>