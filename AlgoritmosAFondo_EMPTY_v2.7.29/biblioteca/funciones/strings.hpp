#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::string;

// ═══════════════════════════════════════════════════════════════
//  FUNCIONES BÁSICAS DE STRINGS
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// length: retorna la cantidad de caracteres de la cadena s.
// Recorre s carácter por carácter hasta encontrar el '\0'.
// Ejemplo: length("hola") → 4 | length("") → 0
// ---------------------------------------------------------------
int length(string s)
{
    int i = 0;
    while (s[i] != '\0') // '\0' marca el final de la cadena
    {
        i++;
    }
    return i;
}

// ---------------------------------------------------------------
// charCount: cuenta cuántas veces aparece el carácter c en s.
// Recorre toda la cadena y suma cada vez que encuentra c.
// Ejemplo: charCount("banana", 'a') → 3
// ---------------------------------------------------------------
int charCount(string s, char c)
{
    int cont = 0; // acumulador de ocurrencias
    int i    = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            cont++;
        }
        i++;
    }
    return cont;
}

// ---------------------------------------------------------------
// substring: extrae una subcadena de s desde d (inclusive)
// hasta h (no inclusive). Copia letra por letra en el rango [d, h).
// Ejemplo: substring("hola mundo", 0, 4) → "hola"
//          substring("hola mundo", 5, 9) → "mund"
// ---------------------------------------------------------------
string substring(string s, int d, int h)
{
    string resultado = "";
    for (int i = d; i < h; i++) // va de d hasta h sin incluir h
    {
        resultado = resultado + s[i];
    }
    return resultado;
}

// ---------------------------------------------------------------
// substring (sobrecarga): extrae desde d hasta el final de s.
// Equivale a substring(s, d, length(s)).
// Ejemplo: substring("hola mundo", 5) → "mundo"
// ---------------------------------------------------------------
string substring(string s, int d)
{
    return substring(s, d, length(s));
}

// ═══════════════════════════════════════════════════════════════
//  FUNCIONES indexOf
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// indexOf: retorna la posición de la primera ocurrencia de c en s.
// Si c no está en s, retorna -1 (valor negativo).
// Ejemplo: indexOf("hola", 'l') → 2 | indexOf("hola", 'z') → -1
// ---------------------------------------------------------------
int indexOf(string s, char c)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c) return i; // encontrado → devuelve posición
        i++;
    }
    return -1; // no encontrado
}

// ---------------------------------------------------------------
// indexOf (con offset): igual al anterior pero empieza a buscar
// desde la posición offSet, descartando los caracteres anteriores.
// Ejemplo: indexOf("banana", 'a', 2) → 3
// ---------------------------------------------------------------
int indexOf(string s, char c, int offSet)
{
    int i = offSet; // salta directamente al punto de partida
    while (s[i] != '\0')
    {
        if (s[i] == c) return i;
        i++;
    }
    return -1;
}

// ---------------------------------------------------------------
// indexOf (subcadena): retorna la posición donde empieza toSearch
// dentro de s. Compara carácter por carácter cuando hay candidato.
// Si no la encuentra, retorna -1.
// Ejemplo: indexOf("hola mundo", "mundo") → 5
// ---------------------------------------------------------------
int indexOf(string s, string toSearch)
{
    int largo = length(toSearch);
    int i     = 0;

    while (s[i] != '\0')
    {
        if (s[i] == toSearch[0]) // posible inicio de coincidencia
        {
            int pos = i; // guardamos dónde empieza el candidato
            int j   = 0;
            while (j < largo && s[i] == toSearch[j]) // comparamos letra a letra
            {
                i++;
                j++;
            }
            if (j == largo) return pos; // coincidieron todas → encontrado
            i = pos + 1;                // no coincidió todo → retrocedemos
        }
        else
        {
            i++;
        }
    }
    return -1;
}

// ---------------------------------------------------------------
// indexOf (subcadena con offset): igual al anterior pero empieza
// la búsqueda desde la posición offset.
// Retorna -1 si offset es inválido o no encuentra toSearch.
// ---------------------------------------------------------------
int indexOf(string s, string toSearch, int offset)
{
    if (offset < 0 || offset > length(s))
    {
        return -1; // offset fuera de rango → no puede buscar
    }

    int largo = length(toSearch);
    int i     = offset;

    while (s[i] != '\0')
    {
        if (s[i] == toSearch[0])
        {
            int pos = i;
            int j   = 0;
            while (j < largo && s[i] == toSearch[j])
            {
                i++;
                j++;
            }
            if (j == largo) return pos;
            i = pos + 1;
        }
        else
        {
            i++;
        }
    }
    return -1;
}

// ---------------------------------------------------------------
// lastIndexOf: retorna la posición de la ÚLTIMA ocurrencia de c.
// Recorre s de derecha a izquierda.
// Si c no está en s, retorna -1 (valor negativo).
// Ejemplo: lastIndexOf("banana", 'a') → 5
// ---------------------------------------------------------------
int lastIndexOf(string s, char c)
{
    int i = length(s) - 1; // empieza desde la última letra
    while (i >= 0)
    {
        if (s[i] == c) return i;
        i--; // retrocede hacia el inicio
    }
    return -1;
}

// ---------------------------------------------------------------
// indexOfN: retorna la posición de la N-ésima ocurrencia de c.
// Si n <= 0 → retorna -1.
// Si n supera la cantidad de ocurrencias → retorna length(s).
// Ejemplo: indexOfN("banana", 'a', 2) → 3
//          indexOfN("banana", 'a', 9) → 6  (length de "banana")
// ---------------------------------------------------------------
int indexOfN(string s, char c, int n)
{
    if (n <= 0) return -1; // n inválido

    int i    = 0;
    int cont = 0; // contador de ocurrencias encontradas
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            cont++;
            if (cont == n) return i; // encontramos la n-ésima
        }
        i++;
    }
    return length(s); // n supera las ocurrencias reales
}

// ═══════════════════════════════════════════════════════════════
//  CONVERSIONES ENTRE TIPOS
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// charToInt: convierte un carácter a su valor numérico.
// Acepta '0'-'9' (→ 0-9), 'A'-'Z' y 'a'-'z' (→ 10-35).
// Si el carácter no es válido, retorna -1.
// Ejemplo: charToInt('A') → 10 | charToInt('9') → 9
// ---------------------------------------------------------------
int charToInt(char c)
{
    if (c >= '0' && c <= '9') return c - '0';       // dígito decimal
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;  // letra mayúscula
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;  // letra minúscula
    return -1;
}

// ---------------------------------------------------------------
// intToChar: convierte un entero a su carácter equivalente.
// Acepta 0-9 (→ '0'-'9') o 65-90 (códigos ASCII de 'A'-'Z').
// Si i está fuera de rango, retorna -1.
// Ejemplo: intToChar(5) → '5' | intToChar(65) → 'A'
// ---------------------------------------------------------------
char intToChar(int i)
{
    if (i >= 0  && i <= 9)  return i + '0';  // dígito → carácter numérico
    if (i >= 65 && i <= 90) return (char)i;  // código ASCII → letra mayúscula
    return -1;
}

// ---------------------------------------------------------------
// getDigit: retorna el dígito en la posición i del número n,
// contando desde la derecha y empezando en 0.
// Si i supera la cantidad de dígitos, retorna -1.
// Ejemplo: getDigit(12345, 0) → 5 | getDigit(12345, 2) → 3
// ---------------------------------------------------------------
int getDigit(int n, int i)
{
    if (n < 0) n = -n; // trabajamos con el valor absoluto
    for (int k = 0; k < i; k++)
    {
        n = n / 10;            // descartamos el último dígito
        if (n == 0) return -1; // ya no quedan dígitos en esa posición
    }
    return n % 10; // último dígito restante es el que buscamos
}

// ---------------------------------------------------------------
// digitCount: cuenta cuántos dígitos tiene el número entero a.
// Para negativos usa el valor absoluto. El 0 tiene 1 dígito.
// Ejemplo: digitCount(12345) → 5 | digitCount(0) → 1
// ---------------------------------------------------------------
int digitCount(int a)
{
    if (a < 0) a = -a; // valor absoluto para negativos
    int c = 1;         // mínimo 1 dígito
    while (a >= 10)    // mientras queden más de un dígito
    {
        a = a / 10;
        c++;
    }
    return c;
}

// ---------------------------------------------------------------
// intToString: convierte un entero a su representación en texto.
// Extrae dígito por dígito con % 10, los va pegando al frente.
// Ejemplo: intToString(123) → "123" | intToString(-42) → "-42"
// ---------------------------------------------------------------
string intToString(int a)
{
    string c   = "";
    char   g;
    bool   neg = false;

    if (a < 0) { a = a * -1; neg = true; } // guardamos si es negativo
    if (a == 0) { c = intToChar(a) + c; return c; } // caso especial: cero

    while (a > 0)
    {
        int b = a % 10; // último dígito
        g     = intToChar(b);
        c     = g + c;  // lo pegamos al frente para mantener el orden
        a     = a / 10;
    }

    if (neg) c = '-' + c; // reponemos el signo negativo
    return c;
}

// ---------------------------------------------------------------
// stringToInt (con base): convierte s a entero en la base b dada.
// Acepta mayúsculas y minúsculas. Maneja signo negativo.
// Si b es inválida o hay un carácter fuera de base, retorna -1.
// Ejemplo: stringToInt("FF", 16) → 255 | stringToInt("11", 2) → 3
// ---------------------------------------------------------------
int stringToInt(string s, int b)
{
    if (b < 2 || b > 36) return -1; // base fuera de rango

    bool neg = false;
    int  i   = 0;

    if (s[0] == '-') { neg = true; i = 1; } // detectamos signo negativo

    int acu = 0;
    while (s[i] != '\0')
    {
        int val;
        if      (s[i] >= '0' && s[i] <= '9') val = s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'Z') val = s[i] - 'A' + 10;
        else if (s[i] >= 'a' && s[i] <= 'z') val = s[i] - 'a' + 10;
        else return -1; // carácter inválido

        if (val >= b) return -1; // dígito no válido para esta base

        acu = acu * b + val; // acumulamos en la base dada
        i++;
    }

    return neg ? -acu : acu;
}

// ---------------------------------------------------------------
// stringToInt (base 10): convierte s a entero decimal.
// Delega en la versión con base, pasando b = 10.
// Ejemplo: stringToInt("123") → 123 | stringToInt("-7") → -7
// ---------------------------------------------------------------
int stringToInt(string s)
{
    return stringToInt(s, 10);
}

// ---------------------------------------------------------------
// charToString: convierte un carácter en un string de longitud 1.
// Ejemplo: charToString('h') → "h"
// ---------------------------------------------------------------
string charToString(char c)
{
    string b = " "; // string de un espacio para tener lugar para un char
    b[0]     = c;   // reemplazamos el espacio por el carácter dado
    return b;
}

// ---------------------------------------------------------------
// stringToChar: retorna el primer (y único) carácter de s.
// Se asume que s tiene longitud exactamente 1.
// Ejemplo: stringToChar("h") → 'h'
// ---------------------------------------------------------------
char stringToChar(string s)
{
    return s[0];
}

// ---------------------------------------------------------------
// stringToString: retorna una copia del mismo string s.
// Ejemplo: stringToString("hola") → "hola"
// ---------------------------------------------------------------
string stringToString(string s)
{
    return s;
}

// ---------------------------------------------------------------
// doubleToString: convierte un número decimal a texto.
// Usa sprintf con formato %g para elegir la representación más corta.
// Ejemplo: doubleToString(3.14) → "3.14"
// ---------------------------------------------------------------
string doubleToString(double d)
{
    char buffer[64];          // buffer temporal para armar el texto
    sprintf(buffer, "%g", d); // %g elige el formato más compacto
    return string(buffer);
}

// ---------------------------------------------------------------
// stringToDouble: convierte texto a número decimal.
// Separa la parte entera de la decimal en el punto '.'.
// Maneja signo negativo. Si no hay '.', trata todo como entero.
// Ejemplo: stringToDouble("3.14") → 3.14 | stringToDouble("-2.5") → -2.5
// ---------------------------------------------------------------
double stringToDouble(string s)
{
    bool neg    = false;
    int  inicio = 0;

    if (s[0] == '-') { neg = true; inicio = 1; } // detectamos signo negativo

    int    puntoPos = indexOf(s, '.'); // posición del punto decimal
    string c        = ""; // parte entera como texto
    string d        = ""; // parte decimal como texto
    double e        = 0;  // valor de la parte entera
    double k        = 0;  // valor de la parte decimal
    int    p        = 1;  // divisor (10^cantidad de decimales)

    if (puntoPos == -1) // no hay punto → solo parte entera
    {
        c = substring(s, inicio, length(s));
        e = stringToInt(c);
    }
    else
    {
        c = substring(s, inicio, puntoPos);         // parte entera
        d = substring(s, puntoPos + 1, length(s));  // parte decimal
        e = stringToInt(c);
        k = stringToInt(d);
        int o = length(d); // cantidad de dígitos decimales
        int i = 0;
        while (i < o) { p = p * 10; i++; } // calculamos el divisor
    }

    double resultado = e + k / p;
    return neg ? -resultado : resultado;
}

// ═══════════════════════════════════════════════════════════════
//  FUNCIONES DE CONSULTA
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// isEmpty: retorna true solo si s es exactamente "".
// Una cadena con espacios ("   ") NO es vacía.
// Ejemplo: isEmpty("") → true | isEmpty("   ") → false
// ---------------------------------------------------------------
bool isEmpty(string s)
{
    return s[0] == '\0'; // si el primer carácter es el fin, la cadena es vacía
}

// ---------------------------------------------------------------
// startsWith: retorna true si s comienza con el texto x.
// Compara x contra el inicio de s letra por letra.
// Ejemplo: startsWith("hola mundo", "hola") → true
// ---------------------------------------------------------------
bool startsWith(string s, string x)
{
    int i = 0;
    while (x[i] != '\0') // recorremos todo x
    {
        if (s[i] != x[i]) return false; // diferencia encontrada → false
        i++;
    }
    return true; // todas las letras de x coincidieron
}

// ---------------------------------------------------------------
// endsWith: retorna true si s termina con el texto x.
// Alinea el final de x con el final de s y compara letra por letra.
// Ejemplo: endsWith("hola mundo", "mundo") → true
// ---------------------------------------------------------------
bool endsWith(string s, string x)
{
    int largoS = length(s);
    int largoX = length(x);

    if (largoX > largoS) return false; // x más largo que s → imposible

    for (int i = 0; i < largoX; i++)
    {
        if (s[largoS - largoX + i] != x[i]) return false; // comparamos desde el final
    }
    return true;
}

// ---------------------------------------------------------------
// contains: retorna true si el carácter c aparece al menos una vez en s.
// Usa indexOf: si retorna algo distinto de -1, el carácter está.
// Ejemplo: contains("hola", 'o') → true | contains("hola", 'z') → false
// ---------------------------------------------------------------
bool contains(string s, char c)
{
    return indexOf(s, c) != -1;
}

// ═══════════════════════════════════════════════════════════════
//  FUNCIONES DE MODIFICACIÓN
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// replace: reemplaza TODAS las ocurrencias de oldChar por newChar.
// Modifica s en el lugar (trabaja sobre la copia por valor).
// Ejemplo: replace("banana", 'a', 'o') → "bonono"
// ---------------------------------------------------------------
string replace(string s, char oldChar, char newChar)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == oldChar) s[i] = newChar; // reemplazamos si coincide
        i++;
    }
    return s;
}

// ---------------------------------------------------------------
// insertAt: inserta el carácter c en la posición pos de s.
// Los caracteres en pos en adelante se desplazan a la derecha.
// Si pos >= length(s), inserta al final.
// Ejemplo: insertAt("hola", 2, 'X') → "hoXla"
// ---------------------------------------------------------------
string insertAt(string s, int pos, char c)
{
    string resultado = "";
    int    i         = 0;

    while (s[i] != '\0')
    {
        if (i == pos) resultado += c; // insertamos antes de la posición pedida
        resultado += s[i];
        i++;
    }
    if (pos >= i) resultado += c; // si pos es al final o más allá

    return resultado;
}

// ---------------------------------------------------------------
// removeAt: elimina el carácter en la posición pos de s.
// Copia todos los caracteres excepto el de la posición dada.
// Ejemplo: removeAt("hola", 1) → "hla"
// ---------------------------------------------------------------
string removeAt(string s, int pos)
{
    string resultado = "";
    int    i         = 0;

    while (s[i] != '\0')
    {
        if (i != pos) resultado += s[i]; // copiamos todo menos pos
        i++;
    }
    return resultado;
}

// ═══════════════════════════════════════════════════════════════
//  ESPACIOS Y RELLENO
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// ltrim: elimina los espacios del inicio (izquierda) de s.
// Avanza i hasta el primer carácter no-espacio, luego copia el resto.
// Ejemplo: ltrim("   hola   ") → "hola   "
// ---------------------------------------------------------------
string ltrim(string s)
{
    int i = 0;
    while (s[i] == ' ') i++; // saltamos los espacios del inicio

    string resultado = "";
    while (s[i] != '\0')
    {
        resultado += s[i];
        i++;
    }
    return resultado;
}

// ---------------------------------------------------------------
// rtrim: elimina los espacios del final (derecha) de s.
// Retrocede desde el final hasta el último carácter no-espacio.
// Ejemplo: rtrim("   hola   ") → "   hola"
// ---------------------------------------------------------------
string rtrim(string s)
{
    int i = length(s) - 1;
    while (i >= 0 && s[i] == ' ') i--; // retrocedemos sobre los espacios finales

    return substring(s, 0, i + 1); // devolvemos hasta el último no-espacio
}

// ---------------------------------------------------------------
// trim: elimina espacios del inicio Y del final de s.
// Aplica rtrim primero y luego ltrim sobre el resultado.
// Ejemplo: trim("   hola   ") → "hola"
// ---------------------------------------------------------------
string trim(string s)
{
    return ltrim(rtrim(s));
}

// ---------------------------------------------------------------
// replicate: genera un string con el carácter c repetido n veces.
// Ejemplo: replicate('*', 4) → "****"
// ---------------------------------------------------------------
string replicate(char c, int n)
{
    string resultado = "";
    for (int i = 0; i < n; i++)
    {
        resultado += c;
    }
    return resultado;
}

// ---------------------------------------------------------------
// spaces: genera un string con n espacios en blanco.
// Delega en replicate con el carácter espacio.
// Ejemplo: spaces(4) → "    "
// ---------------------------------------------------------------
string spaces(int n)
{
    return replicate(' ', n);
}

// ---------------------------------------------------------------
// lpad: rellena s con el carácter c por la IZQUIERDA hasta largo n.
// Si length(s) >= n, retorna s sin cambios.
// Ejemplo: lpad("hola", 8, '*') → "****hola"
// ---------------------------------------------------------------
string lpad(string s, int n, char c)
{
    int largo = length(s);
    if (largo >= n) return s; // ya tiene el largo requerido
    return replicate(c, n - largo) + s;
}

// ---------------------------------------------------------------
// rpad: rellena s con el carácter c por la DERECHA hasta largo n.
// Si length(s) >= n, retorna s sin cambios.
// Ejemplo: rpad("hola", 8, '*') → "hola****"
// ---------------------------------------------------------------
string rpad(string s, int n, char c)
{
    int largo = length(s);
    if (largo >= n) return s;
    return s + replicate(c, n - largo);
}

// ---------------------------------------------------------------
// cpad: centra s rellenando con c a ambos lados hasta largo n.
// Si el relleno total es impar, el lado derecho recibe el extra.
// Si length(s) >= n, retorna s sin cambios.
// Ejemplo: cpad("hi", 8, '*') → "***hi***"
// ---------------------------------------------------------------
string cpad(string s, int n, char c)
{
    int largo = length(s);
    if (largo >= n) return s;

    int totalRelleno = n - largo;
    int rellenoIzq   = totalRelleno / 2;         // mitad para la izquierda
    int rellenoDer   = totalRelleno - rellenoIzq; // el resto para la derecha

    return replicate(c, rellenoIzq) + s + replicate(c, rellenoDer);
}

// ═══════════════════════════════════════════════════════════════
//  CLASIFICACIÓN DE CARACTERES
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// isDigit: retorna true solo si c es un dígito del '0' al '9'.
// Ejemplo: isDigit('5') → true | isDigit('a') → false
// ---------------------------------------------------------------
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

// ---------------------------------------------------------------
// isLetter: retorna true si c es una letra mayúscula o minúscula.
// Ejemplo: isLetter('a') → true | isLetter('5') → false
// ---------------------------------------------------------------
bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// ---------------------------------------------------------------
// isUpperCase: retorna true solo si c es una letra mayúscula (A-Z).
// Ejemplo: isUpperCase('A') → true | isUpperCase('a') → false
// ---------------------------------------------------------------
bool isUpperCase(char c)
{
    return c >= 'A' && c <= 'Z';
}

// ---------------------------------------------------------------
// isLowerCase: retorna true solo si c es una letra minúscula (a-z).
// Ejemplo: isLowerCase('a') → true | isLowerCase('A') → false
// ---------------------------------------------------------------
bool isLowerCase(char c)
{
    return c >= 'a' && c <= 'z';
}

// ═══════════════════════════════════════════════════════════════
//  MAYÚSCULAS / MINÚSCULAS
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// toUpperCase (char): convierte c a mayúscula sumando 32 en ASCII.
// Si c ya es mayúscula o no es letra, retorna c sin cambios.
// Ejemplo: toUpperCase('a') → 'A' | toUpperCase('5') → '5'
// ---------------------------------------------------------------
char toUpperCase(char c)
{
    if (isLowerCase(c)) return c - 32; // diferencia ASCII entre 'a' y 'A' es 32
    return c;
}

// ---------------------------------------------------------------
// toLowerCase (char): convierte c a minúscula restando 32 en ASCII.
// Si c ya es minúscula o no es letra, retorna c sin cambios.
// Ejemplo: toLowerCase('A') → 'a' | toLowerCase('5') → '5'
// ---------------------------------------------------------------
char toLowerCase(char c)
{
    if (isUpperCase(c)) return c + 32;
    return c;
}

// ---------------------------------------------------------------
// toUpperCase (string): convierte todo s a mayúsculas.
// Aplica toUpperCase(char) sobre cada carácter de s.
// Ejemplo: toUpperCase("hola Mundo") → "HOLA MUNDO"
// ---------------------------------------------------------------
string toUpperCase(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = toUpperCase(s[i]); // convertimos letra por letra
        i++;
    }
    return s;
}

// ---------------------------------------------------------------
// toLowerCase (string): convierte todo s a minúsculas.
// Aplica toLowerCase(char) sobre cada carácter de s.
// Ejemplo: toLowerCase("HOLA MUNDO") → "hola mundo"
// ---------------------------------------------------------------
string toLowerCase(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = toLowerCase(s[i]);
        i++;
    }
    return s;
}

// ═══════════════════════════════════════════════════════════════
//  COMPARACIÓN
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// cmpString: compara dos cadenas letra por letra.
// Retorna 0 si son iguales, negativo si a < b, positivo si a > b.
// Ejemplo: cmpString("abc", "abd") → negativo (c < d)
// ---------------------------------------------------------------
int cmpString(string a, string b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i]) return a[i] - b[i]; // primera diferencia → decide
        i++;
    }
    return (int)a[i] - (int)b[i]; // el más corto "viene antes"
}

// ---------------------------------------------------------------
// cmpDouble: compara dos números decimales.
// Retorna -1 si a < b, 1 si a > b, 0 si son iguales.
// Ejemplo: cmpDouble(1.0, 2.0) → -1 | cmpDouble(3.0, 3.0) → 0
// ---------------------------------------------------------------
int cmpDouble(double a, double b)
{
    if (a < b) return -1;
    if (a > b) return  1;
    return 0;
}

// ═══════════════════════════════════════════════════════════════
//  CONVERSIÓN string ↔ char[]
// ═══════════════════════════════════════════════════════════════

// ---------------------------------------------------------------
// stringToCString: convierte un string de C++ a un array de char
// estilo C (terminado en '\0'). El llamador debe liberar con delete[].
// ---------------------------------------------------------------
char* stringToCString(string s)
{
    char* ret = new char[length(s) + 1]; // +1 para el '\0' final
    int   i   = 0;
    while (s[i] != '\0')
    {
        ret[i] = (char)s[i];
        i++;
    }
    ret[i] = '\0';
    return ret;
}

// ---------------------------------------------------------------
// cStringToString: convierte un array de char estilo C a string C++.
// ---------------------------------------------------------------
string cStringToString(char c[])
{
    return string(c);
}

#endif
