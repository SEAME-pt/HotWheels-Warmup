#ifndef CAR_HPP
#define CAR_HPP

#include "EngineSystem.hpp"
#include "TransmissionSystem.hpp"
#include <memory>

class Car {
private:
  std::shared_ptr<EngineSystem> engineSystem;
  std::shared_ptr<TransmissionSystem> transmissionSystem;
  int speed;

  void updateSpeed();

public:
  Car();
  Car(std::shared_ptr<EngineSystem> engineSystem,
      std::shared_ptr<TransmissionSystem> transmissionSystem);
  Car(const Car &other);
  Car &operator=(const Car &other);
  ~Car();

  int getSpeed() const;

  void start();
  void accelerate();
  void decelerate();
  void shiftUp();
  void shiftDown();
  void stop();

  std::string getCarInfo() const;
};

#endif
