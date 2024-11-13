#include "RaceTrack.h"

RaceTrack::RaceTrack(int xStart, int size)
    : m_xStart(xStart)
    , m_size(size)
{
}

int RaceTrack::getXStart() const
{
    return m_xStart;
}

int RaceTrack::getSize() const
{
    return m_size;
}
