#include "CarSetupManager.h"
#include <QDebug>

CarSetupManager::CarSetupManager(QGraphicsScene* scene, RaceTrack* raceTrack, RaceController* raceController, int numCars, QObject* parent)
    : QObject(parent)
    , m_scene(scene)
    , m_raceTrack(raceTrack)
    , m_raceController(raceController)
    , m_numCars(numCars)
{
    this->m_carDisplayManager = new CarDisplayManager(this->m_scene);
    qDebug() << "[CarSetupManager] Initialized with" << this->m_numCars << "cars.";
}

void CarSetupManager::setupCars()
{
    qDebug() << "[CarSetupManager] Setting up cars and CarDisplayManager.";

    int startX = this->m_raceTrack->getXStart();
    int carDiameter = 20;
    int spacing = 10;

    // Initialize car graphics in the CarDisplayManager
    this->m_carDisplayManager->initializeCars(this->m_numCars, startX, carDiameter, spacing);

    // Connect RaceController's position update signal to update car positions in the UI
    connect(this->m_raceController,
            &RaceController::carPositionUpdated,
            this,
            [=](int x, int y, int carIndex) {
                // qDebug() << "[CarSetupManager] Updating car position in UI for car index" << carIndex << ": x =" << x << ", y =" << y;
                this->m_carDisplayManager->updateCarPosition(x, y, carIndex);
            });

    // Add cars to RaceController with their initial positions
    for (int i = 0; i < this->m_numCars; ++i) {
        int initialY = spacing + i * (carDiameter + spacing);
        this->m_raceController->addCar(i, startX, initialY);
    }
}
