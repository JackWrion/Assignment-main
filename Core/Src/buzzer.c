/*
 * buzzer.c
 *
 *  Created on: Dec 15, 2022
 *      Author: ASUS
 */

#include "buzzer.h"

int toggle_buzzer = 1;
int act_buzzer = 0;
int time = 1000;

void buzzer(){

	if (act_buzzer == 1){
		if (timer4_flag == 1){
			setTimer4(time);
			time -= 50;
			if (time < 150) time = 150;
			int feq = 900 - 500*(10*timer3_counter/timer_yellow);
			__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1, feq*toggle_buzzer);
			toggle_buzzer = 1 - toggle_buzzer;
		}
	}
	else {
		toggle_buzzer = 1;
		time = timer_yellow/10;
		setTimer4(200);
	}

}
