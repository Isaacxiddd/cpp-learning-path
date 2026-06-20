#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../../lib/funciones/strings.hpp"
#include "../../../lib/funciones/tokens.hpp"
#include "../../../lib/tads/parte1/Coll.hpp"
using namespace std;

// ─── Structs ─────────────────────────────────────────────────────────────────

struct Registro
{
	int id;
	char nombre[50];
};

struct RRegistro
{
	Registro r;
	int acum;
};

// ─── Registro ────────────────────────────────────────────────────────────────

string registroToString(Registro x)
{
	char sep = 1;
	return to_string(x.id) + sep + x.nombre;
}

Registro registroFromString(string s)
{
	char sep = 1;
	Registro x;
	x.id = stoi(getTokenAt(s, sep, 0));
	strcpy(x.nombre, getTokenAt(s, sep, 1).c_str());
	return x;
}

string registroToDebug(Registro x)
{
	stringstream sout;
	sout << "[" << x.id << "," << x.nombre << "]";
	return sout.str();
}

string registroToDebug(string mssg, Registro x)
{
	return mssg + ":" + registroToDebug(x);
}

Registro registro(int id, string nombre)
{
	Registro a;
	a.id = id;
	strcpy(a.nombre, nombre.c_str());
	return a;
}

bool registroEquals(Registro a, Registro b)
{
	if(a.id!=b.id) return false;
	return true;
}

// ─── RRegistro ───────────────────────────────────────────────────────────────

string rRegistroToString(RRegistro x)
{
	char sep = 2;
	return registroToString(x.r) + sep + to_string(x.acum);
}

RRegistro rRegistroFromString(string s)
{
	char sep = 2;
	RRegistro x;
	x.r    = registroFromString(getTokenAt(s, sep, 0));
	x.acum = stoi(getTokenAt(s, sep, 1));
	return x;
}

string rRegistroToDebug(RRegistro x)
{
	stringstream sout;
	sout << "[" << registroToDebug(x.r) << "," << x.acum << "]";
	return sout.str();
}

string rRegistroToDebug(string mssg, RRegistro x)
{
	return mssg + ":" + rRegistroToDebug(x);
}

RRegistro rRegistro(Registro r, int acum)
{
	RRegistro a;
	a.r    = r;
	a.acum = acum;
	return a;
}

bool rRegistroEquals(RRegistro a, RRegistro b)
{
	if(!registroEquals(a.r,b.r)) return false;
	if(a.acum!=b.acum) return false;
	return true;
}

#endif
