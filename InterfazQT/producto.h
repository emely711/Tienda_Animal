#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QAbstractItemModel>
#include <vector>
#include<string>

struct Producto{
    std::string codigo;
    std::string nombre;
    float precio;
    int stock;
};

extern std::vector<Producto> productos;

bool soloLetras(const std::string &texto);
bool codigoDuplicado(const std::string &codigo);
void guardarProductos();
void cargarProductos();

class producto : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit producto(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // PRODUCTO_H
