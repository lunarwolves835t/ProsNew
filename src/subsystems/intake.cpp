#include "main.h"

void setIntake() {
  int ip = 0;
  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

  ip = -127 * r + 127 * l;

  intakeL.move(ip);
  intakeR.move(ip);
}
