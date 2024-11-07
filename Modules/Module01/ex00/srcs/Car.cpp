#include "../includes/Car.hpp"

/* Orthodox Canonical Form */
Car::Car() : speed(0) {}

Car::~Car() {}

Car::Car(const Car& originalCar)
{
	this->name = originalCar.name;
	this->speed = originalCar.speed;
}

Car& Car::operator=(const Car& originalCar)
{
	if (this != &originalCar)
	{
		this->name = originalCar.name;
		this->speed = originalCar.speed;
	}
	return *this;
}


/* ------------------------ */

Car::Car(const std::string& name)
{
	this->name = name;
	this->speed = 0;
}

const std::string& Car::getName(void)
{
	return this->name;
}

unsigned int Car::getSpeed(void)
{
	return this->speed;
}

void Car::setName(const std::string &name)
{
	this->name = name;
}

void Car::setSpeed(unsigned int speed)
{
	this->speed = speed;
}
