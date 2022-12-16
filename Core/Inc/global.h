/*
 * global.h
 *
 *  Created on: Oct 28, 2022
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "button.h"
#include "Software_Timer.h"
#include "LED_TOGGLE.h"

#define RED_TIME 10000
#define GREEN_TIME 6000
#define YELLOW_TIME 4000

// Khai bao trong global.c
extern int timer_red;
extern int timer_yellow;
extern int timer_green;

extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim3;


#endif /* INC_GLOBAL_H_ */
