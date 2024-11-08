#ifndef PISTON_HPP
#define PISTON_HPP

#include "Part.hpp"

class Piston : public Part {
private:
  double diameter;
  double strokeLength;
  std::string material;

public:
  Piston();
  Piston(int id, const std::string &name, double weight, double diameter,
         double strokeLength, const std::string &material);
  Piston(const Piston &other);
  Piston &operator=(const Piston &other);
  ~Piston() override;

  double getDiameter() const;
  double getStrokeLength() const;
  std::string getMaterial() const;

  void setDiameter(double diameter);
  void setStrokeLength(double strokeLength);
  void setMaterial(const std::string &material);

  std::string getInfo() const override;
  void performFunction() override;
};

#endif
