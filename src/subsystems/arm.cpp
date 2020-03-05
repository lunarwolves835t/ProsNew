#include "main.h"

void setArm() {
  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);

  if (!r && !l) {
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.move_velocity(0);
  } else {
    int sp = 127 * (l - r);

    tray.move(30);

    arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    arm.move(sp);
  }
}
