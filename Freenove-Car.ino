#include <Arduino.h>
#include "Freenove_4WD_Car_For_Pico_W.h"
#include "Line_Tracking.h"
#include "Ultrasonic.h"

#define TURN_POWER ( -50 )
#define FORWARD_POWER ( -25 )

void setup()
{
  tracker_setup();
  ultrasonic_scan_setup();
  Serial.begin(9600);
}


bool Disabled = false;
int Time = 0;

void Single_Move( int Mseconds, int Left_M_Power, int Right_M_Power) {
  Motor_M_Move(Left_M_Power, Left_M_Power, Right_M_Power, Right_M_Power);
  delay(Mseconds);
  Motor_M_Move(0,0,0,0);
  delay(500);
}

void Move_Around() {
        Single_Move(225, -TURN_POWER, TURN_POWER);
        
        Single_Move(600, FORWARD_POWER, FORWARD_POWER);

        Single_Move(250, TURN_POWER, -TURN_POWER);

        Single_Move(200, FORWARD_POWER, FORWARD_POWER);
        do {
          Single_Move(100, FORWARD_POWER, FORWARD_POWER);
          Single_Move(225, TURN_POWER, -TURN_POWER);
          float Distance = Get_Sonar();
          if (Distance >60) {
            break;
          }
          Single_Move(225, -TURN_POWER, TURN_POWER);
        } while(true);

        Single_Move(500, FORWARD_POWER, FORWARD_POWER);

        Single_Move(225, -TURN_POWER, TURN_POWER);

}

void loop()
{
  /*if (Time % 10 == 0) {
    float Obstacle_Distance = Get_Sonar();
    Serial.println(Obstacle_Distance);
    if (Obstacle_Distance <= 20) {
      if (Disabled == false) {
        //Initial Stop
        Disabled = true;
        //Move_Around();
      }
    }
    else{
      Disabled = false;
    }
  }*/
  

  track_line_move();

  delay(1);
  //Time += 1;
}
