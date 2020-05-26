#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>
#include <QList>


class User {
    struct Bet {
        int betValue;
        QDate date;
        bool isCorrect;
    };

private:
    QDate startDate;
    QString name;
    int score;
    QList <Bet> bets;
public:
    User(int score, QDate startDate);

    // User defined functions

    int isScoreValid() { return this->score > 0; }
    void addBet(int value, QDate date, bool isCorrect);

    // Getters and Setters

    void clearAllBets();
    QDate getStartDate() const;
    void setStartDate(const QDate &value);
    int getScore() const;
    void setScore(int value);
    QList <Bet> getBets() const { return this->bets; };
    void setBets(const QList <Bet> &value);
};

#endif // USER_H
