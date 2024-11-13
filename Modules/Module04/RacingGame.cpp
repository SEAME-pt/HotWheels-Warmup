#include "RacingGame.h"
#include "./ui_RacingGame.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>

RacingGame::RacingGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RacingGame)
    , m_raceTrack(50, 400)
{
    this->ui->setupUi(this);
    qDebug() << "[RacingGame] Initializing UI and scene.";

    this->initializeScene();
    this->connectSignals();

    // Set up TrackView to manage visual elements of the race track
    this->m_trackView = new TrackView(this->m_scene, &this->m_raceTrack, this->m_numCars);
    this->m_trackView->initializeTrackView();

    // Initialize CarDisplayManager with the scene
    qDebug() << "[RacingGame] Initializing CarDisplayManager.";
    this->m_carDisplayManager = new CarDisplayManager(this->m_scene);

    // Initialize CarDisplayManager with the scene
    qDebug() << "[RacingGame] Initializing RaceController.";
    this->m_raceController = new RaceController(&this->m_raceTrack, this);

    this->setupCars();
}

RacingGame::~RacingGame()
{
    qDebug() << "[RacingGame] Cleaning up resources in destructor.";
    delete this->m_raceController;
    delete this->m_carDisplayManager;
    delete this->m_trackView;
    delete this->ui;
}

void RacingGame::initializeScene()
{
    qDebug() << "[RacingGame] Setting up the QGraphicsScene.";
    this->m_scene = new QGraphicsScene(this);
    this->ui->racingTrackView->setScene(this->m_scene);
}

void RacingGame::connectSignals()
{
    qDebug() << "[RacingGame] Connecting UI signals to slots.";
    connect(this->ui->startButton, &QPushButton::clicked, this, &RacingGame::startButtonClicked);
    connect(this->ui->exitButton, &QPushButton::clicked, this, &RacingGame::exitButtonClicked);
    connect(this->ui->pauseButton, &QPushButton::clicked, this, &RacingGame::pauseButtonClicked);
}

void RacingGame::setupCars()
{
    qDebug() << "[RacingGame] Setting up cars and CarThreads.";

    int startX = this->m_raceTrack.getXStart();
    int carDiameter = 20;
    int spacing = 10;

    // Initialize car graphics in the CarDisplayManager
    this->m_carDisplayManager->initializeCars(this->m_numCars, startX, carDiameter, spacing);

    // Connect RaceController's position update signal to the UI update slot
    connect(this->m_raceController, &RaceController::carPositionUpdated, this, [=](int x, int y, int carIndex) {
        qDebug() << "[RacingGame] Updating car position in UI for car index" << carIndex << ": x =" << x << ", y =" << y;
        this->m_carDisplayManager->updateCarPosition(x, y, carIndex);
    });

    for (int i = 0; i < this->m_numCars; ++i) {
        int initialY = spacing + i * (carDiameter + spacing);
        this->m_raceController->addCar(i, startX, initialY); // Call addCar for each car
    }
}

void RacingGame::startButtonClicked()
{
    qDebug() << "[RacingGame] Start button clicked.";
    this->m_raceController->startRace();

    // Update button states for an ongoing race
    this->ui->startButton->setEnabled(false);  // Disable start button
    this->ui->pauseButton->setEnabled(true);   // Enable pause button
}

void RacingGame::pauseButtonClicked()
{
    qDebug() << "[RacingGame] Pause button clicked.";

    // Placeholder for pausing race logic
    // You might add a call like this->m_raceController->pauseRace(); in the future.

    // Example toggle:
    this->ui->pauseButton->setEnabled(false);  // Disable pause button when paused
    this->ui->startButton->setEnabled(true);   // Enable start button if you want to allow resuming
}

void RacingGame::exitButtonClicked()
{
    qDebug() << "[RacingGame] Exit button clicked, stopping race.";
    this->m_raceController->stopRace();       // Ensure all threads are stopped

    // Disable buttons upon exit to prevent further interaction
    this->ui->startButton->setEnabled(false);
    this->ui->pauseButton->setEnabled(false);

    QApplication::quit();   // Close the application
}

