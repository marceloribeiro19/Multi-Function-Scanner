# Custom Raspberry Pi Project

## Overview

This project involves the development of a custom Linux image for the Raspberry Pi using Buildroot. The system integrates various hardware components and software functionalities to meet specific project requirements, including a GUI, temperature sensor, RGB LED device driver, and database management.

## Key Features

- **Custom Linux Image**:
  - Created specifically for the project's needs using Buildroot.

- **Multitasking and GUI Development**:
  - Developed in C and C++ using PThreads as the multitasking API.
  - GUI implemented with QTCreator on a 5-inch touchscreen.

- **Hardware Integration**:
  - Integration of a temperature sensor.
  - Custom device driver for an RGB LED developed from scratch.

- **Database Management**:
  - SQLite used as an embedded database to store all stock information.

- **Data Recording and Visualization**:
  - ThingSpeak COTS utilized to record all sales performed by the scanner and represent them graphically.

## Technical Specifications

- **Operating System**: Custom Linux image built with Buildroot.
- **Programming Languages**: C and C++.
- **Multitasking API**: PThreads.
- **GUI Development Tool**: QTCreator.
- **Touchscreen**: 5-inch display.
- **Database**: SQLite.
- **Data Recording Tool**: ThingSpeak COTS.

## Methodology

1. **Custom Linux Image**:
   - Creation of a tailored Linux image using Buildroot to meet specific project requirements.

2. **Software Development**:
   - **Multitasking**:
     - Implementation using PThreads for efficient multitasking.
   - **GUI**:
     - Developed with QTCreator for a 5-inch touchscreen interface.

3. **Hardware Integration**:
   - **Temperature Sensor**:
     - Integration and data handling of the temperature sensor.
   - **RGB LED**:
     - Development of a custom device driver for the RGB LED.

4. **Database Management**:
   - **SQLite**:
     - Integration of SQLite as an embedded database for stock information management.

5. **Data Recording and Visualization**:
   - **ThingSpeak COTS**:
     - Utilization for recording and graphical representation of sales data.

## Implementation

1. **Custom Linux Image**:
   - Built using Buildroot, tailored to the specific needs of the project.

2. **Software Components**:
   - **Multitasking with PThreads**:
     - Developed in C and C++ for efficient task management.
   - **GUI Implementation**:
     - Created using QTCreator for a 5-inch touchscreen display.

3. **Hardware Components**:
   - **Temperature Sensor**:
     - Integrated and programmed to provide real-time data.
   - **RGB LED Driver**:
     - Custom driver developed from scratch to control the RGB LED.

4. **Database Integration**:
   - **SQLite**:
     - Embedded database used to store and manage stock information.

5. **Data Management**:
   - **ThingSpeak COTS**:
     - Utilized to log sales data and generate graphical representations.

## Conclusion

This Raspberry Pi project demonstrates the effective integration of custom software and hardware components tailored to specific requirements. With a custom-built Linux image, multitasking capabilities, a user-friendly GUI, and robust data management, this project serves as a comprehensive solution for the intended application. Detailed implementation and results can be found in the provided project report.
