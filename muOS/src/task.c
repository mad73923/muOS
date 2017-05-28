/*
 * task.c
 *
 *  Created on: 26.04.2017
 *      Author: matthias
 */

#include "task.h"

uint32_t task_totalNumber = 0;

const uint32_t task_canaryValue = 0xAAAAAAAA;

void muOS_task_init(taskControlBlock* tcb, void* taskFunction, uint32_t* stackBegin, uint32_t stackSize, uint32_t prio){
	tcb->id = task_totalNumber;
	task_totalNumber++;

	// init TCB
	tcb->stackBegin = stackBegin;
	tcb->stackSize = stackSize;
	tcb->taskFunction = taskFunction;
	tcb->prio = prio;

	// set canary values
	tcb->stackBegin[0] = task_canaryValue;
	tcb->stackBegin[stackSize-1] = task_canaryValue;

	muOS_core_stack_init(tcb);
}

void muOS_task_yield(void){
	SCB->ICSR |= SCB_ICSR_PENDSTSET_Msk;
}
