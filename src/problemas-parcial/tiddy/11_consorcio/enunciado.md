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

# Emitir un listado por cada consorcio, con el detalle que se indica más abajo, ordenado decrecientemente por la cantidad de metros porcentuales que cada departamento ocupa dentro del piso, y detallando también cómo se distribuye el total de los gastos entre las diferentes categorías.

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

# Contando con el archivo `DISTRIBUCION.dat`, cuya estructura de registro vemos a continuación, sin orden y con una cantidad de registros acotada que permite gestionarlo en memoria:

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

!!! Variantes

Este problema debe resolverse teniendo en cuenta las siguientes variantes:

* Situación (A) - Considere que `GASTOS.dat` está ordenado por `idCons`.
* Situación (B) - Considere que `GASTOS.dat` no está ordenado.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `CONSORCIOS.dat`  → 2 consorcios = 128 B (64 B c/u)
- `GASTOS.dat`      → 6 gastos = 240 B (40 B c/u), ordenado por idCons
- `DISTRIBUCION.dat`→ 5 registros = 80 B (16 B c/u), sin orden

Layout C++ (MinGW, little endian):
- `Gasto`       = 40 B: idCons@0, fecha@4, importe@8, categoria@16, pad 36-39
- `Consorcio`   = 64 B: idCons@0, direccion@4, cantPisos@54, dtosPorPiso@58, pad 62-63
- `Distribucion`= 16 B: idCons@0, tipoDto@4, mtsPorc@8

Datos:
- Consorcio 1: AV CORDOBA 1234, 3 pisos × 2 deptos/piso; distribución tipo 1 = 55%, tipo 2 = 45%
- Consorcio 2: RIVADAVIA 5678, 2 pisos × 3 deptos/piso; distribución tipo 1 = 40%, tipo 2 = 35%, tipo 3 = 25%
- Gastos consorcio 1: LIMPIEZA 1000+500=1500, SERVICIOS 500, SUELDOS 800 → total 2800
- Gastos consorcio 2: LIMPIEZA 200, SERVICIOS 600 → total 800

Salida esperada (consorcio 1): depto 1 paga 2800×0,55 = 1540, depto 2 paga 2800×0,45 = 1260.
