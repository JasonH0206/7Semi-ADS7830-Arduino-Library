# 7Semi-ADS7830-Arduino-Library

This Arduino library provides support for the **7Semi ADS7830 ADC Module**, an 8-channel 8-bit analog-to-digital converter that communicates over I2C. It enables fast, low-power analog signal acquisition in embedded systems, compatible with microcontrollers like Arduino, ESP32, STM32, and others.

![Arduino](https://img.shields.io/badge/platform-arduino-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Status](https://img.shields.io/badge/status-active-brightgreen.svg)

---

## Hardware Required

- 7Semi ADS7830 ADC Module  
- Arduino-compatible board  
- I2C connection (SDA, SCL)  

---

## Getting Started

### 1. Installation via Arduino Library Manager

1. Open the **Arduino IDE**
2. Navigate to:
   - `Sketch > Include Library > Manage Libraries…` (IDE 1.x), or  
   - Use the 📚 Library Manager icon in IDE 2.x
3. Search for:
   -7Semi ADS7830
4. Click **Install**

In your sketch:

#include <7semi_ads7830.h>
#### 2. Wiring

| ADS7830 Pin | Arduino Pin                      |
| ----------- | -------------------------------- |
| VCC         | 3.3V or 5V                       |
| GND         | GND                              |
| SDA         | A4 (Uno)                         |
| SCL         | A5 (Uno)                         |
| ADDR        | GND/VCC (for I2C address config) |

### 3. Applications

Analog sensor interfacing

Battery monitoring

Robotics and automation

Educational projects
