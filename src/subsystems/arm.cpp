#include "main.h"

void setArm() {
  int ratio = 2;

  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);

  if (!r && !l) {
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.move_velocity(0);
  } else {
    int sp = 127 * (l - r) / ratio;

    arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    arm.move(sp);
    tray.move(sp);
  }
}
