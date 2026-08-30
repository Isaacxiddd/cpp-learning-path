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
//   RESERVAS.dat  → novedades (se recorre una sola vez)
//   PREDIOS.dat   → consulta (se sube a memoria)
//   CANCHAS.dat   → consulta (se sube a memoria)
//
// Cada cancha admite 4 partidos por turno. Se pide:
//   1) Generar RECHAZOS.dat (motivo 1 = cancha no disponible, 2 = predio
//      inexistente).
//   2) Notificar aceptacion/rechazo (cancha y hora asignada, o motivo).
//   3) Por barrio y turno, reservas aceptadas y rechazadas.

int main()
{
	// TODO: resolvé acá (estructuras de trabajo, subir consultas,
	// procesamiento de novedades y muestra).

	std::cin.get();
	return 0;
}
