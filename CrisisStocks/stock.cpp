#include "stock.h"


// Constructor

Stock::Stock() {

}

Stock::Stock(QDate date, float openPrice, float highPrice, float lowPrice, float closePrice, float adjClose,
             float volume) : date(date), openPrice(openPrice), highPrice(highPrice), lowPrice(lowPrice),
                             closePrice(closePrice), adjClose(adjClose), volume(volume) {
}

// Getters and Setters

QDate Stock::getDate() const {
    return date;
}

void Stock::setDate(const QDate &value) {
    date = value;
}

float Stock::getVolume() const {
    return volume;
}

void Stock::setVolume(float value) {
    volume = value;
}

float Stock::getAdjClose() const {
    return adjClose;
}

void Stock::setAdjClose(float value) {
    adjClose = value;
}

float Stock::getClosePrice() const {
    return closePrice;
}

void Stock::setClosePrice(float value) {
    closePrice = value;
}

float Stock::getLowPrice() const {
    return lowPrice;
}

void Stock::setLowPrice(float value) {
    lowPrice = value;
}

float Stock::getHighPrice() const {
    return highPrice;
}

void Stock::setHighPrice(float value) {
    highPrice = value;
}

float Stock::getOpenPrice() const {
    return openPrice;
}

void Stock::setOpenPrice(float value) {
    openPrice = value;
}
