#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
using std::string;

int length(string s)
{
    // cuenta la cantidad de letras de una cadena 
    int i = 0;
    while(s[i] != '\0'){
          i ++;
    }

    return i;
}

int charCount(string s, char c)
{
    // cuenta la cantidad de veces que aparece un caracter
     int cont = 0;
     int i = 0;
    while(s[i] != c){
          i ++;
    if(s[i] == c){
      cont ++;
    }
    }
    return cont;
}

string substring(string s, int d, int h)
{
  // Retorna la subcadena de s comprendida entre la posición d y el final de 
//la cadena.

  string resu = "";
    while(s[d]< s[h]){
          resu = resu + s[d];
    }
    return resu;
}

int indexOf(string s, char c)  // ok
{
      int i = 0;
    while(s[i] != c){
          i++;
          if(s[i] == '\0'){
          return -1;

          }
    }

    return i;
}

int indexOf(string s, char c, int offSet)  // ok
{
     int i = 0;
     i = i + offSet;
    while(s[i] != c){
          i++;
          if(s[i] == '\0'){
          return -1;

          }
    }

    return i;
}

int indexOf(string s, string toSearch)  // ok
{
    
     int i = 0;
     int pos = -1;
    while(s[i] != toSearch[0]){
          i++;
          if (s[i] == toSearch[0])
          {
            int j = 0;
            pos = i;
            while(s[i] == toSearch[j]){
                i++;
                j++;
            }
            if(j == length(toSearch)){
                return pos;
            }
            else{
                pos = -1;
            }

          }
          if(s[i] == '\0'){
          return pos;

          }
    }
    

    return pos;
}

int indexOf(string s, string toSearch, int offset)
{

    if(offset < 0 or offset > length(s)){
        return -1;
    }
    int i = 0 + offset
    
    ;
     int pos = -1;
    while(s[i] != toSearch[0]){
          i++;
          if (s[i] == toSearch[0])
          {
            int j = 0;
            pos = i;
            while(s[i] == toSearch[j]){
                i++;
                j++;
            }
            if(j == length(toSearch)){
                return pos;
            }
            else{
                pos = -1;
            }

          }
          if(s[i] == '\0'){
          return pos;

          }
    }
    

    return pos;
}

int lastIndexOf(string s, char c){
     int i = length(s);
    while(s[i] != c){
          i--;
        if(i==0 && s[i]){
            return -1;      
        
    }
    }
    

    return i;
}

int indexOfN(string s, char c, int n)
{
    int i = 0;
    int cont = 0;
    if(n <= 0 )
    {
        return -1;
    }
    while(s[i] != '\0'){
          
          if(s[i] == c){
            cont++;
            if(cont == n)
            {
                return i;
            }
          }
          i++;
    }
    if(n>cont)
    {
        return length(s);
    }
    return -1;
}

int charToInt(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 10;
    }
    return -1;
}

char intToChar(int i)
{
    
 if (i >= 0 && i <= 9)
    {
        return i + '0';
    }
    if (i >= 10 && i <= 35)
    {
        return i + 'A' - 10;
    }
    return -1;
}

int getDigit(int n, int i) // n es el numero , i es el digito 
{
    int cont = 0;
    if(n < 0)
    {
        n = n * -1;
}
  while(cont < i){
    if(n >= 10)
    {
        n = n / 10;
        cont++;
    }
    else if(n < 10 && n > -1)
    {
        n = n % 10;
    }
  }
  if(cont == i)
  {
    return n % 10;
  }
  else if (i) // anda a saber que estaba por hacer aca - Felipe
  {
    return -1;
  }
    return n;
}
// 123456 / 10 hasta llegar al digito n
// 12 % 10 = 2     4 es el digito


int digitCount(int n)
{
    return 0;
}

string intToString(int i)
{
    
    return "";
}

int stringToInt(string s, int b)  // ok
{
    return 0;
}

int stringToInt(string s)  // ok
{
    return 0;
}

string charToString(char c)
{
    return "";
}

char stringToChar(string s)
{
    return '0';
}

string stringToString(string s)
{
    return "";
}

string doubleToString(double d)
{
    return "";
}

double stringToDouble(string s)
{
    return 1.0;
}

bool isEmpty(string s)
{
    return true;
}

bool startsWith(string s, string x)
{
    return true;
}

bool endsWith(string s, string x)
{
    return true;
}

bool contains(string s, char c)
{
    return true;
}

string replace(string s, char oldChar, char newChar)
{
    return "";
}

string insertAt(string s, int pos, char c)
{
    return "";
}

string removeAt(string s, int pos)
{
    return "";
}

string ltrim(string s)
{
    return "";
}

string rtrim(string s)
{
    return "";
}

string trim(string s)
{
    return "";
}

string replicate(char c, int n)
{
    return "";
}

string spaces(int n)
{
    return "";
}

string lpad(string s, int n, char c)
{
    return "";
}

string rpad(string s, int n, char c)
{
    return "";
}

string cpad(string s, int n, char c)
{
    return "";
}

bool isDigit(char c)
{
    return true;
}

bool isLetter(char c)
{
    return true;
}

bool isUpperCase(char c)
{
    return true;
}

bool isLowerCase(char c)
{
    return true;
}

char toUpperCase(char c)
{
    return '0';
}

char toLowerCase(char c)
{
    return '0';
}

string toUpperCase(string s)
{
    return "";
}

string toLowerCase(string s)
{
    return "";
}

int cmpString(string a, string b)
{
    return 0;
}

int cmpDouble(double a, double b)
{
    return 0;
}

char* stringToCString(string s)
{
    char* ret = new char[length(s) + 1];

    int i = 0;
    while(s[i] != '\0')
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
