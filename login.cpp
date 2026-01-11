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

void guardarUsuarios() {
    ofstream archivoUsuarios("usuarios.txt");
    for (const auto& usuario : listaUsuarios) {
        archivoUsuarios << usuario.usuario << " " << usuario.contrasena << "\n";
    }
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

void registrar() {
    Usuario nuevoUsuario;
    cout << "Nuevo usuario: ";
    cin >> nuevoUsuario.usuario;
    for (const auto& usuario : listaUsuarios) {
        if (usuario.usuario == nuevoUsuario.usuario) {
            cout << "Error: El usuario ya existe\n";
            return;
        }
    }
    cout << "Nueva contrasena: ";
    cin >> nuevoUsuario.contrasena;
    listaUsuarios.push_back(nuevoUsuario);
    guardarUsuarios();
    cout << "Usuario registrado correctamente\n";
}

int main() {
    cargarUsuarios();

    if (listaUsuarios.empty()) {
        cout << "No hay usuarios registrados. Debes crear uno.\n";
        registrar();
    }

    cout << "==== LOGIN ====\n";
    if (login()) {
        cout << "Login exitoso!\n";
    } else {
        cout << "Usuario o contrasena incorrectos.\n";
    }

    return 0;
}
