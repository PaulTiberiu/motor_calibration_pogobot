
#include "pogobot.h"
#include "kalman.h"
#include "display.h"

int main(int argc, char* argv[]) {
    pogobot_init();
    printf("init ok\n");
    anim_same();

    int leftMotorVal;
    int rightMotorVal;

    pogobot_quick_calibrate(650, &leftMotorVal, &rightMotorVal);
    printf("Calibration ok : powerLeft = %d ; powerRight = %d\n", leftMotorVal, rightMotorVal);

    int16_t motorPowers[3] = {rightMotorVal, leftMotorVal, 0};
    if (pogobot_motor_power_mem_set(motorPowers) == 0) {
        printf("Motor powers saved to memory.\n");
    } else {
        printf("Failed to save motor powers.\n");
    }

    pogobot_motor_jump_set(motorL, leftMotorVal);
    pogobot_motor_jump_set(motorR, rightMotorVal); 

    anim_same();
    
    return 1;
}
