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
//   RESPUESTAS.dat → novedades, ordenado por idAlu, tipoAfir, idAfir
//   TEMAS.dat      → consulta (respuestas correctas)
//   ALUMNOS.dat    → consulta
//   CURSOS.dat     → consulta
//
// Corte de control por idAlu. Calificacion = 0,5*n - 0,5*m (n correctas,
// m incorrectas); minimo 3 puntos por parte; calificacion R si < 2,5 en
// alguna parte. Listar por idAlu: curso (descr y turno) y calificacion.



void procesarAlumnos(Coll<Alumno>& a)
{
	FILE* f = fopen("ALUMNOS.dat","r+b");
	Alumno alu = read<Alumno>(f);       // primera lectura
	while( !feof(f) )
	{
		collAdd<Alumno>(a, alu, alumnoToString);
		alu = read<Alumno>(f);          // leer el siguiente
	}
	fclose(f);
}

void procesarRespuestas(Coll<Respuesta>& a)
{
 FILE* f = fopen("Respuestas.dat","r+b");
 Respuesta respu = read<Respuesta>(f);
 while(!feof(f))
 {
    collAdd<Respuesta>(a,respu,respuestaToString);
    respu = read<Respuesta>(f);
    fclose(f);
 }

}

int main()
{
	// TODO: resolvé acá (estructuras de trabajo, subir consultas,
	// procesamiento de novedades y muestra).
Coll<Alumno> cola= coll<Alumno>();
   procesarAlumnos(cola);

Coll<Respuesta> alumno= coll<Respuesta>();
   procesarRespuestas(alumno);




	std::cin.get();
	return 0;
}
