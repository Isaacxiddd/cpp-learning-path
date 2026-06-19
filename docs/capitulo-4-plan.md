# Capítulo 4: Cómo resolver problemas integradores

**Criterio:** Metodología Sznajdleder  
**Objetivo:** Dominar corte de control y apareo de archivos  
**Aplicación:** Ejercicios del Capítulo 4 (15 versiones del caso testigo)

---

## 1. Metodología: Antes de escribir código

### PASO 1: Lee el enunciado 3 veces

**Primera lectura:** General
- ¿Cuál es el contexto? (compañía aérea, banco, torneo)
- ¿Qué datos tengo? (archivos, tipos de registros)
- ¿Qué debo entregar?

**Segunda lectura:** Detallada
- ¿Cuántos archivos entran?
- ¿En qué orden están los datos?
- ¿Necesito procesar todo o datos específicos?

**Tercera lectura:** Crítica
- ¿Hay condiciones especiales?
- ¿Qué pasa si hay datos vacíos o malformados?
- ¿El enunciado tiene ambigüedades?

### PASO 2: Identifica entrada, salida, proceso

```
┌─────────────┬──────────────────┬──────────────┐
│   ENTRADA   │    PROCESO       │    SALIDA    │
├─────────────┼──────────────────┼──────────────┤
│ Archivo de  │ Procesar por     │ Reporte con  │
│ LLAMADAS    │ corte de control │ consumo por  │
│ ordenado    │ (agrupar por     │ abonado      │
│ por idAbono │ idAbonado)       │              │
└─────────────┴──────────────────┴──────────────┘
```

### PASO 3: Clasifica el tipo de problema

#### ¿Es un problema de **CORTE DE CONTROL**?

```cpp
// Signos de alerta:
// - "por cada..." (por cada cliente, por cada mes)
// - Datos ordenados por un campo
// - Reportes subtotales
// - Hay un archivo principal que procesas
```

**Ejemplo:**
```
"Se tiene un archivo LLAMADAS ordenado por idAbonado.
 Generar un reporte con el consumo total por abonado."
```

#### ¿Es un problema de **APAREO**?

```cpp
// Signos de alerta:
// - Dos o más archivos
// - Necesitas combinar datos
// - "Buscar en consulta"
// - "Completar con información de otro archivo"
```

**Ejemplo:**
```
"Se tiene archivo RESERVAS y archivo CLIENTES.
 Para cada reserva, mostrar nombre y DNI del cliente."
```

#### ¿Es **PROCESAMIENTO DIRECTO**?

```cpp
// Signos:
// - No hay agrupación
// - No hay múltiples archivos
// - "Listar", "contar", "sumar"
```

**Ejemplo:**
```
"Contar cuántos registros en CLIENTES viven en Buenos Aires."
```

---

## 2. Técnica 1: Corte de Control Simple

### Definición

Procesar un archivo **ordenado por un campo** y generar reportes **por grupo**.

### Estructura base (Sznajdleder)

```cpp
#include "principal.hpp"

int main() {
    FILE* f = fopen("archivo.x", "r+b");
    
    // 1. INICIALIZACIÓN
    int totalRegistros = fileSize<TuStruct>(f);
    TuStruct registro_anterior = /* valor inicial */;
    int acumulador = 0;  // o lo que necesites
    
    // 2. LECTURA Y PROCESAMIENTO
    for (int i = 0; i < totalRegistros; i++) {
        TuStruct registro = read<TuStruct>(f);
        
        // 3. CORTE: ¿Cambió el valor de agrupación?
        if (/* fue la primera lectura */ || 
            registro.campoAgrupacion != registro_anterior.campoAgrupacion) {
            
            // 4a. REPORTAR grupo anterior (si no es primera iteración)
            if (i > 0) {
                cout << "Grupo " << registro_anterior.campoAgrupacion 
                     << ": " << acumulador << endl;
            }
            
            // 4b. RESETEAR
            acumulador = 0;
            registro_anterior = registro;
        }
        
        // 5. ACUMULAR
        acumulador += registro.valor;
    }
    
    // 6. ÚLTIMO GRUPO
    if (totalRegistros > 0) {
        cout << "Grupo " << registro_anterior.campoAgrupacion 
             << ": " << acumulador << endl;
    }
    
    fclose(f);
    return 0;
}
```

### Caso de estudio: Llamadas por abonado

**Enunciado:**
> Se tiene un archivo `LLAMADAS.x` con registros ordenados por `idAbonado`. 
> Generar reporte: para cada abonado, mostrar consumo total en segundos.

**Estructura:**
```cpp
struct Llamada {
    int idAbonado;      // Campo de agrupación
    long long fechaHora;
    int duracion;       // Campo a acumular
    char nroDestino[30];
};
```

**Solución (versión 1 del caso testigo):**

```cpp
#include "principal.hpp"

int main() {
    FILE* f = fopen("LLAMADAS.x", "r+b");
    if (!f) {
        cout << "Error: archivo no existe" << endl;
        return 1;
    }
    
    int totalLlamadas = fileSize<Llamada>(f);
    
    Llamada llamada;
    int abonado_anterior = -1;
    int consumoAbonado = 0;
    
    for (int i = 0; i < totalLlamadas; i++) {
        llamada = read<Llamada>(f);
        
        // ¿Cambió el abonado?
        if (abonado_anterior != -1 && 
            llamada.idAbonado != abonado_anterior) {
            
            // Reportar abonado anterior
            cout << "Abonado " << abonado_anterior 
                 << ": " << consumoAbonado << "s" << endl;
            
            // Resetear acumulador
            consumoAbonado = 0;
        }
        
        // Acumular duración
        consumoAbonado += llamada.duracion;
        abonado_anterior = llamada.idAbonado;
    }
    
    // Último abonado
    if (totalLlamadas > 0) {
        cout << "Abonado " << abonado_anterior 
             << ": " << consumoAbonado << "s" << endl;
    }
    
    fclose(f);
    return 0;
}
```

**Output esperado:**
```
Abonado 1001: 1250s
Abonado 1002: 890s
Abonado 1003: 2145s
...
```

---

## 3. Técnica 2: Corte de Control con Buffer

### Problema: Necesito información adicional

**Enunciado extendido:**
> Se tienen archivos:
> - `LLAMADAS.x`: llamadas ordenadas por idAbonado
> - `ABONADOS.x`: datos de abonados (nombre, plan, etc.)
> 
> Mostrar: "Abonado [nombre]: [consumo] segundos"

**Problema:** No tengo el nombre en el archivo LLAMADAS, está en ABONADOS.

### Solución: Guardar contexto en una estructura

```cpp
struct ContextoAbonado {
    int idAbonado;
    string nombre;
    int consumoTotal;
};

int main() {
    FILE* fLlamadas = fopen("LLAMADAS.x", "r+b");
    FILE* fAbonados = fopen("ABONADOS.x", "r+b");
    
    // Cargar ABONADOS en memoria (apareo simple)
    Coll<Abonado> abonados;
    int totalAbonados = fileSize<Abonado>(fAbonados);
    for (int i = 0; i < totalAbonados; i++) {
        Abonado a = read<Abonado>(fAbonados);
        coll_add(abonados, a);
    }
    fclose(fAbonados);
    
    // Procesar LLAMADAS con corte de control
    int totalLlamadas = fileSize<Llamada>(fLlamadas);
    
    Llamada llamada;
    ContextoAbonado contexto = {-1, "", 0};
    
    for (int i = 0; i < totalLlamadas; i++) {
        llamada = read<Llamada>(fLlamadas);
        
        // ¿Cambió el abonado?
        if (contexto.idAbonado != -1 && 
            llamada.idAbonado != contexto.idAbonado) {
            
            // Reportar
            cout << "Abonado " << contexto.nombre 
                 << ": " << contexto.consumoTotal << "s" << endl;
            
            // Resetear
            contexto.consumoTotal = 0;
        }
        
        // ¿Debo buscar el nombre (cambio de abonado)?
        if (llamada.idAbonado != contexto.idAbonado) {
            // Buscar en ABONADOS
            Abonado* a = buscar_por_id(abonados, llamada.idAbonado);
            contexto.idAbonado = llamada.idAbonado;
            contexto.nombre = a->nombre;
        }
        
        // Acumular
        contexto.consumoTotal += llamada.duracion;
    }
    
    // Último
    if (totalLlamadas > 0) {
        cout << "Abonado " << contexto.nombre 
             << ": " << contexto.consumoTotal << "s" << endl;
    }
    
    fclose(fLlamadas);
    return 0;
}
```

**Key insight:** El **contexto** guarda los datos que necesito del grupo actual. Solo busco en ABONADOS cuando cambia el grupo.

---

## 4. Técnica 3: Apareo de Archivos

### Definición

Procesar dos archivos **ordenados por el mismo campo** y combinar información.

### Algoritmo (similar a merge-sort)

```
Abrir ambos archivos
Leer primer registro de cada uno

MIENTRAS (queden registros en al menos uno):
    
    SI archivo1.id < archivo2.id:
        Procesar archivo1 sin match
        Avanzar archivo1
    
    SINO SI archivo1.id > archivo2.id:
        Procesar archivo2 sin match
        Avanzar archivo2
    
    SINO (son iguales):
        Procesar MATCH (combinar datos)
        Avanzar ambos
```

### Caso práctico: Ventas vs. Devoluciones

**Archivos:**
```
VENTAS.x:      Ordenado por idProducto
DEVOLUCIONES.x: Ordenado por idProducto

Cada producto puede aparecer en:
- Solo VENTAS (se vendió, no se devolvió)
- Solo DEVOLUCIONES (se devolvió algo que no estaba registrado)
- En ambos (hay ventas y devoluciones)
```

**Objetivo:** Reporte completo con ventas netas.

```cpp
#include "principal.hpp"

struct Venta {
    int idProducto;
    int cantidad;
    float precio;
};

struct Devolucion {
    int idProducto;
    int cantidad;
};

int main() {
    FILE* fVentas = fopen("VENTAS.x", "r+b");
    FILE* fDevoluciones = fopen("DEVOLUCIONES.x", "r+b");
    
    int totalVentas = fileSize<Venta>(fVentas);
    int totalDevoluciones = fileSize<Devolucion>(fDevoluciones);
    
    Venta venta;
    Devolucion devolucion;
    
    int i = 0, j = 0;
    
    // Leer primeros registros
    if (i < totalVentas) venta = read<Venta>(fVentas);
    if (j < totalDevoluciones) devolucion = read<Devolucion>(fDevoluciones);
    
    // APAREO
    while (i < totalVentas || j < totalDevoluciones) {
        
        if (i >= totalVentas) {
            // Solo quedan devoluciones
            cout << "Devolucion no vendida: " << devolucion.idProducto 
                 << " (" << devolucion.cantidad << ")" << endl;
            j++;
            if (j < totalDevoluciones) 
                devolucion = read<Devolucion>(fDevoluciones);
        }
        else if (j >= totalDevoluciones) {
            // Solo quedan ventas
            cout << "Venta sin devolución: " << venta.idProducto 
                 << " (" << venta.cantidad << ")" << endl;
            i++;
            if (i < totalVentas) 
                venta = read<Venta>(fVentas);
        }
        else if (venta.idProducto < devolucion.idProducto) {
            // Venta sin devolución
            cout << "Venta neta: " << venta.idProducto 
                 << " (" << venta.cantidad << ")" << endl;
            i++;
            if (i < totalVentas) 
                venta = read<Venta>(fVentas);
        }
        else if (venta.idProducto > devolucion.idProducto) {
            // Devolución sin venta
            cout << "Devolucion no vendida: " << devolucion.idProducto 
                 << " (" << devolucion.cantidad << ")" << endl;
            j++;
            if (j < totalDevoluciones) 
                devolucion = read<Devolucion>(fDevoluciones);
        }
        else {
            // MATCH: mismo producto
            int neto = venta.cantidad - devolucion.cantidad;
            cout << "Neto: " << venta.idProducto 
                 << " (" << neto << ")" << endl;
            i++;
            j++;
            if (i < totalVentas) 
                venta = read<Venta>(fVentas);
            if (j < totalDevoluciones) 
                devolucion = read<Devolucion>(fDevoluciones);
        }
    }
    
    fclose(fVentas);
    fclose(fDevoluciones);
    return 0;
}
```

---

## 5. Checklist: Antes de correr el programa

- [ ] ¿Validé que los archivos existen?
- [ ] ¿Los archivos están ordenados por el campo correcto?
- [ ] ¿Manejé el primer/último registro correctamente?
- [ ] ¿Mi acumulador se resetea en el lugar correcto?
- [ ] ¿Mi criterio de comparación (==, <, >) es el correcto?
- [ ] ¿Probé con archivos vacíos?
- [ ] ¿Probé con un solo registro?
- [ ] ¿Probé con varios grupos?

---

## 6. Errores comunes

### Error 1: No resetear el acumulador

```cpp
// ❌ MAL
if (cambio_grupo) {
    reportar();
    // ¡OLVIDE resetear acumulador!
}
```

```cpp
// ✅ BIEN
if (cambio_grupo) {
    reportar();
    acumulador = 0;  // AQUÍ
}
```

---

### Error 2: Comparar mal el cambio de grupo

```cpp
// ❌ INCORRECTO: solo verifica si es primer registro
if (i == 0) { /* nuevo grupo */ }

// ✅ CORRECTO: verifica si cambió el valor de agrupación
if (registro.idAbonado != anterior_id) { /* nuevo grupo */ }
```

---

### Error 3: Perder el último grupo

```cpp
// ❌ INCORRECTO: el último grupo solo se reporta si hay otro después
for (int i = 0; i < total; i++) {
    if (cambio_grupo) {
        reportar(); // nunca se ejecuta después del loop
    }
}

// ✅ CORRECTO: reportar después del loop
for (int i = 0; i < total; i++) {
    if (cambio_grupo) reportar();
}
// IMPORTANTE: reportar el último grupo aquí
reportar_ultimo();
```

---

### Error 4: Apareo sin verificar bounds

```cpp
// ❌ INCORRECTO: intento leer cuando i >= totalVentas
while (i < totalVentas) {
    venta = read<Venta>(fVentas);  // puede fallar si i es gran index
}

// ✅ CORRECTO: verificar antes de leer
while (i < totalVentas || j < totalDevoluciones) {
    if (i < totalVentas) {
        venta = read<Venta>(fVentas);
    } else {
        // solo procesar devoluciones
    }
}
```

---

## 7. Versiones del caso testigo (resumen)

| Versión | Técnica | Complejidad | Concepto clave |
|---------|---------|-------------|---|
| 1 | Corte simple | Básica | Agrupación, acumulación |
| 2 | Corte + buffer | Media | Contexto, búsqueda |
| 3 | Apareo | Media | Merge, comparación |
| 4-7 | Apareo avanzado | Media-Alta | Múltiples archivos |
| 8-15 | Integradores | Alta | Combinación de técnicas |

**Para el parcial:** Dominar versiones 1-3 garantiza puntaje alto.

---

## 8. Consejo final de Sznajdleder

> "Antes de escribir una línea de código, dibuja el flujo del programa en papel. 
> ¿Qué pasa en cada iteración del loop? ¿Qué variables cambian? ¿Cuándo reporto?
> 
> El código viene después. La lógica, primero."

---

## Recursos

- Apéndice 2: Especificaciones de FILE I/O
- Capítulo 4: Enunciados completos (15 versiones)
- file-io-guia.md: Referencia de funciones
- Ejemplo resuelto: Versión 1 (arriba)
