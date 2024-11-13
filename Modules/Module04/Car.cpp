#include "Car.h"
#include <QDebug>
#include <cmath>

Car::Car(QObject* parent)
    : QObject(parent)
    , m_speed(0)
    , m_direction(0)
    , m_x(0)
    , m_y(0)
{
    qDebug() << "[Car] Car object created with initial position (0, 0)";
}

void Car::setSpeed(int speed)
{
    m_speed = speed;
    qDebug() << "[Car] Speed set to:" << m_speed;
}

void Car::setDirection(int direction)
{
    m_direction = direction;
    qDebug() << "[Car] Direction set to:" << m_direction;
}

void Car::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    qDebug() << "[Car] Initial position set to (" << m_x << "," << m_y << ")";
}

int Car::getSpeed() const
{
    qDebug() << "[Car] getSpeed called. Current speed:" << m_speed;
    return m_speed;
}

int Car::getX() const
{
    qDebug() << "[Car] getX called. Current X:" << m_x;
    return m_x;
}

int Car::getY() const
{
    qDebug() << "[Car] getY called. Current Y:" << m_y;
    return m_y;
}

void Car::move()
{
    m_mutex.lock(); // Lock for thread-safe position update

    // Calculate the new position based on current speed and direction
    int oldX = m_x;
    int oldY = m_y;
    m_x += m_speed * std::cos(m_direction * M_PI / 180.0);
    m_y += m_speed * std::sin(m_direction * M_PI / 180.0);

    qDebug() << "[Car] Moving car from (" << oldX << "," << oldY << ") to (" << m_x << "," << m_y << ") with speed =" << m_speed << "and direction =" << m_direction;

    emit positionUpdated(m_x, m_y); // Emit updated position

    m_mutex.unlock(); // Unlock after updating position
}
