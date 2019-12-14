#include "main.h"

void autonomous(){
  //sintake(1);
  //mov(10, 50);
  //sintake(0);
  //mov(10, -50);
  //turnn(-1, 50);
  //mov(5, 50);
  pros::lcd::print(0, "Autonomous");
  movement(3250, 60, 60);
  tturn(5, -1, 50);
}
