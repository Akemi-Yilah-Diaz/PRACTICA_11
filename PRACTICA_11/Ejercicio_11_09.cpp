/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 9
// Problema planteado: Cifrado de un archivo de texto (Cifrado César)
Descripción: Escribe un programa que lea un archivo mensaje.txt, realice
un cifrado César con un desplazamiento de 3 sobre el texto y guarde el
resultado en un archivo mensaje_cifrado.txt. El cifrado César desplaza cada
letra por un número fijo de posiciones en el alfabeto (por ejemplo, A se
convierte en D, B en E, etc.)
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void aplicarCifradoCesar(const string& archivoEntrada, const string& archivoDestino) {
    ifstream archivoOriginal(archivoEntrada);
    if (!archivoOriginal) {
        return;
    }

    ofstream archivoCifrado(archivoDestino);
    if (!archivoCifrado) {
        return;
    }

    string textoLinea;
    const int desplazamiento = 3;

    while (getline(archivoOriginal, textoLinea)) {
        for (char& letra : textoLinea) {
            if (isupper(letra)) {
                letra = (letra - 'A' + desplazamiento) % 26 + 'A';
            } else if (islower(letra)) {
                letra = (letra - 'a' + desplazamiento) % 26 + 'a';
            }
        }

        archivoCifrado << textoLinea << endl;
    }

    archivoOriginal.close();
    archivoCifrado.close();
    cout << "El texto ha sido cifrado correctamente y guardado en " << archivoDestino << endl;
}

int main() {
    string archivoEntrada = "mensaje.txt";
    string archivoDestino = "mensaje_cifrado.txt";

    aplicarCifradoCesar(archivoEntrada, archivoDestino);

    return 0;
}
