#include "endgamewindow.h"
#include "ui_endgamewindow.h"

EndGameWindow::EndGameWindow(QWidget *parent,int score) :
    QDialog(parent),
    ui(new Ui::EndGameWindow)
{
    ui->setupUi(this);
    ui->scoreLabel->setText("Max score "+QString::number(score));
}


EndGameWindow::~EndGameWindow()
{
    delete ui;
}
