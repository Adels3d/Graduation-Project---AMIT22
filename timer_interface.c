#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

#include "timer_interface.h"

#include <util/delay.h>

void Timer0_Mode_Sel(u8 mode)
{
	TCCR0_R = (mode)|(TCCR0_R & 0xb7);
}

void Timer2_Mode_Sel(u8 mode)
{
	TCCR2_R = (mode)|(TCCR2_R & 0xb7);
}



void Timer0_Clk(u8 value)
{
	TCCR0_R = (value)|(TCCR0_R & 0xf8);
}

void Timer2_Clk(u8 value)
{
	TCCR2_R = (value)|(TCCR2_R & 0xf8);
}




void Timer0_oc0_Mode_Sel(u8 mode)
{
	TCCR0_R = (mode)|(TCCR0_R & 0xcf);
}

void Timer2_oc2_Mode_Sel(u8 mode)
{
	TCCR2_R = (mode)|(TCCR2_R & 0xcf);
}




void Timer0_Write_Compare(u8 value)
{
	OCR0_R = value;
}

void Timer2_Write_Compare(u8 value)
{
	OCR2_R = value;
}




void Timer0_Interrupt(u8 interrupt_type,u8 state)
{
	MAKE_BIT(TIMSK_R,interrupt_type,state);
}

void Timer2_Interrupt(u8 interrupt_type,u8 state)
{
	MAKE_BIT(TIMSK_R,interrupt_type+6,state);
}



void Timer0_Force_val(u8 value)
{
	TCNT0_R=value;
}

void Timer2_Force_val(u8 value)
{
	TCNT2_R=value;
}


u8 Timer0_Read_val(void)
{
	return TCNT0_R;
}

u8 Timer2_Read_val(void)
{
	return TCNT2_R;
}



void Timer0_Interrupt_Flag_Reset(void)
{
		SET_BIT(TIFR_R,0);
		SET_BIT(TIFR_R,1);
}

void Timer2_Interrupt_Flag_Reset(void)
{
		SET_BIT(TIFR_R,6);
		SET_BIT(TIFR_R,7);
}
