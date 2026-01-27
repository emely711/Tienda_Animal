#include "dialogmenu.h"
#include "ui_dialogmenu.h"

dialogmenu::dialogmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialogmenu)
{
    ui->setupUi(this);
}

dialogmenu::~dialogmenu()
{
    delete ui;
}
