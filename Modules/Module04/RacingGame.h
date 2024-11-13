#ifndef RACINGGAME_H
#define RACINGGAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include "RaceTrack.h"
#include "RaceController.h"
#include "CarDisplayManager.h"
#include "TrackView.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class RacingGame;
}
QT_END_NAMESPACE

// RacingGame provides the main interface for the racing application, handling UI and race coordination.
class RacingGame : public QMainWindow
{
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr); // Sets up UI and initializes components
    ~RacingGame();

private slots:
    void startButtonClicked(); // Initiates the race
    void exitButtonClicked();  // Stops the race and closes the application
    void pauseButtonClicked(); // Pauses the race (to be implemented)

private:
    void initializeScene(); // Configures the graphical scene for display
    void connectSignals();  // Links UI buttons to actions
    void setupCars();       // Sets up car objects in the race

private:
    Ui::RacingGame *ui;                   // Main UI interface
    RaceTrack m_raceTrack;                // Track information
    QGraphicsScene* m_scene;              // Manages graphical items
    int m_numCars = 3;                    // Configurable number of cars

    RaceController *m_raceController;     // Controls race progression
    TrackView *m_trackView;               // Manages track visuals
    CarDisplayManager* m_carDisplayManager; // Handles car graphics
};

#endif // RACINGGAME_H
