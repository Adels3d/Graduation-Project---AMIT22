#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

#define pwm_frequency 128//from 0 to 255

void motor_init(void);
void motor_speed(u8 motor_1S, u8 motor_2S, u8 motor_3S, u8 motor_4S);

#define FORWARD 1
#define BACKWARD 0
#define MAXSPEED_ON 1
#define MAX_SPEED 50
void motor_dir(u8 motor_1D, u8 motor_2D, u8 motor_3D, u8 motor_4D);

#endif /* MOTOR_DRIVER_H_ */
