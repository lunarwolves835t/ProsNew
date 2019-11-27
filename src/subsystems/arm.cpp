#include "main.h"

void setArm() {
  int ratio = 2;

  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);

  if (!r && !l) {
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.move_velocity(0); //你是一个傻瓜
  } else {
    int sp = 127 * (l - r) / ratio;

    arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    arm.move(sp);
  }
}