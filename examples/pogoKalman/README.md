
# [IAR Project, M2 ANDROIDE - M2/S1 - 2024 - Automatic motor calibration algorithm using an extended Kalman filter]


## Pogobot Motor Calibration 

Functions used to calibrate the Pogobot aim to determine the optimal motor values (ranging from 0 to 1023) that enable the robot to move as straight as possible without turning. It is important to note that Pogobots are highly sensitive to environmental factors. Dust, uneven terrain, or a loosely attached exoskeleton can significantly impact the robot's trajectory.

The calibration process involves activating the motors for a short duration, observing whether the robot veers to the left or right, adjusting the motor values accordingly, and repeating this process several times to refine the calibration.

**Functions:**

```C
void pogobot_quick_calibrate(int power, int* leftMotorVal, int* rightMotorVal);
```
Call this function to calibrate the motors of the Pogobot at approximately **power**. The value of **power** must be between 0 and 1023. However, the closer the value is to the extremes (0 or 1023), the less precise the calibration will be. Keeping **power** between 500 and 800 is recommended.

The calibrated motor values are returned as integers through **leftMotorVal** and **rightMotorVal**.

```C
void pogobot_calibrate(int power, int startup_duration, int try_duration, int number_of_tries, float correction, int method, int* leftMotorVal, int* rightMotorVal);
```
>Same function as before, but gives more control to the user over its parameters.<br />
>Call this function to calibrate the motors of the Pogobot at roughly ***power***. During each try, the motors are turned on for ***startup_duration***ms before we actually collect IMU data. Then IMU data is collected during ***try_duration***ms. The experience is repeated ***number_of_tries*** times.
>This code uses 4 different methods of calibration that can be selected using the **method** parameter.
>
Method 0: Gyroscope-Based Calibration  
Uses Z-axis gyroscope data to detect and correct veering.  
Adjusts motor power based on angular velocity. 

Method 1: Gyroscope Calibration with Noise Filtering  
Introduces an epsilon threshold to ignore minor noise.  
Stops calibration after consecutive near-zero readings.

Method 2: Proportional Gyroscope Adjustment  
Applies a correction factor to scale motor adjustments.  
Smoothly compensates for larger deviations.

Method 3: Accelerometer-Based Calibration  
Uses Y-axis accelerometer data to detect drift.  
Limited reliability due to high accelerometer noise.   

## Kalman filter implementation in C

The Kalman filter is executable at runtime. It is used to reduce the noise from the IMU. In particular, the z axis of the gyroscope (horizontal rotation) can be used to determine if the pogobot is turning. It is used in pogobot_calibrate() but can be used elsewhere.

**Functions:**

```C
void extendedKalmanFilter(
    float z_k_observation_vector[][C],        // [1][6] 6x1
    float state_estimate_k_minus_1[][C],      // [1][6] 6x1
    float P_k_minus_1[][C],                   // [6][6] 6x6
    float A_k_minus_1[][C],                   // [6][6] 6x6
    float process_noise_v_k_minus_1[][C],     // [1][6] 6x1
    float Q_k[][C],                           // [6][6] 6x6
    float R_k[][C],                           // [6][6] 6x6
    float H_k[][C],                           // [6][6] 6x6
    float sensor_noise_w_k[][C],              // [1][6] 6x1
    // returns:
    float state_estimate_k[][C],              // [1][6] 6x1
    float P_k[][C]                            // [6][6] 6x6
    );
```
>Function to filter out noisy data (makes a prediction from the previous iteration then correct it with the new data). z_k_observation_vector should be the data read by the IMU : {acc[0], acc[1], acc[2], gyro[0], gyro[1], gyro[2]}. <br />
>The results are stored in state_estimate_k and P_k. At the next iteration, you should assign their values to P_k_minus_1 and state_estimate_k_minus_1. The other parameters don't need to be changed (initialize once then forget about them).

```C
void initExtendedKalmanFilter(
    int power,
    float state_estimate_k_minus_1[][C],      // [1][6] 6x1
    float P_k_minus_1[][C],                   // [6][6] 6x6
    float A_k_minus_1[][C],                   // [6][6] 6x6
    float process_noise_v_k_minus_1[][C],     // [1][6] 6x1
    float Q_k[][C],                           // [6][6] 6x6
    float R_k[][C],                           // [6][6] 6x6
    float H_k[][C],                           // [6][6] 6x6
    float sensor_noise_w_k[][C]               // [1][6] 6x1
    );
```
>Declare arrays and pass them as arguments of this function to initialize them, after which you can pass them as the corresponding parameters of extendedKalmanFilter().



## Debug, display and convenient functions

Useful functions, linked to the calibration of the pogobots or with a more general purpose.

**Functions:**

```C
void print_float(float i, int precision);
```
>Print a float to the console, because printf("%f", myFloat); doesn't work on pogobots. They're too cool for that.<br />
>Example: printf("one point two = "); print_float(1.22f, 10); printf("\n"); <br />
>Result: "one point two = 1.2\n"

```C
void print_kalman(int i, float state_estimate_k[][6], float acc[], float gyro[3]);
```
>Print to the console the IMU values with and without the Kalman filter. The parameter ***i*** is the current time in milliseconds.

```C
void pogobot_motor_jump_set(int power, int motor);
```
>Safely initiate motor value (short jumpstart if ***value*** is under 512).

```C
void combine_arrays(float res[], float arr1[], float arr2[], int len1, int len2);
```
>Combine arr1[len1] and arr2[len2] into res[len1+len2] (res = arr1 + arr2 in python)

```C
void split_array(float base[], float arr1[], float arr2[], int len1, int len2);
```
>Split base[len1+len2] into arr1[len1] and arr2[len2] by putting the len1 first elements into arr1 and len1+1 to len1+len2 into arr2

```C
void set_all_leds(int r, int g, int b);
```
>Set all of the pogobot's leds to the same color.

```C
void anim_same(void);
```
>Pretty animation.

```C
void anim_blink(int r, int g, int b, int number_of_blinks);
```
>All leds blinks ***number_of_blinks*** times. 

```C
void print_f_list(float* list, int len, int precision);
```
>Print an array of floats to the console with \t in between each element. There is no \n.


