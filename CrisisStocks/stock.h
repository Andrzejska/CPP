#ifndef STOCK_H
#define STOCK_H
#include <QDate>
#include <QDebug>

class Stock
{
private:
    QDate date;
    float openPrice;
    float highPrice;
    float lowPrice;
    float closePrice;
    float adjClose;
    float volume;
public:
    Stock();
    Stock(QDate date,float openPrice,float highPrice,float lowPrice,float closePrice,float adjClose,float volume);

    // Getters and Setters

    float getOpenPrice() const;
    void setOpenPrice(float value);
    float getHighPrice() const;
    void setHighPrice(float value);
    float getLowPrice() const;
    void setLowPrice(float value);
    float getClosePrice() const;
    void setClosePrice(float value);
    float getAdjClose() const;
    void setAdjClose(float value);
    float getVolume() const;
    void setVolume(float value);
    QDate getDate() const;
    void setDate(const QDate &value);
};

#endif // STOCK_H
