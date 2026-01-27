#include "menuudialog.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_pushButton_acceder_clicked()
{
    QString usuario = ui->lineEdit_usuario->text();
    QString contrasenia = ui->lineEdit_contrasenia->text();

    if(usuario == "admin1" && contrasenia == "hola123"){
        //QMessageBox::information(this, "Acceder", "Usuario y Contraseña correctos");
        hide();
        menuuDialog = new menuudialog(this);
        menuuDialog->show();

    }else{
        QMessageBox::warning(this, "Acceder", "Usuario o Contraseña incorrectos");
    }
}

