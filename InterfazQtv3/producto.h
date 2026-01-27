#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

struct Producto {
    std::string codigo;
    std::string nombre;
    float precio;
    int stock;
};

bool letrasYEspacios(const std::string &texto);
bool soloLetras(const std::string &texto);
bool codigoDuplicado(const std::string &codigo);


void guardarProducto(const Producto &p);

#endif
