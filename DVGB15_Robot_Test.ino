#include <kaulab.h>

//#include <Arduino_FreeRTOS.h>

void setup() {
  // put your setup code here, to run once:
  zInitialize();
 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int lineread = zRobotGetLineSensor();
  Serial.println(lineread);
  delay(500);
  //Serial.println("YEs");
  //delay(500);
  //Serial.begin(9600);
  
}
