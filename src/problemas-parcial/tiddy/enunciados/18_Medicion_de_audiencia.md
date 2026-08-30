TITLE: Medición de audiencia
TAGS: Problema [[Nivel avanzado]]

La empresa que se encarga de mediar el //ranking// de los programas de  televisión dispone del archivo  `MUESTRAS.dat`, con los datos del encendido, //zapping// y pagado que registraron los monitores de audiencia, que se encuentran distribuidos en puntos estratégicos de la ciudad. Este archivo no tiene orden, y por su tamaño puede ser administrarlo en memoria.

```cpp
struct Muestra
{
   int idMonitor;
   int hora;
   int min;
   char accion; 
   int canal;
}
```

El campo `accion` establece qué acción se ejecutó a la hora/minuto indicada por los campos `hora` y `min`. Esta acción puede ser:

* ‘E’ – Enciende
* ‘C’ – Cambia de canal
* ‘A’ – Apaga

Las acciones ‘E’ y ‘A’ no involucran ningún canal, por lo que el campo `canal` no trae ninguna información válida en tales casos. La acción ‘C’ se produce cada vez que el usuario abandona un canal, habiéndolo dejado fijo por, al menos, 1 minuto.

Si luego de ver un determinado canal (durante más de 1 minuto) el usuario apaga el televisor, el monitor generará, primero, un registro con `accion` = ‘C’, cuya hora/minuto coincidirán con la hora/minuto del evento de apagado. Algo similar sucederá si la TV permanece encendida, en un mismo canal, de 
un día para el otro. Al llegar la hora 23:59:59 se generará un registro con `accion` = ‘C’.  Luego se generará un evento de apagado y otro de encendido.
 
Se garantiza la consistencia de los datos. Es decir: para un monitor equis, existirá un registro con `accion` = ‘E’. Luego habrá uno o varios registros ‘C’, y finalmente un registro ‘A’. Esta secuencia podría repetirse varias veces, pues los televidentes miran TV muchas veces al día.

!!! Se pide: 

# Grabar el grabar el archivo `MINAMIN.dat` (Minuto a Minuto), con la estructura de registro que veremos enseguida, ordenado por `canal` y `min`. Describiendo, por cada canal, cuántos monitores lo sitonizaron durante cada minuto del día. El campo `min` indica el minuto del día, cuyo valor estará comprendido entre 0 y 1439.  <div>

```cpp
struct MinAMin
{
   int canal;
   int min; // min del dia (de 0 a 1439)
   int cant; 
};
```
</div>

La empresa que se encarga de mediar el //ranking// de los programas de  televisión dispone del archivo  `MUESTRAS.dat`, con los datos del encendido, //zapping// y pagado que registraron los monitores de audiencia, que se encuentran distribuidos en puntos estratégicos de la ciudad. Este archivo no tiene orden, y por su tamaño puede ser administrarlo en memoria.

```cpp
struct Muestra
{
   int idMonitor;
   int hora;
   int min;
   char accion; 
   int canal;
}
```

El campo `accion` establece qué acción se ejecutó a la hora/minuto indicada por los campos `hora` y `min`. Esta acción puede ser:

* ‘E’ – Enciende
* ‘C’ – Cambia de canal
* ‘A’ – Apaga

Las acciones ‘E’ y ‘A’ no involucran ningún canal, por lo que el campo `canal` no trae ninguna información válida en tales casos. La acción ‘C’ se produce cada vez que el usuario abandona un canal, habiéndolo dejado fijo por, al menos, 1 minuto.

Si luego de ver un determinado canal (durante más de 1 minuto) el usuario apaga el televisor, el monitor generará, primero, un registro con `accion` = ‘C’, cuya hora/minuto coincidirán con la hora/minuto del evento de apagado. Algo similar sucederá si la TV permanece encendida, en un mismo canal, de 
un día para el otro. Al llegar la hora 23:59:59 se generará un registro con `accion` = ‘C’.  Luego se generará un evento de apagado y otro de encendido.
 
Se garantiza la consistencia de los datos. Es decir: para un monitor equis, existirá un registro con `accion` = ‘E’. Luego habrá uno o varios registros ‘C’, y finalmente un registro ‘A’. Esta secuencia podría repetirse varias veces, pues los televidentes miran TV muchas veces al día.

!!! Se pide: 

# Grabar el grabar el archivo `MINAMIN.dat` (Minuto a Minuto), con la estructura de registro que veremos enseguida, ordenado por `canal` y `min`. Describiendo, por cada canal, cuántos monitores lo sitonizaron durante cada minuto del día. El campo `min` indica el minuto del día, cuyo valor estará comprendido entre 0 y 1439.  <div>

```cpp
struct MinAMin
{
   int canal;
   int min; // min del dia (de 0 a 1439)
   int cant; 
};
```
</div>