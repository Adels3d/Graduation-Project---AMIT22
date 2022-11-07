#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Register.h"
#include "DIO_Interface.h"
#include <util/delay.h>

#include "LCD_interface.h"

void Lcd_Init(void){
u8 i;
for(i=4; i<=7; i++){//Set data pin to LOW first then OUTPUT
	DIO_SetPinVal(PORTA_IO,i,LOW);
	DIO_SetPinDir(PORTA_IO,i,OUTPUT);
}
	DIO_SetPinVal(PORTB_IO,rs,LOW);
	DIO_SetPinDir(PORTB_IO,rs,OUTPUT);
	DIO_SetPinVal(PORTB_IO,enable,LOW);
	DIO_SetPinDir(PORTB_IO,enable,OUTPUT);
	DIO_SetPinVal(PORTB_IO,rw,LOW);
	DIO_SetPinDir(PORTB_IO,rw,OUTPUT);

_delay_ms(16);//Delay at startup for lcd to be ready
//Initial command should send three times
DIO_SetPinVal(PORTB_IO,rw,LOW);//Read data (ignored when rs LOW)
DIO_SetPinVal(PORTB_IO,rs,LOW);//Read as command
DIO_SetPinVal(PORTB_IO,enable,HIGH);//Enable rise to read control pins

DIO_SetPinVal(PORTA_IO,bit0,HIGH);//Write 0x3 to lcd
DIO_SetPinVal(PORTA_IO,bit1,HIGH);
DIO_SetPinVal(PORTA_IO,bit2,LOW);
DIO_SetPinVal(PORTA_IO,bit3,LOW);
_delay_us(0.23);//Delay between rise and fall of enable pin

DIO_SetPinVal(PORTB_IO,enable,LOW);//Enable fall to read data pins

_delay_ms(4.2);//Delay between first and second initial command

DIO_SetPinVal(PORTB_IO,enable,HIGH);//Second time
_delay_us(0.23);//Delay between rise and fall of enable pin
DIO_SetPinVal(PORTB_IO,enable,LOW);

_delay_us(110);//Delay between second and third initial command

DIO_SetPinVal(PORTB_IO,enable,HIGH);//Third time
_delay_us(0.23);//Delay between rise and fall of enable pin
DIO_SetPinVal(PORTB_IO,enable,LOW);
_delay_us(0.5);//Delay between two rise time of enable pin

DIO_SetPinVal(PORTB_IO,enable,HIGH);//4 bit mode command
DIO_SetPinVal(PORTA_IO,bit0,LOW);//Write 0x2 to lcd
_delay_us(0.23);//Delay between rise and fall of enable pin
DIO_SetPinVal(PORTB_IO,enable,LOW);
_delay_us(0.5);//Delay between two rise time of enable pin

Lcd_Cmd(0x28,insr);//Function set command (4 bit mode / 2 line lcd / 5x8 character
Lcd_Cmd(0x08,insr);//Display off command
Lcd_Cmd(0x01,insr);//Display clear
Lcd_Cmd(0x06,insr);//Entry mode set
while(Lcd_Busy());
}



void Lcd_Cmd(u8 data_r, u8 data_type){
while(Lcd_Busy());
for(u8 i=0; i<=1; i++)//Write MSB first then LSB
{
	DIO_SetPinVal(PORTB_IO,rs,data_type);//First bit tell is insr or data
	DIO_SetPinVal(PORTB_IO,rw,LOW);//We only read busy flag which have its function
	DIO_SetPinVal(PORTB_IO,enable,HIGH);//Enable rise to read control pins
	DIO_SetPortVal(PORTA_IO,(((DIO_GetPortPrevVal(PORTA_IO))&(0x0f))|((data_r)&(0xf0))));
	//Write higher 4 bits of data_r to higher bit of port without change lower bits
	data_r=data_r<<4;
	_delay_us(0.23);//Delay between rise and fall of enable pin
	DIO_SetPinVal(PORTB_IO,enable,LOW);//Enable fall to read data pins
	_delay_us(0.5);//Delay between two rise time of enable pin
}
}


u8 Lcd_Busy(void){
for(u8 i=4; i<=7; i++)//Set data pin to LOW first then INPUT to read busy flag
{
	DIO_SetPinVal(PORTA_IO,i,LOW);
	DIO_SetPinDir(PORTA_IO,i,INPUT);
}
u8 busy_r;//Variable to save flag value in it

DIO_SetPinVal(PORTB_IO,rs,LOW);//the next operation is insr
DIO_SetPinVal(PORTB_IO,rw,HIGH);//Read the busy flag

DIO_SetPinVal(PORTB_IO,enable,HIGH);//Enable rise to read control pins
_delay_us(0.23);//Delay between rise and fall of enable pin
busy_r = DIO_GetPinVal(PORTA_IO,bit3);//Read busy flag
DIO_SetPinVal(PORTB_IO,enable,LOW);//Enable fall to read data pins
_delay_us(0.5);//Delay between two rise time of enable pin

DIO_SetPinVal(PORTB_IO,enable,HIGH);//Rise enable again to make lcd write last 4 bit even if we don't need them
_delay_us(0.23);//Delay between rise and fall of enable pin
DIO_SetPinVal(PORTB_IO,enable,LOW);//Enable fall to read data pins
_delay_us(0.5);//Delay between two rise time of enable pin

for(u8 i=4; i<=7; i++)//Set data pin output to continue normal operation
{
	DIO_SetPinDir(PORTA_IO,i,OUTPUT);//Data pins are already low from last for loop
}

return busy_r;
}


void Lcd_Print(u8 *string){
u8 i=0;
do
{
	Lcd_Cmd(string[i],data);
	i++;
}while(string [i]!='\0');
}

void CG_Char_Write(u8 *CG_Char, u8 Char_Num){
Lcd_Cmd(CGRAM_Address(Char_Num,0),insr);
for(u8 i=0; i<=7; i++)
{
	Lcd_Cmd(CG_Char[i],data);
}
}

void Lcd_Print_num(u16 num)
{
	if(num==0)
		Lcd_Cmd('0',data);
	else
	{
		u8 print[5];
		u8 i=4;
		u8 space;
		while(num!=0){
			print[i]=num%10;
			print[i]+=48;
			num/=10;
			i--;
		}
		i++;
		space=i;
		for( ; i<=4 ; i++){
			Lcd_Cmd(print[i],data);
		}
		Lcd_Print("cm");
		if(space>2)
		{
			space-=2;
			for(; space>=1; space--)
			{
				Lcd_Cmd(' ',data);
			}
		}
	}

}


