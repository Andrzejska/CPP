#include "instructionwindow.h"
#include "ui_instructionwindow.h"

instructionWindow::instructionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instructionWindow)
{
    ui->setupUi(this);
}

instructionWindow::~instructionWindow()
{
    delete ui;
}
