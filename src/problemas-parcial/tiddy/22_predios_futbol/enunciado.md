TITLE: Predios de fútbol
TAGS: [[Nivel avanzado]] Problema

Un estudio administrativo que gestiona predios con varias canchas de fútbol requiere un programa que procese la reserva de canchas para el mes próximo.

Los clientes reservan una cancha en un predio para un determinado día del mes, en uno de los tres turnos: mañana (10 a 14 hs.), tarde (14 a 18 hs.) y noche (18 a 22 hs.).

```cpp
struct Predio
{
   int idPredio;
   char nombre[100];
   char direccion[100];
   int cantCanchas;
   int idBarrio;
};
```

```cpp
struct Reserva
{
   int idReserva;
   int idCliente;
   int idPredio;
   int diaMes; // 1 a 31
   char turno; // 'M', 'T', 'N'
   char celContacto[50];
};
```

```cpp
struct Cancha
{
   int idPredio;
   int nroCancha;
   double precio;
   int flgCubierta;
   char obs[200];
};
```

Los partidos comienzan a hora exacta y duran 50 minutos; los 10 minutos restantes se usan para el recambio de jugadores. Por lo tanto cada cancha admite 4 partidos por turno (horarios 10:00, 11:00, 12:00 y 13:00 en el turno mañana, y así en cada turno). La asignación de cancha y hora la establece el programa.

!!! Se pide:

# Generar `RECHAZOS.dat` con las reservas que no serán aceptadas:

```cpp
struct Rechazo
{
   Reserva reserva;
   int motivoRechazo; // 1 = cancha no disponible, 2 = predio inexistente
};
```

# Notificar a los clientes sobre la aceptación o rechazo de su reserva (en caso de aceptación, cancha y hora asignada; en caso de rechazo, el motivo).
# Emitir un listado detallando, por barrio, cuántas reservas fueron aceptadas y cuántas rechazadas por cada turno.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `PREDIOS.dat` → 3 predios = 636 B (212 B c/u)
- `CANCHAS.dat` → 4 canchas = 896 B (224 B c/u)
- `RESERVAS.dat` → 10 reservas = 720 B (72 B c/u)
- `RECHAZOS.dat` → generado por el programa = 152 B (2 × 76 B)

Layout C++ (MinGW, little endian):
- `Predio`  = 212 B: idPredio@0, nombre@4, direccion@104, cantCanchas@204, idBarrio@208
- `Cancha`  = 224 B: idPredio@0, nroCancha@4, precio@8 (double), flgCubierta@16, obs@20, pad 220-223
- `Reserva` = 72 B: idReserva@0, idCliente@4, idPredio@8, diaMes@12, turno@16, pad 17-19, celContacto@20, pad 70-71
- `Rechazo` = 76 B

Predios: P1 (2 canchas, barrio 1), P2 (1 cancha, barrio 2), P3 (1 cancha, barrio 1).

Reservas y resultado:
- R1, R2, R3: P1 día 5 turno M → aceptadas (P1 tiene 2 canchas × 4 slots = 8 lugares)
- R4: P9 (inexistente) → RECHAZOS (motivo 2)
- R5 a R8: P2 día 5 turno T → aceptadas (4 slots ocupados)
- R9: P2 día 5 turno T → RECHAZOS (motivo 1, sin lugar)
- R10: P3 día 5 turno N → aceptada

RECHAZOS.dat: 2 registros → R4 motivo 2, R9 motivo 1

Listado por barrio:
- Barrio 1 (P1, P3): M 3 aceptadas / 0 rechazadas · T 0/0 · N 1 aceptada / 0 rechazadas
- Barrio 2 (P2): M 0/0 · T 4 aceptadas / 1 rechazada · N 0/0
