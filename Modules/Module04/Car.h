#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QMutex>

// Car represents a vehicle with position, speed, and direction, and handles movement logic.
class Car : public QObject
{
    Q_OBJECT

public:
    Car(QObject* parent = nullptr);

    void setSpeed(int speed);         // Sets the car's speed
    void setDirection(int direction); // Sets the car's direction
    void setPosition(int x, int y);   // Initializes the car's position

    int getX() const;      // Returns the current x-coordinate
    int getY() const;      // Returns the current y-coordinate
    int getSpeed() const;  // Returns the current speed
    void move();           // Updates position based on speed and direction

signals:
    void positionUpdated(int x, int y); // Emitted when the position changes

private:
    int m_speed;       // Current speed of the car
    int m_direction;   // Current direction of movement (in degrees)
    int m_x;           // Current x-coordinate of the car
    int m_y;           // Current y-coordinate of the car

    QMutex m_mutex;    // Mutex for ensuring thread safety during movement updates
};

#endif // CAR_H
