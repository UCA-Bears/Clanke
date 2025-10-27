#include "threadedMotorBase.h"
#include "vex.h"

vex::threadedMotorBase::threadedMotorBase(vex::motor* motor)
:internalMotor(motor)
{

}

// A static "trampoline" function that takes a void* to the object.
int vex::threadedMotorBase::Trampoline(void* instance) {
if (instance) {
    // Cast the void* back to the correct class pointer.
    vex::threadedMotorBase* my_class_instance = static_cast<vex::threadedMotorBase*>(instance);
    // Call the non-static member function on that instance.
    my_class_instance->Handle();
}
return 0; // Return value is required by VEX thread signature.
}

void vex::threadedMotorBase::StartThreads() {
    // Pass the static trampoline function and a pointer to 'this'.
    vex::thread threadedMotor(vex::threadedMotorBase::Trampoline, this);
}
