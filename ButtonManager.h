#ifndef ButtonManager_h
#define ButtonManager_h

#include <Arduino.h>

class ButtonManager {
public:
  ButtonManager(int pin);
  void begin();
  bool isPressed();

private:
  int buttonPin;
  int buttonState;
};

#endif
