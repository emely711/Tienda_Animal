#ifndef ACTUALIZAR_H
#define ACTUALIZAR_H

#include <QDialog>
#include"menu_actualizar.h"
namespace Ui {
class Actualizar;
}

class Actualizar : public QDialog
{
    Q_OBJECT

public:
    explicit Actualizar(QWidget *parent = nullptr);
    ~Actualizar();

private slots:
    void on_btnActualizar_D_clicked();

private:
    Ui::Actualizar *ui;
};

#endif // ACTUALIZAR_H
