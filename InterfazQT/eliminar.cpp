#include "eliminar.h"
#include "ui_eliminar.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDir>

eliminar::eliminar(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::eliminar)
{
    ui->setupUi(this);
}

eliminar::~eliminar()
{
    delete ui;
}

void eliminar::on_eliminar_2_clicked()
{
    QString codigoEliminar = ui->codigo->text().trimmed();

    if (codigoEliminar.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese el código");
        return;
    }

    QString ruta = QDir::homePath() + "/Documents/InterfazQT/productos.txt";
    QFile archivo(ruta);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo");
        return;
    }

    QTextStream in(&archivo);
    QStringList lineas;
    bool eliminado = false;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (linea.isEmpty()) continue;

        QStringList campos = linea.split(";");
        if (campos.size() != 4) continue;

        if (campos[0] == codigoEliminar) {
            eliminado = true;
            continue;
        }

        lineas.append(linea);
    }

    archivo.close();

    if (!eliminado) {
        QMessageBox::information(this, "Aviso", "Producto no encontrado");
        return;
    }


    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo");
        return;
    }

    QTextStream out(&archivo);
    for (const QString &l : lineas) {
        out << l << "\n";
    }

    archivo.close();

    QMessageBox::information(this, "Éxito", "Producto eliminado correctamente");
    ui->codigo->clear();
}

void eliminar::on_regresar_clicked()
{
    close();
}
