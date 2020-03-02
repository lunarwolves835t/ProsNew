#include "main.h"

void checkRelease() {
  bool x = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);

  if (x) {
    release();
  }
}

void release() {
  pros::delay(50);

  for (int i = 0; i < 35; i++) {
    //intakeL.move(-127);
    //intakeR.move(-127);
    arm.move(127);
    tray.move(-80);

    pros::delay(10);
  }
  for(int i = 0; i < 30; i++){
    tray.move(-80);
  }


  pros::delay(300);



  for (int i = 0; i < 167; i++) {
    arm.move(-127);
    tray.move(70);

    pros::delay(10);
  }
  for(int i = 0; i < 1; i++){
    arm.move(-6);
    pros::delay(10);
  }

}

void runIntake(int voltage) {
  if (voltage == 0) {
    intakeL.move(0);
    intakeR.move(0);
  }
  else {
    intakeL.move(voltage);
    intakeR.move(voltage);
  }
}

void setIntake() {
  int ip = 0;
  bool r = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
  bool l = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);

   //127 is outtake, -127 is intake

  if (!r && !l) {
    intakeL.move(0);
    intakeR.move(0);
  }
  else {
    ip = -127 * r + 127 * l;
    runIntake(ip);
  }
}


void moonwalk() {
  int ip = -127 * controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
  if (ip) {
    double moonWalkSpeed = -127 * controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) / 3.5;
    runIntake(ip);

    drive(moonWalkSpeed, -moonWalkSpeed);
  }
}

void intake(int direction, int distance) {
  while (driveFL.get_position() < distance) {
    runIntake(127);

    pros::delay(10);
  }

  while (intakeL.get_position() < distance) {

  }

  pros::delay(50);

  runIntake(0);
}
