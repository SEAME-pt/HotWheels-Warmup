#ifndef CARDISPLAYMANAGER_H
#define CARDISPLAYMANAGER_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QVector>

// CarDisplayManager manages the graphical representation of cars within a scene.
class CarDisplayManager
{
public:
    // Constructs CarDisplayManager with a specified scene for displaying cars.
    CarDisplayManager(QGraphicsScene* scene);
    ~CarDisplayManager();

    // Initializes car display items in the scene with the specified properties.
    void initializeCars(int numCars, int startX, int carDiameter, int spacing);
    void resetCars(int numCars, int startX, int carDiameter, int spacing);

    // Updates the graphical position of the car at carIndex.
    void updateCarPosition(int x, int y, int carIndex);

    // Clears all car graphics items from the scene.
    void clearCars();

private:
    QGraphicsScene* m_scene;                     // Scene where cars are displayed
    QVector<QGraphicsEllipseItem*> m_carItems;   // Ellipse items representing each car
};

#endif // CARDISPLAYMANAGER_H
