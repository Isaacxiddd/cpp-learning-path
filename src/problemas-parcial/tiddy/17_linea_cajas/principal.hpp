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

struct Mov
{
	int caja;
	char mov;
	int hora;
};

string movToString(Mov x)
{
	char sep = 1;
	string sCaja=to_string(x.caja);
	string sMov=string(1,x.mov);
	string sHora=to_string(x.hora);
	return sCaja+sep+sMov+sep+sHora;
}

Mov movFromString(string s)
{
	char sep = 1;
	Mov x;
	string t0 = getTokenAt(s,sep,0);
	x.caja=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.mov=(char)t1[0];
	string t2 = getTokenAt(s,sep,2);
	x.hora=stoi(t2);
	return x;
}

string movToDebug(Mov x)
{
	stringstream sout;
	sout<< "[";
	sout << x.caja;
	sout << ",";
	sout << x.mov;
	sout << ",";
	sout << x.hora;
	sout<< "]";
	return sout.str();
}

string movToDebug(string mssg,Mov x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.caja;
	sout << ",";
	sout << x.mov;
	sout << ",";
	sout << x.hora;
	sout<< "]";
	return sout.str();
}

Mov mov(int caja,char mov,int hora)
{
	Mov a;
	a.caja = caja;
	a.mov = mov;
	a.hora = hora;
	return a;
}

bool movEquals(Mov a,Mov b)
{
	if(a.caja!=b.caja) return false;
	if(a.mov!=b.mov) return false;
	if(a.hora!=b.hora) return false;
	return true;
}

#endif
