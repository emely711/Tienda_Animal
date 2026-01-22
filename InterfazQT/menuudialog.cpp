#include "menuudialog.h"
#include "ui_menuudialog.h"
#include "agregar.h"


menuudialog::menuudialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menuudialog)
{
    ui->setupUi(this);
}

menuudialog::~menuudialog()
{
    delete ui;
}


void menuudialog::on_agregarButton_clicked()
{
    agregar ventanaAgregar(this);
    ventanaAgregar.exec();
}


void menuudialog::on_actualizarButton_clicked()
{

}


void menuudialog::on_mostrarButton_clicked()
{
    mostrar ventanaMostrar;
    ventanaMostrar.exec();

}

void menuudialog::on_buscarButton_clicked()
{

}


void menuudialog::on_eliminarButton_clicked()
{

}




void menuudialog::on_salirButton_clicked()
{

}

