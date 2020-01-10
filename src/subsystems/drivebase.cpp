#include "main.h"

void drive(double left, double right) {
  driveFR.move(right);
  driveBR.move(right);
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

    drive(speedLeft, speedRight);
    printf("%f %f", speedRight, speedLeft);
}


void tturn(int distance, int direction, double ratio) {
  driveFR.tare_position();
  driveBR.tare_position();
  driveFL.tare_position();
  driveBL.tare_position();

  int rlJoy = direction * 127;

  rlJoy = abs(rlJoy) < 10 ? 0 : rlJoy;

  double motorSpeed =  rlJoy * 0.7;
  motorSpeed /= ratio;

  double avgChange = (driveFR.get_position() +
                      driveBR.get_position() +
                      driveFL.get_position() +
                      driveBL.get_position()) / 2;

  while (avgChange < distance) {
    drive(motorSpeed, motorSpeed);
  }
}

void movement(int units, int leftVoltage, int rightVoltage) {
    driveFR.tare_position();
    driveBR.tare_position();
    driveFL.tare_position();
    driveBL.tare_position();

    while (driveFL.get_position() < units) {
      drive(leftVoltage, -rightVoltage);
      intakeL.move(127);
      intakeR.move(127);

      pros::delay(10);
    }

    drive(-10, -10);

    pros::delay(50);

    drive(0, 0);
}
