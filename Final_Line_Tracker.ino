/**********************************************************************
  Filename    : Tracking_Car.ino
  Product     : Freenove 4WD Car for Raspberry Pi Pico (W)
  Auther      : www.freenove.com
  Modification: 2023/07/10
**********************************************************************/

#include <Arduino.h>
#include "Freenove_4WD_Car_For_Pico_W.h"

#define SPEED_LV4   ( -47 )
#define SPEED_LV3   ( -40 )
#define SPEED_LV2   ( -25 )
#define SPEED_LV1   ( -25 )

void setup()
{
  Track_Setup();      //Trace module initialization
  Motor_Setup();      //Motor initialization
  Serial.begin(115200);
  //Emotion_Setup();    //Emotion initialization
}

int LastVal = 90;



void loop()
{
  delay(1);
  Track_Read();

  Serial.print("CHECKING WITH VALUE ");
  Serial.print(sensorValue[3]);
  Serial.print("\n");
  /*if (sensorValue[3] == LastVal) {
    Serial.println("SAME VALUE AS PREVIOUS CYCLE. TAKING NO ACTION.");
    return;
  }*/

  switch (sensorValue[3])
  {
    case 2:   //010
      Serial.println("SEES LINE IN MIDDLE. MOVING FORWARD");
      Motor_M_Move(SPEED_LV1, SPEED_LV1, SPEED_LV1, SPEED_LV1);
      break;
    case 5:   //101
      Serial.println("SEES LINE ON BOTH SIDES BUT NOT IN MIDDLE. CHANGING NOTHING.");
      //Motor_M_Move(0,0,0,0);
      break;
    case 0:   //000
      Serial.println("SEES NO LINE. CHANGING NOTHING.");
      //Motor_M_Move(0,0,0,0);
      break;
    case 7:   //111
      Serial.println("SEES LINE ON ALL THREE SIDES. MOVING FORWARD");
      Motor_M_Move(SPEED_LV1, SPEED_LV1, SPEED_LV1, SPEED_LV1);
      break;
    case 4:   //100
      Serial.println("SEES LINE ON LEFT SIDE. TURNING LEFT.");
      Motor_M_Move(-SPEED_LV2, -SPEED_LV2, SPEED_LV2, SPEED_LV2);
      break;
    case 6:   //110
      Serial.println("SEES LINE ON MIDDLE AND LEFT. MOVING FORWARD.");
      Motor_M_Move(SPEED_LV1, SPEED_LV1, SPEED_LV1, SPEED_LV1);
      break;
    case 1:   //001
      Serial.println("SEES LINE ON RIGHT SIDE. TURNING RIGHT.");
      Motor_M_Move(SPEED_LV2, SPEED_LV2, -SPEED_LV2, -SPEED_LV2);
      break;
    case 3:   //011
      Serial.println("SEES LINE ON RIGHT AND MIDDLE. MOVING FORWARD.");
      Motor_M_Move(SPEED_LV1, SPEED_LV1, SPEED_LV1, SPEED_LV1);
      break;
    default:
      Serial.println("DEFAULT CASE TRIGGERED?");
      break;
  }
  LastVal = sensorValue[3];
}
