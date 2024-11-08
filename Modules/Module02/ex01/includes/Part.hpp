#ifndef PART_HPP
#define PART_HPP

#include <string>

class Part {
protected:
  int partID;
  std::string name;
  double weight;

public:
  Part();
  Part(int id, const std::string &name, double weight);
  Part(const Part &other);
  Part &operator=(const Part &other);
  virtual ~Part();

  int getPartID() const;
  std::string getName() const;
  double getWeight() const;

  void setPartID(int id);
  void setName(const std::string &name);
  void setWeight(double weight);

  virtual std::string getInfo() const = 0;
  virtual void performFunction() = 0;
};

#endif
