#include "pogobot.h"
#include "demo.h"
#include <stdint.h>

void pogobot_delay_ms(uint32_t ms) {
    time_reference_t timer;
    pogobot_stopwatch_reset(&timer);
    while (pogobot_stopwatch_get_elapsed_microseconds(&timer) / 1000 < ms) {
        // Wait
    }
}


uint16_t get_left_motor_power(void){
    uint16_t motorPowers[3] = {0, 0, 0}; // Array to store motor powers [R, L, B]
    // Attempt to recover motor power values from memory
    while (pogobot_motor_power_mem_get(motorPowers) != 0) {
        printf("Motor power values retrieved: Right = %d, Left = %d, Back = %d\n", motorPowers[0], motorPowers[1], motorPowers[2]);
    }
    return motorPowers[1];
}

uint16_t get_right_motor_power(void){
    uint16_t motorPowers[3] = {0, 0, 0}; // Array to store motor powers [R, L, B]
    // Attempt to recover motor power values from memory
    while (pogobot_motor_power_mem_get(motorPowers) != 0) {
        printf("Motor power values retrieved: Right = %d, Left = %d, Back = %d\n", motorPowers[0], motorPowers[1], motorPowers[2]);
    }
    return motorPowers[0];
}

void move_straight(void) {
    printf("Movement: Straight\n");
    uint16_t duration = 5000; // 5 s
    pogobot_led_setColor(255, 255, 255); // White
    uint16_t motorLeftPower = get_left_motor_power();
    uint16_t motorRightPower = get_right_motor_power();
    pogobot_motor_power_set(motorL, motorLeftPower);
    pogobot_motor_power_set(motorR, motorRightPower);
    pogobot_delay_ms(duration);
    pogobot_motor_power_set(motorL, 0);
    pogobot_motor_power_set(motorR, 0);
}

void move_light_left(void) {
    printf("Movement: Light Left\n");
    uint16_t duration = 5000; // 5 seconds
    pogobot_led_setColor(255, 180, 255); // Pale pink
    uint16_t motorLeftPower = get_left_motor_power();
    uint16_t motorRightPower = get_right_motor_power();
    pogobot_motor_power_set(motorL, motorLeftPower);
    pogobot_motor_power_set(motorR, (uint16_t) motorRightPower * 0.9);
    pogobot_delay_ms(duration);
    pogobot_motor_power_set(motorL, 0);
    pogobot_motor_power_set(motorR, 0);
}

void move_hard_left(void) {
    printf("Movement: Hard Left\n");
    uint16_t duration = 5000; // 5 seconds
    pogobot_led_setColor(153, 0, 153); // Dark purple
    uint16_t motorLeftPower = get_left_motor_power();
    uint16_t motorRightPower = get_right_motor_power();
    pogobot_motor_power_set(motorL, motorLeftPower);
    pogobot_motor_power_set(motorR, (uint16_t) motorRightPower * 0.75);
    pogobot_delay_ms(duration);
    pogobot_motor_power_set(motorL, 0);
    pogobot_motor_power_set(motorR, 0);
}

void move_straight_left(void) {
    printf("Movement: Straight Left\n");
    uint16_t duration = 5000; // 5 seconds
    pogobot_led_setColor(255, 0, 0); // Red
    uint16_t motorLeftPower = get_left_motor_power();
    pogobot_motor_power_set(motorL, motorLeftPower);
    pogobot_motor_power_set(motorR, 0); // Stop right motor
    pogobot_delay_ms(duration);
    pogobot_motor_power_set(motorL, 0);
    pogobot_motor_power_set(motorR, 0);
}

void move_light_right(void) {
    printf("Movement: Light Right\n");
    uint16_t duration = 5000; // 5 seconds
    pogobot_led_setColor(0, 255, 255); // Baby blue
    uint16_t motorLeftPower = get_left_motor_power();
    uint16_t motorRightPower = get_right_motor_power();
    pogobot_motor_power_set(motorL, (uint16_t) motorLeftPower * 0.9);
    pogobot_motor_power_set(motorR, motorRightPower);
    pogobot_delay_ms(duration);
    pogobot_motor_power_set(motorL, 0);
    pogobot_motor_power_set(motorR, 0);
}

void move_hard_right(void) {
    printf("Movement: Hard Right\n");
    uint16_t duration = 5000; // 5 seconds
    pogobot_led_setColor(0, 153, 153); // Dark baby blue
    uint16_t motorLeftPower = get_left_motor_power();
    uint16_t motorRightPower = get_right_motor_power();
    pogobot_motor_power_set(motorL, (uint16_t) motorLeftPower * 0.75);
    pogobot_motor_power_set(motorR, motorRightPower);
    pogobot_delay_ms(duration);
    pogobot_motor_power_set(motorL, 0);
    pogobot_motor_power_set(motorR, 0);
}

void move_straight_right(void) {
    printf("Movement: Straight Right\n");
    int duration = 5000; // 5 seconds
    pogobot_led_setColor(0, 0, 255); // Blue
    uint16_t motorRightPower = get_right_motor_power();
    pogobot_motor_power_set(motorL, 0); // Stop left motor
    pogobot_motor_power_set(motorR, motorRightPower);
    pogobot_delay_ms(duration);
    pogobot_motor_power_set(motorL, 0);
    pogobot_motor_power_set(motorR, 0);
}

void stop_robot(void) {
    printf("Movement: Stop\n");
    int duration = 5000; // 5 seconds
    pogobot_led_setColor(0, 255, 0); // Green
    pogobot_motor_power_set(motorL, 0);
    pogobot_motor_power_set(motorR, 0);
    pogobot_delay_ms(duration);
}

void demo(void) {
    while (1) {
        move_straight();
        msleep(500);
        move_light_left();
        msleep(500);
        move_hard_left();
        msleep(500);
        move_straight_left();
        msleep(500);
        move_light_right();
        msleep(500);
        move_hard_right();
        msleep(500);
        move_straight_right();
        msleep(500);
        stop_robot();       
        msleep(500);

    }
}
