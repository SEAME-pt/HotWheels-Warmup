#include "EngineSystem.hpp"
#include <iostream>

EngineSystem::EngineSystem()
    : motor(nullptr), crankshaft(nullptr), isRunning(false), speed(0) {}

EngineSystem::EngineSystem(std::shared_ptr<Motor> motor,
                           const std::vector<std::shared_ptr<Piston>> &pistons,
                           std::shared_ptr<Crankshaft> crankshaft)
    : motor(motor), pistons(pistons), crankshaft(crankshaft), isRunning(false),
      speed(0) {}

EngineSystem::EngineSystem(const EngineSystem &other)
    : motor(other.motor), pistons(other.pistons), crankshaft(other.crankshaft),
      isRunning(other.isRunning), speed(other.speed) {}

EngineSystem &EngineSystem::operator=(const EngineSystem &other) {
  if (this != &other) {
    this->motor = other.motor;
    this->pistons = other.pistons;
    this->crankshaft = other.crankshaft;
    this->isRunning = other.isRunning;
    this->speed = other.speed;
  }
  return *this;
}

EngineSystem::~EngineSystem() {}

std::string EngineSystem::getInfo() const {
  std::string info = "Engine System\n";
  if (this->motor) {
    info += "  Motor: " + motor->getInfo() + "\n";
  }
  if (this->crankshaft) {
    info += "  Crankshaft: " + crankshaft->getInfo() + "\n";
  }
  for (const auto &piston : pistons) {
    info += "  Piston: " + piston->getInfo() + "\n";
  }
  info += "  Engine Status: " + std::string(isRunning ? "Running" : "Stopped") +
          "\n";
  info += "  Speed: " + std::to_string(speed) + " units\n";
  return info;
}

void EngineSystem::ignite() {
  if (this->isRunning) {
    std::cout << "Engine is already running." << std::endl;
    return;
  }
  std::cout << "Igniting the engine..." << std::endl;
  if (this->motor) {
    this->motor->performFunction();
  }
  for (const auto &piston : pistons) {
    piston->performFunction();
  }
  if (this->crankshaft) {
    this->crankshaft->performFunction();
  }
  this->isRunning = true;
  this->speed = 0;
}

void EngineSystem::accelerate() {
  if (!this->isRunning) {
    std::cout << "Engine is not running. Ignite it first." << std::endl;
    return;
  }
  this->speed += 10;
  std::cout << "Accelerating engine. Current speed: " << this->speed
            << " units." << std::endl;
}

void EngineSystem::decelerate() {
  if (!this->isRunning) {
    std::cout << "Engine is not running. Ignite it first." << std::endl;
    return;
  }
  this->speed -= 10;
  if (this->speed < 0) {
    this->speed = 0;
  }
  std::cout << "Decelerating engine. Current speed: " << this->speed
            << " units." << std::endl;
}

void EngineSystem::shutdown() {
  if (!this->isRunning) {
    std::cout << "Engine is already stopped." << std::endl;
    return;
  }
  std::cout << "Shutting down the engine..." << std::endl;
  this->isRunning = false;
  this->speed = 0;
}
