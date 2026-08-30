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

struct Inscripcion
{
	int idAlumno;
	int idCurso;
};

struct Curso
{
	int idCurso;
	int capacidad;
	char nombre[50];
};

string inscripcionToString(Inscripcion x)
{
	char sep = 1;
	string sIdAlumno=to_string(x.idAlumno);
	string sIdCurso=to_string(x.idCurso);
	return sIdAlumno+sep+sIdCurso;
}

Inscripcion inscripcionFromString(string s)
{
	char sep = 1;
	Inscripcion x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlumno=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCurso=stoi(t1);
	return x;
}

string inscripcionToDebug(Inscripcion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlumno;
	sout << ",";
	sout << x.idCurso;
	sout<< "]";
	return sout.str();
}

string inscripcionToDebug(string mssg,Inscripcion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlumno;
	sout << ",";
	sout << x.idCurso;
	sout<< "]";
	return sout.str();
}

Inscripcion inscripcion(int idAlumno,int idCurso)
{
	Inscripcion a;
	a.idAlumno = idAlumno;
	a.idCurso = idCurso;
	return a;
}

bool inscripcionEquals(Inscripcion a,Inscripcion b)
{
	if(a.idAlumno!=b.idAlumno) return false;
	if(a.idCurso!=b.idCurso) return false;
	return true;
}

string cursoToString(Curso x)
{
	char sep = 2;
	string sIdCurso=to_string(x.idCurso);
	string sCapacidad=to_string(x.capacidad);
	string sNombre=x.nombre;
	return sIdCurso+sep+sCapacidad+sep+sNombre;
}

Curso cursoFromString(string s)
{
	char sep = 2;
	Curso x;
	string t0 = getTokenAt(s,sep,0);
	x.idCurso=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.capacidad=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.nombre,t2.c_str());
	return x;
}

string cursoToDebug(Curso x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCurso;
	sout << ",";
	sout << x.capacidad;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

string cursoToDebug(string mssg,Curso x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCurso;
	sout << ",";
	sout << x.capacidad;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

Curso curso(int idCurso,int capacidad,string nombre)
{
	Curso a;
	a.idCurso = idCurso;
	a.capacidad = capacidad;
	strcpy(a.nombre,nombre.c_str());
	return a;
}

bool cursoEquals(Curso a,Curso b)
{
	if(a.idCurso!=b.idCurso) return false;
	if(a.capacidad!=b.capacidad) return false;
	return true;
}

#endif
