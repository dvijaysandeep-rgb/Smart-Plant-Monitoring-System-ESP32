# 🌱 Smart Plant Monitoring and Automatic Irrigation System Using ESP32

## Overview

The Smart Plant Monitoring and Automatic Irrigation System is an IoT-based project developed using ESP32 to automate plant care and environmental monitoring.

The system continuously monitors soil moisture, temperature, humidity, and water tank level. Whenever the soil becomes dry, the ESP32 automatically activates a water pump through a relay module, ensuring optimal plant growth while reducing water wastage.

Real-time sensor data is displayed on an OLED screen and remotely monitored through the Blynk IoT platform.

---

## Features

* Automatic Plant Watering
* Soil Moisture Monitoring
* Temperature Monitoring using DHT11
* Humidity Monitoring using DHT11
* Water Tank Level Detection using HC-SR04
* OLED Real-Time Display
* Relay Controlled Water Pump
* Wi-Fi Connectivity using ESP32
* Blynk IoT Dashboard Integration
* Remote Monitoring through Smartphone
* Water Conservation through Smart Automation

---

## Hardware Components

| Component                 | Quantity    |
| ------------------------- | ----------- |
| ESP32 Development Board   | 1           |
| Soil Moisture Sensor      | 1           |
| DHT11 Sensor              | 1           |
| HC-SR04 Ultrasonic Sensor | 1           |
| Relay Module              | 1           |
| Mini Water Pump           | 1           |
| OLED Display (I2C)        | 1           |
| Breadboard                | 2           |
| Jumper Wires              | As Required |
| Water Tank                | 1           |

---

## Software & Tools Used

* Arduino IDE
* Blynk IoT Platform
* ESP32 Board Package
* Adafruit SSD1306 Library
* Adafruit GFX Library
* DHT Sensor Library
* EasyEDA
* Onshape
* GitHub

---

## Working Principle

1. Soil moisture sensor continuously monitors soil condition.
2. ESP32 processes sensor data.
3. If soil moisture drops below threshold:

   * Relay activates
   * Water pump turns ON
4. Pump stops automatically after sufficient moisture is detected.
5. DHT11 measures temperature and humidity.
6. HC-SR04 monitors water tank level.
7. OLED displays live sensor readings.
8. ESP32 uploads data to Blynk Cloud via Wi-Fi.
9. Users monitor the system remotely using a smartphone.

---

## IoT Dashboard Features

* Live Soil Moisture Monitoring
* Temperature Monitoring
* Humidity Monitoring
* Water Tank Monitoring
* Pump Status Monitoring
* Remote Access through Blynk Mobile App

---

## PCB Design

The project includes a custom PCB designed using EasyEDA for compact hardware implementation.

### PCB Features

* ESP32 Integration
* Sensor Interfaces
* Relay Driver Circuit
* OLED Connectivity
* Power Distribution Layout

---

## Testing Results

| Test Case                  | Result |
| -------------------------- | ------ |
| Dry Soil Condition         | PASS   |
| Wet Soil Condition         | PASS   |
| Temperature Monitoring     | PASS   |
| Humidity Monitoring        | PASS   |
| Water Level Detection      | PASS   |
| OLED Display Output        | PASS   |
| Blynk Dashboard Monitoring | PASS   |

---

## Future Improvements

* AI-Based Plant Care Recommendations
* Mobile Push Notifications
* Smart LED Grow Light Control
* Solar Powered Operation
* Cloud Data Analytics
* Multi-Plant Support
* 3D Printed Enclosure

---

## Project Images

### Hardware Setup

[Hardware](Full%20Hardware.jpeg)

### Circuit Diagram

[Circuit](circuit%20diagram.png)

### PCB Layout

[PCB](PCB%203D%20Layout.png)

### OLED Display Output

[OLED](OLED%20Display%20Data.jpeg)

---

## Author

**Sandeep Dhangar**
B.Tech – Electronics & Communication Engineering
Bharat Ratna Sardar Vallabh Bhai Patel Rajkiya Engineering College, Basti

---

## GitHub Repository

Smart Plant Monitoring and Automatic Irrigation System Using ESP32
