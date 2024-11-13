#ifndef RACECONTROLLER_H
#define RACECONTROLLER_H

#include <QObject>
#include <QVector>
#include "Car.h"
#include "CarThread.h"
#include "RaceTrack.h"

class RaceController : public QObject
{
    Q_OBJECT

public:
    RaceController(RaceTrack* raceTrack, QObject* parent = nullptr);
    ~RaceController();

    void startRace();
    void stopRace();

    void addCar(int carIndex, int startX, int initialY);

signals:
    void carFinished(int carIndex); // Signal to notify when a car finishes the race
    void carPositionUpdated(int x, int y, int carIndex);

private:
    QVector<Car*> m_cars;
    QVector<CarThread*> m_carThreads;
    RaceTrack* m_raceTrack; // Pointer to the race track
    bool m_isRaceOngoing = false;
};

#endif // RACECONTROLLER_H
