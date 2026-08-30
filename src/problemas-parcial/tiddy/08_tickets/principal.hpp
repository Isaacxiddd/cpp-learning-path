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

struct Producto
{
	int idProd;
	char descr[20];
	double precio;
	int idRub;
};

struct Rubro
{
	int idRub;
	char descr[20];
	double promo;
};

string productoToString(Producto x)
{
	char sep = 1;
	string sIdProd=to_string(x.idProd);
	string sDescr=x.descr;
	string sPrecio=to_string(x.precio);
	string sIdRub=to_string(x.idRub);
	return sIdProd+sep+sDescr+sep+sPrecio+sep+sIdRub;
}

Producto productoFromString(string s)
{
	char sep = 1;
	Producto x;
	string t0 = getTokenAt(s,sep,0);
	x.idProd=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.precio=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.idRub=stoi(t3);
	return x;
}

string productoToDebug(Producto x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idProd;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

string productoToDebug(string mssg,Producto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idProd;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

Producto producto(int idProd,string descr,double precio,int idRub)
{
	Producto a;
	a.idProd = idProd;
	strcpy(a.descr,descr.c_str());
	a.precio = precio;
	a.idRub = idRub;
	return a;
}

bool productoEquals(Producto a,Producto b)
{
	if(a.idProd!=b.idProd) return false;
	if(a.precio!=b.precio) return false;
	if(a.idRub!=b.idRub) return false;
	return true;
}

string rubroToString(Rubro x)
{
	char sep = 2;
	string sIdRub=to_string(x.idRub);
	string sDescr=x.descr;
	string sPromo=to_string(x.promo);
	return sIdRub+sep+sDescr+sep+sPromo;
}

Rubro rubroFromString(string s)
{
	char sep = 2;
	Rubro x;
	string t0 = getTokenAt(s,sep,0);
	x.idRub=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.promo=stod(t2);
	return x;
}

string rubroToDebug(Rubro x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idRub;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.promo;
	sout<< "]";
	return sout.str();
}

string rubroToDebug(string mssg,Rubro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idRub;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.promo;
	sout<< "]";
	return sout.str();
}

Rubro rubro(int idRub,string descr,double promo)
{
	Rubro a;
	a.idRub = idRub;
	strcpy(a.descr,descr.c_str());
	a.promo = promo;
	return a;
}

bool rubroEquals(Rubro a,Rubro b)
{
	if(a.idRub!=b.idRub) return false;
	if(a.promo!=b.promo) return false;
	return true;
}

#endif
