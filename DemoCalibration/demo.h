#include <stdint.h>
#include "pogobot.h"

// Function declarations for robot movements
void move_straight(void);
void move_light_left(void);
void move_hard_left(void);
void move_straight_left(void);
void move_light_right(void);
void move_hard_right(void);
void move_straight_right(void);
void stop_robot(void);
uint16_t get_left_motor_power(void);
uint16_t get_right_motor_power(void);
void pogobot_delay_ms(uint32_t ms);
// Main demo function to execute the movements
void demo(void);
