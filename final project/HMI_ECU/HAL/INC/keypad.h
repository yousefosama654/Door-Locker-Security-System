/*
 ============================================================================
 *  keypad.h
 *  Date: OCT 25, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of KEYPAD Driver
 ============================================================================
 */
#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../../CONFIG/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                  4
#define KEYPAD_NUM_ROWS                  4

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID                   PORTC_ID

#define KEYPAD_FIRST_ROW_PIN_ID           PIN0_ID
#define KEYPAD_FIRST_COLUMN_PIN_ID        PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */
