#include "../includes/Car.hpp"
#include <iostream>

Car::Car() : engineSystem(std::make_shared<EngineSystem>()) {}

Car::Car(std::shared_ptr<EngineSystem> engineSystem)
    : engineSystem(engineSystem) {}

Car::Car(const Car &other) : engineSystem(other.engineSystem) {}

Car &Car::operator=(const Car &other) {
  if (this != &other) {
    this->engineSystem = other.engineSystem;
  }
  return *this;
}

Car::~Car() {}

void Car::startEngine() {
  if (this->engineSystem) {
    this->engineSystem->ignite();
  } else {
    std::cout << "No engine system installed." << std::endl;
  }
}

void Car::accelerate() {
  if (this->engineSystem) {
    this->engineSystem->accelerate();
  } else {
    std::cout << "No engine system installed." << std::endl;
  }
}

void Car::decelerate() {
  if (this->engineSystem) {
    this->engineSystem->decelerate();
  } else {
    std::cout << "No engine system installed." << std::endl;
  }
}

void Car::stopEngine() {
  if (this->engineSystem) {
    this->engineSystem->shutdown();
  } else {
    std::cout << "No engine system installed." << std::endl;
  }
}

std::string Car::getCarInfo() const {
  std::string info = "Car Status:\n";
  if (this->engineSystem) {
    info += this->engineSystem->getInfo();
  } else {
    info += "  No engine system installed.\n";
  }
  return info;
}
