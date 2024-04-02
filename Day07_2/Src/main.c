/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

extern int count;

int main(void)
{
	char str[50];
	SystemInit();
	LedInit(LED_RED);
	LedInit(LED_ORANGE);
	LedInit(LED_GREEN);
	LedInit(LED_BLUE);
	UartInit(BAUD_9600);
	SwitchInit(SWITCH);
	UartPuts("--------LED_CONTROL-------\r\n");		DelayMs(30);
	UartPuts("1. RED LED ON\r\n");					DelayMs(30);
	UartPuts("2. RED LED OFF\r\n");					DelayMs(30);
	UartPuts("3. ORANGE LED ON\r\n");				DelayMs(30);
	UartPuts("4. ORANGE LED OFF\r\n");				DelayMs(30);
	UartPuts("5. GREEN LED ON\r\n");				DelayMs(30);
	UartPuts("6. GREEN LED OFF\r\n");				DelayMs(30);
	UartPuts("7. BLUE LED ON\r\n");					DelayMs(30);
	UartPuts("8. BLUE LED OFF\r\n");				DelayMs(30);

	while(1)
	{
		UartGets(str);
		DelayMs(30);
		if(str[0] == '1')
		{
			LedOn(LED_RED);
			UartPuts("LED_Red_ON");
		}
		else if(str[0] == '2')
		{
			LedOff(LED_RED);
			UartPuts("LED_Red_OFF");
		}
		if(str[0] == '3')
		{
			LedOn(LED_ORANGE);
			UartPuts("LED_Orange_ON");
		}
		else if(str[0] == '4')
		{
			LedOff(LED_ORANGE);
			UartPuts("LED_Orange_OFF");
		}
		if(str[0] == '5')
		{
			LedOn(LED_GREEN);
			UartPuts("LED_Green_ON");
		}
		else if(str[0] == '6')
		{
			LedOff(LED_GREEN);
			UartPuts("LED_Green_Off");
		}
		if(str[0] == '7')
		{
			LedOn(LED_BLUE);
			UartPuts("LED_Blue_ON");
		}
		else if(str[0] == '8')
		{
			LedOff(LED_BLUE);
			UartPuts("LED_Blue_OFF");
		}
	}
	return 0;
}
