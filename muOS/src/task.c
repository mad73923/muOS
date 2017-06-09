/*
 * task.c
 *
 *  Created on: 26.04.2017
 *      Author: matthias
 */

#include "task.h"

uint32_t task_totalNumber = 0;
taskControlBlock tcb[TASK_MAX_NUMBER];
volatile LinkedList allTasksList;
volatile uint8_t taskStructsAreInit = 0;

const uint32_t task_canaryValue = 0xAAAAAAAA;

void muOS_task_initStructs(void){
	linkedList_init(&allTasksList);
}

void muOS_task_init(void* taskFunction, uint32_t* stackBegin, uint32_t stackSize, uint32_t prio){
	if(!taskStructsAreInit){
		muOS_task_initStructs();
		taskStructsAreInit = 1;
	}

	if(linkedList_length(&allTasksList)>=TASK_MAX_NUMBER){
		kernelPanic();
	}

	if(prio > TASK_MAX_PRIO){
		kernelPanic();
	}

	taskControlBlock* cb = &tcb[linkedList_length(&allTasksList)];

	cb->id = task_totalNumber;
	task_totalNumber++;
	linkedList_append(&allTasksList, cb);

	// init TCB
	cb->stackBegin = stackBegin;
	cb->stackSize = stackSize;
	cb->taskFunction = taskFunction;

	cb->prio = prio;

	// set canary values
	cb->stackBegin[0] = task_canaryValue;
	cb->stackBegin[stackSize-1] = task_canaryValue;

	muOS_core_stack_init(cb);
}

void muOS_task_yield(void){
	muOS_core_dispatcher_trigger();
}
