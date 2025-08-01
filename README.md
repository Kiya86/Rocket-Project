# Rocket-Project
For hack club!

# 🚀 Project MightyMouse – Actively Stabilized High-Power Rocket

**Project MightyMouse** is a fully custom, actively stabilized high-power rocket built from the ground up for TRA/NAR Level 2 certification. Featuring custom avionics on a 4-layer PCB, a hand-made fiberglass airframe, live telemetry, and even custom-formulated rocket motors, this rocket was engineered for maximum performance and modularity. The vehicle uses active stabilization with 4 fins and a reaction wheel, deploys parachutes via pyro channels, and sends live data to a custom-built ground station.

---

## 📦 Bill of Materials (BOM)

| **Category**        | **Item**                                      | **Details**                                                   | **Est. Price** |
|---------------------|-----------------------------------------------|----------------------------------------------------------------|----------------|
| **Avionics**        | STM32 Microcontroller                         | Custom PCB – flight computer and telemetry                     | Custom         |
|                     | MS5611 Barometric Sensor                      | High-accuracy pressure sensor                                  | ~$10           |
|                     | BNO0855 IMU                                   | Orientation and acceleration                                   | ~$15           |
|                     | LIS3MDLTR Magnetometer                        | Direction/orientation sensing                                  | ~$5            |
|                     | MAX-M10S GPS Module                           | GNSS tracking                                                   | ~$10           |
|                     | LoRa (RFM96W) Module                          | Long-range telemetry                                            | ~$10           |
|                     | FRAM (CY15B104Q)                              | 512K non-volatile memory                                        | ~$5            |
|                     | Custom 4-layer PCB                            | Designed in KiCad – includes 12V/5V/3.3V rails, ESD protection  | Custom         |

| **Actuation**       | 4× BMS-127WV+ Servos                          | Metal gear, high-torque, 5V                                     | ~$80 total     |
|                     | Reaction Wheel (Custom)                      | Stabilization during coast phase                                | Custom         |
|                     | Servo Linkages                               | Linkage rods and ball joints                                    | ~$10           |

| **Structure**       | Fiberglass Tube (homemade)                   | TotalBoat epoxy + fiberglass cloth                              | ~$40           |
|                     | PETG Filament                                | Inland / eSUN, used for fins, nose cone, bulkheads              | ~$20/roll      |
|                     | Carbon Fiber Rods                            | Internal support for structural components                       | ~$10           |
|                     | M2 / M3 / M4 Screws and Nuts                 | Stainless steel fasteners                                        | ~$15 total     |
|                     | Custom Latch System                          | For modular tube separation                                     | Custom         |

| **Recovery**        | Kevlar Shock Cord (20 ft)                    | Durable, heat-resistant                                         | ~$35           |
|                     | Drogue Parachute (12″)                       | Deploys at apogee                                               | ~$20           |
|                     | Main Parachute (24–30″)                      | Deploys at ~450 ft                                              | ~$20           |
|                     | E-Matches / Igniters                         | Slim Gem Starters                                               | ~$24           |

| **Propulsion**      | Custom 29mm Solid Motors                     | AN/AP-based, 150 N peak thrust                                  | Custom         |
|                     | 29mm Motor Mount + Retainer                 | Compatible with custom casing                                   | ~$10           |

| **Software**        | Rocket Firmware (C++)                        | Custom codebase for telemetry, pyro, and stabilization          | Custom         |
|                     | Ground Station UI (HTML/CSS/JS)             | Displays live telemetry via LoRa                                | Free           |

---

> ✅ *All custom or 3D-printed parts (like bulkheads, nose cone, and fins) are not included in pricing estimates.*

