#ifndef THREADEDDRIVEMOTOR_H
#define THREADEDDRIVEMOTOR_H

#include "threadedMotorBase.h"

namespace vex {

    class threadedDriveMotor : vex::threadedMotorBase {
        public: 

            threadedDriveMotor(vex::motor* motor, double* ForwardControlValue, double* TurnControlValue, bool IsTurnNegative = false);

            void Handle() override;

            using threadedMotorBase::StartThreads;
        protected:
            double* forwardControlValue = nullptr;
            double* turnControlValue = nullptr;
            bool isTurnNegative;
            bool hasInit = false;  
        
    };
}

#endif