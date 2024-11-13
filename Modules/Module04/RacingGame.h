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

class RacingGame : public QMainWindow
{
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr);
    ~RacingGame();

private slots:
    void startButtonClicked();
    void exitButtonClicked();
    void pauseButtonClicked();

private:
    void initializeScene();
    void connectSignals();
    void setupCars();

private:
    Ui::RacingGame *ui;
    RaceTrack m_raceTrack;
    QGraphicsScene* m_scene;  // Scene for managing graphical items
    int m_numCars = 3;        // Number of cars (can be changed as needed)

    RaceController *m_raceController;// Tracks race status
    TrackView *m_trackView;
    CarDisplayManager* m_carDisplayManager; // Manages car graphics
};

#endif // RACINGGAME_H
