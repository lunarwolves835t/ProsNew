#include "main.h"

void autonomous(){
  //release();
  //movement(100, 30, 30, true);
  // drive(127, 127);
  // pros::delay(400);
  // drive(0, 0);
  // pros::delay(40);

//pushbot
  drive(100, 100);
  pros::delay(1500);
  drive(-40, -40);
  pros::delay(3000);
  drive(0, 0);
//pushbot
  release();

  pros::delay(200);
  //redProtected();

  //redNonProtected();

  //movement(1000, 60, 60);
  //movement(-1000, 60, 60);
  //tturn(500, -1, 2.5);
}

void redProtected() {
  // pros::delay(100);
  // drive(60, 60);
  // runIntake(127);
  // pros::delay(2000);
  // drive(0, 0);
  // runIntake(0);
  // pros::delay(100);
  // drive(-60, -60);
  // pros::delay(2000);

  movement(3000, 60, 60, true);
  //movement(2000, -60, -60, false);
  //movement(1000, -60, 60, false);
  //movement(400, 40, 40, false);
  //deploy();
}

void pushbot() {

}

void blueUnprotected(){
  movement(2900, 60, 60, true);
}

void redNonProtected() {
  //forwards
  //left
  //forward
  //reverse
  //do a 180
  //forwards, then deploy
  // movement(2900, 60, 60);
  //
  // movement(300, -30, 30);
  //
  // movement(300, 60, 60);
  //
  // movement(1000, -50, -50);
  //
  // movement(600, -40, 40);
  //
  // movement(400, 30, 30);

  deploy();
}
