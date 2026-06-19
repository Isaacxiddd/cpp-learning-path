# Roadmap de Promoción — Algoritmos y Programación A Fondo

**Objetivo:** Promocionar la materia y preparar estudiantes hasta el parcial  
**Alcance:** Capítulo 4 + Lección 10 (Coll/tadcoll)  
**Profesor:** Pablo A. Sznajdleder  
**Criterio:** Dominio de técnicas de resolución de problemas

---

## 1. Estructura de la materia hasta el parcial

### Bloques de contenido

```
BLOQUE 1: FUNDAMENTOS (Lecciones 1-3)
├─ Lección 1: Operaciones, condicionales, loops
├─ Lección 2: Funciones (modulización)
└─ Lección 3: TADs (Fracción, Fecha, Timer)

BLOQUE 2: APIs EDUCATIVAS (Lecciones 4-7)
├─ Lección 4: API Strings
├─ Lección 5: API Tokens
├─ Lección 6/7: API Coll (Colecciones)
└─ (Lección 8-9: no entran en el parcial)

BLOQUE 3: RESOLUCIÓN DE PROBLEMAS (Capítulo 4)
├─ 4.1: Análisis de problemas
├─ 4.2: Tipos de problemas
│   ├─ Corte de control simple
│   ├─ Corte de control con buffer
│   └─ Apareo de archivos (versiones 3+)
└─ 4.3-4.5: 15 versiones del caso testigo
```

---

## 2. Contenidos específicos por lección

### Lección 1: Operaciones aritméticas y control de flujo

**Qué entra:**
- Operaciones básicas (+, -, *, /, %)
- Condicionales (if/else, switch)
- Loops (while, for)
- Conteo y acumulación

**Ejercicios clave:**
- 1.2.6: Mayor, medio y menor entre tres números
- 1.2.10: Fecha más próxima
- 1.2.12-1.2.20: Factorial, primos, Fibonacci, fracciones
- 1.2.21-1.2.32: Conteo, promedios, conjuntos, palabras

**Criterio Sznajdleder:**
> "No solo resolver el problema, sino entender **por qué** esa solución es correcta. El algoritmo debe ser legible y eficiente."

---

### Lección 2: Funciones (Modulización)

**Qué entra:**
- Declaración y definición de funciones
- Parámetros por valor y referencia
- Reutilización mediante funciones

**Ejercicios clave:**
- 1.3.1: Función factorial (generalizar de 1.2.13)
- 1.3.3: Función esPrimo (generalizar de 1.2.14)
- 1.3.4: Primeros n números primos
- 1.3.5-1.3.6: Funciones Fibonacci

**Criterio Sznajdleder:**
> "Las funciones no son solo para reutilizar código: son para **encapsular lógica** y hacer el código legible. Si una función hace más de una cosa, divídela."

---

### Lección 3: Tipos Abstractos de Datos (TADs)

**Qué entra:**
- Struct como agrupación de datos
- Funciones asociadas a structs (patrón C)
- TAD Fracción (modelo de referencia)
- TAD Fecha (implementar)
- TAD Timer (implementar)

**Ejercicios clave:**
- 1.4.1: TAD Fracción — suma, simplificar, comparar
- 1.4.2: TAD Fecha — crear, comparar, diferencia de días
- 1.4.3: TAD Timer — medir tiempos, lap, reset

**Criterio Sznajdleder:**
> "Un TAD encapsula datos + operaciones. La estructura interna es privada; el usuario solo ve la interfaz pública (funciones). Esto es el inicio de la abstracción."

---

### Lección 4: API Strings

**Qué entra:**
- Funciones para manipular strings
- Búsqueda (contains, indexOf)
- Transformación (toUpper, toLower, trim)
- Partición (substring, split — simple)

**Funciones principales:**
```
strContains(s, substr)       // ¿Contiene substring?
strIndexOf(s, substr)        // Posición del primer match
strToUpper(s)                // Mayúsculas
strToLower(s)                // Minúsculas
strTrim(s)                   // Eliminar espacios
strSubstring(s, inicio, len) // Extraer porción
```

**Criterio Sznajdleder:**
> "Estas funciones no son 'mágicas': cada una recorre el string carácter a carácter. Entender la implementación es clave para resolver problemas reales."

---

### Lección 5: API Tokens

**Qué entra:**
- Separar un string en tokens por delimitador
- Procesar cada token como unidad

**Función principal:**
```cpp
int tokenize(string texto, string separador, vector<string>& tokens);
```

**Ejemplo:**
```cpp
string texto = "Juan,30,Buenos Aires";
vector<string> tokens;
int n = tokenize(texto, ",", tokens);  // n=3
// tokens[0]="Juan", tokens[1]="30", tokens[2]="Buenos Aires"
```

**Criterio Sznajdleder:**
> "Los tokens son la base para **procesar archivos de registros**. Cada línea de un archivo CSV es un string; los tokens son sus campos."

---

### Lección 6/7: API Coll (Colecciones)

**Qué entra:**
- TAD Coll: colección genérica (template)
- Inserción, búsqueda, eliminación
- Iteración
- Ordenamiento

**Funciones principales:**
```cpp
Coll<T> coll_new();
void coll_add(Coll<T>& c, T t);
T coll_get(Coll<T>& c, int idx);
bool coll_contains(Coll<T>& c, T t);
void coll_sort(Coll<T>& c);
int coll_size(Coll<T>& c);
```

**Usos:**
- Guardar múltiples registros en memoria
- Ordenarlos
- Buscarlos

**Criterio Sznajdleder:**
> "Coll es tu **base de datos en memoria**. Cuando no quieres trabajar con archivos o necesitas operaciones complejas, coll es tu herramienta. Así introducimos estructuras de datos."

---

### Capítulo 4: Resolución de Problemas Integradores

**Qué entra:**

#### 4.1: Análisis de problemas
- Identificar datos de entrada/salida
- Archivos de novedades vs. archivos de consulta
- Estrategia antes de codificar

#### 4.2: Tipos de problemas

**A) Corte de control simple**
- Datos ordenados por un campo
- Reportar resultados por grupos
- Ejemplo: consumo por abonado

**B) Corte de control con buffer**
- Información adicional necesaria
- Guardar contexto entre registros

**C) Apareo de archivos** (versiones 3+)
- Combinar datos de múltiples archivos
- Algoritmo merge similar a merge-sort

---

## 3. Plan de estudio sugerido (Sznajdleder)

### Semana 1-2: Fundamentos (Lecciones 1-3)

**Objetivo:** Dominar control de flujo y TADs básicos

```
Día 1: Lección 1 (ejercicios 1.2.1 a 1.2.10)
Día 2: Lección 1 (ejercicios 1.2.11 a 1.2.32)
Día 3: Lección 2 (ejercicios 1.3.1 a 1.3.6)
Día 4: Lección 3 (TAD Fracción — análisis)
Día 5: Lección 3 (TAD Fecha — implementación)
Día 6: Lección 3 (TAD Timer — implementación)
Día 7: Repaso + ejercicios combinados
```

**Evaluación:** Quiz 1 — Escribir una función que resuelva un problema de control de flujo

---

### Semana 3-4: APIs Educativas (Lecciones 4-7)

**Objetivo:** Dominar manipulación de strings, tokens y colecciones

```
Día 8: Lección 4 (API Strings — búsqueda y transformación)
Día 9: Lección 4 (Ejercicios con strings)
Día 10: Lección 5 (API Tokens — separar, procesar)
Día 11: Lección 5 (Ejercicios con tokens)
Día 12: Lección 6/7 (Coll — estructura y operaciones)
Día 13: Lección 6/7 (Coll + ordenamiento)
Día 14: Repaso + integradores
```

**Evaluación:** Quiz 2 — Procesar un archivo de texto (strings + tokens + Coll)

---

### Semana 5-6: Capítulo 4 (Resolución de Problemas)

**Objetivo:** Dominar corte de control y apareo

```
Día 15: 4.1 Análisis de problemas (metodología)
Día 16: 4.2.1 Corte de control simple (Versiones 1-2)
Día 17: 4.2.2 Corte de control + buffer (Versión 2)
Día 18: 4.2.3 Apareo de archivos (Versión 3)
Día 19: Apareo avanzado (Versión 4+)
Día 20: Caso de estudio completo (Versión 15)
Día 21: Repaso general
```

**Evaluación:** Examen parcial — Resolver problema tipo (similar a versiones 2-3 del caso testigo)

---

## 4. Temas clave para el parcial

### Obligatorios

- [ ] Corte de control (identificar, implementar, debuggear)
- [ ] Apareo de archivos (merge, búsqueda)
- [ ] Lectura de archivos binarios (fopen, read, seek, fileSize)
- [ ] API Strings (búsqueda, transformación)
- [ ] API Tokens (separación, procesamiento)
- [ ] API Coll (inserción, búsqueda, ordenamiento)

### Muy importantes

- [ ] TAD Fecha (crear, comparar, diferencias)
- [ ] TAD Fracción (suma, simplificar)
- [ ] Funciones genéricas (templates)
- [ ] Estrategia antes de código

### Complementarios

- [ ] TAD Timer (medir tiempos)
- [ ] Archivos de texto (readLine, readWord)
- [ ] Bit Writer/Reader (opcional, avanzado)

---

## 5. Estrategia de promoción

### Para atraer estudiantes

**Mensaje central:**
> "No solo aprendes C++. Aprendes a resolver problemas reales: procesar archivos de reservas, analizar datos, implementar algoritmos eficientes. Todo desde cero, con criterio profesional."

### Por plataforma

**GitHub:** Repositorio público con:
- README claro
- Ejemplos resueltos
- Estructura documentada

**TiddlyWiki:** Ejercicios interactivos que varían cada vez (generador)

**Obsidian/Notas:** Guías conceptuales (como esta)

**Social (si aplica):** 
- "Ejercicio del día" — problemas progresivos
- Antes/después: código sin estructura vs. código con TADs

---

## 6. Criterio Sznajdleder resumido

### Principios fundamentales

1. **Entender antes de codificar**
   - Leer 3 veces el enunciado
   - Identificar datos, procesos, resultados
   - Escribir estrategia (en papel, sin código)

2. **Código legible > Código corto**
   - Nombres claros para variables
   - Funciones pequeñas y bien documentadas
   - Indentación consistente

3. **Reutilización mediante abstracción**
   - Funciones genéricas (templates)
   - TADs encapsulan lógica
   - APIs reducen complejidad

4. **Eficiencia con propósito**
   - Un algoritmo O(n²) es aceptable si n es pequeño
   - Un O(n) es necesario si n es grande (millones)
   - La claridad supera microoptimizaciones

5. **Archivos y persistencia**
   - Archivos binarios para velocidad
   - Archivos de novedades vs. consulta
   - Corte de control para reportes

---

## 7. Recursos de estudio

| Tipo | Descripción | Ubicación |
|------|-------------|-----------|
| **Apéndice 1** | Enunciados detallados de ejercicios 1.2.1-1.2.32 | `docs/apendice-01-ejercicios.md` |
| **Apéndice 2** | Especificaciones y API (Fracción, Fecha, Strings, Tokens, Coll, Files) | `docs/apendice-02-api.md` |
| **Capítulo 4** | Técnicas de resolución (corte de control, apareo) | `docs/capitulo-04-resolucion.md` |
| **Ejemplos resueltos** | TAD Fracción, ejercicios 1.2.11-1.2.20 | `src/leccion-01-basicos/` |
| **Referencia FILE I/O** | Guía completa (este documento) | `docs/file-io-guia.md` |

---

## 8. Checklist para estudiante

Antes del parcial, debes poder:

- [ ] Resolver un problema de corte de control en 30 min
- [ ] Implementar un apareo de 2 archivos en 45 min
- [ ] Escribir una función que procese un Coll<T>
- [ ] Debuggear un problema de lectura de archivos
- [ ] Explicar por qué tu solución es O(n) o O(n²)
- [ ] Escribir código que otro lea sin preguntas

---

## Resumen: Promoción del curso

**Para estudiantes:**
> "Aprendes C++ profesional, no trucos de lenguaje. Cada concepto tiene una razón. Resolverás problemas reales con datos persistentes, archivos y algoritmos."

**Para profesores/coordinadores:**
> "Curso acreditado por Sznajdleder. Cobertura completa de estructuras de datos, APIs educativas, técnicas de resolución. Preparación integral para programación moderna."

**Para empresas:**
> "Egresados con capacidad de análisis, modularización y resolución de problemas escalables. Base sólida para cualquier lenguaje o framework."
