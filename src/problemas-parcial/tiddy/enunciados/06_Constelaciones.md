TITLE: Constelaciones
TAGS: Problema [[Nivel avanzado]]

El observatorio de la Ciudad de Buenos Aires desea desarrollar una página Web interactiva que le permita a los usuarios visualizar un conjunto de constelaciones, entendiendo que una constelación es un conjunto de segmentos imaginarios que unen un conjunto de estrellas.

Cada constelación a visualizar estará representada por una estructura `Constelación`. 

```cpp
struct Constelacion
{
   char nombre[50];
   Estrella estrellas[25]; 
   Segmento segmentos[25];
};
```

Siendo las estructuras `Estrella` y `Segmento` las siguientes:

```cpp
struct Estrella
{
   char nombre[50];
   int coordX;
   int corrdY;
   int orden;
};
```

```cpp
struct Segmento
{
   int ptoOrigen;
   int ptoDestino;
};
```

Además, ponen a nuestra disposición la función `dibujarSegmento`, cuyo prototipo es el siguiente:

```cpp
void dibujarSegmento(Estrella e1,Estrella e2);
```

!!! Se pide:

# Desarrollar la función `mostrarConstelaciones`, cuyo prototipo vemos a continaución, para mostrar un conjunto de constelaciones: <div>

```cpp
void mostrarConstelaciones(Constelacion constelaciones[],int len);
```

</div>

# Desarrollar la función `detalleConstelaciones`, con el siguiente prototipo, para mostrar la composición de cada una de las constelaciones del conjunto. <div>

```cpp
void detalleConstelaciones(Constelacion [] a,int len);
```

La función debe arrojar la siguiente salida: 

|>|>|>|Constelación: xxxxxxxxxxxxxxxx|
|Nro. Orden |Estrella |Coord. X |Coord. Y|
| 1|xxxxxxxxxxx| 9999| 9999|
| 2|xxxxxxxxxxx| 9999| 9999|
| 3|xxxxxxxxxxx| 9999| 9999|
| :|: | :| :|

|>|Segmentos |
|Pto. Origen |Pto. Destino |
| 99| 99|
| 99| 99|
| :| :|

</div>





El observatorio de la Ciudad de Buenos Aires desea desarrollar una página Web interactiva que le permita a los usuarios visualizar un conjunto de constelaciones, entendiendo que una constelación es un conjunto de segmentos imaginarios que unen un conjunto de estrellas.

Cada constelación a visualizar estará representada por una estructura `Constelación`. 

```cpp
struct Constelacion
{
   char nombre[50];
   Estrella estrellas[25]; 
   Segmento segmentos[25];
};
```

Siendo las estructuras `Estrella` y `Segmento` las siguientes:

```cpp
struct Estrella
{
   char nombre[50];
   int coordX;
   int corrdY;
   int orden;
};
```

```cpp
struct Segmento
{
   int ptoOrigen;
   int ptoDestino;
};
```

Además, ponen a nuestra disposición la función `dibujarSegmento`, cuyo prototipo es el siguiente:

```cpp
void dibujarSegmento(Estrella e1,Estrella e2);
```

!!! Se pide:

# Desarrollar la función `mostrarConstelaciones`, cuyo prototipo vemos a continaución, para mostrar un conjunto de constelaciones: <div>

```cpp
void mostrarConstelaciones(Constelacion constelaciones[],int len);
```

</div>

# Desarrollar la función `detalleConstelaciones`, con el siguiente prototipo, para mostrar la composición de cada una de las constelaciones del conjunto. <div>

```cpp
void detalleConstelaciones(Constelacion [] a,int len);
```

La función debe arrojar la siguiente salida: 

|>|>|>|Constelación: xxxxxxxxxxxxxxxx|
|Nro. Orden |Estrella |Coord. X |Coord. Y|
| 1|xxxxxxxxxxx| 9999| 9999|
| 2|xxxxxxxxxxx| 9999| 9999|
| 3|xxxxxxxxxxx| 9999| 9999|
| :|: | :| :|

|>|Segmentos |
|Pto. Origen |Pto. Destino |
| 99| 99|
| 99| 99|
| :| :|

</div>



