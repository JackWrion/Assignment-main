/*
 * fsm_manual.h
 *
 *  Created on: Oct 30, 2022
 *      Author: ASUS
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "global.h"
#include "traffic_timer.h"			//include needed to RESET all the state

#define INIT		101
#define MAN_RED		102
#define MAN_GREEN	103
#define MAN_YELLOW	104

extern int status_man;
void fsm_manual_run();

#endif /* INC_FSM_MANUAL_H_ */
