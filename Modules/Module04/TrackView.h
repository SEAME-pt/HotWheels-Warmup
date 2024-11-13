#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QGraphicsScene>
#include <QObject>
#include "RaceTrack.h"

class TrackView : public QObject
{
    Q_OBJECT

public:
    TrackView(QGraphicsScene* scene, RaceTrack* raceTrack, int carCount, QObject* parent = nullptr);

    // Method to initialize the entire track view
    void initializeTrackView();

    // Methods to draw specific parts of the track
    void drawTrackBackground();
    void drawStartLine();
    void drawFinishLine();

    // Method to calculate track height based on car count and spacing
    int calculateHeight(int carDiameter = 20, int spacing = 10) const;

private:
    QGraphicsScene* m_scene;  // The scene where the track elements are drawn
    int m_carCount;           // Number of cars, used to calculate track height
    RaceTrack* m_raceTrack;
};

#endif // TRACKVIEW_H
