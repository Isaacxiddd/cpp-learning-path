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

struct Movil
{
	int idMovil;
	char conductor[100];
	int zona;
	char celular[50];
};

struct Abonado
{
	int idAbo;
	char nombre[100];
	char celular[50];
	bool cuotasAlDia;
};

string movilToString(Movil x)
{
	char sep = 1;
	string sIdMovil=to_string(x.idMovil);
	string sConductor=x.conductor;
	string sZona=to_string(x.zona);
	string sCelular=x.celular;
	return sIdMovil+sep+sConductor+sep+sZona+sep+sCelular;
}

Movil movilFromString(string s)
{
	char sep = 1;
	Movil x;
	string t0 = getTokenAt(s,sep,0);
	x.idMovil=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.conductor,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.zona=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.celular,t3.c_str());
	return x;
}

string movilToDebug(Movil x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idMovil;
	sout << ",";
	sout << x.conductor;
	sout << ",";
	sout << x.zona;
	sout << ",";
	sout << x.celular;
	sout<< "]";
	return sout.str();
}

string movilToDebug(string mssg,Movil x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idMovil;
	sout << ",";
	sout << x.conductor;
	sout << ",";
	sout << x.zona;
	sout << ",";
	sout << x.celular;
	sout<< "]";
	return sout.str();
}

Movil movil(int idMovil,string conductor,int zona,string celular)
{
	Movil a;
	a.idMovil = idMovil;
	strcpy(a.conductor,conductor.c_str());
	a.zona = zona;
	strcpy(a.celular,celular.c_str());
	return a;
}

bool movilEquals(Movil a,Movil b)
{
	if(a.idMovil!=b.idMovil) return false;
	if(a.zona!=b.zona) return false;
	return true;
}

string abonadoToString(Abonado x)
{
	char sep = 2;
	string sIdAbo=to_string(x.idAbo);
	string sNombre=x.nombre;
	string sCelular=x.celular;
	string sCuotasAlDia=to_string(x.cuotasAlDia);
	return sIdAbo+sep+sNombre+sep+sCelular+sep+sCuotasAlDia;
}

Abonado abonadoFromString(string s)
{
	char sep = 2;
	Abonado x;
	string t0 = getTokenAt(s,sep,0);
	x.idAbo=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.celular,t2.c_str());
	string t3 = getTokenAt(s,sep,3);
	return x;
}

string abonadoToDebug(Abonado x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAbo;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.celular;
	sout << ",";
	sout << x.cuotasAlDia;
	sout<< "]";
	return sout.str();
}

string abonadoToDebug(string mssg,Abonado x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAbo;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.celular;
	sout << ",";
	sout << x.cuotasAlDia;
	sout<< "]";
	return sout.str();
}

Abonado abonado(int idAbo,string nombre,string celular,bool cuotasAlDia)
{
	Abonado a;
	a.idAbo = idAbo;
	strcpy(a.nombre,nombre.c_str());
	strcpy(a.celular,celular.c_str());
	a.cuotasAlDia = cuotasAlDia;
	return a;
}

bool abonadoEquals(Abonado a,Abonado b)
{
	if(a.idAbo!=b.idAbo) return false;
	if(a.cuotasAlDia!=b.cuotasAlDia) return false;
	return true;
}

#endif
