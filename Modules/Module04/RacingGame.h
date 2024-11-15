#ifndef RACINGGAME_H
#define RACINGGAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include "RaceTrack.h"
#include "RaceController.h"
#include "CarSetupManager.h"
#include "TrackView.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class RacingGame;
}
QT_END_NAMESPACE

// RacingGame provides the main interface for the racing application, handling UI components and high-level race coordination.
class RacingGame : public QMainWindow
{
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr); // Sets up the UI and initializes core components
    ~RacingGame();

private slots:
    void startButtonClicked(); // Starts the race by triggering RaceController
    void exitButtonClicked();  // Stops the race and exits the application
    void pauseButtonClicked(); // Pauses the race
    void resetButtonClicked();

    void onRaceFinished();

private:
    void initializeScene(); // Configures the graphical scene for track and car display
    void connectSignals();  // Connects UI buttons to their respective actions

private:
    Ui::RacingGame *ui;                    // Main UI interface
    RaceTrack m_raceTrack;                 // Holds track configuration
    QGraphicsScene* m_scene;               // Scene for managing graphics
    int m_numCars = 5;                     // Number of cars in the race

    RaceController *m_raceController;      // Manages race progression and car movement
    TrackView *m_trackView;                // Displays the visual elements of the track
    CarSetupManager* m_carSetupManager;    // Handles car initialization and display setup
};

#endif // RACINGGAME_H
