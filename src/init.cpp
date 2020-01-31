#include "main.h"

void initialize() {
  pros::lcd::initialize();
  pros::lcd::set_text(0, "Lunar Wolves 835T");

  driveFR.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveFL.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveBR.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveBL.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  intakeL.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  intakeR.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //inertS.reset();
}
