/*
 ============================================================================
 *  buzzer.h
 *  Date: OCT 23, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of BUZZER Driver
 ============================================================================
 */
#ifndef HAL_INC_BUZZER_H_
#define HAL_INC_BUZZER_H_

#define BUZZER_PORT_ID
#define BUZZER_PIN_ID

void BUZZER_init();
void BUZZER_on(void);
void BUZZER_off(void);

#endif /* HAL_INC_BUZZER_H_ */
