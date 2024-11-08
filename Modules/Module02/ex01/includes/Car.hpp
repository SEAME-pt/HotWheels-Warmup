#ifndef CAR_HPP
#define CAR_HPP

#include "EngineSystem.hpp"
#include <memory>

class Car {
private:
  std::shared_ptr<EngineSystem> engineSystem;

public:
  Car();
  Car(std::shared_ptr<EngineSystem> engineSystem);
  Car(const Car &other);
  Car &operator=(const Car &other);
  ~Car();

  void startEngine();
  void accelerate();
  void decelerate();
  void stopEngine();

  std::string getCarInfo() const;
};

#endif
