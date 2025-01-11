
# [Projet P-ANDROIDE - M2/S1 - 2024 - Partie calibration de moteur automatique du Pogobot]



## Pogobot Calibration 

Functions used to calibrate the Pogobot: find the correct motor values (between 0 and 1023) which make the robot move forward without turning. Keep in mind that Pogobots are very sensitive to environmental perturbations. Dust, an uneven ground and older toothbrushes can affect the trajectory of a robot.<br />
To calibrate the robot, we turn on the motor for a short time, check if the robot turned left or right, ajust the values of the motors accordingly and repeat a few times.

**Functions:**

```C
void pogobot_quick_calibrate(int power, int* leftMotorVal, int* rightMotorVal);
```
>Call this function to calibrate the motors of the Pogobot at roughly ***power***. The value of ***power*** has to be between 0 and 1023. However, the lower the value, the less precise the calibration will be. Keeping ***power*** between 524 and 716 is a good idea.<br />
>The values are returned as integers through ***leftMotorVal*** and ***rightMotorVal***.

```C
void pogobot_calibrate(int power, int startup_duration, int try_duration, int number_of_tries, float correction, int* leftMotorVal, int* rightMotorVal);
```
>Same function as before, but gives more control to the user over its parameters.<br />
>Call this function to calibrate the motors of the Pogobot at roughly ***power***. During each try, the motors are turned on for ***startup_duration***ms before we actually collect IMU data. Then IMU data is collected during ***try_duration***ms. The experience is repeated ***number_of_tries*** times. Each time, robot_rotation****correction*** is applied to one of the motors. <br />
>In ***pogo_quick_calibrate()***, ***startup_duration*** = 500 ; ***try_duration*** = 750 ; ***number_of_tries*** = 15 and ***correction*** = 50.0f.<br />
>Be careful, if your pogobot is mounted backward, you might need to assign a negative value to ***correction***. 

## Pogobot Demo