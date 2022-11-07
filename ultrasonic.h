#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
 /* ULTRASONIC_H_ */

#define echo PIN6
#define trig PIN7
#define Ultra_PORT PORTB_IO

void Ultra_sonic_init(void);
u16 Ultra_sonic_dist(void);
#endif
