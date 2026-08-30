TITLE: Optimización de colas
TAGS: Problema [[Nivel avanzado]]

Se requiere desarrollar un programa para ayudar a encontrar una relación óptima entre la cantidad de cajas que se habilitan en un supermercado, el tiempo que esperan los clientes en ser atendidos, y el tiempo que permanecen ociosos los empleados que atienden dichas cajas.

Contamos con el archivo `MOVIMIENTOS.dat`, cuya estructura vemos a continuación, que describe qué cliente ingresó o egreso de una caja y a qué hora se produjo dicho movimiento.

```cpp
struct Mov
{
   int idCli;
   char mov; // 'E' o 'S'
   int hora; // hhmm
};
```

Se realizará una simulación con 3, 4, 7, 8 y 10 cajas habilitadas. 

Se debe tener en cuenta que, cuando un cliente llega a la línea de cajas se colocará en la cola más corta, y si hubiese una o varias cajas sin cola el cliente se ubicará en cualquiera de estas.

!!!Se pide: 

# Generar un listado informando el tiempo promedio de espera de los clientes y el porcentaje de tiempo ocioso de las cajas, según cual sea la cantidad de cajas habilitadas. <div>

|Cantidad de cajas habilitadas: | 3 | 4 | 7 | 8 | 10 |
|Tiempo de espera promedio: |9999|9999|9999|9999|9999|
|Porcentaje de tiempo ocioso: |9999|9999|9999|9999|9999|

</div>





Se requiere desarrollar un programa para ayudar a encontrar una relación óptima entre la cantidad de cajas que se habilitan en un supermercado, el tiempo que esperan los clientes en ser atendidos, y el tiempo que permanecen ociosos los empleados que atienden dichas cajas.

Contamos con el archivo `MOVIMIENTOS.dat`, cuya estructura vemos a continuación, que describe qué cliente ingresó o egreso de una caja y a qué hora se produjo dicho movimiento.

```cpp
struct Mov
{
   int idCli;
   char mov; // 'E' o 'S'
   int hora; // hhmm
};
```

Se realizará una simulación con 3, 4, 7, 8 y 10 cajas habilitadas. 

Se debe tener en cuenta que, cuando un cliente llega a la línea de cajas se colocará en la cola más corta, y si hubiese una o varias cajas sin cola el cliente se ubicará en cualquiera de estas.

!!!Se pide: 

# Generar un listado informando el tiempo promedio de espera de los clientes y el porcentaje de tiempo ocioso de las cajas, según cual sea la cantidad de cajas habilitadas. <div>

|Cantidad de cajas habilitadas: | 3 | 4 | 7 | 8 | 10 |
|Tiempo de espera promedio: |9999|9999|9999|9999|9999|
|Porcentaje de tiempo ocioso: |9999|9999|9999|9999|9999|

</div>



