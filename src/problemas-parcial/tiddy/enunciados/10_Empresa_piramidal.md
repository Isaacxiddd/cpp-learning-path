TITLE: Empresa piramidal
TAGS: Problema [[Nivel intermedio]]

Una empresa, cuya estructura organizacional es de tipo //piramidal//, requiere un programa para agilizar la liquidación de las comisiones que devienen de las ventas efectuadas por los diferentes socios. En este tipo de organización cada empleado es considerado un socio, y llega a la empresa referido por otro socio, el cual también llegó referido por otro socio, y así sucesivamente.

De cada venta efectuada por un socio, este percibe una comisión bruta del 30%. De este valor deberá comisionar el 30% a su socio referente, que a su vez comisionará el 30% a su referente, y así hasta llegar al socio principal. El socio principal, que no fue referido por ningún otro socio, tiene el valor -1 en el campo `idSocioRef` de su registro en el archivo `SOCIOS.dat`, cuya estructura vemos a continuación:

```cpp
struct Socio
{
   int idSocio;
   char nombre[50];
   int  idSocioRef;  // socio referente
   Fecha fechaIngreso;
   double totalVentasAcumuladas;
   double liquidacionAnterior;
   double liquidacionesAcumuladas;
};
```

Además, disponemos del archivo `VENTAS.dat`, con el detalle de las ventas realizadas.

```cpp
struct Venta
{
   int idSocio;
   int idProducto;
   char observ[100];
   Fecha fecha; 
   double importe;
};
```

!!!Se pide:

# Imprimir un listado, ordenado por `idSocio`, detallando su nombre, fecha de ingreso, liquidación anterior, liquidación actual (la que surge de procesar las ventas), porcentaje de incremento o decremento de la liquidación actual respecto a la anterior, y el total de acumulado desde su ingreso a la empresa.

# Actualice los campos `liquidacionAnterior`, `liquidacionAcumulada` y `totalVentasAcumuladas` del archivo `SOCIOS.dat`. 


Una empresa, cuya estructura organizacional es de tipo //piramidal//, requiere un programa para agilizar la liquidación de las comisiones que devienen de las ventas efectuadas por los diferentes socios. En este tipo de organización cada empleado es considerado un socio, y llega a la empresa referido por otro socio, el cual también llegó referido por otro socio, y así sucesivamente.

De cada venta efectuada por un socio, este percibe una comisión bruta del 30%. De este valor deberá comisionar el 30% a su socio referente, que a su vez comisionará el 30% a su referente, y así hasta llegar al socio principal. El socio principal, que no fue referido por ningún otro socio, tiene el valor -1 en el campo `idSocioRef` de su registro en el archivo `SOCIOS.dat`, cuya estructura vemos a continuación:

```cpp
struct Socio
{
   int idSocio;
   char nombre[50];
   int  idSocioRef;  // socio referente
   Fecha fechaIngreso;
   double totalVentasAcumuladas;
   double liquidacionAnterior;
   double liquidacionesAcumuladas;
};
```

Además, disponemos del archivo `VENTAS.dat`, con el detalle de las ventas realizadas.

```cpp
struct Venta
{
   int idSocio;
   int idProducto;
   char observ[100];
   Fecha fecha; 
   double importe;
};
```

!!!Se pide:

# Imprimir un listado, ordenado por `idSocio`, detallando su nombre, fecha de ingreso, liquidación anterior, liquidación actual (la que surge de procesar las ventas), porcentaje de incremento o decremento de la liquidación actual respecto a la anterior, y el total de acumulado desde su ingreso a la empresa.

# Actualice los campos `liquidacionAnterior`, `liquidacionAcumulada` y `totalVentasAcumuladas` del archivo `SOCIOS.dat`. 
