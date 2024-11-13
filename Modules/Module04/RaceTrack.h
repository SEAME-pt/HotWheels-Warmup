#ifndef RACETRACK_H
#define RACETRACK_H

// RaceTrack defines the starting position and length of the race track.
class RaceTrack {
public:
    // Constructs a RaceTrack with a specified start position and length.
    RaceTrack(int xStart, int size);

    int getXStart() const; // Returns the starting x-coordinate of the track.
    int getSize() const;   // Returns the length of the track.

private:
    int m_xStart; // Starting x-coordinate of the track
    int m_size;   // Length of the track
};

#endif // RACETRACK_H
