#ifndef CARDISPLAYMANAGER_H
#define CARDISPLAYMANAGER_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QVector>

class CarDisplayManager
{
public:
    CarDisplayManager(QGraphicsScene* scene);
    ~CarDisplayManager();

    // Initializes car display items in the scene
    void initializeCars(int numCars, int startX, int carDiameter, int spacing);

    // Updates the position of a specific car
    void updateCarPosition(int x, int y, int carIndex);

    // Clears all car items from the scene
    void clearCars();

private:
    QGraphicsScene* m_scene;  // Scene where the cars are displayed
    QVector<QGraphicsEllipseItem*> m_carItems; // Stores ellipse items for each car
};

#endif // CARDISPLAYMANAGER_H
