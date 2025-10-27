// A Class for being the base storage for threading motors.
#ifndef THREADEDMOTORBASE_H
#define THREADEDMOTORBASE_H

#include "vex.h"


namespace vex {

    class threadedMotorBase {

        public:

            threadedMotorBase() = delete;
            threadedMotorBase(vex::motor* motor);

            /// @brief This should be called as a thread, this will handle moving this motor.
            virtual void Handle() = 0;

            static int Trampoline(void* instance);
            void StartThreads();


        protected:
            vex::motor* internalMotor;

    };

}

#endif