#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <stdio.h>
#include <iostream>
#include "strings.hpp"
using std::string;

int tokenCount(string s, char sep)
{
    int c = 0;
    if(s != ""){
    c = charCount(s,sep) + 1;
    }else if(s==""){
        c = 0;
    }else{
        c = 1;
    };
    return c;
}  

void addToken(string& s, char sep, string t)
{
if(s == ""){
    s = t;
}else{
 s = s + sep + t; 
}
}

string getTokenAt(string s, char sep, int i)
{
    int e = 0; 
    int c = 0;
    int d = 0;

    if(i > 0){
        while(c < length(s)){
            if(s[c] == sep){ e++; } // contamos los separadores
            if(e == i){ d = c + 1; break; } // nos quedamos con la posicion que coincida
            c++; // contamos la posicion
        }
    }

    // retornamos el string desde d hasta la siguiente ocurrencia del sep
    int h = indexOf(s, sep, d);
    if(h == -1) h = length(s);

    return substring(s, d, h);
}

void removeTokenAt(string& s, char sep, int i)
{
    int e = 0;
    int c = 0;
    int d = 0;
    int p = length(s); // separador que sigue al token, o fin del string
    string k = "";
    string j = "";

    if(i > 0){
        while(c < length(s)){
            if(s[c] == sep){ e++; }
            if(e == i){ d = c + 1; break; } // d = inicio del token i
            c++;
        }
        c++; // avanzar dentro del token (evita re-contar el sep ya encontrado)
    }

    // buscar el separador que termina el token i
    while(c < length(s)){
        if(s[c] == sep){ p = c; break; }
        c++;
    }

    if(i == 0){
        j = (p < length(s)) ? substring(s, p + 1, length(s)) : "";
    } else {
        k = substring(s, 0, d - 1); // antes del sep previo al token
        j = substring(s, p, length(s)); // desde el sep siguiente 
    }
    s = k + j;
}

void setTokenAt(string& s, char sep, string t, int i){
    int e = 0, c = 0, d = 0;
    int p = length(s);

    if(i > 0){
        while(c < length(s)){
            if(s[c] == sep){ e++; }
            if(e == i){ d = c + 1; break; }
            c++;
        }
        c++;
    }

    while(c < length(s)){
        if(s[c] == sep){ p = c; break; }
        c++;
    }

    s = substring(s, 0, d) + t + substring(s, p, length(s));
}

int findToken(string s, char sep, string t)
{
    int i = 0;
    while(i < tokenCount(s, sep)){
        if(getTokenAt(s, sep, i) == t){ return i; }
        i++;
    }
    return -1;
}

#endif
