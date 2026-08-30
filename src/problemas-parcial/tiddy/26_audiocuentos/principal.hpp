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

struct Reproduccion
{
	int idUsuario;
	int idCuento;
	int fecha;
	int minutos;
};

struct Cuento
{
	int idCuento;
	int idRelator;
	int idAutor;
	char titulo[50];
	int duracion;
};

struct Relator
{
	int idRelator;
	char nombre[50];
};

string reproduccionToString(Reproduccion x)
{
	char sep = 1;
	string sIdUsuario=to_string(x.idUsuario);
	string sIdCuento=to_string(x.idCuento);
	string sFecha=to_string(x.fecha);
	string sMinutos=to_string(x.minutos);
	return sIdUsuario+sep+sIdCuento+sep+sFecha+sep+sMinutos;
}

Reproduccion reproduccionFromString(string s)
{
	char sep = 1;
	Reproduccion x;
	string t0 = getTokenAt(s,sep,0);
	x.idUsuario=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCuento=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.minutos=stoi(t3);
	return x;
}

string reproduccionToDebug(Reproduccion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idUsuario;
	sout << ",";
	sout << x.idCuento;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.minutos;
	sout<< "]";
	return sout.str();
}

string reproduccionToDebug(string mssg,Reproduccion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idUsuario;
	sout << ",";
	sout << x.idCuento;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.minutos;
	sout<< "]";
	return sout.str();
}

Reproduccion reproduccion(int idUsuario,int idCuento,int fecha,int minutos)
{
	Reproduccion a;
	a.idUsuario = idUsuario;
	a.idCuento = idCuento;
	a.fecha = fecha;
	a.minutos = minutos;
	return a;
}

bool reproduccionEquals(Reproduccion a,Reproduccion b)
{
	if(a.idUsuario!=b.idUsuario) return false;
	if(a.idCuento!=b.idCuento) return false;
	if(a.fecha!=b.fecha) return false;
	if(a.minutos!=b.minutos) return false;
	return true;
}

string cuentoToString(Cuento x)
{
	char sep = 2;
	string sIdCuento=to_string(x.idCuento);
	string sIdRelator=to_string(x.idRelator);
	string sIdAutor=to_string(x.idAutor);
	string sTitulo=x.titulo;
	string sDuracion=to_string(x.duracion);
	return sIdCuento+sep+sIdRelator+sep+sIdAutor+sep+sTitulo+sep+sDuracion;
}

Cuento cuentoFromString(string s)
{
	char sep = 2;
	Cuento x;
	string t0 = getTokenAt(s,sep,0);
	x.idCuento=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idRelator=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.idAutor=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.titulo,t3.c_str());
	string t4 = getTokenAt(s,sep,4);
	x.duracion=stoi(t4);
	return x;
}

string cuentoToDebug(Cuento x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCuento;
	sout << ",";
	sout << x.idRelator;
	sout << ",";
	sout << x.idAutor;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.duracion;
	sout<< "]";
	return sout.str();
}

string cuentoToDebug(string mssg,Cuento x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCuento;
	sout << ",";
	sout << x.idRelator;
	sout << ",";
	sout << x.idAutor;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.duracion;
	sout<< "]";
	return sout.str();
}

Cuento cuento(int idCuento,int idRelator,int idAutor,string titulo,int duracion)
{
	Cuento a;
	a.idCuento = idCuento;
	a.idRelator = idRelator;
	a.idAutor = idAutor;
	strcpy(a.titulo,titulo.c_str());
	a.duracion = duracion;
	return a;
}

bool cuentoEquals(Cuento a,Cuento b)
{
	if(a.idCuento!=b.idCuento) return false;
	if(a.idRelator!=b.idRelator) return false;
	if(a.idAutor!=b.idAutor) return false;
	if(a.duracion!=b.duracion) return false;
	return true;
}

string relatorToString(Relator x)
{
	char sep = 3;
	string sIdRelator=to_string(x.idRelator);
	string sNombre=x.nombre;
	return sIdRelator+sep+sNombre;
}

Relator relatorFromString(string s)
{
	char sep = 3;
	Relator x;
	string t0 = getTokenAt(s,sep,0);
	x.idRelator=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	return x;
}

string relatorToDebug(Relator x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idRelator;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

string relatorToDebug(string mssg,Relator x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idRelator;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

Relator relator(int idRelator,string nombre)
{
	Relator a;
	a.idRelator = idRelator;
	strcpy(a.nombre,nombre.c_str());
	return a;
}

bool relatorEquals(Relator a,Relator b)
{
	if(a.idRelator!=b.idRelator) return false;
	return true;
}

#endif
