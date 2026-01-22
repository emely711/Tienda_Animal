#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mostrar_contactos.h"
#include <Qfile>
#include <QTextStream>
#include <QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionActualizar_triggered()
{
    Actualizar *actualizarVentana = new Actualizar(this);
    actualizarVentana->setModal(true);
    actualizarVentana->show();
}



void MainWindow::on_actionEliminar_triggered()
{
    Eliminar *eliminarContacto= new Eliminar(this);
    eliminarContacto->show();



}


void MainWindow::on_btnGuardar_clicked()
{
    QString nombre=ui->txtNombre->text();
    QString apellido=ui->txtApellido->text();
    QString apodo=ui->txtApodo->text();
    QString telefono=ui->txtCelular->text();
    QString correo=ui->txtCorreo->text();
    QString direccion=ui->txtDireccion->text();
    QString cumpl=ui->dateEdit->date().toString();
    bool num;
    telefono.toInt(&num);

    if(nombre.isEmpty() || apellido.isEmpty() || apodo.isEmpty() ||
        telefono.isEmpty() || correo.isEmpty() || direccion.isEmpty() || cumpl.isEmpty())
    {
        QMessageBox::warning(this, "ERROR","Por favor ingrese los datos correctamente, uno o mas campos vacios");

    }
    else{
        if(!num || telefono.isEmpty()){
            QMessageBox::critical(this,"ERROR","Solo se pueden ingresar numeros");
            ui->txtCelular->clear();
            ui->txtCelular->setFocus();
        }else{
            QFile archivo("lista_contactos.txt");
            if (!archivo.open(QIODevice::Append|QIODevice::Text)){
                QMessageBox::warning(this,"ERROR","No se pudo abrir el archivo");
                return;
            }
            QTextStream guardar(&archivo);
            guardar<<nombre<<"|"<<apellido<<"|"<<apodo<<"|"<<telefono<<"|"<<correo<<"|"<<direccion<<"|"<<cumpl<<"|"<<"\n";
            archivo.close();
            QMessageBox::information(this,"Exito","Datos guardados correctamente");
            ui->txtNombre->clear();
            ui->txtNombre->setFocus();
            ui->txtApodo->clear();
            ui->txtCelular->clear();
            ui->txtCorreo->clear();
            ui->txtDireccion->clear();
            ui->txtApellido->clear();
        }


    }
}


void MainWindow::on_actionMostrar_Contactos_triggered()
{

    mostrar_contactos *ventana = new mostrar_contactos(this);
    ventana->exec();

}

