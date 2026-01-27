#include <iostream>
#include <fstream>
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

bool login() {
    string u, c;
    cout << "Usuario: ";
    cin >> u;
    cout << "Contrasena: ";
    cin >> c;

    if (u == "admin1" && c == "hola123") {
        return true;
    }

    cout << "Usuario o contrasena incorrectos\n";
    return false;
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

void buscarProducto() {
    cout << "============================\n";
    cout << "BUSCAR PRODUCTO\n";
    cout << "============================\n";

    string nombre;
    cin.ignore();
    cout << "Nombre a buscar: ";
    getline(cin, nombre);

    ifstream archivo("productos.txt");
    Producto p;
    bool encontrado = false;

    while (archivo >> p.codigo >> p.nombre >> p.precio >> p.stock) {
        if (p.nombre == nombre) {
            cout << "----------------------------\n";
            cout << "Codigo: " << p.codigo << endl;
            cout << "Precio: " << p.precio << endl;
            cout << "Stock: " << p.stock << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado\n";
    }

    archivo.close();
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

    if (!encontrado) {
        cout << "Codigo no encontrado\n";
    }
}

void eliminarProducto() {
    cout << "============================\n";
    cout << "ELIMINAR PRODUCTO\n";
    cout << "============================\n";

    string codigo;
    cout << "Codigo a eliminar: ";
    cin >> codigo;

    ifstream archivo("productos.txt");
    ofstream temp("temp.txt");
    Producto p;
    bool encontrado = false;

    while (archivo >> p.codigo >> p.nombre >> p.precio >> p.stock) {
        if (p.codigo == codigo) {
            encontrado = true;
            continue; // no copiar al archivo temporal
        }
        temp << p.codigo << " " << p.nombre << " "
             << p.precio << " " << p.stock << "\n";
    }

    archivo.close();
    temp.close();

    remove("productos.txt");
    rename("temp.txt", "productos.txt");

    if (!encontrado) {
        cout << "Codigo no encontrado\n";
    }
}

int main() {
    int opcion;
    do {
        cout << "============================\n";
        cout << "MUNDO MASCOTA\n";
        cout << "============================\n";
        cout << "1. Login\n";
        cout << "2. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            if (login()) {
                int menu;
                do {
                    cout << "============================\n";
                    cout << "MENU PRODUCTOS\n";
                    cout << "============================\n";
                    cout << "1. Agregar\n";
                    cout << "2. Mostrar\n";
                    cout << "3. Buscar\n";
                    cout << "4. Actualizar\n";
                    cout << "5. Eliminar\n";
                    cout << "6. Salir\n";
                    cout << "Opcion: ";
                    cin >> menu;

                    switch (menu) {
                        case 1: agregarProducto(); break;
                        case 2: mostrarProductos(); break;
                        case 3: buscarProducto(); break;
                        case 4: actualizarProducto(); break;
                        case 5: eliminarProducto(); break;
                    }
                } while (menu != 6);
            }
        }
    } while (opcion != 2);

    return 0;
}
