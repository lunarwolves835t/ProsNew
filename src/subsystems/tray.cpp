#include "main.h"

void setTray() {
  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y);

    if (!r && !l) {
      tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      tray.move_velocity(0);
    } else {
      int sp = 100 * (l - r);

      tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      tray.move(sp);
    }

}
