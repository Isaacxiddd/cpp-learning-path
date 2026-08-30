TITLE: Medición de audiencia
TAGS: [[Nivel avanzado]] Problema

La empresa que se encarga de medir el ranking de los programas de televisión dispone del archivo `MUESTRAS.dat`, con los datos del encendido, zapping y apagado que registraron los monitores de audiencia. Este archivo no tiene orden, y por su tamaño puede administrarse en memoria.

```cpp
struct Muestra
{
   int idMonitor;
   int hora;
   int min;
   char accion; // 'E' Enciende, 'C' Cambia de canal, 'A' Apaga
   int canal;
};
```

La acción 'C' se produce cada vez que el usuario abandona un canal, habiéndolo dejado fijo por, al menos, 1 minuto. Si el usuario apaga el televisor, el monitor genera primero un registro 'C' (con la hora/min del apagado) y luego el 'A'. Se garantiza la consistencia: por cada 'E' hay una secuencia de 'C' y un 'A'.

!!! Se pide:

# Grabar el archivo `MINAMIN.dat` (Minuto a Minuto), ordenado por `canal` y `min`, describiendo por cada canal cuántos monitores lo sintonizaron durante cada minuto del día.

```cpp
struct MinAMin
{
   int canal;
   int min; // min del dia (de 0 a 1439)
   int cant;
};
```

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `MUESTRAS.dat` → 7 muestras = 140 B (20 B c/u)
- `MINAMIN.dat` → generado por el programa

Layout C++ (MinGW, little endian):
- `Muestra` = 20 B: idMonitor@0, hora@4, min@8, accion@12, pad 13-15, canal@16

Muestras:
- Monitor 1: E 10:00 · C 10:15 (canal 5) · C 10:45 (canal 7) · A 11:00
- Monitor 2: E 10:10 · C 10:30 (canal 5) · A 10:35

Rangos sintonizados:
- Monitor 1: canal 5 de min 600 (10:00) a 614, canal 7 de 615 (10:15) a 659 (11:00)
- Monitor 2: canal 5 de min 610 (10:10) a 629 (10:30)

MINAMIN.dat (canal 5): min 600-609 → 1; min 610-614 → 2; min 615-629 → 1
MINAMIN.dat (canal 7): min 615-659 → 1
