
# [Projet P-ANDROIDE - M2/S1 - 2024 - Partie calibration de moteur automatique du Pogobot]



## Pogobot Demo 

This folder contains functions used to demonstrate a calibrated robot. The demonstration includes various movement behaviors, each associated with a specific LED color.

**Functions:**

```C
void pogobot_delay_ms(uint32_t ms);
```

Function that allows a delay during the demonstration code.

```C
uint16_t get_left_motor_power(void);```

Function that retrieves the loaded left motor value from the Pogobot's memory.

```C
uint16_t get_right_motor_power(void);```

Function that retrieves the loaded right motor value from the Pogobot's memory.

```C
void move_straight(void);```

Function that makes the robot move straight for 5 seconds by using its loaded motor values.
- **LED Color:** White.

```C
void move_light_left(void);```

Function that makes the robot turn slightly to the left for 5 seconds.  
- **LED Color:** Pale pink.  
- **Behavior:** Reduces the right motor's power to X% while keeping the left motor at full power.

```C
void move_hard_left(void);```

Function that makes the robot turn sharply to the left for 5 seconds.  
- **LED Color:** Dark purple.  
- **Behavior:** Reduces the right motor's power to X% while keeping the left motor at full power.


```C
void move_straight_left(void);```

Function that makes the robot turn left by stopping the right motor for 5 seconds.  
- **LED Color:** Red.  
- **Behavior:** Keeps the left motor running at full power and stops the right motor.

```C
void move_light_right(void);```

Function that makes the robot turn slightly to the right for 5 seconds.  
- **LED Color:** Baby blue.  
- **Behavior:** Reduces the left motor's power to X% while keeping the right motor at full power.

```C
void move_hard_right(void);```

Function that makes the robot turn sharply to the right for 5 seconds.  
- **LED Color:** Dark baby blue.  
- **Behavior:** Reduces the left motor's power to X% while keeping the right motor at full power.

```C
void move_straight_right(void);```

Function that makes the robot turn right by stopping the left motor for 5 seconds.  
- **LED Color:** Blue.  
- **Behavior:** Keeps the right motor running at full power and stops the left motor.

```C
void stop_robot(void);```

Function that stops the robot for 5 seconds.  
- **LED Color:** Green.  
- **Behavior:** Both motors are stopped during the duration.

```C
void demo(void);```

Function that runs a continuous demonstration loop of the robot's different movement behaviors.  
- **Sequence:**  
  1. Moves straight.  
  2. Turns slightly left.  
  3. Turns sharply left.  
  4. Turns left by stopping the right motor.  
  5. Turns slightly right.  
  6. Turns sharply right.  
  7. Turns right by stopping the left motor.  
  8. Stops the robot.  
- **Timing:** A 500 ms delay is introduced between each behavior.





  
