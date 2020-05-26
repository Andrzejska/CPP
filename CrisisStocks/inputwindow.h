#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H
#include "mainwindow.h"
#include "instructionwindow.h"
#include <QDialog>

namespace Ui {
class inputWindow;
}

class inputWindow : public QDialog
{
    Q_OBJECT

public:
    explicit inputWindow(QWidget *parent = nullptr);
    ~inputWindow();
    int scoreToSend;

private slots:


private:
    Ui::inputWindow *ui;


};

#endif // INPUTWINDOW_H
