#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTime>
#include <QTimer>

class StopWatch : public QObject
{
    Q_OBJECT
public:
    StopWatch();

signals:
    void timeUpdated(const QString& time);

public slots:
    void start();
    void stop();
    void updateTime();
    double getCircleDuration();

private:
    QTimer* timer;
    QTime time;
    QTime timeStart;
};

#endif // STOPWATCH_H
