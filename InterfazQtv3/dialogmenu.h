#ifndef DIALOGMENU_H
#define DIALOGMENU_H

#include <QDialog>

namespace Ui {
class dialogmenu;
}

class dialogmenu : public QDialog
{
    Q_OBJECT

public:
    explicit dialogmenu(QWidget *parent = nullptr);
    ~dialogmenu();

private:
    Ui::dialogmenu *ui;
};

#endif // DIALOGMENU_H
