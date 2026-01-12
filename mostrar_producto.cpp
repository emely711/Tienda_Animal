#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    float precio;
    int stock;
};

vector<Producto> productos;

void mostrarProductos() {
    if (productos.empty()) {
        cout << "La lista de productos está vacía\n";
        return;
    }
    for (const auto& producto : productos) {
        cout << "============================\n";
        cout << "Codigo: " << producto.codigo << endl;
        cout << "Nombre: " << producto.nombre << endl;
        cout << "Precio: " << producto.precio << endl;
        cout << "Stock: " << producto.stock << endl;
        cout << "============================\n";
    }
}

int main() {
    mostrarProductos();
    return 0;
}
