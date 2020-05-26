#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QDialog>
#include <QString>
namespace Ui {
class EndGameWindow;
}

class EndGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EndGameWindow(QWidget *parent = nullptr,int score=100);
    ~EndGameWindow();

private:
    Ui::EndGameWindow *ui;
};

#endif // ENDGAMEWINDOW_H
