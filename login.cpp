
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Usuario {
    string usuario;
    string contrasena;
};

vector<Usuario> listaUsuarios;

void cargarUsuarios() {
    listaUsuarios.clear();
    ifstream archivoUsuarios("usuarios.txt");
    Usuario usuarioActual;
    while (archivoUsuarios >> usuarioActual.usuario >> usuarioActual.contrasena) {
        listaUsuarios.push_back(usuarioActual);
    }
    archivoUsuarios.close();
}

bool login() {
    string usuarioIngresado, contrasenaIngresada;
    cout << "Usuario: ";
    cin >> usuarioIngresado;
    cout << "Contrasena: ";
    cin >> contrasenaIngresada;
    for (const auto& usuario : listaUsuarios) {
        if (usuario.usuario == usuarioIngresado && usuario.contrasena == contrasenaIngresada) {
            return true;
        }
    }
    return false;
}

int main() {
    cargarUsuarios();
    if (listaUsuarios.empty()) {
        cout << "No hay usuarios registrados en el sistema.\n";
        return 0;
    }

    if (login()) {
        cout << "Login exitoso!\n";
    } else {
        cout << "Usuario o contrasena incorrectos."<<endl;
    }

    return 0;
}
