# 🌡️ Real-Time Body Temperature Monitoring Prototype

A real-time, contactless body temperature monitoring prototype developed using an ESP32 and MLX90614 infrared temperature sensor. The system measures body and ambient temperature, displays the readings on an OLED, and provides visual and audible alerts when the measured body temperature exceeds a predefined threshold.

---

## 📌 Project Overview

Conventional body temperature measurement often requires physical contact and manual observation. This project demonstrates a compact embedded system capable of contactless temperature measurement, real-time display, threshold-based temperature classification, and immediate alert generation.

The prototype integrates sensing, processing, display, and alert mechanisms using an ESP32-based embedded platform.

---

## 🎯 Objectives

- Measure body temperature without physical contact.
- Continuously display body and ambient temperature.
- Automatically detect temperature above a predefined threshold.
- Provide visual and audible alerts for elevated temperature.
- Implement real-time sensor data acquisition and processing.
- Integrate sensors and output devices using an ESP32.
- Demonstrate I²C-based sensor and display interfacing.

---

## ⚙️ Key Features

- 🌡️ Contactless temperature sensing
- 📊 Real-time body and ambient temperature display
- 🖥️ 0.96-inch OLED user interface
- 🚨 Threshold-based temperature detection
- 🔴 Red LED indication for elevated temperature
- ⚪ White LED indication for normal condition
- 🔊 Buzzer-based audible alert
- 🙂 OLED status indication using graphical faces
- 🔌 I²C communication
- 💻 ESP32-based real-time processing

---

## 🧰 Hardware Components

| Component | Purpose |
|---|---|
| ESP32 | Main microcontroller and processing unit |
| MLX90614 | Contactless infrared temperature sensor |
| 0.96" SSD1306 OLED | Temperature and status display |
| Red LED | Elevated temperature indication |
| White LED | Normal condition indication |
| Buzzer | Audible warning |
| Breadboard | Circuit prototyping |
| Jumper Wires | Component connections |
| Resistors | LED current limiting |
| USB Power | Power and programming |

---

## 💻 Software & Technologies

- Arduino IDE
- Embedded C/C++
- ESP32
- I²C Communication
- MLX90614 Sensor Library
- Adafruit GFX Library
- Adafruit SSD1306 Library

---

## 🔌 Pin Configuration

| Component | ESP32 Pin |
|---|---:|
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| MLX90614 SDA | GPIO 21 |
| MLX90614 SCL | GPIO 22 |
| Buzzer | GPIO 25 |
| Red LED | GPIO 26 |
| White LED | GPIO 27 |

### OLED Configuration

I²C Address: 0x3C
Resolution: 128 × 64

### System Architecture

          ┌──────────────────┐
          │    MLX90614      │
          │ IR Temperature   │
          │     Sensor       │
          └────────┬─────────┘
                   │
                   │ I²C
                   ▼
          ┌──────────────────┐
          │      ESP32       │
          │ Data Acquisition │
          │   & Processing   │
          └───────┬──────────┘
                  │
        ┌─────────┼─────────┐
        │         │         │
        ▼         ▼         ▼
     OLED      LEDs       Buzzer
 


