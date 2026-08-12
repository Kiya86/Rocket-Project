# Fin-Stabilized Vehicle

<img width="1520" height="730" alt="MainRender" src="https://github.com/user-attachments/assets/93e39f6f-0f19-47b9-8712-8c15fb8ae3f0" />
<img width="1520" height="730" alt="InternalRender" src="https://github.com/user-attachments/assets/776c001d-d437-4f6f-b11a-22c24a1819f8" />

<h4 align="center">
A four-fin actively stabilized rocket designed for aerodynamic control and experimental flight systems.
</h4>

<div align="center">

![Fusion 360](https://img.shields.io/badge/Fusion%20360-FF6B00?style=for-the-badge&logo=autodesk&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![PETG](https://img.shields.io/badge/PETG-3D%20Printed-00A98F?style=for-the-badge)
![Hack Club](https://img.shields.io/badge/Hack%20Club-EC3750?style=for-the-badge)

</div>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#purpose">Purpose</a> •
  <a href="#airframe">Airframe</a> •
  <a href="#active-fin-control">Fin Control</a> •
  <a href="#propulsion">Propulsion</a> •
  <a href="#recovery-system">Recovery</a> •
  <a href="#software">Software</a> •
  <a href="#bom">BOM</a>
</p>

---

## Key Features

- **Four independently controlled fins** — Provides active aerodynamic control through four servo-actuated control surfaces.
- **4× Blue Bird BMS-127WV+ servos** — High-torque metal-gear servos used to actuate the four fins.
- **Mechanical pushrod system** — Steel linkages and M3 ball joints transfer servo motion to the control fins.
- **PETG airframe** — Lightweight 3D-printed primary structure designed in Fusion 360.
- **Fiberglass reinforcement** — The external airframe is reinforced with fiberglass cloth and laminating epoxy.
- **Modular internal structure** — Internal components are housed within a PETG structural framework.
- **29 mm motor compatibility** — Designed around a 29 mm commercial motor mount.
- **Up to 220 mm motor length** — Motor length is limited primarily by the available internal volume and servo placement.
- **Drogue + main recovery system** — Two-stage parachute recovery architecture.
- **Custom flight software** — C++ control software for stabilization, telemetry, and recovery-system logic.
- **Ground station** — HTML/CSS/JavaScript-based telemetry interface for monitoring flight data.

---

## Purpose

This project is an experimental **actively stabilized rocket platform** designed to explore aerodynamic control, servo-driven fin actuation, flight software, and recovery systems.

Unlike a conventional fin-stabilized rocket where the fins remain fixed throughout flight, this vehicle uses **four independently actuated fins**. The fins can be dynamically positioned through servo-driven mechanical linkages, allowing the vehicle to experiment with real-time aerodynamic control.

The project combines mechanical design, additive manufacturing, composite reinforcement, embedded electronics, control software, and flight testing into a single aerospace engineering platform.

---

## Design

The entire vehicle was designed in **Autodesk Fusion 360**, including the external airframe, internal structure, servo mounts, fin mechanisms, motor section, and recovery components.

The design was developed around a modular architecture so that the mechanical, propulsion, recovery, and electronics sections can be iterated independently.

### CAD

The airframe is designed to be manufactured primarily through **FDM 3D printing using PETG**.

The external skin is subsequently reinforced using fiberglass cloth and laminating epoxy to improve structural stiffness and durability.

---

## Airframe

The primary airframe uses **PETG** as the base structural material.

The external airframe is reinforced with fiberglass cloth and resin to provide additional stiffness while maintaining a relatively lightweight structure.

The internal structure follows a similar PETG construction philosophy but does **not** receive the same fiberglass reinforcement as the external skin.

This creates a lightweight internal framework for mounting the propulsion, servo, recovery, and electronics systems.

### Structural Architecture

```text
                Nose
                 │
                 ▼
        ┌─────────────────┐
        │   Nose Section  │
        ├─────────────────┤
        │                 │
        │  Electronics /  │
        │  Flight System  │
        │                 │
        ├─────────────────┤
        │  Servo Section  │
        │                 │
        │  S1   S2        │
        │  S3   S4        │
        │                 │
        ├─────────────────┤
        │  Fin Actuation  │
        ├─────────────────┤
        │ Motor Section   │
        ├─────────────────┤
        │   29 mm Motor   │
        └─────────────────┘
                 │
                 ▼
               Nozzle
