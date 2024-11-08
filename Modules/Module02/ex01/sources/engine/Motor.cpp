#include "Motor.hpp"
#include <iostream>

Motor::Motor() : Part(), horsepower(0), fuelType("Unknown") {}

Motor::Motor(int id, const std::string &name, double weight, int horsepower,
             const std::string &fuelType)
    : Part(id, name, weight), horsepower(horsepower), fuelType(fuelType) {}

Motor::Motor(const Motor &other)
    : Part(other), horsepower(other.horsepower), fuelType(other.fuelType) {}

Motor &Motor::operator=(const Motor &other) {
  if (this != &other) {
    Part::operator=(other);
    this->horsepower = other.horsepower;
    this->fuelType = other.fuelType;
  }
  return *this;
}

Motor::~Motor() {}

int Motor::getHorsepower() const { return this->horsepower; }

std::string Motor::getFuelType() const { return this->fuelType; }

void Motor::setHorsepower(int horsepower) { this->horsepower = horsepower; }

void Motor::setFuelType(const std::string &fuelType) {
  this->fuelType = fuelType;
}

std::string Motor::getInfo() const {
  return "Motor [ID: " + std::to_string(this->partID) +
         ", Name: " + this->name + ", Weight: " + std::to_string(this->weight) +
         " kg, Horsepower: " + std::to_string(this->horsepower) +
         ", Fuel Type: " + this->fuelType + "]";
}

void Motor::performFunction() {
  std::cout << "The motor is running with " << this->horsepower
            << " horsepower using " << this->fuelType << " fuel." << std::endl;
}
