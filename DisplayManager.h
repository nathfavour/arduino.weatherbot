#ifndef DisplayManager_h
#define DisplayManager_h

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define SPI pin connections
#define OLED_CLK 13    // Clock
#define OLED_MOSI 11   // Data input (DIN)
#define OLED_CS 10     // Chip select
#define OLED_DC 9      // Data/command
#define OLED_RESET 8   // Reset

class DisplayManager {
public:
  DisplayManager();
  void begin();
  void clear();
  void display();
  void setTextColor(uint16_t color);
  void setCursor(int x, int y);
  void setTextSize(int size);
  void print(const char* text);
  void print(float value, int decimalPlaces);
  void alerts(float tempC, float hum);
  void page1(float tempC);
  void page2(float tempC, float hum);
  void page3(float tempC, float hum);
  void page3wear(float tempC, float hum);
  void animation2(float tempC, float hum);
  void botcold();
  void botcold1();
  void bot3();
  void bot4();
  void animation();
  void bot();
  void bot1();
  void start();
  void temp23();

private:
  Adafruit_SSD1306 display;
};

#endif
