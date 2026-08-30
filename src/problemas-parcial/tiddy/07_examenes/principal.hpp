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

struct Curso
{
	int idCur;
	char descr[10];
	char turno;
};

struct Alumno
{
	int idAlu;
	int legajo;
	char nombre[50];
	int idCur;
};

struct Tema
{
	int idTema;
	int idAfir;
	char tipoAfir;
	char afir[250];
	char rta;
};

struct Respuesta
{
	int idAlu;
	char tipoAfir;
	int idAfir;
	char rta;
	int idTema;
};

string cursoToString(Curso x)
{
	char sep = 1;
	string sIdCur=to_string(x.idCur);
	string sDescr=x.descr;
	string sTurno=string(1,x.turno);
	return sIdCur+sep+sDescr+sep+sTurno;
}

Curso cursoFromString(string s)
{
	char sep = 1;
	Curso x;
	string t0 = getTokenAt(s,sep,0);
	x.idCur=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.turno=(char)t2[0];
	return x;
}

string cursoToDebug(Curso x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCur;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.turno;
	sout<< "]";
	return sout.str();
}

string cursoToDebug(string mssg,Curso x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCur;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.turno;
	sout<< "]";
	return sout.str();
}

Curso curso(int idCur,string descr,char turno)
{
	Curso a;
	a.idCur = idCur;
	strcpy(a.descr,descr.c_str());
	a.turno = turno;
	return a;
}

bool cursoEquals(Curso a,Curso b)
{
	if(a.idCur!=b.idCur) return false;
	if(a.turno!=b.turno) return false;
	return true;
}

string alumnoToString(Alumno x)
{
	char sep = 2;
	string sIdAlu=to_string(x.idAlu);
	string sLegajo=to_string(x.legajo);
	string sNombre=x.nombre;
	string sIdCur=to_string(x.idCur);
	return sIdAlu+sep+sLegajo+sep+sNombre+sep+sIdCur;
}

Alumno alumnoFromString(string s)
{
	char sep = 2;
	Alumno x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.legajo=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.nombre,t2.c_str());
	string t3 = getTokenAt(s,sep,3);
	x.idCur=stoi(t3);
	return x;
}

string alumnoToDebug(Alumno x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	sout << x.legajo;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.idCur;
	sout<< "]";
	return sout.str();
}

string alumnoToDebug(string mssg,Alumno x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	sout << x.legajo;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.idCur;
	sout<< "]";
	return sout.str();
}

Alumno alumno(int idAlu,int legajo,string nombre,int idCur)
{
	Alumno a;
	a.idAlu = idAlu;
	a.legajo = legajo;
	strcpy(a.nombre,nombre.c_str());
	a.idCur = idCur;
	return a;
}

bool alumnoEquals(Alumno a,Alumno b)
{
	if(a.idAlu!=b.idAlu) return false;
	if(a.legajo!=b.legajo) return false;
	if(a.idCur!=b.idCur) return false;
	return true;
}

string temaToString(Tema x)
{
	char sep = 3;
	string sIdTema=to_string(x.idTema);
	string sIdAfir=to_string(x.idAfir);
	string sTipoAfir=string(1,x.tipoAfir);
	string sAfir=x.afir;
	string sRta=string(1,x.rta);
	return sIdTema+sep+sIdAfir+sep+sTipoAfir+sep+sAfir+sep+sRta;
}

Tema temaFromString(string s)
{
	char sep = 3;
	Tema x;
	string t0 = getTokenAt(s,sep,0);
	x.idTema=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idAfir=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.tipoAfir=(char)t2[0];
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.afir,t3.c_str());
	string t4 = getTokenAt(s,sep,4);
	x.rta=(char)t4[0];
	return x;
}

string temaToDebug(Tema x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idTema;
	sout << ",";
	sout << x.idAfir;
	sout << ",";
	sout << x.tipoAfir;
	sout << ",";
	sout << x.afir;
	sout << ",";
	sout << x.rta;
	sout<< "]";
	return sout.str();
}

string temaToDebug(string mssg,Tema x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idTema;
	sout << ",";
	sout << x.idAfir;
	sout << ",";
	sout << x.tipoAfir;
	sout << ",";
	sout << x.afir;
	sout << ",";
	sout << x.rta;
	sout<< "]";
	return sout.str();
}

Tema tema(int idTema,int idAfir,char tipoAfir,string afir,char rta)
{
	Tema b;
	b.idTema = idTema;
	b.idAfir = idAfir;
	b.tipoAfir = tipoAfir;
	strcpy(b.afir,afir.c_str());
	b.rta = rta;
	return b;
}

bool temaEquals(Tema a,Tema b)
{
	if(a.idTema!=b.idTema) return false;
	if(a.idAfir!=b.idAfir) return false;
	if(a.tipoAfir!=b.tipoAfir) return false;
	if(a.rta!=b.rta) return false;
	return true;
}

string respuestaToString(Respuesta x)
{
	char sep = 4;
	string sIdAlu=to_string(x.idAlu);
	string sTipoAfir=string(1,x.tipoAfir);
	string sIdAfir=to_string(x.idAfir);
	string sRta=string(1,x.rta);
	string sIdTema=to_string(x.idTema);
	return sIdAlu+sep+sTipoAfir+sep+sIdAfir+sep+sRta+sep+sIdTema;
}

Respuesta respuestaFromString(string s)
{
	char sep = 4;
	Respuesta x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.tipoAfir=(char)t1[0];
	string t2 = getTokenAt(s,sep,2);
	x.idAfir=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.rta=(char)t3[0];
	string t4 = getTokenAt(s,sep,4);
	x.idTema=stoi(t4);
	return x;
}

string respuestaToDebug(Respuesta x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlu;
	sout << ",";
	sout << x.tipoAfir;
	sout << ",";
	sout << x.idAfir;
	sout << ",";
	sout << x.rta;
	sout << ",";
	sout << x.idTema;
	sout<< "]";
	return sout.str();
}

string respuestaToDebug(string mssg,Respuesta x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlu;
	sout << ",";
	sout << x.tipoAfir;
	sout << ",";
	sout << x.idAfir;
	sout << ",";
	sout << x.rta;
	sout << ",";
	sout << x.idTema;
	sout<< "]";
	return sout.str();
}

Respuesta respuesta(int idAlu,char tipoAfir,int idAfir,char rta,int idTema)
{
	Respuesta a;
	a.idAlu = idAlu;
	a.tipoAfir = tipoAfir;
	a.idAfir = idAfir;
	a.rta = rta;
	a.idTema = idTema;
	return a;
}

bool respuestaEquals(Respuesta a,Respuesta b)
{
	if(a.idAlu!=b.idAlu) return false;
	if(a.tipoAfir!=b.tipoAfir) return false;
	if(a.idAfir!=b.idAfir) return false;
	if(a.rta!=b.rta) return false;
	if(a.idTema!=b.idTema) return false;
	return true;
}

#endif
