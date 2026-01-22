#include "producto.h"

#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QStringList>
#include <QVariant>
#include <cctype>

// ================= VECTOR GLOBAL =================
std::vector<Producto> productos;

// ================= GUARDAR =================
void guardarProductos()
{
    QFile archivo(QCoreApplication::applicationDirPath() + "/productos.txt");

    if (!archivo.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&archivo);

    const Producto &p = productos.back();

    out << QString::fromStdString(p.codigo) << " "
        << QString::fromStdString(p.nombre) << " "
        << p.precio << " "
        << p.stock << "\n";

    archivo.close();
}

// ================= VALIDACIONES =================
bool soloLetras(const std::string &texto)
{
    if (texto.empty()) return false;

    for (char c : texto) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ')
            return false;
    }
    return true;
}

bool codigoDuplicado(const std::string &codigo)
{
    for (const auto &p : productos) {
        if (p.codigo == codigo)
            return true;
    }
    return false;
}

// ================= CARGAR =================
void cargarProductos()
{
    productos.clear();

    QFile archivo(QCoreApplication::applicationDirPath() + "/productos.txt");

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&archivo);

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (linea.isEmpty()) continue;

        QStringList datos = linea.split(" ", Qt::SkipEmptyParts);
        if (datos.size() < 4) continue;

        Producto p;
        p.codigo = datos[0].toStdString();
        p.nombre = datos[1].toStdString();
        p.precio = datos[2].toFloat();
        p.stock = datos[3].toInt();

        productos.push_back(p);
    }

    archivo.close();
}

// ================= MODELO =================
producto::producto(QObject *parent)
    : QAbstractItemModel(parent)
{
    cargarProductos();
}

int producto::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return productos.size();
}

int producto::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 4;
}

QVariant producto::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    const Producto &p = productos[index.row()];

    switch (index.column()) {
    case 0: return QString::fromStdString(p.codigo);
    case 1: return QString::fromStdString(p.nombre);
    case 2: return p.precio;
    case 3: return p.stock;
    }

    return QVariant();
}

QVariant producto::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
    case 0: return "Código";
    case 1: return "Nombre";
    case 2: return "Precio";
    case 3: return "Stock";
    }

    return QVariant();
}

QModelIndex producto::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid())
        return QModelIndex();

    return createIndex(row, column);
}

QModelIndex producto::parent(const QModelIndex &) const
{
    return QModelIndex();
}
