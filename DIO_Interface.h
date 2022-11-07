#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define LOW 0
#define HIGH 1
#define PORT_LOW 0x00
#define PORT_HIGH 0xff

#define INPUT 0
#define OUTPUT 1

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PORTA_IO 0
#define PORTB_IO 1
#define PORTC_IO 2
#define PORTD_IO 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

void DIO_SetPortDir(u8 portID ,u8 dir);
void DIO_SetPortVal(u8 portID ,u8 val);
u8 DIO_GetPortVal(u8 portID);
u8 DIO_GetPortPrevVal(u8 portID);

void DIO_SetPinDir(u8 portID ,u8 pinID ,u8 dir);
void DIO_SetPinVal(u8 portD ,u8 pinID ,u8 val);
u8 DIO_GetPinVal(u8 portID ,u8 pinID);
u8 DIO_GetPinPrevVal(u8 portID ,u8 pinID);

#endif /* DIO_INTERFACE_H_ */
