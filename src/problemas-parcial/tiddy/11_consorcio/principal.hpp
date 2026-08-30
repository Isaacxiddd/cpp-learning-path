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

struct Gasto
{
	int idCons;
	int fecha;
	double importe;
	char categoria[20];
};

struct Consorcio
{
	int idCons;
	char direccion[50];
	int cantPisos;
	int dtosPorPiso;
};

struct Distribucion
{
	int idCons;
	int tipoDto;
	double mtsPorc;
};

string gastoToString(Gasto x)
{
	char sep = 1;
	string sIdCons=to_string(x.idCons);
	string sFecha=to_string(x.fecha);
	string sImporte=to_string(x.importe);
	string sCategoria=x.categoria;
	return sIdCons+sep+sFecha+sep+sImporte+sep+sCategoria;
}

Gasto gastoFromString(string s)
{
	char sep = 1;
	Gasto x;
	string t0 = getTokenAt(s,sep,0);
	x.idCons=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.fecha=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.importe=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.categoria,t3.c_str());
	return x;
}

string gastoToDebug(Gasto x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCons;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.importe;
	sout << ",";
	sout << x.categoria;
	sout<< "]";
	return sout.str();
}

string gastoToDebug(string mssg,Gasto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCons;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.importe;
	sout << ",";
	sout << x.categoria;
	sout<< "]";
	return sout.str();
}

Gasto gasto(int idCons,int fecha,double importe,string categoria)
{
	Gasto a;
	a.idCons = idCons;
	a.fecha = fecha;
	a.importe = importe;
	strcpy(a.categoria,categoria.c_str());
	return a;
}

bool gastoEquals(Gasto a,Gasto b)
{
	if(a.idCons!=b.idCons) return false;
	if(a.fecha!=b.fecha) return false;
	if(a.importe!=b.importe) return false;
	return true;
}

string consorcioToString(Consorcio x)
{
	char sep = 2;
	string sIdCons=to_string(x.idCons);
	string sDireccion=x.direccion;
	string sCantPisos=to_string(x.cantPisos);
	string sDtosPorPiso=to_string(x.dtosPorPiso);
	return sIdCons+sep+sDireccion+sep+sCantPisos+sep+sDtosPorPiso;
}

Consorcio consorcioFromString(string s)
{
	char sep = 2;
	Consorcio x;
	string t0 = getTokenAt(s,sep,0);
	x.idCons=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.direccion,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.cantPisos=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.dtosPorPiso=stoi(t3);
	return x;
}

string consorcioToDebug(Consorcio x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCons;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.cantPisos;
	sout << ",";
	sout << x.dtosPorPiso;
	sout<< "]";
	return sout.str();
}

string consorcioToDebug(string mssg,Consorcio x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCons;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.cantPisos;
	sout << ",";
	sout << x.dtosPorPiso;
	sout<< "]";
	return sout.str();
}

Consorcio consorcio(int idCons,string direccion,int cantPisos,int dtosPorPiso)
{
	Consorcio a;
	a.idCons = idCons;
	strcpy(a.direccion,direccion.c_str());
	a.cantPisos = cantPisos;
	a.dtosPorPiso = dtosPorPiso;
	return a;
}

bool consorcioEquals(Consorcio a,Consorcio b)
{
	if(a.idCons!=b.idCons) return false;
	if(a.cantPisos!=b.cantPisos) return false;
	if(a.dtosPorPiso!=b.dtosPorPiso) return false;
	return true;
}

string distribucionToString(Distribucion x)
{
	char sep = 3;
	string sIdCons=to_string(x.idCons);
	string sTipoDto=to_string(x.tipoDto);
	string sMtsPorc=to_string(x.mtsPorc);
	return sIdCons+sep+sTipoDto+sep+sMtsPorc;
}

Distribucion distribucionFromString(string s)
{
	char sep = 3;
	Distribucion x;
	string t0 = getTokenAt(s,sep,0);
	x.idCons=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.tipoDto=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.mtsPorc=stod(t2);
	return x;
}

string distribucionToDebug(Distribucion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCons;
	sout << ",";
	sout << x.tipoDto;
	sout << ",";
	sout << x.mtsPorc;
	sout<< "]";
	return sout.str();
}

string distribucionToDebug(string mssg,Distribucion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCons;
	sout << ",";
	sout << x.tipoDto;
	sout << ",";
	sout << x.mtsPorc;
	sout<< "]";
	return sout.str();
}

Distribucion distribucion(int idCons,int tipoDto,double mtsPorc)
{
	Distribucion a;
	a.idCons = idCons;
	a.tipoDto = tipoDto;
	a.mtsPorc = mtsPorc;
	return a;
}

bool distribucionEquals(Distribucion a,Distribucion b)
{
	if(a.idCons!=b.idCons) return false;
	if(a.tipoDto!=b.tipoDto) return false;
	if(a.mtsPorc!=b.mtsPorc) return false;
	return true;
}

#endif
