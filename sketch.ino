#include <kaulab.h>
// void obstacle_Calc(){
//   int s = 0;
//   int t = 0;
//   int v = 0;
//   if ()
// }
// 3 = no line
// 0 = both on line
// 2 = right on line
// 1 = left on line

// 1 = Right motor
// 2 = left motor

void goRight(){
    zRobotSetMotorSpeed(1, 0);
    zRobotSetMotorSpeed(2, 80);
    return;
}
void goLeft(){
    zRobotSetMotorSpeed(1, -80);
    zRobotSetMotorSpeed(2, 0);
    return;
}
void findLine(){
  zRobotSetMotorSpeed(1, -60);
    zRobotSetMotorSpeed(2, 0);   
    return;
} 
void goStraight(){
    zRobotSetMotorSpeed(1, -80);
    zRobotSetMotorSpeed(2, 80);
    return;
}

void followLine(){
  while(1){
    int lineread = zRobotGetLineSensor();
    
  if (lineread == 2){
    zSetAllLed(0, 0, 255);
    goLeft();
  } else if(lineread == 1){
    zSetAllLed(0, 255, 0);
    goRight();
  } else if(lineread == 0){
    zSetAllLed(255, 255, 255);
    goStraight();
  } else if (lineread == 3){
    zSetAllLed(255, 255, 0);
     findLine();
  }
  }
}
void obstacle(){
 int distance = zRobotGetUltraSensor();
 if(distance > 0 && distance < 20){
    zSetAllLed(255, 0, 0);
   zRobotSetMotorSpeed(1, -70);
   zRobotSetMotorSpeed(2, 60);
 } else {
    // No object detected
    // zSetAllLed(255, 255, 255);
    zRobotSetMotorSpeed(1, -60);
    zRobotSetMotorSpeed(2, 60);
}
}

void setup() {
  // put your setup code here, to run once:
  zInitialize();
  // zRobotSetMotorSpeed(1, -70);
  // zRobotSetMotorSpeed(2, 0);
   zScheduleTask(followLine, 100, 70);
  zScheduleTask(obstacle, 70, 70);
// obstacle();
  zStart();
  
}

void loop() {
}
