#include "chart.h"



// Constructor
Chart::Chart(QString chartName, QString seriesName) : chartName(chartName), seriesName(seriesName) {
    this->series = new QCandlestickSeries();
    this->qChart = new QChart();
}


// User defined functions

void Chart::parseCvsToStockObject(QString pathToFile, QDate toDate, QDate fromDate) {
    QFile file(pathToFile);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    QList <Stock> stocks;
    QList <QByteArray> wordList;
    QDate tmpDate;

    // Skipping column name line

    file.readLine();
    for (int i = 0; i < fromDate.daysTo(toDate) - 30; i++) file.readLine();
    do {
        QByteArray line = file.readLine();
        wordList = line.split(',');
        tmpDate = QDate::fromString((wordList[0]), "dd/MM/yyyy");
        if (tmpDate >= (fromDate)) {
            Stock *tmp = new Stock(tmpDate,
                                   (wordList[1]).toFloat(),
                                   (wordList[2]).toFloat(),
                                   (wordList[3]).toFloat(),
                                   (wordList[4]).toFloat(),
                                   (wordList[5]).toFloat(),
                                   (wordList[6]).toFloat());
            stocks.append(*tmp);
        }
    } while (!file.atEnd() && tmpDate <= (toDate));
    this->setStocks(stocks);
}

void Chart::deleteLastStock() {
    this->stocks.pop_back();
}


// Getters and Setters

QCandlestickSeries *Chart::getSeries() const {
    return series;
}

void Chart::setSeries(QCandlestickSeries *value) {
    series = value;
}


QChart *Chart::getQChart() const {
    return qChart;
}

void Chart::setQChart(QChart *value) {
    qChart = value;
}

QChartView *Chart::getChartView() const {
    return chartView;
}

void Chart::setChartView(QChartView *value) {
    chartView = value;
}

QString Chart::getChartName() const {
    return chartName;
}

void Chart::setChartName(const QString &value) {
    chartName = value;
}

QString Chart::getSeriesName() const {
    return seriesName;
}

void Chart::setSeriesName(const QString &value) {
    seriesName = value;
}

QList <Stock> Chart::getStocks() const {
    return stocks;
}

void Chart::setStocks(const QList <Stock> &value) {
    stocks = value;
}

QCandlestickSeries *Chart::getChart() const {
    return series;
}

void Chart::setChart(QCandlestickSeries *value) {
    series = value;
}

