#include "menuudialog.h"
#include "ui_menuudialog.h"

#include "agregar.h"
#include "mostrar.h"
#include "actualizar.h"
#include "buscar.h"
#include "eliminar.h"


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
    actualizar ventanaActualizar(this);
    ventanaActualizar.exec();
}

void menuudialog::on_mostrarButton_clicked()
{
    mostrar ventanaMostrar(this);
    ventanaMostrar.exec();
}

void menuudialog::on_buscarButton_clicked()
{
    buscar ventanaBuscar(this);
    ventanaBuscar.exec();
}

void menuudialog::on_eliminarButton_clicked()
{
    eliminar ventanaEliminar(this);
    ventanaEliminar.exec();
}

void menuudialog::on_salirButton_clicked()
{
    close();
}
