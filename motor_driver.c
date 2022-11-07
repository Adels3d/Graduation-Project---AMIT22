#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"

#include <util/delay.h>
#include "motor_driver.h"
#include "motor_driver_config.h"
#include <avr/interrupt.h>
#include "timer_interface.h"


volatile static u8 motor_pwm=0;

volatile static u8 motor_1=0;
volatile static u8 motor_2=0;
volatile static u8 motor_3=0;
volatile static u8 motor_4=0;


void motor_init(void)
{
	DIO_SetPinDir(Motor_control_PORT,motor_1E,OUTPUT);
	DIO_SetPinDir(Motor_PORT,motor_1R,OUTPUT);
	DIO_SetPinDir(Motor_PORT,motor_1L,OUTPUT);

	DIO_SetPinDir(Motor_control_PORT,motor_2E,OUTPUT);
	DIO_SetPinDir(Motor_PORT,motor_2R,OUTPUT);
	DIO_SetPinDir(Motor_PORT,motor_2L,OUTPUT);

	DIO_SetPinDir(Motor_control_PORT,motor_3E,OUTPUT);
	DIO_SetPinDir(Motor_PORT,motor_3R,OUTPUT);
	DIO_SetPinDir(Motor_PORT,motor_3L,OUTPUT);

	DIO_SetPinDir(Motor_control_PORT,motor_4E,OUTPUT);
	DIO_SetPinDir(Motor_PORT,motor_4R,OUTPUT);
	DIO_SetPinDir(Motor_PORT,motor_4L,OUTPUT);

	Timer0_Mode_Sel(compare);
	Timer0_Write_Compare(pwm_frequency);
	Timer0_Interrupt(compare_INT,ON);
	Timer0_Clk(prescaler_64);
}
ISR(TIMER0_COMP_vect)
{

	if(motor_1>motor_pwm)//motor 1
	{
		DIO_SetPinVal(Motor_control_PORT,motor_1E,HIGH);
	}
	else
	{
		DIO_SetPinVal(Motor_control_PORT,motor_1E,LOW);
	}

	if(motor_2>motor_pwm)//motor 2
	{
		DIO_SetPinVal(Motor_control_PORT,motor_2E,HIGH);
	}
	else
	{
		DIO_SetPinVal(Motor_control_PORT,motor_2E,LOW);
	}

	if(motor_3>motor_pwm)//motor 3
	{
		DIO_SetPinVal(Motor_control_PORT,motor_3E,HIGH);
	}
	else
	{
		DIO_SetPinVal(Motor_control_PORT,motor_3E,LOW);
	}

	if(motor_4>motor_pwm)//motor 4
	{
		DIO_SetPinVal(Motor_control_PORT,motor_4E,HIGH);
	}
	else
	{
		DIO_SetPinVal(Motor_control_PORT,motor_4E,LOW);
	}
	motor_pwm++;
//	#if MOTORSPEED_ON==1
	if(motor_pwm==MAX_SPEED)
		motor_pwm=0;
//	#endif
}

void motor_speed(u8 motor_1S ,u8 motor_2S ,u8 motor_3S, u8 motor_4S)
{
	motor_1 = motor_1S;
	motor_2 = motor_2S;
	motor_3 = motor_3S;
	motor_4 = motor_4S;
}

void motor_dir(u8 motor_1D, u8 motor_2D, u8 motor_3D, u8 motor_4D)
{
	DIO_SetPortVal(Motor_PORT,LOW);

	DIO_SetPinVal(Motor_PORT,motor_1R,motor_1D);//motor 1
	DIO_SetPinVal(Motor_PORT,motor_1L,motor_1D^1);

	DIO_SetPinVal(Motor_PORT,motor_2R,motor_2D);//motor 2
	DIO_SetPinVal(Motor_PORT,motor_2L,motor_2D^1);

	DIO_SetPinVal(Motor_PORT,motor_3R,motor_3D);//motor 3
	DIO_SetPinVal(Motor_PORT,motor_3L,motor_3D^1);

	DIO_SetPinVal(Motor_PORT,motor_4R,motor_4D);//motor 4
	DIO_SetPinVal(Motor_PORT,motor_4L,motor_4D^1);
}

