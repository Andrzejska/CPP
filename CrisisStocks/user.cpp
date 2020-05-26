#include <user.h>


// Constructor

User::User(int score, QDate startDate) : startDate(startDate), score(score) {
}

// User defined functions

void User::addBet(int value, QDate date, bool isCorrect) {
    Bet *bet = new Bet();
    bet->betValue = value;
    bet->date = date;
    bet->isCorrect = isCorrect;
    this->bets.append(*bet);
}

void User::clearAllBets() {
    this->bets.clear();
}

// Getters and Setters

void User::setBets(const QList <Bet> &value) {
    bets = value;
}

QDate User::getStartDate() const {
    return startDate;
}

void User::setStartDate(const QDate &value) {
    startDate = value;
}

int User::getScore() const {
    return score;
}

void User::setScore(int value) {
    score = value;
}



