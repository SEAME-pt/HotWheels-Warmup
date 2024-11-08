#include "Gearbox.hpp"
#include <iostream>

Gearbox::Gearbox() : Part(), currentGear(1), maxGears(5) {}

Gearbox::Gearbox(int id, const std::string &name, double weight, int maxGears)
    : Part(id, name, weight), currentGear(1), maxGears(maxGears) {}

Gearbox::Gearbox(const Gearbox &other)
    : Part(other), currentGear(other.currentGear), maxGears(other.maxGears) {}

Gearbox &Gearbox::operator=(const Gearbox &other) {
  if (this != &other) {
    Part::operator=(other);
    this->currentGear = other.currentGear;
    this->maxGears = other.maxGears;
  }
  return *this;
}

Gearbox::~Gearbox() {}

int Gearbox::getCurrentGear() const { return this->currentGear; }

int Gearbox::getMaxGears() const { return this->maxGears; }

void Gearbox::setCurrentGear(int gear) {
  if (gear >= 1 && gear <= maxGears) {
    this->currentGear = gear;
  }
}

std::string Gearbox::getInfo() const {
  return "Gearbox [ID: " + std::to_string(this->partID) +
         ", Name: " + this->name + ", Weight: " + std::to_string(this->weight) +
         " kg, Current Gear: " + std::to_string(this->currentGear) +
         ", Max Gears: " + std::to_string(this->maxGears) + "]";
}

void Gearbox::performFunction() {
  std::cout << "Gearbox is currently in gear " << this->currentGear << "."
            << std::endl;
}
