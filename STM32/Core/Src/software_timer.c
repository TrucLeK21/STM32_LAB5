/*
 * software_timer.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Truc Le
 */


#include "sofware_timer.h"

int timer1_counter = 0;
uint8_t timer1_flag = 0;

void setTimer1(int duration)
{
	timer1_counter = duration/10;
	timer1_flag = 0;
}

void timerRun()
{
	if(timer1_counter > 0)
	{
		timer1_counter--;
		if(timer1_counter <= 0)
		{
			timer1_flag = 1;
		}
	}
}
