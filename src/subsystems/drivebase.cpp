#include "main.h"

void setDriveMotors() {
    double ratio = 2; //increase to make drive slower

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

void movement(int units, int voltage) {
    driveFR.tare_position();
    driveBR.tare_position();
    driveFL.tare_position();
    driveBL.tare_position();

    while (driveFL.get_position() < units) {
      driveFR.move(voltage);
      driveBR.move(voltage);
      driveFL.move(voltage);
      driveBL.move(voltage);

      pros::delay(10);
    }

    driveFR.move(-9);
    driveBR.move(-9);
    driveFL.move(-9);
    driveBL.move(-9);

    pros::delay(50);

    driveFR.move(0);
    driveBR.move(0);
    driveFL.move(0);
    driveBL.move(0);
}
