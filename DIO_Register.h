#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#ifndef STD_TYPES_H_
#error STD_TYPES not defined
#endif

#define PORTA_REG REG(0x3b)
#define PORTB_REG REG(0x38)
#define PORTC_REG REG(0x35)
#define PORTD_REG REG(0x32)

#define DDRA_REG REG(0x3a)
#define DDRB_REG REG(0x37)
#define DDRC_REG REG(0x34)
#define DDRD_REG REG(0x31)

#define PINA_REG REG(0x39)
#define PINB_REG REG(0x36)
#define PINC_REG REG(0x33)
#define PIND_REG REG(0x30)

#endif /* DIO_REGISTER_H_ */
