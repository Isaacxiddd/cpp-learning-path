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

struct Autor
{
	string nombre;
	Coll<string> frases;
};

struct Frases
{
	string texto;
};

struct Anio
{
	int anio;
	Coll<Autor> autores;
};




string rAutorToString(Autor x)
{
	char sep = 1;
	string sNombre=x.nombre;
	string sFrases=collToString<string>(x.frases);
	return sNombre+sep+sFrases;
}

Autor rAutorFromString(string s)
{
	char sep = 1;
	Autor x;
	string t0 = getTokenAt(s,sep,0);
	x.nombre=t0;
	string t1 = getTokenAt(s,sep,1);
	x.frases=collFromString<string>(t1);
	return x;
}

string rAutorToDebug(Autor x)
{
	stringstream sout;
	sout<< "[";
	sout << x.nombre;
	sout << ",";
	collReset<string>(x.frases);
	int n=collSize<string>(x.frases);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		string q = collGetAt<string>(x.frases,i,stringToString);
		sout << stringToString(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string rAutorToDebug(string mssg,Autor x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.nombre;
	sout << ",";
	collReset<string>(x.frases);
	int n=collSize<string>(x.frases);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		string q = collGetAt<string>(x.frases,i,stringToString);
		sout << stringToString(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Autor rAutor(string nombre,Coll<string> frases)
{
	Autor a;
	a.nombre = nombre;
	a.frases = frases;
	return a;
}

bool rAutorEquals(Autor a,Autor b)
{
	if(a.nombre!=b.nombre) return false;
	if(collToString<string>(a.frases)!=collToString<string>(b.frases)) return false;
	return true;
}

string rAnioToString(Anio x)
{
	char sep = 2;
	string sAnio=to_string(x.anio);
	string sAutores=collToString<Autor>(x.autores);
	return sAnio+sep+sAutores;
}

Anio rAnioFromString(string s)
{
	char sep = 2;
	Anio x;
	string t0 = getTokenAt(s,sep,0);
	x.anio=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.autores=collFromString<Autor>(t1);
	return x;
}

string rAnioToDebug(Anio x)
{
	stringstream sout;
	sout<< "[";
	sout << x.anio;
	sout << ",";
	collReset<Autor>(x.autores);
	int n=collSize<Autor>(x.autores);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Autor q = collGetAt<Autor>(x.autores,i,rAutorFromString);
		sout << rAutorToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string rAnioToDebug(string mssg,Anio x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.anio;
	sout << ",";
	collReset<Autor>(x.autores);
	int n=collSize<Autor>(x.autores);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Autor q = collGetAt<Autor>(x.autores,i,rAutorFromString);
		sout << rAutorToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Anio rAnio(int anio,Coll<Autor> autores)
{
	Anio b;
	b.anio = anio;
	b.autores = autores;
	return b;
}

bool rAnioEquals(Anio a,Anio b)
{
	if(a.anio!=b.anio) return false;
	if(collToString<Autor>(a.autores)!=collToString<Autor>(b.autores)) return false;
	return true;
}
#endif
