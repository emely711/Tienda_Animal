#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "actualizar.h"
#include "menu_actualizar.h"
#include "eliminar.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionCrear_triggered();

    void on_actionActualizar_triggered();

    void on_actionEliminar_triggered();

    void on_btnGuardar_clicked();

    void on_actionMostrar_Contactos_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
