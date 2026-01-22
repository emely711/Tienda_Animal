#ifndef ACTUALIZAR_H
#define ACTUALIZAR_H

#include <QDialog>

namespace Ui {
class actualizar;
}

class actualizar : public QDialog
{
    Q_OBJECT

public:
    explicit actualizar(QWidget *parent = nullptr);
    ~actualizar();

private:
    Ui::actualizar *ui;
};

#endif // ACTUALIZAR_H
