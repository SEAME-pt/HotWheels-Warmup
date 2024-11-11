#ifndef TRANSMISSIONSYSTEM_HPP
#define TRANSMISSIONSYSTEM_HPP

#include "Clutch.hpp"
#include "Gearbox.hpp"
#include <memory>

class TransmissionSystem {
private:
  std::shared_ptr<Clutch> clutch;
  std::shared_ptr<Gearbox> gearbox;
  std::vector<double> gearRatios;

public:
  TransmissionSystem();
  TransmissionSystem(std::shared_ptr<Clutch> clutch,
                     std::shared_ptr<Gearbox> gearbox);
  TransmissionSystem(const TransmissionSystem &other);
  TransmissionSystem &operator=(const TransmissionSystem &other);
  ~TransmissionSystem();

  bool isClutchEngaged() const;
  int getCurrentGear() const;
  double getCurrentGearRatio() const;

  void engageClutch();
  void disengageClutch();
  void shiftUp();
  void shiftDown();

  std::string getInfo() const;
  void operate();
};

#endif
