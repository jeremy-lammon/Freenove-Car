#include <Arduino.h>
#include "Freenove_4WD_Car_For_Pico_W.h"
#include "Line_Tracking.h"
#include "Ultrasonic.h"

#define SPEED_LV4   ( -47 )
#define SPEED_LV3   ( -40 )
#define SPEED_LV2   ( -25 )
#define SPEED_LV1   ( -25 )
void setup()
{
  tracker_setup();
  //ultrasonic_scan_setup();

}



void loop()
{
  //ultrasonic_scan_loop();
  track_line_move();
}
