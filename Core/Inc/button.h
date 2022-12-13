/*
 * button.h
 *
 *  Created on: Oct 28, 2022
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "Software_Timer.h"
#include "main.h"
#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE	GPIO_PIN_RESET


extern int button1_flag;
extern int button2_flag;
extern int button3_flag;
extern int button4_flag;
extern int button5_flag;


int isButton1Pressed();
void getKeyInput1();

int isButton2Pressed();
void getKeyInput2();

int isButton3Pressed();
void getKeyInput3();

int isButton4Pressed();
void getKeyInput4();


#endif /* INC_BUTTON_H_ */
