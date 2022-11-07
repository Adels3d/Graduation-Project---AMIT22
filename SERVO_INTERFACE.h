/*
 * SERVO_INTERFACE.h
 *
 *  Created on: Nov 3, 2022
 *      Author: HP
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

//#define F_CPU 8000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include "STD_TYPES.h"
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */

void SERVO_init();
void SERVO_setAngle(s16 angle); 	//250 for -90, 375 for 0, and 500 for +90

#endif /* SERVO_INTERFACE_H_ */
