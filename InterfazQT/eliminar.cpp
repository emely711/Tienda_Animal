#include "eliminar.h"
#include "ui_eliminar.h"

eliminar::eliminar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::eliminar)
{
    ui->setupUi(this);
}

eliminar::~eliminar()
{
    delete ui;
}
