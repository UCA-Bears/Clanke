// A Class for being the base storage for threading motors.
#include "vex.h"


namespace vex {

    class threadedMotor {

        public:

            
            threadedMotor(vex::motor* motor);

            /// @brief This should be called as a thread, this will handle moving this motor.
            virtual void Handle() = 0;


        protected:
            vex::motor* internalMotor;

    };

}