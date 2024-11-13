#include "CarThread.h"
#include <QDebug>

CarThread::CarThread(Car* car, RaceTrack* raceTrack, QObject* parent)
    : QThread(parent)
    , m_car(car)
    , m_raceTrack(raceTrack) // Store the entire RaceTrack
    , m_shouldRun(true)
{
    qDebug() << "[CarThread] CarThread created for race track with finish line at:"
             << m_raceTrack->getXStart() + m_raceTrack->getSize();
}

CarThread::~CarThread()
{
    qDebug() << "[CarThread] Destructor called, stopping thread.";
    m_shouldRun = false;
    quit();
    wait();
}

void CarThread::stopThread()
{
    this->m_shouldRun = false;
}

void CarThread::run()
{
    qDebug() << "[CarThread] Thread started for car with initial position ("
             << m_car->getX() << "," << m_car->getY() << ")";

    // Main loop for car movement
    while (m_shouldRun) {
        m_car->move(); // Move the car based on its speed and direction
        qDebug() << "[CarThread] Car position updated to (" << m_car->getX() << "," << m_car->getY() << ")";

        // Check if car has reached the end of the track using the finish line from RaceTrack
        int finishLineX = m_raceTrack->getXStart() + m_raceTrack->getSize();
        if (m_car->getX() >= finishLineX) {
            qDebug() << "[CarThread] Car reached the end of the track at position x =" << m_car->getX();
            emit finishedRace(); // Signal that this car has finished the race
            m_shouldRun = false; // Stop the loop
            break;
        }

        this->msleep(50); // Sleep to control the update rate (20 updates per second)
    }
}
