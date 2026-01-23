#include "buscar.h"
#include "ui_buscar.h"
#include "producto.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>

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
    QString nombreBuscado = ui->nombre->text().trimmed();

    if (nombreBuscado.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese el nombre del producto");
        return;
    }

    QString ruta = QDir::homePath() + "/Documents/InterfazQT/productos.txt";
    QFile archivo(ruta);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo");
        return;
    }

    QTextStream in(&archivo);
    bool encontrado = false;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (linea.isEmpty()) continue;

        QStringList campos = linea.split(";");
        if (campos.size() != 4) continue;

        if (campos[1].compare(nombreBuscado, Qt::CaseInsensitive) == 0) {
            // Mostrar datos
            ui->codigo->setText(campos[0]);
            ui->precio->setText(campos[2]);
            ui->stock->setText(campos[3]);
            encontrado = true;
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        QMessageBox::critical(this, "Error", "No se ha encontrado el producto");
    }
}

void buscar::on_pushButton_2_clicked()
{
    close();
}
