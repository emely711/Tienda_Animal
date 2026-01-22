#include "actualizar.h"
#include "ui_actualizar.h"

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
