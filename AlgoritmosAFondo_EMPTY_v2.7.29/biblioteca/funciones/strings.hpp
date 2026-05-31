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

int length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int charCount(string s, char c)
{
    int cont = 0;
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

// d inclusive, h exclusive
string substring(string s, int d, int h)
{
    string resultado = "";
    for (int i = d; i < h; i++)
    {
        resultado = resultado + s[i];
    }
    return resultado;
}

// desde d hasta el final
string substring(string s, int d)
{
    return substring(s, d, length(s));
}

// ═══════════════════════════════════════════════════════════════
//  FUNCIONES indexOf
// ═══════════════════════════════════════════════════════════════

int indexOf(string s, char c)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c) return i;
        i++;
    }
    return -1;
}

int indexOf(string s, char c, int offSet)
{
    int i = offSet;
    while (s[i] != '\0')
    {
        if (s[i] == c) return i;
        i++;
    }
    return -1;
}

int indexOf(string s, string toSearch)
{
    int largo = length(toSearch);
    int i     = 0;

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

int indexOf(string s, string toSearch, int offset)
{
    if (offset < 0 || offset > length(s))
    {
        return -1;
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

int lastIndexOf(string s, char c)
{
    int i = length(s) - 1;
    while (i >= 0)
    {
        if (s[i] == c) return i;
        i--;
    }
    return -1;
}

int indexOfN(string s, char c, int n)
{
    if (n <= 0) return -1;

    int i    = 0;
    int cont = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            cont++;
            if (cont == n) return i;
        }
        i++;
    }
    return length(s);
}

// ═══════════════════════════════════════════════════════════════
//  CONVERSIONES ENTRE TIPOS
// ═══════════════════════════════════════════════════════════════

int charToInt(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

char intToChar(int i)
{
    if (i >= 0  && i <= 9)  return i + '0';
    if (i >= 65 && i <= 90) return (char)i;
    return -1;
}

int getDigit(int n, int i)
{
    if (n < 0) n = -n;
    for (int k = 0; k < i; k++)
    {
        n = n / 10;
        if (n == 0) return -1;
    }
    return n % 10;
}

int digitCount(int a)
{
    if (a < 0) a = -a;
    int c = 1;
    while (a >= 10)
    {
        a = a / 10;
        c++;
    }
    return c;
}

string intToString(int a)
{
    string c    = "";
    char   g;
    bool   neg  = false;

    if (a < 0) { a = a * -1; neg = true; }
    if (a == 0) { c = intToChar(a) + c; return c; }

    while (a > 0)
    {
        int b = a % 10;
        g     = intToChar(b);
        c     = g + c;
        a     = a / 10;
    }

    if (neg) c = '-' + c;
    return c;
}

int stringToInt(string s, int b)
{
    if (b < 2 || b > 36) return -1;

    bool neg = false;
    int  i   = 0;

    if (s[0] == '-') { neg = true; i = 1; }

    int acu = 0;
    while (s[i] != '\0')
    {
        int val;
        if      (s[i] >= '0' && s[i] <= '9') val = s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'Z') val = s[i] - 'A' + 10;
        else if (s[i] >= 'a' && s[i] <= 'z') val = s[i] - 'a' + 10;
        else return -1;

        if (val >= b) return -1;

        acu = acu * b + val;
        i++;
    }

    return neg ? -acu : acu;
}

int stringToInt(string s)
{
    return stringToInt(s, 10);
}

string charToString(char c)
{
    string b = " ";
    b[0]     = c;
    return b;
}

char stringToChar(string s)
{
    return s[0];
}

string stringToString(string s)
{
    return s;
}

string doubleToString(double d)
{
    char buffer[64];
    sprintf(buffer, "%g", d);
    return string(buffer);
}

double stringToDouble(string s)
{
    bool neg    = false;
    int  inicio = 0;

    if (s[0] == '-') { neg = true; inicio = 1; }

    int    puntoPos = indexOf(s, '.');
    string c        = "";
    string d        = "";
    double e        = 0;
    double k        = 0;
    int    p        = 1;

    if (puntoPos == -1)
    {
        c = substring(s, inicio, length(s));
        e = stringToInt(c);
    }
    else
    {
        c = substring(s, inicio, puntoPos);
        d = substring(s, puntoPos + 1, length(s));
        e = stringToInt(c);
        k = stringToInt(d);
        int o = length(d);
        int i = 0;
        while (i < o) { p = p * 10; i++; }
    }

    double resultado = e + k / p;
    return neg ? -resultado : resultado;
}

// ═══════════════════════════════════════════════════════════════
//  FUNCIONES DE CONSULTA
// ═══════════════════════════════════════════════════════════════

bool isEmpty(string s)
{
    return s[0] == '\0';
}

bool startsWith(string s, string x)
{
    int i = 0;
    while (x[i] != '\0')
    {
        if (s[i] != x[i]) return false;
        i++;
    }
    return true;
}

bool endsWith(string s, string x)
{
    int largoS = length(s);
    int largoX = length(x);

    if (largoX > largoS) return false;

    for (int i = 0; i < largoX; i++)
    {
        if (s[largoS - largoX + i] != x[i]) return false;
    }
    return true;
}

bool contains(string s, char c)
{
    return indexOf(s, c) != -1;
}

// ═══════════════════════════════════════════════════════════════
//  FUNCIONES DE MODIFICACIÓN
// ═══════════════════════════════════════════════════════════════

string replace(string s, char oldChar, char newChar)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == oldChar) s[i] = newChar;
        i++;
    }
    return s;
}

string insertAt(string s, int pos, char c)
{
    string resultado = "";
    int    i         = 0;

    while (s[i] != '\0')
    {
        if (i == pos) resultado += c;
        resultado += s[i];
        i++;
    }
    if (pos >= i) resultado += c;

    return resultado;
}

string removeAt(string s, int pos)
{
    string resultado = "";
    int    i         = 0;

    while (s[i] != '\0')
    {
        if (i != pos) resultado += s[i];
        i++;
    }
    return resultado;
}

// ═══════════════════════════════════════════════════════════════
//  ESPACIOS Y RELLENO
// ═══════════════════════════════════════════════════════════════

string ltrim(string s)
{
    int i = 0;
    while (s[i] == ' ') i++;

    string resultado = "";
    while (s[i] != '\0')
    {
        resultado += s[i];
        i++;
    }
    return resultado;
}

string rtrim(string s)
{
    int i = length(s) - 1;
    while (i >= 0 && s[i] == ' ') i--;

    return substring(s, 0, i + 1);
}

string trim(string s)
{
    return ltrim(rtrim(s));
}

string replicate(char c, int n)
{
    string resultado = "";
    for (int i = 0; i < n; i++)
    {
        resultado += c;
    }
    return resultado;
}

string spaces(int n)
{
    return replicate(' ', n);
}

string lpad(string s, int n, char c)
{
    int largo = length(s);
    if (largo >= n) return s;
    return replicate(c, n - largo) + s;
}

string rpad(string s, int n, char c)
{
    int largo = length(s);
    if (largo >= n) return s;
    return s + replicate(c, n - largo);
}

string cpad(string s, int n, char c)
{
    int largo = length(s);
    if (largo >= n) return s;

    int totalRelleno = n - largo;
    int rellenoIzq   = totalRelleno / 2;
    int rellenoDer   = totalRelleno - rellenoIzq;

    return replicate(c, rellenoIzq) + s + replicate(c, rellenoDer);
}

// ═══════════════════════════════════════════════════════════════
//  CLASIFICACIÓN DE CARACTERES
// ═══════════════════════════════════════════════════════════════

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isUpperCase(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool isLowerCase(char c)
{
    return c >= 'a' && c <= 'z';
}

// ═══════════════════════════════════════════════════════════════
//  MAYÚSCULAS / MINÚSCULAS
// ═══════════════════════════════════════════════════════════════

char toUpperCase(char c)
{
    if (isLowerCase(c)) return c - 32;
    return c;
}

char toLowerCase(char c)
{
    if (isUpperCase(c)) return c + 32;
    return c;
}

string toUpperCase(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = toUpperCase(s[i]);
        i++;
    }
    return s;
}

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

int cmpString(string a, string b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i]) return a[i] - b[i];
        i++;
    }
    return (int)a[i] - (int)b[i];
}

int cmpDouble(double a, double b)
{
    if (a < b) return -1;
    if (a > b) return  1;
    return 0;
}

// ═══════════════════════════════════════════════════════════════
//  CONVERSIÓN string ↔ char[]
// ═══════════════════════════════════════════════════════════════

char* stringToCString(string s)
{
    char* ret = new char[length(s) + 1];
    int   i   = 0;
    while (s[i] != '\0')
    {
        ret[i] = (char)s[i];
        i++;
    }
    ret[i] = '\0';
    return ret;
}

string cStringToString(char c[])
{
    return string(c);
}

#endif
