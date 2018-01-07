/*
 * task.h
 *
 *  Created on: 26.04.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_TASK_H_
#define MUOS_INC_TASK_H_

#include "muOSTypes.h"
#include <stdint.h>
#include "stm32l4xx.h"
#include "core.h"
#include "linkedList.h"

#define TASK_MAX_PRIO 19
#define TASK_MAX_NUMBER 30

void muOS_task_initStructs(void);
void muOS_task_init(void* taskFunction, uint32_t* stackBegin, uint32_t stackSize, uint32_t prio);
void muOS_task_yield(void);
void muOS_task_wakeupLinkedTasks(LinkedList* syncObj);
void muOS_task_queueWaitingTask(LinkedList* syncObj, taskControlBlock* newTask);


#endif /* MUOS_INC_TASK_H_ */
