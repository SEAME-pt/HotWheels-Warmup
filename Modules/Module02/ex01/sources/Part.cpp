#include "Part.hpp"

Part::Part() : partID(0), name("Unnamed Part"), weight(0.0) {}

Part::Part(int id, const std::string &name, double weight)
    : partID(id), name(name), weight(weight) {}

Part::Part(const Part &other)
    : partID(other.partID), name(other.name), weight(other.weight) {}

Part &Part::operator=(const Part &other) {
  if (this != &other) {
    this->partID = other.partID;
    this->name = other.name;
    this->weight = other.weight;
  }
  return *this;
}

Part::~Part() {}

int Part::getPartID() const { return this->partID; }

std::string Part::getName() const { return this->name; }

double Part::getWeight() const { return this->weight; }

void Part::setPartID(int id) { this->partID = id; }

void Part::setName(const std::string &name) { this->name = name; }

void Part::setWeight(double weight) { this->weight = weight; }
