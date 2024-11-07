#include <iostream>

class Car {
private:
    std::string make;
    std::string model;
    std::string year;

public:
    /* Orthodox Canonical Form */
    Car();
    ~Car();
    Car(const Car &originalCar);
    Car &operator=(const Car &originalCar);
    /* ----------------------- */
    Car(std::string &make, std::string &model, std::string &year);

    void drive();
};
