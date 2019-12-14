#include "main.h"

void setDriveMotors() {
    double ratio = 2.5; //increase to make drive slower

    int fbJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rlJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    fbJoy = abs(fbJoy) < 10 ? 0 : fbJoy;
    rlJoy = abs(rlJoy) < 10 ? 0 : rlJoy;

    double speedRight = rlJoy * 0.7 - fbJoy;
    speedRight /= ratio;

    double speedLeft = rlJoy * 0.7 + fbJoy;
    speedLeft /= ratio;

    driveFR.move(speedRight);
    driveBR.move(speedRight);
    driveFL.move(speedLeft);
    driveBL.move(speedLeft);
    printf("%f %f", speedRight, speedLeft);
}

void tturn(int distance, int direction, float ratio) {
  int fbJoy = 0;
  int rlJoy = direction * 127;

  fbJoy = abs(fbJoy) < 10 ? 0 : fbJoy;
  rlJoy = abs(rlJoy) < 10 ? 0 : rlJoy;

  double speedRight = rlJoy * 0.7 - fbJoy;

  double speedLeft = rlJoy * 0.7 + fbJoy;

  speedRight /= ratio;
  speedLeft /= ratio;

  for (int i = 0; i < distance; i++) {
    driveFR.move(speedRight);
    driveBR.move(speedRight);
    driveFL.move(speedLeft);
    driveBL.move(speedLeft);
  }
}

void movement(int units, int leftVoltage, int rightVoltage) {
    driveFR.tare_position();
    driveBR.tare_position();
    driveFL.tare_position();
    driveBL.tare_position();

    while (driveFL.get_position() < units) {
      driveFR.move(-rightVoltage);
      driveBR.move(-rightVoltage);
      driveFL.move(leftVoltage);
      driveBL.move(leftVoltage);

      pros::delay(10);
    }

    driveFR.move(-10);
    driveFL.move(-10);
    driveBR.move(-10);
    driveBL.move(-10);

    pros::delay(50);

    driveFR.move(0);
    driveBR.move(0);
    driveFL.move(0);
    driveBL.move(0);
}
