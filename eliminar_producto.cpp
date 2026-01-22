#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    float precio;
    int stock;
};

void eliminarProducto() {
    cout << "============================\n";
    cout << "ELIMINAR PRODUCTO\n";
    cout << "============================\n";

    string codigo;
    cout << "Codigo a eliminar: ";
    cin >> codigo;

    ifstream archivo("productos.txt");
    ofstream temp("temp.txt");
    Producto p;
    bool encontrado = false;

    while (archivo >> p.codigo >> p.nombre >> p.precio >> p.stock) {
        if (p.codigo == codigo) {
            encontrado = true;
            continue; 
        }
        temp << p.codigo << " " << p.nombre << " "
             << p.precio << " " << p.stock << "\n";
    }

    archivo.close();
    temp.close();

    remove("productos.txt");
    rename("temp.txt", "productos.txt");

    if (encontrado) {
        cout << "Producto eliminado correctamente!\n";
    } else {
        cout << "Codigo no encontrado\n";
    }
}

int main() {
    char opcion;

    do {
        eliminarProducto();

        cout << "Desea eliminar otro producto? (s/n): ";
        cin >> opcion;
    } while(opcion == 's' || opcion == 'S');

    return 0;
}
