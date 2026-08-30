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

Cada tipo de infracción prevé un descuento por pronto pago. Es decir, si el infractor se presenta a pagar la multa antes de los `diasPromo` días, se le aplicará un descuento del `dtoPromo` porciento sobre la penalidad. El campo `dtoPromo` contiene el coeficiente por el cual se debe multiplicar la penalidad para obtener el descuento a aplicar.

Se dispone del TAD `Fecha`, cuyas funciones (las que considere necesarias) se deben prototipar pero no desarrollar.

!!! Se pide:

# Por cada tipo de infracción, cantidad de infracciones labradas por día del mes.
# Por cada patente, importe adeudado; según el siguiente listado:

|Patente |Total deuda |Total descuento |Neto a pagar |
|xxxxxxx | 9999.99| 9999.99| 9999.99|
|: | :| :| :|

=== RESULTADO ESPERADO (datos provistos) ===

INFRACCIONES.dat (consulta, 4 registros):
  1 EXCESO DE VELOCIDAD     penalidad=5000 diasPromo=30 dtoPromo=0.20
  2 MAL ESTACIONAMIENTO     penalidad=2000 diasPromo=15 dtoPromo=0.10
  3 SEMAFORO EN ROJO        penalidad=4000 diasPromo=20 dtoPromo=0.15
  4 DOCUMENTACION VENCIDA   penalidad=3000 diasPromo=10 dtoPromo=0.05

ACTAS.dat (novedades, 10 actas):
  (1,'AB123CD',20200315,1015,1)
  (2,'EF456GH',20200315,1400,1)
  (1,'AB123CD',20200402,0930,2)
  (3,'IJ789KL',20200402,1815,2)
  (2,'AB123CD',20200410,1200,3)
  (1,'EF456GH',20200410,1650,3)
  (3,'MN012OP',20200501,0800,4)
  (2,'IJ789KL',20200501,1930,4)
  (1,'AB123CD',20200515,1100,1)
  (3,'EF456GH',20200515,1550,2)

P1) Infracciones por día del mes (día = fecha % 100):
  Infraccion 1: dia 15 -> 2
  Infraccion 2: dia 02 -> 1, dia 15 -> 1
  Infraccion 3: dia 10 -> 2
  Infraccion 4: dia 01 -> 2

P2) Patente | Total deuda | Total descuento | Neto a pagar
  (asumiendo pronto pago: descuento aplicado siempre)
  AB123CD | 16000 | 2800 | 13200
  EF456GH | 11000 | 1800 | 9200
  IJ789KL | 5000 | 350 | 4650
  MN012OP | 3000 | 150 | 2850
