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
	int idCli;
	char mov;
	int hora;
};

string movToString(Mov x)
{
	char sep = 1;
	string sIdCli=to_string(x.idCli);
	string sMov=string(1,x.mov);
	string sHora=to_string(x.hora);
	return sIdCli+sep+sMov+sep+sHora;
}

Mov movFromString(string s)
{
	char sep = 1;
	Mov x;
	string t0 = getTokenAt(s,sep,0);
	x.idCli=stoi(t0);
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
	sout << x.idCli;
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
	sout << x.idCli;
	sout << ",";
	sout << x.mov;
	sout << ",";
	sout << x.hora;
	sout<< "]";
	return sout.str();
}

Mov mov(int idCli,char mov,int hora)
{
	Mov a;
	a.idCli = idCli;
	a.mov = mov;
	a.hora = hora;
	return a;
}

bool movEquals(Mov a,Mov b)
{
	if(a.idCli!=b.idCli) return false;
	if(a.mov!=b.mov) return false;
	if(a.hora!=b.hora) return false;
	return true;
}

#endif
