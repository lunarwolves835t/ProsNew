#include <string>
#include <iostream>
#include "main.h"

void drive(double left, double right) {
  driveFR.move(-right);
  driveBR.move(-right);
  driveFL.move(left);
  driveBL.move(left);
}

void setDriveMotors() {
    double ratio = 1.5; //increase to make drive slower

    int fbJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rlJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    fbJoy = abs(fbJoy) < 10 ? 0 : fbJoy;
    rlJoy = abs(rlJoy) < 10 ? 0 : rlJoy;

    double speedRight = rlJoy * 0.7 - fbJoy;
    speedRight /= ratio;

    double speedLeft = rlJoy * 0.7 + fbJoy;
    speedLeft /= ratio;

    drive(speedLeft, -speedRight);
    printf("%f %f", speedRight, speedLeft);
}


void tturn(int distance, int direction, double ratio) {

}

void movement(int units, int leftVoltage, int rightVoltage) {
    driveFR.tare_position();
    driveBR.tare_position();
    driveFL.tare_position();
    driveBL.tare_position();

    while (driveFL.get_position() < units) {
      drive(leftVoltage, rightVoltage);
      intakeL.move(127);
      intakeR.move(127);

      arm.move(40);

      pros::delay(10);
    }

    intakeL.move(0);
    intakeR.move(0);

    drive(-10, -10);

    pros::delay(50);

    drive(0, 0);
}

void deploy() {
  int trayDistance = 3060; //2800 2900
  int pushDistance = 150; // 400 500
  int outtakeDistance = 500;
  int trayBack = 3100;

  int traySpeed = 80;
  int intakeSpeed = 70;
  int driveSpeed = 50;


  // tray out until 90*
  tray.tare_position();
  tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  while (tray.get_position() > -trayDistance) {
    tray.move(-traySpeed);
    //std::string thing = std::to_string(tray.get_position());

    //const char* value = thing.c_str();

    //controller.set_text(0, 0, value);
  }

  tray.move(0);
  tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  pros::delay(200);

  driveFR.tare_position();
  driveBR.tare_position();
  driveFL.tare_position();
  driveBL.tare_position();

  int ratio = 2;

  // while (driveFL.get_position() < pushDistance) {
  //   drive(driveSpeed / ratio, driveSpeed / ratio);
  // }

  drive(0, 0);

  pros::delay(500);

  // outtake while reversing

  driveFR.tare_position();
  driveBR.tare_position();
  driveFL.tare_position();
  driveBL.tare_position();

  int reduction = 2;

  intakeL.move(-intakeSpeed * 2);
  intakeR.move(-intakeSpeed * 2);

  pros::delay(1000);

  while (driveFL.get_position() > -outtakeDistance) {
    drive(-driveSpeed / reduction, -driveSpeed / reduction);
  }

  intakeL.move(0);
  intakeR.move(0);
  drive(0, 0);

  //tray back

  tray.tare_position();
  tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  while (tray.get_position() < trayBack) {
    tray.move(traySpeed);
  }

  tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
