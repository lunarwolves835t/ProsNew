#include "main.h"

void opcontrol() {

  while (true) {

    if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      checkMecanum();

      checkRelease();
      //setDriveMotors();
      setIntake();
      setArm();
      setTray();
      moonwalk();
      checkBindings();
    }
    else{
      //deploy()
      // pros::delay(1000);
      deployNine();

      /* CODE THAT WORKS
      movement(3600, 60, 50, true); // 70, 60
      movement(968, -60, -50, true);
      movement(1450, -60, -50, false); //1700 for other
      movement(968, 60, -50, false);
      */

      /* DO NOT UNCOMMENT
      movement(645, 60, -50, false);
      pros::delay(200);
      driveMecanum(127, 0, -40);
      pros::delay(1000);
      driveMecanum(0, 0, 0);
      killSwitch();
      */

      /* CODE THAT WORKS
      movement(700, 60, 50, false);
      pros::delay(500);
      deploy();
      */
    }



    pros::delay(10);
  }
}
