#include "config.h"
#include "DisplayManager.h"
#include "SensorManager.h"
#include "ButtonManager.h"

DisplayManager display;
SensorManager sensor(DHT11_PIN);
ButtonManager button(BUTTON_PIN);

int val;

void setup() {
  Serial.begin(9600);
  display.begin();
  button.begin();
}

void loop() {
  sensor.read();
  val = analogRead(POT_PIN);
  val = map(val, 0, 1032, 0, 100);

  if (button.isPressed()) {
    display.alerts(sensor.getTemperature(), sensor.getHumidity());
  } else if ((val >= 0) && (val <= 30)) {
    display.page1(sensor.getTemperature());
  } else if ((val >= 31) && (val <= 60)) {
    display.page2(sensor.getTemperature(), sensor.getHumidity());
  } else if ((val >= 61) && (val <= 100)) {
    display.page3(sensor.getTemperature(), sensor.getHumidity());
  }

  delay(50);
}
