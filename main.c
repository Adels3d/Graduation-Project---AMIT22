#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"

#include <util/delay.h>
#include "motor_driver.h"
#include "motor_driver_config.h"
#include "ultrasonic.h"
#include "LCD_interface.h"
#include "SERVO_INTERFACE.h"

//#define SREG REG(0x5f)

enum state { stop, go , right_turn, left_turn, reverse};
enum state car= stop;
u16 distance=0;
s16 angle=90;
u8 scan_no=0;
u8 flag=0; //when car = stop
u8 flag_right=0; //when car= right turn
u8 flag_left=0;  //whem car= left turn

void car_GO(){
	motor_dir(FORWARD,FORWARD,FORWARD,FORWARD);
	motor_speed(20,20,20,12); //motors move in a straight paths
}
void car_RIGHT_TURN(){
	motor_dir(FORWARD,FORWARD,BACKWARD,BACKWARD);
	motor_speed(35,35,35,35);
}
void car_LEFT_TURN(){
	motor_dir(BACKWARD,BACKWARD,FORWARD,FORWARD);
	motor_speed(35,35,35,35);
}
enum state car_STOP(){
	enum state decision= stop;
	flag=1;
	scan_no++;
	motor_speed(0,0,0,0); //stop all motors

	u8 dist_right,dist_left;

	SERVO_setAngle(180);
	_delay_ms(500);
	dist_left= Ultra_sonic_dist();

	SERVO_setAngle(0);
	_delay_ms(500);
	dist_right= Ultra_sonic_dist(); //in cm

	if(dist_left > dist_right && dist_left > 20){
		decision= left_turn;
		flag_left=1;
		SERVO_setAngle(90);
		_delay_ms(300);
		return decision;
	}
	else;


	if(dist_right > dist_left && dist_right > 20){
		decision= right_turn;
		flag_right=1;
		SERVO_setAngle(90);
		_delay_ms(300);
		return decision;
	}
	else;

	if(scan_no ==4 ) decision= reverse;
	else;

	SERVO_setAngle(90);
	_delay_ms(300);
	return decision;
}

void car_REVERSE(){
	motor_dir(BACKWARD,BACKWARD,BACKWARD,BACKWARD);
	motor_speed(20,20,20,12);
}

int main()
{
	SREG |=0x80;
	/*----------------ULTRA SONIC------------------*/
	Ultra_sonic_init();
	/*----------------SERVO------------------------*/
	SERVO_init();
	/*-----------------LCD-----------------*/
	Lcd_Init();
	Lcd_Cmd(Display_Control(Dis_On,Cursor_Off,Cursor_Static),insr);
	/*-----------------MOTORS-----------------*/
	motor_init();
	motor_dir(FORWARD,FORWARD,FORWARD,FORWARD);
	motor_speed(0,0,0,0);

	DIO_SetPinVal(PORTA_IO,PIN3,LOW);

while(1)
{
//	DIO_SetPinVal(PORTA_IO,PIN3,LOW);
	distance= Ultra_sonic_dist(); //in cm
	Lcd_Cmd(DDRAM_Address(1,1),insr);
	Lcd_Print_num(distance);
	Lcd_Cmd(DDRAM_Address(4,2),insr);
	if(distance <= 20 && flag == 0 && flag_right ==0 && flag_left == 0) car= stop;
	else;
	switch(car){
		case go:
			car_GO();
			Lcd_Print("Forward");
			break;

		case stop:
			car= car_STOP();
			Lcd_Print("Stop");
			break;

		case right_turn:
			car_RIGHT_TURN();
			_delay_ms(1300);
			flag_right=0;
			Lcd_Print("Right  ");
			break;

		case left_turn:
			car_LEFT_TURN();
			_delay_ms(1300);
			flag_left=0;
			Lcd_Print("Left   ");
			break;

		case reverse:
			car_REVERSE();
			scan_no=0;
			Lcd_Print("Reverse");
			break;
	}
	if(distance > 25 && flag_right ==0 && flag_left == 0 ) {
		flag=0;
		car= go;
	}

	_delay_ms(50);
}
}
