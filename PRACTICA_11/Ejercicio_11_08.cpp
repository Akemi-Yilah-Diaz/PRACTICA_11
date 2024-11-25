/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 8
// Problema planteado: Contador de líneas, palabras y caracteres
Descripción: Escribe un programa que lea un archivo de texto llamado
documento.txt y cuente el número total de líneas, palabras y caracteres. Al
final, el programa debe mostrar estos totales en la consola.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void procesarArchivo(const string& nombreArchivo) 
{
    ifstream archivoTexto(nombreArchivo);
    if (!archivoTexto) {
        cerr << "Error: no se pudo abrir el archivo especificado." << endl;
        return;
    }

    string contenidoLinea;
    int contadorLineas = 0, contadorPalabras = 0, contadorCaracteres = 0;

    while (getline(archivoTexto, contenidoLinea)) {
        contadorLineas++;

        contadorCaracteres += contenidoLinea.length();

        bool palabraActiva = false;
        for (char caracter : contenidoLinea) {
            if (!isspace(caracter) && !palabraActiva)
             {
                palabraActiva = true;
                contadorPalabras++;
            } else if (isspace(caracter)) 
            {
                palabraActiva = false;
            }
        }
    }

    archivoTexto.close();

    cout << "Cantidad de líneas: " << contadorLineas << endl;
    cout << "Cantidad de palabras: " << contadorPalabras << endl;
    cout << "Cantidad de caracteres: " << contadorCaracteres << endl;
}

int main()
{
    string archivoDestino = "documento.txt";

    procesarArchivo(archivoDestino);

    return 0;
}
