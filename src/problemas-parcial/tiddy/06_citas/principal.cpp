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

// --- FUNCIONES A IMPLEMENTAR (estructura vacía para que compiles) ---
void subirAutores(Coll<Autor>& a);
void mostrarFrasesPorAnio(Coll<Autor>& a, int anioSeleccionado);

// --- FUNCION PRINCIPAL ---
int main()
{
    Coll<Autor> autores;

    // 1. Cargar datos desde el archivo FRASES.txt
    subirAutores(autores);

    // 2. Recopilar años únicos de las frases cargadas
    int aniosUnicos[200] = {0};
    int cantidadAnios = 0;

    collReset<Autor>(autores);
    while (collHasNext<Autor>(autores))
    {
        Autor aActual = collNext<Autor>(autores, rAutorFromString);
        collReset<string>(aActual.frases);
        while (collHasNext<string>(aActual.frases))
        {
            string frm = collNext<string>(aActual.frases, stringToString);
            string anioStr = getTokenAt(frm, '|', 2);
            int anioNum = stringToInt(anioStr);

            // Agregar al array de años si no está ya
            bool yaExiste = false;
            for (int i = 0; i < cantidadAnios; i++)
            {
                if (aniosUnicos[i] == anioNum)
                {
                    yaExiste = true;
                    break;
                }
            }
            if (!yaExiste)
            {
                aniosUnicos[cantidadAnios] = anioNum;
                cantidadAnios++;
            }
        }
    }

    // Ordenar años de menor a mayor (simple burbuja)
    for (int i = 0; i < cantidadAnios - 1; i++)
    {
        for (int j = i + 1; j < cantidadAnios; j++)
        {
            if (aniosUnicos[i] > aniosUnicos[j])
            {
                int tmp = aniosUnicos[i];
                aniosUnicos[i] = aniosUnicos[j];
                aniosUnicos[j] = tmp;
            }
        }
    }

    // 3. Mostrar menú de años
    cout << "[SELECCIONE ANIO]" << endl;
    for (int i = 0; i < cantidadAnios; i++)
    {
        cout << i + 1 << ". " << aniosUnicos[i] << endl;
    }
    cout << "> ";

    int opcion;
    cin >> opcion;

    // 4. Validar opción y mostrar frases del año seleccionado
    if (opcion >= 1 && opcion <= cantidadAnios)
    {
        int anioSel = aniosUnicos[opcion - 1];
        cout << "\n[SELECCIONE AUTOR (" << anioSel << ")]" << endl;

        // Mostrar autores con frases en ese año
        collReset<Autor>(autores);
        bool primero = true;
        while (collHasNext<Autor>(autores))
        {
            Autor aActual = collNext<Autor>(autores, rAutorFromString);

            // Verificar si el autor tiene alguna frase del año seleccionado
            collReset<string>(aActual.frases);
            bool tieneFrasesAno = false;

            while (collHasNext<string>(aActual.frases))
            {
                string frm = collNext<string>(aActual.frases, stringToString);
                string anioFrm = getTokenAt(frm, '|', 2);
                int anioFrmNum = stringToInt(anioFrm);

                if (anioFrmNum == anioSel)
                {
                    tieneFrasesAno = true;
                    break;
                }
            }

            if (tieneFrasesAno)
            {
                if (!primero)
                    cout << endl;
                cout << aActual.nombre << ":";
                primero = false;

                // Mostrar frases del autor del año seleccionado
                collReset<string>(aActual.frases);
                while (collHasNext<string>(aActual.frases))
                {
                    string frm = collNext<string>(aActual.frases, stringToString);
                    string anioFrm = getTokenAt(frm, '|', 2);
                    int anioFrmNum = stringToInt(anioFrm);
                    if (anioFrmNum == anioSel)
                    {
                        // Extraer solo la frase (quitar el año y autor que vienen en el string)
                        string frase = getTokenAt(frm, '|', 0);
                        // La frase empieza después del segundo pipe
                        // Formato original: contenido|autor|anio
                        // getTokenAt con | del 0 trae el contenido
                        cout << " " << frase;
                    }
                }
            }
        }
        if (primero)
            cout << "\nNo hay frases para este año.";
        cout << endl;
    }
    else
    {
        cout << "\nOpcion invalida." << endl;
    }

    // Pausa
    cin.ignore();
    cin.get();

    return 0;
}

// --- IMPLEMENTACIÓN DE FUNCIONES ---

void subirAutores(Coll<Autor>& a)
{
    FILE* f = fopen("FRASES.txt", "rt");
    if (!f)
    {
        cout << "Error: no se puede abrir FRASES.txt" << endl;
        return;
    }

    string ln;
    string contenido, autor, anioStr;
    int anio;
    Autor tempAutor;

    // --- PATRÓN SAGRDO: primera lectura FUERA del while ---
    if (!readLine(f, ln))
    {
        fclose(f);
        return; // archivo vacío
    }

    // Procesar primera línea y setup inicial
    contenido = getTokenAt(ln, '|', 0);
    autor = getTokenAt(ln, '|', 1);
    anioStr = getTokenAt(ln, '|', 2);
    anio = stringToInt(anioStr);

    // Crear estructura del autor y agregar primera frase
    tempAutor.nombre = autor;
    tempAutor.frases = collFromString<string>(contenido);
    collAdd<Autor>(a, tempAutor, rAutorToString);

    // --- BUCLE PRINCIPAL: leer resto de líneas ---
    while (readLine(f, ln))
    {
        contenido = getTokenAt(ln, '|', 0);
        autor = getTokenAt(ln, '|', 1);
        anioStr = getTokenAt(ln, '|', 2);
        anio = stringToInt(anioStr);

        // Buscar si el autor ya existe en la colección
        collReset<Autor>(a);
        Autor actual;
        bool encontrado = false;

        // Recorrer la colección para buscar por nombre
        collReset<Autor>(a);
        while (collHasNext<Autor>(a))
        {
            actual = collNext<Autor>(a, rAutorFromString);
            if (actual.nombre == autor)
            {
                encontrado = true;
                break;
            }
        }

        if (encontrado)
        {
            // Autor existe, agregar frase a su colección existente
            // Usamos collAdd que agrega a la colección de strings
            tempAutor = actual;
            collAdd<string>(tempAutor.frases, contenido, stringToString);
        }
        else
        {
            // Nuevo autor, crear estructura y agregarla
            tempAutor.nombre = autor;
            tempAutor.frases = collFromString<string>(contenido);
            collAdd<Autor>(a, tempAutor, rAutorToString);
        }
    }

    fclose(f); // SEMPRE fuera del while!
}

void mostrarFrasesPorAnio(Coll<Autor>& a, int anioSeleccionado)
{
    // Esta función puede completarse según necesites
    // Por ahora la dejamos con lógica básica en main()
}