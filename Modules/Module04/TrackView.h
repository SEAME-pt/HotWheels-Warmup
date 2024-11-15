#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QGraphicsScene>
#include <QObject>
#include "RaceTrack.h"

// TrackView manages the visual representation of the race track in the scene.
class TrackView : public QObject
{
    Q_OBJECT

public:
    // Constructs TrackView with the scene, associated RaceTrack, and car count for height calculation.
    TrackView(QGraphicsScene* scene, RaceTrack* raceTrack, int carCount, QObject* parent = nullptr);

    // Initializes the full track view, including background, start line, and finish line.
    void initializeTrackView();

    // Draws the track background to encompass all visual elements.
    void drawTrackBackground();

    // Draws the starting line at the beginning of the race track.
    void drawStartLine();

    // Draws the finish line at the end of the race track.
    void drawFinishLine();

    // Calculates the track height based on the number of cars and their spacing.
    int calculateHeight(int carDiameter = 20, int spacing = 10) const;

private:
    QGraphicsScene* m_scene;    // Scene where track elements are drawn
    int m_carCount;             // Number of cars for calculating track height
    RaceTrack* m_raceTrack;     // Reference to the RaceTrack data
};

#endif // TRACKVIEW_H
