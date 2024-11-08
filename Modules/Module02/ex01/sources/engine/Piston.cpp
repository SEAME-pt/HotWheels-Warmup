#include "Piston.hpp"
#include <iostream>

Piston::Piston()
    : Part(), diameter(0.0), strokeLength(0.0), material("Unknown") {}

Piston::Piston(int id, const std::string &name, double weight, double diameter,
               double strokeLength, const std::string &material)
    : Part(id, name, weight), diameter(diameter), strokeLength(strokeLength),
      material(material) {}

Piston::Piston(const Piston &other)
    : Part(other), diameter(other.diameter), strokeLength(other.strokeLength),
      material(other.material) {}

Piston &Piston::operator=(const Piston &other) {
  if (this != &other) {
    Part::operator=(other);
    this->diameter = other.diameter;
    this->strokeLength = other.strokeLength;
    this->material = other.material;
  }
  return *this;
}

Piston::~Piston() {}

double Piston::getDiameter() const { return this->diameter; }

double Piston::getStrokeLength() const { return this->strokeLength; }

std::string Piston::getMaterial() const { return this->material; }

void Piston::setDiameter(double diameter) { this->diameter = diameter; }

void Piston::setStrokeLength(double strokeLength) {
  this->strokeLength = strokeLength;
}

void Piston::setMaterial(const std::string &material) {
  this->material = material;
}

std::string Piston::getInfo() const {
  return "Piston [ID: " + std::to_string(this->partID) +
         ", Name: " + this->name + ", Weight: " + std::to_string(this->weight) +
         " kg, Diameter: " + std::to_string(this->diameter) +
         " mm, Stroke Length: " + std::to_string(this->strokeLength) +
         " mm, Material: " + this->material + "]";
}

void Piston::performFunction() {
  std::cout << "The piston moves up and down with a stroke length of "
            << this->strokeLength
            << " mm, operating smoothly within the engine." << std::endl;
}
