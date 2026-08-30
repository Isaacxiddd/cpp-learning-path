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

struct Obra
{
	int idObra;
	char titulo[100];
	int fEstreno;
	int idTeatro;
};

struct Teatro
{
	int idTeatro;
	char direccion[50];
	int capacidad;
	int sectores;
};

struct Funcion
{
	int idFuncion;
	int diaSem;
	int hora;
};

struct Reserva
{
	int idCliente;
	int idObra;
	int idFuncion;
	int sector;
	int cant;
};

string obraToString(Obra x)
{
	char sep = 1;
	string sIdObra=to_string(x.idObra);
	string sTitulo=x.titulo;
	string sFEstreno=to_string(x.fEstreno);
	string sIdTeatro=to_string(x.idTeatro);
	return sIdObra+sep+sTitulo+sep+sFEstreno+sep+sIdTeatro;
}

Obra obraFromString(string s)
{
	char sep = 1;
	Obra x;
	string t0 = getTokenAt(s,sep,0);
	x.idObra=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.titulo,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.fEstreno=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.idTeatro=stoi(t3);
	return x;
}

string obraToDebug(Obra x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idObra;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.fEstreno;
	sout << ",";
	sout << x.idTeatro;
	sout<< "]";
	return sout.str();
}

string obraToDebug(string mssg,Obra x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idObra;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.fEstreno;
	sout << ",";
	sout << x.idTeatro;
	sout<< "]";
	return sout.str();
}

Obra obra(int idObra,string titulo,int fEstreno,int idTeatro)
{
	Obra a;
	a.idObra = idObra;
	strcpy(a.titulo,titulo.c_str());
	a.fEstreno = fEstreno;
	a.idTeatro = idTeatro;
	return a;
}

bool obraEquals(Obra a,Obra b)
{
	if(a.idObra!=b.idObra) return false;
	if(a.fEstreno!=b.fEstreno) return false;
	if(a.idTeatro!=b.idTeatro) return false;
	return true;
}

string teatroToString(Teatro x)
{
	char sep = 2;
	string sIdTeatro=to_string(x.idTeatro);
	string sDireccion=x.direccion;
	string sCapacidad=to_string(x.capacidad);
	string sSectores=to_string(x.sectores);
	return sIdTeatro+sep+sDireccion+sep+sCapacidad+sep+sSectores;
}

Teatro teatroFromString(string s)
{
	char sep = 2;
	Teatro x;
	string t0 = getTokenAt(s,sep,0);
	x.idTeatro=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.direccion,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.capacidad=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.sectores=stoi(t3);
	return x;
}

string teatroToDebug(Teatro x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idTeatro;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.capacidad;
	sout << ",";
	sout << x.sectores;
	sout<< "]";
	return sout.str();
}

string teatroToDebug(string mssg,Teatro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idTeatro;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.capacidad;
	sout << ",";
	sout << x.sectores;
	sout<< "]";
	return sout.str();
}

Teatro teatro(int idTeatro,string direccion,int capacidad,int sectores)
{
	Teatro a;
	a.idTeatro = idTeatro;
	strcpy(a.direccion,direccion.c_str());
	a.capacidad = capacidad;
	a.sectores = sectores;
	return a;
}

bool teatroEquals(Teatro a,Teatro b)
{
	if(a.idTeatro!=b.idTeatro) return false;
	if(a.capacidad!=b.capacidad) return false;
	if(a.sectores!=b.sectores) return false;
	return true;
}

string funcionToString(Funcion x)
{
	char sep = 3;
	string sIdFuncion=to_string(x.idFuncion);
	string sDiaSem=to_string(x.diaSem);
	string sHora=to_string(x.hora);
	return sIdFuncion+sep+sDiaSem+sep+sHora;
}

Funcion funcionFromString(string s)
{
	char sep = 3;
	Funcion x;
	string t0 = getTokenAt(s,sep,0);
	x.idFuncion=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.diaSem=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.hora=stoi(t2);
	return x;
}

string funcionToDebug(Funcion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idFuncion;
	sout << ",";
	sout << x.diaSem;
	sout << ",";
	sout << x.hora;
	sout<< "]";
	return sout.str();
}

string funcionToDebug(string mssg,Funcion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idFuncion;
	sout << ",";
	sout << x.diaSem;
	sout << ",";
	sout << x.hora;
	sout<< "]";
	return sout.str();
}

Funcion funcion(int idFuncion,int diaSem,int hora)
{
	Funcion a;
	a.idFuncion = idFuncion;
	a.diaSem = diaSem;
	a.hora = hora;
	return a;
}

bool funcionEquals(Funcion a,Funcion b)
{
	if(a.idFuncion!=b.idFuncion) return false;
	if(a.diaSem!=b.diaSem) return false;
	if(a.hora!=b.hora) return false;
	return true;
}

string reservaToString(Reserva x)
{
	char sep = 4;
	string sIdCliente=to_string(x.idCliente);
	string sIdObra=to_string(x.idObra);
	string sIdFuncion=to_string(x.idFuncion);
	string sSector=to_string(x.sector);
	string sCant=to_string(x.cant);
	return sIdCliente+sep+sIdObra+sep+sIdFuncion+sep+sSector+sep+sCant;
}

Reserva reservaFromString(string s)
{
	char sep = 4;
	Reserva x;
	string t0 = getTokenAt(s,sep,0);
	x.idCliente=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idObra=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.idFuncion=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.sector=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.cant=stoi(t4);
	return x;
}

string reservaToDebug(Reserva x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCliente;
	sout << ",";
	sout << x.idObra;
	sout << ",";
	sout << x.idFuncion;
	sout << ",";
	sout << x.sector;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

string reservaToDebug(string mssg,Reserva x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCliente;
	sout << ",";
	sout << x.idObra;
	sout << ",";
	sout << x.idFuncion;
	sout << ",";
	sout << x.sector;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

Reserva reserva(int idCliente,int idObra,int idFuncion,int sector,int cant)
{
	Reserva a;
	a.idCliente = idCliente;
	a.idObra = idObra;
	a.idFuncion = idFuncion;
	a.sector = sector;
	a.cant = cant;
	return a;
}

bool reservaEquals(Reserva a,Reserva b)
{
	if(a.idCliente!=b.idCliente) return false;
	if(a.idObra!=b.idObra) return false;
	if(a.idFuncion!=b.idFuncion) return false;
	if(a.sector!=b.sector) return false;
	if(a.cant!=b.cant) return false;
	return true;
}

#endif
