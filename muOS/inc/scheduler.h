/*
 * scheduler.h
 *
 *  Created on: 04.06.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_SCHEDULER_H_
#define MUOS_INC_SCHEDULER_H_

#include "../src/scheduler/allScheduler.h"
#include "linkedList.h"
#include "linkedListTypes.h"

void scheduler_callNextTask(void);

#endif /* MUOS_INC_SCHEDULER_H_ */
