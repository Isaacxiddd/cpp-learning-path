#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../../lib/funciones/millis.hpp"
#include "../../../lib/funciones/files.hpp"
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "../../../lib/tads/parte1/Fecha.hpp"
#include "../../../lib/tads/parte1/Timer.hpp"
#include "../../../lib/funciones/Coll.hpp"
#include "../../../lib/tads/parte2/Array.hpp"
#include "../../../lib/tads/parte2/List.hpp"
#include "../../../lib/tads/parte2/Map.hpp"
#include "../../../lib/tads/parte2/Queue.hpp"
#include "../../../lib/tads/parte2/Stack.hpp"
using namespace std;

struct Autor
{
	string nombre;
	Coll<string> c;
};

struct Anio
{
	int a;
	Coll<Autor> c;
};

string autorToString(Autor x)
{
	char sep = 1;
	string sNombre=x.nombre;
	string sC=collToString<string>(x.c);
	return sNombre+sep+sC;
}

Autor autorFromString(string s)
{
	char sep = 1;
	Autor x;
	string t0 = getTokenAt(s,sep,0);
	x.nombre=t0;
	string t1 = getTokenAt(s,sep,1);
	x.c=collFromString<string>(t1);
	return x;
}

string autorToDebug(Autor x)
{
	stringstream sout;
	sout<< "[";
	sout << x.nombre;
	sout << ",";
	collReset<string>(x.c);
	int n=collSize<string>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		string q = collGetAt<string>(x.c,i,stringToString);
		sout << stringToString(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string autorToDebug(string mssg,Autor x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.nombre;
	sout << ",";
	collReset<string>(x.c);
	int n=collSize<string>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		string q = collGetAt<string>(x.c,i,stringToString);
		sout << stringToString(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Autor autor(string nombre,Coll<string> c)
{
	Autor a;
	a.nombre = nombre;
	a.c = c;
	return a;
}

bool autorEquals(Autor a,Autor b)
{
	if(a.nombre!=b.nombre) return false;
	if(collToString<string>(a.c)!=collToString<string>(b.c)) return false;
	return true;
}

string anioToString(Anio x)
{
	char sep = 2;
	string sA=to_string(x.a);
	string sC=collToString<Autor>(x.c);
	return sA+sep+sC;
}

Anio anioFromString(string s)
{
	char sep = 2;
	Anio x;
	string t0 = getTokenAt(s,sep,0);
	x.a=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.c=collFromString<Autor>(t1);
	return x;
}

string anioToDebug(Anio x)
{
	stringstream sout;
	sout<< "[";
	sout << x.a;
	sout << ",";
	collReset<Autor>(x.c);
	int n=collSize<Autor>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Autor q = collGetAt<Autor>(x.c,i,autorFromString);
		sout << autorToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string anioToDebug(string mssg,Anio x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.a;
	sout << ",";
	collReset<Autor>(x.c);
	int n=collSize<Autor>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Autor q = collGetAt<Autor>(x.c,i,autorFromString);
		sout << autorToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Anio anio(int a,Coll<Autor> c)
{
	Anio b;
	b.a = a;
	b.c = c;
	return b;
}

bool anioEquals(Anio a,Anio b)
{
	if(a.a!=b.a) return false;
	if(collToString<Autor>(a.c)!=collToString<Autor>(b.c)) return false;
	return true;
}

#endif
