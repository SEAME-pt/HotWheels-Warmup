#include "RaceController.h"
#include <QDebug>

RaceController::RaceController(RaceTrack* raceTrack, QObject* parent)
    : QObject(parent)
    , m_raceTrack(raceTrack)
    , m_isRaceOngoing(false)
{
    qDebug() << "[RaceController] Initialized with race track.";
}

RaceController::~RaceController()
{
    qDebug() << "[RaceController] Cleaning up cars and threads.";
    for (Car* car : this->m_cars) {
        delete car;
    }
    for (CarThread* carThread : this->m_carThreads) {
        carThread->quit();
        carThread->wait();
        delete carThread;
    }
}

void RaceController::startRace()
{
    qDebug() << "[RaceController] Starting the race.";
    this->m_isRaceOngoing = true;

    // Starts each CarThread if it is not already running
    for (int i = 0; i < this->m_carThreads.size(); ++i) {
        CarThread* carThread = this->m_carThreads[i];
        if (!carThread->isRunning()) {
            qDebug() << "[RaceController] Starting CarThread for car index:" << i;
            carThread->start();
        }
    }
}

void RaceController::stopRace()
{
    qDebug() << "[RaceController] Stopping the race.";

    // Stops each CarThread, ensuring it has time to exit cleanly
    for (int i = 0; i < this->m_carThreads.size(); ++i) {
        CarThread* carThread = this->m_carThreads[i];
        if (carThread->isRunning()) {
            qDebug() << "[RaceController] Stopping CarThread for car index:" << i;
            carThread->quit();
            carThread->wait();
        }
    }
    this->m_isRaceOngoing = false;
    qDebug() << "[RaceController] Race stopped.";
}

void RaceController::addCar(int carIndex, int startX, int initialY)
{
    Car* car = new Car();
    car->setPosition(startX, initialY);
    car->setSpeed(10 + carIndex * 5);
    car->setDirection(0);
    this->m_cars.append(car);

    CarThread* carThread = new CarThread(car, this->m_raceTrack);
    this->m_carThreads.append(carThread);

    // Relays car position updates through RaceController for UI updates
    connect(car, &Car::positionUpdated, this, [=](int x, int y) {
        emit carPositionUpdated(x, y, carIndex);
    });

    // Emits carFinished signal when a car completes the race
    connect(carThread, &CarThread::finishedRace, this, [=]() {
        qDebug() << "[RaceController] Car with index" << carIndex << "finished the race!";
        emit carFinished(carIndex);
    });

    qDebug() << "[RaceController] Added car with index" << carIndex << "at initial position (" << startX << "," << initialY << ")";
}
