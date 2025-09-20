#include "threadedMotor.h"

namespace vex {

    class threadedDriveMotor : vex::threadedMotor {
        public: 

            /// @brief This should be called as a thread, which will then handle turning the drive motor
            void Handle() override {
                while(this->hasInit) {
                    
                    if (isTurnNegative) {
                        internalMotor->spin(fwd, *forwardControlValue - *turnControlValue, pct);
                    } else {
                       internalMotor->spin(fwd, *forwardControlValue + *turnControlValue, pct); 
                    }
                    
                    wait(5, vex::timeUnits::msec);
                }
            }

            /// @brief Call this to init this drive Motor with the given pointers.
            /// @param ForwardControlValue The pointer for the forwardDriveAxis Value.
            /// @param TurnControlValue The Pointer for the turnDriveAxis Value, (turning)
            /// @param IsTurnNegative // If turning needs to be subtractive rather than additve (right side to turn right for example)
            void Init(double* ForwardControlValue, double* TurnControlValue, bool IsTurnNegative = false) {
                this->hasInit = true;
                this->forwardControlValue = ForwardControlValue;
                this->turnControlValue = TurnControlValue;
                this->isTurnNegative = IsTurnNegative;
            }
        protected:
            double* forwardControlValue = nullptr;
            double* turnControlValue = nullptr;
            bool isTurnNegative;
            bool hasInit = false;  
        
    };
}