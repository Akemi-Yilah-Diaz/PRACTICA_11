/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 6
// Problema planteado: Descripción: Escribe un programa que lea un archivo de texto llamado
temperaturas.txt, donde cada línea contiene el nombre de una ciudad
seguido de su temperatura promedio del día. El programa debe generar un
archivo altas_temperaturas.txt que solo incluya las ciudades con
temperaturas superiores a N°C.
Formato del archivo de entrada (temperaturas.txt):
madrid:
barcelona:
sevilla:
valencia:....
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void filtrarCalor(const string& archivoOrigen, const string& archivoDestino, float temperaturaLimite)
 {
    ifstream archivoOriginal(archivoOrigen);
    if (!archivoOriginal) {
        cout << "No se pudo abrir el archivo original." << endl;
        return;
    }

    ofstream archivoResultado(archivoDestino);
    if (!archivoResultado) {
        cout << "No se pudo crear el archivo de resultados." << endl;
        return;
    }

    string ciudad;
    float temperatura;

    while (archivoOriginal >> ciudad >> temperatura) {
        if (temperatura > temperaturaLimite) {
            archivoResultado << ciudad << ": " << temperatura << endl;
        }
    }

    archivoOriginal.close();
    archivoResultado.close();

    cout << "Se ha generado el archivo \"" << archivoDestino << "\" con las ciudades que superan los " 
         << temperaturaLimite << "°C." << endl;
}

int main() 
{
    string archivoEntrada = "temperaturas.txt";
    string archivoSalida = "ciudades_calientes.txt";
    float limiteTemperatura = 30.0;

    filtrarCalor(archivoEntrada, archivoSalida, limiteTemperatura);

    return 0;
}
