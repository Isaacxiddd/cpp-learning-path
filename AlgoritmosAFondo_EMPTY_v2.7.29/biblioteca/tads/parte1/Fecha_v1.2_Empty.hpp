#ifndef FECHA_H
#define FECHA_H

#include <string>

#include "../../funciones/millis_v1.1.hpp"
using namespace std;

// ============================
// Estructura
// ============================

struct Fecha

{

    int dia;

    int mes;

    int anio;

    int hora;

    int minuto;

    int segundo;

    int milli;

};

Fecha fecha(long long ts)

{

    Fecha f;

    f.dia = getDay(ts);

    f.mes = getMonth(ts);

    f.anio = getYear(ts);

    f.hora = getHour(ts);

    f.minuto = getMinute(ts);

    f.segundo = getSecond(ts);

    f.milli = getMillis(ts);

    return f;

}

Fecha fecha()

{

    return fecha(currTimeMillis());

}

Fecha fecha(int anio, int mes, int dia, int hora, int min)

{

    Fecha f;

    f.dia = dia;

    f.mes = mes;

    f.anio = anio;

    f.hora = hora;

    f.minuto = min;

    f.segundo = 0;

    f.milli = 0;

    return f;

}

Fecha fecha(int anio, int mes, int dia)

{

    return fecha(anio,mes,dia,0,0);

}

long long fechaInMillis(Fecha f)
{
    long long ret = attributesToMillis(f.anio, f.mes, f.dia, f.hora, f.minuto, f.segundo, f.milli);
    return ret;
}

Fecha fechaAddSegundos(Fecha f, int n)
{
    long long millis = fechaInMillis(f);
    millis = millis + (long long)n*1000;

    return fecha(millis);
}

Fecha fechaAddMinutos(Fecha f, int n)
{
 n = (long long)n*60;
 long long millis = fechaInMillis (f);
 millis= millis + (long long)n*1000;

 return fecha(millis);
}

Fecha fechaAddHoras(Fecha f, int n)
{
    n= (long long)n*60;
   n = (long long)n*60;
 long long millis = fechaInMillis (f);
 millis= millis + (long long)n*1000;

 return fecha (millis);
}

Fecha fechaAddDias(Fecha f, int n)
{
    n= (long long)n*24;
   n= (long long)n*60;
   n = (long long)n*60;
 long long millis = fechaInMillis (f);
 millis= millis + (long long)n*1000;

 return fecha (millis);
}

long long fechaDiffMillis(Fecha f1, Fecha f2)
{
    long long diff;
long long millis1= fechaInMillis(f1);
long long millis2= fechaInMillis(f2);

if (millis2>millis1) {
    diff= millis2-millis1;
}
else {
    diff= millis1-millis2;
}

    return diff;
}

int fechaDiffDias(Fecha f1, Fecha f2)
{
    long long diff;
long long millis1= fechaInMillis(f1);
long long millis2= fechaInMillis(f2);

if (millis2>millis1) {
    diff= millis2-millis1;
}
else {
    diff= millis1-millis2;
}

diff= diff/1000;
diff= diff/60;
diff= diff/60;
diff= diff/24;
    return diff;
}

int fechaCmp(Fecha f1, Fecha f2)
{
    long long millis1= fechaInMillis(f1);
    long long millis2= fechaInMillis (f2);
  if (millis1>millis2){
  return 1;
  }
else if (millis1<millis2) {
return -1;
}
else {
    return 0;
}
}
int fechaCmpDiaAnio(Fecha f1, Fecha f2){

    return 0;
}

string fechaToString(Fecha f)
{
    return millisToString(fechaInMillis(f));
}

bool fechaEsAnioBisiesto(Fecha f)
{
    return false;
}
    bool fechaEsHoy(Fecha f)
{
    Fecha hoy = fecha();
    return f.dia == hoy.dia && f.mes == hoy.mes && f.anio == hoy.anio;
}

// =================
// Setters y getters
// =================

int fechaGetAnio(Fecha f)
{
    return f.anio;
}

int fechaGetMes(Fecha f)
{

    return f.mes;
}

int fechaGetDia(Fecha f)
{
    return f.dia;
}

int fechaGetHora(Fecha f)
{
    return f.hora;
}

int fechaGetMinuto(Fecha f)
{
    return f.minuto;
}

int fechaGetSegundo(Fecha f)
{
    return f.minuto;
}

void fechaSetAnio(Fecha& f, int anio)
{

 f.anio = anio;

  return ;

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

#endif  // FECHA_H