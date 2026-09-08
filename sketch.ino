
#include <kaulab.h>

void setup() {
  zInitialize();
}

void loop() {
  int distance = zRobotGetUltraSensor();

  if (distance > 0 && distance < 15) {
    // Object detected
    zRobotSetMotorSpeed(1, 60);
    zRobotSetMotorSpeed(2, 60);

  }
  else {
    // No object detected
    zRobotSetMotorSpeed(1, -60);
    zRobotSetMotorSpeed(2, 60);

  }

  zBlockingDelay(10);
}
