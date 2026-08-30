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

struct Acta
{
	int idInspector;
	char pat[10];
	int fecha;
	int hora;
	int idInfraccion;
};

struct Infraccion
{
	int idInfraccion;
	char descr[100];
	double penalidad;
	int diasPromo;
	double dtoPromo;
};

string actaToString(Acta x)
{
	char sep = 1;
	string sIdInspector=to_string(x.idInspector);
	string sPat=x.pat;
	string sFecha=to_string(x.fecha);
	string sHora=to_string(x.hora);
	string sIdInfraccion=to_string(x.idInfraccion);
	return sIdInspector+sep+sPat+sep+sFecha+sep+sHora+sep+sIdInfraccion;
}

Acta actaFromString(string s)
{
	char sep = 1;
	Acta x;
	string t0 = getTokenAt(s,sep,0);
	x.idInspector=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.pat,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.hora=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.idInfraccion=stoi(t4);
	return x;
}

string actaToDebug(Acta x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idInspector;
	sout << ",";
	sout << x.pat;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.hora;
	sout << ",";
	sout << x.idInfraccion;
	sout<< "]";
	return sout.str();
}

string actaToDebug(string mssg,Acta x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idInspector;
	sout << ",";
	sout << x.pat;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.hora;
	sout << ",";
	sout << x.idInfraccion;
	sout<< "]";
	return sout.str();
}

Acta acta(int idInspector,string pat,int fecha,int hora,int idInfraccion)
{
	Acta a;
	a.idInspector = idInspector;
	strcpy(a.pat,pat.c_str());
	a.fecha = fecha;
	a.hora = hora;
	a.idInfraccion = idInfraccion;
	return a;
}

bool actaEquals(Acta a,Acta b)
{
	if(a.idInspector!=b.idInspector) return false;
	if(a.fecha!=b.fecha) return false;
	if(a.hora!=b.hora) return false;
	if(a.idInfraccion!=b.idInfraccion) return false;
	return true;
}

string infraccionToString(Infraccion x)
{
	char sep = 2;
	string sIdInfraccion=to_string(x.idInfraccion);
	string sDescr=x.descr;
	string sPenalidad=to_string(x.penalidad);
	string sDiasPromo=to_string(x.diasPromo);
	string sDtoPromo=to_string(x.dtoPromo);
	return sIdInfraccion+sep+sDescr+sep+sPenalidad+sep+sDiasPromo+sep+sDtoPromo;
}

Infraccion infraccionFromString(string s)
{
	char sep = 2;
	Infraccion x;
	string t0 = getTokenAt(s,sep,0);
	x.idInfraccion=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.penalidad=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.diasPromo=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.dtoPromo=stod(t4);
	return x;
}

string infraccionToDebug(Infraccion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idInfraccion;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.penalidad;
	sout << ",";
	sout << x.diasPromo;
	sout << ",";
	sout << x.dtoPromo;
	sout<< "]";
	return sout.str();
}

string infraccionToDebug(string mssg,Infraccion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idInfraccion;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.penalidad;
	sout << ",";
	sout << x.diasPromo;
	sout << ",";
	sout << x.dtoPromo;
	sout<< "]";
	return sout.str();
}

Infraccion infraccion(int idInfraccion,string descr,double penalidad,int diasPromo,double dtoPromo)
{
	Infraccion a;
	a.idInfraccion = idInfraccion;
	strcpy(a.descr,descr.c_str());
	a.penalidad = penalidad;
	a.diasPromo = diasPromo;
	a.dtoPromo = dtoPromo;
	return a;
}

bool infraccionEquals(Infraccion a,Infraccion b)
{
	if(a.idInfraccion!=b.idInfraccion) return false;
	if(a.penalidad!=b.penalidad) return false;
	if(a.diasPromo!=b.diasPromo) return false;
	if(a.dtoPromo!=b.dtoPromo) return false;
	return true;
}

#endif
