/*
 * core.c
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#include "core.h"

const uint32_t task_numberOfRegisters = 16;

__attribute__ ((naked)) void SysTick_Handler(void){
	__asm("NOP");
	muOS_dispatcher();
}

void muOS_core_stack_init(taskControlBlock* tcb){
	// set SP
	tcb->stackPointer = tcb->stackBegin + tcb->stackSize - task_numberOfRegisters -2;

	// set R7
	tcb->stackBegin[tcb->stackSize-14] = &tcb->stackBegin[tcb->stackSize-1];

	// set PSR
	tcb->stackBegin[tcb->stackSize-3] = 0x1000200;

	// set PC
	tcb->stackBegin[tcb->stackSize-4] = tcb->taskFunction;

	// set LR
	tcb->stackBegin[tcb->stackSize-5] = -7;
}
