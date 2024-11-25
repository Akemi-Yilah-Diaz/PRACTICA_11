/*
// Materia: Programacion I, Paralelo 1
// Autor: Akemi Yilah Machicado Diaz
// Fecha creaciC3n: 25/11/2024
// Numero de ejercicio: 5
// Problema planteado: Actualizar datos en un archivo
Descripción: Escribe un programa que permita actualizar un archivo de
texto llamado productos.txt, el cual contiene una lista de productos y sus
precios. Cada línea del archivo tiene el formato Producto Precio (por
ejemplo, Manzana 1.50). El programa debe permitir al usuario ingresar el
nombre de un producto y el nuevo precio, y actualizar ese precio en el
archivo. Si el producto no se encuentra, debe indicar que no existe.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void modificarPrecio(const string& archivoProductos) {
    ifstream archivoEntrada(archivoProductos);
    if (!archivoEntrada) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    vector<string> listaProductos;
    vector<float> listaPrecios;
    string nombreProducto, productoABuscar;
    float precioActual, nuevoPrecio;
    bool encontrado = false;

    cout << "Ingrese el nombre del producto a modificar: ";
    cin >> productoABuscar;
    cout << "Ingrese el nuevo precio: ";
    cin >> nuevoPrecio;

    while (archivoEntrada >> nombreProducto >> precioActual) {
        listaProductos.push_back(nombreProducto);
        listaPrecios.push_back(precioActual);
    }

    archivoEntrada.close();

    for (int i = 0; i < listaProductos.size(); ++i)
     {
        if (listaProductos[i] == productoABuscar) {
            listaPrecios[i] = nuevoPrecio;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "El producto \"" << productoABuscar << "\" no está en el archivo." << endl;
        return;
    }

    ofstream archivoSalida(archivoProductos);
    for (int i = 0; i < listaProductos.size(); ++i) 
    {
        archivoSalida << listaProductos[i] << " " << listaPrecios[i] << endl;
    }

    archivoSalida.close();
    cout << "El precio del producto \"" << productoABuscar << "\" ha sido actualizado a " << nuevoPrecio << "." << endl;
}

void verProductos(const string& archivoProductos)
 {
    ifstream archivo(archivoProductos);
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string nombreProducto;
    float precio;

    cout << "Lista de productos y precios:" << endl;
    while (archivo >> nombreProducto >> precio) {
        cout << nombreProducto << ": " << precio << endl;
    }

    archivo.close();
}

int main() 
{
    string archivoProductos = "productos.txt";
    int opcion;

    do {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Ver productos y precios" << endl;
        cout << "2. Modificar precio de un producto" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                verProductos(archivoProductos);
                break;
            case 2:
                modificarPrecio(archivoProductos);
                break;
            case 3:
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}
