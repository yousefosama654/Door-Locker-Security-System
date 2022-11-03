/*
 ============================================================================
 *  Utilities.h
 *  Date: Nov 3, 2022
 *  Author: Yousef_Osama
 *  Description: The Header File of Utilities file
 ============================================================================
 */
#ifndef UTILITIES_H_
#define UTILITIES_H_
/*******************************************************************************
 *                                 Files                                       *
 *******************************************************************************/
#include"lcd.h"
#include"keypad.h"
#include"util/delay.h"
#include"usart.h"
#include"timer1.h"
#include"avr/interrupt.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PassLength  5
#define OpenDoorTime 10
#define HoldDoorTime 3
#define CloseDoorTime 10
#define DangerTime 60
#define EnterButton 13
#define NormalDelay 800
#define KeyDelay    500
#define UsartDelay  50
/****************************************************************
*                            Declarations                       *
****************************************************************/
/* String to store the 5-digits password received from user or EEPROM */
uint8 HMI_ECU_Password_1[5];
uint8 HMI_ECU_Password_2[5];
uint8 flag;
uint8 i;
uint8 key;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for Modules initializations .
 */
void TASK_mainInit(void);
/*
 * Description :
 * Function responsible for creating new passwords by user inputs .
 */
void TASK_createNewPass(void);
/*
 * Description :
 * Function responsible for showing the option of the user.
 * 1-open the door.
 * 2-change the password.
 */
void TASK_showOptions(void);
/*
 * Description :
 * Helper Function responsible for checking the sent password to the given in the eeprom.
 */
void TASK_checkPass(void);
/*
 * Description :
 * Function responsible for door management .
 */
void TASK_openDoor(void);
/*
 * Description :
 * Function responsible for changing password management .
 */
void TASK_changePass(void);
/*
 * Description :
 * Function responsible for call back for timer 1 .
 */
void Callback(void);
/*
* Description :
* Function responsible for showing the state of Error.
*/
void TASK_turnOnBuzzer(void);
/*
* Description :
* Function responsible for showing the state of door.
*/
void TASK_turnOnMotor(void);
#endif /* UTILITIES_H_ */
