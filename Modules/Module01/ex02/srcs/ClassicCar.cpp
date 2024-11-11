#include "../includes/ClassicCar.hpp"

/* Orthodox Canonical Form */

ClassicCar::ClassicCar() : ACar(), topSpeed(10) {}

ClassicCar::~ClassicCar() {}

ClassicCar::ClassicCar(const ClassicCar& originalClassicCar) : ACar(originalClassicCar), topSpeed(originalClassicCar.topSpeed) {}

ClassicCar& ClassicCar::operator=(const ClassicCar& originalClassicCar)
{
	if (this != &originalClassicCar)
	{
        ACar::operator=(originalClassicCar);
        this->topSpeed = originalClassicCar.topSpeed;
	}
	return *this;
}

/* ------------------------ */

ClassicCar::ClassicCar(const std::string& carMake, const std::string& carModel, int carYear, int carTopSpeed) : ACar(carMake, carModel, carYear), topSpeed(carTopSpeed) {}

void ClassicCar::drive() const
{
    std::cout << "Driving a " << this->make << " " << this->model << " (" << this->year << ") " << std::endl;
    std::cout << "Top speed: " << this->topSpeed << " km/h !!" << std::endl;
}