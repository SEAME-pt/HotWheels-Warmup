#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QThread>
#include "Car.h"
#include "RaceTrack.h" // Include RaceTrack

class CarThread : public QThread
{
    Q_OBJECT

public:
    CarThread(Car* car, RaceTrack* raceTrack, QObject* parent = nullptr);
    ~CarThread();

    void stopThread();

signals:
    void finishedRace(); // Renamed signal

protected:
    void run() override;

private:
    Car* m_car;
    RaceTrack* m_raceTrack; // Store the entire RaceTrack
    bool m_shouldRun;
};

#endif // CARTHREAD_H
