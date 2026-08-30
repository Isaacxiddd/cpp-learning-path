TITLE: Buques y containers
TAGS: Problema [[Nivel intermedio]] Solución

\define uniquestate() $:/hide/b$(currentTiddler)$

El Puerto de la Ciudad Autónoma de Buenos Aires requiere un sistema para gestionar la carga o descarga de los contenedores transportados por en los buques cargueros. Los archivos `BUQUES.dat` y `CONTAINERS.dat`, cuyas estructuras se detallan más abajo, contienen la información sobre la fecha de llegada o salida de cada barco, y las dimensiones de los contenedores transportados. 

La cantidad de registros estos archivos podrían tener posibilita gestionarlos en memoria.

```cpp
struct Buque
{
   int idBuque;
   char nombre[50];
   int darsena;
   int grua; 
   int cantContainers;
   Fecha fecha; // llegada o salida
   int cteFlotacion;
   char oriODest[100];
};
```

```cpp
struct Container
{
   int idContainer;
   int peso;
   int longitud; 
   int idBuque;
};
```

Los buques pueden haber llegado o estar próximos a partir.  Según cuál sea el caso, el registro que describe al buque (dentro del archivo `BUQUES.dat`) tendrá una `fecha` anterior o posterior a la fecha actual. 

Disponemos del TAD `Fecha` cuyas funciones podemos diseñar y utilizar sin necesidad de implementarlas.

También disponemos de la función `estable`, cuyo prototipo vemos a continuación, permite determinar si el buque permanecerá estabilizado luego de cargar o descargar un //container//.

```cpp
bool estable(int peso,int longitud,int cteFlotacion);
```

!!! Se pide:

# Emitir un listado, con el diseño que se describe más abajo, indicando en qué orden se deben cargar o descargar (según sea el caso) los //containers// de cada buque para que este se mantenga estable. Se garantiza que siempre existirá un orden adecuado para cargar o descargar todos los contenedores. <div>

|>|>|>|Listado de cargas y descargas del día: 99-99-9999 |
|>|>|>|Id. Buque: 9999, [Carga o Descarga], Grúa: 999 |
|>|>|>|Nombre: xxxxxxxxxxxxx, Dársena: 999 |
|>|>|>|Fecha: 99-99-9999 de [Salida o Llegada], Cant. containers: 9999 |
|Orden |Id. Container |Longitud |Peso |
| 1| 99999| 9999| 999|
| 2| 99999| 9999| 999|
| 3| 99999| 9999| 999|
| :| :| :| :|
|>|>|>| Peso total transportado: 9999|

</div>

# Si ambos archivos estuvieran ordenados por `idBuque`, ¿qué alternativas surgirían respecto a la solución desarrollada para el punto anterior?


<!--
<$reveal type="nomatch" state=<<uniquestate>> text="show">
   <$button set=<<uniquestate>> setTo="show">Ver solución propuesta</$button>
</$reveal>
-->

<$reveal type="match" state=<<uniquestate>> text="show">
    <$button set=<<uniquestate>> setTo="hide">Ocultar solución</$button> <div>

!!! Estrategia de solución

(Solución: //Schneideroff// - //Kim//)

Subimos `CONTAINERS.dat` a un `Map<int,Queue<Container>>`, encolando a cada //container// en una cola asociada al //id// del buque que lo transporta. `idBuque` será la //key// del //map//. 

```cpp
Map<int,Queue<Container>> m = subirContainers();
```

Luego recorremos `BUQUES.dat`, y por cada buque imprimimos el listado de carga o descarga solicitado. Los datos necesarios para generar el encabezado los tenemos disponibles en el registro `Buque` que acabamos de leer. Los datos de los //containers// los tenemos en el //map//, en la cola asociada al `idBuque`.

Dado que los //containers// no necesariamente fueron encolados en el orden correcto (que garantiza la estabilidad del buque), el siguiente algoritmo nos permitirá invocar a la función `estable`  pasándole como argumentos el peso y longitud de cada uno de los //containers//, tantas veces como sea necesario hasta que todos hayan sido mostrados en el listado, en el orden adecuado.

Sean `m` el //map// y `b` el buque que acabamos de leer desde el archivo `BUQUES.dat`, entonces:

```cpp
int orden = 1;
Queue* q = mapGet<int,Queue<Container>>(m,b.idBuque);
while( !queueIsEmpty<int,Queue<Container>>(*q) )
{
   Container c = queueDequeue<Container>(*q)
   if( estable(c.peso,c.longitud,b.cteFlotacion) )
   {
      // imprimo el orden y los datos del container 
      orden++;
   }
   else
   {
      queueEnqueue<int,Queue<Container>>(*q,c);
   }
}
```

Si ambos archivos estuviesen ordenados por `idBuque`, podríamos recorrerlos a la par, con la técnica de //apareo de archivos//, combinándola con un corte de control sobre el archivo de //containers//, //bufferizando// en una cola todos los //containers// del mismo buque. Luego, por cada buque, mostramos el encabezado y aplicamos el algoritmo anterior para imprimir, en el orden requerido, todos sus //containers//.

Esta solución insume menos memoria que la anterior, pues utiliza una única cola para encolar los //containers// de cada uno de los buques.

</div></$reveal>

\define uniquestate() $:/hide/b$(currentTiddler)$

El Puerto de la Ciudad Autónoma de Buenos Aires requiere un sistema para gestionar la carga o descarga de los contenedores transportados por en los buques cargueros. Los archivos `BUQUES.dat` y `CONTAINERS.dat`, cuyas estructuras se detallan más abajo, contienen la información sobre la fecha de llegada o salida de cada barco, y las dimensiones de los contenedores transportados. 

La cantidad de registros estos archivos podrían tener posibilita gestionarlos en memoria.

```cpp
struct Buque
{
   int idBuque;
   char nombre[50];
   int darsena;
   int grua; 
   int cantContainers;
   Fecha fecha; // llegada o salida
   int cteFlotacion;
   char oriODest[100];
};
```

```cpp
struct Container
{
   int idContainer;
   int peso;
   int longitud; 
   int idBuque;
};
```

Los buques pueden haber llegado o estar próximos a partir.  Según cuál sea el caso, el registro que describe al buque (dentro del archivo `BUQUES.dat`) tendrá una `fecha` anterior o posterior a la fecha actual. 

Disponemos del TAD `Fecha` cuyas funciones podemos diseñar y utilizar sin necesidad de implementarlas.

También disponemos de la función `estable`, cuyo prototipo vemos a continuación, permite determinar si el buque permanecerá estabilizado luego de cargar o descargar un //container//.

```cpp
bool estable(int peso,int longitud,int cteFlotacion);
```

!!! Se pide:

# Emitir un listado, con el diseño que se describe más abajo, indicando en qué orden se deben cargar o descargar (según sea el caso) los //containers// de cada buque para que este se mantenga estable. Se garantiza que siempre existirá un orden adecuado para cargar o descargar todos los contenedores. <div>

|>|>|>|Listado de cargas y descargas del día: 99-99-9999 |
|>|>|>|Id. Buque: 9999, [Carga o Descarga], Grúa: 999 |
|>|>|>|Nombre: xxxxxxxxxxxxx, Dársena: 999 |
|>|>|>|Fecha: 99-99-9999 de [Salida o Llegada], Cant. containers: 9999 |
|Orden |Id. Container |Longitud |Peso |
| 1| 99999| 9999| 999|
| 2| 99999| 9999| 999|
| 3| 99999| 9999| 999|
| :| :| :| :|
|>|>|>| Peso total transportado: 9999|

</div>

# Si ambos archivos estuvieran ordenados por `idBuque`, ¿qué alternativas surgirían respecto a la solución desarrollada para el punto anterior?


<!--
<$reveal type="nomatch" state=<<uniquestate>> text="show">
   <$button set=<<uniquestate>> setTo="show">Ver solución propuesta</$button>
</$reveal>
-->

<$reveal type="match" state=<<uniquestate>> text="show">
    <$button set=<<uniquestate>> setTo="hide">Ocultar solución</$button> <div>

!!! Estrategia de solución

(Solución: //Schneideroff// - //Kim//)

Subimos `CONTAINERS.dat` a un `Map<int,Queue<Container>>`, encolando a cada //container// en una cola asociada al //id// del buque que lo transporta. `idBuque` será la //key// del //map//. 

```cpp
Map<int,Queue<Container>> m = subirContainers();
```

Luego recorremos `BUQUES.dat`, y por cada buque imprimimos el listado de carga o descarga solicitado. Los datos necesarios para generar el encabezado los tenemos disponibles en el registro `Buque` que acabamos de leer. Los datos de los //containers// los tenemos en el //map//, en la cola asociada al `idBuque`.

Dado que los //containers// no necesariamente fueron encolados en el orden correcto (que garantiza la estabilidad del buque), el siguiente algoritmo nos permitirá invocar a la función `estable`  pasándole como argumentos el peso y longitud de cada uno de los //containers//, tantas veces como sea necesario hasta que todos hayan sido mostrados en el listado, en el orden adecuado.

Sean `m` el //map// y `b` el buque que acabamos de leer desde el archivo `BUQUES.dat`, entonces:

```cpp
int orden = 1;
Queue* q = mapGet<int,Queue<Container>>(m,b.idBuque);
while( !queueIsEmpty<int,Queue<Container>>(*q) )
{
   Container c = queueDequeue<Container>(*q)
   if( estable(c.peso,c.longitud,b.cteFlotacion) )
   {
      // imprimo el orden y los datos del container 
      orden++;
   }
   else
   {
      queueEnqueue<int,Queue<Container>>(*q,c);
   }
}
```

Si ambos archivos estuviesen ordenados por `idBuque`, podríamos recorrerlos a la par, con la técnica de //apareo de archivos//, combinándola con un corte de control sobre el archivo de //containers//, //bufferizando// en una cola todos los //containers// del mismo buque. Luego, por cada buque, mostramos el encabezado y aplicamos el algoritmo anterior para imprimir, en el orden requerido, todos sus //containers//.

Esta solución insume menos memoria que la anterior, pues utiliza una única cola para encolar los //containers// de cada uno de los buques.

</div></$reveal>