#include <Arduino.h>
#include "Freenove_4WD_Car_For_Pico_W.h"
#include "Line_Tracking.h"



#define SPEED_LV2   ( -50 )
#define SPEED_LV1   ( -50 )

void tracker_setup()
{
  Track_Setup();      //Trace module initialization
  Motor_Setup();      //Motor initialization
}


void track_line_move()
{

    delay(1);
    Track_Read();

    switch (sensorValue[3])
    {
        case 2:   //010
        Motor_M_Move(SPEED_LV1, SPEED_LV1, SPEED_LV1, SPEED_LV1);
        
        break;
        case 5:   //101
        break;
        case 0:   //000
        break;
        case 7:   //111
        Motor_M_Move(SPEED_LV1, SPEED_LV1, SPEED_LV1, SPEED_LV1);
        break;
        case 4:   //100
        Motor_M_Move(-SPEED_LV2, -SPEED_LV2, SPEED_LV2, SPEED_LV2);
        break;
        case 6:   //110
        Motor_M_Move(SPEED_LV1, SPEED_LV1, SPEED_LV1, SPEED_LV1);
        break;
        case 1:   //001
        Motor_M_Move(SPEED_LV2, SPEED_LV2, -SPEED_LV2, -SPEED_LV2);
        break;
        case 3:   //011
        Motor_M_Move(SPEED_LV1, SPEED_LV1, SPEED_LV1, SPEED_LV1);
        break;
        default:
        //Serial.println("DEFAULT CASE TRIGGERED?");
        break;

    }
}
