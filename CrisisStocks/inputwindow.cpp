#include "inputwindow.h"
#include "ui_inputwindow.h"

inputWindow::inputWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputWindow)
{
    ui->setupUi(this);
}

inputWindow::~inputWindow()
{
    delete ui;
}
