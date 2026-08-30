TITLE: Compañía de aviación
TAGS: Problema [[Nivel básico]] Solución

Una compañía de aviación requiere implementar un programa que, basado en un sistema de acumulación de millas, promueva la fidelización de sus clientes.

Cada vez que un cliente vuela a través de la compañía recibe una cantidad de millas acumulables que podrá canjear por vuelos sin costo a diferentes destinos. Cuanto mayor sea la cantidad de millas acumuladas, más importantes serán los destinos o premios por los cuales las podrá canjear.

La compañía cuenta con los siguientes archivos: `CIUDADES.dat`, que contiene la descripción de las ciudades a las que vuela, `VUELOS.dat`, con la información de los vuelos que conectan las diferentes ciudades, y `RESERVAS.dat`, con las reservas que realizaron los clientes para volar en los diferentes vuelos.

La estructura de cada uno de estos archivos la vemos a continuación:

```cpp
struct Ciudad
{
   int idCiu;
   char descr[20];
   int millas;
};
```

```cpp
struct Vuelo
{
   int idVue;
   int cap;
   int idOri; // idCiu origen
   int idDes; // idCiu destino
};
```

```cpp
struct Reserva
{
   int idCli;
   int idVue;
   int cant;
};
```

La operatoria es la siguiente: un pasajero que vuela de una ciudad a otra acumula una cantidad de millas equivalente a la diferencia entre las millas establecidas para cada una de esas ciudades, multiplicado por la cantidad de plazas reservadas. Esto será así siempre y cuando su reserva sea aceptada.

Sólo se aceptarán las reservas de aquellos pasajeros que requieran una cantidad de plazas menor o igual a la disponibilidad actual del vuelo en cuestión. De lo contrario la reserva completa será rechazada.

!!! Se pide:

# Informar, para cada ciudad, la cantidad de grupos (familias) que eligieron de destino.
# Indicar, por cada vuelo, la cantidad de plazas que fueron rechazadas, indicando también si el vuelo saldrá completo o incompleto.
# Mostrar, por cada cliente, el total de millas que acumuló.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `CIUDADES.dat` → 3 ciudades = 84 B (28 B c/u)
- `VUELOS.dat`   → 2 vuelos = 32 B (16 B c/u)
- `RESERVAS.dat` → 5 reservas = 60 B (12 B c/u)

Datos:
- Ciudades: 1 Buenos Aires (100), 2 Córdoba (200), 3 Mendoza (300)
- Vuelos: 10 cap=4 (BA→Cba), 20 cap=5 (Cba→Mza)
- Reservas: cli100/vue10×2, cli100/vue20×2, cli200/vue10×2, cli300/vue20×1, cli400/vue10×1

1) Grupos por ciudad de destino:
   - Córdoba (idCiu 2): 3 grupos (las 3 reservas del vuelo 10)
   - Mendoza (idCiu 3): 2 grupos (las 2 reservas del vuelo 20)
   - Buenos Aires (idCiu 1): 0

2) Por vuelo:
   - Vuelo 10: rechazadas 1 (cli400 pidió 1 plaza con cpa ya en 4/4) — COMPLETO
   - Vuelo 20: rechazadas 0 (cpa 3 de 5) — INCOMPLETO

3) Millas por cliente:
   - cli100: 200 + 200 = 400 (vue10 y vue20)
   - cli200: 200 (vue10)
   - cli300: 100 (vue20)
   - cli400: 0 (rechazada)
