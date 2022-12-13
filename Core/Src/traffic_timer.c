/*
 * traffic_timer.c
 *
 *  Created on: Oct 31, 2022
 *      Author: ASUS
 */

#include "traffic_timer.h"


int RED1_flag = 0;
int RED2_flag = 0;
int YELLOW1_flag = 0;
int YELLOW2_flag = 0;
int GREEN1_flag = 0;
int GREEN2_flag = 0;


int status_light1 = INIT1;
int status_light2 = INIT2;


void light_control_1(){

	switch(status_light1){

		case INIT1:
			setTimer2(timer_red);
			LED1_OFF();
			status_light1 = AUTO_RED1;
			break;

		case AUTO_RED1:
			RED1_flag = 1;

			if(timer2_flag == 1){
				setTimer2(timer_green);
				LED1_OFF();
				RED1_flag = 0;
				status_light1 = AUTO_GREEN1;
			}
			break;

		case AUTO_GREEN1:
			GREEN1_flag = 1;

			if(timer2_flag == 1){
				setTimer2(timer_yellow);
				LED1_OFF();
				GREEN1_flag = 0;
				status_light1 = AUTO_YELLOW1;
			}
			break;

		case AUTO_YELLOW1:
			YELLOW1_flag = 1;

			if(timer2_flag == 1){
				setTimer2(timer_red);
				LED1_OFF();
				YELLOW1_flag = 0;
				status_light1 = AUTO_RED1;
			}
			break;
		default:
			break;
		}

}




void light_control_2(){

	switch(status_light2){

		case INIT2:
			setTimer3(timer_green);
			LED2_OFF();
			RED2_flag = 0;
			YELLOW2_flag = 0;
			status_light2 = AUTO_GREEN2;
			break;

		case AUTO_RED2:
			RED2_flag = 1;
			if(timer3_flag == 1){
				setTimer3(timer_green);
				LED2_OFF();
				RED2_flag = 0;
				status_light2 = AUTO_GREEN2;
			}
			break;

		case AUTO_YELLOW2:
			YELLOW2_flag = 1;
			if(timer3_flag == 1){
				setTimer3(timer_red);
				LED2_OFF();
				YELLOW2_flag = 0;
				status_light2 = AUTO_RED2;
			}
			break;

		case AUTO_GREEN2:
			GREEN2_flag = 1;
			if(timer3_flag == 1){
				setTimer3(timer_yellow);
				LED2_OFF();
				GREEN2_flag = 0;
				status_light2 = AUTO_YELLOW2;
			}
			break;
		default:
			break;
		}

}







