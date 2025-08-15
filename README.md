# Arduino-Bluetooth-4WD-Car-Control

This project implements motor control through an H-bridge and supports various movement commands via a Bluetooth mobile app.

![Arduino](https://github.com/user-attachments/assets/82bb66a4-6e27-462a-a936-193baf9b5d4a)

## Features

- 📶 Bluetooth remote control (HC-06 module)
- 🚫 4WD motor control via H-bridge (L298N or similar)
- ⚡ Independent power management (logic and motor circuits)
- 🎮 Multiple control modes:
  - Forward/Backward movement
  - Left/Right turns
  - Diagonal movements (forward-left, backward-right, etc.)
- 🏎️ Adjustable speed (0-9 levels)

 ![Montagem Arduino](https://github.com/user-attachments/assets/401898a3-d294-4458-846f-866bc8ed4528)


### Main Components
- Arduino Uno
- Sensor Shield (for easy connections)
- HC-06 Bluetooth Module
- L298N H-Bridge Motor Driver
- 4WD Chassis with 4 DC Motors
- 7.4V LiPo Battery (for motors)
- 9V Battery or 5V Power Supply (for Arduino and electronics)

## Software Requirements

- Arduino IDE
- Libraries:
  - `SoftwareSerial.h` (included with Arduino IDE)
- Bluetooth Control App (e.g., "Arduino Bluetooth Controller" on Play Store)

## Installation

1. Connect all components according to the pinout table above
2. Power the Arduino separately from the motor power supply
3. Upload the provided code to your Arduino
4. Pair your mobile device with the HC-06 module (default PIN: 1234)
5. Use any Bluetooth serial controller app to send commands

## Command Reference

F - Move Forward
B - Move Backward
R - Turn Right
L - Turn Left
G - Forward-Left (curve)
H - Forward-Right (curve)
I - Backward-Left
J - Backward-Right
S - Stop all motors
0 - Minimum speed (stop)
1-8 - Intermediate speed levels
9 - Maximum speed



https://github.com/user-attachments/assets/8f5c1fbd-14d1-458b-8f78-c13fc9829315



## Troubleshooting

- **Motors not moving**: Check power supply to H-bridge and motor connections
- **Bluetooth not connecting**: Verify TX/RX connections and pairing PIN
- **Low power**: Ensure batteries are fully charged
- **Motor direction wrong**: Swap IN1/IN2 or IN3/IN4 connections

## Customization

- Adjust `valSpeed` in code for different speed ranges
- Modify movement patterns in the motor control functions
- Add additional sensors by using remaining analog pins

## License

This project is open-source under the MIT License.
