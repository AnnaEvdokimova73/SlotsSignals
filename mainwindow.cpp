#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->butCircle->setEnabled(false);
    clearClicked();

    connect(ui->butStart, &QPushButton::clicked, this, &MainWindow::startClicked);
    connect(ui->butCircle, &QPushButton::clicked, this, &MainWindow::circleClicked);
    connect(ui->butClear, &QPushButton::clicked, this, &MainWindow::clearClicked);

    connect(&stopWatch, &StopWatch::timeUpdated, this, &MainWindow::updateLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startClicked()
{
    if (ui->butStart->text() == "Старт")
    {
        ui->butCircle->setEnabled(true);
        ui->butStart->setText("Стоп");
        stopWatch.start();
        timerIsRunning = true;
    }
    else
    {
        ui->butCircle->setEnabled(false);
        ui->butStart->setText("Старт");
        stopWatch.stop();
        timerIsRunning = false;
        circCount = 0;
    }
}

void MainWindow::circleClicked()
{
    double circleDuration = stopWatch.getCircleDuration();
    QString textCircle = QString("Круг %1, время: %2 сек")
            .arg(++circCount)
            .arg(QString::number(circleDuration));
    ui->textCircles->append(textCircle);
}

void MainWindow::clearClicked()
{
    ui->textCircles->clear();
    circCount = 0;
    if (!timerIsRunning)
    {
        QTime curTime = QTime(0, 0, 0);
        ui->labelTime->setText(curTime.toString("hh:mm:ss.zzz"));
    }
    else
    {
        stopWatch.stop();
        stopWatch.start();
    }

}

void MainWindow::updateLabel(const QString& time)
{
    ui->labelTime->setText(time);
}

