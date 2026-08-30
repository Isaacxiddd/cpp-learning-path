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
//   INSCRIPCIONES.dat → novedades, sin orden
//   PADRON.dat        → consulta, ordenado por idEst; demasiado extenso para
//                       memoria -> busqueda binaria sobre el archivo
//
// Generar INCONSISTENCIAS.dat con el tipo de problema:
//   1 = no figura en el padron (nombre = desconocido!!),
//   2 = escuela diferente a la matriculada,
//   3 = fecha de inscripcion anterior a la matriculacion.
// Luego listar el archivo generado.

int main()
{
	// TODO: resolvé acá (estructuras de trabajo, subir consultas,
	// procesamiento de novedades y muestra).

	std::cin.get();
	return 0;
}
