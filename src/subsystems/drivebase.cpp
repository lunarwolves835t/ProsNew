#include <string>
#include <iostream>
#include "main.h"

bool kill = false;

void drive(double left, double right) {
  driveFR.move(right);
  driveBR.move(right);
  driveFL.move(left);
  driveBL.move(left);
}

void setDriveMotors() {
    double ratio = 1; //increase to make drive slower

    int fbJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rlJoy = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    fbJoy = abs(fbJoy) < 10 ? 0 : fbJoy;
    rlJoy = abs(rlJoy) < 10 ? 0 : rlJoy;

    double speedRight = rlJoy * 0.7 - fbJoy;
    speedRight /= ratio;

    double speedLeft = rlJoy * 0.7 + fbJoy;
    speedLeft /= ratio;

    if (speedLeft != 0 || speedRight != 0) {
      kill = false;
    }

    drive(speedLeft, -speedRight);
    printf("%f %f", speedRight, speedLeft);
}


void movement(int units, int leftVoltage, int rightVoltage, bool intake) {
    driveFR.tare_position();
    driveBR.tare_position();
    driveFL.tare_position();
    driveBL.tare_position();

    float averagePos = 0;


    while (averagePos < units) {
      drive(leftVoltage, rightVoltage);
      intakeL.move(127*intake);
      intakeR.move(127*intake);

      pros::delay(10);

      averagePos = (fabs(driveFR.get_position()) +
                   fabs(driveBR.get_position()) +
                   fabs(driveFL.get_position()) +
                   fabs(driveBL.get_position())) / 4.0;

      arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      arm.move(40);
    }
    intakeL.move(0);
    intakeR.move(0);
    drive(-10, -10);

    pros::delay(50);

    drive(0, 0);
}



void deploy() {
  int trayDistance = 3080; //2800 2900
  int pushDistance = 15; // 400 500
  int outtakeDistance = 500;
  int trayBack = 3150;

  int traySpeed = 65;
  int intakeSpeed = 70;
  int driveSpeed = 50;

// outtakes cubes to ready
  if (!kill) {
    runIntake(-intakeSpeed * 1.5f);

    pros::delay(325);
  }

  runIntake(0);


// brings tray out
  killSwitch();
  if (!kill) {
    // tray out until 90*
    tray.tare_position();
    tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    while (tray.get_position() > -trayDistance) {
      killSwitch();
      if (!kill) {
        tray.move(-traySpeed);
        //std::string thing = std::to_string(tray.get_position());

        //const char* value = thing.c_str();

        //controller.set_text(0, 0, value);
      }
      else {
        break;
      }
    }

    tray.move(0);
    tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }

  killSwitch();

  pros::delay(500);

  driveFR.tare_position();
  driveBR.tare_position();
  driveFL.tare_position();
  driveBL.tare_position();

  tray.tare_position();
  tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  while (tray.get_position() < 20) {
    killSwitch();
    if (!kill) {
      tray.move(traySpeed);
      //std::string thing = std::to_string(tray.get_position());

      //const char* value = thing.c_str();

      //controller.set_text(0, 0, value);
    }
    else {
      break;
    }
  }

  pros::delay(200);
  runIntake(-40);
  pros::delay(12);
  runIntake(0);
  // int ratio = 2;
  //
  // while (driveFL.get_position() < pushDistance) {
  //   killSwitch();
  //
  //   if (!kill) {
  //     drive(driveSpeed / ratio, driveSpeed / ratio);
  //   }
  //   else {
  //     break;
  //   }
  // }

  drive(0, 0);

  pros::delay(500);

  // outtake while reversing

  driveFR.tare_position();
  driveBR.tare_position();
  driveFL.tare_position();
  driveBL.tare_position();

  killSwitch();
  double reduction = 0.5;
  if (!kill) {
    runIntake(-intakeSpeed * 0.75f);

    pros::delay(1);
  }

pros::delay(500);

  while (driveFL.get_position() > -outtakeDistance) {
    killSwitch();
    if (!kill) {
      driveMecanum(0, -driveSpeed, 0);
    }
    else {
      break;
    }
  }

  runIntake(0);
  drive(0, 0);

  //tray back

  tray.tare_position();

  killSwitch();

  if (!kill) {
    tray.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

    while (tray.get_position() < trayBack) {
      if (!kill) {
        tray.move(traySpeed);
      }
      else {
        break;
      }
    }

    tray.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
}

void killSwitch() {
  bool k = controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);

  if (k) {
    kill = true;
  }
}
//
// void turn(int degrees, int Voltage) { //- | + for left | right
//   int current_rotation = inertS.get_rotation();
//
//   Voltage *= degrees < 0 ? -1 : 1;
//
//   while (inertS.get_rotation() < degrees) {
//     drive(Voltage, -Voltage);
//     pros::delay(10);
//
//   }
// }
