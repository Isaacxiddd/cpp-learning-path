TITLE: Compañía de aviación
TAGS: Problema [[Nivel básico]] Solución

\define uniquestate() $:/hide/b$(currentTiddler)$

Una compañía de aviación requiere implementar un programa que, basado en un sistema de acumulación de millas, promueva la fidelización de sus clientes. 

Cada vez que un cliente vuela a través de la compañía recibe una  cantidad de millas acumulables que podrá canjear por vuelos sin costo a diferentes destinos. Cuanto  mayor sea la cantidad de millas acumuladas, más importante serán los destinos o premios por los cuales las podrá canjear. 

La compañía cuenta con los siguientes archivos:  `CIUDADES.dat`, que contiene  la descripción de las ciudades a las que vuela, `VUELOS.dat`, con la información de los vuelos que  conectan  las diferentes ciudades, y `RESERVAS.dat`, con las reservas que realizaron los clientes para volar en los diferentes vuelos.

La estructura de cada uno de estos archivos la vemos a continuación:

```cpp
struct Ciudad
{
   int idCiu;
   char descr[20];
   int millas;
};
```

```cpp
struct Vuelo
{
   int idVue; 
   int cap; 
   int idOri; // idCiu origen
   int idDes; // idCiu origen
};
```

```cpp
struct Reserva
{
   int idCli;
   int idVue; 
   int cant;
};
```

La operatoria es la siguiente: un pasajero que vuela de una ciudad a otra acumula una cantidad de millas equivalente a la diferencia entre las millas establecidas para cada una de esas ciudades, multiplicado por la cantidad de plazas reservadas. Esto será así siempre y cuando su reserva sea aceptada.

Sólo se aceptarán las reservas de aquellos pasajeros que requieran una cantidad de plazas menor o igual a la disponibilidad actual del vuelo en cuestión. De lo contrario la reserva completa será rechazada.

!!! Se pide:

# Informar, para cada ciudad, la cantidad de grupos (familias) que eligieron de destino. 
# Indicar, por cada vuelo, la cantidad de plazas que fueron rechazadas, indicando también si el vuelo saldrá completo o incompleto.
# Mostrar, por cada cliente, el total de millas que acumuló. 

<!-- BOTON SOLUCION -->
<$reveal type="nomatch" state=<<uniquestate>> text="show"><$button set=<<uniquestate>> setTo="show">Ver solución propuesta</$button></$reveal>
<$reveal type="match" state=<<uniquestate>> text="show"><$button set=<<uniquestate>> setTo="hide">Ocultar solución</$button> <div>

<!-- SOLUCION -->
!!! Estrategia de solución

Subimos a memoria los archivos de consultas, que son `CIUDADES.dat` y `VUELOS.dat`, y recorremos el archivo de novedades: `RESERVAS.dat`.

Necesitamos un contador por cada ciudad, para contar cuántos grupos la escogieron como destino. Dado que las ciudades ya las tenemos en memoria, en una colección, lo que haremos será //wrappear// `Ciudad`, para agregarle a cada ciudad el contador que necesitamos.

```cpp
struct RCiudad
{
   Ciudad c;
   int cont;
};
```

Si estamos trabajando con el TAD `Coll`, la colección de ciudades será:

```cpp
Coll<RCiudad> cCiu;
```

Si ya conocemos colecciones más avanzadas podríamos optar por una estructura de datos más funcional: un //map//, donde la //key// será el `idCiu`, y asociado a este un `RCiudad`.

```cpp
Map<int,RCiudad> cCiu;
```

Para determinar (por cada vuelo) cuántas plazas fueron rechazadas e indicar si el vuelo salió completo o no, necesitaremos mantener dos acumuladores: uno de plazas rechazadas y otro de plazas aceptadas. De este modo, si luego de procesar las reservas la cantidad de plazas aceptadas es igual a la capacidad del vuelo será porque este salió completo. 

```cpp
struct RVuelo
{
   Vuelo v;
   int cpr; // cantidad de plazas rechazadas
   int cpa; // cantidad de plazas aceptadas
};
```

Subiremos los vuelos a un `Coll` o a un `Map` dependiendo de en qué nivel del curso nos encontremos.

```cpp
Coll<Ruelo> cVue;
```

o bien:

```cpp
Map<int,RVuelo> cVue;
```

Finalmente, no disponemos del archivo de clientes de la compañia. El único dato que tenemos de cada uno es su //id//, que forma parte de la estructura `Reserva`. Para indicar cuántas millas le asignamos a cada cliente necesitaremos mantener un acumulador de millas por cliente, los cuales podremos descubrir a medida que procesamos y aprobamos cada reserva. Esto implica crear una estructura `RCliente` y una colección. 

```cpp
struct RCliente
{
   int idCli; 
   int millas; // cantidad de millas
};
```

Si usamos `Coll`:

```cpp
Coll<RCliente> cCli;
```

Si usamos `Map` la estructura `RCliente` no será estrictamente necesaria, pues podemos aprovechar el //value// del //map// para implementar el acumulador de millas:


```cpp
Map<int,int> cCli;
```

Sin embargo, un `Map<int,RCliente>` hará que nuestra solución sea más extensible, pues nos permitirá guardar cualquier otro dato asociado al cliente en caso de que sea requerido más adelante.

```cpp
Map<int,RCliente> cCli;
```

Retomemos la estrategia de solución: subimos a memoria los archivos de consulta y recorremos el de novedades. Por cada reserva, buscamos el vuelo y luego las ciudades que este vincula. A la ciudad de destino le incrementamos el contador de grupos que la escogieron como destino (punto 1). 

Luego determinamos si la reserva puede ser aprobada. Para esto verificamos si la cantidad de plazas aceptadas del vuelo sumado a la cantidad de plazas solicitadas en la reserva no superan su capacidad. En tal caso la reserva será aprobada. De lo contrario será rechazada. Dependiendo de esto aumentamos el acumulador que corresponda (`cpa` o `cpr`). 

Finalmente, si la reserva fue aprobada calculamos cuántas millas le corresponden al cliente. Hacemos descubrimiento en la colección de clientes y le acumulamos la cantidad de millas.

Los listados solicitados los emitimos recorriendo las colecciones `cCiu` (punto 1), `cVue` (punto 2) y `cCli` (punto 3).

</div></$reveal>





\define uniquestate() $:/hide/b$(currentTiddler)$

Una compañía de aviación requiere implementar un programa que, basado en un sistema de acumulación de millas, promueva la fidelización de sus clientes. 

Cada vez que un cliente vuela a través de la compañía recibe una  cantidad de millas acumulables que podrá canjear por vuelos sin costo a diferentes destinos. Cuanto  mayor sea la cantidad de millas acumuladas, más importante serán los destinos o premios por los cuales las podrá canjear. 

La compañía cuenta con los siguientes archivos:  `CIUDADES.dat`, que contiene  la descripción de las ciudades a las que vuela, `VUELOS.dat`, con la información de los vuelos que  conectan  las diferentes ciudades, y `RESERVAS.dat`, con las reservas que realizaron los clientes para volar en los diferentes vuelos.

La estructura de cada uno de estos archivos la vemos a continuación:

```cpp
struct Ciudad
{
   int idCiu;
   char descr[20];
   int millas;
};
```

```cpp
struct Vuelo
{
   int idVue; 
   int cap; 
   int idOri; // idCiu origen
   int idDes; // idCiu origen
};
```

```cpp
struct Reserva
{
   int idCli;
   int idVue; 
   int cant;
};
```

La operatoria es la siguiente: un pasajero que vuela de una ciudad a otra acumula una cantidad de millas equivalente a la diferencia entre las millas establecidas para cada una de esas ciudades, multiplicado por la cantidad de plazas reservadas. Esto será así siempre y cuando su reserva sea aceptada.

Sólo se aceptarán las reservas de aquellos pasajeros que requieran una cantidad de plazas menor o igual a la disponibilidad actual del vuelo en cuestión. De lo contrario la reserva completa será rechazada.

!!! Se pide:

# Informar, para cada ciudad, la cantidad de grupos (familias) que eligieron de destino. 
# Indicar, por cada vuelo, la cantidad de plazas que fueron rechazadas, indicando también si el vuelo saldrá completo o incompleto.
# Mostrar, por cada cliente, el total de millas que acumuló. 

<!-- BOTON SOLUCION -->
<$reveal type="nomatch" state=<<uniquestate>> text="show"><$button set=<<uniquestate>> setTo="show">Ver solución propuesta</$button></$reveal>
<$reveal type="match" state=<<uniquestate>> text="show"><$button set=<<uniquestate>> setTo="hide">Ocultar solución</$button> <div>

<!-- SOLUCION -->
!!! Estrategia de solución

Subimos a memoria los archivos de consultas, que son `CIUDADES.dat` y `VUELOS.dat`, y recorremos el archivo de novedades: `RESERVAS.dat`.

Necesitamos un contador por cada ciudad, para contar cuántos grupos la escogieron como destino. Dado que las ciudades ya las tenemos en memoria, en una colección, lo que haremos será //wrappear// `Ciudad`, para agregarle a cada ciudad el contador que necesitamos.

```cpp
struct RCiudad
{
   Ciudad c;
   int cont;
};
```

Si estamos trabajando con el TAD `Coll`, la colección de ciudades será:

```cpp
Coll<RCiudad> cCiu;
```

Si ya conocemos colecciones más avanzadas podríamos optar por una estructura de datos más funcional: un //map//, donde la //key// será el `idCiu`, y asociado a este un `RCiudad`.

```cpp
Map<int,RCiudad> cCiu;
```

Para determinar (por cada vuelo) cuántas plazas fueron rechazadas e indicar si el vuelo salió completo o no, necesitaremos mantener dos acumuladores: uno de plazas rechazadas y otro de plazas aceptadas. De este modo, si luego de procesar las reservas la cantidad de plazas aceptadas es igual a la capacidad del vuelo será porque este salió completo. 

```cpp
struct RVuelo
{
   Vuelo v;
   int cpr; // cantidad de plazas rechazadas
   int cpa; // cantidad de plazas aceptadas
};
```

Subiremos los vuelos a un `Coll` o a un `Map` dependiendo de en qué nivel del curso nos encontremos.

```cpp
Coll<Ruelo> cVue;
```

o bien:

```cpp
Map<int,RVuelo> cVue;
```

Finalmente, no disponemos del archivo de clientes de la compañia. El único dato que tenemos de cada uno es su //id//, que forma parte de la estructura `Reserva`. Para indicar cuántas millas le asignamos a cada cliente necesitaremos mantener un acumulador de millas por cliente, los cuales podremos descubrir a medida que procesamos y aprobamos cada reserva. Esto implica crear una estructura `RCliente` y una colección. 

```cpp
struct RCliente
{
   int idCli; 
   int millas; // cantidad de millas
};
```

Si usamos `Coll`:

```cpp
Coll<RCliente> cCli;
```

Si usamos `Map` la estructura `RCliente` no será estrictamente necesaria, pues podemos aprovechar el //value// del //map// para implementar el acumulador de millas:


```cpp
Map<int,int> cCli;
```

Sin embargo, un `Map<int,RCliente>` hará que nuestra solución sea más extensible, pues nos permitirá guardar cualquier otro dato asociado al cliente en caso de que sea requerido más adelante.

```cpp
Map<int,RCliente> cCli;
```

Retomemos la estrategia de solución: subimos a memoria los archivos de consulta y recorremos el de novedades. Por cada reserva, buscamos el vuelo y luego las ciudades que este vincula. A la ciudad de destino le incrementamos el contador de grupos que la escogieron como destino (punto 1). 

Luego determinamos si la reserva puede ser aprobada. Para esto verificamos si la cantidad de plazas aceptadas del vuelo sumado a la cantidad de plazas solicitadas en la reserva no superan su capacidad. En tal caso la reserva será aprobada. De lo contrario será rechazada. Dependiendo de esto aumentamos el acumulador que corresponda (`cpa` o `cpr`). 

Finalmente, si la reserva fue aprobada calculamos cuántas millas le corresponden al cliente. Hacemos descubrimiento en la colección de clientes y le acumulamos la cantidad de millas.

Los listados solicitados los emitimos recorriendo las colecciones `cCiu` (punto 1), `cVue` (punto 2) y `cCli` (punto 3).

</div></$reveal>



