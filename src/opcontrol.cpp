#include "main.h"

void opcontrol() {
  while (true) {

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      checkRelease();
      setDriveMotors();
      setIntake();
      setArm();
      setTray();
      moonwalk();
    }
    else{
      deploy();
    }



    pros::delay(10);
  }
}
