# ESP32 Access Point with Login Page

This project sets up an ESP32 as an Access Point (AP) with a login page. Users can connect to the AP and log in with a username and password to access a settings page.

## Description

This project is designed to help developers set up an ESP32 as an Access Point with a simple login interface. However, there is an important note regarding the ESPAsyncWebServer library. If you download the ESPAsyncWebServer library directly from the Arduino IDE Library Manager, you might encounter errors when compiling the code for the ESP32. These errors are due to some functions in the library that are not compatible with the ESP32.

To resolve this, you can use a pre-modified version of the ESPAsyncWebServer library that has been adjusted for ESP32 compatibility. You can download this modified library directly from the provided link to ensure smooth operation.

## Features

- Creates an AP with a specified SSID and password
- Hosts a web server on the ESP32
- Provides a login page for users to enter their username and password
- Displays a settings page upon successful login

## Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software)
- [ESP32 Board Package](https://dl.espressif.com/dl/package_esp32_index.json)
- [AsyncTCP Library](https://github.com/me-no-dev/AsyncTCP)
- Modified ESPAsyncWebServer Library (Download from the provided link)

## Installation

1. **Install ESP32 Board Package**

   - Open Arduino IDE.
   - Go to `File` > `Preferences`.
   - Add the following URL to the "Additional Board Manager URLs":
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Go to `Tools` > `Board` > `Boards Manager`.
   - Search for "esp32" and install the latest version.

2. **Install Required Libraries**

   - Go to `Sketch` > `Include Library` > `Manage Libraries...`.
   - Search for `AsyncTCP` and install it.

3. **Install Modified ESPAsyncWebServer Library**

   - Download the modified ESPAsyncWebServer library from the provided link.
   - Extract the downloaded file.
   - Copy the extracted folder to your Arduino libraries directory (usually located in `Documents/Arduino/libraries`).

## Usage

1. **Upload the Code**

   - Open the `ESP32_Access_Point.ino` file in Arduino IDE.
   - Select the appropriate ESP32 board from `Tools` > `Board`.
   - Connect your ESP32 board to your computer.
   - Click the Upload button to upload the code to your ESP32.

2. **Connect to the Access Point**

   - Connect to the Wi-Fi network with SSID `ESP32-Access-Point` and password `12345678`.
   - Open a web browser and navigate to the IP address displayed in the Serial Monitor (usually `192.168.4.1`).

3. **Login**

   - Enter `admin` as both the username and password to access the settings page.


