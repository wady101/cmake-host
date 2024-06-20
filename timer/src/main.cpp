// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Hardware.h"
#include "Timer.h"
#include "I_Command.h"

#include <chrono>
#include <iostream>

using namespace std;

class MotorBehaviour : public I_Command{
    Motor motor;
    public:
    MotorBehaviour(Motor &motor_) {motor = motor_;}

    void execute() override {
        static bool isOn = false;
        if (isOn)
            motor.on();
        else
            motor.off();
        isOn = !isOn;
    }
};

int main() {
  cout << "Design Patterns\n";

  Motor motor{};
  MotorBehaviour behave (motor);
  [[maybe_unused]] SevenSeg sevenseg{};
  Timer timer{500ms};

  timer.start(behave);
}
