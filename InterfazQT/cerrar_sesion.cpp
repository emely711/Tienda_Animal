#include "cerrar_sesion.h"
#include "ui_cerrar_sesion.h"

cerrar_sesion::cerrar_sesion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cerrar_sesion)
{
    ui->setupUi(this);
}

cerrar_sesion::~cerrar_sesion()
{
    delete ui;
}
