# WeatherBot 🤖🌦️

## Welcome! 👋

Get ready to meet your new best friend for weather updates! The WeatherBot is an Arduino-based project that keeps you informed about the temperature and humidity in your surroundings. It's like having a tiny, helpful meteorologist right on your desk! 

## What does it do? 🤔

The WeatherBot uses sensors to gather real-time temperature and humidity data, then displays this information on an OLED screen. It also provides alerts for possible weather conditions like rain or snow, and even suggests what you should wear! 👕🧥🩳

## Features ✨

-   **Real-time Monitoring:** 🌡️ Constantly updates temperature and humidity readings.
-   **OLED Display:** 🖥️ Shows the data on a clear, easy-to-read screen.
-   **Alerts:** 🚨 Warns you about potential rain or snow.
-   **Clothing Suggestions:** 👔👗 Recommends appropriate attire based on the weather.
-   **Interactive Button:** 🔘 Press a button to view alerts.
-   **Potentiometer Control:** ⚙️ Adjust settings using a potentiometer.
-   **Animated Interface:** 🤸 Fun animations to make your weather updates enjoyable!

## Hardware Required ⚙️

-   Arduino Board (e.g., Uno, Nano) 💻
-   DHT11 Temperature and Humidity Sensor 🌡️
-   OLED Display (128x64) 🖥️
-   Button 🔘
-   Potentiometer ⚙️
-   Jumper Wires  wires 🦺

## Software Required 💻

-   Arduino IDE 🔨
-   Libraries:
    -   `DHT11`
    -   `Adafruit_GFX`
    -   `Adafruit_SSD1306`

## Setup Instructions 🚀

1.  **Install Arduino IDE:** Download and install the Arduino IDE from the official website.
2.  **Install Libraries:**
    -   Open the Arduino IDE.
    -   Go to `Sketch` \> `Include Library` \> `Manage Libraries...`
    -   Search for and install the following libraries:
        -   `DHT11` by Rob Tillaart
        -   `Adafruit SSD1306` by Adafruit
        -   `Adafruit GFX Library` by Adafruit
3.  **Connect the Hardware:** 
    -   Connect the DHT11 sensor, OLED display, button, and potentiometer to the Arduino board according to your `config.h` file.
4.  **Upload the Code:**
    -   Open the `WeatherBot.ino` file in the Arduino IDE.
    -   Select the correct board and port.
    -   Upload the code to your Arduino board.

## Usage 🕹️

-   Once the code is uploaded, the WeatherBot will start displaying temperature and humidity readings on the OLED screen.
-   Use the potentiometer to navigate through different pages:
    -   Page 1: Animated display
    -   Page 2: Temperature and Humidity
    -   Page 3: Clothing suggestions with animations
-   Press the button to view alerts for possible weather conditions.

## Animations 🎬

Here are some cool animations you can expect:

*(Include GIFs or images of the animations here)*

## Contributing 🤝

Contributions are always welcome! If you have any ideas or improvements, feel free to submit a pull request.

## Author 👨‍💻

[NathFavour](https://github.com/NathFavour)

## License 📜

This project is licensed under the [MIT License](LICENSE).
