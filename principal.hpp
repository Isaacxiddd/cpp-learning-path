#ifndef _MAINHPP
#define _MAINHPP

#include <iostream>
#include <string>

// Funciones de la biblioteca
#include "lib/funciones/files.hpp"
#include "lib/funciones/strings.hpp"
#include "lib/funciones/tokens.hpp"
#include "lib/funciones/arrays.hpp"
#include "lib/funciones/lists.hpp"
#include "lib/funciones/millis.hpp"
#include "lib/funciones/Coll.hpp"

// TADs - Intro
#include "lib/tads/intro/Fraccion.hpp"

// TADs - Parte 1
#include "lib/tads/parte1/Coll.hpp"
#include "lib/tads/parte1/Fecha.hpp"
#include "lib/tads/parte1/Timer.hpp"
#include "lib/tads/parte1/MultidimColl.hpp"

// TADs - Parte 2
#include "lib/tads/parte2/Array.hpp"
#include "lib/tads/parte2/List.hpp"
#include "lib/tads/parte2/Map.hpp"
#include "lib/tads/parte2/Queue.hpp"
#include "lib/tads/parte2/Stack.hpp"

using namespace std;
struct Autor
{
	string nom;
	Coll<string> frases;
};

struct Anio
{
	int anio;
	Coll<Autor> a;
};

string autorToString(Autor x)
{
	char sep = 1;
	string sNom=x.nom;
	string sFrases=collToString<string>(x.frases);
	return sNom+sep+sFrases;
}

Autor autorFromString(string s)
{
	char sep = 1;
	Autor x;
	string t0 = getTokenAt(s,sep,0);
	x.nom=t0;
	string t1 = getTokenAt(s,sep,1);
	x.frases=collFromString<string>(t1);
	return x;
}

string autorToDebug(Autor x)
{
	stringstream sout;
	sout<< "[";
	sout << x.nom;
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

string autorToDebug(string mssg,Autor x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.nom;
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

Autor autor(string nom,Coll<string> frases)
{
	Autor a;
	a.nom = nom;
	a.frases = frases;
	return a;
}

bool autorEquals(Autor a,Autor b)
{
	if(a.nom!=b.nom) return false;
	if(collToString<string>(a.frases)!=collToString<string>(b.frases)) return false;
	return true;
}

string anioToString(Anio x)
{
	char sep = 2;
	string sAnio=to_string(x.anio);
	string sA=collToString<Autor>(x.a);
	return sAnio+sep+sA;
}

Anio anioFromString(string s)
{
	char sep = 2;
	Anio x;
	string t0 = getTokenAt(s,sep,0);
	x.anio=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.a=collFromString<Autor>(t1);
	return x;
}

string anioToDebug(Anio x)
{
	stringstream sout;
	sout<< "[";
	sout << x.anio;
	sout << ",";
	collReset<Autor>(x.a);
	int n=collSize<Autor>(x.a);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Autor q = collGetAt<Autor>(x.a,i,autorFromString);
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
	sout << x.anio;
	sout << ",";
	collReset<Autor>(x.a);
	int n=collSize<Autor>(x.a);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		Autor q = collGetAt<Autor>(x.a,i,autorFromString);
		sout << autorToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

Anio anio(int anio,Coll<Autor> a)
{
	Anio b;
	b.anio = anio;
	b.a = a;
	return b;
}

bool anioEquals(Anio a,Anio b)
{
	if(a.anio!=b.anio) return false;
	if(collToString<Autor>(a.a)!=collToString<Autor>(b.a)) return false;
	return true;
}




#endif