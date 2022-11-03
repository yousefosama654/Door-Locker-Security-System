/*
 ============================================================================
 *  timer0.h
 *  Date: OCT 3, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of TIMER_0 Driver
 ============================================================================
 */
#ifndef TIMER0_H_
#define TIMER0_H_
#include "../../CONFIG/std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define TIMER0_MAX_VALUE 255
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum {
	TIMER0_NORMAL_MODE, TIMER0_COMPARE_MODE, TIMER0_FAST_PWM_MODE
} Timer0_Mode;
typedef enum {
	TIMER0_NORMAL_PORT = 0, TIMER0_NON_INVERTING_MODE = 2, TIMER0_INVERTING_MODE = 3
} PWM_Mode;
typedef enum {
	TIMER0_NO_CLOCK,
	TIMER0_F_CPU_CLOCK,
	TIMER0_F_CPU_CLOCK_8,
	TIMER0_F_CPU_CLOCK_64,
	TIMER0_F_CPU_CLOCK_256,
	TIMER0_F_CPU_CLOCK_1024
} Timer0_Clock;
typedef struct {
	Timer0_Mode timer_mode;
	PWM_Mode pwm_mode;
	Timer0_Clock clock;
} Timer0_Config;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the TIMER_0 driver.
 */
void Timer0_init(const Timer0_Config *Config_Ptr);
 /*
  * Description :
  *  Setup the compare value based on the required input duty cycle.
  */
void Timer0_PWM_Start(uint8 duty_cycle_percentage);
/*
 * Description :
 * Function responsible for De_initialize the TIMER_0 driver.
 */
void TIMER0_deinit();
#endif /* TIMER0_H_ */
