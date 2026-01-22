#include "mostrar.h"
#include "ui_mostrar.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QCoreApplication>

mostrar::mostrar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mostrar)
{
    ui->setupUi(this);

    QFile archivo(QCoreApplication::applicationDirPath() + "/productos.txt");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo");
        return;
    }

    QTextStream in(&archivo);
    int fila = 0;

    ui->tablaProductos->setColumnCount(4);
    QStringList headers = {"Código", "Nombre", "Precio", "Stock"};
    ui->tablaProductos->setHorizontalHeaderLabels(headers);

    ui->tablaProductos->setRowCount(0);

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (linea.isEmpty()) continue;

        
        QStringList campos = linea.split(" ", Qt::SkipEmptyParts);

        if (campos.size() < 4) continue;

        ui->tablaProductos->insertRow(fila);

        ui->tablaProductos->setItem(fila, 0, new QTableWidgetItem(campos[0]));
        ui->tablaProductos->setItem(fila, 1, new QTableWidgetItem(campos[1]));
        ui->tablaProductos->setItem(fila, 2, new QTableWidgetItem(campos[2]));
        ui->tablaProductos->setItem(fila, 3, new QTableWidgetItem(campos[3]));

        fila++;
    }

    archivo.close();
}

mostrar::~mostrar()
{
    delete ui;
}


void mostrar::on_salir_clicked()
{
    close();
}


