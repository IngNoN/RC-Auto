#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <Servo.h>
static const int servoPin = 27;

Servo servo1;

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
    Serial.begin(9600); 
    Dabble.begin("Opel Calibra ESP32");
    servo1.attach(servoPin);
}

int posDegrees = 90;

void loop() {
    Dabble.processInput();
  
    float x_axis = GamePad.getXaxisData();


     if (x_axis != 0)
    {
        while(posDegrees > 90 + (x_axis * 6.428)) {
            servo1.write(posDegrees);
            delay(10);
            posDegrees--;
    }

    while(posDegrees < 90 + (x_axis * 6.428)) {
        servo1.write(posDegrees);
        delay(10);
        posDegrees++;
        Serial.println(x_axis);
    }
  }
    else if(x_axis == 0)
    {
        while(posDegrees < 90) {
            servo1.write(posDegrees);
            delay(10);
            posDegrees++;
        }
        while(posDegrees > 90) {
            servo1.write(posDegrees);
            delay(10);
            posDegrees--;
        }
    }
}