#include "agregar.h"
#include "ui_agregar.h"
#include "producto.h"
#include <QMessageBox>

agregar::agregar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregar)
{
    ui->setupUi(this);
}

agregar::~agregar()
{
    delete ui;
}


void agregar::on_guardar_producto_clicked()
{
    Producto p;

    p.codigo = ui->codigo->text().toStdString();
    p.nombre = ui->nombre->text().toStdString();

    bool okPrecio;
    p.precio = ui->precio->text().toFloat(&okPrecio);

    bool okStock;
    p.stock = ui->stock->text().toInt(&okStock);

    if (p.codigo.empty() || p.nombre.empty()) {
        QMessageBox::warning(this, "Error", "Complete todos los campos");
        return;
    }

    if (!soloLetras(p.codigo)) {
        QMessageBox::warning(this, "Error", "El código solo debe contener letras");
        return;
    }

    if (!soloLetras(p.nombre)) {
        QMessageBox::warning(this, "Error", "El nombre solo debe contener letras y espacios");
        return;
    }

    if(codigoDuplicado(p.codigo)){
        QMessageBox::warning(this, "Error", "El codigo ya existe");
        return;
    }


    if (!okPrecio || p.precio < 0) {
        QMessageBox::warning(this, "Error", "Precio inválido");
        return;
    }

    if (!okStock || p.stock < 0) {
        QMessageBox::warning(this, "Error", "Stock inválido");
        return;
    }

    guardarProducto(p);

    QMessageBox::information(this, "Correcto", "Producto agregado correctamente");
    close();


}


void agregar::on_pushButton_clicked()
{
    close();
}

