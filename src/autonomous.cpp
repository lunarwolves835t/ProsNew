#include "main.h"

void autonomous(){
  //sintake(1);
  //mov(10, 50);
  //sintake(0);
  //mov(10, -50);
  //turnn(-1, 50);
  //mov(5, 50);

  int sp = 127 / 2;

  arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  for (int i = 0; i < 50; i++) {
    arm.move(sp);
  }

  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  arm.move_velocity(0);

  movement(3250, 60, 60);

  //tturn(500, -1, 2.5);
}
