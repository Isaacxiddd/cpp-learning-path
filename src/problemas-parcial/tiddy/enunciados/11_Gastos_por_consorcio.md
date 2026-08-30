TITLE: Gastos por consorcio
TAGS: Problema [[Nivel intermedio]]

Un estudio que administra consorcios requiere un programa para que lo asista durante el proceso de liquidación de expensas. 

Disponemos de los archivos `GASTOS.dat` y `CONSORCIOS.dat`, cuyas estructuras son respectivamente las siguientes:

```cpp
struct Gasto
{
   int idCons; // ver situaciones A y B
   int fecha;  // aaaammdd
   double importe;
   char categoria[20]; // ej. Limpieza, Sueldos, Servicios...
};
```

```cpp
struct Consorcio
{
   int idCons;
   char direccion[50];
   int cantPisos;
   int dtosPorPiso;
};
```

En todos los casos, los departamentos de los consorcios se identifican con dígitos numéricos (1, 2, 3, etcétera), y todos los pisos de un consorcio tienen la misma cantidad de departamentos, distribuidos exactamente del mismo modo.

Disponemos de la función `mtsPorcentuales`, que dado un consorcio y un tipo de departamento, retorna la proporción que los departamentos de dicho tipo ocupan dentro de los pisos del consorcio. Su prototipo es el siguiente:

```cpp
double mtsPorcencuales(int idCons,int tipoDepto);
```

Por ejemplo, si un tipo de departamento de un determinado consorcio ocupa el 28% del piso, la función retornará 0,28.

!!! Se pide: 

# Emitir un listado por cada consorcio, con el detalle que se indica más abajo, ordenado decrecientemente por la cantidad de metros porcentuales que cada departamento ocupa dentro del piso, y detallando también cómo se distribuye el total de los gastos entre las diferentes categorías. <div>

|>|>|Consorcio calle: xxxxxxxxxxxxx, Total gastos: $99999.99|
|Depto.|M2. (%)|Total a pagar ($)|
| 3| 33| 999.99|
| 1| 30| 999.99|
| 2| 25| 999.99|
| :| :| :|

|Categoría | Gastos ($)|
|Limpieza | 999.99|
|Servicios | 999.99|
|Sueldos | 999.99|
| Total:| $99999.99|

</div>

# Contando con el archivo `DISTRIBUCION.dat`, cuya estructura de registro vemos a continuación, sin orden y con una cantidad de registros acotada que permite gestionarlo en memoria: <div>

```cpp
struct Distribucion
{
   int idCons;
   int tipoDto;
   double mtsPorc;
};
```

Se pide desarrollar el TAD `Distrib` y utilizarlo para reemplazar la función `mtsPorcentuales` utilizada durante el desarrollo anterior. La API del TAD debe ser la siguiente: 







```cpp
// Funcion de inicializacion
Distrib distrib();

// Retorna el porcentaje que ocupan los departamentos
// de un determinado tipo dentro del consorcio
double distribMetrosPorcentuales(Distrib d,int idCons,int tipoDto);
```

</div>

!!! Variantes

Este problema debe resolverse teniendo en cuenta las siguientes variantes:

* Situación (A) - Considere que `GASTOS.dat` está ordenado por `idCons`.
* Situación (B) - Considere que `GASTOS.dat` no está ordenado.



Un estudio que administra consorcios requiere un programa para que lo asista durante el proceso de liquidación de expensas. 

Disponemos de los archivos `GASTOS.dat` y `CONSORCIOS.dat`, cuyas estructuras son respectivamente las siguientes:

```cpp
struct Gasto
{
   int idCons; // ver situaciones A y B
   int fecha;  // aaaammdd
   double importe;
   char categoria[20]; // ej. Limpieza, Sueldos, Servicios...
};
```

```cpp
struct Consorcio
{
   int idCons;
   char direccion[50];
   int cantPisos;
   int dtosPorPiso;
};
```

En todos los casos, los departamentos de los consorcios se identifican con dígitos numéricos (1, 2, 3, etcétera), y todos los pisos de un consorcio tienen la misma cantidad de departamentos, distribuidos exactamente del mismo modo.

Disponemos de la función `mtsPorcentuales`, que dado un consorcio y un tipo de departamento, retorna la proporción que los departamentos de dicho tipo ocupan dentro de los pisos del consorcio. Su prototipo es el siguiente:

```cpp
double mtsPorcencuales(int idCons,int tipoDepto);
```

Por ejemplo, si un tipo de departamento de un determinado consorcio ocupa el 28% del piso, la función retornará 0,28.

!!! Se pide: 

# Emitir un listado por cada consorcio, con el detalle que se indica más abajo, ordenado decrecientemente por la cantidad de metros porcentuales que cada departamento ocupa dentro del piso, y detallando también cómo se distribuye el total de los gastos entre las diferentes categorías. <div>

|>|>|Consorcio calle: xxxxxxxxxxxxx, Total gastos: $99999.99|
|Depto.|M2. (%)|Total a pagar ($)|
| 3| 33| 999.99|
| 1| 30| 999.99|
| 2| 25| 999.99|
| :| :| :|

|Categoría | Gastos ($)|
|Limpieza | 999.99|
|Servicios | 999.99|
|Sueldos | 999.99|
| Total:| $99999.99|

</div>

# Contando con el archivo `DISTRIBUCION.dat`, cuya estructura de registro vemos a continuación, sin orden y con una cantidad de registros acotada que permite gestionarlo en memoria: <div>

```cpp
struct Distribucion
{
   int idCons;
   int tipoDto;
   double mtsPorc;
};
```

Se pide desarrollar el TAD `Distrib` y utilizarlo para reemplazar la función `mtsPorcentuales` utilizada durante el desarrollo anterior. La API del TAD debe ser la siguiente: 







```cpp
// Funcion de inicializacion
Distrib distrib();

// Retorna el porcentaje que ocupan los departamentos
// de un determinado tipo dentro del consorcio
double distribMetrosPorcentuales(Distrib d,int idCons,int tipoDto);
```

</div>

!!! Variantes

Este problema debe resolverse teniendo en cuenta las siguientes variantes:

* Situación (A) - Considere que `GASTOS.dat` está ordenado por `idCons`.
* Situación (B) - Considere que `GASTOS.dat` no está ordenado.

