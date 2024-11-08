#include <iostream>
#include "../includes/ACar.hpp"
#include "../includes/ClassicCar.hpp"
#include "../includes/ElectricCar.hpp"

int main() {
    // Create a ClassicCar and an ElectricCar
    ACar* myClassicCar = new ClassicCar("Ford Mustang", "Shelby GT500", 1967, 206);
    ACar* myElectricCar = new ElectricCar("Tesla", "Model S", 2023, 100);

    // Demonstrating polymorphism
    myClassicCar->drive();  // Calls ClassicCar's drive
    myElectricCar->drive(); // Calls ElectricCar's drive

    // Clean up dynamically allocated memory
    delete myClassicCar;
    delete myElectricCar;

    return 0;
}
