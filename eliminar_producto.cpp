#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct Usuario {
    string usuario;
    string contrasena;
};

struct Producto {
    string codigo;
    string nombre;
    float precio;
    int stock;
};

vector<Usuario> listaUsuarios;
vector<Producto> productos;

void eliminarProducto() {
    if (productos.empty()) {
        cout << "La lista de productos está vacía\n";
        return;
    }
    string codigoEliminar;
    cout << "Codigo a eliminar: ";
    cin >> codigoEliminar;
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i].codigo == codigoEliminar) {
            productos.erase(productos.begin() + i);
            cout << "Producto eliminado\n";
            return;
        }
    }
    cout << "Codigo no encontrado\n";
}
int main() {
    eliminarProducto();

	return 0;
	
}
