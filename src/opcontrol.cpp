#include "main.h"

void opcontrol() {
  while (true) {
    setDriveMotors();
    setIntake();

    pros::delay(10);
  }
}
