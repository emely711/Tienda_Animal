#include "menudialog.h"
#include "ui_menudialog.h"

menu::menu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}
