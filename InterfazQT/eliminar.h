#ifndef ELIMINAR_H
#define ELIMINAR_H

#include <QDialog>

namespace Ui {
class eliminar;
}

class eliminar : public QDialog
{
    Q_OBJECT

public:
    explicit eliminar(QWidget *parent = nullptr);
    ~eliminar();

private:
    Ui::eliminar *ui;
};

#endif // ELIMINAR_H
