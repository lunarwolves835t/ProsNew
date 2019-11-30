#include "main.h"

void autonomous(){
  //sintake(1);
  mov(10, 50);
  //sintake(0);
  mov(10, -50);
  turnn(-1, 50);
  mov(5, 50);
}

void mov(double dist, int vel) { //moves robot dist inches forwards
  const double circum = 4 * 3.14;
  double revo = dist/circum;

  driveFL.move_relative(revo, vel);
  driveFR.move_relative(revo, vel);
  driveBR.move_relative(revo, vel);
  driveBL.move_relative(revo, vel);
}

void turnn(int direc, double velocity) { //direc must be -1 or 1
  const double vel = velocity;

  driveFL.move_relative(direc, velocity);
  driveFL.move_relative(direc, velocity);
  driveFL.move_relative(direc, velocity);
  driveFL.move_relative(direc, velocity);
}

void sintake(int state) { //state must be -1, 0, or 1
  intakeL.move(127 * state);
  intakeR.move(127 * state);
}
