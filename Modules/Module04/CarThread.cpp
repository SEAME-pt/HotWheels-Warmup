#include "CarThread.h"
#include <QDebug>

CarThread::CarThread(Car* car, RaceTrack* raceTrack, QObject* parent)
    : QThread(parent)
    , m_car(car)
    , m_raceTrack(raceTrack)
    , m_shouldRun(true)
{
    qDebug() << "[CarThread] CarThread created for race track with finish line at:"
             << m_raceTrack->getXStart() + m_raceTrack->getSize();
}

CarThread::~CarThread()
{
    qDebug() << "[CarThread] Destructor called, stopping thread.";
    m_shouldRun = false;
    quit(); // Request thread to stop
    wait(); // Block until thread finishes
}

void CarThread::stopThread()
{
    this->m_shouldRun = false; // Sets flag to stop the main loop in run()
}

void CarThread::run()
{
    qDebug() << "[CarThread] Thread started for car with initial position ("
             << m_car->getX() << "," << m_car->getY() << ")";

    // Main loop for car movement
    while (m_shouldRun) {
        m_car->move();
        qDebug() << "[CarThread] Car position updated to (" << m_car->getX() << "," << m_car->getY() << ")";

        // Check if the car has crossed the finish line
        int finishLineX = m_raceTrack->getXStart() + m_raceTrack->getSize();
        if (m_car->getX() >= finishLineX) {
            qDebug() << "[CarThread] Car reached the end of the track at position x =" << m_car->getX();
            emit finishedRace(); // Signal completion of race
            m_shouldRun = false;
            break;
        }

        this->msleep(50); // Controls update rate (20 frames per second)
    }
}
