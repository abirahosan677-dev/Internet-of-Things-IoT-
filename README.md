Smart Silent Sound Spike & Temperature Detector

Overview

The Smart Silent Sound Spike & Temperature Detector is an Arduino-based project designed to detect sudden sound spikes and temperature changes. It uses a sound sensor to detect claps or loud noises and a temperature sensor to monitor the surrounding environment. When certain thresholds are exceeded, it triggers visual (LED) and auditory (buzzer) alerts. The system can also be muted with a button.

Components

KY-038 Sound Sensor: Detects sound spikes (e.g., claps or loud noises).

LM35 Temperature Sensor: Monitors temperature and provides analog input.

LiquidCrystal LCD Display: Displays status messages such as "NO ALERT" or an active alert.

LED: Illuminates when a sound spike or temperature alert is triggered.

Buzzer: Emits sound when an alert condition is met.

Button: A push button to mute/unmute alerts.

Features

Sound Spike Detection: Monitors sound levels and activates the LED and buzzer when a sound spike is detected.

Temperature Monitoring: Continuously monitors the temperature and activates alerts if the temperature goes beyond a preset threshold.

Mute/Unmute Button: Allows the user to mute or unmute the buzzer for alerts.

LCD Display: Displays messages like "NO ALERT" or "ALERT" to indicate the system's status.

Pin Configuration

Sound Sensor (KY-038): Connected to digital pin 7.

LED: Connected to digital pin 9.

Buzzer: Connected to digital pin 8.

Button: Connected to digital pin 6.

Temperature Sensor (LM35): Connected to analog pin A3.

LCD Display: Connected to pins 12, 11, 5, 4, 3, and 2.

Installation

Hardware Setup:

Connect the KY-038 sound sensor to digital pin 7.

Connect the LM35 temperature sensor to analog pin A3.

Connect the LED to digital pin 9.

Connect the buzzer to digital pin 8.

Connect the push button to digital pin 6.

Connect the LCD display according to the pin configuration in the code.

Arduino IDE:

Install the LiquidCrystal library via the Arduino Library Manager.

Open the Arduino IDE, paste the code into the editor, and upload it to your Arduino board.

Usage

Power on the system.

The LCD will display "NO ALERT" initially.

If a loud sound is detected or if the temperature exceeds the set threshold, the LED and buzzer will activate.

Press the button to mute or unmute the alerts.

Code Explanation

The sensor pin is used to read the sound sensor's output.

The LM35_PIN is used to read the temperature.

The buttonPin is used to detect the mute/unmute button press.

The LCD shows the current system status, whether there are alerts or not.

The LED and buzzer are activated when sound or temperature spikes are detected.

Acknowledgments

This project was created as part of a student assignment to learn about sensors, Arduino programming, and real-time monitoring systems.
