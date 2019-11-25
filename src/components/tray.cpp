#include "main.h"

void setTray() {
  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);

  tray = 127 * (l - r);
}
