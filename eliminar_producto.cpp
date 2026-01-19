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
    cout << "============================\n";
    cout << "ELIMINAR PRODUCTO\n";
    cout << "============================\n";

    string codigo;
    cout << "Codigo a eliminar: ";
    cin >> codigo;

    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i].codigo == codigo) {
            productos.erase(productos.begin() + i);
            guardarProductos();
            return;
        }
    }
    cout << "Codigo no encontrado\n";
}

int main() {
    eliminarProducto();

	return 0;
	
}
