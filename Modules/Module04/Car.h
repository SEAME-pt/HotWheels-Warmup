#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QMutex>

class Car : public QObject
{
    Q_OBJECT

public:
    Car(QObject* parent = nullptr);
    void setSpeed(int speed);
    void setDirection(int direction);
    void setPosition(int x, int y); // Method to set initial position

    int getX() const;
    int getY() const;
    int getSpeed() const;
    void move(); // Method that updates position

signals:
    void positionUpdated(int x, int y);

private:
    int m_speed;
    int m_direction;
    int m_x;
    int m_y;

    QMutex m_mutex; // Mutex for thread safety
};


#endif // CAR_H
