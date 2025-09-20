// A Class for being the base storage for threading motors.
#ifndef THREADEDMOTOR_H
#define THREADEDMOTOR_H

#include "vex.h"


namespace vex {

    class threadedMotor {

        public:

            threadedMotor() = delete;
            threadedMotor(vex::motor* motor);

            /// @brief This should be called as a thread, this will handle moving this motor.
            virtual void Handle() = 0;


        protected:
            vex::motor* internalMotor;

    };

}

#endif