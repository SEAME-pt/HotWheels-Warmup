
Car Class Documentation

Overview

The `Car` class integrates `EngineSystem` and `TransmissionSystem` to control power, speed, and shifting. It provides a simple, high-level interface for driving operations like starting, accelerating, shifting gears, and stopping.

Components and Roles

EngineSystem  
- Generates power, which combines with the current gear ratio to set `speed`.  
- Key actions: start, adjust power, stop.

TransmissionSystem  
- Manages power flow to the wheels with clutch and gearbox control.  
- Key actions: engage/disengage clutch, shift gears, provide current gear ratio for speed calculation.

Car Class Fields and Methods

Fields  
- `engineSystem`: Manages engine power.  
- `transmissionSystem`: Controls clutch and gear shifting.  
- `speed`: Calculated from engine power and gear ratio.

Methods  
- `start()`: Starts the engine, engages the clutch.  
- `accelerate()`: Increases power, updates speed based on gear ratio.  
- `decelerate()`: Decreases power, adjusts speed.  
- `shiftUp()` / `shiftDown()`: Changes gear to control torque and speed.  
- `stop()`: Shuts down engine, disengages clutch, sets speed to zero.

System Coordination

1. **Starting**: Ignites engine, engages clutch for power flow.  
2. **Accelerating**: Increases power, shifts up as needed, updates speed with gear ratio.  
3. **Decelerating**: Lowers power, shifts down as needed, recalculates speed.  
4. **Stopping**: Shuts down engine, disengages clutch, resets speed.

Speed Calculation

`speed = power * gear ratio` – Speed dynamically adjusts with both power and gear, simulating realistic acceleration and torque changes across gears. 

This setup simplifies complex system interactions, offering easy and realistic control for driving.