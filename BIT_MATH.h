#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BITNO)  (REG) |= (1 << (BITNO))
#define CLR_BIT(REG, BITNO)  (REG) &= (~(1 << (BITNO)))
#define TOG_BIT(REG, BITNO)  (REG) ^= (1 << (BITNO))
#define GET_BIT(REG, BITNO)  (((REG) >> (BITNO)) & 1)

#define MAKE_BIT(REG, BITNO, VAL)	(REG) ^= ((VAL^ (((REG) >> (BITNO)) & 1)) << (BITNO))

#endif /* BIT_MATH_H_ */
