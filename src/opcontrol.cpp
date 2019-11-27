#include "main.h"

void opcontrol() {
  while (true) {
    setDriveMotors();
    setIntake();
    setArm();

    pros::delay(10);
  }
}
