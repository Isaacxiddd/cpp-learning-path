#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"
#include "../../../../lib/funciones/Coll.hpp"
using namespace std;

struct Muestra
{
	int idMonitor;
	int hora;
	int min;
	char accion;
	int canal;
};

struct MinAMin
{
	int canal;
	int min;
	int cant;
};

string muestraToString(Muestra x)
{
	char sep = 1;
	string sIdMonitor=to_string(x.idMonitor);
	string sHora=to_string(x.hora);
	string sMin=to_string(x.min);
	string sAccion=string(1,x.accion);
	string sCanal=to_string(x.canal);
	return sIdMonitor+sep+sHora+sep+sMin+sep+sAccion+sep+sCanal;
}

Muestra muestraFromString(string s)
{
	char sep = 1;
	Muestra x;
	string t0 = getTokenAt(s,sep,0);
	x.idMonitor=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.hora=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.min=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.accion=(char)t3[0];
	string t4 = getTokenAt(s,sep,4);
	x.canal=stoi(t4);
	return x;
}

string muestraToDebug(Muestra x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idMonitor;
	sout << ",";
	sout << x.hora;
	sout << ",";
	sout << x.min;
	sout << ",";
	sout << x.accion;
	sout << ",";
	sout << x.canal;
	sout<< "]";
	return sout.str();
}

string muestraToDebug(string mssg,Muestra x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idMonitor;
	sout << ",";
	sout << x.hora;
	sout << ",";
	sout << x.min;
	sout << ",";
	sout << x.accion;
	sout << ",";
	sout << x.canal;
	sout<< "]";
	return sout.str();
}

Muestra muestra(int idMonitor,int hora,int min,char accion,int canal)
{
	Muestra b;
	b.idMonitor = idMonitor;
	b.hora = hora;
	b.min = min;
	b.accion = accion;
	b.canal = canal;
	return b;
}

bool muestraEquals(Muestra a,Muestra b)
{
	if(a.idMonitor!=b.idMonitor) return false;
	if(a.hora!=b.hora) return false;
	if(a.min!=b.min) return false;
	if(a.accion!=b.accion) return false;
	if(a.canal!=b.canal) return false;
	return true;
}

string minAMinToString(MinAMin x)
{
	char sep = 2;
	string sCanal=to_string(x.canal);
	string sMin=to_string(x.min);
	string sCant=to_string(x.cant);
	return sCanal+sep+sMin+sep+sCant;
}

MinAMin minAMinFromString(string s)
{
	char sep = 2;
	MinAMin x;
	string t0 = getTokenAt(s,sep,0);
	x.canal=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.min=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.cant=stoi(t2);
	return x;
}

string minAMinToDebug(MinAMin x)
{
	stringstream sout;
	sout<< "[";
	sout << x.canal;
	sout << ",";
	sout << x.min;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

string minAMinToDebug(string mssg,MinAMin x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.canal;
	sout << ",";
	sout << x.min;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

MinAMin minAMin(int canal,int min,int cant)
{
	MinAMin a;
	a.canal = canal;
	a.min = min;
	a.cant = cant;
	return a;
}

bool minAMinEquals(MinAMin a,MinAMin b)
{
	if(a.canal!=b.canal) return false;
	if(a.min!=b.min) return false;
	if(a.cant!=b.cant) return false;
	return true;
}

#endif
