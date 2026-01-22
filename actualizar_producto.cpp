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

void actualizarProducto() {
    cout << "============================\n";
    cout << "ACTUALIZAR PRODUCTO\n";
    cout << "============================\n";

    string codigo, stockStr;
    cout << "Codigo a actualizar: ";
    cin >> codigo;

    ifstream archivo("productos.txt");
    ofstream temp("temp.txt");
    Producto p;
    bool encontrado = false;

    while (archivo >> p.codigo >> p.nombre >> p.precio >> p.stock) {
        if (p.codigo == codigo) {
            encontrado = true;

            cin.ignore();
            do {
                cout << "Nuevo nombre: ";
                getline(cin, p.nombre);
                if (!soloLetras(p.nombre))
                    cout << "Error: Solo ingrese letras\n";
            } while (!soloLetras(p.nombre));

            do {
                cout << "Nuevo precio: ";
                cin >> p.precio;
                if (cin.fail() || p.precio < 0) {
                    cout << "Error: Solo ingrese numeros\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            } while (cin.fail() || p.precio < 0);

            do {
                cout << "Nuevo stock: ";
                cin >> stockStr;
                if (!soloNumeros(stockStr))
                    cout << "Error: El stock solo puede contener numeros enteros\n";
            } while (!soloNumeros(stockStr));

            p.stock = stoi(stockStr);
        }

        temp << p.codigo << " " << p.nombre << " "
             << p.precio << " " << p.stock << "\n";
    }

    archivo.close();
    temp.close();

    remove("productos.txt");
    rename("temp.txt", "productos.txt");

    if (encontrado) {
        cout << "Producto actualizado correctamente!\n";
    } else {
        cout << "Codigo no encontrado\n";
    }
}

int main() {
    char opcion;

    do {
        actualizarProducto();

        cout << "Desea actualizar otro producto? (s/n): ";
        cin >> opcion;
        cin.ignore();
    } while(opcion == 's' || opcion == 'S');

    return 0;
}
