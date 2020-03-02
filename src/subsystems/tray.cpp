#include "main.h"

void setTray() {
  int ratio = 2;

  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y);

  bool override = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
  bool doverride = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);

  if (!override && !doverride) {
    if (!r && !l) {
      tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      tray.move_velocity(0);
    } else {
      int sp = 127 * (l - r) / ratio;

      tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      tray.move(sp);
    }
  } else {
    overrideTray(override, doverride);
  }
}

void overrideTray(bool ov, bool dov) {
  int ratio = 2;

  if (!ov && !dov) {
    ov = controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP);
    dov = controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
  }

  int sp = 126 * (ov - dov) / ratio;

  tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  tray.move(-sp);

  arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  arm.move(sp);
}
