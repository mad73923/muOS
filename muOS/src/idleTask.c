/*
 * idleTask.c
 *
 *  Created on: 04.06.2017
 *      Author: matthias
 */

#include "idleTask.h"

uint32_t idleTaskStack[idleTaskStackSize];

void idleTask_task(void);

void idleTask_init(void){
	muOS_task_init(idleTask_task, idleTaskStack, idleTaskStackSize, TASK_MAX_PRIO);
}

void idleTask_task(void){
	while(1){
		muOS_task_yield();
	}
}
