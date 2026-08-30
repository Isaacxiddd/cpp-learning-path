TITLE: Hospedaje en casas de familia
TAGS: Problema [[Nivel intermedio]]

Un sitio de Internet que ofrece alojamiento en casas de familia requiere aumentar las funcionalidades de sus servicios.

En el archivo `CARACTERISTICAS.dat`, que se describe más abajo, el valor del campo `idCaract` es una potencia de 2. Por ejemplo: 1implica //Cercanía a la costa//, 2 implica //Aire acondicionado//, 4 implica //Parrilla//, 8 implica //Piscina//, 16 implica //Cochera//, etcétera. Cada potencia representa una característica diferente.

En el archivo `CASAS.dat`, si el valor d el campo `idUsr`,  es 0 (cero) significa que la casa en cuestión está disponible. De lo contrario indicará el //id// del usuario que la arrendó.

```cpp
struct Caract
{
   int idCaract; 
   char descr[100];
};
```

```cpp
struct Casa
{
   int idCasa;
   char direcc[50];
   int idDueno;
   int caractMask;
   int idUsr;
};
```

Los usuarios buscan casas que tengan ciertas características. Cada búsqueda genera un registro del siguiente tipo:

```cpp
struct Busqueda
{
   int idUsr;
   int caractMask;
   int dias;
   double tolerancia;
};
```

El campo `caractMask` es una máscara de bits de 4 bytes, donde cada bit indica la existencia o no de una determinada característica.

Se dispone de siguientes funciones de biblioteca:

La función `concordancia` compara las características de una casa con las carácterísticas que desea el potencial inquilino, y retorna un porcentaje de coincidencia; siendo 1 el 100%, 0,8 el 80%, etcétera. 

```cpp
double concordancia(int idCasa,int mask);
```

Las funciones leerBusqueda y continuarOperando permiten interactuar con la operatoria del portal de Internet.

```cpp
// Retorna un registro con los parametros de busqueda indicados por el usuario
Busqueda leerBusqueda();  

// Indica si quedan mas busquedas por procesar
bool continuarOperando();

// Muestra por pantalla la casa especificada
void  mostrarCasa(int idCasa) 
```

!!!Se pide:

# Por cada búsqueda, emitir un listado (ordenado decrecientemente por el porcentaje de concordancia) de todas las casas disponibles cuya concordancia está por encima del valor tolerancia del registro de la búsqueda. Por cada casa, se debe invocar a la función `mostrarCasa`, que mostrará en la página Web las fotos, detalles y demás datos que resultarán de interés para el usuario.


Un sitio de Internet que ofrece alojamiento en casas de familia requiere aumentar las funcionalidades de sus servicios.

En el archivo `CARACTERISTICAS.dat`, que se describe más abajo, el valor del campo `idCaract` es una potencia de 2. Por ejemplo: 1implica //Cercanía a la costa//, 2 implica //Aire acondicionado//, 4 implica //Parrilla//, 8 implica //Piscina//, 16 implica //Cochera//, etcétera. Cada potencia representa una característica diferente.

En el archivo `CASAS.dat`, si el valor d el campo `idUsr`,  es 0 (cero) significa que la casa en cuestión está disponible. De lo contrario indicará el //id// del usuario que la arrendó.

```cpp
struct Caract
{
   int idCaract; 
   char descr[100];
};
```

```cpp
struct Casa
{
   int idCasa;
   char direcc[50];
   int idDueno;
   int caractMask;
   int idUsr;
};
```

Los usuarios buscan casas que tengan ciertas características. Cada búsqueda genera un registro del siguiente tipo:

```cpp
struct Busqueda
{
   int idUsr;
   int caractMask;
   int dias;
   double tolerancia;
};
```

El campo `caractMask` es una máscara de bits de 4 bytes, donde cada bit indica la existencia o no de una determinada característica.

Se dispone de siguientes funciones de biblioteca:

La función `concordancia` compara las características de una casa con las carácterísticas que desea el potencial inquilino, y retorna un porcentaje de coincidencia; siendo 1 el 100%, 0,8 el 80%, etcétera. 

```cpp
double concordancia(int idCasa,int mask);
```

Las funciones leerBusqueda y continuarOperando permiten interactuar con la operatoria del portal de Internet.

```cpp
// Retorna un registro con los parametros de busqueda indicados por el usuario
Busqueda leerBusqueda();  

// Indica si quedan mas busquedas por procesar
bool continuarOperando();

// Muestra por pantalla la casa especificada
void  mostrarCasa(int idCasa) 
```

!!!Se pide:

# Por cada búsqueda, emitir un listado (ordenado decrecientemente por el porcentaje de concordancia) de todas las casas disponibles cuya concordancia está por encima del valor tolerancia del registro de la búsqueda. Por cada casa, se debe invocar a la función `mostrarCasa`, que mostrará en la página Web las fotos, detalles y demás datos que resultarán de interés para el usuario.
