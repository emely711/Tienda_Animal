#ifndef MENU_ACTUALIZAR_H
#define MENU_ACTUALIZAR_H

#include <QDialog>
namespace Ui {
class menu_Actualizar;
}

class menu_Actualizar : public QDialog
{
    Q_OBJECT

public:
    explicit menu_Actualizar(QWidget *parent = nullptr);
    ~menu_Actualizar();

private slots:
    void on_btnActualizar_menu_clicked();

private:
    Ui::menu_Actualizar *ui;
};

#endif // MENU_ACTUALIZAR_H
