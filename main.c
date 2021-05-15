#define F_CPU 8000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "TIMER_Interface.h"

#define TCNT0	*((u8*)0x52)

void tog_led()
{
	u32 static counter = 0;
	counter++;

	if(123 == counter)
	{
		TCNT0 = 238;
		DIO_VidTogglePinValue(PORTA , 0);
		counter = 0;
	}
}

int main()
{
	DIO_VidSetPinDirection(0,0,1);
	TIMER0_VidInit();

	Timer0_VidSetCallBackFun(&tog_led);
	TIMER0_VidInit();

	while(1)
	{

	}

	return 0;
}
