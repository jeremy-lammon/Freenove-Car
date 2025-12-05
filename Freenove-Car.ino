/**********************************************************************
  Filename    : Tracking_Car.ino
  Product     : Freenove 4WD Car for Raspberry Pi Pico (W)
  Auther      : www.freenove.com
  Modification: 2023/07/10
**********************************************************************/

#include <Arduino.h>
#include "Freenove_4WD_Car_For_Pico_W.h"
#include "Line_Tracking.h"

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

  Serial.print("CHECKING WITH VALUE ");
  Serial.print(sensorValue[3]);
  Serial.print("\n");

  track_line_move();
}
