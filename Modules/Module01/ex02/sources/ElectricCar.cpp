#include "../includes/ElectricCar.hpp"

/* Orthodox Canonical Form */

ElectricCar::ElectricCar() : ACar(), batteryCapacity(10) {}

ElectricCar::~ElectricCar() {}

ElectricCar::ElectricCar(const ElectricCar& originalElectricCar) : ACar(originalElectricCar), batteryCapacity(originalElectricCar.batteryCapacity) {}

ElectricCar& ElectricCar::operator=(const ElectricCar& originalElectricCar)
{
	if (this != &originalElectricCar)
	{
        ACar::operator=(originalElectricCar);
        this->batteryCapacity = originalElectricCar.batteryCapacity;
	}
	return *this;
}

/* ------------------------ */

ElectricCar::ElectricCar(const std::string& carMake, const std::string& carModel, int carYear, int carbatteryCapacity) : ACar(carMake, carModel, carYear), batteryCapacity(carbatteryCapacity) {}

void ElectricCar::drive() const
{
    std::cout << "Driving a " << this->make << " " << this->model << " (" << this->year << ") " << std::endl;
    std::cout << "Battery capacity: " << this->batteryCapacity << " kW/h !!" << std::endl;
}