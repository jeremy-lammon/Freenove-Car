#include <Arduino.h>
#include "Ultrasonic.h"
#include "Freenove_4WD_Car_For_Pico_W.h"

int Current_Angle = 90;
int Current_Direction = 1;  // 1 = Left | 2 = Right
int Angle_Increment = 1;
float Previous_Distance;
const float OBSTACLE_DISTANCE = 20;

void ultrasonic_scan_setup() {
  Serial.begin(115200);
  Ultrasonic_Setup();
  Servo_Setup();
  Servo_1_Angle(90);
  Previous_Distance = Get_Sonar();
}

void Move() {
  if (Current_Direction == 2) {
    if (Current_Angle - Angle_Increment < 30) {
      Current_Angle = 30;
      Serial.println("SETTING TO 30, TOO FAR RIGHT.");
      Current_Direction = 1;
    } else {
      Current_Angle -= Angle_Increment;
    }

  } else {
    if (Current_Angle + Angle_Increment > 150) {
      Current_Angle = 150;
      Serial.println("SETTING TO 150, TOO FAR LEFT");
      Current_Direction = 2;
    } else {
      Current_Angle += Angle_Increment;
    }
  }
}




void Sweep_Step(float This_Distance) {
    Servo_1_Angle(Current_Angle);
  if (false) {
      if (This_Distance > Previous_Distance) {
        if (Current_Direction == 1) {
          Current_Direction = 2;
        } else {
          Current_Direction = 1;
        }
      }
      else {
        return;
      }
  }
  if (This_Distance <= Previous_Distance) {

    }
    else {
        if (Current_Direction == 1) {
            Current_Direction = 2;
            Serial.println("CHANGING FROM RIGHT TO LEFT");
        }
        else {
            Current_Direction = 1;
            Serial.println("CHANGING FROM LEFT TO RIGHT");
        }
  }


  Move();
}
bool Locked_On = false; // if true, searched for the obstacle it's locked on. if false, stays in middle.
bool Previously_Locked = false;

void ultrasonic_scan_loop() {
  float This_Distance = Get_Sonar();

  if (This_Distance > OBSTACLE_DISTANCE) {
    Locked_On = false;
    Previously_Locked = false;
  } else {
    Locked_On = true;
    if (Previously_Locked == false) {

    }
  }

  if (Locked_On == false && Previously_Locked == false) {
    
    Servo_1_Angle(90);
    Current_Angle = 90;
    Previously_Locked = true;
  } else if (Locked_On == true) {
    Sweep_Step(This_Distance);
  }

  Previous_Distance = This_Distance;
}
