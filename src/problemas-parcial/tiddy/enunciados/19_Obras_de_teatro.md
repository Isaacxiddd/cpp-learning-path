TITLE: Obras de teatro
TAGS: Problema [[Nivel avanzado]]

Un sitio de Internet vende localidades para las obras de teatro que se encuentran en cartel en las diferentes salas de la ciudad.

Cada sala tiene varios sectores (platea, pulman, preferencial, etcétera), y cada sector admite una determinada capacidad de espectadores. Los sectores de las salas teatrales se numeran desde 1 y son correlativos. 

Contamos con los archivos `OBRAS.dat` y `TEATROS.dat` cuyas estructuras son las siguientes:

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

Contamos también con la función `funcionesProgramadas`, que retorna una colección de funciones según cuál sea el `idObra` que reciba como parámetro.  

```cpp
   List<Funcion> funcionesProgramadas(int idObra);
```

Siendo la estructura `Funcion` la siguiente:

```cpp
struct Funcion
{
   int idFuncion; 
   int diaSem;  // 1=>Lunes, 2=>Martes, ...
   int hora;   // hhmm
};
```

Se acepta que `idFuncion` es un valor único e irrepetible, independientemente de cuál sea la función y la obra de teatro.

Por cada reserva de localidades que un cliente genere a través del sitio Web, el sistema produce registro `Reserva`, cuya estructura es: 

```cpp
struct Reserva
{
   int idCliente;
   int idObra;
   int idFuncion;
   int sector; // sector de la sala; ej: Pullman,Platea...
   int cant;
};
```

Las siguientes funciones de biblioteca nos permitirán interactuar con el sitio Web.

```cpp
 // Retorna la reserva de un cliente
Reserva leerReserva();        

// Indica si quedan mas reservas por procesar
bool continuarOperando(); 
```

La función `leerReserva` es //blockeante//, lo que significa que se quedará esperando hasta que algún cliente haya ingresado los datos necesarios que permitan 
generar una nueva reserva. Por su parte, `continunarOperando` indica si se debe continuar aceptando (o leyendo) nuevas reservas.

La función `capacidadSector` retorna la capacidad de un sector de una sala teatral.

```cpp
int capacidadSector(int idTeatro,int sector);
```

!!! Se pide: 

# Emitir un listado indicando, por cada obra, la cantidad de reservas que quedaron excluídas por falta de capacidad (sólo se aceptarán reservas completas). <div>

|>|Obra de teatro (titulo): xxxxxxxxxxxxxxxx |
|Id. Función |Dia |Hora |Rechazos |
| 99| 9| 99:99| 999|
| 99| 9| 99:99| 999|
| :| :| :| Total: 9999|

</div>


Un sitio de Internet vende localidades para las obras de teatro que se encuentran en cartel en las diferentes salas de la ciudad.

Cada sala tiene varios sectores (platea, pulman, preferencial, etcétera), y cada sector admite una determinada capacidad de espectadores. Los sectores de las salas teatrales se numeran desde 1 y son correlativos. 

Contamos con los archivos `OBRAS.dat` y `TEATROS.dat` cuyas estructuras son las siguientes:

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

Contamos también con la función `funcionesProgramadas`, que retorna una colección de funciones según cuál sea el `idObra` que reciba como parámetro.  

```cpp
   List<Funcion> funcionesProgramadas(int idObra);
```

Siendo la estructura `Funcion` la siguiente:

```cpp
struct Funcion
{
   int idFuncion; 
   int diaSem;  // 1=>Lunes, 2=>Martes, ...
   int hora;   // hhmm
};
```

Se acepta que `idFuncion` es un valor único e irrepetible, independientemente de cuál sea la función y la obra de teatro.

Por cada reserva de localidades que un cliente genere a través del sitio Web, el sistema produce registro `Reserva`, cuya estructura es: 

```cpp
struct Reserva
{
   int idCliente;
   int idObra;
   int idFuncion;
   int sector; // sector de la sala; ej: Pullman,Platea...
   int cant;
};
```

Las siguientes funciones de biblioteca nos permitirán interactuar con el sitio Web.

```cpp
 // Retorna la reserva de un cliente
Reserva leerReserva();        

// Indica si quedan mas reservas por procesar
bool continuarOperando(); 
```

La función `leerReserva` es //blockeante//, lo que significa que se quedará esperando hasta que algún cliente haya ingresado los datos necesarios que permitan 
generar una nueva reserva. Por su parte, `continunarOperando` indica si se debe continuar aceptando (o leyendo) nuevas reservas.

La función `capacidadSector` retorna la capacidad de un sector de una sala teatral.

```cpp
int capacidadSector(int idTeatro,int sector);
```

!!! Se pide: 

# Emitir un listado indicando, por cada obra, la cantidad de reservas que quedaron excluídas por falta de capacidad (sólo se aceptarán reservas completas). <div>

|>|Obra de teatro (titulo): xxxxxxxxxxxxxxxx |
|Id. Función |Dia |Hora |Rechazos |
| 99| 9| 99:99| 999|
| 99| 9| 99:99| 999|
| :| :| :| Total: 9999|

</div>
