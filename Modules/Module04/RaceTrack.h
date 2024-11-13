#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack {
public:
    RaceTrack(int xStart, int size);

    int getXStart() const;
    int getSize() const;

private:
    int m_xStart;
    int m_size;
};

#endif // RACETRACK_H
