#include "actualizar.h"
#include "ui_actualizar.h"

Actualizar::Actualizar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Actualizar)
{
    ui->setupUi(this);
}

Actualizar::~Actualizar()
{
    delete ui;
}


void Actualizar::on_btnActualizar_D_clicked()
{
    menu_Actualizar *datos_actualizar =new menu_Actualizar(this);
    datos_actualizar->exec();

}

