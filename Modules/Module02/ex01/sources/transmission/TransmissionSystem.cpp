#include "TransmissionSystem.hpp"
#include <iostream>

TransmissionSystem::TransmissionSystem() : clutch(nullptr), gearbox(nullptr) {
  this->gearRatios = {0.3, 0.6, 1.0, 1.3, 1.5, 1.8};
}

TransmissionSystem::TransmissionSystem(std::shared_ptr<Clutch> clutch,
                                       std::shared_ptr<Gearbox> gearbox)
    : clutch(clutch), gearbox(gearbox) {
  this->gearRatios = {0.3, 0.6, 1.0, 1.3, 1.5, 1.8};
}

TransmissionSystem::TransmissionSystem(const TransmissionSystem &other)
    : clutch(other.clutch), gearbox(other.gearbox) {}

TransmissionSystem &
TransmissionSystem::operator=(const TransmissionSystem &other) {
  if (this != &other) {
    this->clutch = other.clutch;
    this->gearbox = other.gearbox;
  }
  return *this;
}

TransmissionSystem::~TransmissionSystem() {}

bool TransmissionSystem::isClutchEngaged() const {
  return this->clutch ? this->clutch->getIsEngaged() : false;
}

int TransmissionSystem::getCurrentGear() const {
  return this->gearbox ? this->gearbox->getCurrentGear() : 0;
}

double TransmissionSystem::getCurrentGearRatio() const {
  int gear = this->getCurrentGear();
  std::cout << gear << "|" << this->gearRatios.size() << std::endl;
  return (gear >= 1 && gear <= this->gearRatios.size())
             ? this->gearRatios[gear - 1]
             : 0.0;
}

void TransmissionSystem::engageClutch() {
  if (this->clutch) {
    this->clutch->setIsEngaged(true);
    std::cout << "Clutch engaged." << std::endl;
  }
}

void TransmissionSystem::disengageClutch() {
  if (this->clutch) {
    this->clutch->setIsEngaged(false);
    std::cout << "Clutch disengaged." << std::endl;
  }
}

void TransmissionSystem::shiftUp() {
  if (this->clutch && !this->clutch->getIsEngaged()) {
    int newGear = this->gearbox->getCurrentGear() + 1;
    if (newGear <= this->gearbox->getMaxGears()) {
      this->gearbox->setCurrentGear(newGear);
      std::cout << "Shifted up to gear " << newGear << "." << std::endl;
    } else {
      std::cout << "Already in the highest gear." << std::endl;
    }
  } else {
    std::cout << "Cannot shift gears while clutch is engaged." << std::endl;
  }
}

void TransmissionSystem::shiftDown() {
  if (this->clutch && !this->clutch->getIsEngaged()) {
    int newGear = this->gearbox->getCurrentGear() - 1;
    if (newGear >= 1) {
      this->gearbox->setCurrentGear(newGear);
      std::cout << "Shifted down to gear " << newGear << "." << std::endl;
    } else {
      std::cout << "Already in the lowest gear." << std::endl;
    }
  } else {
    std::cout << "Cannot shift gears while clutch is engaged." << std::endl;
  }
}

std::string TransmissionSystem::getInfo() const {
  std::string info = "\nTransmission System\n";
  if (this->clutch) {
    info += "  " + this->clutch->getInfo() + "\n";
  }
  if (this->gearbox) {
    info += "  " + this->gearbox->getInfo() + "\n";
  }
  return info;
}

void TransmissionSystem::operate() {
  std::cout << "Operating the transmission system..." << std::endl;
  if (this->clutch) {
    this->clutch->performFunction();
  }
  if (this->gearbox) {
    this->gearbox->performFunction();
  }
}
