#include "RaceController.h"
#include <QDebug>
#include "Utils.h"

RaceController::RaceController(RaceTrack *raceTrack, QObject *parent)
    : QObject(parent)
    , m_raceTrack(raceTrack)
    , m_isRaceOngoing(false)
{
    qDebug() << "[RaceController] Initialized with race track.";
}

RaceController::~RaceController()
{
    qDebug() << "[RaceController] Cleaning up cars and threads.";
    for (Car *car : this->m_cars) {
        delete car;
    }
    this->m_cars.clear();
    for (CarThread *carThread : this->m_carThreads) {
        if (carThread && carThread->isRunning()) {
            qDebug() << "[RaceController] Stopping thread.";
            carThread->quit();
            carThread->wait();
        }
        Utils::safeDelete(carThread);
    }
    this->m_carThreads.clear();
}

void RaceController::onCarFinished(int carIndex)
{
    if (carIndex >= 0 && carIndex < this->m_carThreads.size()) {
        CarThread *carThread = this->m_carThreads[carIndex];

        if (carThread->isRunning()) {
            carThread->stopThread(); // Stop the car's movement loop
            carThread->quit();       // Request the thread to exit
            carThread->wait();       // Wait for the thread to finish
        }

        qDebug() << "[RaceController] Stopped CarThread for car index:" << carIndex;
    }

    // Update the car's finished state
    if (carIndex >= 0 && carIndex < this->m_carFinishedStates.size()) {
        this->m_carFinishedStates[carIndex] = true;
    }

    // Check if all cars are finished
    bool isRaceFinished = std::all_of(this->m_carFinishedStates.begin(),
                                      this->m_carFinishedStates.end(),
                                      [](bool finished) { return finished; });

    if (isRaceFinished) {
        qDebug() << "[RaceController] All cars have finished the race!";
        emit allCarsFinished(); // Emit a signal if needed
    }
}

void RaceController::startRace()
{
    qDebug() << "[RaceController] Starting the race.";
    this->m_isRaceOngoing = true;

    // Starts each CarThread if it is not already running
    for (int i = 0; i < this->m_carThreads.size(); ++i) {
        CarThread *carThread = this->m_carThreads[i];
        if (!carThread->isRunning()) {
            qDebug() << "[RaceController] Starting CarThread for car index:" << i;
            carThread->start();
                carThread->restartThread();
        }
    }
}

void RaceController::pauseRace()
{
    qDebug() << "[RaceController] Pausing the race.";

    for (CarThread *carThread : this->m_carThreads) {
        if (carThread->isRunning()) {
            qDebug() << "[RaceController] Stopping thread.";
            carThread->stopThread(); // Set the stop flag
            carThread->quit();       // Request thread to exit
            carThread->wait();       // Wait until the thread exits
        }
    }

    qDebug() << "[RaceController] Race paused.";
}

void RaceController::stopRace()
{
    qDebug() << "[RaceController] Stopping the race.";

    // Stops each CarThread, ensuring it has time to exit cleanly
    for (CarThread *carThread : this->m_carThreads) {
        if (carThread->isRunning()) {
            qDebug() << "[RaceController] Stopping thread.";
            carThread->stopThread(); // Set the stop flag
            carThread->quit();       // Request thread to exit
            carThread->wait();       // Wait until the thread exits
        }
    }
    this->m_isRaceOngoing = false;
    qDebug() << "[RaceController] Race stopped.";
}

void RaceController::addCar(int carIndex, int startX, int startY)
{
    Car *car = new Car();
    car->setPosition(startX, startY);
    car->setSpeed(10 + carIndex * 5);
    car->setDirection(0);
    this->m_cars.append(car);

    CarThread *carThread = new CarThread(car, this->m_raceTrack);
    this->m_carThreads.append(carThread);

    this->m_carFinishedStates.append(false); // Mark the car as not finished

    // Relays car position updates through RaceController for UI updates
    connect(car, &Car::positionUpdated, this, [=](int x, int y) {
        qDebug() << "[RaceController] Car with index" << carIndex << "moved!";
        emit carPositionUpdated(x, y, carIndex);
    });

    // Emits carFinished signal when a car completes the race
    connect(carThread, &CarThread::finishedRace, this, [=]() {
        qDebug() << "[RaceController] Car with index" << carIndex << "finished the race!";
        this->onCarFinished(carIndex);
    });

    qDebug() << "[RaceController] Added car with index" << carIndex << "at initial position ("
             << startX << "," << startY << ")";
}

void RaceController::resetCars(int startX, int spacing, int carDiameter)
{
    qDebug() << "[RaceController] Reset cars positions.";
    for (int i = 0; i < this->m_cars.size(); ++i) {
        int initialY = spacing + i * (carDiameter + spacing);
        Car *car = this->m_cars[i];
        car->setPosition(startX, initialY);
    }

    this->m_carFinishedStates.fill(false, this->m_cars.size());
}
