#include "CarThread.h"
#include <QDebug>

CarThread::CarThread(Car *car, RaceTrack *raceTrack, QObject *parent)
    : QThread(parent)
    , m_car(car)
    , m_raceTrack(raceTrack)
    , m_shouldRun(true)
{
    qDebug() << "[CarThread] CarThread created for race track with finish line at:"
             << this->m_raceTrack->getXStart() + this->m_raceTrack->getSize();
}

CarThread::~CarThread()
{
    qDebug() << "[CarThread] Destructor called.";
    this->m_shouldRun = false;
    if (this->isRunning()) {
        qDebug() << "[CarThread] Stopping thread.";
        this->quit(); // Request thread to stop
        this->wait(); // Block until thread finishes
    }
}

void CarThread::stopThread()
{
    this->m_shouldRun = false; // Sets flag to stop the main loop in run()
}

void CarThread::restartThread()
{
    this->m_shouldRun = true; // Sets flag to restart the main loop in run()
}

void CarThread::run()
{
    qDebug() << "[CarThread] Thread started for car with initial position (" << this->m_car->getX()
             << "," << this->m_car->getY() << ")";

    // Main loop for car movement
    while (m_shouldRun) {
        this->m_car->move();
        // qDebug() << "[CarThread] Car position updated to (" << m_car->getX() << "," << m_car->getY()
        //          << ")";

        // Check if the car has crossed the finish line
        int finishLineX = this->m_raceTrack->getXStart() + this->m_raceTrack->getSize();
        if (this->m_car->getX() >= finishLineX) {
            qDebug() << "[CarThread] Car reached the end of the track at position x ="
                     << m_car->getX();
            emit this->finishedRace(); // Signal completion of race
            this->m_shouldRun = false;
            break;
        }

        this->msleep(50); // Controls update rate (20 frames per second)
    }
}
