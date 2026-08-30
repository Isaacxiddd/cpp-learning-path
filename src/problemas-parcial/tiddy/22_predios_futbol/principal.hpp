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

struct Predio
{
	int idPredio;
	char nombre[100];
	char direccion[100];
	int cantCanchas;
	int idBarrio;
};

struct Reserva
{
	int idReserva;
	int idCliente;
	int idPredio;
	int diaMes;
	char turno;
	char celContacto[50];
};

struct Cancha
{
	int idPredio;
	int nroCancha;
	double precio;
	int flgCubierta;
	char obs[200];
};

struct Rechazo
{
	Reserva reserva;
	int motivoRechazo;
};

string predioToString(Predio x)
{
	char sep = 1;
	string sIdPredio=to_string(x.idPredio);
	string sNombre=x.nombre;
	string sDireccion=x.direccion;
	string sCantCanchas=to_string(x.cantCanchas);
	string sIdBarrio=to_string(x.idBarrio);
	return sIdPredio+sep+sNombre+sep+sDireccion+sep+sCantCanchas+sep+sIdBarrio;
}

Predio predioFromString(string s)
{
	char sep = 1;
	Predio x;
	string t0 = getTokenAt(s,sep,0);
	x.idPredio=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	strcpy(x.direccion,t2.c_str());
	string t3 = getTokenAt(s,sep,3);
	x.cantCanchas=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.idBarrio=stoi(t4);
	return x;
}

string predioToDebug(Predio x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idPredio;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.cantCanchas;
	sout << ",";
	sout << x.idBarrio;
	sout<< "]";
	return sout.str();
}

string predioToDebug(string mssg,Predio x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idPredio;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.cantCanchas;
	sout << ",";
	sout << x.idBarrio;
	sout<< "]";
	return sout.str();
}

Predio predio(int idPredio,string nombre,string direccion,int cantCanchas,int idBarrio)
{
	Predio a;
	a.idPredio = idPredio;
	strcpy(a.nombre,nombre.c_str());
	strcpy(a.direccion,direccion.c_str());
	a.cantCanchas = cantCanchas;
	a.idBarrio = idBarrio;
	return a;
}

bool predioEquals(Predio a,Predio b)
{
	if(a.idPredio!=b.idPredio) return false;
	if(a.cantCanchas!=b.cantCanchas) return false;
	if(a.idBarrio!=b.idBarrio) return false;
	return true;
}

string reservaToString(Reserva x)
{
	char sep = 2;
	string sIdReserva=to_string(x.idReserva);
	string sIdCliente=to_string(x.idCliente);
	string sIdPredio=to_string(x.idPredio);
	string sDiaMes=to_string(x.diaMes);
	string sTurno=string(1,x.turno);
	string sCelContacto=x.celContacto;
	return sIdReserva+sep+sIdCliente+sep+sIdPredio+sep+sDiaMes+sep+sTurno+sep+sCelContacto;
}

Reserva reservaFromString(string s)
{
	char sep = 2;
	Reserva x;
	string t0 = getTokenAt(s,sep,0);
	x.idReserva=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCliente=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.idPredio=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.diaMes=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.turno=(char)t4[0];
	string t5 = getTokenAt(s,sep,5);
	strcpy(x.celContacto,t5.c_str());
	return x;
}

string reservaToDebug(Reserva x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idReserva;
	sout << ",";
	sout << x.idCliente;
	sout << ",";
	sout << x.idPredio;
	sout << ",";
	sout << x.diaMes;
	sout << ",";
	sout << x.turno;
	sout << ",";
	sout << x.celContacto;
	sout<< "]";
	return sout.str();
}

string reservaToDebug(string mssg,Reserva x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idReserva;
	sout << ",";
	sout << x.idCliente;
	sout << ",";
	sout << x.idPredio;
	sout << ",";
	sout << x.diaMes;
	sout << ",";
	sout << x.turno;
	sout << ",";
	sout << x.celContacto;
	sout<< "]";
	return sout.str();
}

Reserva reserva(int idReserva,int idCliente,int idPredio,int diaMes,char turno,string celContacto)
{
	Reserva a;
	a.idReserva = idReserva;
	a.idCliente = idCliente;
	a.idPredio = idPredio;
	a.diaMes = diaMes;
	a.turno = turno;
	strcpy(a.celContacto,celContacto.c_str());
	return a;
}

bool reservaEquals(Reserva a,Reserva b)
{
	if(a.idReserva!=b.idReserva) return false;
	if(a.idCliente!=b.idCliente) return false;
	if(a.idPredio!=b.idPredio) return false;
	if(a.diaMes!=b.diaMes) return false;
	if(a.turno!=b.turno) return false;
	return true;
}

string canchaToString(Cancha x)
{
	char sep = 3;
	string sIdPredio=to_string(x.idPredio);
	string sNroCancha=to_string(x.nroCancha);
	string sPrecio=to_string(x.precio);
	string sFlgCubierta=to_string(x.flgCubierta);
	string sObs=x.obs;
	return sIdPredio+sep+sNroCancha+sep+sPrecio+sep+sFlgCubierta+sep+sObs;
}

Cancha canchaFromString(string s)
{
	char sep = 3;
	Cancha x;
	string t0 = getTokenAt(s,sep,0);
	x.idPredio=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.nroCancha=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.precio=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.flgCubierta=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	strcpy(x.obs,t4.c_str());
	return x;
}

string canchaToDebug(Cancha x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idPredio;
	sout << ",";
	sout << x.nroCancha;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.flgCubierta;
	sout << ",";
	sout << x.obs;
	sout<< "]";
	return sout.str();
}

string canchaToDebug(string mssg,Cancha x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idPredio;
	sout << ",";
	sout << x.nroCancha;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.flgCubierta;
	sout << ",";
	sout << x.obs;
	sout<< "]";
	return sout.str();
}

Cancha cancha(int idPredio,int nroCancha,double precio,int flgCubierta,string obs)
{
	Cancha a;
	a.idPredio = idPredio;
	a.nroCancha = nroCancha;
	a.precio = precio;
	a.flgCubierta = flgCubierta;
	strcpy(a.obs,obs.c_str());
	return a;
}

bool canchaEquals(Cancha a,Cancha b)
{
	if(a.idPredio!=b.idPredio) return false;
	if(a.nroCancha!=b.nroCancha) return false;
	if(a.precio!=b.precio) return false;
	if(a.flgCubierta!=b.flgCubierta) return false;
	return true;
}

string rechazoToString(Rechazo x)
{
	char sep = 4;
	string sReserva=reservaToString(x.reserva);
	string sMotivoRechazo=to_string(x.motivoRechazo);
	return sReserva+sep+sMotivoRechazo;
}

Rechazo rechazoFromString(string s)
{
	char sep = 4;
	Rechazo x;
	string t0 = getTokenAt(s,sep,0);
	x.reserva=reservaFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.motivoRechazo=stoi(t1);
	return x;
}

string rechazoToDebug(Rechazo x)
{
	stringstream sout;
	sout<< "[";
	sout << reservaToDebug(x.reserva);
	sout << ",";
	sout << x.motivoRechazo;
	sout<< "]";
	return sout.str();
}

string rechazoToDebug(string mssg,Rechazo x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << reservaToDebug(x.reserva);
	sout << ",";
	sout << x.motivoRechazo;
	sout<< "]";
	return sout.str();
}

Rechazo rechazo(Reserva reserva,int motivoRechazo)
{
	Rechazo a;
	a.reserva = reserva;
	a.motivoRechazo = motivoRechazo;
	return a;
}

bool rechazoEquals(Rechazo a,Rechazo b)
{
	if(!reservaEquals(a.reserva,b.reserva)) return false;
	if(a.motivoRechazo!=b.motivoRechazo) return false;
	return true;
}

#endif
