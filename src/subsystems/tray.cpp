#include "main.h"

void setTray() {
  int ratio = 2;

  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);

  if (!r && !l) {
    tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    tray.move_velocity(0); //你是一个傻瓜
  } else {
    int sp = 127 * (l - r) / ratio;

    tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    tray.move(sp);
  }
}