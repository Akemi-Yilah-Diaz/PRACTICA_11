/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 3
// Problema planteado: Almacenamiento de registros de estudiantes
Descripción: Escribe un programa que permita registrar la información de
varios estudiantes en un archivo de texto llamado estudiantes.txt. Cada
estudiante debe tener un nombre, una edad y un promedio de
calificaciones. Luego, el programa debe poder leer el archivo y mostrar toda
la información de los estudiantes en un formato organizado.
formato:
Nombre:
Edad:
Promedio:
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void agregarEstudiante(const string& archivoEstudiantes) 
{
    ofstream archivo(archivoEstudiantes, ios::app);
    if (!archivo) {
        cout << "No fue posible abrir el archivo." << endl;
        return;
    }

    string nombreCompleto;
    int edadEstudiante;
    float calificacionPromedio;

    cout << "Escribe el nombre completo del estudiante: ";
    cin.ignore();
    getline(cin, nombreCompleto);

    cout << "Escribe la edad del estudiante: ";
    cin >> edadEstudiante;

    cout << "Escribe el promedio del estudiante: ";
    cin >> calificacionPromedio;

    archivo << nombreCompleto << "," << edadEstudiante << "," << calificacionPromedio << endl;

    archivo.close();
    cout << "El estudiante se registró correctamente." << endl;
}

void listarEstudiantes(const string& archivoEstudiantes)
 {
    ifstream archivo(archivoEstudiantes);
    if (!archivo) {
        cout << "No fue posible abrir el archivo." << endl;
        return;
    }

    string registro;
    cout << "\nLista de estudiantes registrados:" << endl;
    cout << "----------------------------------" << endl;

    while (getline(archivo, registro)) {
        size_t pos1 = registro.find(',');
        size_t pos2 = registro.find_last_of(',');

        string nombreCompleto = registro.substr(0, pos1);
        int edadEstudiante = stoi(registro.substr(pos1 + 1, pos2 - pos1 - 1));
        float calificacionPromedio = stof(registro.substr(pos2 + 1));

        cout << "Nombre: " << nombreCompleto << endl;
        cout << "Edad: " << edadEstudiante << endl;
        cout << "Promedio: " << calificacionPromedio << endl;
        cout << "----------------------------------" << endl;
    }

    archivo.close();
}

void iniciarMenu() 
{
    string archivoEstudiantes = "estudiantes.txt";
    int eleccion;

    do {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Agregar un estudiante" << endl;
        cout << "2. Ver lista de estudiantes" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> eleccion;

        switch (eleccion) {
            case 1:
                agregarEstudiante(archivoEstudiantes);
                break;
            case 2:
                listarEstudiantes(archivoEstudiantes);
                break;
            case 3:
                cout << "\nSaliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, intenta de nuevo." << endl;
        }
    } while (eleccion != 3);
}

int main() 
{
    iniciarMenu();
    return 0;
}
