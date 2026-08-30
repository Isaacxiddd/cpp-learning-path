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

struct Proyecto
{
	int idProy;
	char descr[50];
	char dir[50];
};

struct Horas
{
	int idEmpleado;
	int idProy;
	int horas;
	int fecha;
};

struct Empleado
{
	int idEmp;
	char nombre[50];
};

string proyectoToString(Proyecto x)
{
	char sep = 1;
	string sIdProy=to_string(x.idProy);
	string sDescr=x.descr;
	string sDir=x.dir;
	return sIdProy+sep+sDescr+sep+sDir;
}

Proyecto proyectoFromString(string s)
{
	char sep = 1;
	Proyecto x;
	string t0 = getTokenAt(s,sep,0);
	x.idProy=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.dir,t2.c_str());
	return x;
}

string proyectoToDebug(Proyecto x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idProy;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.dir;
	sout<< "]";
	return sout.str();
}

string proyectoToDebug(string mssg,Proyecto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idProy;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.dir;
	sout<< "]";
	return sout.str();
}

Proyecto proyecto(int idProy,string descr,string dir)
{
	Proyecto a;
	a.idProy = idProy;
	strcpy(a.descr,descr.c_str());
	strcpy(a.dir,dir.c_str());
	return a;
}

bool proyectoEquals(Proyecto a,Proyecto b)
{
	if(a.idProy!=b.idProy) return false;
	return true;
}

string horasToString(Horas x)
{
	char sep = 2;
	string sIdEmpleado=to_string(x.idEmpleado);
	string sIdProy=to_string(x.idProy);
	string sHoras=to_string(x.horas);
	string sFecha=to_string(x.fecha);
	return sIdEmpleado+sep+sIdProy+sep+sHoras+sep+sFecha;
}

Horas horasFromString(string s)
{
	char sep = 2;
	Horas x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmpleado=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idProy=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.horas=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.fecha=stoi(t3);
	return x;
}

string horasToDebug(Horas x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEmpleado;
	sout << ",";
	sout << x.idProy;
	sout << ",";
	sout << x.horas;
	sout << ",";
	sout << x.fecha;
	sout<< "]";
	return sout.str();
}

string horasToDebug(string mssg,Horas x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEmpleado;
	sout << ",";
	sout << x.idProy;
	sout << ",";
	sout << x.horas;
	sout << ",";
	sout << x.fecha;
	sout<< "]";
	return sout.str();
}

Horas horas(int idEmpleado,int idProy,int horas,int fecha)
{
	Horas a;
	a.idEmpleado = idEmpleado;
	a.idProy = idProy;
	a.horas = horas;
	a.fecha = fecha;
	return a;
}

bool horasEquals(Horas a,Horas b)
{
	if(a.idEmpleado!=b.idEmpleado) return false;
	if(a.idProy!=b.idProy) return false;
	if(a.horas!=b.horas) return false;
	if(a.fecha!=b.fecha) return false;
	return true;
}

string empleadoToString(Empleado x)
{
	char sep = 3;
	string sIdEmp=to_string(x.idEmp);
	string sNombre=x.nombre;
	return sIdEmp+sep+sNombre;
}

Empleado empleadoFromString(string s)
{
	char sep = 3;
	Empleado x;
	string t0 = getTokenAt(s,sep,0);
	x.idEmp=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	return x;
}

string empleadoToDebug(Empleado x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idEmp;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

string empleadoToDebug(string mssg,Empleado x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idEmp;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

Empleado empleado(int idEmp,string nombre)
{
	Empleado a;
	a.idEmp = idEmp;
	strcpy(a.nombre,nombre.c_str());
	return a;
}

bool empleadoEquals(Empleado a,Empleado b)
{
	if(a.idEmp!=b.idEmp) return false;
	return true;
}

#endif
