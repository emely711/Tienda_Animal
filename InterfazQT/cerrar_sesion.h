#ifndef CERRAR_SESION_H
#define CERRAR_SESION_H

#include <QDialog>

namespace Ui {
class cerrar_sesion;
}

class cerrar_sesion : public QDialog
{
    Q_OBJECT

public:
    explicit cerrar_sesion(QWidget *parent = nullptr);
    ~cerrar_sesion();

private:
    Ui::cerrar_sesion *ui;
};

#endif // CERRAR_SESION_H
