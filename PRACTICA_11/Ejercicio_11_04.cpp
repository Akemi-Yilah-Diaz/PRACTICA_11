/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 4
// Problema planteado: Búsqueda de texto en un archivo
Descripción: Escribe un programa que lea un archivo de texto llamado
datos.txt y permita al usuario buscar una palabra o frase específica. El
programa debe contar y mostrar cuántas veces aparece esa palabra o frase
en el archivo.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int contarOcurrencias(const string& archivoTexto, const string& palabraClave) 
{
    ifstream archivo(archivoTexto);
    if (!archivo) {
        cout << "no se pudo abrir el archivo" << endl;
        return -1;
    }

    string palabraActual;
    int totalOcurrencias = 0;

    while (archivo >> palabraActual) {
        if (palabraActual == palabraClave) {
            totalOcurrencias++;
        }
    }

    archivo.close();
    return totalOcurrencias;
}

int main() {
    string archivoTexto = "datos.txt";
    string palabraClave;

    cout << "Qué palabra deseas buscar en el archivo? ";
    cin >> palabraClave;

    int ocurrencias = contarOcurrencias(archivoTexto, palabraClave);

    if (ocurrencias >= 0) {
        cout << "La palabra \"" << palabraClave << "\" aparece " << ocurrencias << " veces en el archivo." << endl;
    }

    return 0;
}
