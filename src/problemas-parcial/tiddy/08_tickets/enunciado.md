TITLE: Emisión de tickets
TAGS: Problema [[Nivel básico]]

Un comercio vende productos clasificados en diferentes rubros. Algunos rubros pueden estar
 en promoción, razón por la cual sus productos se ofrecerán al público por debajo de su valor habitual.

Disponemos de los archivos: `PRODUCTOS.dat`, con la información de cada uno 
de los productos comercializados, y `RUBROS.dat`, que describe los rubros y sus promociones.

```cpp
struct Producto
{
   int idProd;
   char descr[20];
   double precio;
   int idRub;
};
```

```cpp
struct Rubro
{
   int idRub;
   char descr[20];
   double promo;
};
```

Por cada cliente se ingresará su `idCli`, y varios pares {`idProd`, `cant`}. Un `idProd`=0 
indicará el final de la compra del cliente. Un `idCli`=0 indicará la finalización de la operatoria del comercio.

!!! Se pide:

# Por cada venta, emitir un ticket, con el formato que se detalla a continuación, agrupando los productos y sumando sus cantidades, ordenando los ítems alfabéticamente según la descripción de los productos.

|Producto |Precio |c/Dto. |Cant. |Total |
|xxxxxxxxxxxxxxx | 999,99| 999,99| 999| 99999,99|

|Ahorro por rubro|
|Rubro |Total |
|xxxxxxxxxxxxx | 999,99|

# Informar cuáles fueron los 10 productos más demandados, ordenando el listado decrecientemente según la cantidad demandada.

=== RESULTADO ESPERADO (datos provistos) ===

PRODUCTOS.dat (consulta, 7 registros):
  1 DETERGENTE   precio=100   rubro 1
  2 ESPONJA      precio=50    rubro 1
  3 ARROZ        precio=80    rubro 2
  4 FIDEOS       precio=70    rubro 2
  5 LAPTOP       precio=100000 rubro 3
  6 MOUSE        precio=3000  rubro 3
  7 CAFE         precio=120   rubro 2

RUBROS.dat (consulta, 3 registros):
  1 LIMPIEZA     promo=0.10
  2 ALIMENTOS    promo=0.20
  3 ELECTRONICA  promo=0.00

Ejemplo de ingreso por teclado:
  1
  1 3
  3 2
  6 1
  1 2
  0
  2
  7 4
  2 1
  0
  0

P1) Ticket cliente 1 (agrupado y ordenado alfabeticamente):
  DETERGENTE  precio=100  c/dto=90   cant=5  total=450   (ahorro 50)
  ARROZ       precio=80   c/dto=64   cant=2  total=128   (ahorro 32)
  MOUSE       precio=3000 c/dto=3000 cant=1  total=3000  (ahorro 0)
  Total: 3578
  Ahorro por rubro: LIMPIEZA=50, ALIMENTOS=32, ELECTRONICA=0, TOTAL=82

  Ticket cliente 2:
  CAFE        precio=120  c/dto=96   cant=4  total=384   (ahorro 96)
  ESPONJA     precio=50   c/dto=45   cant=1  total=45    (ahorro 5)
  Total: 429
  Ahorro por rubro: ALIMENTOS=96, LIMPIEZA=5, TOTAL=101

P2) Top productos mas demandados (decreciente por cantidad):
  DETERGENTE 5, CAFE 4, ARROZ 2, MOUSE 1, ESPONJA 1
