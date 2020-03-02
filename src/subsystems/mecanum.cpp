#include "main.h"

void driveMecanum(double moveX, double moveY, double turn) {
  double frontLeft = moveY - moveX + turn;
  double frontRight = moveY - moveX - turn;
  double backLeft = moveY + moveX + turn;
  double backRight = moveY + moveX - turn;

  driveFL.move(frontLeft);
  driveFR.move(frontRight);
  driveBL.move(backLeft);
  driveBR.move(backRight);
}

void checkMecanum() {
  double ratio = 1; //replace with power curve later

  int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
  int translateX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
  int translateY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

  //deadzone
  turn = abs(turn) < 5 ? 0 : turn;
  translateX = abs(translateX) < 5 ? 0 : translateX;
  translateY = abs(translateY) < 5 ? 0 : translateY;

  bool bLeft = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  bool bRight = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
  //power curve
  turn = 1/16129.0 * pow(turn, 3);
  translateX = 1/16129.0 * pow(translateX, 3);
  translateY = 1/16129.0 * pow(translateY, 3);

  // Digital controls
  if (bLeft && !bRight) {
    translateX = -100;
    turn += 18;
  }
  else if (bRight && !bLeft) {
    translateX = 100;
    turn -= 18;
  }
  else {
    translateX = 0;
  }


  driveMecanum(translateX, translateY, turn);
}
