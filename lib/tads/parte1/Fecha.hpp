#ifndef FECHA_H
#define FECHA_H

#include <string>

#include "../../funciones/millis.hpp"

using std::string;
using std::to_string;

// ============================
// Estructura
// ============================

struct Fecha
{
    // pone aqui los atributos que consideres
};

Fecha fecha(long long ts)
{
    Fecha x;
    return x;
}

Fecha fecha()
{
    Fecha x;
    return x;
}

Fecha fecha(int anio, int mes, int dia, int hora, int min)
{
    Fecha x;
    return x;
}

Fecha fecha(int anio, int mes, int dia)
{
    Fecha x;
    return x;
}

long long fechaInMillis(Fecha f)
{
    return 0;
}

Fecha fechaAddSegundos(Fecha f, int n)
{
    Fecha x;
    return x;
}

Fecha fechaAddMinutos(Fecha f, int n)
{
    Fecha x;
    return x;
}

Fecha fechaAddHoras(Fecha f, int n)
{
    Fecha x;
    return x;
}

Fecha fechaAddDias(Fecha f, int n)
{
    Fecha x;
    return x;
}

long long fechaDiffMillis(Fecha a, Fecha b)
{
    return 0;
}

int fechaDiffDias(Fecha a, Fecha b)
{
    return 0;
}

int fechaCmp(Fecha a, Fecha b)
{
    return 0;
}

int fechaCmpDiaMesAnio(Fecha a, Fecha b)
{
    return 0;
}

string fechaToString(Fecha f)
{
    return "";
}

bool fechaEsAnioBisiesto(int anio)
{
    return false;
}

bool fechaEsAnioBisiesto(Fecha f)
{
    return false;
}

int fechaDiasEnMes(int m, int a)
{
    return 0;
}

int fechaDiasEnMes(Fecha f)
{
    return 0;
}

int fechaDiaDelAnio(Fecha f)
{
    return 0;
}

bool fechaEsValida(Fecha f)
{
    return false;
}

bool fechaEsHoy(Fecha f)
{
    return false;
}

// =================
// Setters y getters
// =================

int fechaGetAnio(Fecha f)
{
    return 0;
}

int fechaGetMes(Fecha f)
{
    return 0;
}

int fechaGetDia(Fecha f)
{
    return 0;
}

int fechaGetHora(Fecha f)
{
    return 0;
}

int fechaGetMinuto(Fecha f)
{
    return 0;
}

int fechaGetSegundo(Fecha f)
{
    return 0;
}

int fechaGetMillis(Fecha& f, int millis)
{
    return 0;
}

void fechaSetAnio(Fecha& f, int anio)
{
}

void fechaSetMes(Fecha& f, int mes)
{
}

void fechaSetDia(Fecha& f, int dia)
{
}

void fechaSetHora(Fecha& f, int hora)
{
}

void fechaSetMinuto(Fecha& f, int minuto)
{
}

void fechaSetSegundo(Fecha& f, int segundo)
{
}

void fechaSetMillis(Fecha& f, int millis)
{
}

#endif  // FECHA_H