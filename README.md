# Rocket-Project
For hack club!

# 🚀 Rocketry Project

## Actively Stabilized Rocket

- Custom avionics based on STM32 with live telemetry data  
- Includes 4 pyro channels, reverse protection, 4 servo channels, reaction wheel, GPS, pressure sensor, IMU, magnetometer, LoRa, 12V/5V/3.3V rails, and is based on a 4-layer PCB  
- Custom airframe modeled in Fusion 360  
- Optimized for weight – Modeled aerodynamic efficiency to make sure it was optimized  
- Includes removable segments through a custom-built “latch” system  
- Airframe skin is fiberglass with TotalBoat epoxy *(yes, I made the tube in my tiny 1-bedroom apartment 😭)*  
- Nose cone and fins were simulated and 3D printed with PETG  
- Custom motors  
  - Made custom motors for rocket using chemicals such as ammonium nitrate, ammonium perchlorate, etc. *(can’t leak the recipe yk)*  
  - Ran multiple trials to ensure max performance from each motor *(Peak thrust: 150 N/S)*  
- Custom telemetry viewer (ground station)  
  - Built using HTML, CSS *(CSS is a joke)*, and JS *(still haven’t learned React 😱)*  
- Custom flight computer code  
  - Written in C++ using hardware libraries – took ages  

---

## 📦 Bill of Materials (BOM)

| **Category**       | **Item**                                 | **Details**                                                      | **Est. Price** |
|--------------------|------------------------------------------|------------------------------------------------------------------|----------------|
| **Avionics**       | STM32 MCU (Teensy 4.1 or STM32F4)        | Main controller with breakout                                     | $25            |
|                    | MS5611 Barometric Sensor                 | High-precision pressure/altitude sensor                          | $10            |
|                    | BNO0855 IMU                              | Orientation and motion tracking                                  | $15            |
|                    | LIS3MDLTR Magnetometer                   | Heading/orientation                                               | $5             |
|                    | MAX-M10S GPS                             | GNSS receiver for position                                        | $10            |
|                    | RFM96W LoRa Module                       | Long-range telemetry module                                       | $8             |
|                    | FRAM CY15B104Q                           | 512K non-volatile memory                                          | $5             |
|                    | Custom 4-layer PCB                       | Designed in KiCad                                                 | $25            |
|                    | Voltage Regulators                       | 12V, 5V, 3.3V rails using LM2596 series                           | $5             |

| **Actuation**      | 4× Blue Bird BMS-127WV+ Servos           | High-torque metal gear servos                                     | $80 total      |
|                    | Reaction Wheel (Custom)                  | For active stabilization                                          | Custom         |
|                    | Servo Linkages                           | Pushrods + ball joints                                            | $10            |

| **Structure**      | PETG Filament Rolls                      | 1kg eSUN or Inland brand                                          | $20            |
|                    | Fiberglass Cloth                         | With TotalBoat epoxy (airframe)                                   | $40            |
|                    | TotalBoat Epoxy Kit                      | Laminating epoxy for tube                                         | $40            |
|                    | Carbon Rods / Internal Support           | Structural reinforcement                                          | $10            |
|                    | M2/M3/M4 Screws and Nuts                 | Stainless hardware                                                | $15            |
|                    | Custom Latch System                      | PETG printed, custom design                                       | Custom         |

| **Recovery**       | Drogue Parachute (12″)                   | Deploys at apogee                                                 | $20            |
|                    | Main Parachute (24–30″)                  | Deploys at 450 ft                                                 | $20            |
|                    | Kevlar Shock Cord (20 ft)                | Flame-resistant tether                                            | $35            |
|                    | E-Matches (Slim Gem Starters)           | For pyro channel deployment                                       | $24            |

| **Propulsion**     | Custom 29mm Solid Motors                 | AN/AP-based, 150 N peak thrust                                    | Custom         |
|                    | 29mm Motor Retainer                      | Motor retention system                                            | $10            |

| **Software**       | C++ Flight Code                          | Custom stabilization, pyro control, telemetry logic               | Free           |
|                    | HTML/CSS/JS Ground Station               | Telemetry dashboard                                               | Free           |

---

> 🧪 *All custom, printed, or experimental parts are not given a commercial cost.*
