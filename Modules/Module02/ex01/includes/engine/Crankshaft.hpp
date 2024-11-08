#ifndef CRANKSHAFT_HPP
#define CRANKSHAFT_HPP

#include "Part.hpp"

class Crankshaft : public Part {
private:
  int numberOfCylinders;
  double length;
  std::string material;

public:
  Crankshaft();
  Crankshaft(int id, const std::string &name, double weight,
             int numberOfCylinders, double length, const std::string &material);
  Crankshaft(const Crankshaft &other);
  Crankshaft &operator=(const Crankshaft &other);
  ~Crankshaft() override;

  int getNumberOfCylinders() const;
  double getLength() const;
  std::string getMaterial() const;

  void setNumberOfCylinders(int numberOfCylinders);
  void setLength(double length);
  void setMaterial(const std::string &material);

  std::string getInfo() const override;
  void performFunction() override;
};

#endif
