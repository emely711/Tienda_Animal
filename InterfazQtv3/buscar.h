#ifndef BUSCAR_H
#define BUSCAR_H

#include <QDialog>

namespace Ui {
class buscar;
}

class buscar : public QDialog
{
    Q_OBJECT

public:
    explicit buscar(QWidget *parent = nullptr);
    ~buscar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::buscar *ui;
};

#endif // BUSCAR_H
