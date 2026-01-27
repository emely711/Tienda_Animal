#ifndef ACTUALIZAR_H
#define ACTUALIZAR_H

#include <QDialog>
#include <QString>

namespace Ui {
class actualizar;
}


bool soloLetrasQString(const QString &texto);

class actualizar : public QDialog
{
    Q_OBJECT

public:
    explicit actualizar(QWidget *parent = nullptr);
    ~actualizar();

private slots:
    void on_actualizar_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::actualizar *ui;
};

#endif // ACTUALIZAR_H
