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
