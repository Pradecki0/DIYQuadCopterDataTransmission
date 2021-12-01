# DIYQuadCopterDataTransmission

Built a DIY Quadcopter Drone, with an Arduino Uno microcontroller mounted atop running an RTOS program (sending Inertial Measurement Unit (IMU) Sensor captures Roll+Pitch+Yaw data over I2C buss and streaming data to Rasberry Pi over the serial port) while transmitting GPS and WebCam data connected to a Raspberry Pi 4 microprocessor (also mounted on the QuadCopter drone). The system can capture Roll+Pitch+Yaw on the Arduino Uno, send over I2C to the RPi, capture GPS Lat+Lon_Alt and WebCam Video on the RPi, send Roll+Pitch+Yaw, Lat+Lon+Alt via WiFi from RPi to a Host machine continuously streaming over a TCP/IP socket, while displaying on the host. 


Hardware Components:
• Raspberry Pi 4 4GB Model B (Running Raspberry Pi OS, Kernel Version 5.10)
• Adafruit 9-DOF Absolute Orientation IMU - BNO055
•	G-Mouse USB GPS receiver unit 
• 32GB Micro SD card 
• 5V-3A Anker Power Bank (to power Uno & RPi)
• USB C Cable (for power)
• USB Webcam module
• Assembled QWinOut Quadcopter & Controller DIY kit (Parts list below)
   • F450 Nylon Fiber Drone Frame Kit (4-axis 450mm Quadcopter Frame & Center)
   • 4 drone arms (2 red in color & 2 white in color)
   • 4 QWinOut 30A Electronic Speed Controller (ESC)
   • 4 Propellers - 1045 10x4.5 (2 Clockwise & 2 Counter-Clockwise)
   • 4 QWinOut A2212/13T Brushless Motors 
   • 4 Prop Screw bases
   • 4 Prop Nuts
   • 4 Prop Caps
   • KK Multicopter Flight Controller 
   • QWinOut LI-PO Battery Pack
   • Radiolink R8EF Receiver
   • Radiolink T8FB Remote Controller
   • 4 Skid Legs
   • Zip Ties 
   • Velcro Strap
   • Adhesive Tape 
   • Various Screws For Assembly 
   • WRB Plug to WRB Plug
   • WRB Plug to W Plug + R Plug + B Plug
• Windows Laptop Host Machine
• WiFi Router 
• Zip ties
• Arduino Uno Microcontroller
• Various Jumper Wires
• Solderless Breadboard

Full Drone System:
![PXL_20211107_191355425](https://user-images.githubusercontent.com/88686423/144148483-ff9cdb31-4807-4f85-aab0-3c9ec0bde0e3.jpg)

Schematic View of Arduino Uno microcontroller connected to IMU Sensor:
![proj8_schem_schem](https://user-images.githubusercontent.com/88686423/144149042-6644e7e0-4741-40d3-80bd-abbd2007f981.png)

FAA Recreational Drone Registration:
![Drone_certificate](https://user-images.githubusercontent.com/88686423/144149077-2b4abb34-43ed-4194-928b-34b9b5e47176.png)

