#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QThread>
#include "Car.h"
#include "RaceTrack.h"

// CarThread manages the movement of a Car along the RaceTrack in a separate thread.
class CarThread : public QThread
{
    Q_OBJECT

public:
    // Constructs a CarThread to control the specified Car on a given RaceTrack.
    CarThread(Car* car, RaceTrack* raceTrack, QObject* parent = nullptr);
    ~CarThread();

    void stopThread(); // Safely stops the thread's execution loop

signals:
    void finishedRace(); // Emitted when the car reaches the end of the RaceTrack

protected:
    void run() override; // Main loop for updating the car's position

private:
    Car* m_car;             // Car instance controlled by this thread
    RaceTrack* m_raceTrack; // Reference to the RaceTrack for determining finish line
    bool m_shouldRun;       // Flag to control the thread's running state
};

#endif // CARTHREAD_H
