
Transmission System Documentation

Overview

The TransmissionSystem controls power transfer from the engine to the wheels by managing the Clutch and Gearbox components. Together, these parts allow smooth control over the car’s speed and torque.

Components and Roles

Clutch  
- Role: The clutch engages or disengages power from the engine to the gearbox, allowing for smooth gear shifts.  
- Fields:  
  - `isEngaged`: A boolean indicating if the clutch is currently engaged. When engaged, power from the engine flows to the gearbox; when disengaged, power is temporarily halted for safe shifting.

Gearbox  
- Role: The gearbox provides different gears that adjust the torque and speed sent to the wheels. Higher gears allow for greater speed, while lower gears provide more torque.  
- Fields:  
  - `currentGear`: The current active gear  
  - `maxGears`: The maximum number of gears, defining the range available for shifting

TransmissionSystem Class

Fields  
- `clutch`: A Clutch object that manages the connection between the engine and gearbox  
- `gearbox`: A Gearbox object for selecting gears

Methods  
- `engageClutch()` and `disengageClutch()`: Control clutch engagement, disengaging before shifts and re-engaging after  
- `shiftUp()` and `shiftDown()`: Shift gears in the gearbox. The clutch must be disengaged for safe shifting

System Operation

In the Car class, TransmissionSystem is responsible for coordinating clutch engagement and gear changes

1. Starting: Engages the clutch, allowing power to flow from the engine
2. Accelerating: Calls `shiftUp()` if necessary, with controlled clutch engagement
3. Stopping: Disengages the clutch and sets the gear appropriately

This setup allows for effective power management and seamless control of the car's speed and torque