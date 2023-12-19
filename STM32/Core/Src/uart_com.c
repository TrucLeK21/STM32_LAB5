/*
 * uart_com.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Truc Le
 */


#include "uart_com.h"


void uart_communication_fsm()
{
	switch (status2) {
		case WAIT_FOR_CMD_STATE:
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			if(command_flag)
			{
				command_flag = 0;
				if(strcmp(command_data, "RST") == 0)
				{
					transmit_data();
					status2 = WAIT_FOR_TIMEOUT;
				}
			}
			break;
		case WAIT_FOR_TIMEOUT:
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
			if(timer1_flag)
			{
				reTransmit_data();
			}

			if(command_flag)
			{
				command_flag = 0;
				if(strcmp(command_data, "RST") == 0)
				{
					transmit_data();
				}

				if(strcmp(command_data, "OK") == 0)
				{
					status2 = WAIT_FOR_CMD_STATE;
				}
			}
			break;
		default:
			break;
	}
}
