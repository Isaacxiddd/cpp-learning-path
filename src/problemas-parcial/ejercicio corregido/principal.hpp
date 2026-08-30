#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "../../../lib/funciones/Coll.hpp"
using namespace std;

// ============================================================
// ESTRUCTURA RAutor: guarda NOMBRE del autor + sus FRASES
// ============================================================
struct RAutor
{
	string nombre;      // ej: "Maradona D."
	Coll<string> frases; // coleccion de strings (las frases de ese autor)
};

// ============================================================
// ESTRUCTURA RAnio: guarda un ANIO + sus AUTORES
// ============================================================
struct RAnio
{
	int anio;            // ej: 2003
	Coll<RAutor> autores; // coleccion de RAutor (los autores de ese anio)
};

// ============================================================
// rAutorToString: convierte RAutor a string para guardar en la Coll
// Usa separador char(1) para separar nombre de frases
// ============================================================
string rAutorToString(RAutor x) 
{
	char sep = 1;
	string sNombre=x.nombre;
	string sFrases=collToString<string>(x.frases); // convierte la Coll<string> a string
	return sNombre+sep+sFrases; // ej: "Maradona D." + char(1) + "frase1#frase2#..."
}

// ============================================================
// rAutorFromString: revierte rAutorToString, reconstruye RAutor desde string
// ============================================================
RAutor rAutorFromString(string s)
{
	char sep = 1;
	RAutor x;
	string t0 = getTokenAt(s,sep,0); // token 0 = nombre
	x.nombre=t0;
	string t1 = getTokenAt(s,sep,1); // token 1 = las frases serializadas
	x.frases=collFromString<string>(t1); // convierte ese string de vuelta a Coll<string>
	return x;
}

// ============================================================
// rAutorToDebug: muestra RAutor bonito para consola (solo debugging)
// ============================================================
string rAutorToDebug(RAutor x)
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

// ============================================================
// rAutorToDebug con mensaje: igual pero con prefijo
// ============================================================
string rAutorToDebug(string mssg,RAutor x)
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

// ============================================================
// rAutor: constructor de RAutor (devuelve struct con datos asignados)
// ============================================================
RAutor rAutor(string nombre,Coll<string> frases)
{
	RAutor a;
	a.nombre = nombre;
	a.frases = frases;
	return a;
}

// ============================================================
// rAutorEquals: compara dos RAutor campo por campo
// ============================================================
bool rAutorEquals(RAutor a,RAutor b)
{
	if(a.nombre!=b.nombre) return false;
	if(collToString<string>(a.frases)!=collToString<string>(b.frases)) return false;
	return true;
}

// ============================================================
// rAnioToString: serializa RAnio a string con separador char(2)
// ============================================================
string rAnioToString(RAnio x)
{
	char sep = 2;
	string sAnio=to_string(x.anio);
	string sAutores=collToString<RAutor>(x.autores); // convierte Coll<RAutor> a string
	return sAnio+sep+sAutores; // ej: "2003" + char(2) + "autor1$autor2$..."
}

// ============================================================
// rAnioFromString: revierte rAnioToString
// ============================================================
RAnio rAnioFromString(string s)
{
	char sep = 2;
	RAnio x;
	string t0 = getTokenAt(s,sep,0); // token 0 = anio
	x.anio=stoi(t0);
	string t1 = getTokenAt(s,sep,1); // token 1 = autores serializados
	x.autores=collFromString<RAutor>(t1);
	return x;
}

// ============================================================
// rAnioToDebug: muestra RAnio bonito para debug
// ============================================================
string rAnioToDebug(RAnio x)
{
	stringstream sout;
	sout<< "[";
	sout << x.anio;
	sout << ",";
	collReset<RAutor>(x.autores);
	int n=collSize<RAutor>(x.autores);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RAutor q = collGetAt<RAutor>(x.autores,i,rAutorFromString);
		sout << rAutorToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

// ============================================================
// rAnioToDebug con mensaje
// ============================================================
string rAnioToDebug(string mssg,RAnio x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.anio;
	sout << ",";
	collReset<RAutor>(x.autores);
	int n=collSize<RAutor>(x.autores);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		RAutor q = collGetAt<RAutor>(x.autores,i,rAutorFromString);
		sout << rAutorToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

// ============================================================
// rAnio: constructor de RAnio
// ============================================================
RAnio rAnio(int anio,Coll<RAutor> autores)
{
	RAnio b;
	b.anio = anio;
	b.autores = autores;
	return b;
}

// ============================================================
// rAnioEquals: compara dos RAnio
// ============================================================
bool rAnioEquals(RAnio a,RAnio b)
{
	if(a.anio!=b.anio) return false;
	if(collToString<RAutor>(a.autores)!=collToString<RAutor>(b.autores)) return false;
	return true;
}

#endif
