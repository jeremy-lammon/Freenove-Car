#include <Arduino.h>
#include "Freenove_4WD_Car_For_Pico_W.h"
#include "Line_Tracking.h"




#define SPEED_LV1   ( -30 )

void tracker_setup()
{
  Track_Setup();      //Trace module initialization
  Motor_Setup();      //Motor initialization
}


float Previous_Left = 0;
float Previous_Right = 0;

void track_line_move()
{

    delay(1);
    Track_Read();

    switch (sensorValue[3])
    {
        case 2:   //010
        Previous_Left = SPEED_LV1;
        Previous_Right = SPEED_LV1;
        break;
        case 5:   //101
        break;
        case 0:   //000
        break;
        case 7:   //111
        Previous_Left = SPEED_LV1;
        Previous_Right = SPEED_LV1;
        break;
        case 4:   //100
        Previous_Left = -SPEED_LV1;
        Previous_Right = SPEED_LV1;
        break;
        case 6:   //110
        break;
        case 1:   //001
        Previous_Left = SPEED_LV1;
        Previous_Right = -SPEED_LV1;
        break;
        case 3:   //011
        break;
        default:
        break;

    }
    Motor_M_Move(Previous_Left, Previous_Left, Previous_Right, Previous_Right);
}
