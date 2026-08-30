TITLE: Asistencia mecánica
TAGS: Problema [[Nivel avanzado]]

Una empresa de asistencia mecánica solicita desarrollar un programa que ayude con la gestión de sus servicios.

Cuando un abonado requiere asistencia se comunica con la empresa. Indica su número de abonado (`idAbo`) y en qué zona está. Existen 10 zonas, numeradas de 0 a 9.
El operador que recibe la llamada debe verificar que el abonado tenga sus cuotas al día. Luego, lo colocará en una cola de espera y le informará el tiempo aproximado que deberá esperar.

Cuando un móvil finaliza una asistencia se comunica con la empresa e informa cuál es el número de caso que acaba de resolver. El móvil libre pasará a una cola y quedará en espera hasta que un nuevo caso le sea asignado. El operador le informará, estimativamente, qué tiempo deberá esperar.

Luego de cada evento (llamada de un abonado o de un móvil) el sistema debe verificar si es posible realizar una asignación móvil/abonado. En tal caso, deberá notificar a ambos involucrados (abonado y móvil) vía mensaje de texto (SMS) al celular. El abonado debe recibir un SMS con el nombre del conductor del móvil que está en camino. El móvil debe recibir el nombre del abonado que lo está esperando.

Las siguientes funciones de biblioteca están disponibles para su uso.

```cpp
// envia un SMS al celular especificado como parametro
void notificarAsignacion(string celularDestino,int nroCaso,string nombre);

// retorna la hora actual expresada en milisegundos
int getTime();
```

Las estructuras de los archivos `MOVILES.dat` y `ABONADOS.dat` son las siguientes:

```cpp
struct Movil
{
   int idMovil;
   char conductor[100];
   int zona;
   char celular[50];
};
```

```cpp
struct Abonado
{
   int idAbo;
   char nombre[100];
   char celular[50];
   bool cuotasAlDia;
};
```

El número de caso inicial se ingresará por teclado. A partir de allí, a cada caso se le asignará un valor correlativo.

!!! Se pide:

# Desarrollar un programa interactivo que asista al operador durante toda la operatoria descripta más arriba. El programa estará esperando a que ocurra un evento. Si llama un abonado, el operador ingresará el valor 1. Si llama un móvil, ingresará 2. Para finalizar el programa ingresará 3.
# Al finalizar el programa indicar, por cada móvil, los casos cuyo tiempo de atención estuvo por debajo del promedio de la zona.

=== RESULTADO ESPERADO (datos provistos) ===

Archivos generados:
- `MOVILES.dat`  → 5 móviles (zonas 0, 1, 2, 3, 4) = 800 B
- `ABONADOS.dat` → 5 abonados (3 con cuotas al día, 2 sin cuotas) = 780 B

Layout C++ (MinGW, little endian):
- `Movil`    = 160 B: idMovil@0, conductor@4, zona@104, celular@108, pad 158-159
- `Abonado`  = 156 B: idAbo@0, nombre@4, celular@104, cuotasAlDia@154, pad 155

La salida final depende de la secuencia de eventos ingresada por teclado:
- `notificarAsignacion(celular, nroCaso, nombre)` debe invocarse por cada asignación
  (al abonado con el conductor y al móvil con el abonado).
- `mostrarResultado()` imprime por cada móvil los casos con tiempo de atención
  por debajo del promedio de su zona.
