/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 2
// Problema planteado: Contador de palabras en un archivo
Descripción: Escribe un programa que lea un archivo de texto llamado
texto.txt y cuente cuántas palabras contiene. Una "palabra" se define como
cualquier secuencia de caracteres separada por espacios o saltos de línea.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int numPalabras(const string& archivo);
void conteo(const string& archivo);

int main() {
    string archivoTexto = "texto.txt";
    conteo(archivoTexto);
    return 0;
}

int numPalabras(const string& archivo) 
{
    ifstream entrada(archivo);
    if (!entrada) {
        return -1;
    }

    string token;
    int cantidadPalabras = 0;

    while (entrada >> token) {
        cantidadPalabras++;
    }

    entrada.close();
    return cantidadPalabras;
}

void conteo(const string& archivo) 
{
    int totalPalabras = numPalabras(archivo);
    if (totalPalabras == -1) {
        cout << "No se pudo acceder al archivo: " << archivo << endl;
    } else {
        cout << "El archivo \"" << archivo << "\" tiene " << totalPalabras << " palabras." << endl;
    }
}
