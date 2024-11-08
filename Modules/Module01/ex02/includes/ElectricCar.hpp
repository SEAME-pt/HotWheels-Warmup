#pragma once

#include <iostream>
#include "ACar.hpp"

class ElectricCar : public ACar {
private:
    int batteryCapacity;

public:
    /* Orthodox Canonical Form */
    ElectricCar();
    ~ElectricCar();
    ElectricCar(const ElectricCar &originalElectricCar);
    ElectricCar &operator=(const ElectricCar &originalElectricCar);
    /* ----------------------- */

    // Constructor to initialize make, model, year, and top speed
    ElectricCar(const std::string& carMake, const std::string& carModel, int carYear, int carBatteryCapacity);

    // Override drive function to include top speed
    void drive() const override;
};