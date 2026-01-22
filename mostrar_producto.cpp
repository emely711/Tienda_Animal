#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    float precio;
    int stock;
};

bool soloLetras(const string& texto) {
    for (char c : texto) {
        if (!isalpha(c) && c != ' ')
            return false;
    }
    return !texto.empty();
}

bool soloNumeros(const string& texto) {
    if (texto.empty()) return false;
    for (char c : texto) {
        if (!isdigit(c))
            return false;
    }
    return true;
}


bool codigoDuplicado(const string& codigo) {
    ifstream archivo("productos.txt");
    Producto p;
    while (archivo >> p.codigo >> p.nombre >> p.precio >> p.stock) {
        if (p.codigo == codigo) {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

void agregarProducto() {
    Producto p;
    string stockStr;

    cout << "============================\n";
    cout << "AGREGAR PRODUCTO\n";
    cout << "============================\n";

    do {
        cout << "Codigo: ";
        cin >> p.codigo;
        if (codigoDuplicado(p.codigo))
            cout << "Error: El codigo ya existe\n";
    } while (codigoDuplicado(p.codigo));

    cin.ignore();
    do {
        cout << "Nombre: ";
        getline(cin, p.nombre);
        if (!soloLetras(p.nombre))
            cout << "Error: Solo ingrese letras\n";
    } while (!soloLetras(p.nombre));

    do {
        cout << "Precio: ";
        cin >> p.precio;
        if (cin.fail() || p.precio < 0) {
            cout << "Error: Solo ingrese numeros\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (cin.fail() || p.precio < 0);

    do {
        cout << "Stock: ";
        cin >> stockStr;
        if (!soloNumeros(stockStr))
            cout << "Error: El stock solo puede contener numeros enteros\n";
    } while (!soloNumeros(stockStr));

    p.stock = stoi(stockStr);

    ofstream archivo("productos.txt", ios::app);
    archivo << p.codigo << " " << p.nombre << " "
            << p.precio << " " << p.stock << "\n";
    archivo.close();

    cout << "Producto agregado correctamente!\n";
}

void mostrarProductos() {
    cout << "============================\n";
    cout << "LISTA DE PRODUCTOS\n";
    cout << "============================\n";

    ifstream archivo("productos.txt");
    Producto p;
    bool hayProductos = false;

    while (archivo >> p.codigo >> p.nombre >> p.precio >> p.stock) {
        hayProductos = true;
        cout << "----------------------------\n";
        cout << "Codigo: " << p.codigo << endl;
        cout << "Nombre: " << p.nombre << endl;
        cout << "Precio: " << p.precio << endl;
        cout << "Stock: " << p.stock << endl;
    }

    if (!hayProductos) {
        cout << "No hay productos\n";
    }

    archivo.close();
}

int main() {
    int opcion;

    do {
        cout << "============================\n";
        cout << "MUNDO MASCOTA\n";
        cout << "============================\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: agregarProducto(); break;
            case 2: mostrarProductos(); break;
            case 3: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }

    } while(opcion != 3);

    return 0;
}
