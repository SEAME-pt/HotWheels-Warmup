#ifndef RACECONTROLLER_H
#define RACECONTROLLER_H

#include <QObject>
#include <QVector>
#include "Car.h"
#include "CarThread.h"
#include "RaceTrack.h"

// RaceController manages race flow, including starting, stopping, and tracking car positions.
class RaceController : public QObject
{
    Q_OBJECT

public:
    // Constructs a RaceController linked to a RaceTrack.
    RaceController(RaceTrack* raceTrack, QObject* parent = nullptr);
    ~RaceController();

    void startRace();  // Starts the race by activating all car threads.
    void stopRace();   // Stops the race and halts all car threads.

    // Adds a car to the race with specified initial position.
    void addCar(int carIndex, int startX, int initialY);

public slots:
    void onCarFinished(int carIndex);

signals:
    void carPositionUpdated(int x, int y, int carIndex); // Emitted for UI position updates

private:
    QVector<Car*> m_cars;            // Collection of car objects in the race
    QVector<CarThread*> m_carThreads; // Threads managing each car's movement
    RaceTrack* m_raceTrack;          // Reference to the race track
    bool m_isRaceOngoing = false;    // Tracks the current race state
};

#endif // RACECONTROLLER_H
