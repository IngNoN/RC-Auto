/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

  const int freq = 5000;
  const int ledChannel = 0;
  const int resolution = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("MyEsp32");       //set bluetooth name of your device



  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(16, ledChannel); // GPIO 16 = RX2
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  
  float y_axis = GamePad.gety_axis();
  if (y_axis >= 0)
  {
    ledcWrite(ledChannel, y_axis * 36);
  }
}
