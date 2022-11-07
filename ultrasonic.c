#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"

#include <util/delay.h>
#include "timer_interface.h"
#include "LCD_interface.h"
#include "ultrasonic.h"
#include <avr/interrupt.h>

volatile static u16 timer_OVF=0;

void Ultra_sonic_init(void)
{
	DIO_SetPinDir(Ultra_PORT,echo,INPUT);
	DIO_SetPinDir(Ultra_PORT,trig,OUTPUT);
	Timer2_Mode_Sel(normal);
	Timer2_Clk(no_clk);
	Timer2_Force_val(0);
	Timer2_Interrupt(overflow_INT,ON);

}


u16 Ultra_sonic_dist(void)//58.3us for 1cm ultrasonic
{
	Timer0_Interrupt(compare_INT,OFF);
	timer_OVF=0;
	u16 time;
	DIO_SetPinVal(Ultra_PORT,trig,HIGH);
	_delay_us(10);
	DIO_SetPinVal(Ultra_PORT,trig,LOW);

	while(!DIO_GetPinVal(Ultra_PORT,echo));
	Timer2_Clk(4);//pre 64
	while((DIO_GetPinVal(Ultra_PORT,echo)));


	time = Timer2_Read_val();//4us for every one
	Timer2_Clk(no_clk);
	Timer2_Force_val(0);

	time = time + (timer_OVF * 256);
	u16 dist= time / 15;

	Timer0_Interrupt(compare_INT,ON);
	return dist;

}

ISR(TIMER2_OVF_vect)
{
	timer_OVF++;
	if(timer_OVF==10)
		timer_OVF=9;
}
