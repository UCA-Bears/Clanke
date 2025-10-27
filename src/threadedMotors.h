#ifndef THREADEDMOTORS_H
#define THREADEDMOTORS_H

#include "threadedMotorBase.h"

namespace vex {

    class threadedRollerMotor : threadedMotorBase{
        public:
            threadedRollerMotor(vex::motor* motor, bool* spin, double* speed, vex::brakeType brakeType);

            void Handle() override;

            using threadedMotorBase::StartThreads;
        protected:
            bool* spin;
            double* speed;
            bool hasInit = false;  
    };


}


#endif