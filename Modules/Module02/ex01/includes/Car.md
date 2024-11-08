
Car Class Documentation

Overview

The `Car` class acts as the central controller for the vehicle, integrating both the `EngineSystem` and `TransmissionSystem` to manage the car’s power and speed. By coordinating these systems, the `Car` class provides a simplified, high-level interface for driving operations like starting, accelerating, shifting gears, and stopping.

Components and Roles

EngineSystem  
- The `EngineSystem` generates power for the car. It controls the engine’s `power` output, which is essential for determining the car’s `speed`. The `Car` class interacts with `EngineSystem` to start the engine, adjust power, and shut down the engine when necessary.

TransmissionSystem  
- The `TransmissionSystem` manages power flow from the engine to the wheels by controlling the clutch and gearbox. This system allows the `Car` to shift gears and control torque output. The `Car` class uses `TransmissionSystem` to engage/disengage the clutch and shift gears.

Car Class Fields and Methods

Fields  
- `engineSystem`: A pointer to the `EngineSystem` object that manages engine power  
- `transmissionSystem`: A pointer to the `TransmissionSystem` object that handles clutch engagement and gear shifting  
- `speed`: An integer representing the current speed of the car, which is updated based on the power output from the `EngineSystem`

Methods  
- `start()`: Starts the engine by engaging the clutch and igniting the engine, allowing power to flow through the transmission  
- `accelerate()`: Increases the engine’s power, updating the car’s speed accordingly  
- `decelerate()`: Decreases engine power, lowering the car’s speed  
- `shiftUp()` and `shiftDown()`: Adjust the current gear in the transmission to control torque and speed, ensuring smoother acceleration and deceleration  
- `stop()`: Shuts down the engine and disengages the clutch, setting the car’s speed to zero

System Coordination and Operation

The `Car` class coordinates the `EngineSystem` and `TransmissionSystem` to provide a realistic driving experience. Each method in `Car` uses these systems to control power and speed effectively.

1. Starting: Calls `EngineSystem::ignite()` to start the engine and `TransmissionSystem::engageClutch()` to allow power transfer  
2. Accelerating: Increases `EngineSystem` power and shifts up gears when needed to manage speed smoothly  
3. Decelerating: Decreases `EngineSystem` power and shifts down gears as required  
4. Stopping: Calls `EngineSystem::shutdown()` and `TransmissionSystem::disengageClutch()` to stop power flow and reset speed to zero

This structure allows the `Car` class to simplify complex engine and transmission interactions, providing a cohesive and user-friendly control interface for the vehicle.