TITLE: Línea de cajas
TAGS: [[Nivel avanzado]] Problema

Se requiere un programa para optimizar la atención en la línea de cajas de un supermercado. Se dispone del archivo `MOVIMIENTOS.dat`, con un registro por cada persona que entra a la cola de una caja y otro por cada persona que sale.

Los ingresos se representan con un carácter 'E' en el campo `mov`; los egresos con 'S'. El campo `hora` (formato hhmm) indica a qué hora se produjo el ingreso o egreso en la cola de la caja `caja`.

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
# Longitud máxima a la que llegó la cola de cada caja.

Modelo a utilizar: por caja se mantiene una cola FIFO con las horas de ingreso. En 'E' se encola la hora; en 'S' se desencola el primer cliente, cuya espera es `horaSalida - horaEntrada`. Cuando al salir un cliente la cola queda vacía, el tiempo hasta la entrada del próximo cliente es tiempo ocioso.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `MOVIMIENTOS.dat` → 12 movimientos = 144 B (12 B c/u), ordenado por caja

Layout C++ (MinGW, little endian):
- `Mov` = 12 B: caja@0, mov@4, pad 5-7, hora@8

Movimientos por caja:
- Caja 1: E0900 S0910 · E0930 S0940
- Caja 2: E0905 S0915 · E0920 S0935
- Caja 3: E0900 E0905 · S0915 S0925

Resultado:
- Caja 1: esperas 10 y 10 → promedio 10; ocioso 20 (0910→0930); longitud máx 1
- Caja 2: esperas 10 y 15 → promedio 12.5; ocioso 5 (0915→0920); longitud máx 1
- Caja 3: esperas 15 (0900→0915) y 20 (0905→0925) → promedio 17.5; ocioso 0; longitud máx 2
