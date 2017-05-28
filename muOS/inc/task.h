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

void muOS_task_init(taskControlBlock* tcb, void* taskFunction, uint32_t* stackBegin, uint32_t stackSize, uint32_t prio);
void muOS_task_yield(void);


#endif /* MUOS_INC_TASK_H_ */
