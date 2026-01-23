#ifndef MENUUDIALOG_H
#define MENUUDIALOG_H

#include "mostrar.h"
#include <QDialog>

namespace Ui {
class menuudialog;
}

class menuudialog : public QDialog
{
    Q_OBJECT

public:
    explicit menuudialog(QWidget *parent = nullptr);
    ~menuudialog();

private slots:
    void on_pushButton_clicked();

    void on_actualizarButton_clicked();

    void on_agregarButton_clicked();

    void on_mostrarButton_clicked();

    void on_eliminarButton_clicked();

    void on_buscarButton_clicked();

    void on_salirButton_clicked();

private:
    Ui::menuudialog *ui;
};

#endif // MENUUDIALOG_H
