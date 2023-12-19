/*
 * uart_com.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Truc Le
 */

#ifndef INC_UART_COM_H_
#define INC_UART_COM_H_

#include "main.h"
#include "uart_cmd_parser.h"
#include "sofware_timer.h"

#define WAIT_FOR_CMD_STATE	0
#define WAIT_FOR_TIMEOUT	1
#define TIMEOUT 3000

int status2;
void uart_communication_fsm();



#endif /* INC_UART_COM_H_ */
