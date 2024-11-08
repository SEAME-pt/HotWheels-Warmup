#include "Clutch.hpp"
#include <iostream>

Clutch::Clutch() : Part(), isEngaged(false) {}

Clutch::Clutch(int id, const std::string &name, double weight, bool isEngaged)
    : Part(id, name, weight), isEngaged(isEngaged) {}

Clutch::Clutch(const Clutch &other) : Part(other), isEngaged(other.isEngaged) {}

Clutch &Clutch::operator=(const Clutch &other) {
  if (this != &other) {
    Part::operator=(other);
    this->isEngaged = other.isEngaged;
  }
  return *this;
}

Clutch::~Clutch() {}

bool Clutch::getIsEngaged() const { return this->isEngaged; }

void Clutch::setIsEngaged(bool isEngaged) { this->isEngaged = isEngaged; }

std::string Clutch::getInfo() const {
  return "Clutch [ID: " + std::to_string(this->partID) +
         ", Name: " + this->name + ", Weight: " + std::to_string(this->weight) +
         " kg, Status: " + (this->isEngaged ? "Engaged" : "Disengaged") + "]";
}

void Clutch::performFunction() {
  std::cout << "Clutch is currently "
            << (this->isEngaged ? "engaged, transmitting power."
                                : "disengaged, no power transmission.")
            << std::endl;
}
