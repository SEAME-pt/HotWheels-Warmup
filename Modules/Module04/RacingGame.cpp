#include "RacingGame.h"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include "./ui_RacingGame.h"
#include "Utils.h"

RacingGame::RacingGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RacingGame)
    , m_raceTrack(50, 400)
{
    this->ui->setupUi(this);
    qDebug() << "[RacingGame] Initializing UI and scene.";

    this->initializeScene();
    this->connectSignals();

    this->ui->pauseButton->setEnabled(false);
    this->ui->resetButton->setEnabled(false);

    // Set up TrackView for managing visual elements of the race track
    this->m_trackView = new TrackView(this->m_scene, &this->m_raceTrack, this->m_numCars);
    this->m_trackView->initializeTrackView();

    // Initialize RaceController to manage race logic
    qDebug() << "[RacingGame] Initializing RaceController.";
    this->m_raceController = new RaceController(&this->m_raceTrack, this);
    // Connect RaceController's signal to RacingGame's slot
    connect(this->m_raceController,
            &RaceController::allCarsFinished,
            this,
            &RacingGame::onRaceFinished);

    // Initialize CarSetupManager to handle car setup and display
    qDebug() << "[RacingGame] Initializing CarSetupManager.";
    this->m_carSetupManager = new CarSetupManager(this->m_scene,
                                                  &this->m_raceTrack,
                                                  this->m_raceController,
                                                  this->m_numCars,
                                                  this);
    this->m_carSetupManager->setupCars();
}

RacingGame::~RacingGame()
{
    qDebug() << "[RacingGame] Cleaning up resources in the destructor.";
    Utils::safeDelete(m_trackView);
    Utils::safeDelete(ui);
}

void RacingGame::initializeScene()
{
    qDebug() << "[RacingGame] Setting up the QGraphicsScene.";
    this->m_scene = new QGraphicsScene(this);
    this->ui->racingTrackView->setScene(this->m_scene);
    this->ui->racingTrackView->setBackgroundBrush(Qt::lightGray);
}

void RacingGame::connectSignals()
{
    qDebug() << "[RacingGame] Connecting UI signals to slots.";
    connect(this->ui->startButton, &QPushButton::clicked, this, &RacingGame::startButtonClicked);
    connect(this->ui->exitButton, &QPushButton::clicked, this, &RacingGame::exitButtonClicked);
    connect(this->ui->pauseButton, &QPushButton::clicked, this, &RacingGame::pauseButtonClicked);
    connect(this->ui->resetButton, &QPushButton::clicked, this, &RacingGame::resetButtonClicked);
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

    this->m_raceController->pauseRace();

    // Toggle button states for paused state
    this->ui->pauseButton->setEnabled(false);  // Disable pause button
    this->ui->startButton->setEnabled(true);   // Enable start button
    this->ui->startButton->setText("Resume");
}

void RacingGame::exitButtonClicked()
{
    qDebug() << "[RacingGame] Exit button clicked, stopping race.";
    this->m_raceController->stopRace(); // Ensure all threads are stopped

    // Disable buttons upon exit to prevent further interaction
    this->ui->startButton->setEnabled(false);
    this->ui->pauseButton->setEnabled(false);

    QApplication::quit(); // Close the application
}

void RacingGame::resetButtonClicked()
{
    qDebug() << "[RacingGame] Reset button clicked, restarting race.";

    this->m_carSetupManager->resetCarsPositions();
    this->ui->startButton->setEnabled(true);
    this->ui->resetButton->setEnabled(false);
    this->ui->startButton->setText("Start");
}

void RacingGame::onRaceFinished()
{
    qDebug() << "[RacingGame] All cars have finished the race!";

    this->ui->pauseButton->setEnabled(false);
    this->ui->startButton->setEnabled(false);
    this->ui->resetButton->setEnabled(true);
}
