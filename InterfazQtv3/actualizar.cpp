#include "actualizar.h"
#include "ui_actualizar.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QChar>
#include <QCoreApplication>

bool soloLetrasQString(const QString &texto)
{
    for (QChar c : texto) {
        if (!c.isLetter() && !c.isSpace())
            return false;
    }
    return true;
}

actualizar::actualizar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::actualizar)
{
    ui->setupUi(this);
}

actualizar::~actualizar()
{
    delete ui;
}

void actualizar::on_actualizar_2_clicked() // ACTUALIZAR
{
    QString codigo = ui->codigo->text().trimmed();
    QString nombre = ui->nombre->text().trimmed();

    bool okPrecio, okStock;
    double precio = ui->precio->text().toDouble(&okPrecio);
    int stock     = ui->stock->text().toInt(&okStock);


    if (codigo.isEmpty() || nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "Todos los campos son obligatorios");
        return;
    }

    if (!soloLetrasQString(codigo)) {
        QMessageBox::warning(this, "Error", "El código solo debe contener letras");
        return;
    }

    if (!soloLetrasQString(nombre)) {
        QMessageBox::warning(this, "Error", "El nombre solo debe contener letras");
        return;
    }

    if (!okPrecio) {
        QMessageBox::warning(this, "Error", "El precio debe ser un número decimal");
        return;
    }

    if (!okStock) {
        QMessageBox::warning(this, "Error", "El stock debe ser un número entero");
        return;
    }

    QString ruta = QCoreApplication::applicationDirPath() + "/productos.txt";
    QFile archivo(ruta);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo");
        return;
    }

    QStringList lineas;
    QTextStream in(&archivo);
    bool encontrado = false;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        if (linea.isEmpty()) continue;

        QStringList c = linea.split(";");
        if (c.size() != 4) continue;

        if (c[0] == codigo) {
            lineas << codigo + ";" + nombre + ";" +
            QString::number(precio) + ";" +
            QString::number(stock);
            encontrado = true;
        } else {
            lineas << linea;
        }
    }
    archivo.close();

    if (!encontrado) {
        QMessageBox::warning(this, "Aviso", "Código no encontrado");
        return;
    }

    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo guardar el archivo");
        return;
    }

    QTextStream out(&archivo);
    for (const QString &l : lineas)
        out << l << "\n";

    archivo.close();

    QMessageBox::information(this, "Éxito", "Producto actualizado correctamente");
    close();
}

void actualizar::on_pushButton_clicked()
{
    close();
}
