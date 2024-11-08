#include <iostream>
#include "../includes/Car.hpp"
#include "../includes/SportsCar.hpp"

int main() {
    // Test default constructor
    Car car1;
    std::cout << "Testing default constructor:" << std::endl;
    car1.drive();

    // Test parameterized constructor
    std::string make = "Toyota";
    std::string model = "Corolla";
    int year = 2022;
    Car car2(make, model, year);
    std::cout << "Testing parameterized constructor:" << std::endl;
    car2.drive();

    // Test copy constructor
    Car car3(car2);
    std::cout << "Testing copy constructor (should match car2):" << std::endl;
    car3.drive();

    // Test assignment operator
    car1 = car3;
    std::cout << "Testing assignment operator (should match car3):" << std::endl;
    car1.drive();

    // Test inheritance
    std::cout << "[Testing inheritance car]" << std::endl;
    SportsCar sport1("Ford Mustang", "Shelby GT500", 1967, 206);
    sport1.drive();
    
    return 0;
}
