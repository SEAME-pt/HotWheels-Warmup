
#include "Crankshaft.hpp"
#include <iostream>

Crankshaft::Crankshaft()
    : Part(), numberOfCylinders(0), length(0.0), material("Unknown") {}

Crankshaft::Crankshaft(int id, const std::string &name, double weight,
                       int numberOfCylinders, double length,
                       const std::string &material)
    : Part(id, name, weight), numberOfCylinders(numberOfCylinders),
      length(length), material(material) {}

Crankshaft::Crankshaft(const Crankshaft &other)
    : Part(other), numberOfCylinders(other.numberOfCylinders),
      length(other.length), material(other.material) {}

Crankshaft &Crankshaft::operator=(const Crankshaft &other) {
  if (this != &other) {
    Part::operator=(other);
    this->numberOfCylinders = other.numberOfCylinders;
    this->length = other.length;
    this->material = other.material;
  }
  return *this;
}

Crankshaft::~Crankshaft() {}

int Crankshaft::getNumberOfCylinders() const { return this->numberOfCylinders; }

double Crankshaft::getLength() const { return this->length; }

std::string Crankshaft::getMaterial() const { return this->material; }

void Crankshaft::setNumberOfCylinders(int numberOfCylinders) {
  this->numberOfCylinders = numberOfCylinders;
}

void Crankshaft::setLength(double length) { this->length = length; }

void Crankshaft::setMaterial(const std::string &material) {
  this->material = material;
}

std::string Crankshaft::getInfo() const {
  return "Crankshaft [ID: " + std::to_string(this->partID) +
         ", Name: " + this->name + ", Weight: " + std::to_string(this->weight) +
         " kg, Cylinders: " + std::to_string(this->numberOfCylinders) +
         ", Length: " + std::to_string(this->length) +
         " mm, Material: " + this->material + "]";
}

void Crankshaft::performFunction() {
  std::cout << "The crankshaft rotates to convert linear piston motion into "
               "rotational energy, supporting "
            << this->numberOfCylinders << " cylinders." << std::endl;
}
