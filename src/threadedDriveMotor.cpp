#include "threadedDriveMotor.h"

/// @brief This should be called as a thread, which will then handle turning the drive motor
void vex::threadedDriveMotor::Handle() {
    while(this->hasInit) {
        if (*forwardControlValue == 0 && *turnControlValue == 0) {
            internalMotor->stop(brake);
        }
        else if (isTurnNegative) {
            internalMotor->spin(fwd, *forwardControlValue - *turnControlValue, pct);
        } else {
            internalMotor->spin(fwd, *forwardControlValue + *turnControlValue, pct); 
        }
        
        wait(5, vex::timeUnits::msec);
    }
}



/// @brief Call this constructor init this threaded drive Motor with the given pointers.
/// @param motor The motor pointer to reference that the thread will control
/// @param ForwardControlValue The pointer for the forwardDriveAxis Value.
/// @param TurnControlValue The Pointer for the turnDriveAxis Value, (turning)
/// @param IsTurnNegative // If turning needs to be subtractive rather than additve (right side to turn right for example)
vex::threadedDriveMotor::threadedDriveMotor(vex::motor* motor, double* ForwardControlValue, double* TurnControlValue, bool IsTurnNegative) 
: vex::threadedMotor(motor) {
    this->hasInit = true;
    this->forwardControlValue = ForwardControlValue;
    this->turnControlValue = TurnControlValue;
    this->isTurnNegative = IsTurnNegative;
}