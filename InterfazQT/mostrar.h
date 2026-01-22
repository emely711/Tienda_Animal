#ifndef MOSTRAR_H
#define MOSTRAR_H

#include <QDialog>

namespace Ui {
class mostrar;
}

class mostrar : public QDialog
{
    Q_OBJECT

public:
    explicit mostrar(QWidget *parent = nullptr);
    ~mostrar();

private slots:
    void on_salir_clicked();

private:
    Ui::mostrar *ui;
    void on_agregarButton_clicked();
    void cargarProductos();

};

#endif // MOSTRAR_H
