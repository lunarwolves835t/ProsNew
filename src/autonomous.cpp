#include "main.h"

void autonomous(){
  //sintake(1);
  //mov(10, 50);
  //sintake(0);
  //mov(10, -50);
  //turnn(-1, 50);
  //mov(5, 50);

  release();

  pros::delay(200);

  //redProtected();

  movement(1000, 60, 60);
  movement(-1000, 60, 60);
  //tturn(500, -1, 2.5);
}

void redProtected() {
  movement(2900, 60, 60);
}

void redNonProtected() {
  //forwards
  //left
  //forward
  //reverse
  //do a 180
  //forwards, then deploy
  movement(2900, 60, 60);

  movement(300, -30, 30);

  movement(300, 60, 60);

  movement(1000, -50, -50);

  movement(600, -40, 40);

  movement(400, 30, 30);

  deploy();
}
