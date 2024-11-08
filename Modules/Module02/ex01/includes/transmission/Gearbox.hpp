#ifndef GEARBOX_HPP
#define GEARBOX_HPP

#include "Part.hpp"
#include <string>

class Gearbox : public Part {
private:
  int currentGear;
  int maxGears;

public:
  Gearbox();
  Gearbox(int id, const std::string &name, double weight, int maxGears);
  Gearbox(const Gearbox &other);
  Gearbox &operator=(const Gearbox &other);
  ~Gearbox() override;

  int getCurrentGear() const;
  int getMaxGears() const;

  void setCurrentGear(int gear);

  std::string getInfo() const override;
  void performFunction() override;
};

#endif
