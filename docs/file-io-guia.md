 # Guía de FILE I/O en C++ — Por qué, cómo y cuándo

**Materia:** Algoritmos y Programación A Fondo  
**Profesor:** Pablo A. Sznajdleder  
**Concepto clave:** Persistencia de datos en archivos de registros

---

## 1. ¿Qué es FILE I/O y por qué lo necesitamos?

### El problema: Datos que persisten

Cuando escribes un programa en C++, los datos que creas en memoria (variables, arrays, estructuras) desaparecen cuando el programa termina. Esto es un problema en aplicaciones reales porque:

- **Una compañía aérea** necesita guardar reservas incluso después de cerrar el software
- **Un torneo de fútbol** debe recordar los resultados de partidos pasados
- **Un banco** necesita archivos históricos de transacciones

**Solución:** Guardar datos en **archivos persistentes** (en disco duro).

### La abstracción: Archivos como flujos de bytes

En C++, un archivo es un **flujo de datos** que puedes leer y escribir:

```
         MEMORIA (RAM)              ARCHIVO (Disco)
           ┌──────┐                  ┌──────┐
     ┌────▶│ var1 │◄────read()────◀─│ ... │
     │     └──────┘                  └──────┘
     │     ┌──────┐                  ┌──────┐
     └────▶│ var2 │◀──write()──────►│ ... │
           └──────┘                  └──────┘
```

---

## 2. Tipos de archivos que usamos

### Archivos binarios (lo que usamos en este curso)

Guardan datos en **formato binario** — la representación exacta en memoria:

```cpp
struct Llamada {
    int idAbonado;      // 4 bytes
    long long fechaHora; // 8 bytes
    int duracion;       // 4 bytes
    char nroDestino[30]; // 30 bytes
};                      // Total: 46 bytes por registro

// Cada Llamada ocupa exactamente 46 bytes en el archivo
```

**Ventajas:**
- Lectura/escritura ultrarrápida
- Acceso aleatorio: puedo leer el registro 100 sin leer los anteriores
- Compacto: los datos ocupan exactamente lo necesario

### Archivos de texto (menos usados en este curso)

Guardan datos como **texto legible por humanos**. Usamos textual solo cuando procesamos líneas o palabras de un documento.

---

## 3. Funciones básicas de FILE I/O en C++

### Abrir y cerrar archivos

```cpp
// Abrir archivo
FILE* f = fopen("datos.bin", "w+b");  // "w+b" = lectura/escritura binaria
if (f == NULL) {
    cout << "Error: no se pudo abrir el archivo" << endl;
    return;
}

// ... trabajar con el archivo ...

// Cerrar archivo (muy importante)
fclose(f);
```

**Modos de apertura:**
- `"w+b"` — Crear nuevo (borra si existe)
- `"r+b"` — Abrir existente para lectura/escritura
- `"a+b"` — Abrir/crear, escribir al final (append)

---

## 4. API de funciones templatizadas (Sznajdleder)

El profesor diseñó funciones **genéricas con templates** para simplificar el trabajo con archivos. Están en `lib/funciones/files.hpp`:

### Escribir registros

```cpp
template <typename T>
void write(FILE* f, T t) {
    fwrite(&t, sizeof(T), 1, f);
}
```

**Uso:**
```cpp
FILE* f = fopen("numeros.x", "w+b");
write<short>(f, 1234);    // Escribe un short (2 bytes)
write<short>(f, 4321);    // Escribe otro short
write<short>(f, -9876);   // Y otro más
fclose(f);
// Archivo resultante: 6 bytes (3 shorts × 2 bytes cada uno)
```

---

### Leer registros

```cpp
template <typename T>
T read(FILE* f) {
    T valor;
    fread(&valor, sizeof(T), 1, f);
    return valor;
}
```

**Uso:**
```cpp
FILE* f = fopen("numeros.x", "r+b");
while (!feof(f)) {  // Mientras NO sea fin de archivo
    short s = read<short>(f);
    cout << s << endl;
}
fclose(f);
// Output: 1234, 4321, -9876
```

---

### Navegar dentro del archivo: seek()

**Problema:** El archivo tiene 1000 registros. ¿Cómo leo el registro 500 sin leer los 499 anteriores?

**Solución:** `seek()` mueve el "cursor" del archivo:

```cpp
template <typename T>
void seek(FILE* f, int n) {
    fseek(f, n * sizeof(T), SEEK_SET);
}
```

**Uso:**
```cpp
FILE* f = fopen("registros.x", "r+b");

// Saltar directamente al registro 100
seek<Persona>(f, 100);

// Leer ese registro específico
Persona p = read<Persona>(f);
cout << "Registro 100: " << p.nombre << endl;

fclose(f);
```

**¿Por qué funciona?**
- `seek<Persona>(f, 100)` coloca el cursor en la posición: `100 × sizeof(Persona)` bytes
- El siguiente `read()` obtiene exactamente ese registro

---

### Saber cuántos registros hay: fileSize()

```cpp
template <typename T>
int fileSize(FILE* f) {
    long posActual = ftell(f);        // Guarda posición actual
    fseek(f, 0, SEEK_END);            // Va al final
    long posFinal = ftell(f);         // Lee posición final (bytes totales)
    fseek(f, posActual, SEEK_SET);    // Vuelve a posición original
    return posFinal / sizeof(T);      // Retorna cantidad de registros
}
```

**Uso:**
```cpp
FILE* f = fopen("registros.x", "r+b");
int totalRegistros = fileSize<Persona>(f);
cout << "El archivo tiene " << totalRegistros << " personas" << endl;
fclose(f);
```

---

### Saber la posición actual: filePos()

```cpp
template <typename T>
int filePos(FILE* f) {
    return ftell(f) / sizeof(T);
}
```

**Uso:**
```cpp
FILE* f = fopen("registros.x", "r+b");

for (int i = fileSize<Persona>(f) - 1; i >= 0; i--) {
    seek<Persona>(f, i);
    Persona p = read<Persona>(f);
    int posActual = filePos<Persona>(f) - 1; // -1 porque ya avanzó
    cout << "Registro " << posActual << ": " << p.nombre << endl;
}
fclose(f);
```

---

## 5. Funciones de texto (archivos de líneas y palabras)

A veces procesamos **archivos de texto legible** como parámetros de entrada:

### Leer líneas: readLine()

```cpp
bool readLine(FILE* f, string& ln);
```

Lee una línea completa (hasta encontrar `\n`):

```cpp
FILE* f = fopen("usuarios.txt", "r+b");
string linea;
while (readLine(f, linea)) {  // true si quedan líneas
    cout << linea << endl;
}
fclose(f);
```

**Ejemplo de archivo:**
```
Juan Pérez
María González
Carlos López
```

---

### Leer palabras: readWord()

```cpp
bool readWord(FILE* f, string& w);              // Solo [A-Z][a-z][0-9]
bool readWord(FILE* f, string& w, string also); // + caracteres especiales
```

Separa por espacios y caracteres especiales:

```cpp
FILE* f = fopen("datos.txt", "r+b");
string palabra;
while (readWord(f, palabra, "-_")) {  // Permite guiones y guiones bajos
    cout << "[" << palabra << "]" << endl;
}
fclose(f);
```

**Si el archivo contiene:**
```
Este archivo es
MUY-CHICO. Por eso, nadie lo quiere
compactar_mas. Ok?
```

**Output:**
```
[Este]
[archivo]
[es]
[MUY-CHICO]
[Por]
[eso]
[nadie]
[lo]
[quiere]
[compactar_mas]
[Ok]
```

---

## 6. Caso de uso real: Procesamiento de datos del Capítulo 4

### El problema típico

"Se tiene un archivo `LLAMADAS.x` con 10,000 registros de llamadas telefónicas. Calcular el consumo total por abonado."

```cpp
struct Llamada {
    int idAbonado;
    long long fechaHora;
    int duracion;     // en segundos
    char nroDestino[30];
};
```

### La solución: Corte de control + archivo persistente

```cpp
#include "principal.hpp"

int main() {
    FILE* f = fopen("LLAMADAS.x", "r+b");
    
    int totalRegistros = fileSize<Llamada>(f);
    
    // Asumimos que el archivo está ordenado por idAbonado
    int abonado_anterior = -1;
    int consumoAbonado = 0;
    
    for (int i = 0; i < totalRegistros; i++) {
        Llamada llamada = read<Llamada>(f);
        
        // Corte de control
        if (abonado_anterior != -1 && llamada.idAbonado != abonado_anterior) {
            // Cambió el abonado → reportar el anterior
            cout << "Abonado " << abonado_anterior 
                 << ": " << consumoAbonado << " segundos" << endl;
            consumoAbonado = 0;
        }
        
        // Acumular
        consumoAbonado += llamada.duracion;
        abonado_anterior = llamada.idAbonado;
    }
    
    // Último abonado
    cout << "Abonado " << abonado_anterior 
         << ": " << consumoAbonado << " segundos" << endl;
    
    fclose(f);
    return 0;
}
```

---

## 7. Por qué Sznajdleder usa templates

### El problema sin templates

Si quisiéramos funciones para cada tipo:

```cpp
void writeShort(FILE* f, short s) { fwrite(&s, sizeof(short), 1, f); }
void writeInt(FILE* f, int i) { fwrite(&i, sizeof(int), 1, f); }
void writePersona(FILE* f, Persona p) { fwrite(&p, sizeof(Persona), 1, f); }
// ... una función para cada tipo ...
```

**¡Código duplicado y mantenimiento pesado!**

### La solución: Templates

```cpp
template <typename T>
void write(FILE* f, T t) {
    fwrite(&t, sizeof(T), 1, f);  // Funciona para CUALQUIER tipo T
}
```

**Ahora funciona para todo:**
```cpp
write<short>(f, 123);
write<int>(f, 456);
write<Persona>(f, juan);
write<Llamada>(f, llamada);
```

**Principio:** "Escribe una vez, usa para siempre" → **Reutilización máxima**.

---

## 8. Resumen: Cuándo usar cada función

| Tarea | Función | Ejemplo |
|-------|---------|---------|
| Escribir un registro | `write<T>` | `write<short>(f, 123);` |
| Leer un registro | `read<T>` | `short s = read<short>(f);` |
| Ir al registro N | `seek<T>` | `seek<Persona>(f, 100);` |
| Contar registros | `fileSize<T>` | `int n = fileSize<Persona>(f);` |
| Saber dónde estoy | `filePos<T>` | `int pos = filePos<Persona>(f);` |
| Leer texto línea a línea | `readLine` | `readLine(f, linea);` |
| Leer texto palabra a palabra | `readWord` | `readWord(f, palabra);` |

---

## 9. Recursos complementarios

- **Libro:** Capítulo 4 (Resolución de Problemas) — Pablo A. Sznajdleder
- **Apéndice 2:** Especificaciones y API — Sección 1.5.1
- **Implementación:** `lib/funciones/files.hpp` en el proyecto

---

## Ejercicio propuesto

Crear un programa que:
1. Genere un archivo `numeros.x` con 5 enteros (123, 456, 789, 111, 222)
2. Lea el archivo de atrás para adelante
3. Muestre: `[posición] [número]`

**Salida esperada:**
```
[4] 222
[3] 111
[2] 789
[1] 456
[0] 123
```

**Pista:** Usa `fileSize<int>()` y un loop que va hacia atrás, combinado con `seek<int>()`.
