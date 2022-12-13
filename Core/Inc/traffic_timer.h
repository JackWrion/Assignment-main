/*
 * traffic_timer.h
 *
 *  Created on: Oct 31, 2022
 *      Author: ASUS
 */

#ifndef INC_TRAFFIC_TIMER_H_
#define INC_TRAFFIC_TIMER_H_

#include "global.h"

#define INIT1			19
#define AUTO_RED1		20
#define AUTO_YELLOW1	21
#define AUTO_GREEN1		22

#define INIT2			23
#define AUTO_RED2		24
#define AUTO_YELLOW2	25
#define AUTO_GREEN2		26


extern int status_light1;
extern int status_light2;

extern int RED1_flag;
extern int RED2_flag;
extern int YELLOW1_flag;
extern int YELLOW2_flag;
extern int GREEN1_flag;
extern int GREEN2_flag;

void light_control_1();
void light_control_2();




#endif /* INC_TRAFFIC_TIMER_H_ */
