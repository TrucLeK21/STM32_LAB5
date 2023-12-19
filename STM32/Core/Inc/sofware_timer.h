/*
 * sofware_timer.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Truc Le
 */

#ifndef INC_SOFWARE_TIMER_H_
#define INC_SOFWARE_TIMER_H_

#include "stdint.h"

extern uint8_t timer1_flag;

void timerRun();
void setTimer1(int duration);

#endif /* INC_SOFWARE_TIMER_H_ */
