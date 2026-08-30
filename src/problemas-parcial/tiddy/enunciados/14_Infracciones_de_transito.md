TITLE: Infracciones de tránsito
TAGS: Problema [[Nivel básico]]

Una municipalidad requiere procesar las actas de infracción labradas por sus inspectores de tránsito. Para esto cuenta con los siguientes archivos: `ACTAS.dat`, con el detalle de dichas actas, e `INFRACCIONES.dat`, con los diferentes tipos de infracción y sus respectivas penalidades. 

```cpp
struct Acta
{
   int idInspector;
   char pat[10];
   int fecha; // aaaammdd
   int hora;  // hhmm
   int idInfraccion;
};
```

```cpp
struct Infraccion
{
   int idInfraccion;
   char descr[100];
   double penalidad; // $
   int diasPromo;
   double dtoPromo; // ej: 0.20
};
```

Cada tipo de infracción prevé un descuento por pronto pago. Es decir, si el infractor se presenta a pagar la multa antes de los `diasPromo` días, se le aplicará un descuento del `dtoPromo` porciento sobre la  penalidad. El campo `dtoPromo` contiene el coeficiente por el cual se debe multiplicar la penalidad para obtener el descuento a aplicar.

Se dispone del TAD `Fecha`, cuyas funciones (las que considere necesarias) se deben prototipar pero no desarrollar.

!!! Se pide:

# Por cada tipo de infracción, cantidad de infracciones labradas por día del mes.
# Por cada patente, importe adeudado; según el siguiente listado: <div>

|Patente |Total deuda |Total descuento |Neto a pagar |
|xxxxxxx | 9999.99| 9999.99| 9999.99|
|: | :| :| :|

</div>


Una municipalidad requiere procesar las actas de infracción labradas por sus inspectores de tránsito. Para esto cuenta con los siguientes archivos: `ACTAS.dat`, con el detalle de dichas actas, e `INFRACCIONES.dat`, con los diferentes tipos de infracción y sus respectivas penalidades. 

```cpp
struct Acta
{
   int idInspector;
   char pat[10];
   int fecha; // aaaammdd
   int hora;  // hhmm
   int idInfraccion;
};
```

```cpp
struct Infraccion
{
   int idInfraccion;
   char descr[100];
   double penalidad; // $
   int diasPromo;
   double dtoPromo; // ej: 0.20
};
```

Cada tipo de infracción prevé un descuento por pronto pago. Es decir, si el infractor se presenta a pagar la multa antes de los `diasPromo` días, se le aplicará un descuento del `dtoPromo` porciento sobre la  penalidad. El campo `dtoPromo` contiene el coeficiente por el cual se debe multiplicar la penalidad para obtener el descuento a aplicar.

Se dispone del TAD `Fecha`, cuyas funciones (las que considere necesarias) se deben prototipar pero no desarrollar.

!!! Se pide:

# Por cada tipo de infracción, cantidad de infracciones labradas por día del mes.
# Por cada patente, importe adeudado; según el siguiente listado: <div>

|Patente |Total deuda |Total descuento |Neto a pagar |
|xxxxxxx | 9999.99| 9999.99| 9999.99|
|: | :| :| :|

</div>
