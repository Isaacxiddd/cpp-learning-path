TITLE: Optimización de colas
TAGS: [[Nivel avanzado]] Problema

Se requiere un programa para encontrar una relación óptima entre la cantidad de cajas habilitadas en un supermercado, el tiempo que esperan los clientes en ser atendidos, y el tiempo que permanecen ociosos los empleados.

Se dispone del archivo `MOVIMIENTOS.dat`, en orden cronológico, que describe qué cliente ingresó ('E') o egresó ('S') de una caja y a qué hora.

```cpp
struct Mov
{
   int idCli;
   char mov; // 'E' o 'S'
   int hora; // hhmm
};
```

Se realizará una simulación con 3, 4, 7, 8 y 10 cajas habilitadas. Cuando un cliente llega se coloca en la cola más corta; si hay una o varias cajas sin cola, se ubica en cualquiera de estas.

!!! Se pide:

# Generar un listado con el tiempo promedio de espera de los clientes y el porcentaje de tiempo ocioso de las cajas, según la cantidad de cajas habilitadas.

Espera de un cliente = hora de salida − hora de entrada. El tiempo ocioso de una caja es la suma de los períodos en que quedó sin clientes (ventana de tiempo desde el primer hasta el último movimiento).

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `MOVIMIENTOS.dat` → 10 movimientos = 120 B (12 B c/u), orden cronológico

Layout C++ (MinGW, little endian):
- `Mov` = 12 B: idCli@0, mov@4, pad 5-7, hora@8

Movimientos: E0900 S0910 · E0915 S0930 · E0940 S1000 · E1010 S1025 · E1030 S1040

Los clientes llegan siempre con todas las cajas libres (nunca se forma cola), por lo que la asignación es idéntica para cualquier cantidad de cajas ≥ 3:
- Cliente 1 → caja 1, espera 10
- Cliente 2 → caja 2, espera 15
- Cliente 3 → caja 3, espera 20
- Cliente 4 → caja 1, espera 15
- Cliente 5 → caja 2, espera 10

Tiempo de espera promedio = 70/5 = 14 (igual en todas las configuraciones).

Ventana = 0900 → 1040 = 100 min. Tiempo ocupado por caja: caja 1 = 25 (0910 + 1010→1025), caja 2 = 25, caja 3 = 20.

| Cajas | Ocioso total (min) | Ocioso % = ocioso/(cajas×100) |
|-------|--------------------|------------------------------|
| 3     | 75+75+80 = 230     | 76.7%                        |
| 4     | 230+100 = 330      | 82.5%                        |
| 7     | 230+400 = 630      | 90%                          |
| 8     | 230+500 = 730      | 91.25%                       |
| 10    | 230+700 = 930      | 93%                          |
