//Main header file connecting all other header files to the same includes and to main.cpp

#ifndef MY_MAIN_H
#define MY_MAIN_H

    #include "vex.h"
    #include "functions.h"
    #include "auton.h"
    #include "threadedDriveMotor.h"
    #include <cmath>
    using namespace vex;

    //Controller
        extern controller Controller1;
    //Motors
        extern motor FR_Motor; //Front Right Motor
        extern motor FL_Motor; //Front Left Motor
        extern motor BR_Motor; //Back Right Motor
        extern motor BL_Motor; //Back Left Motor
        extern motor intake_Motor_left; // motor to control the intake roller // prot 3
        extern motor intake_Motor_right; // motor to control the intake roller // prot 8
        extern motor intake_Motor_Back; // the motor that controls the top intake and the rolloer // port 15

    //Motor Groups
        extern motor_group RD_Motors; //Right Side Drive Motors
        extern motor_group LD_Motors; //Left Side Drive Motors
        extern motor_group Intake_Motors; //'Intake motors gorup
    //Sensors 
        extern rotation leftMotors_Sensors ;
        extern rotation RightMotors_Sensors ;
        extern vision AIVisionSensor;
        


    //Variables
        extern double AxisFwdDriveOut; //To Send Forward Inputs too drive wheel Threads
        extern double AxisTurnDriveOut; //TO send stering inputs to drive wheel threads

        //All Speeds are in percent unless stated otherwise
        extern double Cv_Speed;  //Conveyer Speed
        extern double Tail_Speed; //Tail Speed 
        extern double R_Speed; //Roller Speed 

        

#endif