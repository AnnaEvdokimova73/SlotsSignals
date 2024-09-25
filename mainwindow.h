#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startClicked();
    void circleClicked();
    void clearClicked();

    void updateLabel(const QString& time);

private:
    Ui::MainWindow *ui;
    StopWatch stopWatch;
    bool timerIsRunning = false;
    int circCount = 0;
};
#endif // MAINWINDOW_H
