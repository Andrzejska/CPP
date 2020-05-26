#include "mainwindow.h"
#include "instructionwindow.h"
#include "inputwindow.h"
#include "user.h"
#include "chart.h"
#include <QApplication>
#include <QDebug>
#include <QDate>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString startDate = QInputDialog::getText(nullptr,"Start date","Enter the start date from */*/2007-*/*/2010");
    int score=QInputDialog::getInt(nullptr,"Start score","Enter the start score");
    MainWindow w(QDate::fromString(startDate,"dd/MM/yyyy"),nullptr,score);
    w.showChart();
    return a.exec();
}
