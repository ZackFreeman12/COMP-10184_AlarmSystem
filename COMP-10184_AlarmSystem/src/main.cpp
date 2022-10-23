
// COMP-10184 – Mohawk College
// I Zack Freeman, 000781330 certify that this material is my original work.
// No other person's work has been used without due acknowledgement.
// I have not made my work available to anyone else."

#include <Arduino.h>

// digital input pin definitions
#define PIN_PIR D5
#define PIN_BUTTON D6
bool alarmTripped = false;
// *************************************************************
void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);

  // configure the LED output
  pinMode(LED_BUILTIN, OUTPUT);

  // PIR sensor is an INPUT
  pinMode(PIN_PIR, INPUT);

  // Button is an INPUT
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

// *************************************************************
void loop()
{
  if (!alarmTripped)
  {
    bool bPIR;

    bPIR = digitalRead(PIN_PIR);

    if (bPIR)
    {
      int count = 0;
      while (count < 40)
      {
        // turn the LED ON
        digitalWrite(LED_BUILTIN, LOW);
        delay(125);

        // turn the LED OFF
        digitalWrite(LED_BUILTIN, HIGH);
        delay(125);
        count += 1;
      }

      digitalWrite(LED_BUILTIN, LOW);
      alarmTripped = true;
    }
  }
}
