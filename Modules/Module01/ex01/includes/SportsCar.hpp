#pragma once

#include <iostream>
#include "Car.hpp"

class SportsCar : public Car {
private:
    int topSpeed;

public:
    /* Orthodox Canonical Form */
    SportsCar();
    ~SportsCar();
    SportsCar(const SportsCar &originalSportsCar);
    SportsCar &operator=(const SportsCar &originalSportsCar);
    /* ----------------------- */

    // Constructor to initialize make, model, year, and top speed
    SportsCar(const std::string& carMake, const std::string& carModel, int carYear, int carTopSpeed);

    // Override drive function to include top speed
    void drive() const override;
};