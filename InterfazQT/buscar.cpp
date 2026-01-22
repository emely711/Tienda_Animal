#include "buscar.h"
#include "ui_buscar.h"

buscar::buscar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::buscar)
{
    ui->setupUi(this);
}

buscar::~buscar()
{
    delete ui;
}
