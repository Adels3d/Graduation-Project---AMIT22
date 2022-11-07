#include "SERVO_INTERFACE.h"

void SERVO_init(){
	    DDRD |= (1<<PD5);	/* Make OC1A pin as output */
		TCNT1 = 0;		/* Set timer1 count zero */
		ICR1 = 4999;		/* Set TOP count for timer1 in ICR1 register */

		/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
		TCCR1A = (1<<WGM11)|(1<<COM1A1);
		TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
}

void SERVO_setAngle(s16 angle){
	//250 for -90, 375 for 0, and 500 for +90
	OCR1A= angle * 2.6111111 + 130;
	//OCR1A = angle;
}

