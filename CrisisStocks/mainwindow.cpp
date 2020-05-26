#include "mainwindow.h"
#include "./ui_mainwindow.h"

// Constructor
MainWindow::MainWindow(QDate startDate, QWidget *parent, int score)
        : QMainWindow(parent),
          user(new User(score, startDate)),
          currentDate(startDate),
          ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Setting start score

    this->user->setScore(score);
    QString scoreText = "Score : " + QString::number(this->user->getScore());
    ui->scoreLabel->setText(scoreText);
    this->maxScore = score;

    // Setting start and current date

    this->user->setStartDate(startDate);
    QString dateText = "Todays date is :" + startDate.toString();
    ui->dateLabel->setText(dateText);

    // Setting the layout

    this->chart = NULL;
    ui->chartArea->setLayout(new QVBoxLayout);

    // Setting the default Path

    this->pathToFile = "C:/Users/Andy/Documents/GitHub/covidStocks/AAPL.csv";

}

MainWindow::~MainWindow() {
    delete ui;
}

Chart *MainWindow::getChart() const
{
    return chart;
}

void MainWindow::setChart(Chart *value)
{
    chart = value;
}

// User defined functions
void MainWindow::showChart() {

    Chart *chart = new Chart();
    QString scoreText = "Score : " + QString::number(this->user->getScore());
    ui->scoreLabel->setText(scoreText);
    chart->parseCvsToStockObject(this->getPathToFile(), this->getCurrentDate().addDays(31),
                                 this->getUser()->getStartDate());


    // Cleaning previous data

    auto chartSeries=chart->getSeries();
    chartSeries->clear();
    chart->getStocks().clear();

    // Setting the name and colors of the chart

    chartSeries->setName(chart->getSeriesName());
    chartSeries->setIncreasingColor(QColor(Qt::green));
    chartSeries->setDecreasingColor(QColor(Qt::red));

    // Setting values to be shown

    QStringList categories;
    QCandlestickSet *set;
    auto chartStocks=chart->getStocks();
    for (int i = 0; i < chart->getStocks().length() - 1; i++) {
        set = new QCandlestickSet();
        set->setLow(chartStocks[i].getLowPrice());
        set->setHigh(chartStocks[i].getHighPrice());
        set->setOpen(chartStocks[i].getOpenPrice());
        set->setTimestamp(chartStocks[i].getDate().toString("ddMMyyyy").toDouble());
        set->setClose(chartStocks[i].getClosePrice());
        categories.append(chartStocks[i].getDate().toString());
        chartSeries->append(set);
    }

    // Setting chart name and axes

    auto qChart=chart->getQChart();
    qChart->addSeries(chart->getSeries());
    qChart->setTitle(chart->getChartName());
    qChart->setAnimationOptions(QChart::SeriesAnimations);
    qChart->createDefaultAxes();
    QBarCategoryAxis *axisX = qobject_cast<QBarCategoryAxis *>(qChart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);
    axisX->setLabelsAngle(-90);

    QValueAxis *axisY = qobject_cast<QValueAxis *>(qChart->axes(Qt::Vertical).at(0));
    axisY->setMax(axisY->max() * 1.01);
    axisY->setMin(axisY->min() * 0.99);

    qChart->legend()->setVisible(true);
    qChart->legend()->setAlignment(Qt::AlignBottom);

    chart->setChartView(new QChartView(chart->getQChart(), ui->chartArea));
    chart->getChartView()->setRenderHint(QPainter::Antialiasing);

    // Removing previous chart and adding new
    if (this->chart != NULL) ui->chartArea->layout()->removeWidget(this->chart->getChartView());
    this->setChart(chart);
    ui->chartArea->layout()->addWidget(chart->getChartView());
    this->show();
}

QString MainWindow::getPathToFileFromIndex(QString index) {
    if (index == "APPL") return "C:/Users/Andy/Documents/GitHub/covidStocks/AAPL.csv";
    if (index == "GOOG") return "C:/Users/Andy/Documents/GitHub/covidStocks/GOOG.csv";
    if (index == "MSFT") return "C:/Users/Andy/Documents/GitHub/covidStocks/MSFT.csv";
    if (index == "SNE") return "C:/Users/Andy/Documents/GitHub/covidStocks/SNE.csv";
    if (index == "INTC") return "C:/Users/Andy/Documents/GitHub/covidStocks/INTC.csv";
    return NULL;
}


void MainWindow::on_confirmPushButton_clicked() {
    if (ui->betInputLineEdit->text().toUInt() > 0) {

        //Ask user to confirm bet

        QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirming the bet",
                                                                  "Are you sure you want to make a bet?",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) {

        } else {
            if (this->getUser()->getScore() >= ui->betInputLineEdit->text().toInt()) {

                // Setting the bet message

                auto inputBetValue = ui->betInputLineEdit->text();
                QString betTextConfirm =
                        "Your bet is " + inputBetValue + " for index " + ui->selectIndexComboBox->currentText() +
                        " to go " +
                        ui->upDownBetComboBox->currentText().toLower();
                ui->playersBetTextLabel->setText(betTextConfirm);

                // Modyfying user  and adding bet

                this->getUser()->setScore(this->getUser()->getScore() - (ui->betInputLineEdit->text().toInt()));
                QString scoreText = "Score : " + QString::number(this->getUser()->getScore());
                ui->scoreLabel->setText(scoreText);

                auto chart=this->getChart();
                auto chartStocks=chart->getStocks();
                float nextDayValue = (chartStocks.last().getHighPrice() +
                                      chartStocks.last().getLowPrice()) / 2;
                chart->deleteLastStock();
                float previousDayValue = (chartStocks.last().getHighPrice() +
                                          chartStocks.last().getLowPrice()) / 2;
                bool isPositive = nextDayValue > previousDayValue;
                this->getUser()->addBet(ui->betInputLineEdit->text().toInt(), this->getCurrentDate(), isPositive);

            } else {
                QMessageBox::warning(this, "Bet value", "Value of your bet can not be higher than number of points");
            }
        }


    } else {
        QMessageBox::warning(this, "Bet value", "Value of your bet can not be lower than 0");
    }

}


void MainWindow::on_selectIndexComboBox_currentIndexChanged(const QString &index) {
    this->pathToFile = getPathToFileFromIndex(index);
    this->showChart();
}

void MainWindow::on_nextDayPushButton_clicked() {

    // Checking if the game is not over

    if (this->getUser()->getScore() <= 0 || this->getUser()->getStartDate().daysTo(this->getCurrentDate()) >= 30) {
        hide();
        EndGameWindow *endGameWindow = new EndGameWindow(this, this->maxScore);
        endGameWindow->show();
    } else {

        // Setting date

        this->setCurrentDate(this->getCurrentDate().addDays(1));
        QString dateText = "Todays date is :" + this->getCurrentDate().toString();
        ui->dateLabel->setText(dateText);

        // Setting the max score

        this->maxScore = std::max(maxScore, this->getUser()->getScore());

        // Adding earned money

        int earnedMoney = 0;
        auto bets = this->getUser()->getBets();
        for (int i = 0; i < bets.length(); i++) {
            earnedMoney += (bets[i].isCorrect) ? bets[i].betValue * 2 : 0;
        }
        this->getUser()->setScore(this->getUser()->getScore() + earnedMoney);

        // Information window

        QMessageBox msgBox;
        if (this->getUser()->getBets().length() > 0) {
            msgBox.setText("Your daily earning is " + QString::number(earnedMoney) + " points.");
            msgBox.exec();
        }

        this->showChart();
        this->getUser()->clearAllBets();
    }
}

void MainWindow::on_pushButton_clicked() {
    instructionWindow = new class instructionWindow();
    instructionWindow->show();
}

// Getters and Setters

QDate MainWindow::getCurrentDate() const {
    return currentDate;
}

void MainWindow::setCurrentDate(const QDate &value) {
    currentDate = value;
}

QString MainWindow::getPathToFile() const {
    return pathToFile;
}

void MainWindow::setPathToFile(const QString &value) {
    pathToFile = value;
}

User *MainWindow::getUser() const {
    return user;
}

void MainWindow::setUser(User *value) {
    user = value;
}



