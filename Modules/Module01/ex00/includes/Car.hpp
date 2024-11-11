#include <iostream>

class Car {
private:
  std::string name;
  unsigned int speed;

public:
  /* Orthodox Canonical Form */
  Car();
  ~Car();
  Car(const Car &originalCar);
  Car &operator=(const Car &originalCar);
  /* ----------------------- */
  Car(const std::string &name);

  void setName(const std::string &name);
  void setSpeed(unsigned int speed);
  const std::string &getName(void);

  unsigned int getSpeed(void);
};
