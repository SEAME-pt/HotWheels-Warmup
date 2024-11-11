#include "../includes/SportsCar.hpp"

/* Orthodox Canonical Form */

SportsCar::SportsCar() : Car(), topSpeed(10) {}

SportsCar::~SportsCar() {}

SportsCar::SportsCar(const SportsCar& originalSportsCar) : Car(originalSportsCar), topSpeed(originalSportsCar.topSpeed) {}

SportsCar& SportsCar::operator=(const SportsCar& originalSportsCar)
{
	if (this != &originalSportsCar)
	{
        Car::operator=(originalSportsCar);
        this->topSpeed = originalSportsCar.topSpeed;
	}
	return *this;
}

/* ------------------------ */

SportsCar::SportsCar(const std::string& carMake, const std::string& carModel, int carYear, int carTopSpeed) : Car(carMake, carModel, carYear), topSpeed(carTopSpeed) {}

void SportsCar::drive() const
{
    Car::drive();
    std::cout << "Top speed: " << this->topSpeed << "km/h !!"<< std::endl;
}