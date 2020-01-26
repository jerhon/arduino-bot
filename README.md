# Arduino Bot

## License

Read the LICENSE file included in the repository.

## Overview

This is a personal arduino project based on the LAFVIIN Multi-Functional Smart Car Kit.

### Danceoff

This is a class I wrote with my kids and wife to program the robot to do a dance they came up with.  After we were done, we had a danceoff where we had a 3rd party vote for their favorite dance.

dance3 was the winner.

## Tooling Setup

Use the Arduino IDE to load, or Arduino extension for VS Code after setting it up for C++/Arduino development.  If using linux, this assumes that arduino is installed in /opt/arduino.

Instructions are on the Arduino site, and arduino-cli github project.

Install the pre-req arduino libraries

```
arduino-cli lib install Servo
arduino-cli lib install NewPing
```

## Environment Setup

WSL notes for enabling USB
https://docs.microsoft.com/en-us/archive/blogs/wsl/serial-support-on-the-windows-subsystem-for-linux

In WSL, I've found I need to connect to the Arduino in windows first before I can communicate with it in the WSL.  Not sure why yet.  Usually opening the serial monitor in arduino IDE in windows works enough for it to work once, then I close it and upload in WSL.


```
sudo usermod -a -G dialout <username>
```

