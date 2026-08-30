#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "../../../lib/tads/parte1/Coll.hpp"
using namespace std;

struct Empresa
{
	int idEmpresa;
	char razonSocial[100];
	int cantTrabAsegurados;
};

struct REmpresa
{
	Empresa e;
	int cont;
};

struct RTrabajador
{
	int legajo;
	int cont;
};

struct Accidente
{
	int idEmpresa;
	int legajo;
	int fecha;
	int cantDiasLicencia;
};

string empresaToString(Empresa x)
{
	char sep = 1;
	string sIdEmpresa=to_string(x.idEmpresa);
	string sRazonSocial=x.razonSocial;
	string sCantTrabAsegurados=to_string(x.cantTrabAsegurados);
	return sIdEmpresa+sep+sRazonSocial+sep+sCantTrabAsegurados;
}

Empresa empresaFromString(string s)
{
	char sep = 1;
	Empresa x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmpresa=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.razonSocial,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.cantTrabAsegurados=stoi(t2);
	return x;
}

string empresaToDebug(Empresa x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEmpresa;
	sout << ",";
	sout << x.razonSocial;
	sout << ",";
	sout << x.cantTrabAsegurados;
	sout<< "]";
	return sout.str();
}

string empresaToDebug(string mssg,Empresa x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEmpresa;
	sout << ",";
	sout << x.razonSocial;
	sout << ",";
	sout << x.cantTrabAsegurados;
	sout<< "]";
	return sout.str();
}

Empresa empresa(int idEmpresa,string razonSocial,int cantTrabAsegurados)
{
	Empresa a;
	a.idEmpresa = idEmpresa;
	strcpy(a.razonSocial,razonSocial.c_str());
	a.cantTrabAsegurados = cantTrabAsegurados;
	return a;
}

string rEmpresaToString(REmpresa x)
{
	char sep = 2;
	string sE=empresaToString(x.e);
	string sCont=to_string(x.cont);
	return sE+sep+sCont;
}

REmpresa rEmpresaFromString(string s)
{
	char sep = 2;
	REmpresa x;
	string t0 = getTokenAt(s,sep,0);
	x.e=empresaFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cont=stoi(t1);
	return x;
}

string rEmpresaToDebug(REmpresa x)
{
	stringstream sout;
	sout<< "[";
	sout << empresaToDebug(x.e);
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

string rEmpresaToDebug(string mssg,REmpresa x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << empresaToDebug(x.e);
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

REmpresa rEmpresa(Empresa e,int cont)
{
	REmpresa a;
	a.e = e;
	a.cont = cont;
	return a;
}

string rTrabajadorToString(RTrabajador x)
{
	char sep = 3;
	string sLegajo=to_string(x.legajo);
	string sCont=to_string(x.cont);
	return sLegajo+sep+sCont;
}

RTrabajador rTrabajadorFromString(string s)
{
	char sep = 3;
	RTrabajador x;
	string t0 = getTokenAt(s,sep,0);
	x.legajo=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cont=stoi(t1);
	return x;
}

string rTrabajadorToDebug(RTrabajador x)
{
	stringstream sout;
	sout<< "[";
	sout << x.legajo;
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

string rTrabajadorToDebug(string mssg,RTrabajador x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.legajo;
	sout << ",";
	sout << x.cont;
	sout<< "]";
	return sout.str();
}

RTrabajador rTrabajador(int legajo,int cont)
{
	RTrabajador a;
	a.legajo = legajo;
	a.cont = cont;
	return a;
}

string accidenteToString(Accidente x)
{
	char sep = 4;
	string sIdEmpresa=to_string(x.idEmpresa);
	string sLegajo=to_string(x.legajo);
	string sFecha=to_string(x.fecha);
	string sCantDiasLicencia=to_string(x.cantDiasLicencia);
	return sIdEmpresa+sep+sLegajo+sep+sFecha+sep+sCantDiasLicencia;
}

Accidente accidenteFromString(string s)
{
	char sep = 4;
	Accidente x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmpresa=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.legajo=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.cantDiasLicencia=stoi(t3);
	return x;
}

string accidenteToDebug(Accidente x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEmpresa;
	sout << ",";
	sout << x.legajo;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.cantDiasLicencia;
	sout<< "]";
	return sout.str();
}

string accidenteToDebug(string mssg,Accidente x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEmpresa;
	sout << ",";
	sout << x.legajo;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.cantDiasLicencia;
	sout<< "]";
	return sout.str();
}

Accidente accidente(int idEmpresa,int legajo,int fecha,int cantDiasLicencia)
{
	Accidente a;
	a.idEmpresa = idEmpresa;
	a.legajo = legajo;
	a.fecha = fecha;
	a.cantDiasLicencia = cantDiasLicencia;
	return a;
}

#endif
