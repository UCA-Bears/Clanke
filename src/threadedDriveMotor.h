#ifndef THREADEDDRIVEMOTOR_H
#define THREADEDDRIVEMOTOR_H

#include "threadedMotor.h"

namespace vex {

    class threadedDriveMotor : vex::threadedMotor {
        public: 

            threadedDriveMotor(vex::motor* motor, double* ForwardControlValue, double* TurnControlValue, bool IsTurnNegative = false);

            void Handle() override;

        protected:
            double* forwardControlValue = nullptr;
            double* turnControlValue = nullptr;
            bool isTurnNegative;
            bool hasInit = false;  
        
    };
}

#endif