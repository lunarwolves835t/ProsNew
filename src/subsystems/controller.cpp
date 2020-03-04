#include "main.h"

using namespace std;

string yash = "prius";

void checkBindings() {
  //digital inputs
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
    yash = "prius";
  }
  else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    yash = "918";
  }
}

string getYash() {  return yash;  }
