#ifndef CARSETUPMANAGER_H
#define CARSETUPMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include "RaceController.h"
#include "CarDisplayManager.h"
#include "RaceTrack.h"

// CarSetupManager manages the initialization and display of cars in the race.
class CarSetupManager : public QObject
{
    Q_OBJECT

public:
    // Constructs CarSetupManager to handle car setup and display management.
    CarSetupManager(QGraphicsScene* scene, RaceTrack* raceTrack, RaceController* raceController, int numCars, QObject* parent = nullptr);

    void setupCars(); // Sets up cars with display items and connects position updates
    void resetCarsPositions();

private:
    QGraphicsScene* m_scene;                // Scene where car items are displayed
    RaceTrack* m_raceTrack;                 // Reference to the race track configuration
    RaceController* m_raceController;       // Manages car logic and race control
    CarDisplayManager* m_carDisplayManager; // Manages graphical display of cars
    int m_numCars;                          // Total number of cars in the race
};

#endif // CARSETUPMANAGER_H
