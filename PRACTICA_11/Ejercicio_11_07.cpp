/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 7
// Problema planteado: Promedio de calificaciones por estudiante
Descripción: Escribe un programa que lea un archivo calificaciones.txt,
donde cada línea contiene el nombre de un estudiante seguido de varias
calificaciones. El programa debe calcular el promedio de cada estudiante y
escribirlo en un archivo promedios.txt en el formato Nombre Promedio.
Formato del archivo de entrada (calificaciones.txt):
juan 6.0 7.8 5.6 
Ana 6.5 3.4 9.9 
Luis 5.5 9.9 8.8 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void procesarCalificaciones(const string& archivoOrigen, const string& archivoDestino) 
{
    ifstream entradaCalificaciones(archivoOrigen);
    if (!entradaCalificaciones) {
        cout << "Error: No se pudo abrir el archivo de entrada." << endl;
        return;
    }

    ofstream salidaPromedios(archivoDestino);
    if (!salidaPromedios) {
        cout << "Error: No se pudo crear el archivo de salida." << endl;
        return;
    }

    string linea, estudiante;
    float nota, totalNotas, promedio;
    int cantidadNotas;

    while (getline(entradaCalificaciones, linea)) {
        stringstream flujo(linea);
        flujo >> estudiante; 

        totalNotas = 0;
        cantidadNotas = 0;

        while (flujo >> nota) {
            totalNotas += nota;
            cantidadNotas++;
        }

        if (cantidadNotas > 0) {
            promedio = totalNotas / cantidadNotas;
            salidaPromedios << estudiante << " " << promedio << endl;
        } else {
            cout << "Advertencia: No se encontraron notas para " << estudiante << endl;
        }
    }

    entradaCalificaciones.close();
    salidaPromedios.close();

    cout << "Cálculo de promedios completado. Resultados guardados en " << archivoDestino << "." << endl;
}

int main()
 {
    string archivoEntrada = "calificaciones.txt";
    string archivoSalida = "promedios.txt";

    procesarCalificaciones(archivoEntrada, archivoSalida);

    return 0;
}
