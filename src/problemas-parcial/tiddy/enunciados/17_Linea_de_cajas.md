TITLE: Línea de cajas
TAGS: Problema [[Nivel avanzado]]

Se requiere un programa para optimizar la atención en la línea de cajas de un supermercado. Para esto, ponen a nuestra disposición el archivo `MOVIMIENTOS.dat` (cuya estructura ya veremos), en el cual hay un registro por cada persona que entra en la cola de una caja y otro por cada persona que sale.

Los ingresos se  representan mediante un carácter ‘E’ en el campo `mov`. Los egresos tienen una ‘S’ en dicho campo. El campo `hora` indica a qué hora se produjo el ingreso o egreso en la cola de la caja `caja`.

```cpp
struct Mov
{
   int caja;
   char mov;  // 'E' => Entra, 'S' => Sale
   int hora;  // hhmm
};
```

!!! Se pide: 

Procesando el archivo de movimientos, informar:

# Tiempo promedio de espera por caja.
# Sumatoria del tiempo ocioso por caja.
# Longitud máxima a la llegó la cola de cada caja

Se requiere un programa para optimizar la atención en la línea de cajas de un supermercado. Para esto, ponen a nuestra disposición el archivo `MOVIMIENTOS.dat` (cuya estructura ya veremos), en el cual hay un registro por cada persona que entra en la cola de una caja y otro por cada persona que sale.

Los ingresos se  representan mediante un carácter ‘E’ en el campo `mov`. Los egresos tienen una ‘S’ en dicho campo. El campo `hora` indica a qué hora se produjo el ingreso o egreso en la cola de la caja `caja`.

```cpp
struct Mov
{
   int caja;
   char mov;  // 'E' => Entra, 'S' => Sale
   int hora;  // hhmm
};
```

!!! Se pide: 

Procesando el archivo de movimientos, informar:

# Tiempo promedio de espera por caja.
# Sumatoria del tiempo ocioso por caja.
# Longitud máxima a la llegó la cola de cada caja