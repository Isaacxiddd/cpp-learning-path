#ifndef _MAINHPP
#define _MAINHPP

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>

#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"
#include "../../../../lib/funciones/Coll.hpp"
#include "../../../../lib/tads/parte1/Fecha.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

struct Socio
{
    int idSocio;
    char nombre[50];
    int idSocioRef;  // socio referente, -1 si es el socio principal
    Fecha fechaIngreso;
    double totalVentasAcumuladas;
    double liquidacionAnterior;
    double liquidacionesAcumuladas;
};

struct Venta
{
    int idSocio;
    int idProducto;
    char observ[100];
    Fecha fecha;
    double importe;
};

#endif
