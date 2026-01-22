#include "eliminar.h"
#include "ui_eliminar.h"

Eliminar::Eliminar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Eliminar)
{
    ui->setupUi(this);
}

Eliminar::~Eliminar()
{
    delete ui;
}

