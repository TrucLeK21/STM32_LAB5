/*
 * uart_cmd_parser.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Truc Le
 */

#include "uart_cmd_parser.h"

char command_data[MAX_COMMAND_LEN];
uint8_t command_flag = 0;

void reset_command_data()
{
	command_index = 0;
	memset(command_data, 0, sizeof(command_data));
}


void command_parser_fsm()
{
	switch (status1) {
		case IDLE_STATE:
			if(buffer[index_buffer] == '!')
			{
				status1 = RECEIVING_STATE;
				// reset command data to use it again
				reset_command_data();
			}
			break;
		case RECEIVING_STATE:
			if(buffer[index_buffer] == '!')
			{
				reset_command_data();
				break;
			}

			if(buffer[index_buffer] == '#')
			{
				status1 = IDLE_STATE;
				// add null terminate for extracting command
				command_data[command_index] = '\0';
				command_flag = 1;
			} else
			{
				command_data[command_index++] = buffer[index_buffer];
			}
			break;
		default:
			break;
	}
}
