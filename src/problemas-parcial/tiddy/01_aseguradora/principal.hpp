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

struct Fecha
{
	int anio;
	int mes;
	int dia;
	int hora;
	int minuto;
	int segundo;
};

struct Empresa
{
	int idEmpresa;
	char razonSocial[100];
	int cantTrabAsegurados;
};

struct Accidente
{
	int idEmpresa;
	int legajo;
	Fecha fecha;
	int cantDiasLicencia;
};

string fechaToString(Fecha x)
{
	char sep = 1;
	string sAnio=to_string(x.anio);
	string sMes=to_string(x.mes);
	string sDia=to_string(x.dia);
	string sHora=to_string(x.hora);
	string sMinuto=to_string(x.minuto);
	string sSegundo=to_string(x.segundo);
	return sAnio+sep+sMes+sep+sDia+sep+sHora+sep+sMinuto+sep+sSegundo;
}

Fecha fechaFromString(string s)
{
	char sep = 1;
	Fecha x;
	string t0 = getTokenAt(s,sep,0);
	x.anio=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.mes=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.dia=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.hora=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.minuto=stoi(t4);
	string t5 = getTokenAt(s,sep,5);
	x.segundo=stoi(t5);
	return x;
}

string fechaToDebug(Fecha x)
{
	stringstream sout;
	sout<< "[";
	sout << x.anio;
	sout << ",";
	sout << x.mes;
	sout << ",";
	sout << x.dia;
	sout << ",";
	sout << x.hora;
	sout << ",";
	sout << x.minuto;
	sout << ",";
	sout << x.segundo;
	sout<< "]";
	return sout.str();
}

string fechaToDebug(string mssg,Fecha x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.anio;
	sout << ",";
	sout << x.mes;
	sout << ",";
	sout << x.dia;
	sout << ",";
	sout << x.hora;
	sout << ",";
	sout << x.minuto;
	sout << ",";
	sout << x.segundo;
	sout<< "]";
	return sout.str();
}

Fecha fecha(int anio,int mes,int dia,int hora,int minuto,int segundo)
{
	Fecha b;
	b.anio = anio;
	b.mes = mes;
	b.dia = dia;
	b.hora = hora;
	b.minuto = minuto;
	b.segundo = segundo;
	return b;
}

bool fechaEquals(Fecha a,Fecha b)
{
	if(a.anio!=b.anio) return false;
	if(a.mes!=b.mes) return false;
	if(a.dia!=b.dia) return false;
	if(a.hora!=b.hora) return false;
	if(a.minuto!=b.minuto) return false;
	if(a.segundo!=b.segundo) return false;
	return true;
}

string empresaToString(Empresa x)
{
	char sep = 2;
	string sIdEmpresa=to_string(x.idEmpresa);
	string sRazonSocial=x.razonSocial;
	string sCantTrabAsegurados=to_string(x.cantTrabAsegurados);
	return sIdEmpresa+sep+sRazonSocial+sep+sCantTrabAsegurados;
}

Empresa empresaFromString(string s)
{
	char sep = 2;
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

bool empresaEquals(Empresa a,Empresa b)
{
	if(a.idEmpresa!=b.idEmpresa) return false;
	if(a.cantTrabAsegurados!=b.cantTrabAsegurados) return false;
	return true;
}

string accidenteToString(Accidente x)
{
	char sep = 3;
	string sIdEmpresa=to_string(x.idEmpresa);
	string sLegajo=to_string(x.legajo);
	string sFecha=fechaToString(x.fecha);
	string sCantDiasLicencia=to_string(x.cantDiasLicencia);
	return sIdEmpresa+sep+sLegajo+sep+sFecha+sep+sCantDiasLicencia;
}

Accidente accidenteFromString(string s)
{
	char sep = 3;
	Accidente x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmpresa=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.legajo=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=fechaFromString(t2);
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
	sout << fechaToDebug(x.fecha);
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
	sout << fechaToDebug(x.fecha);
	sout << ",";
	sout << x.cantDiasLicencia;
	sout<< "]";
	return sout.str();
}

Accidente accidente(int idEmpresa,int legajo,Fecha fecha,int cantDiasLicencia)
{
	Accidente a;
	a.idEmpresa = idEmpresa;
	a.legajo = legajo;
	a.fecha = fecha;
	a.cantDiasLicencia = cantDiasLicencia;
	return a;
}

bool accidenteEquals(Accidente a,Accidente b)
{
	if(a.idEmpresa!=b.idEmpresa) return false;
	if(a.legajo!=b.legajo) return false;
	if(!fechaEquals(a.fecha,b.fecha)) return false;
	if(a.cantDiasLicencia!=b.cantDiasLicencia) return false;
	return true;
}

#endif
