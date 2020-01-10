#include "main.h"

void opcontrol() {
  while (true) {
    setDriveMotors();
    setIntake();
    setArm();
    setTray();
    moonwalk();

    pros::delay(10);
  }
}
