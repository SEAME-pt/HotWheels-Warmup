#pragma once

#include <iostream>
#include "ACar.hpp"

class ClassicCar : public ACar {
private:
    int topSpeed;

public:
    /* Orthodox Canonical Form */
    ClassicCar();
    ~ClassicCar();
    ClassicCar(const ClassicCar &originalClassicCar);
    ClassicCar &operator=(const ClassicCar &originalClassicCar);
    /* ----------------------- */

    // Constructor to initialize make, model, year, and top speed
    ClassicCar(const std::string& carMake, const std::string& carModel, int carYear, int carTopSpeed);

    // Override drive function to include top speed
    void drive() const override;
};