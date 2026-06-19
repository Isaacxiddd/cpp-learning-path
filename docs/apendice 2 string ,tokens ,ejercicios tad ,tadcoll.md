## APÉNDICE 2 ESPECIFICACIONES Y API 

## 1.1. Lección 3 

## 1.1.1. Introducción 

La presente guía de Especificaciones y API describe un conjunto de Tipos Abstractos de Datos (TAD) y bibliotecas que el estudiante deberá implementar a lo largo de todo el curso de algoritmos. 

Estos TAD y bibliotecas forman parte del proyecto `AlgoritmosAFondo_EMPTY` , o proyecto AAFE, el cual se entrega como base de trabajo. En dicho proyecto, las estructuras y fun- _Cómo trabajar con_ ciones de los TAD y las bibliotecas ya se encuentran definidas, _este documento_ pero sus implementaciones están vacías. Es decir, el estudiante dispone de los esqueletos de código necesarios, y su tarea consiste en completar cada una de las funciones siguiendo las especificaciones detalladas en este documento. 

Así, esta guía indica qué debe hacerse, mientras que el proyecto AAFE proporciona el lugar donde hacerlo. El aprendizaje se construye a partir de la implementación progresiva de cada TAD y biblioteca, respetando las definiciones dadas. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

2 |[Apéndice 2 ● Especificaciones y API] 

A modo de ejemplo, se incluye un TAD completamente resuelto: el TAD `Fraccion` , que representa a los números fraccionarios. A diferencia del resto, este TAD está completamente implementado. Su objetivo es servir como modelo de referencia, permitiendo observar cómo se traduce una especificación en código concreto, cómo se organiza su implementación y cuál será nuestra mecánica de trabajo de aquí en adelante. 

En síntesis: 

- Este documento indica qué hacer. 

- El proyecto `AlgoritmosAFondo_EMPTY` es dónde lo haremos. 

- El TAD `Fraccion` muestra cómo hacerlo. 

- El estudiante debe implementar el resto de las bibliotecas y TAD. 

## 1.1.1.1. Importar el proyecto en Visual Studio Code 

Para importar el proyecto en en Visual Studio Code (la herramienta de trabajo), seguiremos los siguientes pasos: 

1. Descargar el proyecto `AlgoritmosAFondo_EMPTY_v` _X.X.XX_ `.zip` , donde _X.X.XX_ representa la versión actual del archivo (descargar archivo). 

2. Extraer el contenido del `zip` en la carpeta `C:\vscode\Workspace` (asumiendo que `vscode` se encuentra en la unidad de disco `C:` ). 

3. En Visual Studio Code, seleccionar el menú: _File_ → _Add Folder To Workspace_ → _Doble Click_ en la carpeta `AlgoritmosAFondo_EMPTY_v` _X.X.XX_ → presionar el botón _Add_ . 

A partir de aqui, cada vez que hagamos referencia al proyecto lo haremos como: `AlgoritmosAFondo_EMPTY` , omitiendo su versión, o por su acrónimo: AAFE. 

## 1.1.1.2. Ubicar el TAD Fraccion dentro del proyecto 

El TAD `Fraccion` se encuentra en el archivo `Fraccion.hpp` . Para ubicarlo, luego de haber importado el proyecto en Visual Studio Code, hacemos: _click_ sobre el proyecto _AlgoritmosAFondo_EMPTY_ → _biblioteca_ → _intro_ → _doble click_ en `Fraccion.hpp` . 

Veremos el siguiente código, que incluye la estructura del TAD (vacía) y los esqueletos de todas sus funciones: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 3 

```
#ifndef _TFRACCION_T_
#define _TFRACCION_T_
#include <iostream>
using std::string;
using std::to_string;
struct Fraccion
{
   // declara aqui los campos o atributos que
   // consideres necesarios para describir una fraccion
};
Fraccion fraccion(int n,int d)
{
   // implementacion pendiente...
   Fraccion ret;
return ret;
}
string fraccionToString(Fraccion f)
{
   // implementacion pendiente...
return "";
}
Fraccion fraccionSumar(Fraccion a,Fraccion b)
{
   // implementacion pendiente...
   Fraccion ret;
return ret;
}
Fraccion fraccionSimplificar(Fraccion f)
{
   // implementacion pendiente...
   Fraccion ret;
return ret;
}
bool fraccionEsEntera(Fraccion f)
{
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

4 |[Apéndice 2 ● Especificaciones y API] 

```
   // implementacion pendiente...
return false;
}
int fraccionGetNumerador(Fraccion f)
{
   // implementacion pendiente...
return 0;
}
void fraccionSetNumerador(Fraccion& f,int n)
{
   // implementacion pendiente...
}
int fraccionGetDenominador(Fraccion f)
{
   // implementacion pendiente...
return 0;
}
void fraccionSetDenominador(Fraccion& f,int d)
{
   // implementacion pendiente...
}
#endif
```

## 1.1.1.3. Implementando las funciones del TAD Fraccion 

En esta sección trabajaremos con el TAD `Fraccion` como caso de referencia. Esto nos permitirá analizar cómo interpretar la documentación de cada función y llevarla a código mediante su implementación paso a paso. 

A lo largo del proceso, se hará foco en comprender la relación entre la especificación y el resultado final (la implementación), prestando especial atención a la correcta utilización de los parámetros y valores de retorno. 

## _Documentación_ 

Estructura del TAD 

_Descripción_ : Agregue a la estructura `Fraccion` los campos que considere conveniente. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 5 

```
struct Fraccion
{
   // complete aqui los campos de la estructura
};
```

## _Implementación de referencia_ 

El objetivo aquí es establecer qué campos (o atributos) debe contener la estructura `Fraccion` de modo que sea capaz de representar un número fraccionario. Lo razonable sería declarar dos campos: `numerador` y `denominador` . 

```
struct Fraccion
{
int numerador;
int denominador;
};
```

Ya definimos la implementación de la estructura. A continuación, analizaremos la especificación de cada función del TAD (función de inicialización, de conversión y otras), observando cómo se documentan, y cómo debemos implementarlas respetando los lineamientos establecidos. 

## _Documentación_ 

Función fraccion 

_Prototipo_ : `Fraccion fraccion(int n,int d);` 

_Descripción_ : Crea una fracción y le da valor inicial a cada uno de sus campos (o atributos). _Parámetros_ : 

• `int n` - Numerador. 

• `int d` - Denominador. 

_Retorna_ : `Fraccion` – Una fracción cuyo numerador es `n` y su denominador es `d` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

6 |[Apéndice 2 ● Especificaciones y API] 

```
Fraccion f = fraccion(2,5); // crea la fraccion 2/5
```

## _Implementación de referencia_ 

La función de inicialización de un TAD debe crear y retornar una variable del tipo de la estructura del TAD, dándole valor inicial a cada uno de sus campos. Usualmente, los TAD proveen una función de inicialización que recibe tantos parámetros como campos tiene la estructura. Este es el caso de la función de inicialización del TAD `Fraccion` . 

Por lo tanto, para implementar adecuadamente esta función crearemos la variable `ret` de tipo `Fraccion` , le asignaremos `n` al campo `numerador` , `d` al campo `denominador` y la retornaremos. 

```
Fraccion fraccion(int n,int d)
{
   Fraccion ret;
   ret.numerador = n;
   ret.denominador = d;
return ret;
}
```

## _Documentación_ 

Función fraccionToString 

_Prototipo_ : `string fraccionToString(Fraccion f);` 

_Descripción_ : Crea una cadena de caracteres para representar a la fracción `f` . _Parámetros_ : 

• `Fraccion f` – Fracción que queremos representar como cadena. _Retorna_ : `string` – Una cadena que representa a la fracción `f` . 

Ejemplo de uso: 

```
Fraccion f = fraccion(2,5); // crea la fraccion 2/5
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 7 

```
string s = fraccionToString(f);
cout << s << endl;
```

## _Implementación de referencia_ 

La función de conversión de un TAD es la encargada de elaborar y retornar una cadena de caracteres que represente los valores de los campos o atributos del TAD. 

Recibe como parámetro una estructura del tipo `Fraccion` cuyos campos `numerador` y `denominador` ya tienen asignados valores concretos. Entonces, para implementar esta función crearemos y retornaremos una cadena de caracteres compuesta por el valor del campo `numerador` de `f` , seguida de “/”, seguida del valor del campo `denominador` de `f` . 

C++ no permite concatenar cadenas mezclando datos de diferentes tipos. Por esto, usaremos la función de biblioteca `to_string` , que recibe un `int` y retorna una cadena que lo representa. Así, observando el código, vemos que la función se resuelve retornando la suma (concatenación) de tres cadenas: `sNum+"/"+sDen` . 

```
string fraccionToString(Fraccion f)
{
   string sNum = to_string(f.numerador);
   string sDen = to_string(f.denominador);
return sNum+"/"+sDen;
}
```

## _Documentación_ 

Función fraccionSumar 

_Prototipo_ : `Fraccion fraccionSumar(Fraccion a,Fraccion b);` 

_Descripción_ : Retorna la fracción que resulta de sumar las fracciones `a` y `b` . 

_Parámetros_ : 

• `Fraccion a` – Fracción a sumar. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

8 |[Apéndice 2 ● Especificaciones y API] 

• `Fraccion b` – Fracción a sumar. 

_Retorna_ : `Fraccion` – Una fracción que equivale a la suma de `a+b` . 

Ejemplo de uso: 

```
Fraccion a = fraccion(2,5); // crea la fraccion 2/5
Fraccion b = fraccion(1,3); // crea la fraccion 1/3
Fraccion c = fraccionSumar(a,b);
cout << fraccionToString(c) << endl; // muestra: 11/15
```

## _Implementación de referencia_ 

Esta función debe generar y retornar una fracción que resulte de sumar las fracciones `a` y `b` que recibe como parámetro. El denominador de la nueva fracción ( `ret` ) lo calcularemos como `a.denominador*b.denominador` , y el numerador lo obtendremos de sumar `a.numerador*b.denominador` y `b.numerador*a.denominador` . `Fraccion fraccionSumar(Fraccion a,Fraccion b) { Fraccion ret;` **`int`** `numA = a.numerador;` **`int`** `denA = a.denominador;` **`int`** `numB = b.numerador;` **`int`** `denB = b.denominador;` **`int`** `num = numA*denB + numB*denA;` **`int`** `den = denA*denB; ret.numerador = num; ret.denominador = den;` **`return`** `ret; }` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 9 

## _Documentación_ 

Función fraccionSimplificar _Prototipo_ : `Fraccion fraccionSimplificar(Fraccion f);` _Descripción_ : Retorna una fracción equivalente a `f` pero simplificada. 

_Parámetros_ : 

• `Fraccion f` – Fracción a simplificar. _Retorna_ : `Fraccion` – Una fracción equivalente a `f` pero simplificada. 

Ejemplo de uso: 

```
Fraccion a = fraccion(72,96); // crea la fraccion 72/96
Fraccion b = fraccionSimplificar(a);
cout << fraccionToString(b) << endl; // muestra: 3/4
```

## _Implementación de referencia_ 

En este caso, debemos generar y retornar una nueva fracción equivalente a `f` en su mínima expresión. Para ello, usaremos el siguiente algoritmo: inicializaremos una variable `i` en 2 y e intentaremos dividir simultáneamente a `f.numerador` y `f.denominador` por `i` . Si ambos son divisibles, continuaremos dividiendo por ese mismo valor. Si no lo son, incrementaremos el valor de `i` y repetiremos el proceso. Así mientras que `i` sea menor o igual que ambos valores. 

```
Fraccion fraccionSimplificar(Fraccion f)
{
   Fraccion ret;
int n = f.numerador;
int d = f.denominador;
int i=2;
while( i<=n && i<=d )
   {
if( n%i==0 && d%i==0 )
      {
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

10 |[Apéndice 2 ● Especificaciones y API] 

```
         n = n/i;
         d = d/i;
      }
else
      {
         i = i+1;
      }
   }
   ret.numerador = n;
   ret.denominador = d;
return ret;
}
```

## _Documentación_ 

Función fraccionEsEntera 

_Prototipo_ : `bool fraccionEsEntera(Fraccion f);` 

_Descripción_ : Indica si la fracción `f` representa un número entero. _Parámetros_ : 

• `Fraccion f` – Fracción a determinar si equivale a un número entero. 

_Retorna_ : `bool` – `true` o `false` si `f` es una fracción entera o no lo es. 

Ejemplo de uso: 

```
Fraccion f = fraccion(8,4);
bool esEntera = fraccionEsEntera(f);  // retorna true
```

_Implementación de referencia_ 

Debemos retornar `true` o `false` según resulte que `f.numerador` sea divisible por `f.denominador` . Es decir, `true` si el resto en dicha división es cero. Por lo tanto, simplemente retornaremos: `f.numerador%f.denominador==0` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 11 

```
bool fraccionEsEntera(Fraccion f)
{
   return f.numerador%f.denominador==0;
}
```

## _Documentación_ 

Función fraccionGetNumerador 

_Prototipo_ : `int fraccionGetNumerador(Fraccion f);` 

_Descripción_ : Retorna el numerador de la fracción `f` . _Parámetros_ : 

• `Fraccion f` – Fracción a la que accederemos a su numerador. _Retorna_ : `int` – el numerador de la fracción `f` . 

Ejemplo de uso: 

```
Fraccion f = fraccion(2,3);
int n = fraccionGetNumerador(f);
cout << n << endl;  // muestra 2
```

_Implementación de referencia_ 

Esta es una de las _funciones de acceso_ del TAD. Simplemente debemos retornar el valor del campo `numerador` de la fraccion `f` que recibimos como parámetro. 

```
int fraccionGetNumerador(Fraccion f)
{
return f.numerador;
}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

12 |[Apéndice 2 ● Especificaciones y API] 

_Documentación_ 

Función fraccionSetNumerador _Prototipo_ : `void fraccionSetNumerador(Fraccion& f,int num);` _Descripción_ : Asigna el numerador `num` a la fracción `f` . _Parámetros_ : 

• `Fraccion& f` – Fracción cuyo numerador será modificado. _Retorna_ : `void` . Ejemplo de uso: 

```
Fraccion f = fraccion(2,3);
fraccionSetNumerador(f,5);
cout << fraccionToString(f) << endl;  // muestra 5/3
```

## _Implementación de referencia_ 

En esta función debemos asignar el valor de `num` al campo `numerador` de la fracción `f` . 

```
void fraccionSetNumerador(Fraccion& f,int num)
{
   f.numerador = num;
}
```

_Documentación_ 

Función fraccionGetDenominador 

_Prototipo_ : `int fraccionGetDenominador(Fraccion f);` _Descripción_ : Retorna el denominador de la fracción `f` . _Parámetros_ : • `Fraccion f` – Fracción a la que accederemos a su denominador. _Retorna_ : `int` – el denominador de la fracción `f` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 13 

Ejemplo de uso: `Fraccion f = fraccion(2,3);` **`cout`** `<< fraccionGetDenominador(f) <<` **`endl`** `;` _`// muestra 3`_ 

_Implementación de referencia_ 

Retornaremos el valor del denominador de `f` . **`int`** `fraccionGetDenominador(Fraccion f) {` **`return`** `f.denominador; }` 

## _Documentación_ 

Función fraccionSetDenominador _Prototipo_ : `void fraccionSetDenominador(Fraccion& f,int den);` _Descripción_ : Asigna el denominador `den` a la fracción `f` . _Parámetros_ : • `Fraccion& f` – Fracción cuyo denominador será modificado. _Retorna_ : `void` . Ejemplo de uso: `Fraccion f = fraccion(2,3); fraccionSetDenominador(f,5);` **`cout`** `<< fraccionToString(f) <<` **`endl`** `;` _`// muestra 2/5`_ 

_Implementación de referencia_ 

Aquí asignaremos el valor de `den` a `f.denominador` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

14 |[Apéndice 2 ● Especificaciones y API] 

```
void fraccionSetDenominador(Fraccion& f,int den)
{
   f.denominador = den;
}
```

## 1.1.2. API de tratamiento de instantes expresados en milisegundos 

Las siguientes funciones se encuentran programadas y disponibles en `millis.hpp` , y serán la base sobra la que se programará el TAD `Fecha` , documentado más adelante. 

## 1.1.2.1. Función currTimeMillis 

_Prototipo_ : `long long currTimeMillis();` 

_Descripción_ : Retorna la cantidad de milisegundos transcurridos desde el 1-1-1970. A este valor, de aquí en adelante, lo llamaremos _timestamp_ . 

_Retorna_ : `long long` – El _timestamp_ representando al instante actual. 

Ejemplo de uso: 

```
long long ts = currTimeMillis();
cout << ts << endl; // muestra: 1776867620878 (por ejemplo)
```

## 1.1.2.2. Función millisToString 

_Prototipo_ : `string millisToString(long long ts);` 

_Descripción_ : Retorna una cadena representando al _timestamp_ `ts` . 

_Retorna_ : `string` – Una cadena que representa a `ts` fácil de entender. 

Ejemplo de uso: 

```
long long ts = currTimeMillis();
```

```
// Retorna: 2026-04-22, 11:20:20.878 (por ejemplo)
cout << millisToString(ts) << endl;
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 15 

## 1.1.2.3. Función attributesToMillis 

_Prototipo_ : `long long attributesToMillis(` 

```
                                 int y,int mo,int d
                                ,int h,int m
                                ,int s,int ms);
```

_Descripción_ : Toma los atributos _year_ , _month_ , _day_ , hour, _minute_ , _second_ y _millisecond_ y retorna un _timestamp_ que los representa. 

_Retorna_ : `long long` – Un _timestamp_ construído en función de los parámetros. 

Ejemplo de uso: 

```
// 20 de mayo de 2026, a las 10:30 hs.
long long ts = attributesToMillis(2026,5,20,10,30,0,0);
// muestra: 1776867620878 (por ejemplo)
cout << millisToString(ts) << endl;
```

## 1.1.2.4. Funciones millisToAttributes 

_Prototipo_ : `void millisToAttributes(` 

```
                       long long ts,int& y,int& mo,int& d
                      ,int& h,int& m,int& s,int& ms);
```

_Descripción_ : Dado un _timestamp_ , decodifica el año, mes, día, hora, minuto, segundo y milisegundo, y los asigna en los parámetros que la función recibe por referencia. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
int anio,mes,dia,h,m,s,ms;
long long ts = currTimeMillis();
millisToAttributes(ts,anio,mes,dia,h,m,s,ms);
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

16 |[Apéndice 2 ● Especificaciones y API] 

## 1.1.3. TAD Fecha 

Las siguientes funciones deben programarse dentro del archivo `Fecha.hpp` para implementar el TAD `Fecha` , cuyo objetivo es encapsular la lógica propia de las fechas y los horarios. 

## 1.1.3.1. Estructura del TAD 

```
struct Fecha
{
   // Tu implementacion aqui que permita
   // resolver fechas y horas...
};
```

## 1.1.3.2. Función fecha 

_Prototipo_ : `Fecha fecha(long long ts);` 

_Descripción_ : Función de inicialización que crea una fecha a partir de un _timestamp_ . 

_Retorna_ : `Fecha` – Retorna una fecha a partir de `ts` . 

Ejemplo de uso: 

```
long long ts = currTimeMillis();
Fecha f = fecha(ts);
```

## 1.1.3.3. Función fecha (sobrecarga 1) 

_Prototipo_ : `Fecha fecha();` 

_Descripción_ : Función de inicialización que crea una fecha inicializada en este instante. Es decir: fecha de hoy, hora actual. 

_Retorna_ : `Fecha` – Retorna una fecha a partir del instante en que fue invocada. 

Ejemplo de uso: 

```
Fecha fAhora = fecha(); // fecha de hoy, hora de ahora...
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 17 

## 1.1.3.4. Función fecha (sobrecarga 2) 

_Prototipo_ : `Fecha fecha(int y,int mo,int d,int h,int m);` 

_Descripción_ : Función de inicialización que crea una fecha inicializada a partir de los valores que recibe como parámetro. 

_Retorna_ : `Fecha` – Retorna una fecha. 

Ejemplo de uso: 

```
// 25-5-2026, 13:30 hs.
Fecha f = fecha(2026,5,25,13,30);
```

## 1.1.3.5. Función fecha (sobrecarga 3) 

_Prototipo_ : `Fecha fecha(int y,int m,int d);` 

_Descripción_ : Función de inicialización que crea una fecha inicializada a partir de los valores de _year_ , _month_ y _day_ , dejando la hora, minuto segundos y milisegundos en cero. 

_Retorna_ : `Fecha` – Retorna una fecha. 

Ejemplo de uso: 

```
// 25-5-2026, 0:00 hs.
Fecha f = fecha(2026,5,25);
```

## 1.1.3.6. Función fechaToString 

_Prototipo_ : `string fechaToString(Fecha f);` 

_Descripción_ : Función de conversión. 

_Retorna_ : `string` – Retorna una cadena que representa a la fecha `f` . 

Ejemplo de uso: 

```
Fecha f = fecha(2025,10,2);
cout << fechaToString(f) << endl;
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

18 |[Apéndice 2 ● Especificaciones y API] 

## 1.1.3.7. Función fechaInMillis 

_Prototipo_ : `long long fechaInMillis(Fecha f);` 

_Descripción_ : Retorna la fecha `f` representada como un _timestamp_ . 

_Retorna_ : `long long` – Retorna el _timestamp_ que se corresponde con `f` . 

Ejemplo de uso: 

```
Fecha f = fecha();
long long ts = fechaInMillis(f);
```

## 1.1.3.8. Función fechaAddSegundos 

_Prototipo_ : `Fecha fechaAddSegundos(Fecha f,int n);` 

_Descripción_ : Crea y retorna una fecha que resultará de sumarle `n` segundos a `f` . 

_Retorna_ : `Fecha` – Retorna una fecha que difiere de `f` en `n` segundos. 

Ejemplo de uso: 

```
Fecha f1 = fecha(2026,5,25);
Fecha f2 = fechaAddSegundos(f1,10);
```

## 1.1.3.9. Función fechaAddMinutos 

_Prototipo_ : `Fecha fechaAddMinutos(Fecha f,int n);` 

_Descripción_ : Idem anterior pero suma `n` minutos a la fecha `f` 

## 1.1.3.10. Función fechaAddHoras 

_Prototipo_ : `Fecha fechaAddHoras(Fecha f,int n);` 

_Descripción_ : Idem anterior pero suma `n` horas a la fecha `f` 

## 1.1.3.11. Función fechaAddDias 

_Prototipo_ : `Fecha fechaAddDias(Fecha f,int n);` 

_Descripción_ : Crea y retorna una fecha que resultará de sumarle `n` días a `f` . 

_Retorna_ : `Fecha` – Retorna una fecha que difiere de `f` en `n` días. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 19 

Ejemplo de uso: 

```
Fecha f1 = fecha(2026,5,20);
Fecha f2 = fechaAddDias(f1,5);  // 25 de mayo
Fecha f3 = fechaAddDias(f1,-5); // 15 de mayo
```

## 1.1.3.12. Función fechaDiffMillis 

_Prototipo_ : `long long fechaDifMillis(Fecha f1,Fecha f2);` 

_Descripción_ : Retorna la diferencia expresada en milisegundos entre `f1` y `f2` . 

_Retorna_ : `long long` – Retorna la diferencia expresada en milisegundos. 

Ejemplo de uso: 

```
Fecha f1 = fecha(1973,6,15);
Fecha f2 = fecha(1970,10,2);
long long diff = fechaDiffMillis(f1,f2);
```

## 1.1.3.13. Función fechaDiffDias 

_Prototipo_ : `int fechaDiffDias(Fecha f1,Fecha f2);` 

_Descripción_ : Retorna la diferencia en días entre `f1` y `f2` . 

_Retorna_ : `int` – Diferencia en días entre dos fechas. 

Ejemplo de uso: 

```
Fecha f1 = fecha(2025,10,2);
Fecha f2 = fecha(2025,10,10);
int n = fechaDiffDias(f1,f2); // retorna 8
```

## 1.1.3.14. Función fechaCmp 

_Prototipo_ : `int fechaCmp(Fecha f1,Fecha f2);` 

_Descripción_ : Función de comparación que permite estabecer si una fecha precede a otra. La comparación debe considerar año, mes, día, hora, minuto, segundo y milisegundo. _Retorna_ : `int` – Negativo, cero o positivo según `f1` sea anterior, igual o posterior a `f2` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

20 |[Apéndice 2 ● Especificaciones y API] 

Ejemplo de uso: 

```
Fecha f1 = fecha(2025,10,2,18,30);
Fecha f2 = fecha(2025,10,10,21,0);
if( fechaCmp(f1,f2)<0 )
{
cout << fechaToString(f1) << " es anterior a ";
cout << fechaToString(f2) << endl;
}
```

## 1.1.3.15. Función fechaCmpDiaMesAnio 

_Prototipo_ : `int fechaCmpDiaMesAnio(Fecha f1,Fecha f2);` 

_Descripción_ : Compara `f1` y `f2` sin considerar hora, minuto, segundo ni milisegundo. 

_Retorna_ : `int` – Negativo, cero o positivo según `f1` sea anterior, igual o posterior a `f2` . 

Ejemplo de uso: 

```
Fecha f1 = fecha(2025,10,2);
Fecha f2 = fecha(2025,10,10);
if( fechaCmp(f1,f2)<0 )
{
cout << fechaToString(f1) << " es anterior a ";
cout << fechaToString(f2) << endl;
}
```

## 1.1.3.16. Función fechaEsAnioBisiesto 

_Prototipo_ : `bool fechaEsAnioBisiesto(int a);` 

_Descripción_ : Indica si un año es bisiesto. 

_Retorna_ : `bool` – Retorna `true` o `false` según `a` sea un año bisiesto o no. 

Ejemplo de uso: 

```
bool esBisiesto = fechaEsAnioBisiesto(2025);
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 21 

## 1.1.3.17. Función fechaEsAnioBisiesto (sobrecarga) 

_Prototipo_ : `bool fechaEsAnioBisiesto(Fecha f);` 

_Descripción_ : Indica si el año de la fecha `f` es bisiesto. 

_Retorna_ : `bool` – Retorna `true` o `false` según el año de la fecha `f` sea o no bisiesto. 

Ejemplo de uso: 

```
Fecha f = fecha();
bool esBisiesto = fechaEsAnioBisiesto(f);
```

## 1.1.3.18. Función fechaDiasEnMes 

_Prototipo_ : `int fechaDiasEnMes(int mes,int anio);` 

_Descripción_ : Indica cuántos días tiene el mes `mes` . 

_Retorna_ : `int` – Retorna la cantidad de días que tiene el mes `mes` según el año `anio` . 

Ejemplo de uso: 

```
// retorna 28 porque febrero de 2026 no fue bisiesto
int dias = fechaDiasEnMes(2,2026);
```

## 1.1.3.19. Función fechaDiasEnMes (sobrecarga) 

_Prototipo_ : `int fechaDiasEnMes(Fecha f);` 

_Descripción_ : Indica cuántos días tiene el mes de la fecha `f` . 

_Retorna_ : `int` – Retorna la cantidad de días que tiene el de la fecha `f` . 

Ejemplo de uso: 

```
Fecha f = fecha();
int dias = fechaDiasEnMes(f);
```

## 1.1.3.20. Función fechaDiaDelAnio 

_Prototipo_ : `int fechaDiaDelAnio(Fecha f);` 

_Descripción_ : Retorna a qué número de día del año corresponde la fecha `f` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

22 |[Apéndice 2 ● Especificaciones y API] 

_Retorna_ : `int` – Retorna el número del día de la fecha `f` , que estará entre 1 y 365 o 366. 

Ejemplo de uso: 

```
Fecha f = fecha();
int nroDia = fechaDiaDelAnio(f);
```

## 1.1.3.21. Función fechaEsValida 

_Prototipo_ : `bool fechaEsValida(Fecha f);` 

_Descripción_ : Determina si una fecha es consistente o no lo es. 

_Retorna_ : `bool` – `true` si la fecha `f` es consistente o `false` si no lo es. 

Ejemplo de uso: 

```
Fecha f = fecha(29,2,2925);
bool consistente = fechaEsValida(f); // retorna false
```

## 1.1.3.22. Función fechaEsHoy 

_Prototipo_ : `bool fechaEsHoy(Fecha f);` 

_Descripción_ : Determina si una fecha coincide con la fecha de hoy (día, mes y año). 

_Retorna_ : `bool` – `true` si la fecha `f` es es la fecha de hoy. 

Ejemplo de uso: 

```
Fecha f = fecha();
bool esHoy = fechaEsHoy(f); // retorna true
```

## 1.1.3.23. Función fechaGetDia 

_Prototipo_ : `int fechaGetDia(Fecha f);` 

_Descripción_ : Retorna el día de la fecha `f` . 

_Retorna_ : `int` – Si la fecha fuera 6 de octubre de 2023, retornaría 6. 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 23 

```
Fecha f = fecha();
int dia = fechaGetDia(f); // retorna el dia
```

## 1.1.3.24. Función fechaSetDia 

_Prototipo_ : `void fechaSetDia(Fecha& f,int x);` 

_Descripción_ : Asigna el día `x` a la fecha `f` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Fecha f = fecha(2026,10,9); // 9 de octubre de 2026
fechaSetDia(f,3);  // cambio a 3 de octubre de 2026
```

## 1.1.3.25. Función fechaGetMes 

_Prototipo_ : `int fechaGetMes(Fecha f);` 

_Descripción_ : Retorna el mes de la fecha `f` . 

_Retorna_ : `int` – Si la fecha fuera 6-10-2023, retornaría 10. 

Ejemplo de uso: 

```
Fecha f = fecha();
int mes = fechaGetMes(f); // retorna el mes
```

## 1.1.3.26. Función fechaSetMes 

_Prototipo_ : `void fechaSetMes(Fecha& f,int x);` 

_Descripción_ : Asigna el mes `x` a la fecha `f` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Fecha f = fecha(2026,10,9); // 9 de octubre de 2026
fechaSetMes(f,3);    // cambio a 9 de marzo de 2026
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

24 |[Apéndice 2 ● Especificaciones y API] 

## 1.1.3.27. Función fechaGetAnio 

_Prototipo_ : `int fechaGetAnio(Fecha f);` 

_Descripción_ : Retorna el anio de la fecha `f` . 

_Retorna_ : `int` – Si la fecha fuera 6 de octubre de 2023, retornaría 2023. 

Ejemplo de uso: 

```
Fecha f = fecha();
int anio = fechaGetAnio(f); // retorna el anio
```

## 1.1.3.28. Función fechaSetAnio 

_Prototipo_ : `void fechaSetAnio(Fecha& f,int x);` 

_Descripción_ : Asigna el anio `x` a la fecha `f` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Fecha f = fecha(2026,10,9);    // 9 de octubre de 2026
fechaSetAnio(f,1990); // cambio a 9 de octubre de 1990
```

## 1.1.3.29. Función fechaGetHora 

_Prototipo_ : `int fechaGetHora(Fecha f);` 

_Descripción_ : Retorna la hora de la fecha `f` . 

_Retorna_ : `int` . 

Ejemplo de uso: 

```
Fecha f = fecha(2025,12,8,10,30);
int x = fechaGetHora(f); // retorna la hora: 10
```

## 1.1.3.30. Función fechaSetHora 

_Prototipo_ : `void fechaSetHora(Fecha& f,int x);` 

_Descripción_ : Asigna la hora `x` a la fecha `f` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 25 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Fecha f = fecha(2026,10,9,10,30); // 9-oct-2026, 10:30 hs
fechaSetHora(f,12);  // cambio la hora a 12
```

## 1.1.3.31. Función fechaGetMinuto 

_Prototipo_ : `int fechaGetMinuto(Fecha f);` 

_Descripción_ : Retorna los minutos de la fecha `f` . 

_Retorna_ : `int` . 

Ejemplo de uso: 

```
Fecha f = fecha(2025,12,8,10,30);
int x = fechaGetMinuto(f); // retorna los minutos: 30
```

## 1.1.3.32. Función fechaSetMinuto 

_Prototipo_ : `void fechaSetMinuto(Fecha& f,int x);` 

_Descripción_ : Asigna el minuto `x` a la fecha `f` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Fecha f = fecha(2026,10,9,10,30); // 9-oct-2026, 10:30 hs
fechaSetMinuto(f,45);  // cambio los minutos a 45
```

## 1.1.3.33. Función fechaGetSegundo 

_Prototipo_ : `int fechaGetSegundo(Fecha f);` 

_Descripción_ : Retorna los segundos de la fecha `f` . 

_Retorna_ : `int` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

26 |[Apéndice 2 ● Especificaciones y API] 

```
Fecha f = fecha(2025,12,8,10,30,25,0);
int x = fechaGetSegundo(f); // retorna los segundos: 25
```

## 1.1.3.34. Función fechaSetSegundo 

_Prototipo_ : `void fechaSetSegundo(Fecha& f,int x);` 

_Descripción_ : Asigna el segundo `x` a la fecha `f` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Fecha f = fecha(2026,10,9,10,30,25,0);
fechaSetSegundo(f,30);  // cambio los segundos de 25 a 30
```

## 1.1.3.35. Función fechaGetMillis 

_Prototipo_ : `int fechaGetMillis(Fecha f);` 

_Descripción_ : Retorna los milisegundos de la fecha `f` . 

_Retorna_ : `int` . 

Ejemplo de uso: 

```
Fecha f = fecha(2025,12,8,10,30,25,0);
int x = fechaGetMillis(f); // retorna los milisegundos: 0
```

## 1.1.3.36. Función fechaSetMillis 

_Prototipo_ : `void fechaSetMillis(Fecha& f,int x);` 

_Descripción_ : Asigna los milisegundos `x` a la fecha `f` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Fecha f = fecha(2026,10,9,10,30,25,0);
fechaSetMillis(f,100);  // cambio los milisegundos a 100
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 27 

## 1.1.4. TAD Timer 

Implementar el TAD `Timer` dentro del archivo `Timer.hpp` , cuya funcionalidad nos permitirá medir el tiempo transcurrido entre dos momentos especificados. 

Para su implementación se debe utilizar la biblioteca `millis.hpp` . 

## 1.1.4.1. Ejemplo de uso del TAD Timer 

```
Timer t = timer();
int n;
cout << "Ingrese un valor: ";
// inicio el timer
timerStart(t);
cin >> n
// detengo el timer
timerStop(t);
long long ms = timerElapsedTime(t);
cout << "Demoraste " << ms << " milisegundos" << endl;
```

## 1.1.4.2. Estructura del TAD 

```
struct Timer
{
   // programar aqui la implementacion...
};
```

## 1.1.4.3. Función timer 

_Prototipo_ : `Timer timer();` 

_Descripción_ : Función de inicialización del _timer_ . 

_Retorna_ : `Timer` . 

## 1.1.4.4. Función timerStart 

_Prototipo_ : `void timerStart(Timer& t);` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

28 |[Apéndice 2 ● Especificaciones y API] 

_Descripción_ : Comienza la cuenta de tiempo del _timer_ `t` . 

_Parámetro_ : `Timer t` – El _timer_ que comenzará a contar. 

_Retorna_ : `void` . 

## 1.1.4.5. Función timerStop 

_Prototipo_ : `void timerStop(Timer& t);` 

_Descripción_ : Finaliza la cuenta de tiempo del _timer_ `t` . 

_Parámetro_ : `Timer t` – El _timer_ que finalizará de contar. 

_Retorna_ : `void` . 

## 1.1.4.6. Función timerElapsedTime 

_Prototipo_ : `long long timerElapsedTime(Timer t);` 

_Descripción_ : Retorna la cantidad de milisegundos transcurridos entre el _start_ y el _stop_ del _timer_ `t` . 

_Parámetro_ : `Timer t` – El _timer_ . 

_Retorna_ : `long long` – Cuántos milisegundos transcurrieron. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 29 

## 1.2. Lección 4 

## 1.2.1. API de tratamiento de cadenas de caracteres 

La siguientes funciones deben programarse en el archivo `strings.hpp` . 

## 1.2.1.1. Función length 

_Prototipo_ : `int length(string s);` 

_Descripción_ : Cuenta la cantidad de caracteres que componen la cadena `s` . 

_Parámetro_ : `string s` – Cadena cuya longitud debemos averiguar. 

_Retorna_ : `int` – Cuántos caracteres contiene la cadena `s` . 

Ejemplo de uso: 

```
string s = "Hola";
int n = length(s);
cout << n << endl; // muestra: 4
s = "";
n = length(s);
cout << n << endl; // muestra: 0
```

## 1.2.1.2. Función charCount 

_Prototipo_ : `int charCount(string s,char c);` 

_Descripción_ : Cuenta la cantidad de veces que aparece el carácter `c` dentro de `s` . 

_Parámetros_ : 

- `string s` – Cadena que contiene al carácter `c` . 

- `char c` – Carácter cuya cantidad de ocurrencias queremos averiguar. 

_Retorna_ : `int` – Cuántas veces aparece `c` dentro de la cadena `s` . 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

30 |[Apéndice 2 ● Especificaciones y API] 

```
int n = charCount(s,'e');
cout << n << endl;    // muestra: 2
n = charCount(s,' ');
cout << n << endl;    // muestra: 3
```

## 1.2.1.3. Función substring 

_Prototipo_ : `string substring(string s,int d,int h);` 

_Descripción_ : Retorna la subcadena de `s` comprendida entre las posiciones `d` (inclusive) y `h` (no inclusive). 

_Parámetros_ : 

- `string s` – Cadena que contiene la subcadena que queremos obtener. 

- `int d` – Posición (inclusive) que indica dónde comienza la subcadena. 

- `int h` – Posición (no inclusive) que indica dónde finaliza la subcadena. 

_Retorna_ : `string` – La subcadena de `s` comprendida comprendida entre las posiciones `d` (inclusive) y `h` (no inclusive). 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
string x = substring(s,2,10);
cout << x << endl;  // muestra: to es un
x = substring(s,2,length(s));
cout << x << endl;  // muestra: to es una prueba
```

## 1.2.1.4. Función substring (sobrecarga) 

_Prototipo_ : `string substring(string s,int d);` 

_Descripción_ : Retorna la subcadena de `s` comprendida entre la posición `d` y el final de la cadena. 

## _Parámetros_ : 

- `string s` – Cadena que contiene la subcadena que queremos obtener. 

- `int d` – Posición (inclusive) que indica dónde comienza la subcadena. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 31 

_Retorna_ : `string` – La subcadena de `s` comprendida comprendida entre la posición `d` (inclusive) y el final de la cadena. 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
string x = substring(s,2);
cout << x << endl; // muestra: to es una prueba
```

## 1.2.1.5. Función indexOf 

_Prototipo_ : `int indexOf(string s,char c)` 

_Descripción_ : Retorna la posición que ocupa la primera ocurrencia del carácter `c` dentro de la cadena `s` . 

_Parámetros_ : 

- `string s` - Cadena que contiene al carácter `c` . 

- `char c` - Carácter cuya posición, dentro de `s` , queremos averiguar. 

_Retorna_ : `int` – La posición que ocupa, dentro de `s` , la primera ocurrencia del carácter `c` , o un valor negativo si `s` no contiene a `c` . 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
int p = indexOf(s,'e');
cout << p << endl; // muestra: 5
p = indexOf(s,'X');
cout << p << endl; // muestra: -1
```

## 1.2.1.6. Función indexOf (sobrecarga) 

_Prototipo_ : `int indexOf(string s,char c,int offset)` ; 

_Descripción_ : Retorna la posición que ocupa la primera ocurrencia de un carácter `c` dentro de la cadena `s` , descartando los primeros `offeset` caracteres (desplazamiento inicial). 

_Parámetros_ : 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

32 |[Apéndice 2 ● Especificaciones y API] 

- `string s` - Cadena que contiene al carácter `c` . 

- `char c` - Carácter cuya posición, dentro de `s` , queremos averiguar. 

- `int offset` - Posición de desplazamiento desde donde debemos buscar. 

_Retorna_ : `int` – La posición que ocupa, dentro de `s` , la primera ocurrencia del carácter `c` , considerando desde `offset` . 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
int p = indexOf(s,'e',0);
cout << p << endl; // muestra: 5
p = indexOf(s,'e',12);
cout << p << endl; // muestra: 15
```

## 1.2.1.7. Función indexOf (sobrecarga) 

_Prototipo_ : `int indexOf(string s,string toSearch)` 

_Descripción_ : Retorna la posición que ocupa la primera ocurrencia de `toSearch` dentro de la cadena `s` . 

_Parámetros_ : 

- `string s` - Cadena que contiene al carácter `c` . 

- `string toSearch` – Cadena cuya posición queremos averiguar. 

_Retorna_ : `int` – La posición inicial de la primera ocurrencia de `toSearch` dentro de `s` o un valor negativo si `s` no contiene a `toSearch` . 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
int p = indexOf(s,"una");
cout << p << endl; // muestra: 8
p = indexOf(s,"jamon");
cout << p << endl; // muestra: algun valor negativo
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 33 

## 1.2.1.8. Función indexOf (sobrecarga) 

_Prototipo_ : `int indexOf(string s,string toSearch,int offset)` ; 

_Descripción_ : Retorna la posición que ocupa la primera ocurrencia de `toSearch` dentro de la cadena `s` , descartando los primeros `offeset` caracteres (desplazamiento inicial). 

_Parámetros_ : 

- `string s` - Cadena que contiene a `toSearch` . 

- `string toSearch` – Cadena que vamos a buscar. 

- `int offset` - Posición de desplazamiento desde donde debemos buscar. 

_Retorna_ : `int` – La posición que ocupa la primera ocurrencia de `toSearch` considerando a `s` a partir de la posición `offset` . 

Ejemplo de uso: 

```
string s = "Esta funcion es la funcion mas dificil";
int p = indexOf(s,"funcion",0);
cout << p << endl; // muestra: 5
p = indexOf(s,"funcion",13);
cout << p << endl; // muestra: 19
```

## 1.2.1.9. Función lastIndexOf 

_Prototipo_ : `int lastIndexOf(string s,char c)` ; 

_Descripción_ : Retorna la posición de la última ocurrencia del carácter `c` dentro de `s` 

_Parámetros_ : 

- `string s` - Cadena que contiene al carácter `c` . 

- `char c` - Carácter cuya última posición, dentro de `s` , queremos averiguar. 

_Retorna_ : `int` – La posición que ocupa, dentro de `s` , la última ocurrencia del carácter `c` , o un valor negativo si `s` no contiene a `c` . 

## 1.2.1.10. Función indexOfN 

_Prototipo_ : `int indexOfN(string s,char c,int n);` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

34 |[Apéndice 2 ● Especificaciones y API] 

_Descripción_ : Retorna la posición de la _n_ -ésima ocurrencia de `c` dentro de `s` . Si `n` es 0 (cero) retorna -1; si `n` es mayor que la cantidad de ocurrencias de `c` retorna la longitud de la cadena `s` . 

_Parámetros_ : 

- `string s` - Cadena que contiene al carácter `c` . 

- `char c` - Carácter cuya posición se debe determinar. Se asume que `s` contiene a `c` , al menos, `n` veces. 

- `int n` - Número de ocurrencia de `c` , contando desde 1. 

_Retorna_ : `int` - La posición de la _n_ -ésima ocurrencia de `c` dentro de `s` . 

Ejemplo de uso: 

```
string s = "John|Paul|George|Ringo";
int p = indexOfN(s,'|',1);
cout << p << endl; // muestra: 4
p = indexOfN(s,'|',2);
cout << p << endl; // muestra: 9
p = indexOfN(s,'|',3);
cout << p << endl; // muestra: 16
```

## 1.2.1.11. Función charToInt 

_Prototipo_ : `int charToInt(char c);` 

_Descripción_ : Retorna el valor numérico que representa el carácter `c` . 

_Parámetro_ : `char c` – Carácter que podrá ser numérico o alfabético, siendo ‘0’ <= `c` <= ‘9’, ‘A’ <= `c` <= ’Z’, ‘a’ <= `c` <= ‘z’. Acepta indistintamente mayúsculas y minúsculas. 

_Retorna_ : `int` - El valor numérico del carácter `c` . Para letras se considera: ‘A’=10. 

Ejemplo de uso: 

```
char c = '2';
int n = charToInt(c); // retorna: 2
cout << n << endl;
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 35 

```
c = 'D';
n = charToInt(c); // retorna: 13
cout << n << endl;
```

## 1.2.1.12. Función intToChar 

_Prototipo_ : `char intToChar(int i);` 

_Descripción_ : Retorna el carácter que representa al valor de `i` , que debe estar comprendido entre 0 y 9, o en entre 65 y 90. Es la función inversa de `charToInt` . 

_Parámetro_ : `int i` - Valor numérico. 

_Retorna_ : `char` - El carácter que representa al valor de `i` , considerando que 10=’A’. 

Ejemplo de uso: 

```
int i = 2;
char c = intToChar(i);
cout << c << endl; // muestra: 2
i = 13;
c = intToChar(i);
cout << c << endl; // muestra: D
```

## 1.2.1.13. Función getDigit 

_Prototipo_ : `int getDigit(int n,int i);` 

_Descripción_ : Retorna el _i_ -ésimo dígito del valor de n. 

_Parámetros_ : 

- `int n` – Número entero de 1 o más dígitos desde donde que se quiere obtener el dígito que se ubica en la _i_ -ésima posición. 

- `int i` - Posición, contando desde 0 (cero) y de derecha a izquierda, del dígito de `n` que queremos obtener. 

_Retorna_ : `int` - El dígito que se ubica en la _i_ -ésima posición de `n` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

36 |[Apéndice 2 ● Especificaciones y API] 

```
int n = 12345;
int i = 0;
int r = getDigit(n,i);
cout << r << endl; // muestra: 5
i = 1;
r = getDigit(n,i);
cout << r << endl; // muestra: 4
```

## 1.2.1.14. Función digitCount 

_Prototipo_ : `int digitCount(int n);` 

_Descripción_ : Retorna la cantidad de dígitos que contiene el valor de n. 

_Parámetro_ : `int n` - Valor numérico cuya cantidad de dígitos queremos averiguar. 

_Retorna_ : `int` - La cantidad de dígitos que tiene el valor de `n` . 

Ejemplo de uso: 

```
int n = 12345;
int i = digitCount(n);
cout << i << endl; // muestra: 5
```

## 1.2.1.15. Función intToString 

_Prototipo_ : `string intToString(int i);` 

_Descripción_ : Retorna una cadena de caracteres representando el valor `i` . 

_Parámetro_ : `int i` - Valor numérico entero que se va a representar como `string` . 

_Retorna_ : `string` - Cadena de caracteres que representando el valor de `i` . 

Ejemplo de uso: 

```
int i = 12345;
string s = intToString(i);
cout << s << endl; // muestra: 12345
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 37 

## 1.2.1.16. Función stringToInt 

_Prototipo_ : `int stringToInt(string s,int b);` 

`Descripción` : Retorna el valoro numérico representado en la cadena `s` , considerando que dicho valor está expresado en la base numérica `b` . 

_Parámetros_ : 

- `string s` - Cadena que representa un valor numérico entero en base `b` . 

- `int b` - Base numérica del valor que representado en la cadena s. 

_Retorna_ : `int` - El número numérico representado en la cadena `s` . 

Ejemplo de uso: 

```
string s = "10";
int i = stringToInt(s,10);
cout << i << endl; // muestra: 10
i = stringToInt(s,2);
cout << i << endl; // muestra: 2
i = stringToInt(s,16);
cout << i << endl; // muestra: 16
s = "12AB";
i = stringToInt(s,16);
cout << i << endl; // muestra: 4779
```

## 1.2.1.17. Función stringToInt (sobrecarga) 

_Prototipo_ : `int stringToInt(string s); // SOBRECARGA` 

_Descripción_ : Retorna el valor numérico de la cadena `s` , la cual sólo debe contener dígitos numéricos en base 10. Esta función es la función inversa de `intToString` . 

_Parámetro_ : `string s` - Cadena de caracteres que sólo contiene dígitos numéricos. 

_Retorna_ : `int` - El valor numérico que está representado en la cadena `s` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

38 |[Apéndice 2 ● Especificaciones y API] 

```
string s = "12345";
int i = stringToInt(s);
cout << i << endl; // muestra: 12345
```

## 1.2.1.18. Función charToString 

_Prototipo_ : `string charToString(char c);` 

_Descripción_ : Retorna una cadena cuyo único carácter es `c` . 

_Parámetro_ : `char c` – Carácter que será el contenido de la cadena. 

_Retorna_ : `string` - Una cadena de longitud 1 cuyo único carácter será `c` . 

Ejemplo de uso: 

```
char c = 'A';
string s = charToString(c);
cout << s << endl;         // muestra: A
cout << length(s) << endl; // muestra: 1
c = ' ';
string s = charToString(c);
cout << s << endl;         // muestra: [VACIO]
cout << length(s) << endl; // muestra: 1
```

## 1.2.1.19. Función stringToChar 

_Prototipo_ : `char stringToChar(string s);` 

_Descripción_ : Retorna el único carácter que contiene la cadena `s` . Esta es la función inversa de `charToString` . 

_Parámetro_ : `string s` - Cadena de caracteres de longitud 1. 

_Retorna_ : `char` - El único carácter que contiene la cadena `s` . 

Ejemplo de uso: 

```
string s = "A";
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 39 

```
char c = stringToChar(s);
cout << c << endl;      // muestra: A
cout << (int)c << endl; // muestra: 65
s = " ";
c = stringToChar(s);
cout << c << endl;      // muestra: [VACIO]
cout << (int)c << endl; // muestra: 32, ASCII de ' '
```

## 1.2.1.20. Función stringToString 

_Prototipo_ : `string stringToString(string s);` 

_Descripción_ : Retorna la misma cadena que recibe. Se trata de una función trivial que usaremos más adelante, dentro de este mismo capítulo. 

_Parámetro_ : `string s` - Cadena de caracteres. 

_Retorna_ : `string` – La misma cadena que recibe como parámetro. 

Ejemplo de uso: 

```
string s = stringToString("Hola");
cout << s << endl;  // muestra: Hola
```

## 1.2.1.1. Función doubleToString 

_Prototipo_ : `string doubleToString(double d,int prec);` 

_Descripción_ : Retorna una cadena representando el valor contenido en `d` con una precisión de `prec` dígitos para la parte decimal. 

_Parámetro_ : `double d` - Valor que se representará como cadena. 

_Parámetro_ : `int prec` – Precisión de la parte decimal del número `n` . 

_Retorna_ : `string` - Cadena de caracteres representando el valor de `d` . 

Ejemplo de uso: 

```
double d = 123.45678;
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

40 |[Apéndice 2 ● Especificaciones y API] 

```
string s = doubleToString(d,4);
cout << s << endl; // muestra: 123.4567
```

## 1.2.1.2. Función doubleToString (sobrecarga) 

_Prototipo_ : `string doubleToString(double d);` 

_Descripción_ : Retorna una cadena representando el valor contenido en `d` con una precisión de 3 dígitos para la parte decimal. 

_Parámetro_ : `double d` - Valor que se representará como cadena. 

_Retorna_ : `string` - Cadena de caracteres representando el valor de `d` . 

Ejemplo de uso: 

```
double d = 123.45678;
string s = doubleToString(d);
cout << s << endl; // muestra: 123.456
```

## 1.2.1.3. Función stringToDouble 

_Prototipo_ : `double stringToDouble(string s);` 

_Descripción_ : Retorna el valor numérico representado en la cadena `s` . 

_Parámetro_ : `string s` - Cadena que contiene un valor compatible con `double` . 

_Retorna_ : `double` – El valor que está representado en la cadena `s` . 

Ejemplo de uso: 

```
string s = "123.4";
double d = stringToDouble(s);
cout << d << endl; // muestra: 123.4
```

## 1.2.1.4. Función isEmpty 

_Prototipo_ : `bool isEmpty(string s);` 

_Descripción_ : Retorna `true` o `false` según `s` sea o no la cadena vacía. 

_Parámetro_ : `string s` - Una cadena de caracteres. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 41 

_Retorna_ : `bool` – Retorna `true` si `s` es la cadena vacía o `false` si no lo es. 

Ejemplo de uso: 

```
string s = "";
cout << isEmpty(s) << endl; // true
s = "Hola";
cout << isEmpty(s) << endl; // false
s = "    ";
cout << isEmpty(s) << endl; // false
```

## 1.2.1.5. Función startsWith 

_Prototipo_ : `bool startsWith(string s,string x);` 

_Descripción_ : Determina si `x` es prefijo de `s` . 

_Parámetros_ : 

- `string s` - Cadena que podría comenzar con `x` . 

- `char x` – Cadena que podría ser prefijo de `s` . 

_Retorna_ : `bool` - `true` si `x` es prefijo de `s` . 

Ejemplo de uso: 

```
string s1 = "cursoDeAlgoritmos";
string s2 = "curso";
if( startsWith(s1,s2) )
{
cout << s2 << " es prefijo de: " << s1 << endl;
}
```

## 1.2.1.6. Función endsWith 

_Prototipo_ : `bool endsWith(string s,string x);` 

_Descripción_ : Determina si `x` es sufijo de `s` . 

_Parámetros_ : 

- `string s` - Cadena que podría finalizar con `x` . 

- `char x` – Cadena que podría ser sufijo de `s` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

42 |[Apéndice 2 ● Especificaciones y API] 

_Retorna_ : `bool` - `true` si `x` es sufijo de `s` . 

Ejemplo de uso: 

```
string s1 = "cursoDeAlgoritmos";
string s2 = "Algoritmos";
if( endsWith(s1,s2) )
{
cout << s2 << " es sufijo de: " << s1 << endl;
}
```

## 1.2.1.7. Función contains 

_Prototipo_ : `bool contains(string s,char c);` 

_Descripción_ : Determinar si la cadena `s` contiene al carácter `c` . 

_Parámetros_ : 

- `string s` - Cadena que podría contener al carácter `c` . 

- • `char c` - Carácter cuyo valor podría estar contenido en `s` . 

_Retorna_ : `bool` - `true` si `s` contiene a `c` ; `false` si no lo contiene. 

Ejemplo de uso: 

```
string s = "abcd";
char c = 'b';
if( contains(s,c) )
{
cout << s << " contiene a: " << c << endl;
}
c = 'X';
if( !contains(s,c) )
{
cout << s << " NO contiene a: " << c << endl;
}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 43 

## 1.2.1.8. Función replace 

_Prototipo_ : `string replace(string s,char oldChar,char newChar);` 

_Descripción_ : Reemplaza en `s` todas las ocurrencias de `oldChar` por `newChar` . Parámetros: 

- `string s` - Cadena sobre la cual se reemplazarán los caracteres. 

- `char oldChar` - Carácter que va a ser reemplazado por `newChar` . 

- `char newChar` - Valor que reemplazará todas las ocurrencias de `oldChar` . 

_Retorna_ : `string` - La cadena `s` con caracteres `oldChar` donde antes tenía `oldChar` . 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
string r = replace(s,'e','X');
cout << r << endl;// SALIDA: Esto Xs una pruXba
```

## 1.2.1.9. Función insertAt 

_Prototipo_ : `string insertAt(string s,int pos,char c);` 

_Descripción_ : Insertar el carácter c en la posición pos de la cadena s. 

Parámetros: 

- `string s` - Cadena de caracteres donde se insertará un carácter. 

- `int pos` - Posición de `s` se va a insertar al carácter `c` . 

- `char c` - Carácter que se insertará en `s` , en la posición `pos` . 

_Retorna_ : `string` - Una cadena cuya longitud será `length(s)` +1, idéntica a `s` pero con el valor de `c` insertado en la posición `pos` . 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
int pos = 6;
char c = 'X';
string r = insertAt(s,pos,c);
cout << r << endl; // SALIDA: Esto eXs una prueba
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

44 |[Apéndice 2 ● Especificaciones y API] 

## 1.2.1.10. Función removeAt 

_Proototipo_ : `string removeAt(string s,int pos);` 

_Descripción_ : Remover de s el carácter ubicado en la posición pos. 

_Parámetros_ : 

- `string s` - Cadena de caracteres sobre la cual se removerá un carácter. 

- `int pos` - Posición del carácter que se removerá. 

_Retorna_ : `string` - Una cadena igual a `s` pero sin `s[pos]` . 

Ejemplo de uso: 

```
string s = "Esto es una prueba";
int pos = 7;
string r = removeAt(s,pos);
cout << r << endl;  // SALIDA: Esto esuna prueba
```

## 1.2.1.11. Función ltrim 

_Prototipo_ : `string ltrim(string s);` 

_Descripción_ : Recorta los espacios en blanco que se encuentren a la izquierda de `s` . 

_Parámetro_ : `string s` - Cadena que podría tener espacios a la izquierda. 

_Retorna_ : `string` - Una cadena idéntica a `s` pero sin espacios a la izquierda. 

Ejemplo de uso: 

```
string s = "   Esto es una prueba"; // espacios a izq
string r = ltrim(s);
cout << "[" << r << "]" << endl; // [Esto es una prueba]
s = "Esto es una prueba"; // sin espacios
r = ltrim(s);
cout << "[" << r << "]" << endl; // [Esto es una prueba]
s = "   Esto es una prueba   "; // espacios a izq y der
r = ltrim(s);
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 45 

```
cout << "[" << r << "]" << endl; // [Esto es una prueba   ]
```

## 1.2.1.12. Función rtrim 

_Prototipo_ : `string rtrim(string s);` 

_Descripción_ : Recortar los espacios en blanco a la derecha de `s` . 

_Parámetro_ : `string s` - Cadena que podría tener espacios a la derecha. 

_Retorna_ : `string` - Una cadena idéntica a `s` sin espacios en blanco a la derecha. 

Ejemplo de uso: 

```
string s = "Esto es una prueba   "; // espacios a der
string r = rtrim(s);
cout << "[" << r << "]" << endl; // [Esto es una prueba]
s = "Esto es una prueba"; // sin espacios
r = rtrim(s);
cout << "[" << r << "]" << endl; // [Esto es una prueba]
s = "   Esto es una prueba   "; // espacios a izq y der
r = rtrim(s);
cout << "[" << r << "]" << endl; // [   Esto es una prueba]
```

## 1.2.1.13. Función trim 

_Prototipo_ : `string trim(string s);` 

_Descripción_ : Recortar los espacios en blanco ubicados a izquierda y derecha de `s` . 

_Parámetro_ : `string s` - Cadena que podría contener espacios en los extremos. 

_Retorna_ : `string` - Una cadena idéntica a `s` sin espacios en los extremos. 

Ejemplo de uso: 

```
// con espacios a izquierda y derecha
string s = "   Esto es una prueba   ";
string r = trim(s);
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

46 |[Apéndice 2 ● Especificaciones y API] 

```
cout << "[" << r << "]" << endl; // [Esto es una prueba]
// con espacios dentro de la cadena
s = "Esto   es una prueba";
r = rtrim(s);
cout << "[" << r << "]" << endl; // [Esto   es una prueba]
```

## 1.2.1.14. Función replicate 

_Prototipo_ : `string replicate(char c,int n);` 

_Descripción_ : Generar una cadena de caracteres compuesta por `n` caracteres `c` . 

_Parámetros_ : 

- `char c` - Carácter que se replicará `n` veces para generar la cadena. 

- `int n` - Cantidad de caracteres que tendrá la cadena generada. 

_Retorna_ : `string` - Una cadena compuesta por n caracteres c. 

Ejemplo de uso: 

```
int n = 5;
char c = 'X'
string r = replicate(c,n);
cout << "[" << r << "]" << endl; // muestra: [XXXXX]
c = ' ';
r = replicate(c,n);
cout << "[" << r << "]" << endl; // muestra: [     ]
```

## 1.2.1.15. Función spaces 

_Prototipo_ : `string spaces(int n);` 

_Descripción_ : Genera una cadena de caracteres compuesta por `n` caracteres `' '` . 

_Parámetro_ : `int n` – Longitud de la cadena que se generará. 

_Retorna_ : `string` - Una cadena compuesta por n caracteres `' '` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 47 

```
int n = 5;
string r = spaces(n);
// muestra: [     ] (cinco espacios)
cout << "[" << r << "]" << endl;
```

## 1.2.1.16. Función lpad 

_Prototipo_ : `string lpad(string s,int n,char c);` 

_Descripción_ : Retorna una cadena idéntica a `s` , con longitud `n` completando, si fuese necesario, con caracteres `c` a la izquierda hasta llegar a la longitud requerida. 

## _Parámetros_ : 

- `int n` - Longitud final que tendrá la cadena. 

- `char c` - Carácter con que se completará a `s` si fuera necesario. 

_Retorna_ : `string` - Una cadena de longitud `n` compuesta por `n-length(s)` caracteres `c` seguidos de la cadena `s` . 

Ejemplo de uso: 

```
string s = "Hola";
int n = 10;
char c = 'X';
string r = lpad(s,n,c);
cout << "[" << r << "]" << endl; // muestra: [XXXXXXHola]
```

## 1.2.1.17. Función rpad 

_Prototipo_ : `string rpad(string s,int n,char c);` 

_Descripción_ : Idem `lpad` pero, de ser necesario, agrega caracteres `c` a la derecha. 

## _Parámetros_ : 

- `int n` - Longitud final que tendrá la cadena retornada. 

- `char c` - Carácter con que se debe completará la cadena. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

48 |[Apéndice 2 ● Especificaciones y API] 

_Retorna_ : `string` - Una cadena de longitud `n` compuesta por el contenido de `s` seguida de `n-length(s)` caracteres `c` . 

Ejemplo de uso: 

```
string s = "Hola";
int n = 10;
char c = 'X';
string r = rpad(s,n,c);
cout << "[" << r << "]" << endl; // muestra: [HolaXXXXXX]
```

## 1.2.1.18. Función cpad 

_Prototipo_ : `string cpad(string s,int n,char c);` 

_Descripción_ : Idem `rpad` pero distribuye los caracteres c a izquierda y derecha. 

_Parámetros_ : 

- `int n` - Longitud final que tendrá la cadena. 

- `char c` - Carácter con que se completará si fuerea necesario. 

_Retorna_ : `string` - Una cadena de longitud `n` compuesta por `s` y caracteres `c` distribuidos a la izquierda y a la derecha de modo tal que su longitud final sea `n` . 

Ejemplo de uso: 

```
string s = "Hola";
int n = 10;
char c = 'X';
string r = cpad(s,n,c);
cout << "[" << r << "]" << endl; // muestra: [XXXHolaXXX]
```

## 1.2.1.19. Función isDigit 

_Prototipo_ : `bool isDigit(char c);` 

_Descripción_ : Determinar si el valor de `c` corresponde o no a un dígito numérico. 

_Parámetro_ : `char c` - Carácter a determinar si representa a un dígito numérico. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 49 

_Retorna_ : `bool` - `true` si `c` es '0', '1', '2', ..., '9', `false` en cualquier otro caso. Ejemplo de uso: 

```
char c = '9';
if( isDigit(c) )
{
cout << c << " es digito" << endl; // SALIDA
}
c = 'A';
if( !isDigit(c) )
{
cout << c << " NO es digito" << endl; // SALIDA
}
```

## 1.2.1.20. Función isLetter 

_Prototipo_ : `bool isLetter(char c);` 

_Descripción_ : Determina si el valor de `c` corresponde o no a una letra. 

_Parámetro_ : `char c` - Carácter a determinar si representa a una letra. 

_Retorna_ : `bool` - `true` si `c` es 'A', 'B', 'C', ..., 'Z' o 'a', 'b', 'c', ..., 'z'. Si no retorna `false` . 

Ejemplo de uso: 

```
char c = 'X';
if( isLetter(c) )
{
cout << c << " es letra" << endl; // SALIDA
}
c = '9';
if( !isLetter(c) )
{
cout << c << " NO es letra" << endl; // SALIDA
}
```

## 1.2.1.21. Función isUpperCase 

_Prototipo_ : `bool isUpperCase(char c);` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

50 |[Apéndice 2 ● Especificaciones y API] 

_Descripción_ : Determinar si el valor de `c` corresponde a una letra mayúscula. _Parámetro_ : `char c` - Carácter para determinar si es una letra mayúscula. _Retorna_ : `bool` - `true` si `c` es 'A', 'B', 'C', ..., 'Z', `false` en cualquier otro caso. Ejemplo de uso: 

```
char c = 'X';
if( isUpperCase(c) )
{
cout << c << " es letra mayuscula" << endl; // SALIDA
}
c = 'x';
if( !isUpperCase(c) )
{
cout << c << " NO es mayuscula" << endl; // SALIDA
}
```

## 1.2.1.22. Función isLowerCase 

_Prototipo_ : `bool isLowerCase(char c);` _Descripción_ : Determina si el valor de `c` corresponde a una letra minúscula. _Parámetro_ : `char c` - Carácter a debe determinar si contiene una letra minúscula. _Retorna_ : `bool - true` si `c` es 'a', 'b', 'c', ..., 'z', `false` en cualquier otro caso. Ejemplo de uso: 

```
char c = 'a';
if( isLowerCase(c) )
{
cout << c << " es letra minuscula" << endl; // SALIDA
}
c = 'A';
if( !isLowerCase(c) )
{
cout << c << " NO es minuscula" << endl; // SALIDA
}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 51 

## 1.2.1.23. Función toUpperCase 

_Prototipo_ : `char toUpperCase(char c);` 

_Descripción_ : Convertir el valor de `c` a mayúscula. 

_Parámetro_ : `char c` - El carácter cuyo valor se debe convertir a mayúscula. 

_Retorna_ : `char` – Si `c` es una letra minúscula retorna su mayúscula, en cualquier otro caso retorna el mismo valor de `c` . 

Ejemplo de uso: 

```
char c = 'a';
char r = toUpperCase(c);
cout << r << endl; // Salida: A (convierte a mayuscula)
c = 'B';
r = toUpperCase(c);
cout << r << endl; // Salida: B (ya era mayuscula)
c = '9';
r = toUpperCase(c);
cout << r << endl; // Salida: 9 (no es una letra)
```

## 1.2.1.24. Función toLowerCase 

_Prototipo_ : `char toLowerCase(char c);` 

_Descripción_ : Convierte el valor de `c` a minúscula. 

_Parámetro_ : `char c` - El carácter cuyo valor se debe convertir a minúscula. 

_Retorna_ : `char` – Si `c` es un una letra mayúscula retorna su minúscula, en cualquier otro caso retorna el mismo carácter `c` . 

Ejemplo de uso: 

```
char c = 'A';
char r = toLowerCase(c);
cout << r << endl; // Salida: a (convierte a minuscula)
c = 'b';
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

52 |[Apéndice 2 ● Especificaciones y API] 

```
r = toLowerCase(c);
cout << r << endl; // Salida: b (ya era minuscula)
c = '9';
r = toLowerCase(c);
cout << r << endl; // Salida: 9 (no es una letra)
```

## 1.2.1.25. Función toUpperCase (sobrecarga) 

_Prototipo_ : `string toUpperCase(string s);` 

_Descripción_ : Retorna una cadena idéntica a `s` pero completamente en mayúsculas. 

_Parámetro_ : `string s` – Cadena cuyo valor se debe convertir a mayúscula. 

_Retorna_ : `string` – Una cadena igual a `s` pero totalmente en mayúsculas. 

Ejemplo de uso: 

```
string s = "hola";
string r = toUpperCase(s);
cout << r << endl; // Salida: HOLA
```

## 1.2.1.26. Función toLowerCase  (sobrecarga) 

_Prototipo_ : `string toLowerCase(string s);` 

_Descripción_ : Retorna una cadena idéntica a `s` pero completamente en minúsculas. 

_Parámetro_ : `string s` – Cadena cuyo valor se debe convertir a minúsculas. 

_Retorna_ : `string` – Una cadena igual a `s` pero totalmente en munúsculas. 

Ejemplo de uso: 

```
string s = "HOLA";
string r = toLowerCase(s);
cout << r << endl; // Salida: hola
```

## 1.2.1.27. Función cmpString 

_Prototipo_ : `int cmpString(string a,string b);` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 53 

_Descripción_ : Compara alfabéticamente dos cadenas. 

_Parámetros_ : 

- `string a` – Cadena a comparar. 

- `string b` – Cadena a comparar. 

_Retorna_ : `int` – Un valor negativo si `a` es alfabéticamente menor que `b` . Un valor positivo si `a` es alfabéticamente mayor que `b` , o 0 si ambas cadenas son iguales. 

Ejemplo de uso: 

```
string s1 = "Carlos";
string s2 = "Pablo";
```

```
if( cmpString(s1,s2)<0 )
{
   cout << s1 << " es menor que: " << s2 << endl;
}
```

## 1.2.1.28. Función cmpDouble 

_Prototipo_ : `int cmpDouble(double a,double b);` 

_Descripción_ : Compara dos valores. 

_Parámetros_ : 

- `double a` – Valor a comparar. 

- `double b` – Valor a comparar. 

_Retorna_ : `int` – Un valor negativo si `a` es menor que `b` . Un valor positivo si `a` es mayor que `b` , o 0 si ambos valores son iguales. 

Ejemplo de uso: 

```
double x = 25.7;
double y = 36.9;
```

```
if( cmpDouble(x,y)<0 )
{
   cout << x << " es menor que: " << y << endl;
}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

54 |[Apéndice 2 ● Especificaciones y API] 

## 1.3. Lección 5 

## 1.3.1. API de tratamiento de tokens 

La siguientes funciones deben programarse en el archivo `tokens.hpp` . 

## 1.3.1.1. Función tokenCount 

_Prototipo_ : `int tokenCount(string s,char sep);` 

_Descripción_ : Cuenta la cantidad _tokens_ que el separador `sep` genera en `s` . 

_Parámetros_ : 

- `string s` – Cadena _tokenizada_ . 

- `char sep` – Carácter separador. 

_Retorna_ : `int` – Cuántos _tokens_ genera `sep` en la cadena `s` . 

Ejemplo de uso: 

```
string s = "John|Paul|George|Ringo";
char sep = '|';
int n = tokenCount(s,sep);
cout << n << endl; // Salida: 4
s = "John";
sep = '|';
n = tokenCount(s,sep);
cout << n << endl; // Salida: 1
s = "";
sep = '|';
n = tokenCount(s,sep);
cout << n << endl; // Salida: 0
```

## 1.3.1.2. Función addToken 

_Prototipo_ : `void addToken(string& s,char sep,string t);` 

_Descripción_ : Agrega el _token_ `t` al final de la cadena `s` . 

_Parámetros_ : 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 55 

- `string& s` - Cadena _tokenizada_ 

- `char sep` - Carácter separador. 

- `string t` - _Token_ que se agregará al final de `s` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
string s = "";
char sep = '|';
addToken(s,sep,"John");
cout << s << endl; // Salida: John
addToken(s,sep,"Paul");
cout << s << endl; // Salida: John|Paul
addToken(s,sep,"George");
cout << s << endl; // Salida: John|Paul|George
addToken(s,sep,"Ringo");
cout << s << endl; // Salida: John|Paul|George|Ringo
```

## 1.3.1.3. Función getTokenAt 

_Prototipo_ : `string getTokenAt(string s,char sep,int i);` 

_Descripción_ : Retorna el _i_ -ésimo _token_ de la cadena _tokenizada_ `s` 

Parámetros: 

- `string s` - Cadena _tokenizada_ . 

- `char sep` - Carácter separador. 

- `int i` - Posición del _token_ que se quiere obtener comenzando desde la izquierda y contando a partir de 0 (cero). 

_Retorna_ : `string` - El token ubicado en la posición _i_ de la cadena `s` . 

Ejemplo de uso: 

```
string s = "John|Paul|George|Ringo";
char sep = '|';
int pos = 0;
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

56 |[Apéndice 2 ● Especificaciones y API] 

```
string t = getTokenAt(s,sep,pos);
cout << t << endl; // Salida: John
pos = 1;
t = getTokenAt(s,sep,pos);
cout << t << endl; // Salida: Paul
pos = 2;
t = getTokenAt(s,sep,pos);
cout << t << endl; // Salida: George
pos = 3;
t = getTokenAt(s,sep,pos);
cout << t << endl; // Salida: Ringo
```

## 1.3.1.4. Función removeTokenAt 

_Prototipo_ : `void removeTokenAt(string& s,char sep,int i);` 

_Descripción_ : Remueve de `s` el _token_ ubicado en la posición `i` . 

_Parámetros_ : 

- `string& s` - Cadena tokenizada. 

- `char sep` - Carácter separador. 

- • `char i` - Posición del _token_ que será removido de la cadena `s` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
string s = "John|Paul|George|Ringo";
char sep = '|';
int i = 2;
removeTokenAt(s,sep,i);
cout << s << endl; // Salida: John|Paul|Ringo
i = 0;
removeTokenAt(s,sep,i);
cout << s << endl; // Salida: Paul|Ringo
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 57 

## 1.3.1.5. Función setTokenAt 

_Prototipo_ : `void setTokenAt(string& s,char sep,string t,int i);` 

_Descripción_ : Reemplaza por `t` el _token_ de `s` ubicado en la posición `i` Parámetros: 

- `string& s` - Cadena _tokenizada_ . 

- `char sep` - Carácter separador. 

- `string t` - Valor del nuevo _token_ 

- `int i` - Posición del _token_ que se será reemplazado por `t` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
string s = "John|Paul|George|Ringo";
char sep = '|';
int i = 1;
string t = "McCartney";
setTokenAt(s,sep,t,i);
cout << s << endl; // Salida: John|McCartney|George|Ringo
```

## 1.3.1.6. Función findToken 

_Prototipo_ : `int findToken(string s,char sep,string t);` 

_Descripción_ : Determinar la posición que el token t ocupa dentro de la cadena s. 

Parámetros: 

- `string s` - Cadena tokenizada. 

- `char sep` - Carácter separador. 

- `string t` - _Token_ a buscar en la cadena `s` . 

_Retorna_ : `int` - La posición de la primera ocurrencia del _token_ `t` dentro de la cadena `s` , o un valor negativo si `s` no contiene a `t` . 

Ejemplo de uso: 

```
string s = "John|Paul|George|Ringo";
char sep = '|';
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

58 |[Apéndice 2 ● Especificaciones y API] 

```
string t = "Paul";
int p = findToken(s,sep,t);
cout << p << endl; // Salida: 1
string t = "John";
p = findToken(s,sep,t);
cout << p << endl; // Salida: 0
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 59 

## 1.4. Lección 7 

Comenzaremos analizando algunos ejemplos que ilustran la mayor parte de los casos de uso del TAD `Coll` . Luego pasaremos a las especificaciones. 

## 1.4.1. TAD Coll (ejemplos de uso) 

## 1.4.1.1. Crear una colección, agregarle elementos e iterarla 

```
Coll<string> c = coll<string>();
collAdd<string>(c,"John",stringToString);
collAdd<string>(c,"Paul",stringToString);
collAdd<string>(c,"George",stringToString);
collAdd<string>(c,"Ringo",stringToString);
collReset<string>(c);
while( collHasNext<string>(c) )
{
   string s = collNext<string>(c,stringToString);
cout << s << endl;
}
```

## 1.4.1.2. Iterar la colección, otra posibilidad 

```
Coll<string> c = coll<string>();
collAdd<string>(c,"John",stringToString);
collAdd<string>(c,"Paul",stringToString);
collAdd<string>(c,"George",stringToString);
collAdd<string>(c,"Ringo",stringToString);
```

```
collReset<string>(c);
```

```
bool endOfColl;
```

```
string s = collNext<string>(c,endOfColl,stringToString);
while( !endOfColl )
{
cout << s << endl;
   s = collNext<string>(c,endOfColl,stringToString);
}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

60 |[Apéndice 2 ● Especificaciones y API] 

## 1.4.1.3. Iterar la colección usando un ciclo for 

```
Coll<string> c = coll<string>();
collAdd<string>(c,"John",stringToString);
collAdd<string>(c,"Paul",stringToString);
collAdd<string>(c,"George",stringToString);
collAdd<string>(c,"Ringo",stringToString);
```

```
for(int i=0; i<collSize<string>(c); i++)
{
   string s = collGetAt<string>(c,i,stringToString);
cout << s << endl;
}
```

## 1.4.1.4. Acceso directo a los elementos de la colección 

```
Coll<string> c = coll<string>();
collAdd<string>(c,"John",stringToString);
collAdd<string>(c,"Paul",stringToString);
collAdd<string>(c,"George",stringToString);
collAdd<string>(c,"Ringo",stringToString);
```

```
int pos = 2;
string s = collGetAt<string>(c,pos,stringToString);
cout << s << endl; // George
```

## 1.4.1.5. Reemplazar un elemento de la colección 

```
Coll<string> c = coll<string>();
collAdd<string>(c,"John",stringToString);
collAdd<string>(c,"Paul",stringToString);
collAdd<string>(c,"George",stringToString);
collAdd<string>(c,"Ringo",stringToString);
```

```
int pos = 2;
string nuevo = "George Harrison";
collSetAt<string>(c,nuevo,pos,stringToString);
string s = collGetAt<string>(c,pos,stringToString);
cout << s << endl;  // George Harrison
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 61 

## 1.4.1.6. Remover un elemento de la colección 

```
Coll<string> c = coll<string>();
collAdd<string>(c,"John",stringToString);
collAdd<string>(c,"Paul",stringToString);
collAdd<string>(c,"George",stringToString);
collAdd<string>(c,"Ringo",stringToString);
```

```
int pos = 2;
// Salida: George
cout << collGetAt<string>(c,pos,stringToString) << endl;
collRemoveAt<string>(c,pos);
// Salida: Ringo
cout << collGetAt<string>(c,pos,stringToString) << endl;
```

## 1.4.1.7. Buscar un elemento dentro de la colección 

```
struct Persona
{
int dni; // documento nacional de identidad
   string nombre;
};
```

**==> picture [362 x 36] intentionally omitted <==**

```
Coll<Persona> c = coll<Persona>();
collAdd<Persona>(c,persona(11,"Juan"),personaToString);
collAdd<Persona>(c,persona(44,"Pedro"),personaToString);
collAdd<Persona>(c,persona(33,"Carlos"),personaToString);
collAdd<Persona>(c,persona(22,"Pablo"),personaToString);
```

```
int dni=33;
int pos = collFind<Persona,int>(c
                               ,dni
                               ,cmpPersonaDNI
                               ,personaFromString);
Persona p = collGetAt<Persona>(c,pos,personaFromString);
cout << personaToString(p) << endl;
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

62 |[Apéndice 2 ● Especificaciones y API] 

```
int cmpPersonaDNI(Persona p,int dni)
{
return p.dni-dni;
}
```

## 1.4.1.8. Ordenar una colección 

```
struct Persona
{
int dni; // documento nacional de identidad
   string nombre;
};
```

**==> picture [362 x 36] intentionally omitted <==**

```
Coll<Persona> c = coll<Persona>();
collAdd<Persona>(c,persona(11,"Juan"),personaToString);
collAdd<Persona>(c,persona(44,"Pedro"),personaToString);
collAdd<Persona>(c,persona(33,"Carlos"),personaToString);
collAdd<Persona>(c,persona(22,"Pablo"),personaToString);
// ordenamos por nombre alfabeticamente
collSort<Persona>(c
                 ,cmpPersonaNombre
                 ,personaFromString
                 ,personaToString);
// iteramos y mostramos
mostrarColeccion(c);
// ordenamos por DNI ascendente
collSort<Persona>(c
                 ,cmpPersonaDNI
                 ,personaFromString
                 ,personaToString);
// iteramos y mostramos
mostrarColeccion(c);
```

```
void mostrarColeccion(Coll<Persona> c){
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 63 

```
   collReset<Persona>(c);
while( collHasNext<Persona>(c) )
   {
      Persona p = collNext<Persona>(c,personaFromString);
cout << personaToString(p) << endl;
   }
}
```

**==> picture [362 x 39] intentionally omitted <==**

```
int cmpPersonaNombre(Persona p,String nombre)
{
   return cmpString(p.nombre,nombre);
}
```

```
int cmpPersonaDNI(Persona p,int dni)
{
return p.dni-dni;
}
```

## 1.4.2. TAD Coll (API) 

La siguientes funciones deben programarse en el archivo `Coll.hpp` . 

## 1.4.2.1. Estructura del TAD 

```
template<typename T>
struct Coll
{
   // implementacion a cargo del estudiante
};
```

## 1.4.2.2. Función coll 

_Prototipo_ : `Coll<T> coll(char sep);` 

_Descripción_ : Crea una colección vacía, preparada para contener elementos de tipo `T` ; utilizando el carácter `sep` como separador de la cadena _tokenizada_ sobre la que se implementa la colección. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

64 |[Apéndice 2 ● Especificaciones y API] 

_Parámetro_ : `char sep` – Carácter separador. 

_Retorna_ : `Coll<T>` - Una colección vacía preparada para contener elementos tipo `T` . 

## 1.4.2.3. Función coll (sobrecarga) 

_Prototipo_ : `Coll<T> coll();` 

_Descripción_ : Crea una colección vacía, preparada para contener elementos tipo `T` ; definiendo un separador por defecto para usar en la cadena _tokenizada_ sobre la cual se implementa la colección. 

_Retorna_ : `Coll<T>` - Una colección vacía preparada para contener elementos tipo `T` . 

## 1.4.2.4. Función collSize 

_Prototipo_ : `int collSize(Coll<T> c);` 

_Descripción_ : Retorna la cantidad de elementos que contiene la colección `c` 

_Parámetro_ : `Coll<T> c` - Colección para determinar cuántos elementos tiene. 

_Retorna_ : `int` - Cantidad de elementos que tiene la colección `c` . 

## 1.4.2.5. Función collRemoveAll 

_Prototipo_ : `void collRemoveAll(Coll<T>& c);` 

_Descripción_ : Remueve de la colección `c` todos sus elementos, dejándola vacía. 

_Parámetro_ : `Coll<T>& c` - Colección cuyos elementos serán removidos. 

_Retorna_ : `void` 

## 1.4.2.6. Función collRemoveAt 

_Prototipo_ : `void collRemoveAt(Coll<T>& c,int p);` 

_Descripción_ : Remueve de la colección `c` el elemento ubicado en la posición `p` _Parámetros_ : 

- `Coll<T>& c` - Colección de la cual se eliminará un elemento. 

- • `int p` - Posición del elemento que se eliminará. 

_Retorna_ : `void` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 65 

## 1.4.2.7. Función collAdd 

Prototipo: `int collAdd(Coll<T>& c,T t,string tToString(T));` 

_Descripción_ : Agrega el elemento `t` al final de la colección `c` . 

Parámetros: 

- `Coll<T>& c` - La colección. 

- `T t` - Elemento que se va a agregar al final de `c` . 

- `string tToString(T)` - Función que convierte de `T` a `string` 

_Retorna_ : `int` - La posición que ocupa el elemento recientemente agregado. Coincide con el tamaño de la colección, menos 1. 

## 1.4.2.8. Función collSetAt 

_Prototipo_ : `void collSetAt(Coll<T>& c ,T t ,int p ,string tToString(T));` 

_Descripción_ : Reemplaza por `t` al elemento que se ubica en la posición `p` . 

Parámetros: 

- `Coll<T>& c` - La colección. 

- `T t` - Elemento que se asignará en la posición `p` 

- `int p` - Posición donde quedará asignado `t` . 

- `string tToString(T)` - Función que convierte de `T` a `string` . 

_Retorna_ : `void` . 

## 1.4.2.9. Función collGetAt 

_Prototipo_ : `T collGetAt(Coll<T> c,int p,T tFromString(string));` _Descripción_ : Retorna el elemento que se ubica en la posición `p` de la colección `c` . Parámetros: 

- `Coll<T> c` - La colección. 

- `int p` - Posición del elemento al que se quiere acceder. 

- `T tFromString(string)` – Función que convierte de `string` a `T` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

66 |[Apéndice 2 ● Especificaciones y API] 

_Retorna_ : `T` - El elemento de `c` ubicado en la posición `p` . 

## 1.4.2.10. Función collFind 

Prototipo: `int collFind(Coll<T> c ,K k ,int cmpTK(T,K) ,T tFromString(string));` 

_Descripción_ : Determina si la colección `c` contiene al elemento `k` . 

_Parámetros_ : 

- `Coll<T> c` - La colección. 

- `K k` - Elemento que se debe buscar dentro de `c` . 

- `int cmpTK(T,K)` - Función que compara un elemento tipo `T` ( _t_ ) con otro tipo `K` ( _k_ ) y retorna: negativo si _t_ < _k_ ; cero si _t_ == _k_ o positivo si _t_ > _k_ . 

- `T tFromString(string)` - Función que convierte de `string` a `T` . 

_Retorna_ : `int` - La posición que ocupa la primera ocurrencia de `k` dentro de `c` o un valor negativo si `c` no contiene a `k` . 

Ejemplo de uso: 

## 1.4.2.11. Función collSort 

_Prototipo_ : `void collSort(Coll<T>& c ,int cmpTT(T,T) ,T tFromString(string) ,string tToString(T));` 

_Descripción_ : Ordena los elementos de la colección `c` según el criterio de precedencia que establece `cmpTT` . 

_Parámetros_ : 

- `Coll<T>& c` - La colección. 

- `int cmpTT(T,T)` - Función que compara dos elementos tipo `T` ( _t1_ , _t2_ ) y retorna: negativo si _t1_ < _t2_ ; cero si _t1_ == _t2_ ; positivo si _t1_ > _t2_ . 

- `T tFromString(string)` - Función que convierte de `string` a `T` . 

- `string tToString(T)` - Función que convierte de `T` a `string` . 

_Retorna_ : `void` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 67 

## 1.4.2.12. Función collHasNext 

_Prototipo_ : `bool collHasNext(Coll<T> c);` 

_Descripción_ : Retorna `true` o `false` según queden, en la colección `c` , más elementos para continuar iterando. 

_Parámetro_ : `Coll<T> c` – La colección. 

_Retorna_ : `bool` - `true` o `false` según queden o no elementos para continuar iterando sobre la colección `c` . 

## 1.4.2.13. Función collNext 

_Prototipo_ : `T collNext(Coll<T>& c,T tFromString(string));` 

_Descripción_ : Retorna el próximo elemento de la colección `c` . 

_Parámetros_ : 

- `Coll<T>& c` - La colección. 

- `T tFromString(string)` - Función que convierte de `string` a `T` . 

_Retorna_ : `T` - El siguiente elemento de la colección `c` . 

## 1.4.2.14. Función collNext (sobrecarga) 

_Prototipo_ : `T collNext(Coll<T>& c,bool& eoc,T tFromString(string));` _Descripción_ : Retorna el próximo elemento de la colección `c` , indicando si se llegó al final de la colección. De este modo, permite prescindir de usar `collHasNext` . 

_Parámetros_ : 

- `Coll<T>& c` - La colección. 

- `bool& eoc` – Variable para indicar si se llegó al final de la colección. 

- • `T tFromString(string)` - Función que convierte de `string` a `T` . 

_Retorna_ : `T` - El siguiente elemento de la colección `c` . 

## 1.4.2.15. Función collReset 

_Prototipo_ : `void collReset(Coll<T>& c);` 

_Descripción_ : Reinicia la colección `c` para que la podamos volver a iterar. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

68 |[Apéndice 2 ● Especificaciones y API] 

_Parámetro_ : `Coll<T>& c` - La colección. 

_Retorna_ : `void` . 

## 1.4.3. TAD Mtx (ejemplos de uso) 

**==> picture [60 x 8] intentionally omitted <==**

**----- Start of picture text -----**<br>
Matrices y cubos<br>**----- End of picture text -----**<br>


Veremos a continuación cómo usar el TAD `Mtx` (matriz) para declarar una estructura de datos bidimensional (una matriz). En el siguiente ejemplo, observamos como podemos crear una matriz de 3 filas por 3 columnas, cuya capacidad permitirá contener 9 cadenas de caracteres ( `T` ). El valor inicial que se le asignará a cada celda será: “X”. 

_`// matriz de 3x3 (filas/columnas) de cadenas`_ `Mtx<string> m = mtx<string>(3,3,"X",stringToString);` 

_`// completamos la fila 0`_ `mtxSetAt<string>(m,"Matteo",0,0,stringToString); mtxSetAt<string>(m,"Pablo",0,1,stringToString); mtxSetAt<string>(m,"Juan",0,2,stringToString);` 

_`// valores de la fila 1`_ `mtxSetAt<string>(m,"Carlos",1,0,stringToString); mtxSetAt<string>(m,"Roberto",1,1,stringToString); mtxSetAt<string>(m,"Analia",1,2,stringToString);` 

_`// valores para la fila 2`_ `mtxSetAt<string>(m,"Claudia",2,0,stringToString); mtxSetAt<string>(m,"Ivan",2,1,stringToString); mtxSetAt<string>(m,"Johana",2,2,stringToString);` 

_`// recorremos por fila`_ **`for`** `(` **`int`** `f=0; f<3; f++) {` _`// recorremos por columna`_ **`for`** `(` **`int`** `c=0; c<3; c++) {` _`// obtenemos el elemento ubicado en celda [f,c]`_ `string x = mtxGetAt<string>(m,f,c,stringToString);` _`// mostramos el elemento que obtuvimos`_ **`cout`** `<< x <<` **`endl`** `;` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 69 

```
   }
}
```

## 1.4.4. TAD Mtx (API) 

La siguientes funciones deben programarse en el archivo `MultidimColl.hpp` . 

## 1.4.4.1. Estructura del TAD 

```
template<typename T>
struct Mtx
{
   // Se debe usar el TAD Coll para implentar la estructura Mtx
};
```

## 1.4.4.2. Función mtx 

_Prototipo_ : `Mtx<T> mtx(int rows ,int cols ,T defaultValue ,string tToString(T));` 

_Descripción_ : Crea y retorna una matriz de `rows` filas por `cols` columnas, asignando `defaultValue` a cada una de las `rows` * `cols` celdas. 

_Parámetros_ : 

- `int rows` – Cantidad de filas de la matriz. 

- `int cols` – Cantidad de columnas de la matriz. 

- `T defaultValue` – Valor inicial que recibiran las celdas de la matriz. 

- `string tToString` – Función de conversión. 

_Retorna_ : `Mtx<T>` - Una matriz de `rows*cols` celdas, inicializadas con valores `defaultValue` . 

## 1.4.4.3. Función mtxSetAt 

_Prototipo_ : `void mtxSetAt(Mtx<T> m ,T value ,int row ,int col` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

70 |[Apéndice 2 ● Especificaciones y API] 

```
                     ,string tToString(T));
```

_Descripción_ : Asigna `value` en la celda de la intersección [ `row` , `col` ] de la matriz. 

_Parámetros_ : 

- `Mtx<T>` - La matriz. 

- `T value` – Valor que se asignará en la celda [ `row` , `col` ] de la matriz. 

- • `int row` – Fila. 

- `int col` – Columna. 

- `string tToString` – Función de conversión. 

_Retorna_ : `void` . 

## 1.4.4.4. Función mtxGetAt 

_Prototipo_ : `T mtxGetAt(Mtx<T> m ,int row ,int col ,T tFromString(string));` 

_Descripción_ : Retorna el valor que contiene la matriz en la celda [ `row` , `col` ]. 

_Parámetros_ : 

- `Mtx<T>` - La matriz. 

- `int row` – Fila. 

- `int col` – Columna. 

- `string tToString` – Función de conversión. 

_Retorna_ : `T` – El valor que la matriz m contiene en la celda [ `row` , `col` ]. 

## 1.4.5. TAD Cube (ejemplos de uso) 

Veremos a continuación cómo usar el TAD `Cube` (cubo) para crear una estructura de datos tridimensional (un cubo). En el siguiente ejemplo creamos un cubo de 3 filas por 3 columnas por 3 planos (profundidad), preparado para contener 27 cadenas de caracteres ( `T` ). El valor inicial que se asignará a cada celda será: “X”. 

```
// matriz de 3x3 (filas/columnas) de cadenas
Cube<string> x = cube<string>(3,3,3,"X",stringToString);
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 71 

```
string v;
for(int f=0; f<3; f++) // fila
{
for(int c=0; c<3; c++) // columnas
   {
for(int p=0; p<3; p++) // plano o profundidad
      {
         // el usuario ingresa el valor de la celda f,c,p
cout << "Ingrese valor para la celda: ";
cout << f << "," << c << "," << p << ": ";
cin >> v;
         // asigno el valor v en la celda: f,c,p
         cubeSetAt<string>(x,v,f,c,p,stringToString);
      }
   }
}
// recorro y muestro
for(int f=0; f<3; f++)
{
for(int c=0; c<3; c++)
   {
for(int p=0; p<3; p++)
      {
         string v = cubeGetAt<string>(x,f,c,p,stringToString);
cout << "Valor de la celda ";
cout << f <<","<< c <<","<< p <<": "<< v << endl;
      }
   }
}
```

## 1.4.6. TAD Cube (API) 

La siguientes funciones deben programarse en el archivo `MultidimColl.hpp` . 

## 1.4.6.1. Estructura del TAD 

```
template<typename T>
struct Cube
{
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

72 |[Apéndice 2 ● Especificaciones y API] 

```
   // Usar el TAD Coll para implentar la estructura Cube
};
```

## 1.4.6.2. Función cube 

_Prototipo_ : `Cube<T> cube(int rows ,int cols ,int deep ,T defaultValue ,string tToString(T));` 

_Descripción_ : Crea y retorna un cubo de `rows` filas por `cols` columnas y `deep` planos, asignando `defaultValue` a cada una de las `rows` * `cols*deep` celdas. _Parámetros_ : 

- `int rows` – Cantidad de filas del cubo. 

- `int cols` – Cantidad de columnas del cubo. 

- `int deep` – Cantidad de planos (profundidad) del cubo. 

- `T defaultValue` – Valor inicial que recibiran las celdas de la cubo. 

- `string tToString` – Función de conversión. 

_Retorna_ : `Cube<T>` - Un cubo de `rows*cols*deep` celdas, inicializadas con valores 

`defaultValue` . 

## 1.4.6.3. Función cubeSetAt 

_Prototipo_ : `void cubeSetAt(Cube<T> c ,T value ,int row ,int col ,int deep ,string tToString(T));` 

_Descripción_ : Asigna `value` en la celda de la intersección [ `row` , `col` , `deep` ] del cubo `c` . 

_Parámetros_ : 

- `Cube<T>` - El cube. 

- `T value` – Valor que se asignará en la celda [ `row` , `col` , `deep` ] del cubo. 

- • `int row` – Fila. 

- `int col` – Columna. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 73 

- `int deep` – Plano o profundidad. 

- `string tToString` – Función de conversión. 

_Retorna_ : `void` . 

## 1.4.6.4. Función cubeGetAt 

_Prototipo_ : `T cubeGetAt(Mtx<T> m ,int row ,int col ,int deep ,T tFromString(string));` 

_Descripción_ : Retorna el valor que contiene el cubo en la celda [ `row` , `col` , `deep` ]. 

_Parámetros_ : 

- `Cube<T>` - El cubo. 

- `int row` – Fila. 

- `int col` – Columna. 

- `int deep` – Plano o profundidad. 

- `string tToString` – Función de conversión. 

_Retorna_ : `T` – El valor que el cubo `c` contiene en la celda [ `row` , `col` , `deep` ]. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

74 |[Apéndice 2 ● Especificaciones y API] 

## 1.5. Lección 10 

## 1.5.1. API de tratamiento de archivos de registros 

La siguientes funciones deben programarse en el archivo `files.hpp` . 

## 1.5.1.1. Función write 

_Prototipo_ : `void write(FILE* f,T t);` 

_Descripción_ : Escribe el valor `t` en la posición actual del archivo `f` . 

_Parámetros_ : 

- `FILE* f` – Archivo donde vamos a escribir. 

- `T` – valor (registro) que vamos a escribir en `f` 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
FILE* f = fopen("numeros.x","w+b");
write<short>(f,1234);
write<short>(f,4321);
write<short>(f,-9876);
fclose(f);
```

## 1.5.1.2. Función read 

_Prototipo_ : `T read(FILE* f);` 

_Descripción_ : Lee del archivo `f` un registro tipo `T` y retorna el valor leído. 

_Parámetro_ : `FILE* f` – Archivo desde el cual vamos a leer un registro. _Retorna_ : `T –` Registro leído. 

Ejemplo de uso: 

```
FILE* f = fopen("numeros.x","r+b");
short s = read<short>(f);
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 75 

```
while( !feof(f) )
{
cout << s << endl;
   s = read<short>(f);
}
fclose(f);
```

## 1.5.1.3. Función seek 

_Prototipo_ : `void seek(FILE* f,int n);` 

_Descripción_ : Mueve el indicador de posición del archivo `f` al inicio del registro `n` . _Parámetros_ : 

- `FILE* f` – Archivo cuyo indicador de posición vamos a modificar. 

- `int n` – Número de registro al que haremos apuntar el indicador de posición. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
FILE* f = fopen("numeros.x","r+b");
// apunto al tercer registro (comenzando dese cero)
seek<short>(f,2);
// leo el registro apuntado por el indicador de posicion
short v = read<short>(f);
```

## 1.5.1.4. Función fileSize 

_Prototipo_ : `int fileSize(FILE* f);` 

_Descripción_ : Retorna la cantidad de registros tipo `T` que contiene el archivo. 

_Parámetro_ : `FILE* f` – Archivo. 

_Retorna_ : `int` – Cantidad de registros tipo `T` que contiene el archivo `f` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

76 |[Apéndice 2 ● Especificaciones y API] 

```
FILE* f = fopen("numeros.x","r+b");
// mostramos el archivo desde el final hasta el inicio
for(int i=fileSize<short>(f)-1; i>=0; i--)
{
   seek<short>(f,i);
   short s = read<short>(f);
cout << s << endl;
}
fclose(f);
```

## 1.5.1.5. Función filePos 

_Prototipo_ : `int filePos(FILE* f);` 

_Descripción_ : Retorna el número de registro que está siendo apuntado por el indicador de posición del archivo `f` . 

_Parámetro_ : `FILE* f` – Archivo. 

_Retorna_ : `int` – Número de registro apuntado por el indicador de posición. 

Ejemplo de uso: 

```
FILE* f = fopen("numeros.x","r+b");
// mostramos el archivo desde el final hasta el inicio
for( int i=fileSize<short>(f)-1; i>=0; i-- )
{
   seek<short>(f,i);
   // numero de registro apuntado por el indicador de posicion
int pos = filePos<short>(f);
   short s = read<short>(f);
cout << "Registro Nro. " << pos << "," << s << endl;
}
fclose(f);
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 77 

## 1.5.1.6. Función readLine 

_Prototipo_ : `bool readLine(FILE* f,string& ln);` 

_Descripción_ : Lee una línea de texto desde el archivo `f` y la asigna a `ln` . Retorna `true` si quedan más líneas por leer. 

_Parámetros_ : 

- `FILE* f` – Archivo desde el cuál leerá una línea de texto. 

- `string& ln` – _Buffer_ donde quedará la línea leída. 

_Retorna_ : `bool` – `true` o `false` según queden o no más líneas para ser leídas. 

Ejemplo de uso: 

```
FILE* f = fopen("archivo.txt","r+b");
string ln;
bool hayMas = readLine(f,ln);
while( hayMas )
{
cout << "[" << ln << "]" << endl;
   hayMas = readLine(f,ln);
}
fclose(f);
```

## 1.5.1.7. Función readWord 

_Prototipo_ : `bool readWord(FILE* f,string& w,string alsoAllowed);` 

_Descripción_ : Lee una palabra desde el archivo `f` y la asigna a `w` , considerando que _palabra_ es un conjunto de caracteres comprendidos en `[A-Z]` , `[a-z]` , `[0-9]` más aquellos caracteres comprendidos en `alsoAllowed` . 

_Parámetros_ : 

- `FILE* f` – Archivo desde el cuál leerá una palabra. 

- `string& w` – _Buffer_ donde quedará la palabra leída. 

- `string alsoAllowed` – Cadena con los caracteres también permitidos. 

_Retorna_ : `bool` – `true` o `false` según queden o no más palabras para ser leídas. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

78 |[Apéndice 2 ● Especificaciones y API] 

Ejemplo de uso: 

Suponiendo que `archivo.txt` tiene el siguiente contenido: 

```
Este archivo es
MUY-CHICO. Por eso, nadie lo quiere
compactar_mas. Ok?
```

Entonces, el código de la izquierda mostrará la salida de la derecha. 

```
FILE* f = fopen("archivo.txt","r+b");
string w;
bool hayMas = readWord(f,w,"-_");
while( hayMas )
{
cout << "[" << w << "]" << endl;
  hayMas = readWord(f,w,"-_");
}
fclose(f);
```

```
[Este]
[Archivo]
[es]
[MUY-CHICO]
[Por]
[eso]
[nadie]
[lo]
[quiee]
[compactar_mas]
[Ok]
```

Si la cadena `alsoAlled` fuese `"-"` entonces la salida sería la siguiente. 

```
FILE* f = fopen("archivo.txt","r+b");
string w;
bool hayMas = readWord(f,w,"-");
while( hayMas )
{
cout << "[" << w << "]" << endl;
  hayMas = readWord(f,w,"-");
}
fclose(f);
```

```
[Este]
[Archivo]
[es]
[MUY-CHICO]
[Por]
[eso]
[nadie]
[lo]
[quiee]
[compactar]
[mas]
[Ok]
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 79 

## 1.5.1.8. Función readWord (sobrecarga) 

_Prototipo_ : `bool readWord(FILE* f,string& w);` 

_Descripción_ : Lee una palabra desde el archivo `f` y la asigna a `w` , considerando que _palabra_ es un conjunto de caracteres comprendidos en `[A-Z]` , `[a-z]` , `[0-9]` . 

_Parámetros_ : 

- `FILE* f` – Archivo desde el cuál leerá una palabra. 

- `string& w` – _Buffer_ donde quedará la palabra leída. 

_Retorna_ : `bool` – `true` o `false` según queden o no más palabras para ser leídas. 

Ejemplo de uso: 

Suponiendo que `archivo.txt` tiene el siguiente contenido: 

```
Este archivo es
MUY-CHICO. Por eso, nadie lo quiere
compactar_mas. Ok?
```

Entonces, el código de la izquierda mostrará la salida de la derecha. 

```
FILE* f = fopen("archivo.txt","r+b"); [Este]
[Archivo]
string w; [es]
bool hayMas = readWord(f,w); [MUY]
while( hayMas ) [CHICO]
{ [Por]
cout << "[" << w << "]" << endl; [eso]
  hayMas = readWord(f,w); [nadie]
} [lo]
[quiee]
fclose(f); [compactar]
[mas]
[Ok]
```

## 1.5.1.9. Función writeString 

_Prototipo_ : `void writeString(FILE* f,string s);` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

80 |[Apéndice 2 ● Especificaciones y API] 

_Descripción_ : Escribe la cadena `s` en el archivo `f` . 

_Parámetros_ : 

- `FILE* f` – Archivo donde se grabará la cadena. 

- `string s` – Cadena que será grabada. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
FILE* f = fopen("archivo.txt","r+b");
```

```
// salida: Esta esuna cadenagenial
writeString(f,"Esta es");
writeString(f,"una cadena");
writeString(f,"genial");
```

## 1.5.1.10. Función writeWord 

_Prototipo_ : `void writeWord(FILE* f,string w);` 

_Descripción_ : Escribe la palabra `w` en el archivo `f` . 

_Parámetros_ : 

- `FILE* f` – Archivo donde se grabará la cadena. 

- • `string w` – Palabra que será grabada. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
FILE* f = fopen("archivo.txt","r+b");
```

```
// salida: Esta es una cadena genial
writeWord(f,"Esta");
writeWord(f,"es");
writeWord(f,"una");
writeWord(f,"cadena");
writeWord(f,"genial");
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 81 

## 1.5.1.11. Función writeLine 

_Prototipo_ : `void writeLine(FILE* f,string ln);` 

_Descripción_ : Escribe la línea `ln` en el archivo `f` 

_Parámetros_ : 

- `FILE* f` – Archivo donde se grabará la cadena. 

- `string ln` – Línea que será grabada. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
FILE* f = fopen("archivo.txt","r+b");
// salida:
// Esta es
// una cadena
// GENIAL !
writeLine(f,"Esta es");
writeLine(f,"una cadena");
writeLine(f,"GENIAL!");
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

82 |[Apéndice 2 ● Especificaciones y API] 

## 1.6. Lección 11 

## 1.6.1. TAD BitWriter 

Desarrollar el TAD `BitWriter` cuya función `bitWriterWrite` permite escribir en un archivo _bit a bit_ . 

## 1.6.1.1. Estructura del TAD 

```
struct BitWriter
{
   // implementacion a cargo del estudiante
};
```

## 1.6.1.2. Función bitWriter 

_Prototipo_ : `BitWriter bitWriter(FILE* f);` 

_Descripción_ : Crea e inicializa una variable tipo `BitWriter` . 

_Parámetros_ : `FILE* f` – Archivo donde se grabarán los bit. 

_Retorna_ : `BitWriter` . 

Ejemplo de uso: 

```
FILE* f = fopen("arch.bin","w+b");
BitWriter bw = bitWriter(f);
```

## 1.6.1.3. Función bitWriterWrite 

_Prototipo_ : `void bitWriterWrite(BitWriter& bw,int bit);` 

_Descripción_ : Graba un bit en el archivo. 

_Parámetros_ : 

- `BitWriter br` – Variable del TAD. 

- `int bit` – 1 o 0 que se grabará en el archivo. 

_Retorna_ : `void` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 83 

```
FILE* f = fopen("arch.bin","w+b");
BitWriter bw = bitWriter(f);
bitWriterWrite(bw,0);
bitWriterWrite(bw,1);
bitWriterWrite(bw,0);
bitWriterWrite(bw,0);
bitWriterWrite(bw,0);
bitWriterWrite(bw,0);
bitWriterWrite(bw,0);
bitWriterWrite(bw,1);
bitWriterFlush(bw); // siempre deberia invocarse al final
fclose(f); // El archivo queda asi: 01000001
```

## 1.6.1.4. Función bitWriterWrite (sobrecarga) 

_Prototipo_ : `void bitWriterWrite(BitWriter& bw,string bits);` 

_Descripción_ : Graba en el archivo los unos y ceros que contiene `bits` . 

_Parámetros_ : 

- `BitWriter br` – Variable del TAD. 

- `string bits` – Cadena que contiene caracteres unos y ceros. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
FILE* f = fopen("arch.bin","w+b");
BitWriter bw = bitWriter(f);
bitWriterWrite(bw,"01000001"); // graba un caracter 'A'
bitWriterFlush(bw);
fclose(f); // El archivo queda asi: 01000001
```

_Prototipo_ : `int bitWriterFlush(BitWriter bw);` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

84 |[Apéndice 2 ● Especificaciones y API] 

_Descripción_ : Indica que ya no se grabarán más bits en el archivo. En el caso de que la cantidad de bits que grabamos no sea múltiplo de 8, completará con ceros a la derecha tantos bits como sea necesario, y los grabará. 

_Parámetros_ : `BitWriter br` – Variable del TAD. 

_Retorna_ : `int` – Cuántos bits agregó al final (a la derecha) para completar el byte. 

Ejemplo de uso: 

```
FILE* f = fopen("arch.bin","w+b");
// grabamos un bit 0 y un bit 1 en el archivo
BitWriter bw = bitWriter(f);
bitWriterWrite(bw,0);
bitWriterWrite(bw,1);
int n = bitWriterFlush(bw); // retorna: 6
fclose(f); // El archivo queda asi: 01000000
```

## 1.6.2. TAD BitReader 

Desarrollar el TAD `BitReader` que permite leer desde un archivo _bit por bit_ . 

## 1.6.2.1. Estructura del TAD 

```
struct BitReader
{
   // implementacion a cargo del estudiante
};
```

## 1.6.2.2. Función bitReader 

_Prototipo_ : `BitReader bitReader(FILE* f);` 

_Descripción_ : Crea e inicializa una variable tipo `BitReader` . 

_Parámetro_ : `FILE* f` – Archivo desde el cual se leerán los bit. 

_Retorna_ : `BitReader` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 85 

```
FILE* f = fopen("arch.bin","r+b");
BitReader br = bitReader(f);
```

## 1.6.2.3. Función bitReaderRead 

_Prototipo_ : `int bitReaderRead(BitReader br);` 

_Descripción_ : Lee un bit desde el archivo. 

_Parámetro_ : `BitReader bw` – Variable del TAD. 

_Retorna_ : `int` – Bit (1 o 0) que leído desde el archivo. 

Ejemplo de uso: 

```
FILE* f = fopen("arch.bin","r+b");
BitReader br = bitReader(f);
```

```
int bit = bitReaderRead(br);
while( !feof(f) )
{
cout << bit << endl;
   bit = bitReaderRead(br);
}
fclose(f);
```

NOTA: Para facilitar la implementación de `bitReaderRead` , sugiero previamente desarrollar la función `_binToString` , con el prototipo que vemos a continuación: _Prototipo_ : `string _binToString(unsigned char c);` 

_Descripción_ : Retorna una cadena compuesta de _unos y_ ceros que representa al byte `c` . 

_Parámetro_ : `unsigned char c` – Valor numérico entero comprendido entre 0 y 255. 

_Retorna_ : `string` – Cadena con los _unos y ceros_ que representan a `c` en binario. 

Ejemplo de uso: 

```
unsigned char c = 'A';
string sBin = _binToString(c); // retorna: 01000001
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

86 |[Apéndice 2 ● Especificaciones y API] 

## 1.7. Lección 12 

## 1.7.1. API de tratamiento de arrays 

La siguientes funciones deben programarse en el archivo `arrays.hpp` . 

## 1.7.1.1. Función add 

_Prototipo_ : `int add(T arr[],int& len,T e);` 

_Descripción_ : Agrega el elemento `e` al final de `arr` incrementando su longitud `len` . 

_Parámetros_ : 

- `T arr[]` – _Array_ donde agregaremos un elemento. 

- `int& len` – Longitud actual del _array_ . 

- `T e` – Elemento que vamos a agregar. 

_Retorna_ : `int` – La posición del _array_ donde quedó ubicado el elemento `e` que acabamos de agregar. 

Ejemplo de uso: 

```
string a[10]; // array
int len = 0;  // longitud
add<string>(a,len,"John");
add<string>(a,len,"Paul");
add<string>(a,len,"George");
add<string>(a,len,"Ringo");
// recorro y muestro
for(int i=0; i<len; i++)
{
cout << a[i] << endl;
}
```

## 1.7.1.2. Función insert 

_Prototipo_ : `void insert(T arr[],int& len,T e,int p);` 

_Descripción_ : Inserta el elemento `e` en la posición `p` del _array_ `arr` . Desplaza los elementos ubicados a partir de `p+1` e incrementa la longitud `len` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 87 

_Parámetros_ : 

- `T arr[]` – _Array_ donde insertaremos un elemento. 

- `int& len` – Longitud actual del _array_ . 

- `T e` – Elemento que vamos a agregar. 

- `int p` – Posición donde se insertará el nuevo elemento. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
// array y longitud
string a[10];
int len = 0;
// agrego elementos
insert<string>(a,len,"John",0);
insert<string>(a,len,"Paul",0);
insert<string>(a,len,"George",0);
insert<string>(a,len,"Ringo",0);
// recorro y muestro
for(int i=0; i<len; i++)
{
cout << a[i] << endl; // SALIDA: Ringo,George,Paul,John
}
```

## 1.7.1.3. Función remove 

_Prototipo_ : `T remove(T arr[],int& len,int p);` 

_Descripción_ : Remueve el elemento ubicado en la posición `p` del _array_ `arr` . Desplaza ubicados a partir de `p` y decrementa la longitud `len` . 

_Parámetros_ : 

- `T arr[]` – _Array_ donde removeremos un elemento. 

- `int& len` – Longitud actual del _array_ . 

- `T p` – Posición cuyo elemento será removido. 

_Retorna_ : `T` – Elemento que fue removido del _array_ . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

88 |[Apéndice 2 ● Especificaciones y API] 

```
// array y longitud
string a[10];
int len = 0;
// agrego elementos
add<string>(a,len,"John");
add<string>(a,len,"Paul");
add<string>(a,len,"George");
add<string>(a,len,"Ringo");
```

```
while( len>0 )
{
cout << remove<string>(arr,len,0) << endl;
}
```

## 1.7.1.4. Función find 

_Prototipo_ : `int find(T arr[],int len,K k,int cmpTK(T,K));` 

_Descripción_ : Retorna la posición de la primera ocurrencia de `k` dentro de `arr` o un valor negativo si arr no contiene a `k` . 

_Parámetros_ : 

- `T arr[]` – _Array_ donde buscaremos un elemento. 

- `int len` – Longitud actual del _array_ . 

- `K` k– Valor a buscar dentro de `arr` . 

- `int cmpTK(T,K)` – Función de comparación. 

_Retorna_ : `int` – Posición de la primera ocurrencia de `k` dentro de `arr` o un valor negativo si `arr` no contiene a `k` . 

Ejemplo de uso: 

```
struct Persona
{
int dni;
   string nom;
};
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 89 

```
int cmpPersonaDNI(Persona p,int d)
{
return p.dni-d;
}
```

```
// array de personas
int len=3;
Persona arr[] = {persona(10,"Pablo")
                ,persona(20,"Pedro")
                ,persona(30,"Juan")};
// busco por DNI
int pos = find<Persona,int>(arr,len,20,cmpPersonaDNI);
cout << pos << endl; // SALIDA: 1
```

## 1.7.1.5. Función orderedInsert 

_Prototipo_ : `int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T));` 

_Descripción_ : Inserta `e` dentro de `arr` según el criterio de precedencia que establece `cmpTT` , y retorna la posición donde dicho elemento quedó insertado. El _array_ `arr` debe estar ordenado o vacío. 

## _Parámetros_ : 

- `T arr[]` – _Array_ donde insertaremos un elemento. 

- `int& len` – Longitud actual del _array_ . 

- `T e` – Valor a insertar dentro de `arr` . 

- `int cmpTT(T,T)` – Función de comparación. 

_Retorna_ : `int` – Posición donde quedó insertado `e` dentro de `arr` . 

Ejemplo de uso: 

```
// funcion de comparacion
int cmpInt(int a,int b){return a-b;}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

90 |[Apéndice 2 ● Especificaciones y API] 

```
int arr[10] = {1,2,3,5,6,7,8}; // array
int len = 7;                   // longitud
int pos = orderedInsert<int>(arr,len,4,cmpInt);
cout << pos << endl;
```

## 1.7.1.6. Función sort 

_Prototipo_ : `void sort(T arr[],int len,int cmpTT(T,T));` 

_Descripción_ : Ordena `arr` según el criterio de precedencia que establece `cmpTT` . 

_Parámetros_ : 

- `T arr[]` – _Array_ que ordenaremos. 

- `int len` – Longitud actual del _array_ . 

- `int cmpTT(T,T)` – Función de comparación. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
int arr[] = {5,4,3,2,1}; // array
int len = 5;             // longitud
// ordeno y muestro
sort<int>(arr,len,cmpInt);
for(int i=0; i<len; i++)
{
cout << arr[i] << endl;
}
```

```
// funcion de comparacion
int cmpInt(int a,int b){return a-b;}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 91 

## 1.8. Lección 13 

## 1.8.1. TAD Array 

La siguientes funciones deben programarse en el archivo `Array.hpp` . 

## 1.8.1.1. Estructura del TAD 

```
template<typename T>
struct Array
{
   // implementacion a cargo del estudiante
};
```

## 1.8.1.2. Función array 

_Prototipo_ : `Array<T> array();` 

_Descripción_ : Inicializa un _array_ cuya capacidad inicial será establecida por defecto. La longitud del _array_ será 0, y se incrementará a medida que se agreguen o inserten nuevos elementos. 

_Retorna_ : `Array<T>` – El _array_ . 

Ejemplo de uso: 

```
// array y longitud
Array<int> a = array<int>();
arrayAdd<int>(a,10);
arrayAdd<int>(a,20);
arrayAdd<int>(a,30);
// el size del array?
cout << arraySize<int>(arr) << endl; // Salida: 3
```

## 1.8.1.3. Función arrayAdd 

_Prototipo_ : `int arrayAdd(Array<T>& a,T t);` 

_Descripción_ : Agrega `t` al final de `a` incrementando, de ser necesario, su capacidad. Retorna la posición del _arr_ donde quedó ubicado el elemento `t` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

92 |[Apéndice 2 ● Especificaciones y API] 

_Parámetros_ : 

- `Array<T>& a` – El _array_ . 

- `T t` – Elemento que se agregará. 

_Retorna_ : `int` – Posición de `a` donde se agregó el elemento `t` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
int pos = arrayAdd<int>(a,10); // pos = 0
```

## 1.8.1.4. Función arrayGet 

_Prototipo_ : `T* arrayGet(Array<T> a,int p);` 

_Descripción_ : Retorna la dirección del elemento de `a` ubicado en la posición `p` . 

_Parámetros_ : 

• `Array<T> a` – El _array_ . • `int p` – Posición del elemento de `a` al cual queremos acceder. 

_Retorna_ : `T*` – Dirección del elemento ubicado en la posición `p` del _array_ `a` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
```

```
arrayAdd<int>(a,10);
arrayAdd<int>(a,20);
arrayAdd<int>(a,30);
int* p = arrayGet<int>(a,1);
*p = 22; // cambia 20 por 22
```

## 1.8.1.5. Función arraySet 

_Prototipo_ : `void arraySet(Array<T>& a,int p,T t);` 

_Descripción_ : Asigna el elemento `t` en la posición `p` del _array_ `a` 

_Parámetros_ : 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 93 

- `Array<T>& a` – El _array_ . 

- `int p` – Posición del elemento de `a` al cual queremos acceder. 

- `T t` – Elemento que vamos a asignar en la posición `p` de `a` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayAdd<int>(a,10);
arrayAdd<int>(a,20);
arrayAdd<int>(a,30);
arraySet<int>(a,1,99); // reemplaza 20 x 99
```

## 1.8.1.6. Función arrayInsert 

_Prototipo_ : `void arrayInsert(Array<T>& a,T t,int p);` 

_Descripción_ : Inserta `t` en la posición `p` del _array_ `a` . 

_Parámetros_ : 

- `Array<T>& a` – El _array_ . 

- `T t` – Elemento a insertar. 

- `int p` – Posición donde quedará insertado `t` . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayInsert<int>(a,10,0);
arrayInsert<int>(a,20,0);
arrayInsert<int>(a,30,0);
```

```
int* p = arrayGet<int>(a,0);
cout << *p << endl; // SALIDA: 30
```

## 1.8.1.7. Función arraySize 

_Prototipo_ : `int arraySize(Array<T> a);` 

_Descripción_ : Retorna la longitud actual del _array_ . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

94 |[Apéndice 2 ● Especificaciones y API] 

_Parámetro_ : `Array<T> a` – El _array_ . 

_Retorna_ : `int` – Longitud del _array_ `a` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayAdd<int>(a,10);
arrayAdd<int>(a,20);
arrayAdd<int>(a,30);
```

```
for(int i=0;i<arraySize<int>(a);i++)
{
int* e = arrayGet<int>(a,i);
   cout << *e << endl; // SALIDA: 10,20,30
}
```

## 1.8.1.8. Función arrayRemove 

_Prototipo_ : `T arrayRemove(Array<T>& a,int p);` 

_Descripción_ : Remove el elemento de `a` ubicado en la posición `p` . 

_Parámetros_ : 

- `Array<T>& a` – El _array_ . 

- `int p` – Posición a remover. 

_Retorna_ : `T` – Elemento que ocupaba la posición `p` dentro de `a` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayAdd<int>(a,10);
arrayAdd<int>(a,20);
arrayAdd<int>(a,30);
int e = arrayRemove<int>(a,0);
cout << e << endl; // SALIDA: 10
```

## 1.8.1.9. Función arrayRemoveAll 

_Prototipo_ : `void arrayRemoveAll(Array<T>& a);` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 95 

_Descripción_ : Remueve todos los elemento de `a` dejándolo vacío, con longitud 0. 

_Parámetro_ : `Array<T>& a` – El _array_ . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayAdd<int>(a,10);
arrayAdd<int>(a,20);
arrayAdd<int>(a,30);
```

```
// elimino todos los elementos
arrayRemoveAll<int>(a);
```

```
cout << arraySize<int>(a) << endl; // Salida: 0
```

## 1.8.1.10. Función arrayFind 

_Prototipo_ : `int arrayFind(Array<T> a,K k,int cmpTK(T,K));` 

_Descripción_ : Retorna la posición que `k` ocupa dentro de `a` , según la función de comparación `cmpTK` , o un valor negativo si `a` no contiene a `k` . 

_Parámetros_ : 

- `Array<T>& a` – El _array_ . 

- `int k` – Elemento a buscar. 

- `int cmpTK(T,K)` – Función de comparación. 

_Retorna_ : `int` – Posición de la primera ocurrencia de `k` dentro de `a` o un valor negativo si `a` no contiene a `k` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayAdd<int>(a,10);
arrayAdd<int>(a,20);
arrayAdd<int>(a,30);
int pos = arrayFind<int,int>(a,30,cmpInt);
cout << pos << endl; // SALIDA: 2
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

96 |[Apéndice 2 ● Especificaciones y API] 

## 1.8.1.11. Función arrayOrderedInsert 

_Prototipo_ : `int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T));` 

_Descripción_ : Inserta `t` en `a` según el criterio de precedencia que establece `cmpTT` . 

_Parámetros_ : 

- `Array<T>& a` – El _array_ . 

- `T t` – Elemento a insertar. 

- `int cmpTT(T,T)` – Función de comparación. 

_Retorna_ : `int` – Posición donde quedó insertado `t` dentro de `a` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayOrderedInsert<int>(a,2,cmpInt);
arrayOrderedInsert<int>(a,1,cmpInt);
arrayOrderedInsert<int>(a,3,cmpInt);
```

```
for(int i=0;i<arraySize<int>(a);i++)
{
int* p = arrayGet<int>(a,i);
cout << *p << endl; // SALIDA: 1,2,3
}
```

## 1.8.1.12. Función arrayDiscover 

_Prototipo_ : `T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T));` 

_Descripción_ : Descubre (busca, y si no encuentra lo agrega) al elemento `t` en el _array_ `a` . 

_Parámetros_ : 

- `Array<T>& a` – El _array_ . 

- `T t` – Elemento a descubrir. 

- `int cmpTT(T,T)` – Función de comparación. 

_Retorna_ : `T*` - La dirección del elemento encontrado, o recientemente agregado. 

Ejemplo de uso: 

```
Array<string> a = array<string>();
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 97 

```
arrayDiscover<string>(a,"Pablo",cmpString);
arrayDiscover<string>(a,"Pedro",cmpString);
arrayDiscover<string>(a,"Pedro",cmpString);
arrayDiscover<string>(a,"Juan",cmpString);
arrayDiscover<string>(a,"Pablo",cmpString);
arrayDiscover<string>(a,"Juan",cmpString);
```

```
for(int i=0; i<arraySize<string>(a); i++)
{
   string* s = arrayGet<string>(a,i);
   // SALIDA: Pablo, Pedro, Juan
cout << *s << endl;
}
```

## 1.8.1.13. Función arraySort 

_Prototipo_ : `void arraySort(Array<T>& a,int cmpTT(T,T));` 

_Descripción_ : Ordena el _array_ `a` según establece `cmpTT` . 

_Parámetros_ : 

- `Array<T>& a` – El _array_ . 

- `int cmpTT(T,T)` – Función de comparación. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayAdd<int>(a,2);
arrayAdd<int>(a,1);
arrayAdd<int>(a,3);
// ordeno
arraySort<int>(a,cmpInt)
```

## 1.8.1.14. Función arrayReset 

_Prototipo_ : `void arrayReset(Array<T>& a);` 

_Descripción_ : Prepara el array para una nueva iteración. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

98 |[Apéndice 2 ● Especificaciones y API] 

_Parámetros_ : 

• `Array<T>& a` – El _array_ . 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Array<int> a = array<int>();
arrayAdd<int>(a,2);
arrayAdd<int>(a,1);
arrayAdd<int>(a,3);
```

```
arrayReset<int>(a);
while( arrayHasNext<int>(a) )
{
int* x = arrayNext<int>(a);
cout << *x << endl;
}
```

## 1.8.1.15. Función arrayHasNext 

_Prototipo_ : `bool arrayHasNext(Array<T>& a);` 

_Descripción_ : Indica si quedan elementos para seguir iterando. 

_Parámetros_ : 

• `Array<T>& a` – El _array_ . 

_Retorna_ : `bool` . 

Ejemplo de uso: Ver `arrayReset` . 

## 1.8.1.16. Función arrayNext 

_Prototipo_ : `T* arrayNext(Array<T>& a);` 

_Descripción_ : Retorna la dirección del siguiente elemento de la iteración. _Parámetros_ : 

• `Array<T>& a` – El _array_ . 

_Retorna_ : `int*` . 

Ejemplo de uso: Ver `arrayReset` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 99 

## 1.8.2. TAD Map 

La siguientes funciones deben programarse en el archivo `Map.hpp` . 

## 1.8.2.1. Estructura del TAD 

```
template<typename K,template V>
struct Map
{
   // implementacion a cargo del estudiante
};
```

NOTA: El tipo de dato de la clave ( `K` ) será primitivo, `string` o cualquier otro 

cuya implementación soporte el uso de los operadores relacionales `<` , `>` , `==` y `!=` . 

El TAD `Map` debe implementarse usando el TAD `Array` . 

## 1.8.2.2. Función map 

_Prototipo_ : `Map<K,V> map();` 

_Descripción_ : Inicializa un _map_ . 

_Retorna_ : `Map<K,V>` – El _map_ . 

Ejemplo de uso: 

```
Map<string,int> m = map<string,int>();
mapPut<string,int>(m,"uno",1);
mapPut<string,int>(m,"dos",2);
mapPut<string,int>(m,"tres",3);
int* n = mapGet<string,int>(m,"dos");
cout << *n << endl; // Salida: 2
string k = "uno";
if( mapContains<string,int>(m,k) )
{
cout << "Existe una entrada con clave" << k << endl;
}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

100 |[Apéndice 2 ● Especificaciones y API] 

## 1.8.2.3. Función mapGet 

_Prototipo_ : `V* mapGet(Map<K,V> m,K k);` 

_Descripción_ : Retorna la dirección de memoria del valor asociado a la clave `k` o `NULL` si `m` no contiene ningún valor asociado a dicha clave. 

_Parámetros_ : 

- `Map<K,V> m` – El _map_ . 

- `K k` – Clave con la cual, dentro del _map_ , quedará asociado el elemento `v` . 

_Retorna_ : `V*` - Dirección de memoria del elemento vinculado con la clave `k` o `NULL` si `m` no contiene ningún valor asociado a `k` . 

Ejemplo de uso: ver anterior. 

## 1.8.2.4. Función mapPut 

_Prototipo_ : `V* mapPut(Map<K,V>& m,K k,V v);` 

_Descripción_ : Agrega al _map_ `m` el elemento `v` asociado a la clave `k` . Si existía una entrada vinculada a `k` se debe reemplazar el valor anterior por `v` . 

_Parámetros_ : 

- `Map<K,V>& m` – El _map_ . 

- `K k` – Clave con la cual, dentro del _map_ , quedará asociado el elemento `v` . 

- • `V v` – Valor o elemento a agregar. 

_Retorna_ : `V*` - Dirección de memoria del elemento vinculado con la clave `k` 

Ejemplo de uso: Ver anterior. 

## 1.8.2.5. Función mapContains 

_Prototipo_ : `bool mapContains(Map<K,V> m,K k);` 

_Descripción_ : Verifica si `m` contiene a `k` . 

_Parámetros_ : 

- `Map<K,V> m` – El _map_ . 

- `K k` –Clave. 

_Retorna_ : `bool` - `true` o `false` según `m` contenga, o no, una entrada vinculada a `k` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 101 

Ejemplo de uso: Ver anterior. 

## 1.8.2.6. Función mapRemove 

_Prototipo_ : `V mapRemove(Map<K,V>& m,K k);` 

_Descripción_ : Elimina de `m` la entrada identificada con la clave `k` 

_Parámetros_ : 

- `Map<K,V>& m` – El _map_ . 

- `K k` –Clave que identifica la entrada a remover. 

_Retorna_ : `V` – Valor que contenía la entrada asociada a la clave `k` . 

## 1.8.2.7. Función mapRemoveAll 

_Prototipo_ : `void mapRemoveAll(Map<K,V>& m);` 

_Descripción_ : Elimina todas las entradas del _map_ `m` 

_Parámetro_ : `Map<K,V>& m` – El _map_ . 

_Retorna_ : `void` . 

## 1.8.2.8. Función mapSize 

_Prototipo_ : `int mapSize(Map<K,V> m);` 

_Descripción_ : Retorna la cantidad actual de entradas que tiene `m` 

_Parámetro_ : `Map<K,V>& m` – El _map_ . 

_Retorna_ : `int` – Cantidad de entradas que tiene el _map_ `m` . 

## 1.8.2.9. Función mapHasNext 

_Prototipo_ : `bool mapHasNext(Map<K,V> m);` 

_Descripción_ : Indica si quedan más elementos para continuar iterando el _map_ 

_Parámetro_ : `Map<K,V> m` – El _map_ . 

_Retorna_ : `bool` – `true` o `false` según queden elementos para continuar iterando. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

102 |[Apéndice 2 ● Especificaciones y API] 

Ejemplo de uso: 

```
Map<string,int> m = map<string,int>();
mapPut<string,int>(m,"uno",1);
mapPut<string,int>(m,"dos",2);
mapPut<string,int>(m,"tres",3);
mapPut<string,int>(m,"cuatro",4);
// iteramos el map accediendo a cada key
mapReset<string,int>(m);
while( mapHasNext<string,int>(m) )
{
   // clave y valor
   string k = mapNextKey<string,int>(m);
int* v = mapGet<string,int>(m,k);
cout << k << ", " << *v << endl;
}
// iteramos el map accediendo a cada value
mapReset<string,int>(m);
while( mapHasNext<string,int>(m) )
{
   // valor
int* v = mapNextValue<string,int>(m);
cout << *v << endl;
}
```

## 1.8.2.10. Función mapNextKey 

_Prototipo_ : `K mapNextKey(Map<K,V>& m);` 

_Descripción_ : Permite iterar sobre las claves del _map_ . Esta función es mutuamente excluyente respecto de `mapNextValue` . 

_Parámetro_ : `Map<K,V>& m` – El _map_ . 

_Retorna_ : `K` – La siguiente clave dentro de una iteración. 

Ejemplo de uso: Ver anterior. 

## 1.8.2.11. Función mapNextValue 

_Prototipo_ : `V* mapNextValue(Map<K,V>& m);` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 103 

_Descripción_ : Permite iterar sobre los valores que contiene el _map_ . Esta función es mutuamente excluyente despecto de `mapNextKey` . 

_Parámetro_ : `Map<K,V>& m` – El _map_ . 

_Retorna_ : `V*` – Dirección de memoria del siguiente valor dentro de una iteración. 

Ejemplo de uso: Ver anterior. 

## 1.8.2.12. Función mapReset 

_Prototipo_ : `void mapReset(Map<K,V>& m);` 

_Descripción_ : Prepara el _map_ para comenzar una nueva iteración. 

_Parámetro_ : `Map<K,V>& m` – El _map_ . 

_Retorna_ : `void` . 

Ejemplo de uso: Ver anterior. 

## 1.8.2.13. Función mapDiscover 

_Prototipo_ : `V* mapDiscover(Map<K,V>& m,K k,V v);` 

_Descripción_ : Descubre (busca, y si no encuentre agrega) una entrada { `k` , `v` } en el map `m` . _Parámetros_ : 

- `Map<K,V>& m` – El _map_ . 

- `K k` – _Key_ . 

- `V v` – _Value_ que será agregado en caso de no existir una entrada para `k` . 

_Retorna_ : `V*` - La dirección de memoria del _value_ asociado a `k` , agregado o encontrado. 

Ejemplo de uso: 

```
Map<int,string> m = map<int,string>();
mapDiscover<int,string>(m,1,"Uno");
mapDiscover<int,string>(m,2,"Dos");
mapDiscover<int,string>(m,3,"Tres");
mapDiscover<int,string>(m,1,"Uno");
mapDiscover<int,string>(m,2,"Dos");
mapDiscover<int,string>(m,4,"Cuatro");
mapDiscover<int,string>(m,3,"Tres");
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

104 |[Apéndice 2 ● Especificaciones y API] 

```
mapDiscover<int,string>(m,4,"Cuatro");
```

```
mapReset<int,string>(m);
while( mapHasNext<int,string>(m) )
{
   string* s = mapNextValue<int,string>(m);
cout << *s << endl;
}
```

## 1.8.2.14. Función mapSortByKeys 

_Prototipo_ : `void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K));` 

_Descripción_ : Ordena el _map_ aplicando sobre sus claves el criterio que establece `cmpKK` . _Parámetros_ : 

- `Map<K,V>& m` – El _map_ . 

- `int cmpKK(K,K)` - Función de comparación. 

_Retorna_ : `void` . 

## 1.8.2.15. Función mapSortByValues 

_Prototipo_ : `void mapSortByValues(Map<K,V>& m,int cmpVV(V,V));` 

_Descripción_ : Ordena el _map_ aplicando sobre sus _values_ el criterio que establece `cmpVV` . _Parámetros_ : 

- `Map<K,V>& m` – El _map_ . 

- `int cmpVV(V,V)` – Función de comparación. 

_Retorna_ : `void` . 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 105 

## 1.9. Lección 14 

## 1.9.1. API de tratamiento de listas enlazadas 

La siguientes funciones deben programarse en el archivo `lists.hpp` . 

## 1.9.1.1. Nodo 

```
template<typename T>
struct Node
{
   T info;
   Node<T>* sig;
};
```

Todos los ejemplos de uso, siempre que sea necesario invocar a una función de comparación, invocaremos a `cmpInt` cuyo código es el siguiente. 

```
int cmpInt(int a,int b){return a-b;}
```

## 1.9.1.2. Función add 

_Prototipo_ : `Node<T>* add(Node<T>*& p,T e);` 

_Descripción_ : Agrega el elemento `e` al final de la lista direccionada por `p` . 

_Parámetros_ : 

- `Node<T>*& p` – Puntero al primer nodo de la lista. 

- `T e` – Elemento que vamos a agregar. 

_Retorna_ : `Node<T>*` – Dirección del nodo que contiene al elemento que se agregó. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
add<int>(p,1);
add<int>(p,2);
add<int>(p,3); // p->{1,2,3}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

106 |[Apéndice 2 ● Especificaciones y API] 

## 1.9.1.3. Función addFirst 

_Prototipo_ : `Node<T>* addFirst(Node<T>*& p,T e);` 

_Descripción_ : Agrega el elemento `e` al inicio de la lista direccionada por `p` . 

_Parámetros_ : 

- `Node<T>*& p` – Puntero al primer nodo de la lista. 

- `T e` – Elemento que vamos a agregar al inicio de la lista. 

_Retorna_ : `Node<T>*` – Dirección del nodo que contiene al elemento que se agregó. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
addFirst<int>(p,1);
addFirst<int>(p,2);
addFirst<int>(p,3); // p->{3,2,1}
```

## 1.9.1.4. Función remove 

_Prototipo_ : `T remove(Node<T>*& p,K k,int cmpTK(T,K));` 

_Descripción_ : Remueve la primera ocurrencia del elemento concordante con `cmpTK` . 

_Parámetros_ : 

- `Node<T>*& p` – Puntero al primer nodo de la lista. 

- `K k` – Elemento o clave de búsqueda del elemento que vamos a remover. 

- `int cmpTK(T,K)` – Función de comparación. 

_Retorna_ : `T` – Valor del elemento que fue removido. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
add<int>(p,1);
add<int>(p,2);
add<int>(p,3); // p->{1,2,3}
```

```
int e = remove<int,int>(p,2,cmpInt); // p->{1,3}
cout << e << endl; // Salida: 2
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 107 

## 1.9.1.5. Función removeFirst 

_Prototipo_ : `T removeFirst(Node<T>*& p);` 

_Descripción_ : Remueve el primer elemento de la lista direccionada por `p` . 

_Parámetro_ : `Node<T>*& p` – Puntero al primer nodo de la lista. 

_Retorna_ : `T` – Valor del elemento que acabamos de remover. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
add<int>(p,1);
add<int>(p,2);
add<int>(p,3); // p->{1,2,3}
int e = removeFirst(p); // p->{2,3}
cout << e << endl;      // Salida: 1
```

## 1.9.1.6. Función find 

_Prototipo_ : `Node<T>* find(Node<T>* p,K k,int cmpTK(T,K));` 

_Descripción_ : Retorna la dirección del nodo que contiene la primera ocurrencia de `k` , según `cmpTK` , o `NULL` si ningún elemento concuerda con dicha clave de búsqueda. 

_Parámetros_ : 

- `Node<T>* p` – Puntero al primer nodo de la lista. 

- `K k` – Elemento o clave de búsqueda del elemento. 

- `int cmpTK(T,K)` – Función de comparación. 

_Retorna_ : `Node<T>*` – Dirección del nodo que contiene la primera ocurrencia del elemento que buscamos o `NULL` si la lista no contiene dicho elemento. 

Ejemplo de uso: 

```
// puntero a null (la lista)
Node<int>* p = NULL;
add<int>(p,1);
add<int>(p,2);
add<int>(p,3); // p->{1,2,3}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

108 |[Apéndice 2 ● Especificaciones y API] 

```
Nodo<int>*e = find<int,int>(p,2,cmpInt);
cout << e->info << endl; // Salida: 2
```

## 1.9.1.7. Función orderedInsert 

_Prototipo_ : `Node<T>* orderedInsert(Node<T>*& p ,T e ,int cmpTT(T,T));` 

_Descripción_ : Inserta el elemento `e` en la lista direccionada por `p` según el criterio que establece la función `cmpTT` . La lista debe estar vacía u ordenada según `cmpTT` . _Parámetros_ : 

- `Node<T>*& p` – Puntero al primer nodo de la lista. 

- `T e` – Elemento que vamos a insertar. 

- `int cmpTT(T,T)` – Función que establece el criterio de ordenamiento. 

_Retorna_ : `Node<T>*` – Dirección del nodo que acabamos de insertar. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
orderedInsert<int>(p,2,cmpInt);
orderedInsert<int>(p,3,cmpInt);
orderedInsert<int>(p,1,cmpInt); // p->{1,2,3}
```

## 1.9.1.8. Función searchAndInsert 

_Prototipo_ : `Node<T>* searchAndInsert(Node<T>*& p ,T e ,bool& enc ,int cmpTT(T,T));` 

_Descripción_ : Busca en la lista direccionada por `p` la primera ocurrencia de `e` , y retorna la dirección del nodo que lo contiene. Si `e` no existe en la lista entonces lo insertar en orden, según el criterio establecido por `cmpTT` , y retorna la dirección del nodo insertado. Asigna `true` o `false` a `enc` según `e` fue encontrado o insertado. 

_Parámetros_ : 

- `Node<T>*& p` – Puntero al primer nodo de la lista. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 109 

- `T e` – Elemento que vamos a insertar. 

- `bool& enc` – Parámetro de salida que indica la acción que tomó la función. 

- `int cmpTT(T,T)` – Función que establece el criterio de ordenamiento. 

_Retorna_ : `Node<T>*` – Dirección del nodo que acabamos de encontrar o insertar. 

Ejemplo de uso: 

```
bool enc;
Node<int>* p = NULL;
searchAndInsert<int>(p,1,enc,cmpInt); // p->{1}
cout << enc << endl; // Salida: false
searchAndInsert<int>(p,2,enc,cmpInt); // p->{1,2}
cout << enc << endl; // Salida: false
searchAndInsert<int>(p,3,enc,cmpInt); // p->{1,2,3}
cout << enc << endl; // Salida: false
searchAndInsert<int>(p,2,enc,cmpInt); // p->{1,2,3}
cout << enc << endl; // Salida: true
searchAndInsert<int>(p,1,enc,cmpInt); // p->{1,2,3}
cout << enc << endl; // Salida: true
searchAndInsert<int>(p,4,enc,cmpInt); // p->{1,2,3,4}
cout << enc << endl; // Salida: false
```

## 1.9.1.9. Función sort 

_Prototipo_ : `void sort(Node<T>*& p,int cmpTT(T,T));` 

_Descripción_ : Ordena la lista direccionada por `p` según el criterio que establece la función de comparación `cmpTT` . 

_Parámetros_ : 

- `Node<T>*& p` – Puntero al primer nodo de la lista. 

- `int cmpTT(T,T)` – Función que establece el criterio de ordenamiento. 

_Retorna_ : `void` . 

Ejemplo de uso: 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

110 |[Apéndice 2 ● Especificaciones y API] 

```
Node<int>* p = NULL;
add<int>(p,2);
add<int>(p,1);
add<int>(p,3); // p->{2,1,3}
sort<int>(p,cmpInt); // p->{1,2,3}
```

## 1.9.1.10. Función isEmpty 

_Prototipo_ : `bool isEmpty(Node<T>* p);` 

_Descripción_ : Indica si la lista direccionada por `p` tiene o no elemento. 

_Parámetro_ : N `ode<T>* p` – Puntero al primer nodo de la lista. 

_Retorna_ : `bool` – `true` o `false` según la lista tenga o no elementos. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
add<int>(p,1);
add<int>(p,2);
add<int>(p,3); // p->{1,2,3}
```

```
if( !isEmpty<int>(p) )
{
cout << "la lista tiene elementos" << endl;
}
```

## 1.9.1.11. Función free 

_Prototipo_ : `void free(Node<T>*& p);` 

_Descripción_ : Libera la memoria que utiliza lista direccionada por `p` . Asigna `NULL` a `p` . 

_Parámetro_ : N `ode<T>*& p` – Puntero al primer nodo de la lista. 

_Retorna_ : `void` . 

Ejemplo de uso: 

```
Node<int>* p = NULL;
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 111 

```
add<int>(p,1);
add<int>(p,2);
add<int>(p,3); // p->{1,2,3}
free<int>(p);  // p->NULL
```

## 1.9.2. API de operaciones sobre pilas (extensión) 

Las siguientes funciones extienden la API de operaciones sobre listas. 

## 1.9.2.1. Función push 

_Prototipo_ : `Node<T>* push(Node<T>*& p,T e);` 

_Descripción_ : Inserta un nodo conteniendo a `e` al inicio de la lista direccionada por `p` . 

_Parámetros_ : 

- `Node<T>*& p` – Puntero al primer nodo de la lista. 

- `T e` – Elemento que vamos a agregar al inicio de la lista (apilar). 

_Retorna_ : `Node<T>*` – Dirección del nodo que contiene al elemento que se agregó. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
push<int>(p,1); // p->{1}
push<int>(p,2); // p->{2,1}
push<int>(p,3); // p->{3,2,1}
```

## 1.9.2.2. Función pop 

_Prototipo_ : `T pop(Node<T>*& p);` 

_Descripción_ : Remueve el primer nodo de la lista direccionada por `p` . 

_Parámetro_ : `Node<T>*& p` – Puntero al primer nodo de la lista. 

_Retorna_ : `T` – Elemento que contenía el nodo que fue removido. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

112 |[Apéndice 2 ● Especificaciones y API] 

```
push<int>(p,1); // p->{1}
push<int>(p,2); // p->{2,1}
push<int>(p,3); // p->{3,2,1}
int e = pop<int>(p); // p->{2,1}
cout << e << endl;   // Salida: 3
```

## 1.9.3. API de operaciones sobre colas (extensión) 

Las siguientes funciones extienden la API de operaciones sobre listas. 

## 1.9.3.1. Función enqueue 

_Prototipo_ : `Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e);` 

_Descripción_ : Agrega el elemento `e` al final la lista direccionada por `q` . 

_Parámetros_ : 

- `Node<T>*& p` – Puntero al primer nodo de la lista. 

- `Node<T>*& q` – Puntero al último nodo de la lista. 

- `T e` – Elemento que vamos a agregar al final de la lista ( `q` ). 

_Retorna_ : `Node<T>*` – Dirección del nodo que contiene al elemento que se agregó. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
Node<int>* q = NULL;
enqueue<int>(p,q,1); // p->{1}<-q
enqueue<int>(p,q,2); // p->{1,2}<-q
enqueue<int>(p,q,3); // p->{1,2,3}<-q
```

## 1.9.3.2. Función enqueue (sobrecarga) 

_Prototipo_ : `Node<T>* enqueue(Node<T>*& q,T e);` 

_Descripción_ : Agrega el elemento `e` al final la lista circular direccionada por `q` . 

_Parámetros_ : 

- `Node<T>*& q` – Puntero al último nodo de la lista circular. 

- `T e` – Elemento que vamos a agregar al final de la lista ( `q` ). 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 113 

_Retorna_ : `Node<T>*` – Dirección del nodo que contiene al elemento que se agregó. 

Ejemplo de uso: 

```
Node<int>* q = NULL;
enqueue<int>(q,1); // {1}<-q
enqueue<int>(q,2); // {1,2}<-q
enqueue<int>(q,3); // {1,2,3}<-q
```

## 1.9.3.3. Función dequeue 

_Prototipo_ : `T dequeue(Node<T>*& p,Node<T>*& q);` 

_Descripción_ : Remueve el primer nodo de la lista direccionada por `p` . 

_Parámetros_ : 

- `Node<T>*& p – Puntero al primer nodo de la lista.` 

- • `Node<T>*& q – Puntero al último nodo de la lista.` 

_Retorna_ : `T` – Elemento que contenía el nodo que fue removido. 

Ejemplo de uso: 

```
Node<int>* p = NULL;
Node<int>* q = NULL;
enqueue<int>(p,q,1); // p->{1}<-q
enqueue<int>(p,q,2); // p->{1,2}<-q
enqueue<int>(p,q,3); // p->{1,2,3}<-q
int e = dequeue<int>(p,q); // p->{2,3}<-q
cout << e << endl; // Salida: 1
```

## 1.9.3.4. Función dequeue (sobrecarga) 

_Prototipo_ : `T dequeue(Node<T>*& q);` 

_Descripción_ : Remueve el primer nodo de la lista circular direccionada por `q` . 

_Parámetro_ : `Node<T>*& q` – Puntero al último nodo de la lista circular. 

_Retorna_ : `T` – Elemento que contenía el nodo que fue removido. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

114 |[Apéndice 2 ● Especificaciones y API] 

Ejemplo de uso: 

```
Node<int>* q = NULL;
enqueue<int>(q,1); // {1}<-q
enqueue<int>(q,2); // {1,2}<-q
enqueue<int>(q,3); // {1,2,3}<-q
int e = dequeue<int>(q); // {2,3}<-q
cout << e << endl; // Salida: 1
```

## 1.9.4. TAD List 

La siguientes funciones deben programarse en el archivo `List.hpp` . 

## 1.9.4.1. Estructura del TAD 

```
template<typename T>
struct List
{
   // implementacion a cargo del estudiante
};
```

El siguiente ejemplo ilustra cómo utilizar el TAD `List` . Las funciones de la API se deben implementar invocando a los _templates_ previamente desarrollados. 

```
List<int> lst = list<int>();
// agregamos elementos
listAdd<int>(lst,1);
listAdd<int>(lst,2);
listAdd<int>(lst,3);
// iteramos
listReset<int>(lst);
while( listHasNext<int>(lst) )
{
int* e = listNext<int>(lst);
cout << *e << endl;
}
```

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 115 

```
// liberamos
listFree<int>(lst);
```

## 1.9.4.2. Función list 

_Prototipo_ : `List<T> list();` 

_Descripción_ : Función de inicialización. 

_Retorna_ : `List<T>` – La lista. 

## 1.9.4.3. Función listAdd 

_Prototipo_ : `T* listAdd(List<T>& lst,T e);` 

_Descripción_ : Agrega un elemento al final de la lista. 

_Parámetros_ : 

- `List<T>& lst` - Lista. 

- `T e` – Elemento que se agregará al final de la lista. 

_Retorna_ : `T*` – Dirección de memoria del elemento que se agregó. 

## 1.9.4.4. Función listAddFirst 

_Prototipo_ : `T* listAddFirst(List<T>& lst,T e);` 

_Descripción_ : Agrega el elemento `e` al inicio de la lista. 

_Parámetros_ : 

- `List<T>& lst` - Lista. 

- `T e` – Elemento que se agregará inicio de la lista. 

_Retorna_ : `T*` – Dirección de memoria del elemento que se agregó. 

## 1.9.4.5. Función listRemove 

_Prototipo_ : `T listRemove(List<T>& lst,K k,int cmpTK(T,K));` 

_Descripción_ : Remueve el elemento que concuerde con `k` según la función `cmpTK` . 

_Parámetros_ : 

- `List<T>& lst` - Lista. 

- `K k` – Elemento que será removido de la lista. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

116 |[Apéndice 2 ● Especificaciones y API] 

_Retorna_ : `T` – Elemento que fue removido. 

## 1.9.4.6. Función listRemoveFirst 

_Prototipo_ : `T listRemoveFirst(List<T>& lst);` 

_Descripción_ : Desenlaza y libera el primer nodo de la lista enlazada, retornando el valor del elemento que contenía. 

_Parámetro_ : `List<T>& lst` - Lista. 

_Retorna_ : `T` – Elemento que contenía el (ex) primer nodo de la lista. 

## 1.9.4.7. Función listFind 

_Prototipo_ : `T* listFind(List<T> lst,K k,int cmpTK(T,K));` 

_Descripción_ : Retorna la dirección del primer elemento concordante con `k` según `cmpTK` _Parámetros_ : 

- `List<T> lst` - Lista. 

- `K k` – Clave o elemento a buscar. 

- `int cmpTK(T,K)` – Función de comparación. 

_Retorna_ : `T*` – Dirección del elemento encontrado o `NULL` si hubo concordancia. 

## 1.9.4.8. Función listIsEmpty 

_Prototipo_ : `bool listIsEmpty(List<T> lst);` 

_Descripción_ : Indica si la lista está vacía o tiene elementos. 

_Parámetro_ : `List<T>& lst` – Lista. 

_Retorna_ : `bool` – `true` si la lista está vacía, `false` si tiene elementos. 

## 1.9.4.9. Función listSize 

_Prototipo_ : `int listSize(List<T> lst);` 

_Descripción_ : Indica cuántos elementos tiene la lista. 

_Parámetro_ : `List<T>& lst` – Lista. 

_Retorna_ : `int` – Cantidad de elementos que tiene la lista. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 117 

## 1.9.4.10. Función listFree 

_Prototipo_ : `void listFree(List<T>& lst);` 

_Descripción_ : Libera la memoria que ocupa la lista. 

_Parámetro_ : `List<T>& lst` – Lista. 

_Retorna_ : `void` . 

## 1.9.4.11. Función listDiscover 

_Prototipo_ : `T* listDiscover(List<T>& lst,T t,int cmpTT);` 

_Descripción_ : Descubre el elemento `t` en la lista `lst` 

_Parámetros_ : 

- `List<T>& lst` – Lista. 

- `T t` -  Elemento a descubir. 

_Retorna_ : `T*` - Dirección del elemento encontrado, o recientemente agregado al final de la lista `lst` . 

## 1.9.4.12. Función listOrderedInsert 

_Prototipo_ : `T* listOrderedInsert(List<T>& lst ,T t ,int cmpTT(T,T));` 

_Descripción_ : Inserta un elemento según el orden que establece `cmpTT` . La lista debe estar ordenada (según `cmpTT` ) o vacía. 

_Parámetros_ : 

- `List<T>& lst` - Lista. 

- `T t` – Elemento a insertar. 

- `int cmpTT(T,T)` – Función de comparación. 

_Retorna_ : `T*` – Dirección del elemento insertado. 

## 1.9.4.13. Función listSort 

_Prototipo_ : `void listSort(List<T> &lst,int cmpTT(T,T));` 

_Descripción_ : Ordena la lista según el criterio que establece `cmpTT` 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

118 |[Apéndice 2 ● Especificaciones y API] 

_Parámetros_ : 

- `List<T>& lst` – Lista. 

- `int cmpTT(T,T)` – Función de comparación. 

_Retorna_ : `void` . 

## 1.9.4.14. Función listReset 

_Prototipo_ : `void listReset(List<T>& lst);` 

_Descripción_ : Prepara la lista para iterarla. 

_Parámetro_ : `List<T>& lst` – Lista. 

_Retorna_ : `void` . 

## 1.9.4.15. Función listHasNext 

_Prototipo_ : `bool listHasNext(List<T> lst);` 

_Descripción_ : Indica si quedan más elementos para seguir iterando la lista. 

_Parámetro_ : `List<T>& lst` – Lista. 

_Retorna_ : `bool` – `true` si es posible seguir iterando la lista. 

## 1.9.4.16. Función listNext 

_Prototipo_ : `T* listNext(List<T>& lst);` 

_Descripción_ : Retorna la dirección del siguiente elemento de la lista en la iteración. _Parámetro_ : `List<T>& lst` – Lista. 

_Retorna_ : `T*` – Dirección del siguiente elemento en la iteración. 

## 1.9.4.17. Función listNext (sobrecarga) 

_Prototipo_ : `T* listNext(List<T>& lst,bool& eol);` 

_Descripción_ : Retorna la dirección del siguiente elemento de la lista en la iteración. 

_Parámetros_ : 

- `List<T>& lst` - Lista. 

- `bool& eol` – Indicador de que se llegó al final de la lista ( _End Of List_ 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 119 

_Retorna_ : `T*` – Dirección del siguiente elemento en la iteración. 

## 1.9.5. TAD Stack 

La siguientes funciones deben programarse en el archivo `Stack.hpp` . 

## 1.9.5.1. Estructura del TAD 

```
template<typename T>
struct Stack
{
   // implementacion a cargo del estudiante
};
```

## 1.9.5.2. Función stack 

_Prototipo_ : `Stack<T> stack();` 

_Descripción_ : Crea una pila vacía. 

_Retorna_ : `Stack<T>` – Una pila vacía, lista para usar. 

## 1.9.5.3. Función stackPush 

_Prototipo_ : `T* stackPush(Stack<T>& st,T e);` 

_Descripción_ : Apila el elemento `e` . 

_Parámetros_ : 

- `Stack<T>& st` - Pila. 

- `T e` – Elemento que se apilará. 

_Retorna_ : `T*` – Dirección de memoria del elemento que se apiló. 

## 1.9.5.4. Función stackPop 

_Prototipo_ : `T stackPop(Stack<T>& st);` 

_Descripción_ : Desapila un elemento. 

_Parámetro:_ `Stack<T>& st` - Pila. 

_Retorna_ : `T` – Elemento que se desapiló. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

120 |[Apéndice 2 ● Especificaciones y API] 

## 1.9.5.5. Función stackIsEmpty 

_Prototipo_ : `bool stackIsEmpty(Stack<T> st);` 

_Descripción_ : Retorna `true` o `false` según la pila tenga elementos o no. 

_Parámetro:_ `Stack<T> st` - Pila. 

_Retorna_ : `bool` – `true` o `false` según la pila tenga elementos o no. 

## 1.9.5.6. Función stackSize 

_Prototipo_ : `int stackSize(Stack<T> st);` 

_Descripción_ : Retorna la cantidad de elementos que tiene la pila. 

_Parámetro:_ `Stack<T> st` - Pila. 

_Retorna_ : `int` – Cuántos elementos tiene la pila. 

## 1.9.6. TAD Queue 

La siguientes funciones deben programarse en el archivo `Queue.hpp` 

## 1.9.6.1. Estructura del TAD 

```
template<typename T>
struct Queue
{
   // implementacion a cargo del estudiante
};
```

## 1.9.6.2. Función queue 

_Prototipo_ : `Queue<T> queue();` 

_Descripción_ : Crea una cola vacía. 

_Retorna_ : `Queue<T>` – Una cola vacía, lista para usar. 

## 1.9.6.3. Función queueEnqueue 

_Prototipo_ : `T* queueEnqueue(Queue<T>& q,T e);` 

_Descripción_ : Encola el elemento `e` . 

_Parámetros_ : 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

Curso de algoritmos y programación a fondo | 121 

- `Queue<T>& q` - Cola. 

- `T e` – Elemento que se encolará. 

_Retorna_ : `T*` – Dirección de memoria del elemento que se encoló. 

## 1.9.6.4. Función queueDequeue 

_Prototipo_ : `T queueDequeue(Queue<T>& q);` 

_Descripción_ : Desencola un elemento. 

_Parámetro:_ `Queue<T>& q` - Cola. 

_Retorna_ : `T` – Elemento que se desencoló. 

## 1.9.6.5. Función queueIsEmpty 

_Prototipo_ : `bool queueIsEmpty(Queue<T> q);` 

_Descripción_ : Retorna `true` o `false` según la cola tenga elementos o no. 

_Parámetro:_ `Queue<T> q` - Cola. 

_Retorna_ : `bool` – `true` o `false` según la cola tenga elementos o no. 

## 1.9.6.6. Función queueSize 

_Prototipo_ : `int queueSize(Queue<T> q);` 

_Descripción_ : Retorna la cantidad de elementos que tiene la cola. 

_Parámetro:_ `Queue<T> q` - Cola. 

_Retorna_ : `int` – Cuántos elementos tiene la cola. 

CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER 

**THE JAVA LISTENER** 

