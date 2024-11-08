#include "../includes/Car.hpp"
#include "Clutch.hpp"
#include "EngineSystem.hpp"
#include "Gearbox.hpp"
#include "TransmissionSystem.hpp"
#include <iostream>
#include <memory>

void displayMenu() {
  std::cout << "\n=========================" << std::endl;
  std::cout << "      Car Control Menu      " << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "1. Start Car" << std::endl;
  std::cout << "2. Accelerate" << std::endl;
  std::cout << "3. Decelerate" << std::endl;
  std::cout << "4. Shift Up" << std::endl;
  std::cout << "5. Shift Down" << std::endl;
  std::cout << "6. Stop Car" << std::endl;
  std::cout << "7. Display Car Info" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "Enter your choice: ";
}

void displayCarInfo(const Car &car) {
  std::cout << "\n--------------------------------" << std::endl;
  std::cout << "      Car Information      " << std::endl;
  std::cout << "--------------------------------" << std::endl;
  std::cout << car.getCarInfo() << std::endl;
  std::cout << "--------------------------------" << std::endl;
}

int main() {
  auto motor = std::make_shared<Motor>(1, "V8 Motor", 200.0, 400, "Diesel");
  auto clutch = std::make_shared<Clutch>(2, "Standard Clutch", 10.0, false);
  auto gearbox = std::make_shared<Gearbox>(3, "6-Speed Gearbox", 50.0, 6);
  auto pistons = std::vector<std::shared_ptr<Piston>>{
      std::make_shared<Piston>(4, "Piston 1", 2.0, 80, 100, "Steel"),
      std::make_shared<Piston>(5, "Piston 2", 2.0, 80, 100, "Steel")};
  auto crankshaft = std::make_shared<Crankshaft>(6, "Standard Crankshaft", 20.0,
                                                 2, 150.0, "Iron");

  auto engineSystem =
      std::make_shared<EngineSystem>(motor, pistons, crankshaft);
  auto transmissionSystem =
      std::make_shared<TransmissionSystem>(clutch, gearbox);
  Car car(engineSystem, transmissionSystem);

  int choice;
  do {
    displayMenu();
    std::cin >> choice;
    std::cout << "\n";

    switch (choice) {
    case 1:
      std::cout << "Starting the car..." << std::endl;
      car.start();
      break;
    case 2:
      std::cout << "Accelerating..." << std::endl;
      car.accelerate();
      break;
    case 3:
      std::cout << "Decelerating..." << std::endl;
      car.decelerate();
      break;
    case 4:
      std::cout << "Shifting up..." << std::endl;
      car.shiftUp();
      break;
    case 5:
      std::cout << "Shifting down..." << std::endl;
      car.shiftDown();
      break;
    case 6:
      std::cout << "Stopping the car..." << std::endl;
      car.stop();
      break;
    case 7:
      displayCarInfo(car);
      break;
    case 0:
      std::cout << "Exiting the program." << std::endl;
      break;
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
      break;
    }

    // if (choice != 0 && choice != 7) {
    //   displayCarInfo(car);
    // }

  } while (choice != 0);

  return 0;
}
