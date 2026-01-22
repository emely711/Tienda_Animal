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

int main() {
    char opcion;

    do {
        agregarProducto();

        cout << "Desea agregar otro producto? (s/n): ";
        cin >> opcion;
        cin.ignore();
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
