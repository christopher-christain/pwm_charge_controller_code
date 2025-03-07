# PWM Solar Charge Controller

## Overview

This project is a **Pulse Width Modulation (PWM) Solar Charge Controller** designed to efficiently charge a battery using solar panels. The system ensures safe and optimal charging by regulating the voltage and current from the solar panel to the battery. It prevents overcharging, over-discharging, and provides real-time monitoring of solar panel voltage, battery voltage, and charging current.

This repository contains the Arduino code, circuit diagrams, and documentation required to build and deploy the PWM solar charge controller.

---

## Features

- **PWM Charging**: Efficiently charges the battery using PWM to regulate the charging process.
- **Overcharge Protection**: Prevents the battery from overcharging by disconnecting the solar panel when the battery is fully charged.
- **Over-Discharge Protection**: Protects the battery from deep discharge by disconnecting the load when the battery voltage is too low.
- **Real-Time Monitoring**: Monitors solar panel voltage, battery voltage, and charging current.
- **LED Indicators**: Visual indicators for charging status, battery full, and low battery conditions.
- **Load Control**: Automatically connects/disconnects the load based on battery voltage.
- **Low Power Consumption**: Optimized for energy efficiency.

---

## Hardware Components

1. **Microcontroller**: Arduino Uno/Nano/ESP32/ESP8266
2. **Solar Panel**: 12V or 24V solar panel (depending on your battery).
3. **Battery**: 12V or 24V Lead-Acid, Li-ion, or LiPo battery.
4. **MOSFETs**: For PWM control and load switching.
5. **Voltage Sensors**: To measure solar panel and battery voltage.
6. **Current Sensor**: ACS712 or INA219 for current measurement.
7. **Diodes**: For reverse current protection.
8. **LEDs**: For status indicators (charging, battery full, low battery).
9. **Resistors and Capacitors**: For circuit stabilization and protection.
10. **Relay Module**: For load control (optional).

---

## Software Requirements

1. **Arduino IDE**: For uploading code to the microcontroller.
2. **Libraries**:
   - `Wire.h` for I2C communication (if using INA219).
   - `Adafruit_INA219.h` for current sensing (if using INA219).
3. **Optional Libraries**:
   - `WiFi.h` or `ESP8266WiFi.h` for remote monitoring (if using ESP32/ESP8266).
   - `Thingspeak.h` or `Blynk.h` for cloud-based data visualization.

---

## Circuit Diagram

![Circuit Diagram](images/circuit_diagram.png)  
*(Replace with your actual circuit diagram image or link)*

---

## Installation and Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/pwm-solar-charge-controller.git
