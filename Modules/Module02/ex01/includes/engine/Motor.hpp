#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "Part.hpp"

class Motor : public Part {
private:
  int horsepower;
  std::string fuelType;

public:
  Motor();
  Motor(int id, const std::string &name, double weight, int horsepower,
        const std::string &fuelType);
  Motor(const Motor &other);
  Motor &operator=(const Motor &other);
  ~Motor() override;

  int getHorsepower() const;
  std::string getFuelType() const;

  void setHorsepower(int horsepower);
  void setFuelType(const std::string &fuelType);

  std::string getInfo() const override;
  void performFunction() override;
};

#endif