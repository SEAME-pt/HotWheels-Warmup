#ifndef CLUTCH_HPP
#define CLUTCH_HPP

#include "Part.hpp"
#include <string>

class Clutch : public Part {
private:
  bool isEngaged;

public:
  Clutch();
  Clutch(int id, const std::string &name, double weight, bool isEngaged);
  Clutch(const Clutch &other);
  Clutch &operator=(const Clutch &other);
  ~Clutch() override;

  bool getIsEngaged() const;

  void setIsEngaged(bool isEngaged);

  std::string getInfo() const override;
  void performFunction() override;
};

#endif
