/*
 ============================================================================
 *  timer1.c
 *  Date: Nov 3, 2022
 *  Author: Yousef_Osama
 *  Description: The Source File of TIMER_1 Driver
 ============================================================================
 */
#include "./INC/timer1.h"
#include "avr/io.h"
#include <avr/interrupt.h>
/********************************************************************************
 *                       Global variables                                       *
* ******************************************************************************/
/* Global variable to Point to address of callBack function in Application*/
static volatile void(*callBack_ptr)(void) = NULL_PTR;

/********************************************************************************
 *                       Interrupt Service Routines                             *
 *******************************************************************************/
ISR(TIMER1_COMPA_vect){
	if(callBack_ptr != NULL_PTR){
		(*callBack_ptr)();
	}
}
/********************************************************************************/

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/
#ifndef TIMER1_Compare_Mode
/*
 * Description :
 * Function responsible for initialize the TIMER_1 driver in normal mode.
 */
void TIMER1_init_Normal(Timer1_ConfigType* Config_ptr)
{
	/* Initialize Timer1 With value that will start count according to this value*/
	TCNT1 = Config_ptr->Initial_value;

	/* Enable Timer1 Interrupt*/
	TIMSK |= (1 << OCIE1A);

	/****************************************************************************
	 * FOC1A : It will be set when Timer1 Operate in non PWM Mode
	 * Set First 2-bits From Mode Member to Specify which Mode Timer1 Will Operate
	****************************************************************************/
	TCCR1A = (1 << FOC1A) | ((TCCR1A & 0xFC) | (Config_ptr->Mode & 0x03));

	/****************************************************************************
	 * Set Pre-scaler value in the first 3-bits in TCCR1B Register that will specify which frequency Timer1 will Operate
	 * Set Last 2-bits From Mode Member to Specify Which Mode Timer1 Will Operate
	****************************************************************************/
	TCCR1B = ((TCCR1B & 0xF8) | (Config_ptr->Prescaler & 0x07)) | ((TCCR1B & 0xE7) | ((Config_ptr->Mode & 0x0C)<<1));
}
#else
/*
 * Description :
 * Function responsible for initialize the TIMER_1 driver in compare mode.
 */
void TIMER1_init_Compare(Timer1_ConfigType* Config_ptr)
{
	/* Initialize Timer1 With value that will start count according to this value*/
	TCNT1 = Config_ptr->Initial_value;

	/* Set Compare value that Timer will reach to it then, it backs count from 0*/
	OCR1A = Config_ptr->Compare_value;

	/* Enable Timer1 Interrupt*/
	TIMSK |= (1 << OCIE1A);

	/****************************************************************************
	 * FOC1A : It will be set when Timer1 Operate in non PWM Mode
	 * Set First 2-bits From Mode Member to Specify which Mode Timer1 Will Operate
	****************************************************************************/
	TCCR1A = (1 << FOC1A) | ((TCCR1A & 0xFC) | (Config_ptr->Mode & 0x03));

	/****************************************************************************
	 * Set Pre-scaler value in the first 3-bits in TCCR1B Register that will specify which frequency Timer1 will Operate
	 * Set Last 2-bits From Mode Member to Specify Which Mode Timer1 Will Operate
	****************************************************************************/
	TCCR1B = ((TCCR1B & 0xF8) | (Config_ptr->Prescaler & 0x07)) | ((TCCR1B & 0xE7) | ((Config_ptr->Mode & 0x0C)<<1));
}
#endif
/*
 * Description :
 * Function responsible for De_initialize the TIMER_1 driver.
 */
void TIMER1_deInit(void)
{
	/* Clear Timer Register */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	/* Disable Interrupt */
	TIMSK &= ~(1 << OCIE1A);
}
/*
 * Description :
 * Setup the callback function in the TIMER_1 driver.
 */
void TIMER1_setCallback(void(*a_ptr)(void))
{
	/* Make global variable points to same function to be called in ISR when an detection occur*/
	callBack_ptr = a_ptr;
}
