#include "mostrar.h"
#include "ui_mostrar.h"
#include "producto.h"
#include "agregar.h"

#include <QFile>
#include <QTextStream>
#include <QDir>

mostrar::mostrar(QWidget *parent)
    : QDialog(parent), ui(new Ui::mostrar)
{
    ui->setupUi(this);

    ui->tablaProductos->setColumnCount(4);
    ui->tablaProductos->setHorizontalHeaderLabels(
        {"Código", "Nombre", "Precio", "Stock"}
        );

    cargarProductos();
}

mostrar::~mostrar() {
    delete ui;
}

void mostrar::cargarProductos()
{
    ui->tablaProductos->setRowCount(0);

    QString ruta = QDir::homePath() + "/Documents/InterfazQT/productos.txt";
    QFile archivo(ruta);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&archivo);
    int fila = 0;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (linea.isEmpty()) continue;

        QStringList campos = linea.split(";");
        if (campos.size() != 4) continue;

        ui->tablaProductos->insertRow(fila);
        ui->tablaProductos->setItem(fila, 0, new QTableWidgetItem(campos[0]));
        ui->tablaProductos->setItem(fila, 1, new QTableWidgetItem(campos[1]));
        ui->tablaProductos->setItem(fila, 2, new QTableWidgetItem(campos[2]));
        ui->tablaProductos->setItem(fila, 3, new QTableWidgetItem(campos[3]));

        fila++;
    }

    archivo.close();
}

void mostrar::on_salir_clicked() {
    close();
}

void mostrar::on_agregarButton_clicked()
{
    agregar ventanaAgregar(this);
    ventanaAgregar.exec();
    cargarProductos();
}
