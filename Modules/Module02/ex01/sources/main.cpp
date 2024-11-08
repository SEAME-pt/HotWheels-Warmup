#include "../includes/Car.hpp"
#include <iostream>

int main() {
  Car myCar;

  // Start the engine
  myCar.startEngine();

  // Accelerate a few times
  myCar.accelerate();
  myCar.accelerate();

  // Decelerate
  myCar.decelerate();

  // Print car information
  std::cout << myCar.getCarInfo() << std::endl;

  // Stop the engine
  myCar.stopEngine();

  return 0;
}
