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
//   REPRODUCCIONES.dat → novedades, ordenado por idUsuario (y por idLibro)
//   LIBROS.dat         → consulta (se sube a memoria)
//   RELATORES.dat      → consulta (se sube a memoria)
//
// Corte de control (usuario, libro) acumulando minutos: un usuario retoma el
// libro donde lo dejo. Se pide:
//   1) Por libro, reproducciones completas y por rango (75-100, 50-75, 25-50,
//      <25) sobre el porcentaje minutos/duracion.
//   2) Los 10 relatores con mas reproducciones en el rango 75-100%, de mayor
//      a menor.

int main()
{
	// TODO: resolvé acá (estructuras de trabajo, subir consultas,
	// procesamiento de novedades y muestra).

	std::cin.get();
	return 0;
}
