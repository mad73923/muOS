/*
 * core.c
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#include "core.h"

__attribute__ ((naked)) void SysTick_Handler(void){
	asm("NOP");
	muOS_dispatcher();
}
