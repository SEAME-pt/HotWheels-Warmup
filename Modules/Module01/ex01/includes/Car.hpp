#pragma once
#include <iostream>

class Car {
    protected:
        std::string make;
        std::string model;
        int year;

    public:
        /* Orthodox Canonical Form */
        Car();
        ~Car();
        Car(const Car &originalCar);
        Car &operator=(const Car &originalCar);
        /* ----------------------- */
        Car(const std::string &make, const std::string &model, int year);

        virtual void drive() const;
};
