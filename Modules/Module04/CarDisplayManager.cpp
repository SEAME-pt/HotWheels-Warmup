#include "CarDisplayManager.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "Utils.h"

CarDisplayManager::CarDisplayManager(QGraphicsScene *scene)
    : m_scene(scene)
{}

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

        // Load car image
        QPixmap carPixmap(":/images/car.webp");
        if (carPixmap.isNull()) {
            qDebug() << "[CarDisplayManager] Failed to load car image!";
            continue;
        }

        // Add a QGraphicsPixmapItem for the car
        QGraphicsPixmapItem *carItem = new QGraphicsPixmapItem(
            carPixmap.scaled(carDiameter * 2, carDiameter));
        carItem->setPos(startX, yPosition);
        this->m_scene->addItem(carItem);
        this->m_carItems.append(carItem); // Store the created car item
    }
}

void CarDisplayManager::resetCars(int numCars, int startX, int carDiameter, int spacing)
{
    if (numCars != this->m_carItems.size()) {
        qDebug() << "[CarDisplayManager] Mismatch in number of cars. Reset aborted.";
        return;
    }

    for (int i = 0; i < numCars; ++i) {
        int yPosition = spacing + i * (carDiameter + spacing);
        QGraphicsPixmapItem *carItem = dynamic_cast<QGraphicsPixmapItem *>(this->m_carItems[i]);
        if (carItem) {
            carItem->setPos(startX, yPosition); // Reset the position of the car image
        }
    }

    qDebug() << "[CarDisplayManager] Cars reset to initial positions.";
}

void CarDisplayManager::updateCarPosition(int x, int y, int carIndex)
{
    if (carIndex >= 0 && carIndex < this->m_carItems.size()) {
        QGraphicsPixmapItem *carItem = dynamic_cast<QGraphicsPixmapItem *>(
            this->m_carItems[carIndex]);
        if (carItem) {
            carItem->setPos(x, y); // Update the position of the car image
        }
    }
}

void CarDisplayManager::clearCars()
{
    for (QGraphicsItem *carItem : this->m_carItems) {
        Utils::safeDelete(carItem); // Deletes each car item from the scene
    }
    this->m_carItems.clear(); // Clears the list of car items
}
