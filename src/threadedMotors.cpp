#include "threadedMotors.h"

#pragma region Rollers

vex::threadedRollerMotor::threadedRollerMotor(vex::motor* motor, bool* spin, double* speed, vex::brakeType brakeType)
: vex::threadedMotorBase(motor)
{
    this->internalMotor->setBrake(brakeType);
    this->hasInit = true;
}

void vex::threadedRollerMotor::Handle() {
    while(hasInit) {
        if (*spin) {
            this->internalMotor->spin(fwd, *speed, pct);
        } else {
            this->internalMotor->stop();
        }

        wait(10, vex::timeUnits::msec);
    }
}




#pragma endregion