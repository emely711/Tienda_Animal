#include <iostream>
#include <fstream>
#include <vector>

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
    cout << "============================\n";
    cout << "BUSCAR PRODUCTO\n";
    cout << "============================\n";

    if (productos.empty()) {
        cout << "No hay productos\n";
        return;
    }

    string nombre;
    cin.ignore();
    cout << "Nombre a buscar: ";
    getline(cin, nombre);

    for (const auto& p : productos) {
        if (p.nombre == nombre) {
            cout << "----------------------------\n";
            cout << "Codigo: " << p.codigo << endl;
            cout << "Precio: " << p.precio << endl;
            cout << "Stock: " << p.stock << endl;
            return;
        }
    }
    cout << "Producto no encontrado\n";
}

int main(){
	
	buscarProducto();
	return 0;
}
