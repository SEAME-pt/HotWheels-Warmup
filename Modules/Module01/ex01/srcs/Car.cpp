#include "../includes/Car.hpp"

/* Orthodox Canonical Form */
Car::Car() : make("Renault"), model("Megane"), year(2008) {}

Car::~Car() {}

Car::Car(const Car& originalCar)
{
	this->make = originalCar.make;
	this->model = originalCar.model;
	this->year = originalCar.year;
}

Car& Car::operator=(const Car& originalCar)
{
	if (this != &originalCar)
	{
		this->make = originalCar.make;
        this->model = originalCar.model;
        this->year = originalCar.year;
	}
	return *this;
}


/* ------------------------ */

Car::Car(const std::string &make, const std::string &model, int year) : make(make), model(model), year(year) {};

void Car::drive() const
{
    std::cout << "Driving a " << this->make << " " << this->model << " " << this->year << std::endl;
}