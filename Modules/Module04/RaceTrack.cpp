#include "RaceTrack.h"
#include <QDebug>

RaceTrack::RaceTrack(int xStart, int size)
    : m_xStart(xStart)
    , m_size(size)
{
}

RaceTrack::~RaceTrack()
{
    qDebug() << "[RaceTrack] Destructor called.";
}

int RaceTrack::getXStart() const
{
    return m_xStart;
}

int RaceTrack::getSize() const
{
    return m_size;
}
