#include "CarDisplayManager.h"

CarDisplayManager::CarDisplayManager(QGraphicsScene* scene)
    : m_scene(scene)
{
}

CarDisplayManager::~CarDisplayManager()
{
    qDebug() << "[CarDisplayManager] Destructor called.";
    this->clearCars(); // Ensures all car items are removed from the scene
}

void CarDisplayManager::initializeCars(int numCars, int startX, int carDiameter, int spacing)
{
    this->clearCars(); // Remove existing car items before initializing new ones

    for (int i = 0; i < numCars; ++i) {
        int yPosition = spacing + i * (carDiameter + spacing);
        QGraphicsEllipseItem* carItem = new QGraphicsEllipseItem(startX, yPosition, carDiameter, carDiameter);
        carItem->setBrush(Qt::blue); // Sets the car color to blue
        this->m_scene->addItem(carItem);
        this->m_carItems.append(carItem); // Store the created car item
    }
}

void CarDisplayManager::updateCarPosition(int x, int y, int carIndex)
{
    if (carIndex >= 0 && carIndex < this->m_carItems.size()) {
        QGraphicsEllipseItem* carItem = this->m_carItems[carIndex];
        // Updates the car position while preserving its size
        carItem->setRect(x, y, carItem->rect().width(), carItem->rect().height());
    }
}

void CarDisplayManager::clearCars()
{
    for (QGraphicsEllipseItem* carItem : this->m_carItems) {
        delete carItem; // Deletes each car item from the scene
    }
    this->m_carItems.clear(); // Clears the list of car items
}
