/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2022
 *      Author: ASUS
 */

#include "fsm_manual.h"
#include "stdio.h"


int status_man = INIT;
int temp_timer = 0;
int reset = 0;

void printstatus(){

	switch(status_man){
	case INIT:
	{
		char str2[100];
		if (reset) HAL_UART_Transmit(&huart2,(uint8_t*) str2, sprintf(str2, "!RESET ALL----#\r\n"), 1000);
		HAL_UART_Transmit(&huart2,(uint8_t*) str2, sprintf(str2, "!AUTO MODE----#\r\n"), 1000);
	}
		break;

	case MAN_RED:
	{
		char str2[100];
		HAL_UART_Transmit(&huart2,(uint8_t*) str2, sprintf(str2, "!RED MODE----#\r\n"), 1000);
	}
		break;

	case MAN_YELLOW:
	{
		char str2[100];
		HAL_UART_Transmit(&huart2,(uint8_t*) str2, sprintf(str2, "!YELLOW MODE----#\r\n"), 1000);
	}
		break;

	case MAN_GREEN:
	{
		char str2[100];
		HAL_UART_Transmit(&huart2,(uint8_t*) str2, sprintf(str2, "!GREEN MODE----#\r\n"), 1000);
	}
		break;

	default:
		break;
	}

	reset = 0;

}


void fsm_manual_run(){

	switch(status_man){

	case INIT:
		if (isButton1Pressed()){
			status_man = MAN_RED;
			temp_timer = 0;
			printstatus();
		}
		if (isButton3DoubleClick()){
			timer_red = RED_TIME;
			timer_green = GREEN_TIME;
			timer_yellow = YELLOW_TIME;
			status_light1 = INIT1;
			status_light2 = INIT2;
			status_man = INIT;
			reset = 1;
			printstatus();
		}
		break;



	case MAN_RED:

		if (isButton1Pressed()){
			status_man = MAN_YELLOW;
			temp_timer = 0;
			printstatus();
		}
		if (isButton2Pressed()){
			temp_timer = temp_timer + 1000;
			char str[100];
			HAL_UART_Transmit(&huart2,(uint8_t*) str, sprintf(str, "!INC: %d#\r\n",temp_timer), 1000);
		}
		if (isButton3Pressed()){
			timer_red = temp_timer;
			if (timer_red < timer_green + timer_yellow){			// timer red decrease
				if (timer_red >= timer_green + 1 ) {
					timer_yellow = timer_red - timer_green;
				}
				else timer_red = timer_green + timer_yellow;
			}
			else timer_green = timer_red - timer_yellow;			// timer red increase
			status_man = INIT;
			printstatus();
		}
		break;


	case MAN_YELLOW:
		if (isButton1Pressed()){
			temp_timer = 0;
			status_man = MAN_GREEN;
			printstatus();
		}
		if (isButton2Pressed()){
			temp_timer = temp_timer + 1000;
			char str[100];
			HAL_UART_Transmit(&huart2,(uint8_t*) str, sprintf(str, "!INC: %d#\r\n",temp_timer), 1000);
		}
		if (isButton3Pressed()){
			timer_yellow = temp_timer;
			if (timer_red != timer_green + timer_yellow) timer_red = timer_green + timer_yellow;
			status_man = INIT;
			printstatus();
		}
		break;


	case MAN_GREEN:

		if (isButton1Pressed()){
			temp_timer = 0;
			status_man = INIT;
			printstatus();
		}
		if (isButton2Pressed()){
			temp_timer = temp_timer + 1000;
			char str[100];
			HAL_UART_Transmit(&huart2,(uint8_t*) str, sprintf(str, "!INC: %d#\r\n",temp_timer), 1000);
		}
		if (isButton3Pressed()){
			timer_green = temp_timer;
			if (timer_red != timer_green + timer_yellow) timer_red = timer_green + timer_yellow;
			status_man = INIT;
			printstatus();
		}
		break;

	default:
		break;
	}

}










