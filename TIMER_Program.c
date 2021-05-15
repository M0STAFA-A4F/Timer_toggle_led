#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_Register.h"
#include "DIO_Interface.h"

#define NULL	0

void (* Timer0CallBackPtr)(void) = NULL;


void TIMER0_VidInit()
{
	// Normal Mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

	// prescaling   --> clk/256
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);

	// preload value of timer0
	TCNT0 = 238;

	//  Timer/Counter0 Overflow Interrupt Enable (TOIE)
	SET_BIT(TIMSK,0);

	// GIE=1
	SET_BIT(SREG,7);
}

void Timer0_VidSetCallBackFun(void (* PFun)(void))
{
	Timer0CallBackPtr = PFun;
}

void __vector_11(void)
{
	Timer0CallBackPtr();
}


/*
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_Register.h"
#include "DIO_Interface.h"


void TIMER0_VidInit()
{
	// Normal Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// prescaling   --> clk/256
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
	
	// preload value of timer0
//	TCNT0 = 238;
	OCR0 = 128;
	
	//  Timer/Counter0 Overflow Interrupt Enable (TOIE)
	SET_BIT(TIMSK,1);
	
	// GIE=1
	SET_BIT(SREG,7);
}

void __vector_11(void)
{
	u32 static counter = 0;
	counter++;
	
	if(123 == counter)
	{
		TCNT0 = 238;
		//OCR0 = 128;
		DIO_VidTogglePinValue(PORTA , 0);
		counter = 0;
	}
}



void __vector_10(void)
{
	u32 static counter = 0;
	counter++;

	if(123 == counter)
	{
		//OCR0 = 128;
		DIO_VidTogglePinValue(PORTA , 0);
		counter = 0;
	}
}
*/
