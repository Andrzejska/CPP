#ifndef CHART_H
#define CHART_H
#include <QtCharts>
#include <QCandlestickSeries>
#include <QString>
#include <QDate>
#include "stock.h"
#include <QDebug>
#include <list>
#include <QSet>
#include <QStringList>
#include <QDebug>


using namespace QtCharts;


class Chart
{
private:
    QCandlestickSeries *series;
    QString chartName;
    QString seriesName;
    QChart *qChart;
    QList<Stock> stocks;
    QChartView *chartView;
public:
    Chart(QString chartName="Index",QString seriesName="Index name");
    // User defined functions

    void parseCvsToStockObject(QString pathToFile,QDate toDate,QDate fromDate);
    void deleteLastStock();

   // Getters and setters

    QCandlestickSeries *getChart() const;
    void setChart(QCandlestickSeries *value);
    QList<Stock> getStocks() const;
    void setStocks(const QList<Stock> &value);
    QString getSeriesName() const;
    void setSeriesName(const QString &value);
    QString getChartName() const;
    void setChartName(const QString &value);
    QChartView *getChartView() const;
    void setChartView(QChartView *value);
    QChart *getQChart() const;
    void setQChart(QChart *value);
    QCandlestickSeries *getSeries() const;
    void setSeries(QCandlestickSeries *value);
};

#endif // CHART_H
