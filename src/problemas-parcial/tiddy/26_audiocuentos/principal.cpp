#include <iostream>
#include "../../../../lib/funciones/files.hpp"
#include "../../../../lib/funciones/strings.hpp"
#include "../../../../lib/funciones/tokens.hpp"
#include "../../../../lib/funciones/Coll.hpp"
#include "principal.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

// ─── Enunciado ─────────────────────────────────────────────────────────────────
// Archivos:
//   REPRODUCCIONES.dat → novedades, se recorre una sola vez
//   CUENTOS.dat        → consulta (se sube a memoria)
//   RELATORES.dat      → consulta (se sube a memoria)
//
// Una reproduccion es "completa" si minutos >= duracion del cuento. Los rangos
// se calculan sobre el porcentaje minutos/duracion:
//   completa: 100% ; 75-100% ; 50-75% ; 25-50% ; menos de 25%.
// Se pide:
//   1) Por cada cuento, cuantas reproducciones cayeron en cada rango.
//   2) Los relatores con mas reproducciones en el rango 75-100% (de mayor a
//      menor). Cada relator cuenta sus cuentos: por cada reproduccion de un
//      cuento suyo en el rango 75-100% suma 1.

// ─── Estructuras de trabajo ───────────────────────────────────────────────────

struct RCuento
{
	Cuento c;
	int completa;
	int r75;
	int r50;
	int r25;
	int rMenos;
};

struct RRelator
{
	Relator r;
	int cant75;
};

// ─── Subir consultas ──────────────────────────────────────────────────────────

Coll<Cuento> cuentosSubir()
{
	Coll<Cuento> c = coll<Cuento>();
	// TODO: leer CUENTOS.dat y subir todos los registros a la coleccion
	return c;
}

Coll<Relator> relatoresSubir()
{
	Coll<Relator> c = coll<Relator>();
	// TODO: leer RELATORES.dat y subir todos los registros a la coleccion
	return c;
}

// ─── Busqueda ─────────────────────────────────────────────────────────────────

Cuento buscarCuento(int idCuento, Coll<Cuento> cCuentos)
{
	// TODO: busqueda binaria por idCuento
	return cuento(0, 0, 0, "", 0);
}

Relator buscarRelator(int idRelator, Coll<Relator> cRelatores)
{
	// TODO: busqueda binaria por idRelator
	return relator(0, "");
}

// ─── Contar rangos ────────────────────────────────────────────────────────────

int rangoDe(int minutos, int duracion)
{
	// TODO: devolver 0=completa, 1=75-100, 2=50-75, 3=25-50, 4=menos de 25
	return 0;
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main()
{
	std::cin.get();
	return 0;
}
