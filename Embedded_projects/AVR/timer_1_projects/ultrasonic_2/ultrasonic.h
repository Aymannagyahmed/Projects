

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#define F_CPU 8000000
#include "DIO_Interface.h"
#include "Timers.h"
#include <util/delay.h>




typedef enum{
	ULTRASONIC_1=PINC0,
	ULTRASONIC_2=PINC1,
	ULTRASONIC_3=PINC2,
	ULTRASONIC_4=PINC3
	}ULTRASONIC_type;
	
	
void ULTRASONIC_Init(void);
u8 ULTRASONIC_GetDistance(ULTRASONIC_type ultrasonic_pin);
u8 ULTRASONIC_GetDistance2(ULTRASONIC_type ultrasonic_pin);
void ULTRASONIC_Start(ULTRASONIC_type ultrasonic_pin);
u8 ULTRASONIC_GetDistanceNoBlock(u8*Pdistance);

static void Func_ICU(void);
static void Func_OVF(void);
#endif /* ULTRASONIC_H_ */