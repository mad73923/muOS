/*
 * task.c
 *
 *  Created on: 26.04.2017
 *      Author: matthias
 */

#include "task.h"

uint32_t task_totalNumber = 0;

const uint32_t task_canaryValue = 0xAAAAAAAA;
const uint32_t task_numberOfRegisters = 16;

void muOS_task_init(taskControlBlock* tcb, void* taskFunction, uint32_t* stackBegin, uint32_t stackSize){
	tcb->id = task_totalNumber;
	task_totalNumber++;

	// init TCB
	tcb->stackBegin = stackBegin;
	tcb->stackSize = stackSize;

	// set canary values
	tcb->stackBegin[0] = task_canaryValue;
	tcb->stackBegin[stackSize-1] = task_canaryValue;

	// set SP
	tcb->stackPointer = stackBegin + stackSize - task_numberOfRegisters -2;

	// set R7
	tcb->stackBegin[stackSize-14] = &tcb->stackBegin[stackSize-1];

	// set PSR
	tcb->stackBegin[stackSize-3] = 0x1000200;

	// set PC
	tcb->stackBegin[stackSize-4] = taskFunction;

	// set LR
	tcb->stackBegin[stackSize-5] = -7;
}
