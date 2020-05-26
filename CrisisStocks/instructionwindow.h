#ifndef INSTRUCTIONWINDOW_H
#define INSTRUCTIONWINDOW_H

#include <QDialog>

namespace Ui {
class instructionWindow;
}

class instructionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit instructionWindow(QWidget *parent = nullptr);
    ~instructionWindow();

private:
    Ui::instructionWindow *ui;
};

#endif // INSTRUCTIONWINDOW_H
