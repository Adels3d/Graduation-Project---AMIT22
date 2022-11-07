#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TCCR0_R REG(0x53)
#define OCR0_R REG(0x5c)
#define TCNT0_R REG(0x52)
#define TIMSK_R REG(0x59)
#define TIFR_R REG(0x58)

#define TCCR2_R REG(0x45)
#define OCR2_R REG(0x43)
#define TCNT2_R REG(0x44)
#define ASSR_R REG(0x42)

#define normal 0
#define phase_correct 64
#define compare 8
#define pwm 72
void Timer0_Mode_Sel(u8 mode);
void Timer2_Mode_Sel(u8 mode);


#define no_clk 0
#define no_prescaler 1
#define prescaler_8 2
#define prescaler_64 3
#define prescaler_256 4
#define prescaler_1024 5
#define T0_Fall_Edge 6
#define T0_Rise_Edge 7
void Timer0_Clk(u8 value);
void Timer2_Clk(u8 value);

#define mode0 0
#define mode1 16
#define mode2 32
#define mode3 48
void Timer0_oc0_Mode_Sel(u8 mode);
void Timer2_oc1_Mode_Sel(u8 mode);


void Timer0_Write_Compare(u8 value);
void Timer2_Write_Compare(u8 value);


void Timer0_Force_val(u8 value);
void Timer2_Force_val(u8 value);

u8 Timer0_Read_val(void);
u8 Timer2_Read_val(void);

#define OFF 0
#define ON 1
#define overflow_INT 0
#define compare_INT 1
void Timer0_Interrupt(u8 interrupt_type,u8 state);
void Timer2_Interrupt(u8 interrupt_type,u8 state);


void Timer0_Interrupt_Flag_Reset(void);
void Timer2_Interrupt_Flag_Reset(void);


/*
ISR(TIMER0_OVF_vect)
{

}
ISR(TIMER0_COMP_vect)
{

}

ISR(TIMER2_OVF_vect)
{

}
ISR(TIMER2_COMP_vect)
{

}
*/
#endif /* TIMER_INTERFACE_H_ */
