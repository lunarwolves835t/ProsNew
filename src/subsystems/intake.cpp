#include "main.h"

void checkRelease() {
  bool x = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);

  if (x) {
    release();
  }
}

void release() {
  pros::delay(50);

  for (int i = 0; i < 200; i++) {
    intakeL.move(-127);
    intakeR.move(-127);
    arm.move(127);

    pros::delay(10);
  }

  pros::delay(500);

  intakeL.move(0);
  intakeR.move(0);

  for (int i = 0; i < 50; i++) {
    arm.move(-127);

    pros::delay(10);
  }
}

void setIntake() {
  int ip = 0;
  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

  ip = -127 * r + 127 * l; //127 is outtake, -127 is intake

  intakeL.move(ip);
  intakeR.move(ip);
}


void moonwalk() {
  int ip = -127 * controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
  if (ip) {
    double moonWalkSpeed = -127 * controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) / 3.5;
    intakeL.move(ip);
    intakeR.move(ip);

    drive(moonWalkSpeed, -moonWalkSpeed);
  }
}

void intake(int direction, int distance) {
  while (driveFL.get_position() < distance) {
    intakeL.move(127);
    intakeR.move(127);

    pros::delay(10);
  }

  while (intakeL.get_position() < distance) {

  }

  pros::delay(50);

  intakeL.move(0);
  intakeR.move(0);
}
