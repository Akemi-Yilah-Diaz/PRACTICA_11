/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 1
// Problema planteado: Escritura y lectura básica de archivos
Descripción: Escribe un programa que pida al usuario ingresar una lista de
nombres y guarde cada nombre en un archivo de texto llamado
nombres.txt. Después, el programa debe leer el archivo y mostrar todos los
nombres en la consola.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void mostrarNombres(const string& archivo);
vector<string> pedirNombres(int cantidad);
void guardarEnArchivo(const vector<string>& nombres, const string& archivo);

int main() 
{
    int cantidad;
    cout << "¿Cuántos nombres quieres guardar? ";
    cin >> cantidad;
    cin.ignore();

    vector<string> nombres = pedirNombres(cantidad);

    string archivo = "nombres.txt";
    guardarEnArchivo(nombres, archivo);
    mostrarNombres(archivo);

    return 0;
}

vector<string> pedirNombres(int cantidad) 
{
    vector<string> nombres(cantidad);
    for (int i = 0; i < cantidad; i++) {
        cout << "Dime un nombre: ";
        getline(cin, nombres[i]);
    }
    return nombres;
}

void guardarEnArchivo(const vector<string>& nombres, const string& archivo) {
    ofstream salida(archivo);
    for (int i = 0; i < nombres.size(); i++) {
        salida << nombres[i] << endl;
    }
    salida.close();
}

void mostrarNombres(const string& archivo)
{
    ifstream entrada(archivo);
    vector<string> nombres;
    string nombre;
    while (getline(entrada, nombre)) {
        nombres.push_back(nombre);
    }
    entrada.close();

    cout << "Estos son los nombres que guardaste:" << endl;
    for (int i = 0; i < nombres.size(); i++) {
        cout << nombres[i] << endl;
    }
}
