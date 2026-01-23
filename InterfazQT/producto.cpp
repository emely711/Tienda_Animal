#include "producto.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <cctype>

static QString rutaProductos() {
    QString carpeta = QDir::homePath() + "/Documents/InterfazQT";
    QDir().mkpath(carpeta);
    return carpeta + "/productos.txt";
}

bool soloLetras(const std::string &texto) {
    for (char c : texto) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool codigoDuplicado(const std::string &codigo) {
    QFile archivo(rutaProductos());
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&archivo);
    while (!in.atEnd()) {
        if (in.readLine().startsWith(QString::fromStdString(codigo) + ";"))
            return true;
    }
    return false;
}

void guardarProducto(const Producto &p) {
    QFile archivo(rutaProductos());
    if (!archivo.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&archivo);
    out << QString::fromStdString(p.codigo) << ";"
        << QString::fromStdString(p.nombre) << ";"
        << p.precio << ";"
        << p.stock << "\n";
}
