#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    float precio;
    int stock;
};

vector<Producto> productos;

bool soloLetras(const string& str) {
    for (char c : str) {
        if (!isalpha(c) && c != ' ')
            return false;
    }
    return !str.empty();
}

void actualizarProducto() {
    if (productos.empty()) {
        cout << "La lista de productos está vacía\n";
        return;
    }

    string codigoActualizar;
    cout << "Codigo a actualizar: ";
    cin >> codigoActualizar;

    for (auto& producto : productos) {
        if (producto.codigo == codigoActualizar) {
            cin.ignore();
            do {
                cout << "Nuevo nombre: ";
                getline(cin, producto.nombre);
            } while (!soloLetras(producto.nombre));

            do {
                cout << "Nuevo precio: ";
                cin >> producto.precio;
            } while (producto.precio < 0);

            do {
                cout << "Nuevo stock: ";
                cin >> producto.stock;
            } while (producto.stock < 0);

            cout << "Producto actualizado\n";
            return;
        }
    }
    cout << "Codigo no encontrado\n";
}

int main() {
    actualizarProducto();
    return 0;
}
