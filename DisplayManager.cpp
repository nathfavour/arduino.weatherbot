#include "DisplayManager.h"

DisplayManager::DisplayManager() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS) {}

void DisplayManager::begin() {
  Serial.println("Initializing OLED...");
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 initialization failed!"));
    for (;;); // Infinite loop on failure
  }
  Serial.println("OLED initialized successfully!");
  display.clearDisplay();
}

void DisplayManager::clear() {
  display.clearDisplay();
}

void DisplayManager::display() {
  display.display();
}

void DisplayManager::setTextColor(uint16_t color) {
  display.setTextColor(color);
}

void DisplayManager::setCursor(int x, int y) {
  display.setCursor(x, y);
}

void DisplayManager::setTextSize(int size) {
  display.setTextSize(size);
}

void DisplayManager::print(const char* text) {
  display.print(text);
}

void DisplayManager::print(float value, int decimalPlaces) {
  display.print(value, decimalPlaces);
}

void DisplayManager::alerts(float tempC, float hum) {
  clear();
  setTextColor(SSD1306_WHITE);
  setCursor(0, 0);
  setTextSize(2);
  print("Alerts");
  setCursor(0, 40);
  if ((hum >= 75) && (tempC <= 2)) {
    print("Possible Snow");
  } else if ((hum >= 75) && (tempC >= 3) && (tempC <= 6)) {
    print("Freezing Rain");
  } else if ((hum >= 75) && (tempC >= 7)) {
    print("Rain");
  } else {
    print("No Alerts");
  }
  display();
}

void DisplayManager::page3(float tempC, float hum) {
  animation2(tempC, hum);
}

void DisplayManager::page3wear(float tempC, float hum) {
  setTextColor(SSD1306_WHITE);
  setCursor(0, 0);
  setTextSize(2);
  print("WeatherBot");
  setCursor(0, 20);

  if (hum >= 80) {
    setCursor(0, 20);
    print("Jacket");
    setCursor(0, 40);
    print("Rainpants");
  } else if ((tempC >= 18) && (tempC <= 33)) {
    setCursor(0, 20);
    print("T-Shirt");
    setCursor(0, 40);
    print("Shorts");
  } else if ((tempC >= 8) && (tempC <= 17)) {
    setCursor(0, 20);
    print("Hoodie");
    setCursor(0, 40);
    print("Pants");
  } else if ((tempC >= 0) && (tempC <= 6)) {
    setCursor(0, 20);
    print("Jacket");
    setCursor(0, 40);
    print("Pants");
  }
}

void DisplayManager::animation2(float tempC, float hum) {
  if (hum >= 80) {
    page3wear(tempC, hum);
    display();
    delay(500);
    clear();
    page3wear(tempC, hum);
    display();
    delay(500);
    clear();
  } else if (tempC >= 6) {
    page3wear(tempC, hum);
    bot3();
    display();
    delay(500);
    clear();
    bot4();
    page3wear(tempC, hum);
    display();
    delay(500);
    clear();
  } else if (tempC <= 5) {
    page3wear(tempC, hum);
    botcold();
    display();
    delay(50);
    clear();
    botcold1();
    page3wear(tempC, hum);
    display();
    delay(50);
    clear();
  }
}

void DisplayManager::botcold() {
  setTextSize(2);
  setCursor(98, 20);
  print("o");
  setCursor(80, 35);
  print("/||\\");
  setCursor(92, 50);
  print("==");
}

void DisplayManager::botcold1() {
  setTextSize(2);
  setCursor(97, 20);
  print("o");
  setCursor(79, 35);
  print("/||\\");
  setCursor(91, 50);
  print("==");
}

void DisplayManager::bot3() {
  setTextSize(2);
  setCursor(98, 20);
  print("o");
  setCursor(80, 35);
  print("/||\\");
  setCursor(92, 50);
  print("==");
}

void DisplayManager::bot4() {
  setTextSize(2);
  setCursor(98, 18);
  print("o");
  setCursor(80, 33);
  print("/||\\");
  setCursor(92, 48);
  print("==");
}

void DisplayManager::page2(float tempC, float hum) {
  setTextColor(SSD1306_WHITE);
  clear();
  setCursor(0, 0);
  setTextSize(2);
  print("WeatherBot");
  setCursor(5, 30);
  setTextSize(3);
  print(hum, 0);
  print("%");
  setCursor(75, 30);
  print(tempC, 0);
  setTextSize(2);
  print("C");
  display();
  delay(400);
}

void DisplayManager::page1(float tempC) {
  animation();
}

void DisplayManager::animation() {
  clear();
  bot();
  start();
  temp23();
  display();
  delay(500);
  clear();
  bot1();
  start();
  temp23();
  display();
  delay(500);
}

void DisplayManager::bot() {
  setTextSize(2);
  setCursor(28, 15);
  print("o");
  setCursor(10, 30);
  print("/||\\");
  setCursor(22, 45);
  print("==");
}

void DisplayManager::bot1() {
  setTextSize(2);
  setCursor(28, 13);
  print("o");
  setCursor(10, 28);
  print("/||\\");
  setCursor(22, 43);
  print("==");
}

void DisplayManager::start() {
  setTextSize(2);
  setTextColor(SSD1306_WHITE);         // Size 2
  setCursor(0, 0);            // Start at top-left corner
  print("WeatherBot");
}

void DisplayManager::temp23() {
  setTextSize(3);
  setCursor(70, 30);
  print((float)DHT11.temperature, 0);
  setTextSize(2);
  print("C");
}
