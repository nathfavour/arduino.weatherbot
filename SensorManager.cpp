





































}  delay(50);  }    display.page3(sensor.getTemperature(), sensor.getHumidity());  } else if ((val >= 61) && (val <= 100)) {    display.page2(sensor.getTemperature(), sensor.getHumidity());  } else if ((val >= 31) && (val <= 60)) {    display.page1(sensor.getTemperature());  } else if ((val >= 0) && (val <= 30)) {    display.alerts(sensor.getTemperature(), sensor.getHumidity());  if (button.isPressed()) {  val = map(val, 0, 1032, 0, 100);  val = analogRead(potpin);  sensor.read();void loop() {}  button.begin();  display.begin();  Serial.begin(9600);void setup() {ButtonManager button(buttonPin);SensorManager sensor(DHT11PIN);DisplayManager display;int val;int potpin = 0;const int buttonPin = 2;#define DHT11PIN 4// Define pin connections#include "config.h" // Include config.h#include "ButtonManager.h"#include "SensorManager.h"#include "DisplayManager.h"