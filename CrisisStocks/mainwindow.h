#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "chart.h"
#include "instructionwindow.h"
#include "endgamewindow.h"
#include <QString>
#include <QMessageBox>
#include <user.h>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    instructionWindow *instructionWindow;
    User *user;
    QString pathToFile;
    Chart *chart;
    QDate currentDate;
    int maxScore;
    QList<Stock> nextDayStocks;

public:
    MainWindow(QDate startDate,QWidget *parent = nullptr,int score=2000);
    ~MainWindow();



    // User defined functions

    void showChart();
    QString getPathToFileFromIndex(QString index);

    // Getters and Setters

    User *getUser() const;
    void setUser(User *value);
    QString getPathToFile() const;
    void setPathToFile(const QString &value);
    QDate getCurrentDate() const;
    void setCurrentDate(const QDate &value);
    Chart *getChart() const;
    void setChart(Chart *value);

private slots:
    void on_confirmPushButton_clicked();
    void on_selectIndexComboBox_currentIndexChanged(const QString &arg1);
    void on_nextDayPushButton_clicked();
    void on_pushButton_clicked();



};
#endif // MAINWINDOW_H
