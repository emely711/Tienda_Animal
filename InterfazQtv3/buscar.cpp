#include "buscar.h"
#include "ui_buscar.h"
#include "producto.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

buscar::buscar(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::buscar)
{
    ui->setupUi(this);
}

buscar::~buscar()
{
    delete ui;
}

void buscar::on_pushButton_clicked()
{
    QString nombreBuscado = ui->nombre->text().trimmed().toLower();

    if (nombreBuscado.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese el nombre del producto");
        return;
    }

    QString ruta = QCoreApplication::applicationDirPath() + "/productos.txt";
    QFile archivo(ruta);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir productos.txt");
        return;
    }

    QTextStream in(&archivo);
    bool encontrado = false;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (linea.isEmpty()) continue;

        QStringList campos = linea.split(";");
        if (campos.size() != 4) continue;

        QString nombreArchivo = campos[1].trimmed().toLower();

        if (nombreArchivo == nombreBuscado) {
            ui->codigo->setText(campos[0]);
            ui->precio->setText(campos[2]);
            ui->stock->setText(campos[3]);
            encontrado = true;
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        QMessageBox::information(this, "Aviso", "Producto no encontrado");
        ui->codigo->clear();
        ui->precio->clear();
        ui->stock->clear();
    }
}

void buscar::on_pushButton_2_clicked()
{
    close();
}
