#include "mostrar_contactos.h"
#include "ui_mostrar_contactos.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QTableWidgetItem>
#include <QMessageBox>

mostrar_contactos::mostrar_contactos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mostrar_contactos)
{
    ui->setupUi(this);

    QFile archivo("lista_contactos.txt");
    if(!archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error","No se pudo abrir el archivo");
        return;
    }

    QTextStream in(&archivo);
    QString linea;
    int fila = 0;

    ui->tablaContactos->setColumnCount(7);
    QStringList headers = {"Nombre", "Apellido", "Apodo", "Celular", "Correo", "Dirección", "Cumpleaños"};
    ui->tablaContactos->setHorizontalHeaderLabels(headers);

    while (!in.atEnd()){
        linea = in.readLine().trimmed();

        if (linea.isEmpty()) continue;

        QStringList campos = linea.split('|');

        if (campos.size()<7) continue;

        ui->tablaContactos->insertRow(fila);

        for(int col = 0; col <7; col++){
            QTableWidgetItem *item = new QTableWidgetItem(campos[col].trimmed());
            ui->tablaContactos->setItem(fila, col, item);

        }
        fila++;
    }
    archivo.close();
}


mostrar_contactos::~mostrar_contactos()
{
    delete ui;
}

void mostrar_contactos::on_pushButton_clicked()
{
    this->close();
}

