# Mini RF Fire Fighting Robot

Welcome to the Mini RF Fire Fighting Robot project repository! This project involves creating a tracked mini robot that can extinguish small fires using a PS2 wireless RF remote control. The robot is equipped with a rear-end water supply system, and the nozzle's up-and-down movement is controlled via the remote.

## Overview

The Mini RF Fire Fighting Robot is a tracked robot designed to extinguish fires using a water supply system controlled by a PS2 wireless RF remote. The robot's nozzle, which dispenses water, can be adjusted up and down to direct the water stream. This robot does not include fire detection capabilities and is operated manually.

## Components

- **Arduino microcontroller** or Robot Control Board 20A compatible with Arduino
  - [Product Link](https://robokits.co.in/development-board/motor-control-boards/robot-control-board/robot-control-board-20a-compatible-with-arduino)
- **PS2 wireless RF remote control and receiver**
  - [Product Link](https://robokits.co.in/wireless-solutions/ir-rf-remote-control/playstation-2-wireless-rf-remote-ps2-for-robot-control)
- Nozzle 
- Motors (100rpm 12V) and motor drivers (if using Arduino or any other microcontroller)
- Servo motor
- Tracked chassis
- Battery pack

## Circuit Diagram

The circuit diagram shows how the Arduino, PS2 remote receiver, and servo motor for controlling the nozzle are connected.

<img src="https://github.com/Varshith-Poojary/mini-rc-firefighting-robot/blob/main/Circuit%20diagram.png" alt="Circuit Diagram" width="500"/>

## Control Board

The control board image provides an overview of the custom control board used in this project, including its specifications.

<img src="https://github.com/Varshith-Poojary/mini-rc-firefighting-robot/blob/main/Arduino%20UNO%20R3%20based%2020A%20robot%20controller%20board.png" alt="Control Board" width="500"/>

### Specifications

- **Microcontroller**: ATmega328P
- **Voltage**: 7V - 24V
- **Supply Current**: 1A - 20A
- For more details, visit: [Robot Control Board 20A](https://robokits.co.in/development-board/motor-control-boards/robot-control-board/robot-control-board-20a-compatible-with-arduino)

### Installing the Arduino Bootloader on a Custom Board

Using a custom board with an ATmega328P-AU microcontroller requires a few additional steps compared to using a standard Arduino Uno. Follow these steps to set up and program your custom board to control a servo motor:

#### 1. Prepare an Arduino as ISP

1. Use another Arduino board (like an Uno) as an ISP programmer.
2. Connect it to your computer and upload the "ArduinoISP" sketch from the Arduino IDE:
   - Go to **File > Examples > 11.ArduinoISP > ArduinoISP**.

#### 2. Connect the ISP Programmer

Connect the Arduino ISP to your custom board using jumper wires. You’ll need to connect:

- **MISO** (Pin 12 on the ISP) to **MISO** on the custom board
- **MOSI** (Pin 11 on the ISP) to **MOSI** on the custom board
- **SCK** (Pin 13 on the ISP) to **SCK** on the custom board
- **RESET** (Pin 10 on the ISP) to **RESET** on the custom board
- **VCC** (5V on the ISP) to **VCC** on the custom board
- **GND** (Ground on the ISP) to **GND** on the custom board

#### 3. Burn the Bootloader

1. In the Arduino IDE, go to **Tools > Board** and select "Arduino Uno" (since it uses the same microcontroller).
2. Go to **Tools > Programmer** and select "Arduino as ISP".
3. Click **Tools > Burn Bootloader**. This will upload the bootloader to your ATmega328P-AU.

## Transmitter and Receiver Connections

This section includes images showing the connections between the PS2 wireless RF remote transmitter and receiver modules used for controlling the robot.

<img src="https://github.com/Varshith-Poojary/mini-rc-firefighting-robot/blob/main/reciver_and_board_connection.png" alt="Transmitter and Receiver Connections" width="500"/>
<img src="https://github.com/Varshith-Poojary/mini-rc-firefighting-robot/blob/main/PS2_Plug_Connections.png" alt="PS2 Plug Connections" width="500"/>

## Final Model

Here is an image of the completed Mini RF Fire Fighting Robot, showcasing its tracked design and overall setup.

<img src="https://github.com/Varshith-Poojary/mini-rc-firefighting-robot/blob/main/Final%20model.png" alt="Final Model" width="500"/>

## Arduino Code

The Arduino code controls the robot's water pump and nozzle movement based on input from the PS2 wireless RF remote. The code is located in the `main.ino` folder.
