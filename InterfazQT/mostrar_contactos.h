#ifndef MOSTRAR_CONTACTOS_H
#define MOSTRAR_CONTACTOS_H

#include <QDialog>

namespace Ui {
class mostrar_contactos;
}

class mostrar_contactos : public QDialog
{
    Q_OBJECT

public:
    explicit mostrar_contactos(QWidget *parent = nullptr);
    ~mostrar_contactos();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mostrar_contactos *ui;
};

#endif // MOSTRAR_CONTACTOS_H
