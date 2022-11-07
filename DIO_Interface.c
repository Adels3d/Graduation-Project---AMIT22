#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"


void DIO_SetPortDir(u8 portID ,u8 dir)
{
switch (portID)
{
	case PORTA :
		DDRA_REG=dir;
		break;
	case PORTB :
		DDRB_REG=dir;
		break;
	case PORTC :
		DDRC_REG=dir;
		break;
	case PORTD :
		DDRD_REG=dir;
		break;
	default :
		break;
}
}

void DIO_SetPortVal(u8 portID ,u8 val)
{
switch(portID)
{
	case PORTA :
		PORTA_REG=val;
		break;
	case PORTB :
		PORTB_REG=val;
		break;
	case PORTC :
		PORTC_REG=val;
		break;
	case PORTD :
		PORTD_REG=val;
		break;
	default :
		break;
}
}

u8 DIO_GetPortVal(u8 portID)
{
u8 val;
switch(portID)
{
	case PORTA :
		val=PINA_REG;
		break;
	case PORTB :
		val=PINB_REG;
		break;
	case PORTC :
		val=PINC_REG;
		break;
	case PORTD :
		val=PIND_REG;
		break;
	default : val=0;
		break;
}
return val;
}

u8 DIO_GetPortPrevVal(u8 portID)
{
u8 val;
switch(portID)
{
	case PORTA :
		val=PORTA_REG;
		break;
	case PORTB :
		val=PORTB_REG;
		break;
	case PORTC :
		val=PORTC_REG;
		break;
	case PORTD :
		val=PORTD_REG;
		break;
	default : val=0;
		break;
}
return val;
}


void DIO_SetPinDir(u8 portID ,u8 pinID  ,u8 dir)
{
switch (portID)
{
	case PORTA :
		if(dir==1)
			{
			SET_BIT(DDRA_REG,pinID);
			}
		else
			{
			CLR_BIT(DDRA_REG,pinID);
			}
		break;
	case PORTB :
		if(dir==1)
			{
			SET_BIT(DDRB_REG,pinID);
			}
		else
			{
			CLR_BIT(DDRB_REG,pinID);
			}
		break;
	case PORTC :
		if(dir==1)
			{
			SET_BIT(DDRC_REG,pinID);
			}
		else
			{
			CLR_BIT(DDRC_REG,pinID);
			}
		break;
	case PORTD :
		if(dir==1)
			{
			SET_BIT(DDRD_REG,pinID);
			}
		else
			{
			CLR_BIT(DDRD_REG,pinID);
			}
		break;
	default :
		break;
}
}

void DIO_SetPinVal(u8 portID ,u8 pinID ,u8 val)
{
switch (portID)
{
	case PORTA :
		if(val==1)
			{
			SET_BIT(PORTA_REG,pinID);
			}
		else
			{
			CLR_BIT(PORTA_REG,pinID);
			}
		break;
	case PORTB :
		if(val==1)
			{
			SET_BIT(PORTB_REG,pinID);
			}
		else
			{
			CLR_BIT(PORTB_REG,pinID);
			}
		break;
	case PORTC :
		if(val==1)
			{
			SET_BIT(PORTC_REG,pinID);
			}
		else
			{
			CLR_BIT(PORTC_REG,pinID);
			}
		break;
	case PORTD :
		if(val==1)
			{
			SET_BIT(PORTD_REG,pinID);
			}
		else
			{
			CLR_BIT(PORTD_REG,pinID);
			}
		break;
	default :
		break;
}
}

u8 DIO_GetPinVal(u8 portID ,u8 pinID)
{
u8 val;
switch(portID)
{
	case PORTA :
		val=GET_BIT(PINA_REG,pinID);
		break;
	case PORTB :
		val=GET_BIT(PINB_REG,pinID);
		break;
	case PORTC :
		val=GET_BIT(PINC_REG,pinID);
		break;
	case PORTD :
		val=GET_BIT(PIND_REG,pinID);
		break;
	default :val=0;
		break;
}
return val;
}

u8 DIO_GetPinPrevVal(u8 portID ,u8 pinID)
{
u8 val;
switch(portID)
{
	case PORTA :
		val=GET_BIT(PORTA_REG,pinID);
		break;
	case PORTB :
		val=GET_BIT(PORTB_REG,pinID);
		break;
	case PORTC :
		val=GET_BIT(PORTC_REG,pinID);
		break;
	case PORTD :
		val=GET_BIT(PORTD_REG,pinID);
		break;
	default :val=0;
		break;
}
return val;
}

