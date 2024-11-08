#include "../includes/Car.hpp"
#include <iostream>

Car::Car()
    : engineSystem(std::make_shared<EngineSystem>()),
      transmissionSystem(std::make_shared<TransmissionSystem>()), speed(0) {}

Car::Car(std::shared_ptr<EngineSystem> engineSystem,
         std::shared_ptr<TransmissionSystem> transmissionSystem)
    : engineSystem(engineSystem), transmissionSystem(transmissionSystem),
      speed(0) {}

Car::Car(const Car &other)
    : engineSystem(other.engineSystem),
      transmissionSystem(other.transmissionSystem), speed(other.speed) {}

Car &Car::operator=(const Car &other) {
  if (this != &other) {
    this->engineSystem = other.engineSystem;
    this->transmissionSystem = other.transmissionSystem;
    this->speed = other.speed;
  }
  return *this;
}

Car::~Car() {}

int Car::getSpeed() const { return this->speed; }

void Car::updateSpeed() {
  if (this->engineSystem && this->engineSystem->getIsRunning()) {
    this->speed = this->engineSystem->getPower();
  } else {
    this->speed = 0;
  }
}

void Car::start() {
  if (this->engineSystem) {
    this->engineSystem->ignite();
    updateSpeed();
  }
  if (this->transmissionSystem) {
    this->transmissionSystem->disengageClutch(); // Ready for acceleration
  }
  std::cout << "Car started." << std::endl;
}

void Car::accelerate() {
  if (this->engineSystem) {
    this->engineSystem->accelerate();
    updateSpeed();
  }
  std::cout << "Accelerating. Current speed: " << this->speed << " units."
            << std::endl;
}

void Car::decelerate() {
  if (this->engineSystem) {
    this->engineSystem->decelerate();
    updateSpeed();
  }
  std::cout << "Decelerating. Current speed: " << this->speed << " units."
            << std::endl;
}

void Car::shiftUp() {
  if (this->transmissionSystem) {
    this->transmissionSystem->disengageClutch();
    this->transmissionSystem->shiftUp();
    this->transmissionSystem->engageClutch();
  }
}

void Car::shiftDown() {
  if (this->transmissionSystem) {
    this->transmissionSystem->disengageClutch();
    this->transmissionSystem->shiftDown();
    this->transmissionSystem->engageClutch();
  }
}

void Car::stop() {
  if (this->engineSystem) {
    this->engineSystem->shutdown();
    updateSpeed();
  }
  if (this->transmissionSystem) {
    this->transmissionSystem->disengageClutch();
  }
  std::cout << "Car stopped." << std::endl;
}

std::string Car::getCarInfo() const {
  std::string info = "Car Status:\n";
  info += "  Speed: " + std::to_string(this->speed) + " units\n";
  if (this->engineSystem) {
    info += this->engineSystem->getInfo();
  }
  if (this->transmissionSystem) {
    info += this->transmissionSystem->getInfo();
  }
  return info;
}
