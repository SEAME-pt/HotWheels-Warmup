#include "CarDisplayManager.h"

CarDisplayManager::CarDisplayManager(QGraphicsScene* scene)
    : m_scene(scene)
{
}

CarDisplayManager::~CarDisplayManager()
{
    this->clearCars();
}

void CarDisplayManager::initializeCars(int numCars, int startX, int carDiameter, int spacing)
{
    this->clearCars(); // Clear any existing items

    for (int i = 0; i < numCars; ++i) {
        int yPosition = spacing + i * (carDiameter + spacing);
        QGraphicsEllipseItem* carItem = new QGraphicsEllipseItem(startX, yPosition, carDiameter, carDiameter);
        carItem->setBrush(Qt::blue);
        this->m_scene->addItem(carItem);
        this->m_carItems.append(carItem);
    }
}

void CarDisplayManager::updateCarPosition(int x, int y, int carIndex)
{
    if (carIndex >= 0 && carIndex < this->m_carItems.size()) {
        QGraphicsEllipseItem* carItem = this->m_carItems[carIndex];
        carItem->setRect(x, y, carItem->rect().width(), carItem->rect().height());
    }
}

void CarDisplayManager::clearCars()
{
    for (QGraphicsEllipseItem* carItem : this->m_carItems) {
        delete carItem;
    }
    this->m_carItems.clear();
}
