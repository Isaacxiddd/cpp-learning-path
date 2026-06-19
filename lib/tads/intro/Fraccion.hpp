#ifndef _TFRACCION_T_
#define _TFRACCION_T_

#include <iostream>

using std::string;
using std::to_string;

struct Fraccion
{
};

Fraccion fraccion(int n,int d)
{
    Fraccion ret;
    return ret;
}

string fraccionToString(Fraccion f)
{
   return "";
}

Fraccion fraccionSumar(Fraccion a,Fraccion b)
{
   Fraccion ret;
   return ret;
}

Fraccion fraccionSimplificar(Fraccion f)
{
   Fraccion ret;
   return ret;
}

bool fraccionEsEntera(Fraccion f)
{
   return false;
}

int fraccionGetNumerador(Fraccion f)
{
    return 0;
}

void fraccionSetNumerador(Fraccion& f,int n)
{
}

int fraccionGetDenominador(Fraccion f)
{
    return 0;
}

void fraccionSetDenominador(Fraccion& f,int d)
{
}

#endif