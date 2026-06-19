# C++ Learning Path — Contexto para IA

## Curso
**Algoritmos y Programación A FONDO** — Pablo A. Sznajdleder  
Materia universitaria de programación en C++.

---

## Estructura del proyecto

```
cpp-learning-path/
├── lib/                        # Biblioteca educativa del curso
│   ├── funciones/              # El entregable de las Lecciones 4, 5 y 6/7
│   │   ├── strings.hpp         ✅  Lección 4 — API de cadenas
│   │   ├── tokens.hpp          ✅  Lección 5 — API de tokens
│   │   ├── Coll.hpp            ✅  Lección 6/7 — TAD Coll
│   │   ├── millis.hpp          ✅  API de instantes en milisegundos
│   │   ├── files.hpp           🚧  API de archivos (read, write, seek, etc.)
│   │   ├── arrays.hpp          🚧  API de arrays dinámicos
│   │   └── lists.hpp           🚧  API de listas enlazadas
│   └── tads/
│       ├── intro/
│       │   └── Fraccion.hpp    ✅  TAD Fracción (referencia — Lección 3)
│       ├── parte1/
│       │   ├── Coll.hpp        ✅  TAD Coll (genérico)
│       │   ├── Fecha.hpp       🚧  TAD Fecha — Lección 3 (pendiente)
│       │   ├── Timer.hpp       🚧  TAD Timer — Lección 3 (pendiente)
│       │   └── MultidimColl.hpp 🚧 TAD Coll multidimensional
│       └── parte2/
│           ├── Array.hpp       🚧  TAD Array
│           ├── List.hpp        🚧  TAD List
│           ├── Map.hpp         🚧  TAD Map
│           ├── Queue.hpp       🚧  TAD Queue
│           └── Stack.hpp       🚧  TAD Stack
├── src/                        # Ejercicios con programas independientes
│   ├── leccion-01-basicos/     Lección 1: if/else, while, operaciones
│   ├── leccion-02-funciones/   Lección 2: factorial, primo, fibonacci
│   ├── leccion-03-tads/        Lección 3: ejercicios con Fecha y Timer
│   └── capitulo-04-problemas/  Cap. 4: corte de control, apareo, etc.
├── docs/                       Apéndices del libro (solo lectura)
├── AlgoritmosAFondo_EMPTY_v2.7.29/  Proyecto vacío original del curso (referencia)
├── principal.hpp               Include general de toda la biblioteca
├── principal.cpp               Scratch / pruebas rápidas
└── AGENTS.md                   Este archivo
```

> **Lecciones 4, 5 y 6/7 no tienen carpeta en `src/`** porque su entregable es la biblioteca (`lib/`), no programas ejecutables separados.

✅ = implementado   🚧 = esqueleto vacío (pendiente)

---

## Capas de abstracción (orden estricto)

La biblioteca tiene una **jerarquía de dependencias** que debe respetarse. Cada capa solo usa funciones de capas inferiores, nunca al revés:

```
┌─────────────────────────────────────────────────────┐
│  Capa 4: TADs parte2                                │
│  (Array, List, Map, Queue, Stack)                   │
│  Depende de: arrays.hpp, lists.hpp                  │
├─────────────────────────────────────────────────────┤
│  Capa 3: TADs parte1 + Coll                         │
│  (Coll, Fecha, Timer, MultidimColl)                 │
│  Depende de: tokens, strings, millis                │
├─────────────────────────────────────────────────────┤
│  Capa 2: Tokens + Files                             │
│  (tokens.hpp, files.hpp)                            │
│  tokens.hpp depende de: strings.hpp                  │
│  files.hpp depende de: strings.hpp                   │
├─────────────────────────────────────────────────────┤
│  Capa 1: Strings + Millis + Arrays + Lists          │
│  (strings.hpp, millis.hpp, arrays.hpp, lists.hpp)   │
│  No dependen de nada (solo std)                     │
└─────────────────────────────────────────────────────┘
```

### Reglas de uso
- Si usás `tokens.hpp`, ya tenés `strings.hpp` disponible (tokens lo incluye)
- Si usás `Coll.hpp`, ya tenés `tokens.hpp` y `strings.hpp`
- Si usás `Fecha.hpp`, ya tenés `millis.hpp`
- **Nunca** incluir una capa superior desde una inferior (ej: strings no puede usar Coll)
- `principal.hpp` ya incluye todo en el orden correcto. Usalo directamente.

Equivalencia práctica:
```
strings  →  tokens  →  Coll
                   →  files
                   →  Fecha (via millis)
                   →  parte2/* (via arrays, lists)
```

Si estás programando con `Coll`, **no necesitas** incluir `tokens` ni `strings` aparte — ya están dentro. Pero `Coll` SÍ necesita que sepas cómo funcionan tokens y strings porque los usas indirectamente (al serializar/deserializar con `tToString`/`tFromString`).

---

## API completa de funciones

### strings.hpp — API de cadenas
```
int length(string s)                    — Cantidad de caracteres
int charCount(string s, char c)         — Veces que aparece c en s
string substring(string s, int d, int h) — Subcadena [d, h)
string substring(string s, int d)       — Subcadena [d, final]
int indexOf(string s, char c)           — Posición de c en s (-1 si no)
int indexOf(string s, char c, int off)  — Ídem desde offset
int indexOf(string s, string sub)       — Posición de sub en s
int indexOf(string s, string sub, int off) — Ídem desde offset
int lastIndexOf(string s, char c)       — Última posición de c
int indexOfN(string s, char c, int n)   — Posición de la n-ésima c
int charToInt(char c)                   — '5' → 5, 'A' → 10
char intToChar(int i)                   — 5 → '5', 10 → 'A'
int getDigit(int n, int i)              — i-ésimo dígito (0=unidades)
int digitCount(int n)                   — Cantidad de dígitos
string intToString(int i)               — 123 → "123"
int stringToInt(string s, int b)        — "10" en base b → número
int stringToInt(string s)               — "123" → 123 (base 10)
string charToString(char c)             — 'A' → "A"
char stringToChar(string s)             — "A" → 'A'
string stringToString(string s)         — retorna s tal cual (usado en tToString genérico)
string doubleToString(double d,int p)   — 🚧 STUB: retorna "" (no implementada)
string doubleToString(double d)         — 🚧 STUB: retorna "" (no implementada)
double stringToDouble(string s)         — 🚧 STUB: retorna 1.1 siempre (no implementada)
bool isEmpty(string s)                  — s == ""?
bool startsWith(string s, string x)     — s empieza con x?
bool endsWith(string s, string x)       — s termina con x?
bool contains(string s, char c)         — indexOf(s,c) >= 0?
string replace(string s, char a, char b) — Reemplazar a por b
string insertAt(string s, int p, char c) — Insertar c en p
string removeAt(string s, int p)        — Borrar char en p
string ltrim(string s), rtrim, trim     — Podar espacios
string replicate(char c, int n)         — "ccc...c" (n veces)
string spaces(int n)                    — n espacios
string lpad/rpad/cpad(string s, int n, char c) — Padding
bool isDigit/isLetter/isUpperCase/isLowerCase(char)
char toUpperCase/toLowerCase(char)
string toUpperCase/toLowerCase(string)
int cmpString(string a, string b)       — -1,0,1
int cmpDouble(double a, double b)       — -1,0,1
char* stringToCString(string s)         — convierte string a char[] (heap, requiere delete[])
string cStringToString(char c[])        — convierte char[] a string
```

### tokens.hpp — API de tokens
```
int tokenCount(string s, char sep)          — Cantidad de tokens
void addToken(string& s, char sep, string t) — Agregar token al final
string getTokenAt(string s, char sep, int i) — Obtener token en i
void setTokenAt(string& s, char sep, string t, int i) — Reemplazar token en i
void removeTokenAt(string& s, char sep, int i) — Eliminar token en i
int findToken(string s, char sep, string t)  — Buscar token (-1 si no)
```

### files.hpp — Archivos binarios y de texto (🚧 por implementar)
```
void write<T>(FILE* f, T t)         — Escribir registro binario
T read<T>(FILE* f)                  — Leer registro binario
void seek<T>(FILE* f, int n)         — Posicionar en registro n
int fileSize<T>(FILE* f)            — Cantidad de registros
int filePos<T>(FILE* f)             — Posición actual
bool readLine(FILE* f, string& ln)  — Leer línea de texto
bool readWord(FILE* f, string& w [, string extra]) — Leer palabra
void writeString(FILE* f, string s)  — Escribir string (texto)
void writeWord(FILE* f, string w)    — Escribir palabra
void writeLine(FILE* f, string ln)   — Escribir línea
```

### millis.hpp — Instantes en milisegundos (✅)
```
long long currTimeMillis()                    — Timestamp actual
string millisToString(long long ts)            — "2026-04-22, 11:20:20.878"
long long attributesToMillis(y,mo,d,h,m,s,ms)  — Fecha → timestamp
void millisToAttributes(ts, y,mo,d,h,m,s,ms)   — Timestamp → atributos
```

### Coll<T> — TAD Colección (funciones/Coll.hpp) (✅)

Colección genérica basada en tokens (usa `tokens.hpp`):
```
Coll<T> coll(char sep)              — Crear colección con separador
Coll<T> coll()                      — Crear colección (sep='|')
int collSize(Coll<T> c)
void collRemoveAll(Coll<T>& c)
void collRemoveAt(Coll<T>& c, int p)
int collAdd(Coll<T>& c, T t, string tToString(T))
void collSetAt(Coll<T>& c, T t, int p, string tToString(T))
T collGetAt(Coll<T> c, int p, T tFromString(string))
int collFind(Coll<T> c, K k, int cmpTK(T,K), T tFromString(string))
void collSort(Coll<T>& c, int cmpTT(T,T), T fFrom(string), string tTo(T))
bool collHasNext(Coll<T> c)
T collNext(Coll<T>& c, T tFromString(string))
T collNext(Coll<T>& c, bool& end, T tFromString(string))
void collReset(Coll<T>& c)
string collToString(Coll<T> c)
Coll<T> collFromString(string s)
```

Uso típico:
```cpp
Coll<int> c = coll<int>();
int pos = collAdd<int>(c, 42, intToString);
int val = collGetAt<int>(c, 0, stringToInt);
```

---

## Metodología para resolver un problema

Pasos establecidos en el curso (Apéndice 1 + Capítulo 4):

1. **Determinar datos de entrada, contexto y salida**
   - ¿Qué ingresa el usuario? ¿Qué archivos se leen?
   - ¿Hay datos de contexto (archivos de consulta)?
   - ¿Qué hay que mostrar o guardar?

2. **Clasificar el problema**
   - **Por multiplicidad**: registro único vs múltiples registros
   - **Por procesamiento**: vertical (un valor a la vez) vs horizontal (todo el conjunto)
   - **Por tipo**: corte de control, apareo de archivos, o procesamiento directo

3. **Diseñar el algoritmo**
   - Escribir la estrategia (máx 10 líneas, sin detalles técnicos)
   - Diagramar si es necesario
   - Codificar respetando la estructura del tipo de problema

4. **Probar el correcto funcionamiento**

### Identificación del tipo de problema

| Tipo | Cuándo aplica | Estructura |
|---|---|---|
| **Corte de control** | Archivo ordenado por clave; hay que informar por cada subconjunto | `while (!feof)` anidado con `while (clave == claveAnt)` |
| **Apareo de archivos** | Dos o más archivos ordenados por la misma clave | Leer ambos, comparar claves, avanzar el menor |
| **Procesamiento directo** | No entra en los dos anteriores | Solo `while (!feof)` simple |

### Archivos
- **Novedades/movimientos**: se procesan (una sola pasada)
- **Consulta**: se suben a memoria (si son chicos) o se indexan (si son grandes)

---

## Convenciones de rutas y directorio de trabajo

Al usar `fopen("ARCHIVO.dat", "r+b")`, la ruta es **relativa al directorio de trabajo** (CWD), no al `.cpp` ni al `exe`.

### Convención del curso
- Los `.dat` se colocan en la **raíz del proyecto** (`cpp-learning-path/`)
- Se compila y ejecuta **desde la raíz** del proyecto:

```bash
cd cpp-learning-path
g++ src/capitulo-04-problemas/ejercicio.cpp -I. -o ejercicio.exe
./ejercicio.exe        # fopen("CALIFICACIONES.dat") busca en cpp-learning-path/
```

### Alternativa (por lección)
Si se prefiere tener los `.dat` por lección:

```bash
cd src/capitulo-04-problemas
g++ ejercicio.cpp -I../.. -o ejercicio.exe
./ejercicio.exe        # fopen("CALIFICACIONES.dat") busca en capitulo-04-problemas/
```

**Regla**: siempre especificar el CWD en los comments o documentación de cada ejercicio.

---

## Reglas fundamentales

### ⚠️  No recorrer un archivo más de una vez
> *"De ningún modo aceptaremos recorrer un mismo archivo más de una vez. Sólo será válido en determinadas circunstancias, que por lo general estarán relacionadas con la actualización de los valores de sus campos."*

Si se necesita múltiple acceso a los datos de un archivo:
- **Archivo pequeño**: subirlo a memoria en un `Coll<T>` (colección)
- **Archivo grande**: indexarlo (crear un índice `{clave, posicion}` en un `Coll<Idx>`)

### ⚠️  No APT (A Prueba de Tontos)
> *"En este curso, siempre trabajaremos No APT. No validaremos ningún caso de error, salvo que el enunciado del ejercicio lo requiera explícitamente."*

- **No APT**: se asume que el usuario ingresa datos correctos (no validar)
- **APT**: validar todo (solo cuando el enunciado lo exige)

### ⚠️  Archivos de novedades vs consulta
- **Novedades/movimientos**: archivo que se procesa (se recorre una vez)
- **Consulta**: archivo que complementa datos (se sube a memoria o se indexa)

---

## Patrones clave del curso

### 1. TAD (Tipo Abstracto de Dato)

Cada TAD sigue este patrón:
```cpp
struct MiTAD {
    // campos que representan el estado
};

MiTAD miTAD(params)           // constructor/inicializador
string miTADToString(MiTAD x) // conversión a string
void miTADSetCampo(MiTAD& x, tipo val)  // setter (por referencia)
tipo miTADGetCampo(MiTAD x)             // getter (por valor)
```

Sobrecarga de `tToString` y `tFromString` para `Coll`:
```cpp
string intToString(int i) { return to_string(i); }
int intFromString(string s) { return stoi(s); }
string miTadToString(MiTAD t) { /* armar string con campos */ }
MiTAD miTadFromString(string s) { /* parsear string a campos */ }
```

### 2. Conversión TAD ↔ string (para Coll)

Toda estructura que se guarda en `Coll<T>` necesita dos funciones:
```cpp
string tToString(T t);    // serializar: struct → "campo1,campo2,..."
T tFromString(string s);  // deserializar: "campo1,campo2,..." → struct
```

### 3. Corte de control

Procesar archivo agrupado por clave:
```cpp
Registro r = read<Registro>(f);
while (!feof(f)) {
    int claveAnt = r.clave;
    int cont = 0, acum = 0;
    while (!feof(f) && claveAnt == r.clave) {
        // procesar registro
        cont++; acum += r.valor;
        r = read<Registro>(f);
    }
    // mostrar resultado del subconjunto
    double prom = acum / (double)cont;
    cout << claveAnt << ": " << prom << endl;
}
```

### 4. Corte de control con buffer

Si hay que ordenar/mostrar en orden diferente al del archivo:
```cpp
Coll<Registro> buff = coll<Registro>();
while (!feof(f) && claveAnt == r.clave) {
    if (r.calif >= 4) collAdd(buff, r, registroToString);
    r = read<Registro>(f);
}
collSort<Registro>(buff, cmpRegistro, registroFromString, registroToString);
collReset(buff);
while (collHasNext(buff)) { /* mostrar */ }
```

### 5. Descubrimiento

Mientras se recorren datos, si aparece una clave nueva se crea su estructura:
```cpp
int descubrir(Coll<Estad>& c, int id) {
    int pos = collFind<Estad,int>(c, id, cmpEstadId, estadFromString);
    if (pos < 0) {
        Estad x = {id, 0, 0};
        pos = collAdd<Estad>(c, x, estadToString);
    }
    return pos;
}
```

### 6. Apareo de archivos

Dos archivos ordenados por misma clave se recorren a la par:
```cpp
auto a = read<A>(fA), b = read<B>(fB);
while (!feof(fA) && !feof(fB)) {
    if (a.clave < b.clave) { /* solo en A */ a = read<A>(fA); }
    else if (a.clave == b.clave) { /* en ambos */ a = read<A>(fA); b = read<B>(fB); }
    else { /* solo en B */ b = read<B>(fB); }
}
```

### 7. Subir archivo a memoria (colección)
```cpp
Coll<Ciudad> subirCiudades() {
    Coll<Ciudad> c = coll<Ciudad>();
    FILE* f = fopen("CIUDADES.dat", "r+b");
    Ciudad r = read<Ciudad>(f);
    while (!feof(f)) {
        collAdd<Ciudad>(c, r, ciudadToString);
        r = read<Ciudad>(f);
    }
    fclose(f);
    return c;
}
```

### 8. Indexación de archivos

Para archivos grandes no ordenados por clave de búsqueda:
```cpp
struct AbonadoIdx { int idAbo; int pos; };
Coll<AbonadoIdx> idx = indexarAbonados(f);
// luego buscar: collFind<AbonadoIdx,int>(idx, id, cmpAbonadoIdxId, fromString)
```

---

## Restricciones del lenguaje (solo lo que está en el libro)

El libro solo enseña y permite un subconjunto específico de C++. **Todo lo que no aparezca en el libro o en la API del curso está prohibido.**

### ✅ Permitido (enunciados + código del libro)
- `#include <iostream>` → `cin`, `cout`, `endl`
- `#include <string>` → tipo `std::string`
- `#include <stdio.h>` → `FILE*`, `fopen`, `fread`, `fwrite`, `fclose` (solo si usás archivos)
- `#include <string.h>` → `strlen`, `strcmp` (solo para funciones internas de la API)
- `#include <math.h>` → `pow` (para ejercicios puntuales)
- `#include <stdlib.h>` → funciones de Array TAD (malloc, free)
- `#include <chrono>` → millis.hpp internamente
- Structs para modelar datos
- Funciones (los ejercicios se resuelven con funciones, no clases)
- Templates (Coll los usa internamente — se pueden usar para el TAD Coll)
- Punteros (para archivos, arrays dinámicos, listas enlazadas)
- La API completa del curso (strings, tokens, files, Coll, etc.)

### ❌ Prohibido (no está en el libro, no se puede usar)
- **STL Containers**: `std::vector`, `std::map`, `std::set`, `std::list`, `std::deque`, `std::stack`, `std::queue`, etc.
- **STL Algorithms**: `std::sort`, `std::find`, `std::copy`, etc.
- **Smart pointers**: `std::unique_ptr`, `std::shared_ptr`
- **Cualquier #include que no esté en la lista de permitidos**
- **Bibliotecas externas** (Boost, fmt, range-v3, etc.)
- **Clases con herencia/polimorfismo** (el libro no llega a eso)
- **Lambdas**, **excepciones**, **move semantics**, **auto** (no enseñados)
- **Literales string** como `"texto"s` (requiere `using namespace std::string_literals`)

### Filosofía
El curso enseña a implementar todo desde cero usando tipos básicos.  
Si no está en el libro → no se usa. Se reemplaza con la API equivalente del curso:
| STL | Curso |
|---|---|
| `std::sort(vec)` | `collSort<...>(coll, cmp)` |
| `std::find(vec, x)` | `collFind<...>(coll, x, cmp)` |
| `std::vector<int>` | `Coll<int>` |
| `std::map<K,V>` | `Coll<struct{ K; V; }>` + búsqueda |
| `std::string::find` | `indexOf(s, sub)` |
| `std::string::substr` | `substring(s, d, h)` |

---

## Cómo compilar

```bash
# Sin biblioteca
g++ src/leccion-01-basicos/ejercicio.cpp -o ejercicio.exe

# Con biblioteca (usando principal.hpp)
g++ src/leccion-03-tads/ejercicio.cpp -I. -o ejercicio.exe

# La flag -I. permite #include "principal.hpp"
```

El `principal.hpp` incluye toda la biblioteca. Los .cpp solo necesitan:
```cpp
#include "principal.hpp"
using namespace std;
```

Para probar algo rápido desde la raíz:
```bash
g++ principal.cpp -I. -o principal.exe && principal.exe
```

---

## Estado de implementación

| Archivo | Estado | Ubicación |
|---|---|---|
| `strings.hpp` | ✅ Completo | `lib/funciones/strings.hpp` |
| `tokens.hpp` | ✅ Completo | `lib/funciones/tokens.hpp` |
| `millis.hpp` | ✅ Completo | `lib/funciones/millis.hpp` |
| `Coll.hpp` (funciones) | ✅ Completo | `lib/funciones/Coll.hpp` |
| `Coll.hpp` (parte1) | ✅ Completo | `lib/tads/parte1/Coll.hpp` |
| `Fraccion.hpp` | ✅ Completo (referencia) | `lib/tads/intro/Fraccion.hpp` |
| `files.hpp` | 🚧 Esqueleto vacío | `lib/funciones/files.hpp` |
| `arrays.hpp` | 🚧 Esqueleto vacío | `lib/funciones/arrays.hpp` |
| `lists.hpp` | 🚧 Esqueleto vacío | `lib/funciones/lists.hpp` |
| `Fecha.hpp` | 🚧 Esqueleto vacío | `lib/tads/parte1/Fecha.hpp` |
| `Timer.hpp` | 🚧 Esqueleto vacío | `lib/tads/parte1/Timer.hpp` |
| `MultidimColl.hpp` | 🚧 Esqueleto vacío | `lib/tads/parte1/MultidimColl.hpp` |
| `Array.hpp` (TAD) | 🚧 Esqueleto vacío | `lib/tads/parte2/Array.hpp` |
| `List.hpp` (TAD) | 🚧 Esqueleto vacío | `lib/tads/parte2/List.hpp` |
| `Map.hpp` | 🚧 Esqueleto vacío | `lib/tads/parte2/Map.hpp` |
| `Queue.hpp` | 🚧 Esqueleto vacío | `lib/tads/parte2/Queue.hpp` |
| `Stack.hpp` | 🚧 Esqueleto vacío | `lib/tads/parte2/Stack.hpp` |
