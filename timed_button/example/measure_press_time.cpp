#include "timed_button.hpp"
#include <Arduino.h>

const uint8_t BUTTON_PIN = 36;
const uint16_t BAUDRATE = 9600;
u_int8_t debouncing_interval = 100;
/* Create a new time button instance with:
- Pin 36 as input pin
- a debouncing value of 100 ms
- A pressed state of HIGH
*/
TimedButton btn = TimedButton(BUTTON_PIN, debouncing_interval, HIGH);

void setup() {

  Serial.begin(BAUDRATE);
  /* Initialise the button before usage */
  btn.init();
}

void loop() {

  /* If the button is pressed, the value is > 0 and 
  the code is blocked until the button is released
  The pressed time does not take care into account the debouncing */
  uint64_t elapsed = btn.getPressedTime();
  if (elapsed) {
    Serial.print("Btn pressed for ");
    Serial.print(elapsed);
    Serial.println(" ms.");
  }

  /* We include a small delay to debounce the button */
  delay(5);
}
