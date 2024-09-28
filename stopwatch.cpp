#include "stopwatch.h"

StopWatch::StopWatch()
{

}

void StopWatch::start()
{
    time = QTime(0, 0, 0);
    timeStart = time;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StopWatch::updateTime);
    timer->start(100);
}

void StopWatch::stop()
{
    timer->stop();
    time = QTime(0, 0, 0);
    emit timeUpdated(time.toString("hh:mm:ss.zzz"));
}

void StopWatch::updateTime()
{
    time = time.addMSecs(100);
    emit timeUpdated(time.toString("hh:mm:ss.zzz"));
}

double StopWatch::getCircleDuration()
{
    int durMsecs = timeStart.msecsTo(time);
    double dur = (durMsecs / 1000.0);
    timeStart = time;
    return dur;
}
