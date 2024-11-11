
Transmission System Documentation

Overview

The TransmissionSystem manages the transfer of power from the engine to the wheels by coordinating the Clutch and Gearbox components. Together, these parts allow smooth control over the car’s speed and torque.

Components and Roles

Clutch  
- Role: The clutch controls whether power flows from the engine to the gearbox, enabling smooth and safe gear shifts.  
- Fields:  
  - `isEngaged`: A boolean indicating if the clutch is currently engaged. When engaged, power from the engine flows to the gearbox; when disengaged, power is interrupted for shifting.

Gearbox  
- Role: The gearbox provides multiple gears that adjust torque and speed sent to the wheels. Higher gears increase speed potential, while lower gears provide more torque.  
- Fields:  
  - `currentGear`: The active gear currently in use, determining the speed-torque balance.  
  - `maxGears`: The maximum number of gears available, defining the shifting range.

TransmissionSystem Class

Fields  
- `clutch`: A Clutch object that manages power flow from the engine to the gearbox.  
- `gearbox`: A Gearbox object responsible for selecting gears and influencing speed and torque.  
- `gearRatios`: A vector of doubles representing ratios for each gear, which adjusts speed based on the current gear and engine power.

Methods  
- `engageClutch()` and `disengageClutch()`: Controls the clutch engagement, disengaging it before gear shifts and re-engaging afterward.  
- `shiftUp()` and `shiftDown()`: Safely adjusts gears in the gearbox. Clutch must be disengaged for smooth and safe shifting.  
- `getCurrentGearRatio()`: Returns the gear ratio for the active gear, used to calculate speed from engine power.

System Operation

In the Car class, the TransmissionSystem coordinates clutch engagement and gear changes to manage speed and torque effectively.

1. Starting: Engages the clutch, allowing power to flow from the engine.
2. Accelerating: Uses `shiftUp()` and adjusts the current gear as needed, with controlled clutch engagement.
3. Stopping: Disengages the clutch and resets the gear for safe deceleration.

This setup enables seamless control over the car’s speed and torque, ensuring smooth transitions and responsive handling.