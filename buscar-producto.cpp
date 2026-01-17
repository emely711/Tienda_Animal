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

void buscarProducto() {
    if (productos.empty()) {
        cout << "La lista de productos está vacía\n";
        return;
    }
    string nombreBuscado;
    cin.ignore();
    cout << "Nombre a buscar: ";
    getline(cin, nombreBuscado);
    for (const auto& producto : productos) {
        if (producto.nombre == nombreBuscado) {
            cout << "============================\n";
            cout << "Codigo: " << producto.codigo << endl;
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Precio: " << producto.precio << endl;
            cout << "Stock: " << producto.stock << endl;
            cout << "============================\n";
            return;
        }
    }
    cout << "Producto no encontrado\n";
}

int main(){
	buscarProducto();
	
	return 0;
}
