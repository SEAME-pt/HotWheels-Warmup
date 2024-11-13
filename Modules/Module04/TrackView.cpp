#include "TrackView.h"
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>
#include <QDebug>

TrackView::TrackView(QGraphicsScene* scene, RaceTrack *raceTrack, int carCount, QObject* parent)
    : QObject(parent)
    , m_scene(scene)
    , m_raceTrack(raceTrack)
    , m_carCount(carCount)
{
    qDebug() << "[TrackView] Initialized with track length:" << this->m_raceTrack->getSize()
             << "and calculated track height:" << this->calculateHeight();
}

void TrackView::initializeTrackView()
{
    qDebug() << "[TrackView] Initializing track view.";
    this->drawTrackBackground();
    this->drawStartLine();
    this->drawFinishLine();
}

void TrackView::drawTrackBackground()
{
    int padding = 20; // Padding around the track for borders
    int backgroundWidth = this->m_raceTrack->getSize() + 2 * padding;
    int backgroundHeight = this->calculateHeight() + 2 * padding;
    int backgroundX = this->m_raceTrack->getXStart() - padding;
    int backgroundY = 5 - padding;

    qDebug() << "[TrackView] Drawing track background at (" << backgroundX << "," << backgroundY
             << ") with width =" << backgroundWidth << "and height =" << backgroundHeight;

    QGraphicsRectItem* background = new QGraphicsRectItem(backgroundX, backgroundY, backgroundWidth, backgroundHeight);
    background->setBrush(QBrush(Qt::lightGray));
    background->setPen(Qt::NoPen);
    this->m_scene->addItem(background);
}

void TrackView::drawStartLine()
{
    int startX = this->m_raceTrack->getXStart();
    qDebug() << "[TrackView] Drawing start line at x =" << startX;

    this->m_scene->addRect(startX, 5, 1, this->calculateHeight(), QPen(Qt::green), QBrush(Qt::green));
}

void TrackView::drawFinishLine()
{
     int finishX = this->m_raceTrack->getXStart() + this->m_raceTrack->getSize();
    qDebug() << "[TrackView] Drawing finish line at x =" << finishX;

    this->m_scene->addRect(finishX, 5, 1, this->calculateHeight(), QPen(Qt::red), QBrush(Qt::red));
}

int TrackView::calculateHeight(int carDiameter, int spacing) const
{
    int trackHeight = (this->m_carCount * carDiameter) + ((this->m_carCount + 1) * spacing);
    qDebug() << "[TrackView] Calculated track height:" << trackHeight << "for car count:" << this->m_carCount;
    return trackHeight;
}
