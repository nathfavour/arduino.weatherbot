#ifndef SensorManager_h
#define SensorManager_h

#include <dht11.h>

class SensorManager {
public:
  SensorManager(int pin);
  void read();
  float getTemperature();
  float getHumidity();

private:
  int dht11Pin;
  dht11 DHT11;
  float temperature;
  float humidity;
};

#endif
