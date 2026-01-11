#include <iostream>
#include <fstream>
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

void cargarProductos() {
    productos.clear();
    ifstream archivoProductos("productos.txt");
    Producto productoActual;
    while (archivoProductos >> productoActual.codigo >> productoActual.nombre >> productoActual.precio >> productoActual.stock) {
        productos.push_back(productoActual);
    }
    archivoProductos.close();
}

void guardarProductos() {
    ofstream archivoProductos("productos.txt");
    for (const auto& producto : productos) {
        archivoProductos << producto.codigo << " " << producto.nombre << " " << producto.precio << " " << producto.stock << "\n";
    }
}

bool codigoDuplicado(const string& codigo) {
    for (const auto& producto : productos) {
        if (producto.codigo == codigo)
            return true;
    }
    return false;
}

void agregarProducto() {
    Producto nuevoProducto;
    cargarProductos();
    do {
        cout << "Codigo: ";
        cin >> nuevoProducto.codigo;
        if (codigoDuplicado(nuevoProducto.codigo)) {
            cout << "Error: El codigo ya existe. Intenta otro.\n";
        }
    } while (codigoDuplicado(nuevoProducto.codigo));

    cin.ignore();
    do {
        cout << "Nombre: ";
        getline(cin, nuevoProducto.nombre);
        if (!soloLetras(nuevoProducto.nombre)) {
            cout << "Error: El nombre solo puede contener letras y espacios.\n";
        }
    } while (!soloLetras(nuevoProducto.nombre));

    do {
        cout << "Precio: ";
        cin >> nuevoProducto.precio;
        if (nuevoProducto.precio < 0) {
            cout << "Error: El precio no puede ser negativo.\n";
        }
    } while (nuevoProducto.precio < 0);

    do {
        cout << "Stock: ";
        cin >> nuevoProducto.stock;
        if (nuevoProducto.stock < 0) {
            cout << "Error: El stock no puede ser negativo.\n";
        }
    } while (nuevoProducto.stock < 0);

    productos.push_back(nuevoProducto);
    guardarProductos();
    cout << "Producto agregado correctamente.\n";
}

int main() {
    agregarProducto();
    return 0;
}

