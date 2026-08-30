TITLE: Empresa de gas
TAGS: Problema [[Nivel intermedio]]

La empresa que provee el servicio de gas natural categoriza a sus clientes en función de su consumo anualizado (últimos 12 meses). La categoría, que establece el valor del m^^3^^ (metro cúbico) que los clientes deben pagar, está sujeta a ser modificada mes a mes, luego de procesar las lecturas de los medidores.

Para determinar qué categoría le corresponde a un cliente se te toman en consideración los últimos 12 meses. Dicha información está almacenada en el campo `consumos` del archivo de clientes.

Se dispone de los archivos `CATEGORIAS.dat`, `CLIENTES.dat` y `MEDICIONES.dat`, cuyas estructuras de registro son las siguientes:

```cpp
struct Categoria
{
   char idCat[3];
   char descrip[50];
   int m3Desde;  // mts cubicos
   int m3Hasta;  // mts cubicos 
   double valorM3;
};
```

```cpp
struct Cliente
{
   int idCli; // ordenado
   char nombre[100];
   char direccion[200];
   char idCatAnt[3]; 
   int lecturaAnterior;
   unsigned char consumos[36] ;
};
```

```cpp
struct Medicion
{
   int idCli;
   int lecturaActual;
   Fecha fecha;
};
```

Para acceder al archivo de clientes disponemos de la función `buscarCliente`, que retorna la posición del registro que describe al cliente buscado o un valor negativo si ningún registro describe a dicho cliente. Su prototipo es: 

```cpp
int buscarCliente(int idCli,FILE* fCli);
```

También contamos con las funciones `decodeConsumo` y `encodeConsumo`, que respectivamente decodifican y codifican el historial de consumo anual de un cliente.

```cpp
// Retorna un array (TAD) con 12 estructuras Consumo que describen el
// consumo de los ultimos 12 meses, siendo el mas reciente el que ocupa la
// posicion 0 del array, el anterior ocupa la posicion 1 y asi sucesivamente
Array<Consumo> decodeConsumo(unsigned char consumos[]);

// Funcion inversa a la anterior
unsigned char* encodeConsumo(Array<Consumo> arr);
```

Para calcular el consumo anual utilizaremos la función `calcularConsumoAnual`, cuyo prototipo veremos a continuación, que retorna el consumo anual en función del consumo actual y el de los últimos 12 meses. Además, la función actualiza el //array// de consumos, insertando el consumo actual en la posición cero y eliminando el consumo más antiguo. 

```cpp
// Retorna el consumo anual segun el actual y el acumulado
int calcularConsumoAnual(int consumoActual,Array<Consumo>& consumos);
```

La estructura `Consumo` que utilizan todas estas funciones es la siguiente:

```cpp
struct Consumo
{
   int m3Consumidos;
   Fecha fecha; // fecha de la medicion
};
```

!!!Se pide:

# Emitir un listado detallando, por cada categoría, qué clientes quedaron con esa nueva categorización. Es decir: cuáles  son nuevos en dicha categoría.

# Actualizar el archivo `CLIENTES.dat`, modificando los campos `idCatAnt` (si corresponde), `lecturaAnterior` y `consumos` (eliminando el consumo más antiguo y agregando el consumo del mes actual).

# Implementar la función `calcularConsumoAnual` según lo especificado más arriba.

# Implementar la función `buscarCliente` utilizando el algoritmo de la búsqueda binaria.

La empresa que provee el servicio de gas natural categoriza a sus clientes en función de su consumo anualizado (últimos 12 meses). La categoría, que establece el valor del m^^3^^ (metro cúbico) que los clientes deben pagar, está sujeta a ser modificada mes a mes, luego de procesar las lecturas de los medidores.

Para determinar qué categoría le corresponde a un cliente se te toman en consideración los últimos 12 meses. Dicha información está almacenada en el campo `consumos` del archivo de clientes.

Se dispone de los archivos `CATEGORIAS.dat`, `CLIENTES.dat` y `MEDICIONES.dat`, cuyas estructuras de registro son las siguientes:

```cpp
struct Categoria
{
   char idCat[3];
   char descrip[50];
   int m3Desde;  // mts cubicos
   int m3Hasta;  // mts cubicos 
   double valorM3;
};
```

```cpp
struct Cliente
{
   int idCli; // ordenado
   char nombre[100];
   char direccion[200];
   char idCatAnt[3]; 
   int lecturaAnterior;
   unsigned char consumos[36] ;
};
```

```cpp
struct Medicion
{
   int idCli;
   int lecturaActual;
   Fecha fecha;
};
```

Para acceder al archivo de clientes disponemos de la función `buscarCliente`, que retorna la posición del registro que describe al cliente buscado o un valor negativo si ningún registro describe a dicho cliente. Su prototipo es: 

```cpp
int buscarCliente(int idCli,FILE* fCli);
```

También contamos con las funciones `decodeConsumo` y `encodeConsumo`, que respectivamente decodifican y codifican el historial de consumo anual de un cliente.

```cpp
// Retorna un array (TAD) con 12 estructuras Consumo que describen el
// consumo de los ultimos 12 meses, siendo el mas reciente el que ocupa la
// posicion 0 del array, el anterior ocupa la posicion 1 y asi sucesivamente
Array<Consumo> decodeConsumo(unsigned char consumos[]);

// Funcion inversa a la anterior
unsigned char* encodeConsumo(Array<Consumo> arr);
```

Para calcular el consumo anual utilizaremos la función `calcularConsumoAnual`, cuyo prototipo veremos a continuación, que retorna el consumo anual en función del consumo actual y el de los últimos 12 meses. Además, la función actualiza el //array// de consumos, insertando el consumo actual en la posición cero y eliminando el consumo más antiguo. 

```cpp
// Retorna el consumo anual segun el actual y el acumulado
int calcularConsumoAnual(int consumoActual,Array<Consumo>& consumos);
```

La estructura `Consumo` que utilizan todas estas funciones es la siguiente:

```cpp
struct Consumo
{
   int m3Consumidos;
   Fecha fecha; // fecha de la medicion
};
```

!!!Se pide:

# Emitir un listado detallando, por cada categoría, qué clientes quedaron con esa nueva categorización. Es decir: cuáles  son nuevos en dicha categoría.

# Actualizar el archivo `CLIENTES.dat`, modificando los campos `idCatAnt` (si corresponde), `lecturaAnterior` y `consumos` (eliminando el consumo más antiguo y agregando el consumo del mes actual).

# Implementar la función `calcularConsumoAnual` según lo especificado más arriba.

# Implementar la función `buscarCliente` utilizando el algoritmo de la búsqueda binaria.