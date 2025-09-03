# smart-parking-system
The ESP32 Smart Parking System uses 5 IR sensors to monitor parking slots and a servo motor for gate control. Sensors detect whether slots are occupied or free, and ESP32 calculates available spaces. The system displays status via Serial/LCD and can be extended to IoT for real-time monitoring in malls, offices, and smart cities.
How It Works

IR Sensors for Slot Detection

Each parking slot has an IR sensor installed.

If a car is parked in the slot → sensor detects it and marks the slot as occupied.

If no car is present → slot is empty.

ESP32 as Controller

The ESP32 continuously reads signals from all 5 IR sensors.

It calculates the number of available slots = (Total slots − Occupied slots).

The result is displayed on the Serial Monitor (or LCD/Website if added).

Servo Motor for Gate Control

A servo motor is connected to the ESP32 to act as a parking gate barrier.

When a car arrives at the entry point:

If slots are available → the servo rotates (gate opens).

If slots are full → the servo remains closed.

Outputs

Serial Monitor → Shows number of available slots.

LCD Display or Webpage → Can display available/occupied slot status in real time.

 Buzzer/LED → Alerts when parking is full.

🔹 Advantages

Real-time parking status monitoring.

Automation reduces the need for manual checking.

Scalable → More slots can be added easily.

IoT-ready → With ESP32 WiFi, data can be sent to a web dashboard or mobile app.

🔹 Applications

Shopping malls 🏬

Office complexes 🏢

Airports ✈️

Smart cities 🚗
