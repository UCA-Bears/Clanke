/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Melfely                                                   */
/*    Created:      10/31/2024, 1:09:43 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "main.h"

using namespace vex;

// A global instance of competition
competition Competition;

//Controller
  controller Controller1 = controller();

//Motors 
  motor FR_Motor = motor(PORT10, false);
  motor FL_Motor = motor(PORT1, true);
  motor BR_Motor = motor(PORT20, false);
  motor BL_Motor = motor(PORT11, true); 
  motor intake_Motor_left = motor(PORT3, false);
  motor intake_Motor_right = motor(PORT8, true);
  motor intake_Motor_Back = motor(PORT15,true);
//Motor Groups
  motor_group LD_Motors = motor_group(FL_Motor, BL_Motor);
  motor_group RD_Motors = motor_group( FR_Motor, BR_Motor);
  motor_group Intake_Motors = motor_group(intake_Motor_left, intake_Motor_right,intake_Motor_Back);
//Sensors
  rotation leftMotors_Sensors(PORT10);
  rotation RightMotors_Sensors(PORT9);
  vision AIVisionSensor(PORT2);
  

// Variables


//Threaded Motor Instances
  threadedDriveMotor FR_Thread(&FR_Motor, &AxisFwdDriveOut, &AxisTurnDriveOut, true);
  threadedDriveMotor FL_Thread(&FL_Motor, &AxisFwdDriveOut, &AxisTurnDriveOut);
  threadedDriveMotor BR_Thread(&BR_Motor, &AxisFwdDriveOut, &AxisTurnDriveOut, true);
  threadedDriveMotor BL_Thread(&BL_Motor, &AxisFwdDriveOut, &AxisTurnDriveOut);
  

void pre_auton(void) {

  
}



void autonomous(void) {
  //Distance values are in INCHES
  //Turn Values are in degrees
  //Negative Distance is Backwards, Positive is Forwards
  //Negative degrees is left, Positive is right

  Intake_Motors.spin(fwd,100,pct);
  drive(50, vex::distanceUnits(40));
  turn(50, vex::rotationUnits(-50));
  drive(50, vex::distanceUnits(-36));
  turn(50, vex::rotationUnits(60));
  drive(50, vex::distanceUnits(-30));
  drive(50, vex::distanceUnits(20));


}



void usercontrol(void) {



  thread threadDrive = thread(threadedDrive);
  FR_Thread.StartThreads();
  FL_Thread.StartThreads();
  BR_Thread.StartThreads();
  BL_Thread.StartThreads(); 
 

  while (1) {
    

    wait(10, msec);

  }
}


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
