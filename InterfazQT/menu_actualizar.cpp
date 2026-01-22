#include "menu_actualizar.h"
#include "ui_menu_actualizar.h"

menu_Actualizar::menu_Actualizar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menu_Actualizar)
{
    ui->setupUi(this);
}

menu_Actualizar::~menu_Actualizar()
{
    delete ui;
}

void menu_Actualizar::on_btnActualizar_menu_clicked()
{


}

