/*
 * uart_cmd_parser.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Truc Le
 */

#ifndef INC_UART_CMD_PARSER_H_
#define INC_UART_CMD_PARSER_H_

#include "main.h"

#define MAX_COMMAND_LEN	10
#define MAX_BUFFER_SIZE 30

#define IDLE_STATE		1
#define RECEIVING_STATE 2


extern uint8_t index_buffer;
extern char buffer[MAX_BUFFER_SIZE];

int status1;
extern uint8_t command_flag;
extern char command_data[MAX_COMMAND_LEN];

uint8_t command_index;
void command_parser_fsm();

#endif /* INC_UART_CMD_PARSER_H_ */
